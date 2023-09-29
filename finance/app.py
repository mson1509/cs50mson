import os

from cs50 import SQL
from datetime import datetime
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Create purchases table to keep track of all purchases
db.execute(
                """
                CREATE TABLE IF NOT EXISTS purchases (
                    purchase_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
                    user_id INTEGER NOT NULL,
                    time TEXT NOT NULL,
                    stock TEXT NOT NULL,
                    price REAL NOT NULL,
                    shares INTEGER NOT NULL,
                    purchase REAL NOT NULL,
                    FOREIGN KEY(user_id) REFERENCES users(id)
                )
            """
            )


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# TODO: DOING
@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    id = session["user_id"]
    user = db.execute("SELECT username, cash FROM users WHERE id = ?", id)
    username = user[0]["username"]
    cash = usd(user[0]["cash"])
    stocks = db.execute(
                """
                SELECT stock, SUM(price) AS price, SUM(shares) AS shares
                FROM purchases
                JOIN users
                ON purchases.user_id = users.id
                WHERE users.id = ?
                GROUP BY stock
                ORDER BY stock
            """, id)
    for stock in stocks:
        stock["price"] = usd(stock["price"])
        current = lookup(stock["stock"])
        stock["current"] = usd(current["price"])
        stock["value"] = usd(current["price"] * stock["shares"])
    return render_template("index.html", username=username, cash=cash, stocks=stocks)


# TODO: DONE
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("please enter a whole number of shares", 403)
        if shares <= 0:
            return apology("please enter a positive number of shares", 403)
        stock = lookup(symbol)
        if not stock:
            return apology("stock cannot be found", 404)
        id = session["user_id"]
        time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        rows = db.execute("SELECT * FROM users WHERE id = ?", id)
        cash = rows[0]["cash"]
        price = stock["price"]
        purchase = price * shares
        if cash < purchase:
            return apology("you do not have enough cash", 403)
        db.execute(
            """
            INSERT INTO purchases
                    (user_id, time, stock, price, shares, purchase)
                    VALUES (:id, :time, :symbol, :price, :shares, :purchase)
        """,
            id=id,
            time=time,
            symbol=symbol,
            price=price,
            shares=shares,
            purchase=purchase,
        )
        cash = cash - purchase
        db.execute("UPDATE users SET cash = :cash WHERE id = :id", cash=cash, id=id)
        # add them cai thong bao mua thanh cong vao
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


# TODO: DONE
@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        # Take user input and return the found stock
        quote = request.form.get("quote")
        stock = lookup(quote)
        if stock:
            name = stock["name"]
            price = usd(stock["price"])
            symbol = stock["symbol"]
            return render_template(
                "quoted.html", name=name, price=price, symbol=symbol
            )
        else:
            return apology("stock cannot be found", 404)
    # Default quote interface via GET
    else:
        return render_template("quote.html")


# TODO: DONE
@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        rows = db.execute("SELECT * FROM users")
        # Ensure username and password is valid
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if not username or not password or not confirmation:
            return apology("must provide input", 403)
        for i in range(len(rows)):
            if username == rows[i]["username"]:
                return apology("username already taken", 403)
        if password != confirmation:
            return apology("confirmation do not match", 403)
        # Add user information to db and redirect to login page
        else:
            db.execute(
                "INSERT INTO users (username, hash) VALUES (:username, :hashed_password)",
                username=username,
                hashed_password=generate_password_hash(password),
            )
            # add them thong bao register thanh cong
            return redirect("/login")
    # Render register page when user reached route via GET
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
