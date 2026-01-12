#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find the second largest number in an array
Approach: Brute + Better (Two Pass) + Optimal (One Pass)
Time Complexity: Brute -> O(n log n), Better -> O(2n), Optimal -> O(n)
Space Complexity: Brute/Better/Optimal -> O(1)
Source: Striver A2Z DSA Sheet
*/

int main()
{
    int arr[] = {34, 2, 5, 2, 67, 4, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Brute -> First way is to sort the array and pick the second largest element.
    // We have to check carefully in case the largest element appears multiple times.
    // Time complexity O(n log n), space O(1)

    // Better (Two Pass) -> First, traverse array to find the largest element.
    // Then traverse again to find the maximum element that is less than the largest.
    // Time complexity O(2n), space O(1)

    // Optimal (One Pass) -> Maintain two variables, largest and second largest.
    // Traverse the array once:
    // If current element > largest -> update second largest = largest, largest = current
    // Else if current element < largest and > second largest -> update second largest
    // Time complexity O(n), space O(1)

    int largest = arr[0], slargest = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > slargest)
        {
            slargest = arr[i];
        }
    }

    cout << "Largest number is: " << largest << endl;
    cout << "Second largest number is: " << slargest << endl;

    return 0;
}
