// 使用模板可以写出类型无关代码。
// pattern 和 str 遵循相同的规律，当且仅当可在 pattern 和 str 间建立双射。
// 可以把 pattern 和 str 都映射到同一个序列，双射有自反，对称，传递性质，属于等价关系。
// 把 pattern 转换为 vector<char> v_pattern，str 转换为 vector<string> v_str，然后可以对 v_pattern, v_str做完全相同的预处理。
// 对 v_pattern 和 v_str 按照其中符号首次出现的顺序，把符号映射到递增序列。
// 取递增序列，是为了序列中的符号唯一，不重复。
// 递增序列可以取整数, 0, 1, 2, 3, ...。
// 这里取ASCII码序列 "@ABCDEFG"...。
// "abba" 被映射为 "@AA@"。
// "dog cat cat fish" 被映射为 "@AAB"。
// 然后检查映射的结果是否相同。

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<char, string> m;
        unordered_map<string, int> used;
        vector<string> vs;
        string s;
        int pos;
        int i = 0;

        while (pos != -1) //读取str中的单词
        {
            pos = str.find_first_of(' ', i);      //相当于返回每个空格的索引值,如果找不到空格则-1
            string temp = str.substr(i, pos - i); //截取单词
            vs.push_back(temp);                   //插入单词元素
            i = pos + 1;                          //相当于每个单词的首位索引值
        }

        if (vs.size() != pattern.size())
            return false;

        for (int i = 0; i < pattern.size(); i++)
        {                                 //遍历左边数组
            s = vs[i];                    //依次赋值单词字符串
            if (m.count(pattern[i]) == 0) //如果左边(pattern)数组出现新字母时,执行
                if (used[s])
                    return false; //因为每个新字母对应一个新单词,不能新字母对应旧字符串
                                  //所以出现新字母时,要保证单词也是新的,如果是已经出现过的字符串则返回false
                else
                {
                    m[pattern[i]] = s; //匹配键值对
                    used[s]++;         //相当于标记某个单词已经出现过了
                }
            else if (s != m[pattern[i]])
                return false; //判断str中第i个的字符串是否与映射表中第i位所对应的字符串相等
        }
        return true;
    }
};