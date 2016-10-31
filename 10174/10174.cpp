/*
 * 10174.cpp
 *
 */
//
//  main.cpp
//  icpc
//
//  Created by 최형규 on 2016. 10. 31..
//  Copyright © 2016년 Nisroeld. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;


bool isPal (char a[] , int s,  int e  ){
    if ( s+1 ==e  ){
        if ( a[s] == a[e] || a[s]+ ('a'-'A') == a[e] || a[s] - ('a' - 'A') == a[e] ){
            return true ;
        }else{
            return false ;
        }
    }
    if ( s == e ){
        return true ;
    }
    if ( a[s] == a[e] || a[s]+ ('a'-'A') == a[e] || a[s] - ('a' - 'A') == a[e] ){
        return isPal ( a,s+1,e-1);
    }
    return false ;
}

int main() {
   freopen("input.txt", "r",stdin);
    int tc;
    cin >> tc;
    getchar();
    while (tc--){
        char str[10000] ;
        scanf("%[^\n]s",str);
        getchar();
        int size = (int)strlen(str);
        if ( isPal ( str, 0, size-1 ) ) {
            printf("Yes\n");
        }else {
            printf("No\n");
        }
    }
}
