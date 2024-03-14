import java.util.Scanner;

public class algoritmi {
    static long number;
    static Scanner scan = new Scanner(System.in);

    public static void main(String[] Args) {
        number = scan.nextInt();

        while (number != 1) {
            System.out.print(number + " ");
            if (number % 2 == 0) {
                number = number / 2;
            } else {
                number = number * 3 + 1;
            }
        }

        System.out.print(number);

    }

}