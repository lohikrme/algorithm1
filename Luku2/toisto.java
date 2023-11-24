
import java.util.Scanner;

public class toisto {

    // store the latest letter, longest queue and current queue
    public static char lastLetter;
    public static int longestQueue;
    public static int currentQueue;
    public static String DNA_Code;

    // scanner to receive inputs
    public static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        DNA_Code = scan.nextLine();
        lastLetter = DNA_Code.charAt(0);
        longestQueue = 1;
        currentQueue = 1;

        for (int i = 1; i < DNA_Code.length(); i++) {
            lastLetter = DNA_Code.charAt(i-1);
            if (DNA_Code.charAt(i) == lastLetter) {
                currentQueue++;
                if (currentQueue > longestQueue) {
                    longestQueue = currentQueue;
                }
            } else {
                currentQueue = 1;
            }
        }
        System.out.println(longestQueue);
    }

}