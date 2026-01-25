#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find Maximum Consecutive Ones
Approach: Optimal
Time Complexity: O(n)
Space Complexity: O(1)
Source: Striver A2Z DSA Sheet
*/

// Optimal-> I think this problem is very easy so no brute and better approach discussed here the optimal and easy approach is that we can take a count variable and maxi and initialize both with 0 value, and whenever we find 1 we can increase the value of count and then check if count is greater than maxi then store count value in maxi variable.

int findMaxConsecutiveOnes(vector<int> &nums)
{
  int count = 0, maxi = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == 1)
    {
      count++;
      maxi = max(count, maxi);
    }
    else
      count = 0;
  }
  return maxi;
}

int main(int argc, char const *argv[])
{
  vector<int> arr = {0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1};
  cout << findMaxConsecutiveOnes(arr);
  return 0;
}
