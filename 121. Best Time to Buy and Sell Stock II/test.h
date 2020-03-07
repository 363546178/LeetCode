#include<vector>
using std::vector;

class test
{
    public:
    int max_output(vector<int> &prices)
    {
        int final_cost = 0;
        for(auto i = prices.begin();i!= prices.end();++i)
        {
            if(i+1 != prices.end() && *(i+1) > *i)
            {
                final_cost += *(i+1) - *i;
            }
        }
        return final_cost;
    }    
};

//直接采用指针的方式调用迭代器实现，较为巧妙
//有没有其他更加直接的写法？