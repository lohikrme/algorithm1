import java.util.Scanner;

public class bittijonot {

    static long length;
    static long modulo = (long) (Math.pow(10, 9) + 7);
    static Scanner scan = new Scanner(System.in);
    
    public static void main(String [] Args) {
        length = scan.nextInt();
        long bitlines = 1;
        for (int i = 0; i < length; i++) {
            bitlines = (bitlines * 2) % modulo; // take modulo at each step to prevent overflow
        }
        System.out.println(bitlines);
    }
}