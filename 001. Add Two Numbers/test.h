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
//然后对下一个节点进行处理，采用new的方式进行实现
//最好能够补充一下C++链表的基础知识

//C 库函数 div_t div(int numer, int denom)
//把 numer（分子）除以 denom（分母）。
//该函数返回定义在 <cstdlib> 中的结构中的值，
//该结构有两个成员，如 div_t:int quot(商); int rem(余数);
class Solution
{
public:
    ListNode *addTwoNum(ListNode *num1, ListNode *num2)
    {
        //初始化变量
        ListNode dummy(0);
        ListNode *tail = &dummy;
        //循环遍历
        //1.首先初始化sum
        //2.继续执行循环的条件：sum的商不为0，num1和num2不为NULL
        //3.
        for (div_t sum{0, 0}; sum.quot || num1 || num2; tail = tail->next)
        {
            if (num1) //第一个数值
            {
                sum.quot += num1->val; //第一个数值加入sum的商
                num1 = num1->next;
            }

            if (num2) //第二个数值
            {
                sum.quot += num2->val; //第二个数值加入sum的商
                num2 = num2->next;
            }
            sum = div(sum.quot, 10);            //采用sum的商参数，除以10,求取新的sum的商和余数
            tail->next = new ListNode(sum.rem); //新的节点保存sum的余数
        }
        return dummy.next;
    }
};