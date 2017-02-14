#include <iostream>

using namespace std;



int tc;
int n;
long long d[70];
int main(){
    cin>>tc; 
    while (tc--){
       
        cin>>n;
    
        d[0]=1;
        d[1]=1;
        d[2]=2;
        d[3]=4;
        for (int i=4; i<=n ;i++){
            d[i]= d[i-1]+ d[i-2]+d[i-3]+d[i-4];
        }
        cout<<d[n]<<endl;   
    }


}
