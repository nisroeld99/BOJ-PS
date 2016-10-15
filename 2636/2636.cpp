/*
 * 2636.cpp
 *
 */
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef  pair<int,int> ii;
int n , m ;
bool g[111][111];
bool temp[111][111];
int dy[4] = {1,-1,0,0} , dx[4] ={0,0,1,-1};
bool c[111][111] ;
vector<ii> v;
int cnt = 0 ;
void go (int y ,int x){
    
    if (c[y][x])return ;
    c[y][x] = true;
    
    if ( g[y][x] == true ){
        v.push_back(ii(y,x));
        cnt ++ ;
        return ;
    }
    
    for (int i = 0 ; i<4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 1 || nx < 1 || ny> n || nx >m )continue;
        go (ny,nx);
    }
    

}

int main(int argc, char** argv) {
    
 //   freopen("input.txt", "r", stdin);
    scanf("%d%d",&n,&m);
    for (int i = 1;  i<=n ; i++){
        for (int j= 1 ;j<=m ;j ++){
            int sc;
            scanf("%d", &sc);
            g[i][j] =temp[i][j] =sc ;
        }
    }
    int dab = 0 ;
    while (true ){
        cnt = 0 ;
        memset (c,false, sizeof(c));
        go(1,1);
        
        while (!v.empty() ){
            ii tempp = v.back(); v.pop_back();
            int y = tempp.first;
            int x = tempp.second;
            temp[y][x] = 0 ;
        }
        
        bool one = false ;
        for (int i =1 ; i<=n ; i++){
            for (int j=1 ;j<=m ;j++){
                g[i][j] = temp [i][j] ;
                if ( temp[i][j] ) one = true ;
            }
        }
        dab ++ ;
        if (!one) {//다 녹을떄
            printf("%d\n",dab);
            printf("%d\n",cnt);
            break ;
        }
        
    }
    
}
