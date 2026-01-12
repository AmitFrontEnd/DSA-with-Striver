#include <bits/stdc++.h>
using namespace std;

/*
Problem: Rotate array elements right by d positions
Approach: Brute + Optimal (Reversal Algorithm)
Time Complexity: Brute -> O(n), Optimal -> O(n)
Space Complexity: Brute -> O(d), Optimal -> O(1)
Source: Striver A2Z DSA Sheet
*/

 
// Brute -> First way is to store last d elements in a temporary array, 
// then shift the remaining elements to the right by d positions, 
// and finally copy temp elements to the front of the array. 
// Time complexity O(n), space complexity O(d).
void rotateRightBrute(vector<int> &arr, int n, int d)
{
    d = d % n;   

    vector<int> temp;

    // Step 1: store last d elements
    for (int i = n - d; i < n; i++)
        temp.push_back(arr[i]);

    // Step 2: shift remaining elements to the right
    for (int i = n - 1; i >= d; i--)
        arr[i] = arr[i - d];

    // Step 3: put temp elements in front
    for (int i = 0; i < d; i++)
        arr[i] = temp[i];
}


// Optimal -> Use reversal algorithm:
// 1. Reverse last d elements
// 2. Reverse first n-d elements
// 3. Reverse whole array
// This rotates the array in O(n) time with O(1) space
void rotateRightOptimal(vector<int> &arr, int n, int d)
{
    d = d % n;   // handle case when d > n

    // Step 1: reverse last d elements
    reverse(arr.begin() + (n - d), arr.end());

    // Step 2: reverse first n-d elements
    reverse(arr.begin(), arr.begin() + (n - d));

    // Step 3: reverse whole array
    reverse(arr.begin(), arr.end());
}



int main()
{
    vector<int> arr = {672, 5, 35, 36, 46, 89, 62};
    int d = 2;

    // Brute -> uncomment below to test
    // rotateRightBrute(arr, arr.size(), d);

    // Optimal -> currently using optimal
    rotateRightOptimal(arr, arr.size(), d);

    // print result
    for (auto elem : arr)
        cout << elem << " ";

    return 0;
}
