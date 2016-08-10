/*
 * 2098.cpp
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii> iii ;
typedef long long ll;
const int inf = 987654321;
const int mod = 0 ; 
int n ; 
int g[22][22];
int d[22][(1<<15)+1];
int tsp(int now , int visit){
	if (visit == (1<<n)-1){
		if (g[now][1] != 0){
			return g[now][1];
		}
	}

	int &ret = d[now][visit];
	if (ret!= -1) return ret;
	ret = inf ;
	for (int i =2; i<=n ; i++){
		if (! (visit & 1<<(i-1)) && g[now][i]!=0 ){
				ret = min (ret , g[now][i] +tsp(i , visit | (1<< (i-1) )));
		}
	}
	return ret ; 

}




int main(){
	scanf("%d",&n);
	for (int i =0 ; i<22; i++){
		for (int j= 0 ; j< (1<<15)+1 ; j++)
		{
			d[i][j]=-1;
		}
	}
	for (int i =1 ; i<=n; i++){
		for (int j=1 ;j<=n ;j++ ){
			scanf("%d",&g[i][j]);
		}
	}
	printf("%d\n",tsp(1,1 ));
	return 0 ;
}
