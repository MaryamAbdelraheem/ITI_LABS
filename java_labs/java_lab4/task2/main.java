import MyExceptionThrower.customExeception;

public class main {
    public static void main(String[] args){
        customExeception MyExceptionThrower = new customExeception();
        try{
            MyExceptionThrower.methodOne(-5.0);
        } catch (MyExceptionHandling.MyException e){
            System.out.println(e.getMessage());
        }
        try{
            MyExceptionThrower.methodTwo("");
        }catch (MyExceptionHandling.MyException e){
            System.out.println(e.getMessage());
        }   
        try{
            MyExceptionThrower.methodThree(10, 0);
        }catch (MyExceptionHandling.MyException e){
            System.out.println(e.getMessage()); 
        }
    }
}