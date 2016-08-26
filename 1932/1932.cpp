/*
 * 1932.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
int a[501][510];
int d[555][555];
int main() {

	int n ;
	scanf("%d",&n);
	for (int i = 1;  i<=n; i++){
		for (int j=1 ; j<=i ; j++ ) {
			scanf("%d",&a[i][j]) ;
		}
	}
	d[1][1] = a[1][1];
	for (int i =2 ; i<=n; i++){
		for (int j=1 ; j<=i ;j++){
			d[i][j] = max ( d[i-1][j] , d[i-1][j-1] )  + a[i][j]  ; 
		}
	}
	int dab = -10 ;
	for (int i= 1 ; i<=n; i++ ){
		dab = max (dab, d[n][i] ) ;
	}
	cout <<dab<<endl;

	return 0  ;
}
