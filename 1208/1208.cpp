#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll ;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
#pragma warning(disable:4996) 
ll n ,s;
ll a[21];
ll b[21];
ll asize ;
ll bsize;
vector<ll > as;
vector<ll> bs;
ll cnt = 0 ;
void go1 (ll now ,ll sum , ll zeroCnt ){
    if (now == asize ){
        as.push_back(sum);
        return ;
    }
    go1 (now+1, sum+a[now] ,zeroCnt);
    go1 (now +1 , sum ,zeroCnt+1 );
     
}
void go2 (ll now ,ll sum ,ll zeroCnt  ){
    if (now == bsize ){
        bs.push_back(sum);
        return ;
    }
    go2 (now+1, sum+b[now],zeroCnt );
    go2 (now +1 , sum  ,zeroCnt+1);
     
}
int main(){
     
    scanf("%lld%lld",&n,&s);
    asize = n/2 ;
    bsize = n-n/2;
     
    for (int i = 0 ;i<n/2; i++){
        scanf("%lld",&a[i]);
    }
    int i  = 0 ;
    for (int j= n/2 ;j<n ;j++){
        scanf("%lld",&b[i++]);
    }
     
    go1 (0,0, 0 );
    go2 (0,0,0);
     
    sort ( as.begin(),as.end());
   
    for (int i = 0 ; i< bs.size() ; i++ ) {
        if ( binary_search(as.begin(),as.end() ,s - bs[i] ) ){
            auto num1 =  upper_bound(as.begin(), as.end(), s-bs[i]);
			auto num2 =  lower_bound(as.begin(), as.end(),s-bs[i]);;
            cnt+= (num1-num2);
        }
    }
    if (s == 0)
		cout << cnt-1<< endl;
	else {
		cout << cnt << endl ; 
	}
	
     
   
}
