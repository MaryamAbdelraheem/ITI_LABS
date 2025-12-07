//1- destructuring with import
// import {projectName}  from "./file3.js"
// console.log("Testing file 5",projectName);

//2- get all object properties
// import * as  file3 from "./file3.js";
// console.log(file3.projectName);

//3- run the file  (example : run file contains for example database connection setting)
import  "./file3.js";


//file counter (2 scripts have the same name)
//import * as file3 from "./file3.js"   file3.counter
//import {counter} from "./file4.js";

//import {counter as counterFile3} from "./file3.js"   
//import {counter} from "./file4.js";




