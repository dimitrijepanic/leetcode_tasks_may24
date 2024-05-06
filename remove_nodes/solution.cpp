#include <iostream>
#include <cstddef>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        auto ret = helper(head);
        return ret.first;
    }

    pair<ListNode*, int> helper(ListNode* head){
        if(head == NULL) return {NULL, -1};

        auto ret = helper(head->next);
        head->next = ret.first;

        if(ret.second > head->val){
            return {ret.first, ret.second};
        } 

        return {head, head->val};
    }
};

int main() {
    Solution solution;
    ListNode head(3);
    ListNode first(2);
    ListNode second(4);
    head.next = &first;
    first.next = &second;

    solution.removeNodes(&head);
    cout << head.next->val << endl;
    return 0;
}