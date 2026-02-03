/*
Develop an application that extracts the minimum and maximum of the elements of an array of
1000 element and compute the search running time.

➢ Develop an application to implement the binary search algorithm and compute the search running
time.

➢ Hint: Use System.currentTimeMillis() or System.nanoTime ().

*/

class ArrayAlgorithms {

    // Bubble sort
    public void sort(int[] arr){
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Binary Search
    public int binarySearch(int[] arr, int key){
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (arr[mid] == key)
                return mid; 
            else if (arr[mid] < key) 
                start = mid + 1; 
            else                  
                end = mid - 1; 
        }
        return -1; 
    }

    public int min(int[] arr){
        sort(arr);       
        return arr[0];   
    }

    public int max(int[] arr){
        sort(arr);       
        return arr[arr.length - 1];  
    }

}


public class task3 {
    public static void main(String[] args){
        int[] arr = new int[1000];
        for(int i = 0; i < arr.length; i++)
        {
            arr[i] = (int)(Math.random() * 100); 
        }

        ArrayAlgorithms algo = new ArrayAlgorithms();

        long startTime = System.nanoTime();
        int min = algo.min(arr);
        long endTime = System.nanoTime();
        System.out.println("Minimum: " + min);
        System.out.println("\n Time taken to find minimum: " + (endTime - startTime) + " nanoseconds");

        startTime = System.nanoTime();
        int max = algo.max(arr);
        endTime = System.nanoTime();
        System.out.println("Maximum: " + max);
        System.out.println("\n Time taken to find maximum: " + (endTime - startTime) + " nanoseconds");
    
        algo.sort(arr);

        //bianary search : search for 80
        int key = 80;
        startTime = System.nanoTime();
        int result = algo.binarySearch(arr, key);
        endTime = System.nanoTime();
        if (result == -1)
            System.out.println("Element " + key + " not found in the array.");
        else
            System.out.println("Element " + key + " found at index " + result + ".");
        System.out.println("\n Time taken for binary search of " + key + ": " + (endTime - startTime) + " nanoseconds");
        
        //binary search : search for 700
        key = 700;
        startTime = System.nanoTime();
        result = algo.binarySearch(arr, key);
        endTime = System.nanoTime();
        if (result == -1)
            System.out.println("Element " + key + " not found in the array.");
        else
            System.out.println("Element " + key + " found at index " + result + ".");
        System.out.println("\n Time taken for binary search of " + key + ": " + (endTime - startTime) + " nanoseconds");
        
    }
}