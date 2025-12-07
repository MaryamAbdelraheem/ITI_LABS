const getStudentData=function(id){
    return new Promise((resolve , reject)=>{
        setTimeout(() => {
            resolve({id,name:"xxx",age:20,subjects:[1,2,3]});
            reject(`Can't find student with id ${id}`)
        }, 3000);
    });
}

const getStudentSubjects=function(subjects){
    return new Promise((resolve , reject)=>{
        setTimeout(() => {
            resolve(
                [
                    {id:1, name:"JS",hours:30},
                    {id:1, name:"ES",hours:18},
                    {id:1, name:"advJS",hours:12}
                ]);
            // reject(`Can't find student with id ${id}`)
        }, 3000);
    });
}


//ES8
const getStudentDetails=async function(id){

    try{
        let student=await  getStudentData(id);
        let subjects=await getStudentSubjects(student.subjcets);
        console.log("student",student);
        console.log("subjects",subjects);
    }catch(error)
    {
        console.log(error);
    }
    
}

// using fect exixting function in native JS that returns a promise to consume

const getStudents=async function(){

    try
    {
        let repsponse=await fetch("http://localhost:8080/students");
        let students=await repsponse.json();
        console.log(students);
    }catch(error)
    {
        console.log(error);
    }

}














