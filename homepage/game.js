document.addEventListener("DOMContentLoaded", function() {
    //declare objects
    let rock = document.getElementById("rock");
    let paper = document.getElementById("paper");
    let scissor = document.getElementById("scissor");
    let question = document.getElementById("question");

    //take user input and display their choice
    rock.addEventListener("click", function() {
        userDisplay(0);
    });
    paper.addEventListener("click", function() {
        userDisplay(1);
    });
    scissor.addEventListener("click", function() {
        userDisplay(2);
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
    };
    // wait 2 seconds before computer choose their random choice
    setTimeout(function() {
        console.log("After 2 seconds");
    }, 2000);

    let computer = function() {
        let x = Math.round(Math.random() * 10);
        return x % 3;
    };
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