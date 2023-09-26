document.addEventListener("DOMContentLoaded", function() {
    //declare objects
    let rock = document.getElementById("rock");
    let paper = document.getElementById("paper");
    let scissor = document.getElementById("scissor");
    let question = document.getElementById("question");

    //take user input and print the result
    var user = null;
    let computer = (Math.round(Math.random() * 10)) % 3;
    rock.addEventListener("click", function() {
        user = userDisplay(0);
        winner(computer);
    });
    paper.addEventListener("click", function() {
        user = userDisplay(1);
        winner(computer);
    });
    scissor.addEventListener("click", function() {
        user = userDisplay(2);
        winner(computer);
    });
    // display user choice
    function userDisplay(user) {
        rock.style.display = "none";
        paper.style.display = "none";
        scissor.style.display = "none";
        if (user == 0) {
            rock.style.display = "block";
        }
        else if (user == 1) {
            paper.style.display = "block";
        }
        else if (user == 2) {
            scissor.style.display = "block";
        }
        return user;
    };
    // determine the winner
    function winner(computer) {
        // wait 2 seconds after user clicked
        setTimeout(function() {
            // display computer choice
            if (computer == 0) {
                question.src = "rock.png";
            }
            else if (computer == 1) {
                question.src = "paper.jpg";
            }
            else if (computer == 2) {
                question.src = "scissor.png";
            }
            // print the result
            if ((user + 1) % 3 == computer) {
                document.getElementById("text").innerHTML = "You lose!";
            }
            else if (user == computer) {
                document.getElementById("text").innerHTML = "It's a tie!";
            }
            else {
                document.getElementById("text").innerHTML = "You win!";
            }
        }, 1000);
    };
    // reset the game
    document.getElementById("reset").addEventListener("click", function() {
        location.reload();
    });
})