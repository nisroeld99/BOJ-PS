/*
 * 6549.cpp
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;
vector<ll> h;
stack<ll> remain;
int main(){
    while (true ) {
        h.clear();
        while (!remain.empty())
            remain.pop();
        int num;
        scanf("%d",&num);
        if ( num == 0 ) break ;
        
        for (int i = 0 ; i < num ; i++){
            ll sc;
            scanf("%lld",&sc);
            h.push_back(sc);
        }
        h.push_back(0);
        ll ret = 0 ;
        for (int i = 0 ; i< num+1 ; i++){
            while ( !remain.empty()  && h[remain.top()] >= h[i] ){
                ll j = remain.top();
                remain.pop();
                
                ll width;
                if ( remain.empty()){  //끝까지 왔으면,
                    width = i;
                }
                else {
                    width = i - remain.top()-1;
                }
                
                ret = max ( (ll)ret, (ll) h[j] * width);
            }
            remain.push(i);

        }
        printf("%lld\n",ret);
    
    }
    return 0;
}

