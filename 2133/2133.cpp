/*
	1차원 dp식으로도 풀 수 있습니다

*/

#include <iostream>

using namespace std;

int n;

int d[100]={0};

int main(){
    cin >> n;
    
    d[0]=1;
    d[1]=0;
    d[2]=3;
    
    
    for (int i=4 ; i<=n ; i++){
        if (i%2!=0)continue; //홀수면 패스
        d[i]= d[i-2]*3;
        for(int j=4;j<=i;j+=2){
            d[i]+=2*d[i-j];
        }
    }
    
    cout<<d[n]<<endl;
}
