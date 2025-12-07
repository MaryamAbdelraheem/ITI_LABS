

//IIFE
const file1=(function(){
    console.log("File1 ");

     let counter=1;
     let projectName="OS Project";
     let Student=class {};

     return {projectName,Student}; //{projectName:"OS Project", Student:class {}}
}())
