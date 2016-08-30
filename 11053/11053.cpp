
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int d[1001];
int main(){
    int n ;
    cin >> n;
    int cnt = 1;
    cin >> d[1] ;
    
    for (int i =2;  i<=n; i++){
        int sc;
        scanf("%d",&sc);
        if (d[cnt ] < sc) {
            cnt++;
            d[cnt] = sc;
        }
        
        else {
            auto it = lower_bound(d+1, d+cnt+1, sc);
            *it = sc ;
        }
    }
    cout << cnt << endl;
}
