#include <bits/stdc++.h>
using namespace std;

/*
Problem: Remove duplicates from a sorted array
Approach: Brute + Optimal
Time Complexity: Brute -> O(n log n + n), Optimal -> O(n)
Space Complexity: Brute -> O(n) (using set), Optimal -> O(1)
Source: Striver A2Z DSA Sheet
*/

int removeDuplicatesBrute(vector<int> &arr, int n)
{
    // Brute -> First way is to use a set to store all unique elements.
    // Loop through the array and insert each element into the set.
    // Then copy elements of the set back into the array.
    // Time complexity is O(n log n + n) due to set insertion and copying.
    // Space complexity O(n) for the set.
    
    set<int> numbers;
    int index = 0;
    for (auto elem : arr)
        numbers.insert(elem);

    for (auto elem : numbers)
        arr[index++] = elem;

    return index;
}

int removeDuplicatesOptimal(vector<int> &arr, int n)
{
    // Optimal -> Since array is sorted, we can use two pointers.
    // i points to the last unique element, j scans the array from 1 to n-1.
    // If arr[j] != arr[i], increment i and copy arr[j] to arr[i].
    // At the end, i+1 is the number of unique elements.
    // Time complexity O(n), space O(1).

    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}

int main()
{
    vector<int> arr = {3, 3, 3, 4, 8, 9, 10};

    // Brute -> uncomment below to test
    // int uniqueSize = removeDuplicatesBrute(arr, arr.size());

    // Optimal -> currently using optimal
    int uniqueSize = removeDuplicatesOptimal(arr, arr.size());

    for (int i = 0; i < uniqueSize; i++)
        cout << arr[i] << " ";
    cout << "\nuniqueSize is: " << uniqueSize << endl;

    return 0;
}
