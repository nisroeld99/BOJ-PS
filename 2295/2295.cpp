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
	/*
	 *  수업시간 다뤘던 binary_search 을 이용한 문제,
	 *  4중첩 for 문을 사용한다면 O(n^4) 이기때문에, O(1000000000000) 는 TLE 에 해당한다.
	 *  따라서 O(n^3 log n ) 에 해당하는 전략으로 하면 accept 
	 * */
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
