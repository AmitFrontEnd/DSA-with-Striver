#include <bits/stdc++.h>
using namespace std;

/*
Problem: Two Sum problem
Approach: Brute + Better + Optimal
Time Complexity: Brute -> O(n*n),Better -> O(N),Optimal-> O(N) + O(N log N)
Space Complexity:Brute->O(1),Better->O(n),Optimal-> S.C will be O(1) But we are distorting the array order and best for only variety 1
Source: Striver A2Z DSA Sheet
*/

// Brute -> The brute approach is very simple we can just check for each element with remaining element for sum e.g arr[i]+arr[j]==k if it is we can return true if not we can return false...
// T.C will be O(n*n)
// S.C will be O(1)

string isPossibleBrute(vector<int> &arr, int target)
{
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = i + 1; j < arr.size(); j++)
    {
      if (arr[i] + arr[j] == target)
        return "true";
    }
  }
  return "false";
}

// The Better Solution can be done using hashing, we will check for each time for each element that target-elem exist or not in hashmap if i t exist then we can return yes or no or maybe indexes for variety 2.
// It is the optimal approach for variety2 in which we have to return indexes
// T.C will be O(n) in unordered map avg case
// S.C will be O(n)

string isPossibleBetter(vector<int> &arr, int target)
{
  unordered_map<int, int> mpp;
  for (int i = 0; i < arr.size(); i++)
  {
    int required = target - arr[i];
    if (mpp.find(required) != mpp.end())
    {

      return "Yes";
    }
    mpp[arr[i]] = i;
  }
  return "No";
}

// Optimal-> The optimal approach is optimal only for variety 1 in which we just have to return true or false where index is not required.We first sort the array and then use 2 pointer approach.
// T.C will be O(N) + O(N log N)
// S.C will be O(1) But we are distorting the array order

string isPossibleOptimal(vector<int> &arr, int target)
{
  sort(arr.begin(), arr.end());
  int left = 0, right = arr.size() - 1;
  while (left < right)
  {
    if (arr[left] + arr[right] == target)
      return "Yes";
    else if (arr[left] + arr[right] > target)
      right--;
    else
      left++;
  }
  return "false";
}

int main()
{
  // 1,2,3,5,7,9,15
  vector<int> arr = {2, 5, 3, 1, 7, 9, 15};
  cout << isPossibleOptimal(arr, 18);
  return 0;
}
