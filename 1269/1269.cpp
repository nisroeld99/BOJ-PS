/*
 * 1269.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int main() {
	int n1,n2;
	scanf("%d%d",&n1,&n2);

	vector<int>v1,v2;
	for (int i=0 ; i<n1 ; i++ ){ 
		int sc1;
		scanf("%d",&sc1) ;
		v1.push_back(sc1);
	}
	for (int i = 0 ; i<n2 ; i++ ) {
		int sc1;
		scanf("%d",&sc1) ;
		v2.push_back(sc1); 
	}
	sort ( v2.begin() , v2.end() ) ;

	int ans = 0 ;
	for (int i = 0 ; i< n1 ; i++ ) {
		if ( binary_search(v2.begin(),v2.end(), v1[i] )){
			ans ++ ;			
		} 
	
	}
	printf("%d\n" ,n1+n2- 2*ans ) ;


	return 0  ;
}
