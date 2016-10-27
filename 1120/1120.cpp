/*
 *  1120
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    int ans = 987645123 ;
    for (int i = 0 ; i+s1.size() <s2.size()+1 ; i++){
        int cnt = 0 ;
        for (int j= 0; j<s1.size() ;j++){
            if ( s1[j] !=s2[j+i]){
                cnt ++ ;
            }
        }
        ans = min (ans , cnt ) ;
    }
    printf("%d\n", ans ) ;
}

