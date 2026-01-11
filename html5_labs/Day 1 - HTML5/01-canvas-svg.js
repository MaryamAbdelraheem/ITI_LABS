var myCanvas = document.querySelector("canvas");
console.log(myCanvas);

var ctx = myCanvas.getContext("2d");
console.log(ctx);


// set fill color to red
ctx.fillStyle = "red";

// draw rectangle at(50,50) with width=100 and heigh=150
ctx.fillRect(50, 50, 100, 150);
ctx.fillRect(150, 200, 100, 100);

ctx.moveTo(200, 50) //moving to start point     -- start x=200 y=50
ctx.lineTo(250, 150) //draw line to this point  -- end   x=250 y=150
ctx.stroke();

// start new path
ctx.beginPath();

ctx.moveTo(50, 250)
ctx.lineTo(300, 200)
ctx.stroke();