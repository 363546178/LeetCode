#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

//单次哈希表
class Solution
{
public:
    vector<int> TwoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> record;
        for (int i = 0; i != nums.size(); ++i)
        {
            auto found = record.find(nums[i]);
            if (found != record.end())
            {
                return {found->second, i};       //当前元素能够与表中历史元素的目标元素对应时，就返回数值
            }                                    //第一个是匹配的历史元素的inedx，第二个是当前元素的index
            record.emplace(target - nums[i], i); //每次向表中添加的元素，是当前元素所需的目标元素
        }
        return {-1, -1};
    }
};

//首先是hash表的应用，这个地方自己一直没弄明白道理
//题目要求是，找到两个整数，说明要返回两次
// {key,value} key为b value为a的index
//在进行迭代并将元素插入到表中的同时，我们
//还会回过头来检查表中是否已经存在当前元素
//所对应的目标元素。如果它存在，那我们已经
//找到了对应解，并立即将其返回。

//还需要补充双次哈希表和暴力匹配的解法

//双次哈希表

//暴力匹配