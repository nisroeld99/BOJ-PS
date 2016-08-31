/*
 * 2056.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
int cnt[11111];
int cost[11111];
int dp[11111];
vector<int> g[11111];
int main() {

	int n ;
	cin >> n ; 
	for (int i = 1;  i<=n ; i++ ) {
		int time , num;
		scanf("%d%d",&time,&num);
		cost[i] = time ; 
		cnt[i] = num ;
		while (num--) {
			int sc;
			scanf("%d", &sc) ;
			g[sc].push_back(i); 		
		}
	}
	priority_queue<int , vector<int> , greater<int> >pq;
	for (int i =1 ; i<=n ; i++ ) {
		if (cnt[i] == 0 ) {
			pq.push(i);
			dp[i] = cost[i]; 
		}
	}
	int dab = 0 ;
	while (!pq.empty()){
		int now = pq.top() ; pq.pop();
		for (auto x : g[now] ) {
			dp[x] = max (dp[x] , dp[now] + cost[x] ) ;
			cnt[x] -- ;
			if (cnt[x] == 0) {
				pq.push(x) ; 
			}
		}
	}
	dab = -100 ; 
	for (int i = 1 ; i<=n;  i++ ){
		if (dp[i] > dab ) {
			dab=  dp[i] ; 
		} 
	}
	printf("%d\n",dab);
	
	return 0  ;
}
