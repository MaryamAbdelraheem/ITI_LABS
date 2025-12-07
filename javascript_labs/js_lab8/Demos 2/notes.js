
//---------------------------------------
constructor(top, left, source) {
    super(source);
    this.top = top;
    this.left = left;
    this.image = document.createElement("img");
    this.image.src = source;
    this.image.style.position = "absolute";
    this.updatePosition();
    document.body.appendChild(this.image);
}

//----------------------------------

let bird=new Bird(0,0,"images/bird.png");

bird.imag


class Bird
{
constructor( top, left, source = "../images/bird.gif",conatiner) {
    super();
    this.top = top;
    this.left = left;
    this.source = source;
    this.#createBird(conatiner)    
    this.imageElement = this.#createBird();
    Engin.count++;
}

#createBird(container) {
    let imag = document.createElement("img");
    imag.src = this.source;
    imag.style.top = this.top + "px";
    imag.style.left = this.left + "px";
    imag.style.position = "absolute";
    container.append(imag);
    console.log(imag.style.top, imag.style.left);
    // console.log(document.body);
    // alert("dddddd")
    retrun imag;
}




