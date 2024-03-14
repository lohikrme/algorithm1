import java.util.Scanner;
import java.util.HashSet;

public class puuttuva {

    public static int length;
    public static String inputNumbers;
    public static HashSet<Integer> unfoundNumbers;
    
    public static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {

        // input length and inputNumbers
        length = scan.nextInt();
        scan.nextLine();
        inputNumbers = scan.nextLine();

        // create unfoundNumbers HashSet from 1 to length
        unfoundNumbers = new HashSet<Integer>();
        for (int i = 0; i < length; i++) {
            unfoundNumbers.add(i+1);
        }


        
        // make a inputNumbers2 which is a list of numbers based on inputNumbers String
        String[] inputNumbers2 = inputNumbers.split(" ");

        // run through all inputNumbers2 values
        // delete them from the unfoundNumbers HashSet
        for (int i = 0; i < inputNumbers2.length; i++) {
            if (unfoundNumbers.contains(Integer.valueOf(inputNumbers2[i]))) {
                unfoundNumbers.remove(Integer.valueOf(inputNumbers2[i]));
            }
        }
        

        for (int number: unfoundNumbers) {
            System.out.println(number);
        }

    }
}
