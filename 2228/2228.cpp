/*
 *  2228   
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int a[101];
int d[101][55];
int main(){
	int n , m ;
	scanf("%d%d",&n,&m);
	

	for (int i =1 ; i<=n; i++){
		scanf("%d",&a[i]);		
	}
	for (int i =0 ; i<=100 ; i++){
		for (int j=1 ; j<=50 ;j++){
			d[i][j]= -987654321;
		}
	}
	d[1][1] = a[1];
	int ans =-987654321;
	for (int j =1 ;j <=m ;j++){
		for (int i =2;i<=n ;i++ ){
			d[i][j] = d[i-1][j] + a[i];
			for (int p = 0 ; p< i-1 ; ++p ) {
				d[i][j] = max (d[i][j] , d[p][j-1] + a[i] ) ;
			}
			ans = max ( ans , d[i][m] ) ; 
		}
	}
	printf("%d\n",ans);
}
