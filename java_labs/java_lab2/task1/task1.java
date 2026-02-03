/*
lab2: Task 1
Split a string represent an IP address:
➢ Use string split(“\\.”)
➢ Use StringTokenizer
➢ The program, for example: your Input :
➢ 163.121.12.30
➢ The result is :
163
121
12
30

*/ 

//StringTokenizer 
import java.util.StringTokenizer;

class IPCutter{
    String cmdLine;
    public IPCutter(String cmdLine){
        this.cmdLine = cmdLine;
    }

    int[] doIPSplit(){
        String[] parts = cmdLine.split("\\.");
        int[] result = new int[parts.length];
        for(int i=0; i<parts.length; i++){
            result[i] = Integer.parseInt(parts[i]);
        }
        return result;
    }

    int[] doIPTokenize(){
        StringTokenizer tokenizer = new StringTokenizer(cmdLine, ".");
        int[] result = new int[tokenizer.countTokens()];
        int index = 0;
        while(tokenizer.hasMoreTokens()){
            result[index++] = Integer.parseInt(tokenizer.nextToken());
        }
        return result;
    }

    void print(int[] arr){
        for(int i=0; i<arr.length; i++){
            System.out.println(arr[i]);
        }
    }
}

public class task1 {
    public static void main(String[] args){ 
    String commandLine = "163.121.12.30";
    IPCutter cut = new IPCutter(commandLine);

    System.out.println("The output of " + commandLine + " using split(\\.) is :"); 
    int[] out1 = cut.doIPSplit();
    cut.print(out1);

    System.out.println("The output of " + commandLine + " using StringTokenizer is :"); 
    int[] out2 = cut.doIPTokenize();
    cut.print(out2);

    }
}
