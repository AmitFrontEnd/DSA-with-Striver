#include <bits/stdc++.h>
using namespace std;
/*
Problem:  Find Max Subarray Sum
Approach: Brute + Better + Optimal

Time Complexity:
Brute   -> O(N*N*N)
Better  -> O(N*N)
Optimal -> O(N)

Space Complexity:
Brute   -> O(1)
Better  -> O(1)
Optimal -> O(1)

Source: Striver A2Z DSA Sheet
*/

// Brute ->The brute approach is very simple. Just Calculate the sum of all the subarrays and check whose sum is greater.
// T.C will be O(n*n*n)
// S.C will be O(1)

int findMaxSubarraySumBrute(vector<int> &arr)
{
  int n = arr.size();
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int sum = 0;
      for (int k = i; k <= j; k++)
      {
        sum += arr[k];
      }
      maxi = max(sum, maxi);
    }
  }
  return maxi;
}

// The Better Solution is nothing but just reducing n cube to n square.

// T.C = O(n*n)
// S.C will be O(1)

int findMaxSubarraySumBetter(vector<int> &arr)
{
  int n = arr.size();
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += arr[j];
      maxi = max(sum, maxi);
    }
  }
  return maxi;
}

// Optimal-> The Optimal approach can be done using Kadane's algorithm in which we loop through the array and take a sum variable and initialize with 0 and we continously add elements to it but if any moment the sum becomes less than zero we again set sum to 0 as negative numbers will always reduce the sum so there is no sense to add negative numbers.
//
// T.C will be O(2N)
// S.C will be O(1)

int findMaxSubarraySumOptimal(vector<int> &arr)

{
  int n = arr.size();
  int sum = 0;
  int maxi = INT_MIN;
  int start = -1, ansEnd = -1, ansStart = -1;
  for (int i = 0; i < n; i++)
  {
    if (sum == 0)
      start = i;
    sum += arr[i];
    if (sum > maxi)
    {
      maxi = sum;
      ansStart = start;
      ansEnd = i;
    }

    if (sum < 0)
      sum = 0;
  }
  // If you want to print that longest subarray
  for (int i = ansStart; i <= ansEnd; i++)
  {
    cout << arr[i] << " ";
  }
  return maxi;
}

int main()
{
  vector<int> arr = {1, -3, 2, -3, -2, 3, 4, 5, -2};
  // int sum = findMaxSubarraySumBrute(arr);
  // int sum = findMaxSubarraySumBetter(arr);
  int sum = findMaxSubarraySumOptimal(arr);
  cout << sum;
  return 0;
}
