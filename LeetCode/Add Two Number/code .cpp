
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // Dummy node to simplify list construction
        ListNode* current = dummy; // Pointer to build the result list
        int carry = 0; // Carry for addition

        // Continue while there are digits or a carry
        while (l1 || l2 || carry) {
            // Get values (use 0 if list has ended)
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            // Compute sum and new carry
            int sum = val1 + val2 + carry;
            carry = sum / 10; // Tens place
            int digit = sum % 10; // Ones place

            // Create new node for the current digit
            current->next = new ListNode(digit);
            current = current->next;

            // Move to next nodes if available
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return dummy->next; // Skip the dummy node
    }
};