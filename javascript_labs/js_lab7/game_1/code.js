// --- Global Declarations ---
let nest = document.getElementById("nest");
let egg = document.getElementById("egg");
let died_egg = document.getElementById("died_egg");

//egg class prerequisites
let currentEggInstance = null; 
let gameIntervalId;            
let dropIntervalId;            
let isGameRunning = true; 

//nest object prerequisites
const nest_speed = 35;
let nest_left = 0;


// Egg class 
class Egg {
    constructor() {
        this.topPos = 0;

        egg.style.visibility = "visible";
        died_egg.style.visibility = "hidden";

        this.resetPosition();
        this.startDrop();

        currentEggInstance = this;
    }

    resetPosition() {
        this.topPos = 0;
        egg.style.top = this.topPos + "px";
        egg.style.left = Math.random() * (window.innerWidth - 250) + "px";
    }

    // --------------- DROP LOOP ----------------
    startDrop() {
        clearInterval(dropIntervalId);

        dropIntervalId = setInterval(() => {
            this.topPos += 20; // fall speed
            egg.style.top = this.topPos + "px";

            // 1) check if caught
            if (this.caught()) return;

            // 2) check if missed
            if (this.topPos >= window.innerHeight - 250) {
                this.missed();
            }
        }, 50);
    }

    // --------------- MISSED --------------------
    missed() {
        clearInterval(dropIntervalId);
        egg.style.visibility = "hidden";

        died_egg.style.top = (window.innerHeight - 250) + "px";
        died_egg.style.left = egg.style.left;
        died_egg.style.visibility = "visible";

        setTimeout(() => {
            died_egg.style.visibility = "hidden";
        }, 100);

        console.log("missed");
    }

    // --------------- CAUGHT --------------------
    caught() {
       let egg_bottom = this.topPos + egg.offsetHeight;
       let egg_left = parseInt(egg.style.left);

       let nest_left =parseInt(nest.style.left);
       let nest_top = window.innerHeight - nest.offsetHeight;
       let nest_right = nest_left+nest.offsetWidth;

   
        if (
          egg_left>= nest_left &&
          egg_left <= nest_right &&
          egg_bottom >= nest_top - nest.style.paddingTop
        ) {
            clearInterval(dropIntervalId);
            egg.style.visibility = "hidden";
            console.log("egg caught!");
            
        }

        
    }
}

// NEST POSITION ---------------------------------------------------
function set_nest_position() {
    const nest_width = nest.offsetWidth;

    nest_left = (window.innerWidth / 2) - (nest_width / 2);
    nest.style.left = nest_left + "px";
    nest.style.transform = "none";
}

// load nest position on window load
window.onload = set_nest_position;

// CONTROL NEST MOVEMENT -----------------------------------------
document.addEventListener('keydown', function (event) {
    if (!isGameRunning) return;

    const nest_width = nest.offsetWidth;
    const view_port_width = window.innerWidth;

    if (event.key === 'ArrowLeft') {
        nest_left = Math.max(0, nest_left - nest_speed);
    }
    else if (event.key === 'ArrowRight') {
        nest_left = Math.min(view_port_width - nest_width, nest_left + nest_speed);
    }

    nest.style.left = nest_left + "px";

});

// --- Game Loop Function ---
function game_loop() {
    if (isGameRunning) {
        currentEggInstance = new Egg();
    }
}

gameIntervalId = setInterval(game_loop,2500);
game_loop();