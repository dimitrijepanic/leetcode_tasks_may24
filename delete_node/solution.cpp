#include <iostream>
#include <cstddef>

using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* prev = node;
        
        while(curr->next != NULL){
            prev->val = curr->val;
            prev = curr;
            curr = curr->next;
        }
        prev->val = curr->val;
        prev->next = NULL;
    }
 
};

int main() {
    Solution solution;
    ListNode head(1);
    ListNode first(2);
    ListNode second(3);
    head.next = &first;
    first.next = &second;

    solution.deleteNode(&first);
    cout << head.next->val << endl;
    return 0;
}