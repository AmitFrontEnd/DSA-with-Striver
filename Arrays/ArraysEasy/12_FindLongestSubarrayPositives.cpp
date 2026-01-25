#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find Longest Subarray with sum K
Approach: Brute + Better + Optimal
Time Complexity:
  Brute: O(n^2)
  Better: O(n) [using unordered_map]
  Optimal: O(n)
Space Complexity:
  Brute: O(1)
  Better: O(n)
  Optimal:O(1)
Source: Striver A2Z DSA Sheet
*/

// Brute-> We can find the longest subarray by simply checking each elements just next to each other and store it as a sum if that sums will match to the the given k we can say that the subarray and can take a maxLength variable to store the maximum lenght of a subarray that equals to the given k..
// T.C will be O(n*n)
// S.C will be O(1)

int findLongestSubarrayBrute(vector<int> &arr, long long k)
{
  int size = arr.size();
  int maxLength = 0;
  for (int i = 0; i < size; i++)
  {
    long long sum = 0;
    for (int j = i; j < size; j++)
    {
      sum += arr[j];
      if (sum == k)
      {
        maxLength = max(maxLength, j - i + 1);
      }
    }
  }
  return maxLength;
}

// Better-> Second way is that we can use hashing the thought process behind hashing is that we can use prefix sum because if we are at a element and that element sum is equal to x and we want to find k then we simply subtract x-k and check if x-k anywhere occurs or not and if it does we can find the length of the subarray... *->This approach is optimal when arrays have zeroes,positives as well as negatives...
int findLongestSubarrayBetter(const vector<int> &arr, long long k)
{
  unordered_map<long long, int> subArrayMap;
  int size = arr.size();
  int maxLength = 0;
  long long sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
    if (sum == k)
    {
      maxLength = max(maxLength, i + 1);
    }

    if (subArrayMap.find(sum - k) != subArrayMap.end())
    {
      maxLength = max(maxLength, i - subArrayMap[sum - k]);
    }

    if (subArrayMap.find(sum) == subArrayMap.end())
      subArrayMap[sum] = i;
  }

  return maxLength;
}

// Optimal-> The optimal solution is valid only for positives and zeroes it can be done using two pointer approach and is also called a greedy algorithm...
// T.C will be O(N)
// S.C will be O(1)

int findLongestSubarrayOptimal(const vector<int> &arr, long long k)
{
  int size = arr.size();
  int maxLength = 0;
  long long sum = 0;
  int right = 0, left = 0;
  while (right < size)
  {
    sum += arr[right];

    while (sum > k)
    {
      sum -= arr[left];
      left++;
    }
    if (sum == k)
    {
      maxLength = max(maxLength, right - left + 1);
    }
    right++;
  }

  return maxLength;
}

int main(int argc, char const *argv[])
{
  vector<int> arr = {1, 2, 3, 5, 5, 1, 1, 1, 1, 2, 1, 3, 4};
  // cout << findLongestSubarrayBrute(arr, 6);
  cout << findLongestSubarrayOptimal(arr, 6);
  return 0;
}
