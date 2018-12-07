// THE CHALLENGE 
// write lambdas to compute the average, variance, standard devaition, and min/max of a vector
// You are not allowed to use loops of any kind. That means: no ranged-for, iterator-for, index-for, while, do-while, or goto.
// You are not allowed to create auxiliary functions. All operations must be defined within main.
// You are allowed to use any provided functions, but you may not use any functional utilities from the standard library.

#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <math.h>

using UnaryOperator = std::function<float(std::vector<float> const&)>;
using BinaryOperator = std::function<float(float, float)>;
using Compute = std::function<float(std::vector<float> const&)>;

void forEach(std::vector<float> const& data, UnaryOperator const& op)
{
    for (auto elem : data)
    {
        op(elem);
    }
}

float accumulate(std::vector<float> const& data, BinaryOperator const& op)
{
    float result{};
    for (auto elem : data)
    {
        result = op(result, elem);
    }
    return result;
}

int main()
{
    auto average = [](std::vector<float> const& data)
    {
        float sum = accumulate(data, [](float m_result, float m_elem){return m_result + m_elem;});
        return sum/data.size();
    };
    std::vector<float> m_data {2,5,3,4,1};
    std::cout<<"the average is : "<<average(m_data)<<std::endl;

    auto variance = [average](std::vector<float> const& data)
    {
        float avg = average(data);
        float sum = accumulate(data,[avg](float m_result, float m_elem){return m_result +(m_elem-avg)*(m_elem-avg);});
        return sum/data.size();
    };
    std::cout<<"the variance is : "<<variance(m_data)<<std::endl;

    auto standard_deviation = [variance](std::vector<float> const& data)
    {
        return sqrt(variance(data));
    };
    std::cout<<"the standard deviation is : "<<standard_deviation(m_data)<<std::endl;

    auto min = [](std::vector<float> const& data)
    {
        float min = data.at(0);
        accumulate(data,[&min](float m_result, float m_elem)
        {
        m_result = min;    
        if(m_elem < m_result)
        {
        min = m_elem; 
        }
        return min;
        });
    return min;
    };
    std::cout<<"the min is : "<<min(m_data)<<std::endl;

    auto max = [](std::vector<float> const& data)
    {
        float max = data.at(0);
        accumulate(data,[&max](float m_result, float m_elem)
        {
        m_result = max;    
        if(m_elem > m_result)
        {
        max = m_elem; 
        }
        return max;
        });
    return max;
    };
    std::cout<<"the max is : "<<max(m_data)<<std::endl;

}