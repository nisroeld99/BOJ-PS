#include <iostream>

using namespace std;


int d[50];
int n ; //n<=45
int main(){
    cin>>n;
    
    d[1]=1;
    d[2]=1;
    d[3]=2;
    
    for (int i=4;i<=n;i++){
        d[i]= d[i-1]+d[i-2];
    }

    cout<<d[n]<<endl;
}
