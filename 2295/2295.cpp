/*
 * 2295.cpp
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
	int a[1111];
	for (int i = 0 ; i<n ; i++ ) {
		cin >> a[i]	;		
	}
	sort ( a, a+n  ) ; 
	for (int i =n-1 ; i>=0 ; i-- ) {
		for (int j= 0 ;j < n ;j++ ) {
			for (int k = 0 ; k<n ; k++ ){
				int sum = a[j] + a[k] ;
				if ( binary_search (a,a+n , a[i]-sum)) {
					printf("%d\n",a[i] ) ;
					return 0  ;
				} 
			}
		}


	}

	return 0  ;
}
