/**
 * node js
 *   import * ad fs from "fs"
 *  
 */

//callback Hell
// fs.readFile("path",(error,data)=>{
//     if(!error)
//     //open file the read data  search id
//     // if(check for id)
    
//      fs.writefile("path",(error)=>{
//          if(!error)
//         //manage error
  
//         //confirmation
//         });

//     // else
//         // Handel Error

// })



/************  Promise is a special type of Object to handel
 *  Async Tasks Especially if we have more than one task, these tasks depend on each others */

// console.log("start");

// getStudentData(2)
// .then((student)=>{
//     console.log(student);
//     return getStudentSubjects(student.subjects);
// })

// .then(subjects=>console.log(subjects))
// .catch(error=>console.log("Error !" +error))

// console.log("end");

/**********  Prmises in ES8   async/await */
// getStudentDetails(10);

// fetch
getStudents();