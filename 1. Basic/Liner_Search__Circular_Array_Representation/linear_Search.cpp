#include<iostream>
#include<vector>

/*
LinkToArticle: https://www.geeksforgeeks.org/dsa/linear-search/
*/

class Solution{
public:
	int linearSearch(vector<int>& arr, int x){
		int n = arr.size();
		for(int i = 0 ; i < n ; i++){
			if(arr[i] == x) return i;
		}

		return i;
	}
};


int main(){
	int n1 ;
	cin >> n1;
	vector<int> arr1(n1);

	for(auto &it: num) cin >> it;
	
	int searchEle ;
	cin >> searchEle;

	Solution sol;
	int idx = sol.linearSearch(arr1,searchEle);
	if(idx != -1)	cout << "The index of the search element" << idx << endl;
	eles cout << "Element is not present in the array" << endl;
]
