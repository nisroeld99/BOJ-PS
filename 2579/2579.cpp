/*
 * 2579.cpp
 *
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll ;
const int inf = 987654321;
int a[333];
int d[333];
int main(){
    int n ;
    scanf("%d",&n);
    for (int i =1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    d[1] = a[1];
    d[2] = a[2] +a[1];
    for (int i = 3;  i<=n;  i++){
        d[i] =  max ( d[i-3] +a[i-1] , d[i-2] )  + a[i];
     }
    cout << d[n]<<endl;
    
}
