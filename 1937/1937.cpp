/*
 * 1937.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
int a[501][501];
int d[501][501];
int n ; 
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1 ,0, 0 }; 

int go (int ypos, int xpos ) {
	
	int &ret = d[ypos][xpos] ; 
	if (ret != -1 ) return ret ;
	ret = 1;
	for (int i =0 ; i <4 ; i++ ) {
		int ny = ypos + dy[i] ; 
		int nx = xpos + dx[i] ; 
		if (ny < 1 || nx <1  || ny > n || nx > n ) continue;
		if ( a[ypos][xpos ] >= a[ny][nx] ) continue ;
		ret = max ( go (ny,nx) +1 , ret ) ; 
	}
	return ret ; 
}
int main() {

	cin >>  n ; 
	for (int i =1 ; i<=n ; i++ ) 
		for (int j= 1 ;j<=n ;j++){
			scanf("%d",&a[i][j] );
			d[i][j] = -1 ; 
		}

	int dab = -10 ; 
	for (int i =1 ; i<= n; i++ ){
		for (int j= 1 ;j<=n ;j++ ) {
			dab = max (dab, go(i,j) ) ;
		}
	}
	cout << dab << endl ; 


	return 0  ;
}
