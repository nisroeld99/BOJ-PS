/*
 * 1162.cpp
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
vector<ii> g[10001];
int d[10001][21];
bool c[100001];

priority_queue<ii,vector<ii>,greater<ii> >pq; 
void go (int start, int pave ){
	memset(c,false ,sizeof(c));
	pq.push(ii (0,start));
	d[start][pave]= 0;
	while (!pq.empty()){
		int now =pq.top().second;
		int now_cost = pq.top().first; pq.pop();
		if ( c[now] ) continue;
		c[now] = true; 
		for (int i = 0 ; i< g[now].size () ; ++i){
			int next = g[now][i].first;
			int next_cost  = g[now][i].second ; 
			if ( pave == 0 ) {
				if (d[next][pave] >  d[now][pave] + next_cost ) {
					d[next][pave] = d[now][pave]  + next_cost ; 
					pq.push(ii(d[next][pave], next  ));
				}
			}
			else if (d[next][pave]  > min (d[now][pave] + next_cost , d[now][pave-1] ) 
) { 
				d[next][pave] =min(d[now][pave] +next_cost,d[now][pave-1]) ;
				pq. push(ii(d[next][pave], next));
			}
		}
	}
}
int main(){
	int n,m , k ;
	cin >> n >> m >> k ;
	for (int i =1 ; i<=m ; i++){
		int from,to ,cost;
		scanf("%d%d%d",&from,&to,&cost);
		g[from].push_back(ii(to,cost));
		g[to].push_back(ii(from,cost));
	}
	for (int i = 0 ; i <=n ; i++ ) 
		for (int j= 0 ;j <= k ; j++ ) 
			d[i][j] = inf ; 

	for (int i = 0 ; i<= k ;++i) {
		go (1, i ); 
	}
	
	printf("%d\n", d[n][k]);

	return 0 ;
}
