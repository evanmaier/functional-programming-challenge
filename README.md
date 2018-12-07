# functional-programming-challenge
THE CHALLENGE:

Suppose that we have a vector of data, and we want to perform certain operations on the vector. The operations we wish to compute are:

Compute the average,
variance,
standard deviation, and
min/max.
Now it is true that we could simply implement functions to do these operations and that's it. In order to make it interesting you are given the following restrictions:

You are not allowed to use loops of any kind. That means: no ranged-for, iterator-for, index-for, while, do-while, or goto.
You are not allowed to create auxiliary functions. All operations must be defined within main.
You are allowed to use any provided functions, but you may not use any functional utilities from the standard library.
To aide you in your task, you are given the following set of definitions:

using UnaryOperator = std::function<void(float)>;
using BinaryOperator = std::function<float(float, float)>;
using Compute = std::function<float(std::vector<float> const&>);
These create new types for the different kinds of functions that we will be using throughout this challenge. In addition, you are also given the following functions:

void forEach(std::vector<float> const& data, UnaryOperator const& op)
{
    for (auto elem : data)
    {
        op(elem);
    }
}
forEach will iterate over the vector of data and apply the UnaryOperator function to each element. Notice that UnaryOperator does not return anything. This means that any results that you want to obtain must be captured through the closure of a lambda.

float accumulate(std::vector<float> const& data, BinaryOperator const& op)
{
    float result{};
    for (auto elem : data)
    {
        result = op(result, elem);
    }
    return result;
}
accumulate is used to basically "sum up" the numbers in a vector of data. In order to do this, it takes a BinaryOperator which acts as the summation. The way this is accomplished is by accumulating the result of adding the first parameter to the second in the first parameter. Ultimately, this is emulating the following: result += elem but in a more general way.
