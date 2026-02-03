/*Given a sentence and a word, your task is that to count the number of occurrences of the
given word in the string and print the number of occurrence of the word.

➢ Perform the above task using only methods of the String class (2 ways). 
*/
import java.util.StringTokenizer;

class WordCounter {
    String sentence;
    String word;

    public WordCounter(String sentence, String word){
        this.sentence = sentence;
        this.word = word;
    }

    int countUsingSplit(){
        String[] words = sentence.split(" ");
        int count = 0;

        for(int i = 0; i < words.length; i++){
            if(words[i].equals(word)){
                count++;
            }
        }
        return count;
    }

    int countUsingStringTokenizer(){
        StringTokenizer tokenizer = new StringTokenizer(sentence, " ");
        int count = 0;

        while(tokenizer.hasMoreTokens()){
            String w = tokenizer.nextToken();
            if(w.equals(word)){
                count++;
            }
        }
        return count;
    }
}

public class task2 {
    public static void main(String[] args){
        String sentence = "hello from Java course , java is very useful language";
        String word = "ava";

        WordCounter wc = new WordCounter(sentence, word);

        int count1 = wc.countUsingSplit();
        System.out.println("The word '" + word + "' occurs " + count1 + " times using split().");

        int count2 = wc.countUsingStringTokenizer();
        System.out.println("The word '" + word + "' occurs " + count2 + " times using StringTokenizer.");
    }
}