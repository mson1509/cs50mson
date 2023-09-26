document.addEventListener("DOMContentLoaded", function() {
    /* declare objects */
    let rock = document.getElementById("rock");
    let paper = document.getElementById("paper");
    let scissor = document.getElementById("scissor");
    let question = document.getElementById("question");

    /* take user input */
    rock.addEventListener("click", function() {
        setDisplay(0);
    });
    paper.addEventListener("click", function() {
        setDisplay(1);
    });
    scissor.addEventListener("click", function() {
        setDisplay(2);
    });

    function setDisplay(user) {
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

    let computer = function {
        let x = Math.round(Math.random() * 10);
        return x % 3;
    };

})