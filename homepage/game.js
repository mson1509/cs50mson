document.addEventListener("DOMContentLoaded", function() {
    //declare objects
    let rock = document.getElementById("rock");
    let paper = document.getElementById("paper");
    let scissor = document.getElementById("scissor");
    let question = document.getElementById("question");

    //take user input and display their choice
    var user = null;
    rock.addEventListener("click", function() {
        user = userDisplay(0);
    });
    paper.addEventListener("click", function() {
        user = userDisplay(1);
    });
    scissor.addEventListener("click", function() {
        user = userDisplay(2);
    });

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
    // wait 2 seconds before computer choose their random choice
    setTimeout(function() {
        console.log("Computer generating random choice");
    }, 5000);
    let computer = (Math.round(Math.random() * 10)) % 3;
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
    // determine the winner and print the result
    document.getElementById("text").innerHTML = "VS";
    if ((user + 1) % 3 == computer) {
        document.getElementById("text").innerHTML = "You lose!";
    }
    else if (user == computer) {
        document.getElementById("text").innerHTML = "It's a tie!";
    }
    else {
        document.getElementById("text").innerHTML = "You win!";
    }

})