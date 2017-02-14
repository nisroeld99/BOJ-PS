#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[10001];
int v[10001];


int main(){
    cin>>n;
    
    for (int i=1 ; i<=n; i++){
        cin>>v[i];
    }
    d[1]=v[1];
    d[2]=v[1]+v[2];
    d[3]=max(max(v[1]+v[3] , v[2]+v[3]),  v[1]+v[2]);
    
    for (int i=4 ; i<=n; i++){
        d[i]= max ( (max(d[i-2], d[i-3]+v[i-1])+v[i]) , ( max(d[i-2] ,d[i-1])  ) );
    }
    
    cout<<d[n]<<endl;
    
}
