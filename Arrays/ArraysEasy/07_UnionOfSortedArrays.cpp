#include <bits/stdc++.h>
using namespace std;

/*
Problem: Union of Two Sorted Arrays
Approach: Brute + Optimal
Time Complexity: Brute -> O(arr1 log arr1 + arr2 log arr2 + arr1+arr2), Optimal -> O(arr1 + arr2)
Space Complexity: Brute -> O(arr1 + arr2) (using set), Optimal -> O(arr1 + arr2) (only result array)
Source: Striver A2Z DSA Sheet
*/

// Brute -> First approach is simple: traverse both arrays, store all elements in a set.
// The set keeps elements sorted and removes duplicates automatically.
// Then copy elements from the set into a new array. 
// Time complexity O(arr1 log arr1 + arr2 log arr2 + arr1+arr2), space O(arr1 + arr2)

// Optimal -> Since arrays are already sorted, we can use two pointers.
// i points to arr1, j points to arr2.
// Compare arr1[i] and arr2[j]:
// 1) If arr1[i] <= arr2[j], add arr1[i] to union array (if not duplicate), i++
// 2) Else add arr2[j] to union array (if not duplicate), j++
// Continue until one array finishes, then add remaining elements of the other array avoiding duplicates.
// Time complexity O(arr1 + arr2), Space complexity O(arr1 + arr2) (for result array only)

vector<int> getUnionArray(vector<int> &arr1, int s1, vector<int> &arr2, int s2)
{
    vector<int> unionArr;
    int i = 0, j = 0;

    while (i < s1 && j < s2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != arr1[i])
                unionArr.push_back(arr1[i]);
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != arr2[j])
                unionArr.push_back(arr2[j]);
            j++;
        }
    }

    while (i < s1)
    {
        if (unionArr.size() == 0 || unionArr.back() != arr1[i])
            unionArr.push_back(arr1[i]);
        i++;
    }

    while (j < s2)
    {
        if (unionArr.size() == 0 || unionArr.back() != arr2[j])
            unionArr.push_back(arr2[j]);
        j++;
    }

    return unionArr;
}

int main()
{
    vector<int> arr1 = {4, 5, 6, 6, 6, 6, 6, 8};
    vector<int> arr2 = {3, 4, 5, 5, 5, 10, 11, 12, 22};

    // Brute -> can be implemented using set (commented)
    // Optimal -> currently using two-pointer approach
    vector<int> unionArr = getUnionArray(arr1, arr1.size(), arr2, arr2.size());

    for (auto elem : unionArr)
        cout << elem << " ";
    cout << endl;

    return 0;
}
