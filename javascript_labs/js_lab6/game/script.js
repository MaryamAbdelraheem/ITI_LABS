
let img_object = document.querySelectorAll(".birds"); //nodelist

let id;
let count = 0;
img_object.forEach(bird => {
    id = setInterval(() => {
        bird.style.left = Math.random() * 1450 + "px"; // example range
        bird.style.bottom = Math.random() * 500 + "px";
    }, 1500);
});

img_object.forEach(bird =>{
    bird.addEventListener('click',function(){
        bird.src = "./imgs/died_bird.png";
        setTimeout(()=>{
            bird.style.visibility="hidden";
            count = 0; // Reset count before checking

            img_object.forEach(bird=>{
                console.log(bird.src)
                if(bird.src.includes("died_bird.png")){
                    count +=1;
                }
            })

            console.log(count)

            if(count == img_object.length){
                alert(("you won 😍🏆!!"));
            }
        },3000)

    })

})


/**
 * The problem was that the clearInterval(id) was called inside the click event 
 * for each bird, 
 * which stopped the birds' movement immediately after clicking one bird. 
 * This prevented the game from continuing properly, and since the alert was checked 
 * after the click, it might not have triggered correctly. 
 * By removing it from the click event, 
 * the birds keep moving until the game ends naturally, 
 * and the alert now works when all birds are killed.
 */



// Example stop after 50s
setTimeout(() => clearInterval(id), 50000);
