/*
 * 1012.cpp
 */


nclude <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long  ll;
const int inf =987654321;
int dy[4]= {0,0,-1,1};
int dx[4]= {1,-1,0,0};
int g[55][55];
int m, n ,k ;
void go (int ypos,int xpos ) {
    g[ypos][xpos] = 0 ;
    for (int i=0;i<4; i++){
        int ny= ypos + dy[i];
        int nx= xpos+dx[i];
        if (ny< 0 || nx< 0 || ny>= n || nx >=m )continue;
        if(g[ny][nx]) go(ny,nx);
        else continue;
    }
    
}
int main() {
    
    int tc;
    cin>> tc;
    
    
    while (tc-- ){
        memset (g ,0,sizeof(g));
        
        scanf("%d%d%d",&m,&n,&k);
        for (int i=0 ; i<k ; i++){
            int a,b;
            scanf("%d%d",&a,&b); // x,y축
            g[b][a] = 1 ;
        }
        int cnt = 0 ;
        for (int i = 0 ; i<n ; i++)
            for (int j=0 ;j<m; j++){
                if (g[i][j]){
                    cnt ++ ;
                    go(i,j);
                }
            }
        printf("%d\n",cnt);
    }
    
}

