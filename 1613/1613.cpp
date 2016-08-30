/*
 * 1613.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int d[401][401] ; 


int main() {
	int n, k ;
	cin >> n >> k ; 
	for (int i =0 ; i<k ; i++ ) {
		int n , m ;
		scanf("%d%d",&n,&m) ;
		d[n][m] = 1;
		d[m][n] = -1;
	}
	for (int k = 1 ; k<= n ; k++ ) 
		for (int i = 1 ; i<=n ; i++ )
			for (int j=1 ;j<=n ;j++ ){
				if ( d[i][k] == 1 && d[k][j] ==1 ){
					d[i][j] =1 ; 
				}
				if (d[i][k] ==-1 && d[k][j] == -1 ) {
					d[i][j] =-1 ; 
				}
			}

	int cnt ; 
	cin >> cnt ; 
	while (cnt -- ) {
		int n,m;
		scanf("%d%d",&n,&m);
		if (d[n][m] == 1 ) {  //m이 나중 
			printf("-1\n");
		}else if (d[n][m] == -1 ){
			printf("1\n");

		} else {
			printf("0\n"); 
		}
	}

	return 0  ;
}
