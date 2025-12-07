/**
 *  Testing this with arrow functions
 */
let addBtn=document.querySelector("input[value=Add]");
let studentTable=document.querySelector("#studentsData");
let studentNameTxtBox=document.querySelector("input[name=studentName]");
let studentGradeTxtBox=document.querySelector("input[name=studentGrade]");
let students=[];

addBtn.onclick=async function(){
      let departmetRadio=document.querySelector("input[name=Department]:checked")

      let student=new Student(
            studentNameTxtBox.value,
            // studentGradeTxtBox.value,
            departmetRadio.value
      )
      try
      {
          let response=await fetch("http://localhost:8080/studentss",{
          method:"post",
          headers:{
            "content-type":"application/json"
          },
          body:JSON.stringify(student)
        });
       if( response.status!==200)
        throw new Error("")
        let data=await  response.json();
        console.log(data); 

          //1- sending object to server   --> JSON.stringify(student)
        //2- add student on screen
        students.push(student);
        studentTable.append(createStudentRow(student));

      }catch(error)
      {
        console.log(error)
      }
      
      
    // change BG color depends on Track name


}

//filter
let scuccesStudnets=students.filter(obj=>obj.grade>=60);
studentTable.innerHTML="";
for(let object of scuccesStudnets)
{
  studentTable.append (createStudentRow(obj));
}



/// create Car Object 

let car={
    model:"PMW",
    year:2020,
    speed:0,
    move(){
            setInterval(()=>{
                console.log("interval",this);
                    this.speed+=20;
            },1000)
    }
}



