#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find the largest element in an array
Approach: Brute + Optimal
Time Complexity: Brute -> O(n log n), Optimal -> O(n)
Space Complexity: Brute -> O(1) (if in-place sort), Optimal -> O(1)
Source: Striver A2Z DSA Sheet
*/

int main()
{
    // Brute -> First way to find the largest number is to sort the array and then return the last item.
    // Sorting takes O(n log n) time and accessing the last element is O(1). This is simple but not optimal.
    
    // Optimal -> Second way is to loop through the array, compare each element with a variable 'largest' 
    // initialized with the first element, and update it whenever a larger element is found. 
    // This way we find the largest element in a single traversal. Time complexity is O(n), space O(1).

    int arr[] = {34, 2, 5, 2, 67, 4, 3, 5};
    int largest = arr[0];

    for (int i = 1; i < 8; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
    }

    cout << largest;

    return 0;
}
