/*
 *  2240   
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int a[1001];
int d[1001][31];
int main(){
 int n , m ;
 scanf("%d%d",&n,&m) ;
 for (int i =1 ; i<= n; i++){
 	 scanf("%d",&a[i]);
 }
 if ( a[1] == 1){
 		d[1][0] =1 ;
  }else {
	d[1][1] = 1;
 }

 for (int i =2 ; i<=n; i++){
 		for (int j= 0 ; j<= m ; ++j){
			int now = j%2 ==0 ? 1 :2 ;
			if (now == a[i]){
				if (j>=1){
					d[i][j] = max (d[i-1][j-1] +1 , d[i-1][j] +1 );
				}else {
					d[i][j] = d[i-1][j] +1 ;
				}
			}else {
				d[i][j] = d[i-1][j] ;
			}
		}
 }
 int ans =-10;
 for (int i = 0 ; i<= m ; i++){
 	if (d[n][i] > ans ){
		ans = d[n][i];
	}
 }
 printf("%d\n",ans);

}
