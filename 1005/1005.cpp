/*
 * 1005.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
int timee[1001];
int dp[1001];
int cnt[1001];
vector<int>g[1001];
int main() {
	int tc;
	cin >>tc;
	while (tc--) {
		memset(timee,0, sizeof(timee) ) ;
		memset (dp ,0 , sizeof(dp)) ;
		memset(cnt,0, sizeof(cnt) ) ;
		for (int i =0 ; i<1001; i++ ){
			g[i].clear() ;
		}
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i =1 ; i<=n; i++ ) {
			scanf("%d",&timee[i] );
		}
		while (m--){
			int x,y;
			scanf("%d%d",&x,&y) ;
			g[x].push_back(y);
			cnt[y] ++ ;
		}
		int dest ;
		cin >> dest ;
		queue<int>q;
		for (int i = 1; i<=n ; i++ ){
			if (cnt[i] ==0 ){
				q.push(i);
				dp[i] = timee[i];
			}
		}
		while (!q.empty()){
			int now = q.front() ; q.pop() ;
			for (auto x :g[now] ) {
				dp [x]  = max (dp[x] , dp[now] +timee[x] ) ;
				cnt[ x] --;
				if (cnt[x] == 0){
					q.push(x) ;
				}
			}
		}

		cout << dp[dest]<< "\n";
	}

	


	return 0  ;
}
