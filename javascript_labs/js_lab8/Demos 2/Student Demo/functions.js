//IFEE
(
    async function(){

    try
    {
        let repsponse=await fetch("http://localhost:8080/students");
        let students=await repsponse.json();
        console.log(students);

        for(let student of students)
            createStudentRow(student);
    }catch(error)
    {
        console.log(error);
    }

}

)()



const createStudentRow=function(student){
      let trElm=  document.createElement("tr");
      studentTable.append(trElm);
             
        for(let property in student)
        {
            let tdElem=document.createElement("td");
            tdElem.innerText=student[property];
            trElm.append(tdElem);
        }
        // adding delete button
            let tdElem=document.createElement("td");
            trElm.append(tdElem);
            let deleteBtnElem=document.createElement("button");
            deleteBtnElem.innerText="Delete";
            tdElem.append(deleteBtnElem);

        //handel delete
        deleteBtnElem.onclick=function(){
            this.parentElement.parentElement.remove()
        }
  return trElm;    
}