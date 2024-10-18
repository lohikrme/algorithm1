import java.util.ArrayList;

class Solution {

    public int romanToInt(String s) {

        int answer = 0;
        ArrayList<Integer> numberList = new ArrayList<Integer>();

        try {
            // if smaller value is before bigger value
            // smaller value is negative
            // otherwise all values are cumulatively positive

            for (int i = 0; i < s.length(); i++) {
                numberList.add(singleRomanNumberToInt(s.charAt(i)));
            }

            // go through every number expect very last one, which is always as it is
            for (int i = 1; i < numberList.size(); i++) {
                if (numberList.get(i - 1) < numberList.get(i)) {
                    answer -= numberList.get(i - 1);
                } else {
                    answer += numberList.get(i - 1);
                }
            }

            answer += numberList.get(numberList.size() - 1);

        } catch (Exception e) {
            System.out.println("An exception happened: " + e);
        }

        return answer;
    }

    static int singleRomanNumberToInt(char c) {
        switch (c) {
            case 'M':
                return (1000);
            case 'D':
                return (500);
            case 'C':
                return (100);
            case 'L':
                return (50);
            case 'X':
                return (10);
            case 'V':
                return (5);
            case 'I':
                return (1);
            default:
                return (0);
        }
    }
}