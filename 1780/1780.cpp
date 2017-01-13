/*
 * 1780.cpp
 *
 */
//
//  main.cpp
//  icpc
//
//  Created by 최형규 on 2017. 1. 12..
//  Copyright © 2017년 Nisroeld. All rights reserved.
//
#include <algorithm>
#include <iostream>

using namespace std;

int dab [3] ={0};
int g[ 3333] [3333 ];

bool check( int size , int ypos , int xpos );
void go ( int size , int ypos ,int xpos ) ;


int main(int argc, const char * argv[]) {
   // freopen("input.txt","r",stdin);
    
    int n ;
    scanf("%d",&n ) ;
    
    for (int i =1 ; i<=n ; i++){
        for (int j=1 ;j<=n ;j++ ){
            scanf("%d",&g[i][j]);
        }
    }
    go ( n , 1,1);
    
    printf("%d\n%d\n%d\n",dab[0],dab[1],dab[2]);
}


bool check( int size , int ypos , int xpos ){
    int now = g[ypos][xpos];
    for (int i = ypos ; i < ypos + size ; i++){
        for (int j=xpos ; j < xpos + size ; j++ ){
            if ( g[i][j] != g[ypos][xpos]){
                return false ;
            }
        }
    }
    return true ;
}
void  go( int size , int ypos ,int xpos ) {
    
    if ( check(size , ypos ,xpos ) ){
        int now = g[ypos][xpos];
        dab[now+1]++ ;
        return ;
    }
    
    go (size/3 , ypos ,xpos);
    go (size/3 , ypos + size/3 , xpos );
    go (size/3 , ypos + 2*size/3 , xpos );
    
    go (size/3 , ypos, xpos+size/3 );
    go (size/3 , ypos+size/3, xpos+size/3 );
    go (size/3 , ypos+size/3*2, xpos+size/3 );
    
    
    go (size/3 , ypos , xpos+size/3*2 );
    go (size/3 , ypos+size/3 , xpos+size/3*2 );
    go (size/3 , ypos+size/3*2 , xpos+size/3*2 );
  
    return ;
    

}

