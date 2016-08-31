/*
 * 1516.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int timee[555];
int cnt [555] ;
vector <int> g[555];
int dp[555];
int main() {
	int n ;
	scanf("%d" ,&n ) ;
	for (int i =1 ; i<=n ;i++ ){
		int sc1 ; 
		scanf("%d",&sc1);
		timee [i] =sc1;
		while (true ) {
			int sc2 ;
			scanf("%d", &sc2 ) ;
			if (sc2 == -1 ) break;
			g[sc2].push_back(i) ;
			cnt[i] ++ ;
		}
	}
	priority_queue<int ,vector<int>,greater<int> >pq;
	for (int i =1 ; i<=n; i++ ) {
		if (cnt[i] == 0 ) {
			pq.push(i) ;
			dp[i] = timee[i];
		}
	}
	
	while (!pq.empty()) {
		int now = pq.top() ; pq.pop();
		for (auto x : g[now] ) 
		{
			dp[x] = max (dp[x], dp[now] + timee[x] ) ;
			cnt[x] -- ;	
			if (cnt[x] == 0 )
				pq.push(x) ; 
		}
	}
	for (int i =1 ; i<=n; i++ ) 
		
	{
		printf("%d\n", dp[i] ) ;
	}
	return 0  ;
}
