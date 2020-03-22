# 知识点

1. unordered_set

unordered_set可以把它想象成一个集合，它提供了几个函数让我们可以增删查：
unordered_set::insert
unordered_set::find
unordered_set::erase

这个unorder暗示着，这两个头文件中类的底层实现----Hash。 也是因为如此，你才可以在声明这些unordered模版类的时候，传入一个自定义的哈希函数，准确的说是哈希函数子（hash function object）。



# 递归模式

这道题中，采用了递归模式进行执行

# BFS与DFS

链接：https://www.jianshu.com/p/22f467126d6b

![avatar](/ponyai/291/figure.png)

## BFS Breadth-First-Search，宽度优先搜索；

BFS 的步骤：

从 1 开始进行搜索的话，

先搜索所有和 1 相连的，也就是 2 和 5 被找到了，

然后再从 2 开始搜索和他相连的，也就是 3 被找到了，

然后从 5 搜，也就是 4 被找到了，

然后从 3 开始搜索，4 被找到了，但是 4 之前已经被 5 找到了，所以忽略掉就行;

然后 3 开始搜索，忽略 4 所以啥都没搜到，然后从 4 开始，6 被找到了。。。

## DFS Depth-first search，深度优先搜索


DFS 的步骤：（不到尽头不回头）

从 1 开始，先找到其中一个相连的，2 被找到了，

然后直接开始从 2 开始搜索，3 被找到了，

然后从 3 开始搜索，4 被找到了，

然后从 4 开始搜索，5 被找到了，

然后从 5 开始搜索，忽略已经找到的所以啥都没找到。

然后没路可走了，回到前面去再走另一条路，

从 4 开始，6 被找到了，然后又没路可走了，

然后再回去前面 4，然后没路了，

回去前面 3，然后一直这样。。


## DFS算法基本模板
原文链接：https://blog.csdn.net/weixin_43272781/article/details/82959089

回溯法（探索与回溯法）是一种选优搜索法，又称为试探法，按选优条件向前搜索，以达到目标。但当探索到某一步时，发现原先选择并不优或达不到目标，就退回一步重新选择，这种走不通就退回再走的技术为回溯法，而满足回溯条件的某个状态的点称为“回溯点”。 

```cpp

int check(参数)
{
    if(满足条件)
        return 1;
    return 0;
}
 
void dfs(int step)
{
        判断边界
        {
            相应操作
        }
        尝试每一种可能
        {
               满足check条件
               标记
               继续下一步dfs(step+1)
               恢复初始状态（回溯的时候要用到）
        }
} 

```

# 递归

递归就是在运行的过程中调用自己。

递归必须要有三个要素：

　　①、边界条件

　　②、递归前进段

　　③、递归返回段

当边界条件不满足时，递归前进；当边界条件满足时，递归返回。



# 思路：

原文链接：https://blog.csdn.net/wilzxu/article/details/90398256

和前一题相比，这道题str并没有被空格分开，需要：

1. 一次次的尝试截断单词，并建立映射关系，
2. 每当有违反映射的情况出现，一层层的退回尝试新的截断方式。

这就确定了backtracking的形式。

在递归函数中传递一个patter和string的起始位置，终止条件：
1. 是两个index同时遍历到尽头，标志着所有的映射都成立，可以返回true。
2. 但如果有一个已经遍历完了另一个却没有，那么可以肯定的返回false。
否则冲pattern中先提取新的char c，然后尝试从s开始截断各种长度的string，判断有没有违反映射。

第一种没有违反映射的条件是，之前已经建立过hash[c] = word，这里不用新建，直接向下递归。
第二种条件是，没有建立过这个映射，并且seen也没有见过这个word，i.e. 没有被映射到别的字母上过，那么就开始一次backtracking，向下递归。

注意：把两种成立条件一起处理是不对的，非本层建立的映射不能够在本层删除。另外这个递归的判断条件很容易遗漏情况，下面两种解法是对的。


string value = str.substr(str_cnt, i - str_cnt + 1);


# 程序执行LOG


