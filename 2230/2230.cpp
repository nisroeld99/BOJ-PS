/*
 * 2230.cpp
 *
 */


#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
using namespace std;
typedef pair<int,int> ii;

int main(){
    int n,m;
    cin >> n>> m;
    vector<int>v;
    for (int i = 0 ;i<n; i++){
        int sc1;
        scanf("%d",&sc1);
        v.push_back(sc1);
    }
    sort(v.begin(),v.end());
    
    int minn = 2000000001;
    
    for (int i = 0; i<n; i++){
        auto it = lower_bound(v.begin()+i,v.end(), m+v[i] );
        if (it==v.end())continue;
        minn = min ( minn, *it-v[i] );
    }
    cout << minn<<endl;
    
}
