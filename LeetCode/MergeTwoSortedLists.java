// i need to merge two presorted linked lists
// to maintain the ascending order, i will need to compare if
// number from list1 is smaller than number from list2.
// if number is smaller, i will add to our new linkedlist list1 value
// if number is bigger, i will add to our new linkedlist list2 value
// the list with the smaller value will fetch a new number
// and comparison starts again

/*
public class ListNode {
    int val; // value of node
    ListNode next; // reference to next node
    ListNode() {} // empty constructor
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
*/

import java.util.LinkedList;

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        // initiate new list
        ListNode newList = new ListNode();
        // keep track on current node, so the head of newList wont move forward
        ListNode current = newList;

        while (list1 != null || list2 != null) {
            // if neither is null check both lists
            if (list1 != null && list2 != null) {
                if (list1.val < list2.val) {
                    current.next = new ListNode(list1.val);
                    list1 = list1.next;
                    current = current.next;
                } else {
                    current.next = new ListNode(list2.val);
                    list2 = list2.next;
                    current = current.next;
                }
            }
            // if list1 is null, add rest of list2 to newList
            else if (list1 == null) {
                while (list2 != null) {
                    current.next = new ListNode(list2.val);
                    list2 = list2.next;
                    current = current.next;
                }
            }
            // if list2 is null, add rest of list1 to newList
            else {
                while (list1 != null) {
                    current.next = new ListNode(list1.val);
                    list1 = list1.next;
                    current = current.next;
                }
            }
        }
        // because newList was initiated as empty, skip first empty value
        return newList.next;
    }
}