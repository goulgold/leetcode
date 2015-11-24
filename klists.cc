#define NULL 0
#include <vector>
#include <queue>

using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class CompareNode {
public:
    bool operator()(ListNode* l1, ListNode* l2) {
        if (l1->val > l2->val)
            return true;
        else
            return false;
    }
};


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode > heap;
        ListNode *head = new ListNode(0);
        ListNode *root = head;
        vector<ListNode*>::iterator it;
        for (it = lists.begin(); it != lists.end(); it++) {
            if (*it != NULL)
            heap.push(*it);
        }
        while (!heap.empty()) {
            root->next = heap.top();
            heap.pop();
            root = root->next;
            if (root->next != NULL) {
                heap.push(root->next);
            }

        }
        return head;
    }

int main() {
    return 0;
}
