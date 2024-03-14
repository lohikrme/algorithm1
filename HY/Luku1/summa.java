import java.util.Scanner;

public class summa {

    static Scanner scan = new Scanner(System.in);
    static long number1;
    static long number2;
    
    public static void main(String[] args) {
        number1 = scan.nextInt();
        number2 = scan.nextInt();

        System.out.println(number1+number2);


    }
}