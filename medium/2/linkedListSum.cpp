/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; // Fixed initialization
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;

        // Continue as long as there are digits in either list OR there is a remaining carry.
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum for the current position
            int sum = val1 + val2 + carry;

            // Determine the digit and the next carry
            int digit = sum % 10;
            carry = sum / 10;

            // Create a new node with the resulting digit and append it to the result list.
            current->next = new ListNode(digit);
            current = current->next; // Move 'current' pointer forward

            // Advance pointers for the next iteration, checking for null before accessing ->val/->next
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        
        ListNode* output = dummyHead->next;
        delete dummyHead; // Clean up the temporary head node allocated in this function scope
        return output;
    }
};