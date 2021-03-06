#include "util/util.h"

class Solution {
    public:
        static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0;
    int carry = 0;
    ListNode* result = new ListNode;
    ListNode* return_ptr = result;
    while (l1 != nullptr || l2 != nullptr ) {
        if (l1 == nullptr) {
            sum = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
        } else if (l2 == nullptr) {
            sum = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
        } else {
        sum = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        }
        result->val = sum;
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
        if (l1 != nullptr || l2 != nullptr) {
            result->next = new ListNode;
            result = result->next;
        }
    }
    if (carry == 1) result->next = new ListNode(1);
    return return_ptr;
}

int main() {
    ListNode * l1 = new ListNode(9);
    l1->next = new ListNode(9);
    ListNode * l2 = new ListNode(1);

    ListNode* result = Solution::addTwoNumbers(l1, l2);

    while (result != nullptr) {
        cout << result->val;
        result = result->next;
    }
    cout << endl;
    return 0;

}
