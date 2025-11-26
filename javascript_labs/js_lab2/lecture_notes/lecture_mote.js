/**
 * 1. Function declaration
 * 
 * //noramal declaration :
 * function sumVars(){
 *  let result = 0
 *  for(let i=0; i< arguments.length;i++){
 *        result+=argument[i];
 *   }
 *  return result;
 * }
 * 
 * /////////////////////////////////////////////////
 * 
 * 2. Expression function
 * 
 * // const/var getDetails = function(){
 *      console.log('welcome from expression function');
 * };
 * clg(getDetails);
 * //its not hoisted. 
 * 
 * /////////////////////////////////////////////////
 * 
 * 3. Arrow function(suger function)
 * 
 * //same as expression but in different way: 
 * 
 * //       The struct: [[const/var = (i/p) => {o/p}]]
 * 
 * const arr = () =>{
 *  //body;
 * }
 * 
 *          ++ suger expression: 
 *                  const arr = id => return clg(`welcome from suger function`);   
 * 
 * /////////////////////////////////////////////////
 * 
 * 4. IIFF function
 * 
 * //run immedietly withput calling:
 *      (function arr (){
 *          return  clg(`welcom from IIFF`);
 *       })();
 * 
 * 
 * 
 * 5. Callback function
 * 
 * 
 * 
 * 
 * 
 */


