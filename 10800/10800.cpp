/*
 * 10800.cpp
 *
 */
 
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
typedef pair<int,int> ii ;
vector<ii> arr[2001];
int main() {
 
    int n ;
    scanf("%d",&n);
    for (int i =1 ; i<=n ; i++ ) {
        int a,b;
        scanf("%d%d",&a,&b) ;
        arr[b].push_back(ii(a,i));
    }
    vector<int> c (n+1,0);
    vector<int> dab (n+1, 0);
     
    long long sum = 0 ; 
    for (int i= 2; i<= 2000 ; i++ ) {
        sum+= arr[i-1].size() * (i-1) ; 
        for (int j=0 ; j< arr[i-1].size() ;j++ ){
            c[arr[i-1][j].first ] += i-1;  
        }
        for (int j=0 ; j< arr[i].size() ;j++ ) {
            dab[arr[i][j].second] = sum - c[arr[i][j].first ];  
        }
         
    }
    for (int i = 1; i<=n;  i++ ) 
        printf("%d\n",dab[i] ) ;
 
    return 0  ;
}
