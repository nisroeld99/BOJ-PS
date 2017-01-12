/*
 * 10815.cpp
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
    int n;
    scanf("%d",&n);
    int a[555555];
    for (int i = 0 ; i<n; i++){
        scanf("%d",&a[i]);
    }
    sort ( a, a+n);
    int m ;
    scanf("%d",&m);
    for (int i = 0 ;i<m;i++){
        int sc;
        scanf("%d",&sc);
        int left = 0 , right = n -1 ;
        bool breakPoint = false ;
        while ( left <= right ){
            if  (breakPoint ) break ;
            
            int mid = (left + right)/2;
            if (a[mid] == sc ){ //찾으면
                printf("%d ",1);
                breakPoint = true ;
            } else if ( a[mid] < sc){ //타겟보다 작으면
                left = mid +1 ;
            }else if ( a[mid] > sc){ //타겟보다 크면
                right = mid - 1 ;
            }
            
        }
        if (!breakPoint) printf("0 ");
    }
}

