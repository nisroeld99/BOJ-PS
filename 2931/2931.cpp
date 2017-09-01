#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n , m;
char g[33][33];
bool inRange(int y , int x){
    if (y<0 || x< 0 || y>= n || x>= m)return false;
    return true;
}

char next[7]= {'+','1','2','3','4','-','|'};

bool Left(int y, int x){
    int ny = y;
    int nx = x-1;
    if ( !inRange(ny,nx)) return false ;
    if ( g[ny][nx] == '1' || g[ny][nx] == '2' || g[ny][nx] == '+' || g[ny][nx] == '-' || g[ny][nx]=='M' || g[ny][nx] == 'Z') return true ;
    return false;
}
bool Right(int y, int x){
    int ny = y;
    int nx = x+1;
    if ( !inRange(ny,nx)) return false ;
    if ( g[ny][nx] == '3' || g[ny][nx] == '4' || g[ny][nx] == '+' || g[ny][nx] == '-' || g[ny][nx]=='M' || g[ny][nx] == 'Z') return true ;
    return false;
}
bool Top(int y, int x){
    int ny = y-1;
    int nx = x;
    if ( !inRange(ny,nx)) return false ;
    if ( g[ny][nx] == '1' || g[ny][nx] == '4' || g[ny][nx] == '+' || g[ny][nx] == '|' || g[ny][nx]=='M' || g[ny][nx] == 'Z') return true ;
    return false;
}
bool Bottom(int y, int x){
    int ny = y+1;
    int nx = x;
    if ( !inRange(ny,nx)) return false ;
    if ( g[ny][nx] == '2' || g[ny][nx] == '3' || g[ny][nx] == '+' || g[ny][nx] == '|' || g[ny][nx]=='M' || g[ny][nx] == 'Z') return true ;
    return false;
}


int main(){
    
    scanf("%d%d",&n,&m);
    for (int i = 0 ;i<n; i++){
        cin >> g[i];
    }
    for (int i = 0 ;i<n; i++){
        for (int j=0 ;j<m; j++){
            if ( g[i][j] == '.'){
                // +
                if ( Left(i, j) && Right(i,j) && Top(i,j) && Bottom(i,j)){
                    printf("%d %d %c\n", i+1,j+1,'+');
                    return 0 ;
                }
                // -
                if ( Right(i,j) && Left(i, j) ){
                    printf("%d %d %c\n", i+1,j+1,'-');
                    return 0 ;
                }
                
                // |
                if ( Top(i,j) && Bottom(i, j) ) printf("%d %d %c\n", i+1,j+1,'|');
                // 1
                if ( Right(i,j) && Bottom(i, j) ) printf("%d %d %c\n", i+1,j+1,'1');
                // 2
                if ( Top(i,j) && Right(i, j) ) printf("%d %d %c\n", i+1,j+1,'2');
                // 3
                if ( Top(i,j) && Left(i, j) ) printf("%d %d %c\n", i+1,j+1,'3');
                // 4
                if (Left(i,j) && Bottom(i, j) ) printf("%d %d %c\n", i+1,j+1,'4');
                
            }
        }
    }
    
}
