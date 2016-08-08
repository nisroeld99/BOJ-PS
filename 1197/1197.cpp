/*
 * 1197.cpp
 * Copyright (C) 2016 helloworld <helloworld@choehyeong-gyuui-MacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> ii ;
typedef pair<int,ii> iii ;
int par[10001];
void init(){
	for (int i = 0 ; i < 10000;i++){
		par[i]=i;
	}
}
int find(int n ){
	if ( par[n]==n) return n;
	return par[n]= find(par[n]);
}

void _union(int a, int b){
	a= find(a);
	b= find(b);
	if (a==b) return ; 
	par[a]= b;
}

int main(){
	init();
	int n ,m;
	scanf("%d%d",&n,&m);
	vector<iii> edge;
	for (int i = 0 ; i < m; i++){
		int from,to,cost;
		scanf("%d%d%d",&from,&to,&cost);
		edge.push_back(iii(cost,ii(from,to)));
	}
	sort(edge.begin() , edge.end() ) ;
	int sum = 0 ;
	for (auto x : edge){
		int cost = x.first;
		int from = x.second.first;
		int to = x.second.second;
		if (find(from) == find(to)) {
			continue;
		}else{
			sum+=cost;
			_union(from,to);
		}
	}
	printf("%d\n",sum);
	return 0 ;
}
