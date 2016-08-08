/*
 * 2616.cpp
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii> iii ;
int dp[4][50001];
int a[50001];
int main(){
    int n ;
    scanf("%d",&n);
    for (int i =1 ; i<=n; i++){
        scanf("%d",&a[i]);
        a[i]+= a[i-1];
    }
    int num;
    scanf("%d",&num);
    for (int k =1 ; k<=3; k++){
        for (int j = k * num; j <= n; j++){
            dp[k][j] = (a[j] - a[j - num]) + dp[k - 1][j - num];
            dp[k][j] = max(dp[k][j], dp[k][j - 1]);
        }
    }
    printf("%d\n",dp[3][n]);
    
    return 0 ;
}

