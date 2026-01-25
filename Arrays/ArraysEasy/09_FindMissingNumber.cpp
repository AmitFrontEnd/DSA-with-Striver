#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find Missing Number
Approach: Brute + Better + Optimal
Time Complexity:
    Brute -> O(n*n), Space -> O(1)
    Better (Hashing) -> O(n), Space -> O(n)
    Optimal1 (Sum) -> O(n), Space -> O(1)
    Optimal2 (XOR) -> O(n), Space -> O(1)
Space Complexity: Mentioned above for each approach
Source: Striver A2Z DSA Sheet
*/

// Brute->First method that comes to my mind is that we can run a loop till 1 to N and inside that loop ,run again a loop for elements that present in the array and check if all the numbers are present if any of the number is not present we can return the index from the outer loop
// The T.C of this approach is O(n*n) and S.C is O(1)

// Better-> Second method is that we can have better solution than brute is, we can use hashing technique which is that we can create an array of size n+1 the n+1 size is taken because array indexing is 0 based so we had to take 1 extra for 0 index now we can store all the places with 0 initially and then loop through all the elements and place 1 to the element place inside hashing array. this will help us finding the missing number by checking position if any place the number is 0 instead of 1 then that will be our missing number.
// T.C will be 2N S.C is O(N)
// Optimal1-> The method first optimal method we can use is that first sum of n numbers and then sum of the elements which is given in the array after that take the difference of both and you will get your missing number..
// T.C is O(n) and S.C is O(1) but it can overflow for a very large number for n as when we are trying to do operation like n*(n+1)/2 it will cause overflow so we can use long long int but this will take slighter more memory than int that's where we can go on optimal 2 approach which is using xor operator

// Optimal2 we can use XOR operator for this task and this is optimal as it takes O(N) and S.C is O(1)

int getMissingNumberBrute(const vector<int> &arr, int n)
{
  for (int i = 1; i <= n; i++)
  {
    bool isMissing = true;
    for (int j = 0; j < n - 1; j++)
    {
      if (arr[j] == i)
      {
        isMissing = false;
        break;
      }
    }
    if (isMissing)
      return i;
  }
  return -1;
}
int getMissingNumberBetter(const vector<int> &arr, int n)
{
  int hash[n + 1] = {0};
  for (int i = 0; i < n - 1; i++)
  {
    hash[arr[i]] = 1;
  }
  for (int i = 1; i < n + 1; i++)
  {
    if (hash[i] == 0)
      return i;
  }
  return -1;
}
int getMissingNumberOptimal1(const vector<int> &arr, int n)
{
  int actualSum = (n * (n + 1)) / 2;
  int obtainedSum = 0;
  for (int i = 0; i < n - 1; i++)
  {
    obtainedSum += arr[i];
  }
  return actualSum - obtainedSum;
}
int getMissingNumberOptimal2(const vector<int> &arr, int n)
{
  int xor1 = 0, xor2 = 0;

  for (int i = 0; i < n - 1; i++)
  {
    xor2 = xor2 ^ arr[i];
    xor1 = xor1 ^ (i + 1);
  }
  xor1 = xor1 ^ n;
  return xor1 ^ xor2;
}

int main()
{

  vector<int> arr = {1, 2, 3, 8, 6, 4, 7};

  // int missingNumberBrute = getMissingNumberBrute(arr, 8);
  // cout << "Missing number is: " << missingNumberBrute << endl;
  // int missingNumberBetter = getMissingNumberBetter(arr, 8);
  // cout << "Missing number is: " << missingNumberBetter << endl;
  int missingNumberOptimal2 = getMissingNumberOptimal2(arr, 8);
  cout << "Missing number is: " << missingNumberOptimal2 << endl;

  return 0;
}