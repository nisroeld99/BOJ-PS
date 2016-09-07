/*
 * 11376.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
struct netflow {
	int n ;
	bool c[1111];
	int par[ 1111];
	vector <int> g[1111]; 
	netflow (int n ) : n(n ) {
		memset(c,false, sizeof(c) );
		memset(par , -1 , sizeof( par ) );
	} 
	void add_edge (int u , int v ){
		g[u].push_back(v) ;	
	}
	
	bool dfs (int x ){
		if (x ==-1 ) return true ; //hole 로 빠짐
		for (int next : g[x] ) {
			if (c[next] ) continue;
			c[next]= true ;
			if (dfs (par[next ] ) ){
				par[next] = x ;
				return true ;
			}

		}
		return false ; 
	}
	int flow () {
		int ret = 0 ;
		for (int j=1 ;j<=2 ;j++ ){
			for (int i =1 ; i<= n; i++ ) {
				memset(c,false ,sizeof(c)) ;
				if (dfs(i)) 
					ret ++ ;
			}
		}
		return ret ; 
	}
};
int main() {

	int n , m  ; // n 직원  m  일의 수 
	cin >> n >> m ; 
	netflow nf(n) ; 
	for (int i = 1;  i<= n ; i++  )  {
		int cnt ;
		scanf("%d",&cnt ) ;
		while (cnt -- ) {
			int sc ;
			scanf("%d",&sc) ; 
			nf.add_edge(i,sc);
		}
	}
	cout<< nf.flow() <<endl;



	return 0  ;
}
