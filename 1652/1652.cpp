/*
 * 1652.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int a[111][111];
int b[111][111];
int main() {
    
    int n ;
    scanf("%d",&n) ;
    getchar();
    for (int i =1 ; i<=n ; i++ ){
        for (int j=1 ; j<=n; j++ ){
            char input ;
            scanf("%c",&input) ;
            if (input == '.') {
                a[i][j] = 0 ;
                b[i][j] = 0;
            }else {
                a[i][j] = 1;
                b[i][j] = 1 ;
                
            }
        }
        getchar();
    }
    
    int ans_1 = 0 ;
    int ans_2 = 0  ;
    for (int i =1 ; i<=n ; i++ ){
        for (int j=1 ;j<=n ;j++ ){
            if (a[i][j] == 0 && ( i!=n ) ) {
                if ( a[i+1][j] == 0 ) {
                    ans_1 ++ ;
                    a[i][j] =1 ;
                    a[i+1][j] = 1 ;
                    int now = i+2 ;
                    while ( a[now][j] == 0 && now<=n ) {
                        a[now][j] = 1;
                        now ++ ;
                    }
                    
                }
            }
            
        }
    }
    
    for (int i =1 ; i<=n ; i++ ){
        for (int j=1 ;j<=n ;j++ ){
            if (b[i][j] == 0&& ( j!=n ) ) {
                if ( b[i][1+j] == 0 ) {
                    ans_2++ ;
                    b[i][j+1] = 1 ;
                    b[i][j] = 1;
                    int now = j+2 ; 
                    while ( b[i][now] == 0 && now<=n  ) {
                        b[i][now] = 1;
                        now ++ ; 
                    }
                    
                }		
            }
            
        }
        
    }
    
    
    
        
        
    printf("%d %d\n",ans_2, ans_1) ;
    return 0  ;
}

