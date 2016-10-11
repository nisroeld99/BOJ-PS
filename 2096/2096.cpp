/*
 * 2096.cpp
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 
int n;
int arr[100001][3];
int dm[100001][3];
 
int main(){
    scanf("%d", &n);
     
    for (int i=0 ; i<n;i++){
        scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
 
    }
     
    dm[0][0]=arr[0][0];
    dm[0][1]=arr[0][1];
    dm[0][2]=arr[0][2];
 for (int i=1 ; i< n; i++){
 
        dm[i][0] = max (dm[i-1][0] , dm[i-1][1] )  +arr[i][0];
        dm[i][1] = max (max (dm[i-1][0] , dm[i-1][1] ) , dm[i-1][2]) +arr[i][1];
        dm[i][2] = max (dm[i-1][1] , dm[i-1][2] ) +arr[i][2];
     
 
    }
         cout<<max (max (dm[n-1][0] , dm[n-1][1] ) , dm[n-1][2]) <<' ' ;
     
     
    dm[0][0]=arr[0][0];
    dm[0][1]=arr[0][1];
    dm[0][2]=arr[0][2];
 
     
    for (int i=1 ; i< n; i++){
        dm[i][0] = min (dm[i-1][0] , dm[i-1][1] ) + arr[i][0];
        dm[i][1] = min (min (dm[i-1][0] , dm[i-1][1] ) , dm[i-1][2]) +arr[i][1] ;
        dm[i][2] = min (dm[i-1][1] , dm[i-1][2] ) +arr[i][2];
    }
    
    cout<< min (min (dm[n-1][0] , dm[n-1][1] ) , dm[n-1][2])<<endl;
     
}
