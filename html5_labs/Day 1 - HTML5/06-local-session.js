// localStorage.setItem("name", "ali");
// localStorage.setItem("theme", "dark");
// localStorage.setItem("course", "JS");

// var userName = localStorage.getItem("name");
// console.log(userName);

// localStorage.removeItem("theme");

// // localStorage.clear();
// for (i = 0; i < localStorage.length; i++) {
//     var key = localStorage.key(i);
//     console.log(`${key} , ${localStorage.getItem(key)}`)
//     console.log(`${localStorage.getItem(key)}`)
// }


// zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz

sessionStorage.setItem("name", "ahmed");
sessionStorage.setItem("city", "cairo");

var userName = sessionStorage.getItem("name");
console.log(userName);

// sessionStorage.removeItem("city");
// sessionStorage.clear()

for (i = 0; i < sessionStorage.length; i++) {
    var key = sessionStorage.key(i);
    console.log(`${key} , ${sessionStorage.getItem(key)}`)
}

