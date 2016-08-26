/*
 * 9084.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int d[10001];
int a[21];
int main() {
    
    int tc;
    cin >> tc;
    while (tc--){
        memset (d, 0,sizeof(d));
        int n ;
        
        scanf("%d",&n);
        int disct = n;
        int cnt = 1;
        while (disct--){
            int sc;
            scanf("%d",&sc);
            a[cnt ++] =sc ;
        }
        
        int dest ;
        scanf("%d",&dest);
        
        d[0]= 1;
        for (int k =1 ; k<= n ; k++ ){
            int now_val = a[k];
            for (int j = now_val ; j<=dest ; j++) {
                d[j] += d[j - now_val] ;
            }
        }
        cout << d[dest]<<"\n";
    }
    
    
    return 0  ;
}

