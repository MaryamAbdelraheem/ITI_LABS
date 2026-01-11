const canvas = document.getElementById('circleCanvas');
const ctx = canvas.getContext('2d');
const button = document.getElementById('generateCircleBtn');

// Make canvas full screen
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function getTheSelectedColor() {
    return document.getElementById('colorPicker').value;
}

function drawCircle() {
    const radius = getRandomInt(20, 50);
    const x = getRandomInt(radius, canvas.width - radius);
    const y = getRandomInt(radius, canvas.height - radius);
    const color = getTheSelectedColor();

    ctx.beginPath();
    ctx.arc(x, y, radius, 0, Math.PI * 2);

    // white inside
    ctx.fillStyle = 'white';
    ctx.fill();

    // colored border
    ctx.strokeStyle = color;
    ctx.lineWidth = 4;
    ctx.stroke();
}

button.addEventListener('click', drawCircle);