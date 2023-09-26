console.log("Script loaded");
document.addEventListener("DOMContentLoaded", function() {
    /* declare objects */
    let rock = document.getElementById("rock");
    let paper = document.getElementById("paper");
    let scissor = document.getElementById("scissor");
    let question = document.getElementById("question");

    /* take user input */
    let user = null;
    rock.addEventListener("click", function() {
        user = 0;
        setDisplay();
    });
    paper.addEventListener("click", function() {
        user = 1;
        setDisplay();
    });
    scissor.addEventListener("click", function() {
        user = 2;
        setDisplay();
    });

    function setDisplay() {
        if (user == 0) {
            rock.style.display = "block";
            paper.style.display = "none";
            scissor.style.display = "none";
        }
        else if (user == 1) {
            rock.style.display = "none";
            paper.style.display = "block";
            scissor.style.display = "none";
        }
        else if (user == 2) {
            rock.style.display = "none";
            paper.style.display = "none";
            scissor.style.display = "block";
        }
    }
}