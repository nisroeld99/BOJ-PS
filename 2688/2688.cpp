#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



unsigned long long dp[1001][11];  // [n자리수] [끝자리 숫자?]
int main(){
    int n;
    scanf("%d",&n);
    for (int i =0 ; i<=9 ; i++){
        dp[1][i]= 1;
    }
    for (int i =2; i<=1000 ; i++){
        for (int j= 0 ; j<=9 ;j++){
            for (int k = 0 ; k<=j ; ++k ){
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    
    for (int i = 0 ; i< n ; i++){
        int sc1;
        scanf("%d",&sc1);
        unsigned long long ret = 0 ;
        for (int j = 0 ; j<=9 ; j++){
            ret+=dp[sc1][j];
        }
        cout << ret<<endl;
    }
    
}
