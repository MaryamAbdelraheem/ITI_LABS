// document.images[]

let i=0;
let id=setInterval(() => {
    
        if(i<8)
        document.images[0].src=`images/${++i}.jpg`;
        else
            clearInterval(id);
        
}, 1000);



   
