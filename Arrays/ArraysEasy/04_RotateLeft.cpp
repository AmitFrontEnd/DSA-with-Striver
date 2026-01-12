#include <bits/stdc++.h>
using namespace std;

/*
Problem: Rotate array elements left by d positions
Approach: Brute + Optimal
Time Complexity: Brute -> O(n), Optimal -> O(n)
Space Complexity: Brute -> O(d), Optimal -> O(1)
Source: Striver A2Z DSA Sheet
*/

// Brute -> First way is to store the first d elements in a temporary array, 
// then shift the remaining elements of the original array to the left by d positions, 
// and finally copy the temp array elements back to the last d positions of the original array. 
// Time complexity O(n), space complexity O(d).

// void rotateLeftBrute(vector<int> &arr, int n, int d)
// {
//     d = d % n;
//     vector<int> temp;
//     for (int i = 0; i < d; i++)
//         temp.push_back(arr[i]);

//     for (int i = d; i < n; i++)
//         arr[i - d] = arr[i];

//     for (int i = n - d; i < n; i++)
//         arr[i] = temp[i - (n - d)];
// }

void rotateLeftOptimal(vector<int> &arr, int n, int d)
{
    // Optimal -> Use reverse method to rotate in-place.
    // Steps:
    // 1. Reverse first d elements
    // 2. Reverse remaining n-d elements
    // 3. Reverse the entire array
    // Time complexity O(n), space complexity O(1)

    d = d % n;
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> arr = {672, 5, 35, 36, 46, 89, 62};
    int d = 2;

    // Brute -> uncomment below to test
    // rotateLeftBrute(arr, arr.size(), d);

    // Optimal -> currently using optimal
    rotateLeftOptimal(arr, arr.size(), d);

    for (auto elem : arr)
        cout << elem << " ";
    cout << endl;

    return 0;
}
