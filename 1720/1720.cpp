#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii ;
int n;
long long dp1[31];
long long dp2[31];
int main(){
    scanf("%d",&n);
    dp1[1]=1;
    dp1[2]=3;
    for (int i=3 ; i<=30;i++){
        dp1[i] = dp1[i-1] + dp1[i-2] * 2 ;
    }
    dp2[1]=1;
    dp2[2]=3;
    for (int i=3; i<=30; i++) {
        long long b = 0;
        if (i%2 == 1) b = dp1[(i-1)/2];
        else b = dp1[i/2] + 2*dp1[(i-2)/2];
        dp2[i] = (dp1[i]+b)/2;
    }
    printf("%lld\n",dp2[n]);
     
     
     
}

