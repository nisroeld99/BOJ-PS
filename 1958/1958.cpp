/*
 * 1958.cpp
 *
 */
/*
 * 1958.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int d[111][111][111];
int main() {
    
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3 ;
    int s1size = (int) s1.size() ;
    int s2size = (int) s2.size() ;
    int s3size = (int) s3.size() ;
    s1 = " " + s1 ;
    s2 = " " + s2 ;
    s3 = " " + s3 ;
    
    
    for (int i =1 ; i<=s1size; i++ ){
        for (int j=1 ;j<=s2size; j++){
            for (int k =1 ; k<=s3size ; k++){
                if  ( s1[i] == s2[j] && s2[j]==s3[k]  ){
                    d[i][j][k] = d[i-1][j-1][k-1] +1 ;
                }else {
                    d[i][j][k] = max ({ d[i-1][j][k] , d[i][j-1][k] ,d[i][j][k-1] });
                }
            }
        }
        
    }
    printf("%d\n",d[s1size][s2size][s3size] ) ;

    
    
    return 0  ;
}


