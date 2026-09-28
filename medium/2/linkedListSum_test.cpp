#include <iostream>
#include <vector>
#include <algorithm>
// Assuming linkedListSum.cpp contains the necessary definitions and solution class structure
// In a real project, we would use forward declarations or include headers properly.

/* Definition for singly-linked list (Copied here for self-contained test file) */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class structure (Copied from linkedListSum.cpp for context/compilation)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; // Fixed initialization
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;

        // Loop condition needs to check p1/p2 existence AND carry != 0
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


// --- Helper Functions for Testing ---

/**
 * @brief Converts a vector of integers to a singly linked list.
 * Note: This function allocates memory that must be managed by the caller or test cleanup.
 */
ListNode* buildList(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;

    // Since digits are in reversed order, we build them head-first as they appear in the vector.
    ListNode* dummyHead = new ListNode();
    ListNode* current = dummyHead;

    for (int val : nums) {
        current->next = new ListNode(val);
        current = current->next;
    }
    // The actual head is dummyHead->next
    return dummyHead->next;
}

/**
 * @brief Converts a linked list to a vector of integers.
 * Note: It assumes the input list structure is valid and cleans up allocated memory for all nodes it traverses.
 */
std::vector<int> listToVector(ListNode* head) {
    std::vector<int> nums;
    ListNode* current = head;
    while (current != nullptr) {
        nums.push_back(current->val);
        // Must save the next pointer before deleting the node
        ListNode* nextNode = current->next;
        delete current; // Cleanup memory for the passed list segment
        current = nextNode;
    }
    return nums;
}

/**
 * @brief Checks if two linked lists are structurally equal (digit by digit).
 */
bool compareLists(ListNode* l1, ListNode* l2) {
    // Temporary pointers to traverse and compare without consuming the list structure for cleanup checks.
    ListNode* p1 = l1;
    ListNode* p2 = l2;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->val != p2->val) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    // Both must be null simultaneously for equality
    return (p1 == nullptr && p2 == nullptr);
}

/**
 * @brief Runs a test case for addTwoNumbers.
 */
void runListTest(ListNode* l1_head, ListNode* l2_head, const std::vector<int>& expectedDigits, int testNumber) {
    // IMPORTANT: We must duplicate the input lists because the Solution::addTwoNumbers function 
    // consumes/moves its pointers (l1 and l2) by advancing them until they are nullptr.
    ListNode* l1_copy = buildList(l1_head ? listToVector(l1_head) : std::vector<int>{});
    ListNode* l2_copy = buildList(l2_head ? listToVector(l2_head) : std::vector<int>{});

    Solution solution;
    ListNode* resultHead = solution.addTwoNumbers(l1_copy, l2_copy);

    // The comparison function works on the actual structure returned by addTwoNumbers.
    // We build an expected list from the vector for a consistent structural comparison check 
    // (though comparing digit-by-digit is safer). Let's compare them structurally.
    
    ListNode* expectedHead = buildList(expectedDigits);

    bool passed = compareLists(resultHead, expectedHead) && !compareLists(nullptr, nullptr); // Check if both are null OR structures match
    
    std::cout << "Test " << testNumber << ": ";
    if (passed) {
        std::cout << "PASS\n";
    } else {
        std::cout << "FAIL\n";
        // Since we allocated memory for resultHead and expectedHead, they must be cleaned up later.
    }

    // --- Cleanup ---
    // 1. Clean up all input copies (l1_copy, l2_copy) - their contents were moved into the function logic, but we need to clean them properly.
    // Since we rebuild from vectors, listToVector already deletes nodes it traverses. We must ensure buildList only uses unique memory sources.
    // For robust testing: Build copies of inputs *again* if they weren't cleaned up by internal pointer logic (which is complex here). 
    // For simplicity in this test structure, we rely on the fact that listToVector cleans up what it traverses.
    
    // We only clean up nodes that we know were created and not yet freed from traversal failures: resultHead and expectedHead.
    // The pointers l1_copy/l2_copy internal cleanup is tricky due to pointer advancement logic in addTwoNumbers, 
    // but standard practice suggests checking if the resulting list was fully traversed or if inputs need manual deletion.

    delete resultHead; // This will trigger recursive deletion via listToVector helper logic (if we modify it for deletion) or simply deleting the head. A dedicated deleter is safer.
    // Given the complexity of memory management across multiple allocations, I'll simplify cleanup by just calling listToVector on results/expected and accepting its internal cleanup mechanism, then manually cleaning up inputs.

    // REFINING CLEANUP: Let's write a recursive delete function to handle heap leak detection for test failures.
}


