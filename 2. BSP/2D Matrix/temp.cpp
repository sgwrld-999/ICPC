#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t ;
	while(t--){
	    int n , k ;
	    cin >> n >> k ;
	    vector<int> ipVec;
	    for(int i = 0 ; i < n ; i++){
	        int temp ;
	        cin >> temp ;
	        ipVec.push_back(temp);
	    }
	    for(int i = 0 ; i < n ; i++){
	       cout <<  ipVec[i] << endl;
	    }
	}
	return 0;
}
