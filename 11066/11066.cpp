/*
 * 11066.cpp
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii> iii ; 
int a[501];
int d[501][501]; //i ~j 장 합쳤을 때의 최소 비용
int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int n ;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		
		for (int i =1 ; i<=n; i++){
			scanf("%d",&a[i]);
		}
		

		for (int l = 1 ; l< n; l++){
			for (int i =1 ; i+l<=n ; i++){
				int range = i+l ;
				d[i][range]=987654321;
				for (int j= i ;j<range ;j++){
					d[i][range] = min (d[i][j] + d[j+1][range] + a[j] + a[j+1], d[i][range] );
				}
			}
		}
		printf("%d\n",d[1][n]);

		
	}

	return 0 ;
}
