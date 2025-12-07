let nameInput = document.querySelector("input[name='studentName']");
let gradeInput = document.querySelector("input[name='studentGrade']");
let addBtn = document.querySelector("input[type='button']");
let nameError = document.getElementById("nameError");
let gradeError = document.getElementById("gardeError"); 
let sortSelect = document.querySelectorAll("select")[0];
let filterSelect = document.querySelectorAll("select")[1];
let table = document.getElementById("studentsData");

let students = [];



// VALIDATE NAME
function validateName(name) {
    nameError.textContent = "";
    console.log("Validating name:", name);
    if (name === "") {
        nameError.textContent = "Name is required";
        nameError.style.display = "inline";
        console.log("name required");
        return false;
    }

    let formatted = name[0].toUpperCase() + name.slice(1).toLowerCase();

   for (let i = 0; i < students.length; i++) {
    if (students[i].name === formatted) {
        nameError.textContent = "Name already exists";
        nameError.style.display = "inline";
        console.log("name already exists");
        return false;
    }
}
    nameError.style.display = "none";
    return formatted;
}



// VALIDATE GRADE
function validateGrade(g) {
    gradeError.textContent = "";

    if (g === "" || isNaN(g)) {
        gradeError.textContent = "Grade must be a number";
        console.log("grade should be no.");
        return false;
    }

    let grade = Number(g);

    if (grade < 0 || grade > 100) {
        gradeError.textContent = "Grade must be 0–100";
        console.log("range error");
        return false;
    }

    return grade;
}
console.log("validateGrade:", validateGrade());



// RENDER TABLE
function renderTable(list) {
    table.innerHTML = "";

    list.forEach(student => {
        let tr = document.createElement("tr");

        if (student.grade < 60) tr.style.background = "lightcoral";
        else if (student.grade < 80) tr.style.background = "lightblue";
        else tr.style.background = "lightyellow";

        let nameTD = document.createElement("td");
        nameTD.textContent = student.name;

        let gradeTD = document.createElement("td");
        gradeTD.textContent = student.grade;

        let delTD = document.createElement("td");
        delTD.innerHTML = "🗑️";
        delTD.style.cursor = "pointer";
        delTD.onclick = function () {
            students = students.filter(s => s.name !== student.name);
            renderTable(students);
        };

        tr.append(nameTD, gradeTD, delTD);
        table.appendChild(tr);
    });
}

// ADD BUTTON
addBtn.addEventListener('click', function() {
    
    const validName = validateName(nameInput.value);
    const validGrade = validateGrade(gradeInput.value);

    if (validName && validGrade !== false) {
        students.push({
            name: validName,
            grade: validGrade
        });

        //nameInput.value = "";
        //gradeInput.value = "";
        renderTable(students);
    }
    
});


// SORTING
sortSelect.onchange = function () {
    if (this.value === "name") {
        students.sort((a, b) => a.name.localeCompare(b.name));
    } else {
        students.sort((a, b) => a.grade - b.grade);
    }
    renderTable(students);
};


// FILTER (SUCCESS / FAIL / ALL)
filterSelect.onchange = function () {
    if (this.value === "all") {
        renderTable(students);
    } else if (this.value === "success") {
        renderTable(students.filter(s => s.grade >= 60));
    } else {
        renderTable(students.filter(s => s.grade < 60));
    }
};


console.log("JS Loaded!");





