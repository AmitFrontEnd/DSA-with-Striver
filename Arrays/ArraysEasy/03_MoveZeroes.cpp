#include <bits/stdc++.h>
using namespace std;

/*
Problem: Move all zeros to the end of the array
Approach: Brute + Optimal
Time Complexity: Brute -> O(n), Optimal -> O(n)
Space Complexity: Brute -> O(x) (temporary array for non-zero elements), Optimal -> O(1)
Source: Striver A2Z DSA Sheet
*/

void rm0Brute(vector<int> &arr, int n)
{
    // Brute -> First store all non-zero numbers in a temp array.
    // Then put all elements of temp back into the original array.
    // Fill remaining positions with 0.
    // Time complexity is O(n + n + n) = O(n), space complexity O(x) where x = number of non-zero elements.

    vector<int> temp;

    for (auto elem : arr)
    {
        if (elem != 0)
            temp.push_back(elem);
    }

    for (int i = 0; i < temp.size(); i++)
        arr[i] = temp[i];

    for (int i = temp.size(); i < n; i++)
        arr[i] = 0;
}

void rm0Optimal(vector<int> &arr, int n)
{
    // Optimal -> Use two pointers to optimize space to O(1)
    // Let j point to the first zero in the array.
    // Traverse from j+1 to n. Whenever a non-zero element is found,
    // swap it with arr[j] and increment j. Repeat until array ends.
    // Time complexity O(n), space complexity O(1)

    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return; // no zeros found

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> arr = {4, 0, 12, 0, 15, 35, 0, 35};

    // Brute -> uncomment below to test
    // rm0Brute(arr, arr.size());

    // Optimal -> currently using optimal
    rm0Optimal(arr, arr.size());

    for (auto elem : arr)
        cout << elem << " ";

    return 0;
}
