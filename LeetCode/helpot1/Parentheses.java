// Task: find out if a string has false order or amount of different kind of parentheses

// Solution: 
// use stack to make sure every closing parentheses match every opening parentheses

import java.util.Stack;

class Solution {
    public boolean isValid(String s) {

        Stack<Character> stack = new Stack<>();

        // step 0: filter all unwanted letters away
        // String filtered = s.replaceAll("[^()\\[\\]{}]", "");

        // step 1: make sure remaining string is not empty
        if (s.length() < 1) return true;

        // start processing all letters
        for (char letter: s.toCharArray()) {

            // step 2: push opening parentheses into the stack
            if (letter == '(' || letter == '[' || letter == '{') {
                stack.push(letter);
            }

            // step 3: when encounter closing parentheses
            // make sure stack has a matching opening parentheses or return false
            else if (letter == ')') {
                if (stack.isEmpty()) return false;
                if (stack.peek() == '(') {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
            else if (letter == ']') {
                if (stack.isEmpty()) return false;
                if (stack.peek() == '[') {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
            else if (letter == '}') {
                if (stack.isEmpty()) return false;
                if (stack.peek() == '{') {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
        }

        // step 4: stack should now be empty or return false
        return stack.isEmpty();
    }
}