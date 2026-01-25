#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find the element that appears once
Given an array where every element appears exactly twice,
except for one element which appears only once. Find that element.

Approaches:

1) Brute Force
   - For every element, count its occurrences using a nested loop.
   - The element whose count is 1 is the answer.

   Time Complexity: O(n^2)
   Space Complexity: O(1)

2) Better Approach (Hashing using map / unordered_map)
   - Use a map to store frequency of each element.
   - Then find the element with frequency = 1.

   Time Complexity:
     - Using unordered_map → O(n) average, O(n^2) worst case
     - Using map (ordered) → O(n log n)

   Space Complexity: O(n)

3) Optimal Approach (Using XOR)
   - Use the property of XOR:
       x ^ x = 0
       x ^ 0 = x
   - XOR all elements of the array.
   - All duplicate elements cancel out, leaving the single element.

   Time Complexity: O(n)
   Space Complexity: O(1)

Source: Striver A2Z DSA Sheet
*/


// Brute->The Brute approach is that we can check for each element ony by one how many times it appear if it appears only 1 time we can simply return that element T.C will be O(n*n) and S.C will be O(1)
// Better-> For better approach we can use hashing to store frequencies of array elements we can use any map ordered and unordered but the T.C of ordered map is always O(log n) in each case best worst and average but for unordered map The TC will be O(1) in best case average case but O(n) for worst case which is not happen generally ,once in a bluemoon..so we can use unordered map..
// The T.C will be O(n) S.C will be O(n/2+1)=O(N)

// Optimal is very easy because we just have to perform xor operation with each each element of array and the T.C will be O(N) and S.C will be O(1)

int findOnceBrute(vector<int> &arr)

{
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count == 1)
            return arr[i];
    }
    return -1;
}

int findOnceBetter(vector<int> &arr)

{
    unordered_map<int, int> mpp;

    for (auto elem : arr)
        mpp[elem]++;

    for (auto elem : mpp)
    {
        if (elem.second == 1)
            return elem.first;
    }
    return -1;
}

int findOnceOptimal(vector<int> &arr)
{
    int xor1 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xor1= xor1^arr[i];
    }
    return xor1;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3, 2, 1, 3, 6,6,12};
    // int singleElement = findOnceBrute(arr);
    // int singleElement = findOnceBetter(arr);
    int singleElement = findOnceOptimal(arr);
    cout << singleElement;
    return 0;
}
