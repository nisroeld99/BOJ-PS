/*
 *  1987   
 */
/*
 *  10453.cpp
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char g[22][22];
bool c[55];
int dy[4]= {1,-1,0,0}, dx[4] = {0,0,-1,1};
int r,cc;
int ans = -10000;
void go ( int ypos, int xpos , int cnt ){
    ans = max ( ans, cnt );
    
    for (int i =0 ; i <4 ; i++){
        int ny = ypos + dy[i];
        int nx = xpos + dx [i];
        if ( ny < 1  || nx < 1 || ny > r || nx > cc )continue;
        if ( c[g[ny][nx] -'A' ] == false   ){
            c[g[ny][nx] - 'A']= true;
            go ( ny,nx, cnt+1  );
            c[g[ny][nx] - 'A']= false;
        }
    }
    
}

int main(){
    
    cin >> r >>cc;
    
    for (int i = 1; i <=r;  i++){
        scanf("%s", g[i]+1);
    }
    c[ g[1][1] - 'A' ] = true ;
    go ( 1 , 1 , 1);
    printf("%d\n",ans);
}
