/*
 * 2252.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int cnt[32222];
vector<int> g[32222];

int main() {

	int n , m ;
	cin >> n >> m ;
	while (m--)
	{
		int from,to;
		scanf("%d%d",&from,&to) ;
		g[from].push_back(to) ; 
		cnt[to] ++ ;
	}
	priority_queue<int,vector<int>,greater<int> > pq;
	for (int i = 1 ; i<=n; i++){
		if (cnt[i] == 0){
			pq.push(i) ;
		}
	}

	while (!pq.empty()){
		int now = pq.top() ;
		pq.pop();
		printf("%d ",now);
		for (auto x : g[now] ) {
			cnt[x] -- ;
			if (cnt[x] == 0 ) {
				pq.push(x) ; 
			}
		}
		
		
	} printf("\n");


	return 0  ;
}
