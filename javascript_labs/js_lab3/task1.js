//1 remove duplicates (with Set object then without Set) ===================
// without Set
console.log("task1:");
function remove_duplicates(input){
    return input.filter((current,index) => input.indexOf(current)==index);
}
console.log(remove_duplicates([4,4,5,6,7,8])); 

//with set
function remove_duplicates_useSet(input){
    let nums = new Set(input);
    return nums ;
}
console.log(remove_duplicates_useSet([4,4,5,6,7,8])); 

console.log("----------------------------------------------")
console.log("task2:");
//2 reverse each word =====================================================
function reverse_char(word){
    let reversed = "";
    for(let i = ((word.length)-1) ; i>= 0 ; i--){
        reversed+= word[i];
    }
    return reversed;
}

function reverse_array(arr,func){
    let edited_arr=[];
    for (let item of arr){
        item = func(item);
        edited_arr.push(item);
    }
    return edited_arr;
}

console.log(reverse_array(["mrym","omar","mhmd"],reverse_char));
console.log("----------------------------------------------")
console.log("task3:");
//3========================================================================
function get_even_multiply2(input){
    return input.filter((number) => number % 2 == 0 )
    .map(number => number * 2);
}

console.log(get_even_multiply2([2,3,4,5,6,7]));
console.log("----------------------------------------------")
console.log("---------------++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++----------------")


console.log("task4:");

//4 find second_largest_number no sort
function second_largest_number(input){
    let largest = 0;
    let second_large = 0;

    for (let i =0; i<input.length;i++){
        if(input[i]>largest){
            second_large=largest;
            largest = input[i];}
        else if(input[i]>second_large && input[i]!= largest){
            second_large=input[i];
        }
    }
    return second_large;

}
console.log(second_largest_number([1,2,3,4,5,6,7,8,9]));
console.log("----------------------------------------------")

console.log("task5:");
//5 split the array to odd & even

function split_array_to_even_odd(input){
    let odd_chars = [];
    let even_chars = [];


    for(let i = 0; i<input.length;i++){
        if (input[i].charCodeAt(0) % 2 == 0){
            even_chars.push(input[i]);
        }
        else
        {
            odd_chars.push(input[i]);
        }
    }
    console.log(even_chars);
    console.log(odd_chars);
}

split_array_to_even_odd(['a','b','c','d','e']);

console.log("----------------------------------------------")
console.log("task6:");

function countNumbers_GreaterThan50(input){
    let count = 0;

    for (let i =0; i<input.length;i++){
        if(input[i]>50)
            count++;
    }
    console.log(count);
}

countNumbers_GreaterThan50([1,2,3,4,80,90,100]);
console.log("----------------------------------------------")
console.log("task7:");

function largest_word(input){
    let longest_word = "";

    for (let item of input){
        if(item.length > longest_word.length)
            longest_word = item; // صح هنا
    }
    
    return longest_word;
}

console.log(largest_word(["hi","items","welcome","to_loooop"]));


console.log("----------------------------------------------")
console.log("task8:");
function generate_random_array(length,min,max){
    let array =[];
    array[0]=min;
    array[length-1]=max;
    //0,1,2,3,4
    for(let i= 1; i< length-1 ; i++){
        array[i] = Math.round( min + Math.random() * (max - min));
    }

    return array;
}

console.log(generate_random_array(7,10,50));

console.log("----------------------------------------------")
console.log("task9:");
function round_up(array){

    return array.map((item) => Math.round(item));
}
console.log(round_up([1,2,3.7,4.5]));

console.log("----------------------------------------------")
console.log("task10:");
function days_using_dates(array){
    let days_array =[];
    let today = new Date();
    let diff = 0;

    for (let item of array){
        let date = new Date(item);
        diff = Math.round((today - date)/(1000*60*60*24));
        days_array.push(diff);
    }
    return days_array;
}

console.log(days_using_dates(["1-10-2024","1-12-2025"]));


console.log("----------------------------------------------")
console.log("task11:");

function array_by_date(array){
    return array.sort((a,b)=> new Date(a) - new Date(b));
}
console.log(array_by_date(["1-10-2024","9-12-2025","3-12-2025"]));
//MM-DD-YYYY
