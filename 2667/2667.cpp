/*
 * 2667.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
int g[33][33];
vector<int > dab ; 
int temp = 0 ;
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};

int n ;
void go (int ypos, int xpos ){
	temp ++ ;
	g[ypos][xpos ] = 0;
	for (int i = 0 ; i<4 ; i++ ) {
		int ny = ypos + dy[i] ;
		int nx = xpos + dx[i] ;
		if (ny <1 || nx < 1 || ny > n || nx > n)  continue; 
		if (g [ny][nx] == 0 ) continue ;
		go (ny,nx ) ;
	}
} 

int main() {


	scanf("%d",&n);
	for (int i =1 ; i<=n ; i++ ) 
		for (int j=1 ;j<=n ;j++ ){
			scanf("%1d" ,&g[i][j] ) ;
		}
	for (int i =1 ; i<=n ; i++ ) 
		for (int j=1 ;j<=n ;j++ ){
			if ( g[i][j]  ==1 ) 
			{
				temp = 0 ;
				go(i,j) ; 		
				dab.push_back (temp ) ;
			}
		}
	sort ( dab.begin() , dab.end() ) ;
	printf("%d\n", dab.size() ) ;
	for (auto x : dab) {
		printf("%d\n",x) ;
	}
	return 0  ;
}
