//
//  main.cpp
//  ICPC
//
//  Created by 최형규 on 2017. 5. 9..
//  Copyright © 2017년 Nisroeld. All rights reserved.
//

#include <iostream>

using namespace std;
int n ;
int a[21];
int b[21] ;
int d[21];
int main(int argc, const char * argv[]) {
    
    cin >> n;
    for (int i =1 ; i<=n; i++){
        cin >> a[i] >> b[i];
    }
    
    if ( a[1] <= n)
        d[1] = b[1];
    else
        d[1] = 0;
    
    for (int i =2 ; i<=n; i++){
        d[i] = 0;
        if ( a[i]+i-1 > n  )continue;
        d[i] = b[i];
        for (int j=1; j<=i-1; j++){
            if ( a[j] + j -1 < i    ){
                d[i] = max (d[j] + b[i] , d[i]) ;
            }
        }
    }
    int ans = -10;
    for (int i =1; i<=n; i++){
        ans = max ( ans , d[i]);
    }
    cout << ans <<endl;
}

