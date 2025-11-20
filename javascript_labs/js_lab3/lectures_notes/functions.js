const switchCase=(input)=>{
       input=input.split("");
        console.log(input);
        for(let i=0;i<input.length;i++)
        {
            if(input[i]==input[i].toLowerCase())
                input[i]=input[i].toUpperCase()
            else
                input[i]=input[i].toLowerCase()

        }
    return input.join("");

}


// Task 1: create function to return numbers grater than number
const filterGraeterThan=(array,number)=>{
    let result=[];
        for(let i=0;i<array.length;i++)
        {
            if(array[i]>number)
                result.push(array[i])
        }

    return result;
}


const filterLessThan=(number)=>{
    return number<2;
}

//task generuic function
const filter=(array,condition)=>{ // consdition is callBackFunction

    //filter(grades,userName)    array=grades , condition=userName
    //filter(numbers,switchCase) array=numbers , condition=switchCase
    let result=[];
        for(let i=0;i<array.length;i++)
        {
            if(condition(array[i],i,array))
                result.push(array[i])

        }
        console.log(array);
        console.log(condition);
    return result;

}





