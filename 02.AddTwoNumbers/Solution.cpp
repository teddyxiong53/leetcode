#include <cstddef>
#include <cstdlib>
#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {

    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *tail = &dummy;
        for(div_t sum{0, 0}; sum.quot || l1 || l2; tail=tail->next) {
            if(l1) {
                sum.quot += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum.quot += l2->val;
                l2 = l2->next;
            }
            sum = div(sum.quot, 10);
            tail->next = new ListNode(sum.rem);
        }
        return dummy.next;
    }
};

int main()
{
    Solution *s = new Solution();
    ListNode *a_n1 = new ListNode(1);
    a_n1->next = new ListNode(4);
    a_n1->next->next = new ListNode(7);

    ListNode *b_n1 = new ListNode(3);
    b_n1->next = new ListNode(6);
    b_n1->next->next = new ListNode(9);
    ListNode *result ;
    result = s->addTwoNumbers(a_n1, b_n1);
    while(result != nullptr) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");
    return 0;
}