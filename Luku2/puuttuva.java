import java.util.Scanner;
import java.util.ArrayList;

public class puuttuva {

    public static int length;
    public static String inputNumbers;
    public static ArrayList<Integer> unfoundNumbers;
    
    public static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        length = scan.nextInt();
        scan.nextLine();
        inputNumbers = scan.nextLine();

        // create unfound numbers array, later delete found numbers from here
        unfoundNumbers = new ArrayList<Integer>();
        for (int i = 0; i < length; i++) {
            unfoundNumbers.add(i+1);
        }

        String[] inputNumbers2 = inputNumbers.split(" ");


        for (int i = 0; i < inputNumbers2.length; i++) {
        
            for (int j = 1; j <= length; j++) {
                if (Integer.valueOf(inputNumbers2[i]) == j) {
                    int index = unfoundNumbers.indexOf(j);
                    unfoundNumbers.remove(index);
                }
            }
        }
        System.out.println(unfoundNumbers.get(0));
    }
}
