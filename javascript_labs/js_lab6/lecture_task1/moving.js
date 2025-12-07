let left=0;
let id=setInterval(()=>{
    left+=20;
    if(left<window.innerWidth-document.images[0].width)
    document.images[0].style.left=left+"px";
    else
    clearInterval(id);
},100)