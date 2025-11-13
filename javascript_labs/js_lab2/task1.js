//1.

    //1.1
/*

(getStudentGrades = ()=>{
    let grade = 0;
    for (let i=0; i< 3 ; i++){
        grade = parseInt(prompt("Enter your grade: "));
        console.log(grade);
    }
})();

*/

    //1.2
/*

(getStudentGrades = ()=>{
    let grade = 0;
    for (let i=0; i< 3 ; i++){
        grade += parseInt(prompt("Enter your grade: "));
    }
    console.log(grade);
})();

*/

    //1.3

/*

(getStudentGrades = ()=>{
    let grade = 0;
    let degree = 0;
    let no_of_students= parseInt(prompt("Enter your students number: "));
    for (let i=0; i< no_of_students ; i++){
        grade = parseInt(prompt(`Enter ${i+1} student grade:` ));
        degree += grade;
        console.log(`${i+1} grade is ${grade}`);
    }
    console.log(`the final geades summution is: ${degree}`);

})();

*/

    //1.4
/*

(getStudentGrades = ()=>{
    let grade = 0;
    let degree = 0;
    let no_of_students= parseInt(prompt("Enter your students number: "));
    for (let i=0; i< no_of_students ; i++){
        grade = parseInt(prompt(`Enter ${i+1} student grade:` ));
        degree += grade;
        console.log(`${i+1} grade is ${grade}`);
    }
    if(no_of_students >= 2 && no_of_students <= 10){
        console.log(`the final geades summution is: ${degree}`);
    }
    else{
        alert(`the final geades summution is: ${degree}`);
    }

})();

*/


    //1.5
/*

(getStudentGrades = ()=>{
    let grade = 0;
    let degree = 0;
    let no_of_students= parseInt(prompt("Enter your students number: "));
    for (let i=0; i< no_of_students ; i++){
        grade = Number(prompt(`Enter ${i+1} student grade:` ));
        if(isNaN(grade)==true){
            degree = 0;
            break;
        }
        else{
        degree += grade;
        console.log(`${i+1} grade is ${grade}`);}
    }
    if(no_of_students >= 2 && no_of_students <= 10){
        console.log(`the final geades summution is: ${degree}`);
    }
    else{
        alert(`the final geades summution is: ${degree}`);
    }

})();

*/

    //1.6
/*

(getStudentGrades = ()=>{
    let grade = 0;
    let degree = 0;
    let no_of_students= parseInt(prompt("Enter your students number: "));
    for (let i=0; i< no_of_students ; i++){
        grade = Number(prompt(`Enter ${i+1} student grade:` ));
        while(isNaN(grade)){
            grade = Number(prompt('please enter valid number'));
        }
        degree += grade;
        console.log(`${i+1} grade is ${grade}`);
        
    }
    if(no_of_students >= 2 && no_of_students <= 10){
        console.log(`the final geades summution is: ${degree}`);
    }
    else{
        alert(`the final geades summution is: ${degree}`);
    }

})();

*/

    //1.7

/*

(getStudentGrades = ()=>{
    let grade = 0;
    let degree = 0;
    let no_of_students= parseInt(prompt("Enter your students number: "));
    for (let i=0; i< no_of_students ; i++){
        grade = Number(prompt(`Enter ${i+1} student grade:` ));
        while(isNaN(grade) || grade < 0 || grade > 100) {
            grade = Number(prompt('please enter valid number'));
        }
        degree += grade;
        console.log(`${i+1} grade is ${grade}`);
        
    }
    if(no_of_students >= 2 && no_of_students <= 10){
        console.log(`the final geades summution is: ${degree}`);
    }
    else{
        alert(`the final geades summution is: ${degree}`);
    }

})();

*/



        




