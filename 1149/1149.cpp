/*
 * 1149.cpp
 *
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll ;
const int inf = 987654321;
int a[1111];
int b[1111];
int c[1111];
int d [1111][3];
int main(){
    int n ;
    cin >> n ;
    for (int i =1 ; i<=n ; i++){
        scanf("%d",&a[i]); scanf("%d",&b[i]);scanf("%d",&c[i]);
    }
    d[1][0] =  a[1];
    d[1][1] =b[1];
    d[1][2] = c[1];
    for (int i = 2;  i<=n;  i++){
        d[i][0] = min (d[i-1][1] , d[i-1][2]) +a[i] ;
        d[i][1] = min (d[i-1][0],d[i-1][2] )  +b[i] ;
        d[i][2] = min (d[i-1][1], d[i-1][0])  +c[i] ;
    }
    cout << min({d[n][0],d[n][1],d[n][2] } )<<endl;
    
}
