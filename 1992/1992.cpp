/*
 *  1992   
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll ;
typedef pair<int,int> ii;

int g[66][66];


void go (int size , int ypos, int xpos );
int check (int size , int ypos, int xpos );
int main(){
    int n ;
    scanf("%d",&n);
    for (int i =1 ; i<=n ; i++){
        for(int j=1 ; j<=n ;j++){
            scanf("%1d",&g[i][j]);
        }
    }
    go (n,1,1);
    
}
void go (int size , int ypos, int xpos ){
    if ( check (size , ypos,xpos) ==0 ){
        printf("0");
    
    }
    else if (check (size ,ypos,xpos ) == 1 ){
        printf("1");
    }
    
    else {
        printf("(");
        go (size/2 , ypos , xpos );
        go (size/2 , ypos , xpos + size/2);
        go (size/2 , ypos+size/2 , xpos);
        go (size/2 , ypos +size/2 , xpos + size/2 );
        printf(")");
    }
}


int check (int size , int ypos, int xpos ){
    int one= 0 , zero= 0;
    for (int i = ypos ; i<=ypos+size-1 ;i++){
        for (int j= xpos ; j<=xpos+size-1 ;j++){
            if (g[i][j] ==1 ){
                one ++ ;
            }else {
                zero ++ ;
            }
        }
    }
    if ( one ==0 ){
        return 0;
    }
    else if (zero == 0){
        return 1 ;
    }
    else {
        return 2;
    }
}