/** 
 * @brief Helper to recursively delete all nodes in a linked list starting from head.
 */
void deleteList(ListNode* head) {
    if (head == nullptr) return;
    deleteList(head->next);
    delete head;
}

// REWRITING THE TEST RUNNER TO USE SAFE MEMORY MANAGEMENT

bool runListTestSafe(ListNode* l1_head, ListNode* l2_head, const std::vector<int>& expectedDigits, int testNumber) {
    std::cout << "--- Running Test " << testNumber << " ---" << std::endl;

    // 1. Create deep copies of inputs for testing, as the function consumes them.
    ListNode* l1_copy = buildList(l1_head ? listToVector(l1_head) : std::vector<int>{});
    ListNode* l2_copy = buildList(l2_head ? listToVector(l2_head) : std::vector<int>{});

    // 2. Execute (This consumes pointers, but we rely on the next step to manage memory).
    Solution solution;
    ListNode* resultHead = solution.addTwoNumbers(l1_copy, l2_copy);

    // 3. Build expected list and compare structures.
    ListNode* expectedHead = buildList(expectedDigits);
    bool passed = compareLists(resultHead, expectedHead);

    std::cout << "Test " << testNumber << ": ";
    if (passed) {
        std::cout << "PASS\n";
    } else {
        std::cout << "FAIL: Result list does not match expected structure.\n";
    }
    
    // 4. Cleanup everything allocated in this specific test run.
    deleteList(l1_copy);
    deleteList(l2_copy);
    deleteList(resultHead);
    deleteList(expectedHead);
    return passed;
}


int main() {
    bool allPassed = true;
    // Test Case 1: Equal length, carry at end (99 + 99 = 198)
    std::cout << "========================================\n";
    std::cout << "Test Case 1: 99 + 99 = 198" << std::endl;
    // l1 = 9->9 (represents 99), l2 = 9->9 (represents 99). Expected result digits (reversed) = {8, 9, 1}
    allPassed &= runListTestSafe(buildList({9, 9}), buildList({9, 9}), {8, 9, 1}, 1);

    // Test Case 2: Unequal length, no final carry (342 + 465 = 807)
    std::cout << "\n========================================\n";
    std::cout << "Test Case 2: 342 + 465 = 807" << std::endl;
    // l1 = 2->4->3, l2 = 5->6->4. Expected result digits (reversed) = {7, 0, 8}
    allPassed &= runListTestSafe(buildList({2, 4, 3}), buildList({5, 6, 4}), {7, 0, 8}, 2);

    // Test Case 3: Different lengths, carry at end (9 + 1 = 10)
    std::cout << "\n========================================\n";
    std::cout << "Test Case 3: 9 + 1 = 10" << std::endl;
    // l1 = 9, l2 = 1. Expected result digits (reversed) = {0, 1}
    allPassed &= runListTestSafe(buildList({9}), buildList({1}), {0, 1}, 3);

    // Test Case 4: Zero inputs (0 + 0 = 0)
    std::cout << "\n========================================\n";
    std::cout << "Test Case 4: 0 + 0 = 0" << std::endl;
    allPassed &= runListTestSafe(buildList({0}), buildList({0}), {0}, 4);

    // Test Case 5: One input is zero (123 + 0 = 123)
    std::cout << "\n========================================\n";
    std::cout << "Test Case 5: 123 + 0 = 123" << std::endl;
    allPassed &= runListTestSafe(buildList({3, 2, 1}), buildList({0}), {3, 2, 1}, 5);

    return allPassed ? 0 : 1;
}