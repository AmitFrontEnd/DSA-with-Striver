#include <bits/stdc++.h>
using namespace std;

/*
Problem: Move Zeroes Ones and Two's in a sorted order
Approach: Brute + Better + Optimal
/*
Time Complexity:
Brute   -> O(n log n)
Better  -> O(2N) ≈ O(N)
Optimal -> O(N)

Space Complexity:
Brute   -> O(1)
Better  -> O(1)
Optimal -> O(1)

Source: Striver A2Z DSA Sheet
*/

// Brute -> The brute approach is very simple we can just sort the original array.
// T.C will be O(n log n)
// S.C will be O(1)

void move0s1s2sBrute(vector<int> &arr)
{
  sort(arr.begin(), arr.end());
}

// The Better Solution can be done using we first count how many zeroes ,ones and two's are there in the array and then overwrite the existing array values...
// T.C will be O(2n)
// S.C will be O(1)
void move0s1s2sBetter(vector<int> &arr)
{
  int count0 = 0, count1 = 0, count2 = 0;
  for (auto elem : arr)
  {
    if (elem == 0)
      count0++;
    else if (elem == 1)
      count1++;
    else
      count2++;
  }

  for (int i = 0; i < count0; i++)
  {
    arr[i] = 0;
  }
  for (int i = count0; i < count0 + count1; i++)
  {
    arr[i] = 1;
  }
  for (int i = count0 + count1; i < arr.size(); i++)
  {
    arr[i] = 2;
  }
}

// Optimal-> The optimal approach is based on the dutch national flag algorithm which states that we will use three pointers low, mid, and high and follow three rules {index 0 to low-1 will be filled with value 0 and index low to mid-1 will be filled with value 1 and index mid to high will be filled with value 0,1,2 unsorted order and index high+1 to n-1 will be filled with value 2} we can use this rule to sort the array...
// T.C will be O(N)
// S.C will be O(1)

void move0s1s2sOptimal(vector<int> &arr)
{
  int low = 0, high = arr.size() - 1, mid = 0;

  while (mid <= high)
  {
    if (arr[mid] == 0)
    {
      swap(arr[low], arr[mid]);
      mid++;
      low++;
    }
    else if (arr[mid] == 1)
      mid++;
    else
    {
      swap(arr[mid], arr[high]);
      high--;
    }
  }
}
int main()
{
  vector<int> arr = {1, 1, 0, 0, 2, 1, 1, 2, 2, 0, 2, 2, 0};
  // move0s1s2sBrute(arr);
  // move0s1s2sBetter(arr);
  move0s1s2sOptimal(arr);
  for (auto elem : arr)
    cout << elem << " ";
  return 0;
}
