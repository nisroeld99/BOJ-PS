/*
 *  1051   
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int g[51][51];
int main(){ 
	int n , m ;
	scanf("%d%d",&n,&m);
	for (int i =1;  i<=n; i++){
		for (int j=1 ;j<=m ;j++){
			scanf("%1d",&g[i][j]);
		}
	}
	int dab = 0;
	int now = 0;
	for (int i =1 ; i<=n ; i++){
		for (int j=1 ;j <= m ;j++){
			now = g[i][j];
			for (int k=1 ; k+i <= n && k+j <=m ; k++){
				if (now == g[i+k][j] && g[i][j+k]== now && g[i+k][j+k] == now){
					dab= max(dab,k);
				}
			}
		}
	}
	cout << (dab+1)* (dab+1) <<endl;
	return 0;

}
