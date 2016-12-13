/*
 * 10973.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int main() {

	int n ;
	cin >> n;
	vector<int> v;
	
	while (n--){
		int sc;
		cin >> sc; 
		v.push_back(sc); 
	}

	if ( prev_permutation(v.begin(), v.end() ) == false  ){
		printf("-1\n");
	}else {
		for (auto x : v) 
			printf("%d ", x ) ;	
		printf ("\n") ; 
	}
	return 0  ;
}
