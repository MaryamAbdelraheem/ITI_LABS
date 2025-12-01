// lab1
//1 create function to register data through prompt (firstName, lastName, age, email, department)
console.log("task 1==============================");
let registerUser = function() {

    let user = {
        fullName:{
            firstName: prompt("Enter your first name:"),
            lastName: prompt("Enter your last name:")},
        age:Number(prompt("Enter your age:")),
        email: prompt("Enter your email:"),
        department: prompt("Enter your department:"),
        toString(){
        return `hello, ${this.fullName.firstName} ${this.fullName.lastName}  , age:  ${this.age} `;
        }
        //for pushing in array

    };
    return user;
    
};
//console.log(registerUser());

console.log("task 2==============================");

//2 create array of students, then start push students coming from previous function into this array.
let students = [];
let counter = Number(prompt("Enter number of students to register:"));

for (let i = 0; i < counter; i++) {
    students.push(registerUser());
}
console.log(students);

console.log("task 3==============================");

//3 find the older student 
students.sort((a, b) => {
    return b.age - a.age;
});
const older_student = students[0]; 

console.log(older_student);
console.log("The older student is: " + older_student.fullName.firstName + " " + older_student.fullName.lastName + ", age: " + older_student.age);


console.log("task 4==============================");
//title case
function convert_to_pascal(fullName) {
    f_name = fullName.firstName.charAt(0).toUpperCase() + fullName.firstName.slice(1).toLowerCase();
    l_name = fullName.lastName.charAt(0).toUpperCase() + fullName.lastName.slice(1).toLowerCase();
    
    return f_name + " " + l_name;
}

console.log(convert_to_pascal(students[0].fullName));
console.log("task 5==============================");

//5 find all students with ages greater than 20

function filter_who_passed(students){
    return students.filter(student => student.age > 20);
}
console.log(filter_who_passed(students));


console.log("task 6==============================");
function find_the_average_age(students){
    let totalAge = students.reduce((sum, student) => sum + student.age, 0);
    return totalAge / students.length;

}
console.log("students average age is : " + find_the_average_age(students));

console.log("task 7==============================");
//7 sort students ascading by first name else   by last name

function ascading_by_name(students){
    return students.sort((a, b) => {
        if (a.fullName.firstName === b.fullName.firstName) {
            return a.fullName.lastName.localeCompare(b.fullName.lastName);
        }
        return a.fullName.firstName.localeCompare(b.fullName.firstName);
    });

}
console.log(ascading_by_name(students));

console.log("task 8==============================");

function createArray(fullNamess,ages){


    let students_array = [];

    for (let i = 0; i < fullNamess.length; i++) {
        students_array.push({
            fullName: fullNamess[i],
            age: ages[i]
        });
    }
    return students_array;
}

let fullNamess = ["Bob Smith", "Alice Johnson", "Charlie Brown"];
let ages = [22, 19, 25];
console.log(createArray(fullNamess,ages));

console.log("task 9==============================");
console.log(students[0]+"");

console.log("task 10==============================");

console.log(students[0].toString());

console.log("task 11==============================");
//convert to json 

let test = ["hellloooo" , "maryaaaaammm"];
console.log(JSON.stringify(test));