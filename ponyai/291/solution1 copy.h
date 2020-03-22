#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool wordPatternMatch(string pattern, string str)
    {
        cout << "pattern:" << pattern << " str:" << str << endl;
        unordered_map<char, string> m; //?这个变量作用？
        return backtrace(pattern, 0, str, 0, m);
    }
    bool backtrace(string pattern, int pattern_cnt, string str, int str_cnt, unordered_map<char, string> &m)
    {
        cout << "backtrace pattern_cnt:" << pattern_cnt << " str_cnt:" << str_cnt << endl;
        //p是字符的计数器，r是单词/字符串的计数器
        // 出口条件(check条件)
        //在递归的时候，会同时对计数器进行一次累加，累加后，若字符和字符串的size都与计数器一致，返回为true
        if (pattern_cnt == pattern.size() && str_cnt == str.size())
        {
            cout << "backtrace return true!" << endl;
            return true;
        }
        //若两个条件不同时满足，则说明hash表中key和value并不是完全对应，需要进行earse操作
        if (pattern_cnt == pattern.size() || str_cnt == str.size())
        {
            cout << "backtrace return false!" << endl;
            cout << "pattern size:" << pattern.size() << " str size:" << str.size() << endl;
            cout << "pattern_cnt:" << pattern_cnt << " str_cnt:" << str_cnt << endl;
            return false;
        }

        // 注意:若未达到上面的出口条件，每一次都会执行下面的遍历操作，相当于不断的进行遍历

        // 提取规律首字符作为哈希表key值
        char key = pattern[pattern_cnt];
        // 从r开始到结尾,遍历输入字符串str
        for (int i = str_cnt; i < str.size(); i++)
        {
            // 从r开始,提取i-str_cnt+1长度的子字符串作为哈希表的映射值 //这个地方与290的操作方式很相似，但由于没有空格，只能这样操作
            string value = str.substr(str_cnt, i - str_cnt + 1);
            cout << "pattern cnt:" << pattern_cnt << " str_cnt:" << str_cnt << " i:" << i << " value:" << value << endl;
            // 如果哈希表中存在key值且映射值一样,则递归自身,结果为真的话返回true
            if (m.count(key) && m[key] == value)
            {
                cout << "m.count(key) && m[key] == value KEY:" << key << " value:" << value << endl;
                if (backtrace(pattern, pattern_cnt + 1, str, i + 1, m)) //递归自身
                {
                    cout << "return true"
                         << " pattern_cnt:" << pattern_cnt << " str_cnt:" << str_cnt << endl;
                    return true;
                }
            }
            // 如果哈希表中不存在key值,需判断是否存在重复映射值
            else if (!m.count(key))
            {
                cout << "no this key" << endl;
                bool flag = false;
                for (auto it : m) //遍历所有哈希表，判断是否有重复的映射值
                {
                    if (it.second == value)
                    {
                        flag = true;
                        break; //有重复的映射值跳出此循环，继续遍历输入字符串str
                    }
                }
                // 哈希表中不存在该映射值的话则新增该映射值并递归
                if (!flag)
                {
                    m[key] = value;
                    cout << "add key! KEY:" << key << " value:" << value << endl;
                    if (backtrace(pattern, pattern_cnt + 1, str, i + 1, m)) //递归调用
                    {
                        cout << "return true if (!flag) "
                             << " pattern_cnt:" << pattern_cnt << " str_cnt:" << str_cnt << endl;
                        return true;
                    }
                    // 该key值已递归完成,回溯！！！(恢复为初始状态)
                    cout << "erase this key" << endl;
                    m.erase(key); //递归return false时执行，将这个key和对应的value都进行移除
                }
            }
        }
        // 试探不成功则返回false
        return false;
    }
};