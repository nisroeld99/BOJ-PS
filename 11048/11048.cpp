/*
 * 11048.cpp
 * Copyright (C) 2016 helloworld <helloworld@choehyeong-gyuui-MacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int g[1001][1001];
int d[1001][1001];
int n , m ;
int dy[3]={-1,0,-1};
int dx[3]={-1,-1,0};
int go(int ypos,int xpos){
	if (ypos==1 && xpos==1 ) return g[1][1];
	if (ypos < 1 || xpos <1 || ypos >n || xpos > m) return 0;
	int & ret=  d[ypos][xpos] ;
	if (ret != -1) return ret;
	ret= 0 ;
	for (int i = 0 ; i<3; i++){
		int ny = ypos + dy[i] ;
		int nx = xpos + dx[i] ;
		ret = max ( ret, g[ypos][xpos] + go(ny,nx)) ;
	}
	return ret; 
}
				

int main(){
	memset(d,-1,sizeof(d));
	cin >> n >> m;
	for (int i =1; i<=n; i++){
		for (int j=1; j<=m;j++){
			scanf("%d",&g[i][j]);
		}
	}
	printf("%d\n",go(n,m));
	return 0 ;
}
