#include <bits/stdc++.h>
using namespace std;

/*
Problem: Intersection of Two Sorted Arrays
Approach: Brute + Optimal
Time Complexity: Brute -> O(n*m), Optimal -> O(n + m)
Space Complexity: Brute -> O(m), Optimal -> O(1)
Source: Striver A2Z DSA Sheet
*/

int main()
{
    vector<int> arr1 = {2, 3, 3, 4, 5, 8};
    vector<int> arr2 = {2, 2, 3, 4, 4, 5, 6, 7};

    // Brute -> First way to find intersection is to take one array (arr1) and for the other array (arr2) 
    // we create a visited array to track which elements have already been used in the intersection. 
    // Then we loop through arr1, and for each element, we check every element in arr2. 
    // If we find a match and it has not been visited yet, we add that element to the intersection and mark it as visited.
    // This ensures that duplicates are handled correctly. Time complexity of this approach is O(n*m), where n and m are the sizes of the arrays.
    
    vector<int> visited(arr2.size(), 0);
    vector<int> bruteAns;

    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            if (arr1[i] == arr2[j] && visited[j] == 0)
            {
                visited[j] = 1;
                bruteAns.push_back(arr1[i]);
                break;
            }
        }
    }

    cout << "Brute: ";
    for (auto x : bruteAns) cout << x << " ";
    cout << endl;

    // Optimal -> Second way to find intersection is by using the fact that both arrays are sorted. 
    // We use two pointers, i and j, starting at 0 for arr1 and arr2 respectively. 
    // Then we compare arr1[i] and arr2[j]. 
    // If arr1[i] is smaller, we move i ahead. If arr2[j] is smaller, we move j ahead. 
    // If they are equal, we add the element to the intersection and move both pointers forward. 
    // This way we traverse both arrays only once. Time complexity of this approach is O(n + m) and space complexity is O(1).

    vector<int> optimalAns;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j]) i++;
        else if (arr1[i] > arr2[j]) j++;
        else
        {
            optimalAns.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    cout << "Optimal: ";
    for (auto x : optimalAns) cout << x << " ";
    cout << endl;

    return 0;
}
