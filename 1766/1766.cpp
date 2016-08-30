/*
 * 1766.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
priority_queue<int ,vector<int >, greater<int > > q; 
vector <int > g[40000];
int cnt[40001];

int main() {
	int n , m ;
	scanf("%d%d",&n,&m);
	int start = 50000 ;
	while (m--){
		int from,to;
		scanf("%d%d",&from,&to) ;
		g[from].push_back(to);
		cnt[to] ++ ;
	}
	for (int i =1 ; i<=n; i++) {
		if (cnt[i] == 0 ){
			q.push(i)  ;
		}
	}

	while (!q.empty()){
		int now = q.top() ;
		q.pop() ; 
		printf("%d ",now);
		for (int i = 0 ; i<g[now].size () ; i++ ){
			cnt[g[now][i]] -- ;
			if (cnt [g[now][i] ] ==0 ){
				q.push(g[now][i]) ;
			}
		}
	}
 	
	

	return 0  ;
}
