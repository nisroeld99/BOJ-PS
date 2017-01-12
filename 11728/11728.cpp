/*
 * 11728.cpp
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




int main(int argc, const char * argv[]) {
    int n , m ;
    scanf("%d%d",&n,&m);
    int a [1000001];
    int b [1000001];
    for (int i = 0 ; i<n; i++){
        int sc;
        scanf("%d",&sc);
        a[i] =sc ;
    }
    for (int i = 0 ; i<m; i++){
        int sc;
        scanf("%d",&sc);
        b[i]= sc;
    }
    int ncnt =0, mcnt = 0 ;
    
    while ( ncnt != n && mcnt != m ){
        if ( a[ncnt] < b[mcnt ] ){
            printf("%d ",a[ncnt]);
            ncnt ++ ;
        }else{
            printf("%d ",b[mcnt]);
            mcnt ++ ;
        }
    }
    while (ncnt != n ){
        printf("%d ",a[ncnt]) ;
        ncnt ++ ;
    }
    while (mcnt !=m ){
        printf("%d ",b[mcnt]) ;
        mcnt ++ ;
    }
    

}

