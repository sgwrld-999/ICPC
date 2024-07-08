#include<bits/stdc++.h>
using namespace std;
/*
Problem link : https://www.geeksforgeeks.org/problems/square-root/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
Problem name : Square root of a perfect square
Explanation we've to find the square root of a number.
Brute force approach : We can iterate from 1 to n and check if i*i is equal to n or not. Time complexity of this approach is O(n).
Optimal approach : We can use binary search to find the square root of a number. Time complexity of this approach is O(log(n)).
How?
1^2 = 1
2^2 = 4
3^2 = 9
4^2 = 16
5^2 = 25
6^2 = 36
.
.
.


n^2 = n*n


According to the question if the number if not a perfect number then check with floor function.
For example : 5 -> floor(sqrt(5)) : 


Here 1 2 3 4 5 6 7 8 9 10 11 .......n
Form 1 to 3 ->  1
From 4 to 8 -> 2
From 9 to 15 -> 3
From 16 to 24 -> 4
..
..
..
From (n-1)^2 to (n)^2-1 -> n-1
For n^2 -> n

The idea is to find the number which is less than or equal to the given number.
Or terminate the half as the number is not a perfect square or can be a perfect square.
How we are eliminating the half?
We can see that if the mid element is less than the number then we can move to the right side.
If the mid element is greater than the number then we can move to the left side.
If the mid element is equal to the number then we can return the mid element.
*/

class Solution {
public:
    long long int floorSqrt(long long int x) 
    {
        // Base case
        if (x == 0 || x == 1) return x;

        long long int low = 1;
        long long int high = x;
        long long int ans = 0;

        while (low <= high) {
            long long int mid = low + (high - low) / 2;
            long long int sqrtx = mid * mid;

            if (sqrtx == x) return mid;
            else if (sqrtx < x) {
                low = mid + 1;
                ans = mid;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int x;
        cin >> x;
        Solution obj;
        cout << obj.floorSqrt(x) << endl;
    }
    return 0;
}
/*
Testcase : 
1
5
Output : 2

*/