//search**************************************************************
//1. 
'use strict';

//2.
var number = 30;

console.log(number.toString());    // "30"   (default base 10)
console.log(number.toString(2));   // "11110" (binary)
console.log(number.toString(8));   // "36"    (octal)
console.log(number.toString(16));  // "1e"    (hexadecimal)

//********************************************************************

//----------------------------------------------------------------------------

//2. define 3 numbers variables with different values:

//a
//var number1=3 ;
var number2=2.9 ,number3=0xff;


var firstName = "maryam";
var middleName = 'abdelraheem';
var lastName = `alkhawagh`;

//b
var flag = true;

//c
console.log("this is the external Javascript file");

//----------------------------------------------------------------------------

//3.

//a 
console.log(number1);
var number1=3 ;

//b internal script:

//define before the external file :
/*Uncaught ReferenceError: number1 is not defined

//print the clg line from external:
this is the external Javascript file

//print the value before declration:
undefined

//print the number1 value after the external file:
3

*/


//e. try to change the value:
/* 
since the declarion with var :


number1 = 20;
number2 = 30;
number3 = 40;

console.log(number1); //20
console.log(number2); // 30
console.log(number3); // 40

*/

//f

/*try to change in the string name : 

firstName[3] = 'A';
console.log(firstName); //maryam

//result still as its
*/

//g
console.log(typeof  number1);  //number
console.log(typeof number2) ; //number
console.log(typeof number3) ; //number
console.log(typeof firstName) ;//string
console.log(typeof middleName); //string
console.log(typeof lastName) ;//string

//----------------------------------------------------------------------------


//4.

//== at html file ==

//----------------------------------------------------------------------------

//5. 
//write script to check if a given number is odd or even

//1.if condition:
if(number1 % 2 == 0)  //3 is odd 
{
    console.log(`${number1} is even`);
}
else
{
    console.log(`${number1} is odd`);
}
//----------------------------------------------------------------------------

//6.
//print number 1 to 10 using loops
for(var i=0; i<=10;i++){
    console.log(i);
} // 0/1/2/3/4/5/6/7/8/9/10

//----------------------------------------------------------------------------


//7. check if number is –ve , +ve or zero
var flag = true;
if(number1 >= flag){
    console.log('+ve');
}
else if(number1 < !(flag) ){
    console.log('-ve');
}
else{
    console.log('zero');
}
//----------------------------------------------------------------------------

//8.multiplication table for any number in console
function multiplicationTable(num){
    for(var i=1;i<=11;i++){
        console.log(i*num);
    }
}

multiplicationTable(5); 
multiplicationTable(9);
//----------------------------------------------------------------------------

//9.
/*Write a program that takes a number from 1 to 7 and prints the
corresponding day of the week (e.g., 1 -> "Sunday", 2 ->
"Monday", etc.)*/

function weekDays(day){
    if(day == 1){
        console.log('sunday');}
    else if(day == 2){
        console.log('monday');}
    else if(day == 3){
        console.log('tuesday');}
    else if(day == 4){
        console.log('wednesday');}
    else if(day == 5){
        console.log('thursday');}
    else if(day == 6){
        console.log('friday');}
    else if(day == 7){
        console.log('saturday');}
}

weekDays(2); //monday
weekDays(4); //wedsday
weekDays(7); //saturday
//----------------------------------------------------------------------------

//10.
function checkDayType(day) {
  if (day === 1 || day === 7) {
    console.log("It's a weekend!");
  } else if (day >= 2 && day <= 6) {
    console.log("It's a weekday.");
  } else {
    console.log("Invalid day number! Enter 1–7.");
  }
}

checkDayType(1); // weekend
checkDayType(3); // weekday
checkDayType(7); // weekend

//----------------------------------------------------------------------------