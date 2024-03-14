// --------------MISSION-----------------
/* Calculate how many ways 2 horses can locate on a n-size
 * chessboard so that they wont threat each others
 */


// ------------- LOGIC -------------------
/* The logic will be next: First we calculate assuming
 * there is black and white chess piece
 * I will use example 8x8 chessboard to explain the logic
 * LAYER1 is the outest layer, the edge. 
 * There we have 4 corners, where is always 2 possible threats
 * Next to corners on layer1 3 possible threats
 * And then other eges 4 threats
 * LAYER2 corner has 4 threats. rest of layer 6 threats.
 * Others Layers form the square in the middle of board.
 * For example 8x8 board has 4x4 square in the middle.
 * While 20x20 board has 16x16 square in the middle.
 * There is always 8 threats. (horse can jump to 8 spot from where it is) 
 * So, when we calculate all threats a white button does. 
 * Using example 8x8 board. We will know that
 * All combinations of 2 buttons are 64x63 = 4032.
 * All Threats are  (8+24+64+16+96+(64-48)*8) = 336
 * 4032-336 = 3696. This would apply if buttons were black and white.
 * Because (for reason or another) mission assumes buttons to be same color
 * that means that we must divide both total combinations, and total threats
 * so the correct final answer will be: 
 * 4032/2 - 336/2 = 2016 - 168 = 1848 different combinations
 */


import java.util.Scanner;

public class chesshorses {

    // store answer here
    public static long answer;
    // store max amount of positions 2 horse can locate on board, for example 8x8 board is 64*63 or 3x3 board 9*8
    public static long totalPositions;
    // store positions where 2 horses threat each others
    public static long totalThreats;
    // store chessboard side length
    public static long side;
    // static scanner for importing
    public static Scanner scan = new Scanner(System.in);


    public static void main(String[] args) {
        side = Integer.valueOf(scan.nextLine());

        // calculate totalPositions, for example 8x8 board is 64*63 or 3x3 board 9*8
        totalPositions = (side*side)*(side*side-1);

        // if side is shorter than 5, solve manually
        if (side == 1) {
            answer = 0; // 2 horses dont fit on 1 square
        }
        else if (side == 2) {
            answer = 6; // simply manually tried out
        }
        else if (side == 3) {
            // corners 2 threats, edges 2 threat, middle 0 treat
            totalThreats = 4*2 + 4*2 + 0;
            answer = totalPositions / 2 - totalThreats / 2;
        }
        else if (side == 4) {
            // corners 2 threats, edges 3 threats, middles 4 threats
            totalThreats = 4*2 + 8*3 + 4*4;
            answer = totalPositions / 2 - totalThreats / 2;
        }
        else {
            // Layer 1: corners 2 threats, next to corners 3 threats, other edge 4 threats
            // Layer 2: corners 4 threats, others 6 threats
            // Layer 3 to Layer n: everywhere 8 threats 
            
            // add first Layer 1. other edge must be calculated (side - 4) because we remove corners and next to corner from edges
            // and then *4*4 because board has four Layer 1 edges, each having 4 threats per location
            totalThreats += 4*2 + 8*3 + (side-4)*4*4;

            // now add Layer 2. we again remove corners from edge. this time next to corner is no special.
            // but because we are in layer 2, outermost layer is removed, so this edge is as long
            // as the other edge on Layer 1 was (side - 4)
            totalThreats += 4*4 + (side-4)*4*6;

            // now add the area that stays inside. its size is (side - 4) ^2. Like 8x8 has 4x4 inside square. 8 threats each of these.
            totalThreats += (side-4)*(side-4)*8;

            answer = Math.round((double) totalPositions / 2 - (double) totalThreats / 2);
        }

        // print the answer
        System.out.println(answer);

    }
}
