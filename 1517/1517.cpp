/*
 * 1517.cpp
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int a[555555];

long long go (int left, int right ){
    vector<int> temp(right-left+1) ;
    if ( left == right ){
        return  0 ;
    }
    long long ans = 0 ;
    int mid = (left +right)/2;
    
    ans = go ( left ,mid ) + go (mid + 1 ,right);
    int i = left ;
    int j= mid + 1;
    int k  = 0;
    
    while  ( i<=mid && j <= right) {
        if  ( a[i]<=a[j]  ){
            temp[k++]=a[i++];
        }else {
            ans += (mid - i +1);
            temp[k++] = a[j++];
        }
        
    }
    while ( i<=mid){
        temp[k++]= a[i++];
    }
    while (j<=right){
        temp[k++] =  a[j++];
    }
    k=0 ;
    for (i = left ; i<=right;i++){
        a[i] = temp [k++];
    }
    
    return ans ;
}


int main() {
    int n ;
    scanf("%d",&n);
    for (int i = 0 ; i<n; i++){
        scanf("%d",&a[i]);
    }
    
    printf("%lld\n",go ( 0,n-1  ));
    
}
