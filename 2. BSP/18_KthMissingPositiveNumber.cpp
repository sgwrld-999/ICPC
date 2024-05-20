#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Logic ExplanationInitialize Variables:missingEle: A vector to store the missing elements.current: A variable initialized to the first element of the array, representing the expected value in the sequence.Iterate through the array:For each element in the array, check if there are any missing elements between the current value and the array element.Use a while loop to add all missing elements to missingEle until current catches up to the array element.Boundary Check:After collecting all missing elements, check if the number of missing elements is less than k. If so, return -1 since there aren't enough missing elements.Return k-th Missing Element:If there are enough missing elements, return the k-th missing element from missingEle.ExampleConsider the array a[] = {2, 3, 7, 11, 13} and k = 5.Dry RunInitial Setup:a = {2, 3, 7, 11, 13}n = 5k = 5missingEle = []current = 2Iteration:i = 0:current = 2a[0] = 2current matches a[0], increment current to 3.i = 1:current = 3a[1] = 3current matches a[1], increment current to 4.i = 2:current = 4a[2] = 7current (4) is less than a[2] (7), add 4, 5, and 6 to missingEle.missingEle = {4, 5, 6}Increment current to 7.i = 3:current = 7a[3] = 11current (7) matches a[3], increment current to 8.current (8) is less than a[3] (11), add 8, 9, and 10 to missingEle.missingEle = {4, 5, 6, 8, 9, 10}Increment current to 11.i = 4:current = 11a[4] = 13current matches a[4], increment current to 12.current (12) is less than a[4] (13), add 12 to missingEle.missingEle = {4, 5, 6, 8, 9, 10, 12}Increment current to 13.Boundary Check:missingEle contains 7 elements: {4, 5, 6, 8, 9, 10, 12}k = 5The 5th missing element is 9 (index k-1 which is 4).
*/
int KthMissingElement(int a[], int n, int k)
{
    vector<int> missingEle;
    int current = a[0];

    for(int i = 0; i < n; ++i)
    {
        while(current < a[i])
        {
            missingEle.push_back(current);
            current++;
        }
        current++;
    }

    if(k > missingEle.size())
    {
        return -1;
    }

    return missingEle[k-1];
}
int KthMissingElementBinarySeach(int arr[], int n, int K) {
    int low = 0;
    int high = n - 1;
    int start = arr[0] - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] - (mid + 1 + start) == K && arr[mid] - arr[mid - 1] != 1) {
            return arr[mid] - 1;
        } else if (mid == n - 1 && arr[mid] - n == K) {
            return arr[mid] - 1;
        } else if (mid + 1 + start == arr[mid]) {
            low = mid + 1;
        } else if (arr[mid] - (mid + 1 + start) < K) {
            low = mid + 1;
        } else if (arr[mid] - (mid + 1 + start) >= K) {
            high = mid;
        }

        if (mid == low && low == high) {
            break;
        }
    }

    if (arr[low] - (low + 1 + start) > K) {
        for (int p = arr[low]; p > arr[low - 1]; --p) {
            if (p - (low + start) == K) {
                return p;
            }
        }
    }
    return -1;
}


int main() {
    int a[] = {2, 3, 7, 11, 13};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;
    cout << KthMissingElement(a, n, k) << endl;  // Output should be 9
    return 0;
}
