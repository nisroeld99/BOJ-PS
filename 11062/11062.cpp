/*
 * 11062.cpp
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll ;
int tc;
ll d[1001][1001][2];
int arr[1001];
ll solve(int i,int j,bool tAlice)
{
    if(i == j && tAlice)
        return arr[i];
    else if(i == j && !tAlice)
        return 0;
     
    ll &ret = d[i][j][tAlice];
     
    if(ret != -1)
        return ret;
     
    if(tAlice)
        ret = max(solve(i+1,j,!tAlice) + arr[i],solve(i,j-1,!tAlice) + arr[j]);
    else
        ret = min(solve(i+1,j,!tAlice),solve(i,j-1,!tAlice));
    return ret;
}
int main () {
    cin >> tc;
    while (tc--) {
        int n ;
        scanf("%d",&n);
        memset (arr, 0,sizeof (arr));
        memset (d,-1 ,sizeof (d) );
        for (int i =0 ; i<n; i++ ){
            cin >> arr[i];
        }
        cout << solve(0,n-1,true )<<endl;
    }
} 
