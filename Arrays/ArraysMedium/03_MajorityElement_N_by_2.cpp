#include <bits/stdc++.h>
using namespace std;
/*
Problem: Majority Element Greater than N by 2
Approach: Brute + Better + Optimal

Time Complexity:
Brute   -> O(N*N)
Better  -> O(N) average
Optimal -> O(N)

Space Complexity:
Brute   -> O(1)
Better  -> O(N)
Optimal -> O(1)

Source: Striver A2Z DSA Sheet
*/

// Brute ->The brute approach is very simple just check for each number that how many times it has appeared. if a number has appeared more than n/2 simple return that number.
// T.C will be O(n*n)
// S.C will be O(1)

int findMajorityElementBrute(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    int count = 0;
    for (int j = 0; j < arr.size(); j++)
    {
      if (arr[i] == arr[j])
        count++;
    }
    if (count > n / 2)
      return arr[i];
  }
  return -1;
}

// The Better Solution can be done using hashing as it helps to count how many times a number appears. we just simply store the element as key and no of times it has appeared as value. we will use unordered map as it's best and average case T.C is O(1) for find and insert

// T.C = O(n) average, O(n^2) worst (unordered_map collision case)
// S.C will be O(n)

int findMajorityElementBetter(vector<int> &arr)
{

  unordered_map<int, int> mpp;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    mpp[arr[i]]++;
  }

  for (auto elem : mpp)
  {
    if (elem.second > n / 2)
      return elem.first;
  }

  return -1;
}

// Optimal-> The Optimal approach can be done using Moore's Voting Algorithm.
// I use Boyer–Moore to find a candidate in O(n) time and O(1) space,
// then verify it in a second pass since majority may or may not exist.
// T.C will be O(2N)
// S.C will be O(1)

int findMajorityElementOptimal(vector<int> &arr)
{
  int count = 0;
  int elem = -1;
  for (int i = 0; i < arr.size(); i++)
  {
    if (count == 0)
    {
      elem = arr[i];
      count++;
    }
    else if (arr[i] == elem)
    {
      count++;
    }
    else
      count--;
  }
  count = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (elem == arr[i])
      count++;
  }

  if (count > arr.size() / 2)
    return elem;

  return -1;
}

int main()
{
  vector<int> arr = {2, 2, 3, 2, 2, 5, 6, 7, 2, 3, 2, 22};
  // cout << findMajorityElementBrute(arr);
  // cout << findMajorityElementBetter(arr);
  cout << findMajorityElementOptimal(arr);
  return 0;
}
