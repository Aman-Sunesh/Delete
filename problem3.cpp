#include <iostream>
#include <vector>

using namespace std;

int maxSubSum(const vector<int>& a)
{
    int maxSum = 0;
    int thisSum = 0;

    for (int j = 0; j < a.size(); j++)
    {
        thisSum += a[j];

        if (thisSum > maxSum)
        {
            maxSum = thisSum;
        }

        else if (thisSum < 0)
        {
            thisSum = 0;
        }
    }

    return maxSum;
}

int main()
{
    vector<int> v = {-2, 11, -4, 13, -5, -2};
    cout << maxSubSum(v) << endl; 

    return 0;
}