aaaa
pattern:aaaa str:asdasdasdasd
backtrace pattern_cnt:0 str_cnt:0
pattern cnt:0 str_cnt:0 i:0 value:a
no this key
add key! KEY:a value:a
backtrace pattern_cnt:1 str_cnt:1 //第一次进入递归，单层递归
pattern cnt:1 str_cnt:1 i:1 value:s
continue !
pattern cnt:1 str_cnt:1 i:2 value:sd
continue !
pattern cnt:1 str_cnt:1 i:3 value:sda
continue !
pattern cnt:1 str_cnt:1 i:4 value:sdas
continue !
pattern cnt:1 str_cnt:1 i:5 value:sdasd
continue !
pattern cnt:1 str_cnt:1 i:6 value:sdasda
continue !
pattern cnt:1 str_cnt:1 i:7 value:sdasdas
continue !
pattern cnt:1 str_cnt:1 i:8 value:sdasdasd
continue !
pattern cnt:1 str_cnt:1 i:9 value:sdasdasda
continue !
pattern cnt:1 str_cnt:1 i:10 value:sdasdasdas
continue !
pattern cnt:1 str_cnt:1 i:11 value:sdasdasdasd
continue !
can't find key,return false! //本次递归操作无任何符合条件的结果，结束递归

erase this key // 移除这个KEY

pattern cnt:0 str_cnt:0 i:1 value:as //选择一个新的KEY
no this key
add key! KEY:a value:as //添加这个KEY,再次进入递归(单层递归)
backtrace pattern_cnt:1 str_cnt:2
pattern cnt:1 str_cnt:2 i:2 value:d
continue !
pattern cnt:1 str_cnt:2 i:3 value:da
continue !
pattern cnt:1 str_cnt:2 i:4 value:das
continue !
pattern cnt:1 str_cnt:2 i:5 value:dasd
continue !
pattern cnt:1 str_cnt:2 i:6 value:dasda
continue !
pattern cnt:1 str_cnt:2 i:7 value:dasdas
continue !
pattern cnt:1 str_cnt:2 i:8 value:dasdasd
continue !
pattern cnt:1 str_cnt:2 i:9 value:dasdasda
continue !
pattern cnt:1 str_cnt:2 i:10 value:dasdasdas
continue !
pattern cnt:1 str_cnt:2 i:11 value:dasdasdasd
continue !
can't find key,return false! //第二次进入递归也没有找到符合的KEY，结束本次递归
erase this key //回到最上层，移除这个KEY

pattern cnt:0 str_cnt:0 i:2 value:asd //找到新的value
no this key
add key! KEY:a value:asd //添加至hash表
backtrace pattern_cnt:1 str_cnt:3 //第三次进行递归，深度为1层,此时str的cnt为3，从第四个字符开始搜索
pattern cnt:1 str_cnt:3 i:3 value:a
continue !
pattern cnt:1 str_cnt:3 i:4 value:as
continue !
pattern cnt:1 str_cnt:3 i:5 value:asd
m.count(key) && m[key] == value KEY:a value:asd //找到与之前符合的KEY
backtrace pattern_cnt:2 str_cnt:6 //第四次进行递归，深度为2层，字符串cnt为2，起始的字符为第七个
pattern cnt:2 str_cnt:6 i:6 value:a
continue !
pattern cnt:2 str_cnt:6 i:7 value:as
continue !
pattern cnt:2 str_cnt:6 i:8 value:asd
m.count(key) && m[key] == value KEY:a value:asd
backtrace pattern_cnt:3 str_cnt:9 //第五次进行递归 ，深度为3层
pattern cnt:3 str_cnt:9 i:9 value:a
continue !
pattern cnt:3 str_cnt:9 i:10 value:as
continue !
pattern cnt:3 str_cnt:9 i:11 value:asd
m.count(key) && m[key] == value KEY:a value:asd
backtrace pattern_cnt:4 str_cnt:12 //第六次进行递归，深度为4层
backtrace return true! //符合结束条件，返回true，4层递归结束
return true pattern_cnt:3 str_cnt:9//3层递归结束
return true pattern_cnt:2 str_cnt:6//2层递归结束
return true pattern_cnt:1 str_cnt:3//1层递归结束
return true if (!flag)  pattern_cnt:0 str_cnt:0 //最外层递归结束
flag:1