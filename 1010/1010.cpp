
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int d[31][31];
int main(){
    int tc;
    cin >> tc;
    
    
    for (int i = 1 ; i<=30 ;i++){
        d[i][i] = 1;
    }
    for (int i=1; i<=30; i++)
        for (int j=i+1 ;j<=30; j++){
            d[i][j]= max(d[i][j-1]*j/(j-1) , d[i-1][j]*(j-i+1)/i  ) ;
        }
    
    while (tc--){
        int n , m ;
        scanf("%d%d",&n,&m);
        printf("%d\n",d[n][m]);
    }
}
