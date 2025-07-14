// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/?envType=daily-question&envId=2025-07-14
class Solution {
    public int getDecimalValue(ListNode head) {
        int num = head.val;
        while (head.next != null) {
            num = (num << 1) | head.next.val;
            head = head.next;    
        }
        return num;
    }
}