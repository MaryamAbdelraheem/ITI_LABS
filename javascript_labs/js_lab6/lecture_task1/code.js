//1  Using document object method on the lecture’s HTML page
//a find all images in page by two ways 
//a.1 document default collection
console.log("FIND IMGS BY DEFAULT COLLECTION: ")
let images_by_default_collection = document.images;
console.log(images_by_default_collection)



//a.2 document methods 
console.log("++++++++++++++++++++++++++++++++")
console.log("FIND IMGS BY METHODS: ")
let images_by_method=document.getElementsByTagName("img");
console.log(images_by_method);




//b  Find all options for City drop down list
console.log("++++++++++++++++++++++++++++++++")
console.log("FIND OPTIONS OF CITY DROPDOWN LIST: ")
let city_options = document.getElementsByTagName("select")[0].getElementsByTagName("option");

console.log(city_options );
for(let i =0 ; i<3;i++){
    console.log(`OPTION ${i+1}: ` + city_options[i].innerHTML);
}



//c Find all rows for second table in page
console.log("++++++++++++++++++++++++++++++++")
console.log("FIND ROWS OF SECOND TABLE: ")
let tables = document.getElementsByTagName("table");
let second_table_rows = tables[1].getElementsByTagName("tr");
console.log(second_table_rows);

for(let i =0 ; i<second_table_rows.length;i++){
    console.log("------------------------------");
    console.log(`ROW ${i+1}: ` + second_table_rows[i].innerHTML);
}

console.log("------------------------------");




//d Find all elements that contain class name fontBlue and bGrey
console.log("++++++++++++++++++++++++++++++++")
console.log("FIND ELEMENTS WITH CLASS NAME fontBlue AND BGrey: ")
let elements_with_class = document.getElementsByClassName("fontBlue bGrey");
console.log(elements_with_class);

for(let i =0 ; i<elements_with_class.length;i++){
    console.log(`ELEMENT ${i+1}: ` + elements_with_class[i].innerHTML);
}

////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\



//2  Do the following actions on the following HTML elements
/*a 
Get first anchor inside the second table then change its’ href
property to training.com and it’s text to “Training”*/

console.log("++++++++++++++++++++++++++++++++")
console.log("CHANGE FIRST ANCHOR INSIDE SECOND TABLE: ")
let first_anchor_in_second_table = tables[1].getElementsByTagName("a")[0];
first_anchor_in_second_table.href = "http://training.com";
first_anchor_in_second_table.innerHTML = "Training";

console.log("AFTER CHANGING: ");
console.log('the href : '+first_anchor_in_second_table.href);
console.log('the text : '+first_anchor_in_second_table.innerHTML);





//b Find all images and change its borders to : solid pink 2px
console.log("++++++++++++++++++++++++++++++++");
console.log("CHANGE BORDER OF ALL IMAGES TO SOLID PINK 2PX: ")
for(let i =0 ; i<images_by_method.length;i++){
    images_by_method[i].style.border = "solid pink 2px";
    console.log(`IMAGE ${i+1} BORDER STYLE: ` + images_by_method[i].style.border);
}





/*c  
Find all checkboxes (checked) in userData form and alert
their values*/
console.log("++++++++++++++++++++++++++++++++");
console.log("ALERT VALUES OF CHECKED CHECKBOXES IN USERDATA FORM: ")
let userData_form = document.getElementsByTagName("form")[1];
console.log(userData_form);
let checkboxes = userData_form.querySelectorAll('input[type="checkbox"]:checked');

checkboxes.forEach((checkbox, index) => {
    console.log(`CHECKBOX ${index + 1} VALUE: ` + checkbox.value );
});




/*d Find element with id value “example” then change it’s
background color to pink*/
console.log("++++++++++++++++++++++++++++++++");
let example_element = document.getElementById("example");
example_element.style.backgroundColor = "pink";
console.log("CHANGE BACKGROUND COLOR OF ELEMENT WITH ID 'example' TO PINK: ")
console.log('NEW BACKGROUND COLOR: ' + example_element.style.backgroundColor);


////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


/** 3
     Display the date with time on the document title (which
    changed every second to show time with date).
    Note: use .toLocalString() method of the Date Object.
 */

console.log("++++++++++++++++++++++++++++++++");
console.log("DISPLAY DATE WITH TIME ON DOCUMENT TITLE EVERY SECOND: ")
setInterval(() => {
    let currentDate = new Date();
    document.title = currentDate.toLocaleString();
}, 1000);

////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
