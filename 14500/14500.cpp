//
//  main.cpp
//  ICPC
//
//  Created by 최형규 on 2017. 5. 9..
//  Copyright © 2017년 Nisroeld. All rights reserved.
//

#include <iostream>

using namespace std;
int n , m ;
bool inRange(int y,int x){
    if ( y<1 || x < 1 || y> n || x > m ) return false;
    return true ;
}

int ddy[4][4]= {{0,0,0,1},{0,0,0,-1} , {0,1,2,1},{0,1,2,1}} , ddx[4][4] ={{0,1,2,1},{0,1,2,1},{0,0,0,1},{0,0,0,-1}  };

int g[555][555];
bool visited[555][555];
int ans = -1 ;
int dy[4]= {0,0,-1,1}, dx[4]= {1,-1,0,0};
void go ( int ypos, int xpos , int cnt, int sum){
    if ( cnt == 3 ){
        ans = max ( ans , sum );
        return ;
    }
    
    for (int i = 0 ; i<4; i++){
        int ny = dy[i] + ypos ;
        int nx = dx[i] + xpos ;
        if ( !inRange( ny,nx)) continue;
        if ( visited[ny][nx] )continue;
        
        visited[ny][nx] = true ;
        go ( ny,nx, cnt+1, sum+g[ny][nx]);
        visited[ny][nx] = false ;
    }
    
}

void check_etc(int y,int x ){
    for (int k = 0 ; k<4 ; k++){
        int sum = 0 ;
        for (int l= 0 ;l<4 ;l++){
            int ny = y + ddy[k][l];
            int nx = x + ddx[k][l];
            if ( !inRange(ny, nx)) break;
            sum+= g[ny][nx];
        }
        ans = max ( ans , sum);
    }
    
}

int main(int argc, const char * argv[]) {
    
    cin >> n >> m ;
    for (int  i= 1; i<=n; i++){
        for (int j=1 ;j<=m;j++){
            scanf("%d",&g[i][j]);
        }
    }
    
    for (int i =1;  i<=n; i++){
        for (int j=1; j<=m ;j++){
            visited[i][j] = true;
            go (i,j,0,g[i][j]);
            visited[i][j] = false;
            check_etc(i, j);
        }
    }
    
    cout << ans << endl ;
}

