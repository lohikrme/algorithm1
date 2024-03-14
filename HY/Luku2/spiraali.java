import java.util.Scanner;

public class spiraali {

    // note that these row and col indexes start from 1 for example row 2, col 3 would be 8
    public static long row;
    public static long col;
    public static long sizeOfSquare;
    public static long lenOfSquareSide;
    public static long points; // use this point system to calculate the number of (x,y) location
    
    public static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {

        // receive the input and modify it into row and col index
        String input = scan.nextLine();
        String[] input2 = input.split(" ");
        row = Long.parseLong(input2[0]);
        col = Long.parseLong(input2[1]);

        // test that row and column are received correctly:
        // System.out.println("row: " + row);
        // System.out.println("col: " + col);

        // first we need to figure out the full square before last layer
        // logic is simple - full square is always determined
        // from the larger of row and col. then take away 1
        // for example, if row = 2, col = 3. the square before our spot is
        // actually size of 2x2 = 4 numbers. so (col-1)^2

        // row bigger
        if (row > col) {
            lenOfSquareSide = row - 1;
            sizeOfSquare = lenOfSquareSide * lenOfSquareSide; // area of square
        }
        // col bigger or same big
        else {
            lenOfSquareSide = col - 1;
            sizeOfSquare = lenOfSquareSide * lenOfSquareSide; // area of square
        }

        // test square size works
        // System.out.println("length of side: " + lenOfSquareSide);
        // System.out.println("size of square: " + sizeOfSquare);

        // --------------------------------------------------------
        // next, we need to determine how many numbers the last layer has. for example, if our location is row = 5, col = 5,
        // we alrdy know which layer we are at from previously calculating the square
        // for example, if square before us has 4x4, then we are at layer 5. 
        // odd number layers go from left to right, and from down to up
        // while even number layers (such as layer after 3x3 square) goes
        // from up to down, and from right to left

        // this information we use to make 2 separate logic. 

        // -------- the even number layer logic: --------
        // on even number layer, we go from up to down, and from right to left.
        // if row <= col, add row index to sum of points
        // if row > col, add first (lenOfSquareSide +1) 
        // because that is the max amount they can go from up to down
        // and then add also (row - col)
        // for example row = 4 and col = 3, would be (remember we alrdy solved how to calculate full square first):
        // 3^2 + (3+1) +  (4-3) = 9 + 4 + 1 = 14

        if ((lenOfSquareSide + 1) % 2 == 0) {
            points += sizeOfSquare;
            if (row <= col) {
                points += row;
            } 
            else if (row > col) {
                points += (lenOfSquareSide + 1);
                points += (row-col);
            }
        }

        // -------- the odd number layer logic: --------
        // on odd number layer, we go from left to right, and from down to up
        // if col <= row, add col index to sum of points
        // if col > row, add first (lenOfSquareSide + 1)
        // becasue that is the max amount they can go from left to right
        // and then add also (col - row)
        // for example row = 2, col = 5, would be (remember we alrdy solved how to calculate full square first):
        // 4^2 + (4+1) + (5-2) = 16 + 5 + 3 = 24

        else if ((lenOfSquareSide + 1) % 2 == 1) {
            points += sizeOfSquare;
            if (col <= row) {
                points += col;
            }
            else if (col > row) {
                points += (lenOfSquareSide + 1);
                points += (col - row);
            }
        }

        System.out.println(points);


    }
}
