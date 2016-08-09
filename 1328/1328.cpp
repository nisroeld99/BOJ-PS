/*
 * 1328.cpp
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii> iii ; 
const int mod = 1000000007;
long long d[101][101][101]; // [빌딩 수] [왼쪽에서본 수 ][오른쪽에서 본 수]
int main(){
	int n , l,r;
	scanf("%d%d%d", &n,&l,&r);
	d[1][1][1]= 1;
	for (int i =2; i<= n; i++ ){
		for (int j= 1; j<=l ;j++){
			for (int k = 1; k<=r ; k++){
				d[i][j][k]= d[i-1][j-1][k] + d[i-1][j][k-1] + d[i-1][j][k]*(i-2);
				d[i][j][k] %=mod;
			}
	
		}
	}
	cout <<d[n][l][r]<<endl;
	return 0 ;
}
