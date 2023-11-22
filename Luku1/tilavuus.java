import java.util.Scanner;

public class tilavuus {
    static double radius;
    static double volume;
    static Scanner scan = new Scanner(System.in);

    public static void main (String [] Args) {

        try {
        String command = scan.nextLine();
        radius = Double.parseDouble(command);
         volume = (4*Math.PI*Math.pow(radius, 3))/3;
        System.out.println(volume);

        } 
        catch (Exception e) {
            System.out.println("Exception thrown: " + e);
        }
    }
}
