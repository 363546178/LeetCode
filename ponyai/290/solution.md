1.这道题还是采用和hash表的方法，构建了2个unordermap，分别存储字符和单词
2.单词通过空格实现了切分，这个地方涉及到字符串的几个常用操作：

find_first_of:

size_type find_first_of( const basic_string& str, size_type pos = 0 ) const;
寻找等于给定字符序列中字符之一的首个字符。搜索只考虑区间 [pos, size()) 。若区间中不存在字符，则返回 npos 。

https://zh.cppreference.com/w/cpp/string/basic_string/find_first_of

substr:

basic_string substr( size_type pos = 0, size_type count = npos ) const;

返回子串 [pos, pos+count) 。若请求的子串越过 string 的结尾，或若 count == npos ，则返回的子串为 [pos, size()) 。

https://zh.cppreference.com/w/cpp/string/basic_string/substr

3.匹配查找阶段，采用了hash表模式

通常思路：
(1)首先构建字符与单词之间的映射关系
unordered_map中一个元素为：{key, value}
让字符作为key，对应的单词作为value，构成映射
(2)存储所有的对应关系，之后进行对比，如果新的映射关系，出现
与旧的不一致的，return false


代码实现思路：

(1)在实现构建映射关系之前，就可以开始进行判断map中是否存在这个key
此处采用map中的m.count(pattern[i])实现，若为0说明没有这个key
    (1)如果不存在，就可以进行下一步
        (1)判断这个key对应的单词是否出现过，因为这个题目中，新的字符对应一个新的单词，若出现旧单词，则不符合要求，直接返回false，这个是一个case
        (2)通过后增加新的映射关系，同时将这个单词记录到已经出现的单词的容器中，用于(1)中的判断
    (2)如果存在，对比这个key中容器里面历史key对应的value，与当前key对应
    的value是否一致，若不一致return false



总结涉及的知识点:

1.unorder_map
2.string中的一些操作