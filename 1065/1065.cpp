nclude <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
 
bool c[1001];
 
void check(){
    for (int i=1 ; i<100 ;i++){
        c[i]= true;
    }
     
    for (int i =101 ; i<= 999 ; i++){
        int temp ; int temp2;
        int now=i;
  
        temp = (now%10);
        now/=10;
        temp2 = now%10;
        now/=10;
        int dif = temp-temp2;
         
        if ( temp2-now == dif )c[i]=true;
         
    }
}
int main(){
    memset(c,false,sizeof(c));
    check();
    int n ;
     
    cin >> n;
    int cnt = 0 ;
    for (int i =1 ; i<=n; i++){
        if (c[i]) cnt ++;
    }
    cout << cnt << endl;
}
