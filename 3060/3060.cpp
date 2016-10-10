/*
 * 3060.cpp
 *
 */
#include <iostream>

#include <cstring>
using namespace std;
const int mod  = 6;
int tc;
int a[6];
int d[22][6];
int main(){
    scanf("%d",&tc);
    
    while (tc--){
        memset(d,0,sizeof(d));
        int n ;
        scanf("%d",&n);
        int ans = 0 ;
        for (int i = 0; i<6 ;i++){
            scanf("%d",&d[1][i]);
            ans+= d[1][i];
        }
        if (ans > n) {
            printf("1\n");
            continue;
        }
        
    
        for (int i =2; ;i++){
            ans = 0 ;
            for (int j= 0; j<6 ;j++){
                d[i][j] = d[i-1][(j+6-1)%mod] + d[i-1][(j+6+1) %mod ] + d[i-1][(j+3)%mod] +d[i-1][j];
                ans += d[i][j];
            }
            if (ans  > n ){
                printf("%d\n",i);
                break;
            }
        }
        
        
    }
}

