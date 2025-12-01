let box = document.getElementById("red");
let box2 = document.getElementById("blue");
let box3 = document.getElementById("green");

//box class prerequisites


document.querySelectorAll("div").forEach((item)=>{
    item.addEventListener("click", function clone(){
        let new_box = document.createElement("div");
        new_box.style.backgroundColor = item.id;
        new_box.addEventListener("click", clone,{once:true});
        document.body.appendChild(new_box);
    }, {once:true});
})



