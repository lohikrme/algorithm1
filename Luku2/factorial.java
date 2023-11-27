/* ------------- MISSION ------------------
 * Input between 1 and 1 000 000 000.
 * Tell how many zeros will be in the end of 
 * factorial of this input.
 * For example 5! = 120, so answer is 1 (zero).
 * 6! is 720, so answer is again 1.
 * 10! is 3 628 800 so answer is 2. And so on.
 */

 /* -------------LOGIC --------------- 
  * The Logic goes next:
  For example 5! is 120. But we can split the calculation to
  1*2*3*4*5. This we can again split to 1*2*3*(2*2)*5 And 2*5 = 10.
  So, in 5! we have 1x10, and each time we have 10, we get a zero.
  So we have 1 zero as our answer.
  What about 10!? 1*2*3*4*5*6*7*8*9*10 = 1*2*3*2*2*5*6*7*2*2*2*3*3*2*5. 
  So, we have 2 times 10, which means our answer is 2 zeros.
  When we reach 15! the 15, it is again 3*5. So we use the 5 with a previous 2 to get a third 10.
  20! has 20, which is 4*5. We use aain the 5 with previous 2.
  Then we reach 25!, which is 5*5. Now we have two fives. So we will use both with 2 to get 10*10 = 2 zeros.
  So, each time we reach a steppoint such as 25, 125, 625. We consider it to be built of previous step points.
  So, 25! has 5+1 = 6 zeros. 125 has 5*6+1 = 31 zeros. 625 has 31*5+1 = 156. ETC.
 */


import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class factorial {
    public static long answer;

    public static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int input = scan.nextInt();

        // we check how many times input is divident by 5.
        // we use loop, and compare every step, for example.
        // if 5 < input... if 25 < input... if 125 < input...
        // to check these checkpoints, we need first separately generate all checkpoints

        // creating checkpoints
        Long checkpointCreationNumber = 25L;
        List <Long> checkpoints = new ArrayList<>();
        while (checkpointCreationNumber < 1000000000) {
            checkpoints.add(checkpointCreationNumber);
            checkpointCreationNumber *= 5;
        }

        // if input less than 5, check it manually:
        if (input < 5) {
            answer = 0;
        } 

        // if input is larger than 5, start using the while loop to increase answer every step
        else {

        // number simply represents the growth of factorial by 5. For example from 5! to 10! or from 500! to 505!.
        int number = 5; 

        while (number <= input) {
            answer += 1;

            // now compare the number to checkpoints, if equals, add +1 zero to answer
            for (Long checkpoint : checkpoints) {
                if (number % checkpoint == 0) {
                    answer += 1;
                }
            }

            number += 5;
        }
    }
    System.out.println(answer);
    }
}
