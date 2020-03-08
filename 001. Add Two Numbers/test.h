#include <cstddef>
#include <cstdlib>

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//注意，这里面首先要理解这个链表（ListNode）的含义
//再main中，初始化listnode时，首先初始化单个节点，对val赋值
//

class Solution
{
public:
    ListNode *addTwoNum(ListNode *num1, ListNode *num2)
    {
        //初始化变量
        ListNode dummy(0);
        ListNode *tail = &dummy;
        //循环遍历
        for (div_t sum{0, 0}; sum.quot || num1 || num2; tail = tail->next)
        {
            if (num1)
            {
                sum.quot += num1->val;
                num1 = num1->next;
            }

            if (num2)
            {
                sum.quot += num2->val;
                num2 = num2->next;
            }
            sum = div(sum.quot, 10);
        }
        return dummy.next;
    }
};