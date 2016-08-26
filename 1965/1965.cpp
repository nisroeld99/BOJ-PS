/*
 * 1965.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
int a[1001];
int d[1001];
int main() {

	int n ;
	cin >> n; 
	for (int i = 1 ; i<=n ; i++ ) 
		scanf("%d",&a[i]) ;

	int cnt=1 ; 
	d[1] = a[1] ; 
	for (int i =2 ; i<=n ; i++){
		if ( a[i] > d[cnt]) {
			cnt ++ ;
			d[cnt] = a[i] ;
			continue;
		}
		auto it = lower_bound(d+1, d+cnt+1 , a[i] ) ;
		*it = a[i] ;

	}
	cout << cnt << endl ;



	return 0  ;
}
