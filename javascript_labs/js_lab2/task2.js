// level 1:

//1.1
function find_length(){
    let word = prompt('enter a word');
    console.log(word.length);
}
//1.2
function convertToLower(){
    let word = prompt('enter a word');
    let result = "";
    for(let i =0; i< word.length;i++){
        if(word[i]== word[i].toUpperCase()){
            result+= word[i].toLowerCase();
        }
        else{
            result+=word[i];
        }
    
    }
    return result;
}
//1.3
function convertToUpper(){
    let word = prompt('enter a word');
    let result = "";
    for(let i =0; i< word.length;i++){
        if(word[i]== word[i].toLocaleLowerCase()){
            result+= word[i].toUpperCase();
        }
        else{
            result+=word[i];
        }
    
    }
    return result;
}

//1.4
function charExtractor(){
    let word = prompt('enter a word');
    let first = 0;
    let last = (word.length)-1;
    let mid = (word.length)/2;

    console.log(word[first]);
    console.log(word[mid]);
    console.log(word[last]);

}

//1.5
function  concatination(){
    let first_name = prompt("enter your first name: ");
    let last_name = prompt("enter your ladt name: ");

    alert(`Hello, ${first_name} ${last_name}`);
}

//1.6
function removing_part_of_string(){
    let name = prompt("enter your full name: ");
    let edited = name.substring(0,((name.length)-4));
    console.log(edited);

}

//level 2==================================================
//2.1

function find_a_word(){
    let sentence = prompt('enter a sentence: ');
    let word = prompt('enter the word you want: ')

    if(sentence.includes(word))
        alert('the word is in the sentence. <333');
    else{
        alert('the word is not in the sentence');
    }
}

//2.2
function replace_a_word(){
    let sentence = prompt('Enter your sentence:');
    let current_word = prompt('Enter the word you want to replace:');
    let change_word = prompt('Enter the new word:');

    let after_change = sentence.replace(current_word, change_word);
    alert(`Your new sentence is: ${after_change}`);
}

//2.3
function count_occurence()
{
    let count = 0;
    let sentence = prompt('enter a sentence ');
    let char = prompt('enter the letter you count: ');

    for (let i = 0; i < sentence.length;i++){
        if(sentence[i] == char)
            count++;
    }

    alert(` the character ${char} has been counted : ${count}`);
}

//2.4
function starts_or_ends() {
    let sentence = prompt('Enter a sentence:');
    let sub_string = prompt('Enter the substring:');

    if (sentence.startsWith(sub_string)) {
        alert(`The sentence starts with "${sub_string}"`);
    } else if (sentence.endsWith(sub_string)) {
        alert(`The sentence ends with "${sub_string}"`);
    } else {
        alert(`The sentence neither starts nor ends with "${sub_string}"`);
    }
}


//2.5
function remove_space(){
    let sentence = prompt('Enter a sentence:');
    let edited_sentence = sentence.replaceAll(" ", "");

    alert(`edited_sentence: ${edited_sentence}`);
}


//level 3==================================================
//3.1
function extract_domain() {
    let email = prompt('Enter your email:');

    if (!email.includes('@')) {
        alert(' Invalid email!');
        return;
    }

    // Get everything after '@'
    let domain = email.substring(email.indexOf('@') + 1);

    alert(`The domain of your email is: ${domain}`);
}


//3.2
function initial_generator() {
    let fullName = prompt("Enter your full name:");
    let initials = fullName[0]; // first character

    // loop through string to find letters after spaces
    for (let i = 0; i < fullName.length; i++) {
        if (fullName[i] === ' ' && i + 1 < fullName.length) {
            initials += fullName[i + 1];
        }
    }

    alert(`Your initials are: ${initials.toUpperCase()}`);
}
//3.3
function reverse_string() {
    let str = prompt("Enter a string to reverse:");
    let reversed = "";

    for (let i = str.length - 1; i >= 0; i--) {
        reversed += str[i];
    }

    alert(`Reversed string: ${reversed}`);
}

//3.4
function plindrome_checker() {
    let str = prompt("Enter a string:");
    let reversed = "";

    for (let i = str.length - 1; i >= 0; i--) {
        reversed += str[i];
    }

    if (str === reversed) {
        alert(" This string is a palindrome!");
    } else {
        alert(" Not a palindrome.");
    }
}

//3.5
function count_vowel() {
    let str = prompt("Enter a string:");
    let count = 0;

    for (let i = 0; i < str.length; i++) {
        let ch = str[i].toLowerCase();
        if (ch === 'a' || ch === 'e' || ch === 'i' || ch === 'o' || ch === 'u') {
            count++;
        }
    }

    alert(`Number of vowels: ${count}`);
}
//level 4==================================================
//4.1
function title_case(){
    let input = prompt("Enter your full name:");
    let result = "";
    let capitalize_next = true;

    for (let i = 0; i < input.length; i++) {
        let char = input[i];

        if (char === " ") {
            result += " ";
            capitalizeNext = true;
        } else if (capitalizeNext) {
            result += char.toUpperCase();
            capitalizeNext = false;
        } else {
            result += char.toLowerCase();
        }
    }

    console.log("Hello, " + result + "!");
}

//4.2
function masking(){
    let input = prompt("Enter a phone number (e.g., 01098987876):");
    let mask="";
    for(var i =0; i<input.length;i++){
        if(i < input.length-4)
            mask+="*"
        else
            mask+= input[i];
    }
    console.log(mask);
}

//4.3
function longest_word(){
    let current_word = "";
    let longest_word = "";
    let sentence = prompt('enter your sentence: ');

    for (let i = 0; i < sentence.length ; i++){
        let char = sentence[i];

        if (char != " ")
            current_word += char;
        else{
        // word ended → compare
        if(current_word.length > longest_word.length){
            longest_word = current_word;}
        current_word="";
        }
    }

    // check last word (if no trailing space)
    if (current_word.length > longest_word.length) {
        longest_word = current_word;
    }
    
    alert(`your longest word is: ${longest_word}`);
}


//4.4
function remove_repeated_chars(){
    let unique = "";
    let input = prompt('enter you chars: ');
    for (let i = 0; i <input.length;i++){
        if (!unique.includes(input[i]))
            unique+= input[i];
    }
    alert(`your uniqe unrepeated characters are: ${unique}`);
}




