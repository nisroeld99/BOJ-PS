/*
 * 8892.cpp
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
using namespace std;
vector<string> v;


bool isPal(string s1,int s, int e  ){
    if ( s +1 == e ){
        if  (s1[s] == s1[e]){
            return true ;
        }else {
            return false ;
        }
    }
    if ( s==e) {
        return true ;
    }
    
    if ( s1[s] == s1[e] ){
        return isPal (s1, s+1, e-1);
    }
    
    return false ;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--){
        v.clear();
        int n ;
        cin >> n;
        
        for (int i = 0 ; i<n;  i++){
            string s1;
            cin >> s1;
            v.push_back(s1);
        }
        bool ok = false ;
        for (int i =0 ; i<n;  i++){
            for (int j= 0 ;j <n; j++){
                if ( i==j)continue;
                string temp = v[i] + v[j] ;
                int size = (int)temp.size();
                if ( isPal(temp,0, size-1)  ) {
                    cout << v[i] + v[j]<<endl;
                    ok = true ;
                    break ;
                }
                
                temp = v[j] + v[i] ;
                if ( isPal(temp,0, size-1)  ) {
                    cout << v[j] + v[i]<<endl;
                    ok = true ;
                    break ;
                }
                
                
            }
            if ( ok )break ;
        }
        
        if ( !ok ) printf("0\n");
    }
    
    
    
    return 0;
}

