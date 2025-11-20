/**
 * JS Objects 
 * 1- Language Objects (String, Arrays , Math, Date ....)
 * 2- UserDefined Objects (Anonymous Objects , Classes)
 */

// Arrays 
let grades= new Array(1,2,3);
// new Array(5)
let numbers=[1,2,3,4];  //shortcut
let userName="eman";
// console.log(grades.constructor.name);
// console.log(numbers.constructor.name);
//push , pop , unshift , shift , splic(search), join , indexOf , includes
// woreste case  --> sparse array numbers[7]=7

/***********   For loops in javascript */
// built-in (foreach) , for loop , for in(special case) , for of
// numbers[100]=9;
// for(let i=0;i<numbers.length;i++)
// {
//     console.log(numbers[i]);   
// }
// console.log("***********************")
// for(let index in numbers)
// {
//     console.log(numbers[index]);   
// }
// console.log("***********************")
// for(let item of numbers)
// {
//     console.log(item);
// }


// if(1 in numbers){}
//-- Using callBack functions
// Filter array
// filter(numbers,filterLessThan);
// filter(numbers,filtergreaterThan);
// filter(numbers,filterInBetweenThan);

// next
// filter([1,2,3,4],function(number){return number>3});// Anunymouse function
// filter([1,2,3,4],function(number){return number<3});// Anunymouse function

// //next
// filter([3,5,1,6,8,4],number=>number<3);
// filter([3,5,1,6,8,4],number=>number>5);

//  foreach , sort , map , reduce , etc....


//task : multiply each item 2 
//return new array
// let result=[];
// numbers.forEach((number,index)=>{
    
//     result.push(number*2);
//     console.log(result);
// });

// let numbers_2=numbers.map(number=>number*2);

// change Origuinal array
// numbers.forEach((number,index,array)=> array[index]*=2);


//reduce
//Task : calcualte summition of all array numbers
//[1,2,3,4]
numbers.reduce((prev,current)=>prev+=current,0);

//1- (0,1) => 1
//2- (1,2) => 3
//3- (3,3)

// let sum=0;
// for(let i in numbers)
// {
//     sum+=numbers[i]
// }
// sum

// Task : generate new array caontans sqrt value of array item

// numbers.map(number=>Math.sqrt(number));
// numbers.map(Math.sqrt);// recommended
numbers=[3,1,6,7,5,10];
let names=["eman","mona","ahmed","Hala"];
// console.log(numbers);
// numbers.sort();
// console.log(numbers);

// numbers.sort((a,b)=>{
//     if (a>b) return 1;
//     else if(a<b) return -1;
//     else return 0;
// })


// numbers.sort((a,b)=> a-b);

// students  (id, firstName, lasdtname, grade)

/************ ES6   ... operator   rest & spread  */
//spread
//1- calling function
// Math.min(...numbers)
//2- copy of array
let newNumbers=numbers.map(number=>number);
newNumbers=[...numbers];
//3- concat
let studentsGrades=[...numbers, ...grades,30, 50, ...newNumbers];


// rest 
// const sum=function()
// {
//     // let result=0;
//     // for(let i=0;i<arguments.length;i++)
//     //     result+=arguments[i]; --> array-like
//     // return result;

//     // let result=[];
//     // for(let i=0;i<arguments.length;i++)
//     //     result.push(arguments[i]);

//     // return result.reduce((prev,current)=>prev+=current,0);
// }

// const sum=function(...input)
// {
//     console.log(input); 
//     return input.reduce((prev,current)=>prev+=current,0);
// }

// sum(1,2);
// sum(1,2,5);

//----------- Testing
numbers+1;
numbers+"eman";
names+1

let number;  // empty values false values
if(!number)
    console.log("number is empty")
else
    console.log("number is ",number);
