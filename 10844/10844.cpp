#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
typedef long long ll;
const ll mod = 1000000000;
ll d[101][10];
int main(){
    int n;
    cin >> n; 
 
    for (int i = 1; i <= 9; i++){
        d[1][i] = 1;
    }
    for (int i = 2; i <= n; i++){
        d[i][0] = d[i - 1][1]%mod;
        d[i][1] = d[i - 1][0] % mod + d[i - 1][2] % mod;
        d[i][2] = d[i - 1][1] % mod + d[i - 1][3] % mod;
        d[i][3] = d[i - 1][2] % mod + d[i - 1][4] % mod;
        d[i][4] = d[i - 1][3] % mod + d[i - 1][5] % mod;
        d[i][5] = d[i - 1][4] % mod + d[i - 1][6] % mod;
        d[i][6] = d[i - 1][5] % mod + d[i - 1][7] % mod;
        d[i][7] = d[i - 1][6] % mod + d[i - 1][8] % mod;
        d[i][8] = d[i - 1][7] % mod + d[i - 1][9] % mod;
        d[i][9] = d[i - 1][8] % mod;
    }
    ll sum = 0;
    for (int i = 0; i < 10; i++){
        sum += d[n][i] % mod;
    }
    cout << sum%mod << endl;
     
 
 
}
