/*
 * 4963.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
int g[55][55]; 
bool c[55][55]; 
int w,h; 
int dy [8] = {0,0,-1,1 , -1,1, -1 ,1 };
int dx[8]  ={1,-1, 0,0 , -1,1,  1,-1 };
void go (int ypos, int xpos ){
	g[ypos][xpos ]= 0 ;
	for(int i= 0 ; i<8 ; i++ ){
		int ny = ypos + dy[i] ;
		int nx = xpos + dx[i] ; 
		if (ny <1 || nx <1 || ny > h || nx > w ) continue ;
		if ( g[ny][nx] == 0 ) continue ; 
		go (ny,nx) ;
	} 
}
int main() {

	while (true ) {
		memset (g,0 , sizeof(g) ) ;
		cin >> w >> h ; // w : x 축 h : y축
		if (w== 0 && h==0 ) break; 
		for (int i =1 ; i<=h ; i++ )
			for (int j=1 ;j<=w ; j++ ) {
		 		scanf("%d", &g[i][j] ) ;
			}
		int dab = 0 ;
		for (int i =1 ; i<= h ; i++ ){
			for (int j=1 ;j<=w ; j++ ) {
				if (g[i][j]  == 1 ) {
					dab ++ ; 
					go (i,j);
				}
			}
		}
		printf("%d\n" ,dab ) ; 
	}


	return 0  ;
}
