//lab2
//1
console.log("task1 ======================================");

let names = ['alice', 'smith', 'charlie','mrym'];
let ages = [22, 35, 18];

function createUsers(namesArray, agesArray) {
    let users = [];
    for (let i =0 ; i < namesArray.length; i++) {
        users.push({
            name: namesArray[i],
            age: agesArray[i]
        });
    }
    return users;
}
console.log(createUsers(names, ages));

console.log("task2 ======================================");
//2
function count_frequent(array) {
    let freq = {
        
    };    // object to count

    for (let item of array) {
        if (freq[item]) {
            freq[item]++;      // if exists increase
        } else {
            freq[item] = 1;    // if first time make 1
        }
    }

    // convert object to array of [key, value]
    return Object.entries(freq);
}

console.log(count_frequent(['a','a','n','n','b']));

//frequency array

console.log("task3 ======================================");
function group_grades(array){
    let result = {
        A: [],
        B: [],
        C: [],
        D: [],
        F: []
    };
    for (let item of array){
        if (item >= 90){
            result.A.push(item);
        }
        else if (item >= 80){
            result.B.push(item);
        }
        else if (item >= 70){
            result.C.push(item);
        }
        else if (item >= 60){
            result.D.push(item);
        }
        else {
            result.F.push(item);
        }
    }
    return result;
}

console.log(group_grades([95,82,60,45,77,88]));
console.log("task4 ======================================");

let Names = ['alice bob', 'bob smith', 'smith charlie'];
let grades = [90, 83, 45];
    let students = [];
function convert_to_pascal(namesArray, gradesArray) {
    for (let i =0 ; i < namesArray.length; i++) {
        students.push({
            name: title_case(namesArray[i]),
            grade: gradesArray[i]
        });
    }
    
    return students;
}

;
console.log(convert_to_pascal(Names, grades));

function title_case(input){
    let result = "";
    let capitalize_next = true;

    for (let i = 0; i < input.length; i++) {
        let char = input[i];

        if (char === " ") {
            result += " ";
            capitalize_next = true;
        } else if (capitalize_next) {
            result += char.toUpperCase();
            capitalize_next = false;
        } else {
            result += char.toLowerCase();
        }
    }

    return result ;
}

console.log("task5 ======================================");

function sort_descending(students){
    return students.sort((a, b) => b.grade - a.grade);
}

console.log(sort_descending(students));


console.log("task6 ======================================");
function highest_grade(students){
    let sorted_students = sort_descending(students);
    return sorted_students[0];
}
console.log(highest_grade(students));

console.log("task7 ======================================");

function filter_who_passed(students){
    return students.filter(student => student.grade >= 60);
}
console.log(filter_who_passed(students));

console.log("task8 ======================================");
function conversion(students){
    return students.map( (student) => student.name + "" + student.grade);
}
console.log(conversion(students));


console.log("task9 ======================================");
let names_list = ['Ali', 'Bob', 'Charlie', 'David'];
function count_students_with_names_4(students){
    return students.filter(student => student.length >= 4);
 }
console.log(count_students_with_names_4(names_list));

console.log("task10 ======================================");
function createBook(_title, _author, _year, _price){
    let book = {
    title :_title,
    author:_author,
    year :Number(_year),
    price:Number(_price),
    applyDiscount (percentage){
    this.price = this.price - (this.price*percentage)/100 ;
    }
};

    return book;
}

function isClassic(book){
    return Boolean((2025 - book.year) > 20);
}


let myBook = createBook("The Great Gatsby", "F. Scott Fitzgerald", 1925, 10.99);
let book2 = createBook("To Kill a Mockingbird", "Harper Lee", 1960, 7.99);
let book3 = createBook("The Catcher in the Rye", "J.D. Salinger", 2023, 6.99);

let books =[];
books.push(myBook);
books.push(book2);
books.push(book3);

console.log(myBook);
console.log(book2);
console.log(book3);
console.log("====================");

console.log(isClassic(myBook));
console.log(isClassic(book2));
console.log(isClassic(book3));

console.log("====================");

for (let book of books){
    if(2025 - book.year > 10){
        book.applyDiscount(10)
    }
    console.log(book);
}

