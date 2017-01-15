/*
 *  2108   
 */
/*
 *  2108
 */
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#define Round(Number,count) (floor((Number) * pow(10,count) + 0.5) / pow(10,count))
using namespace std;
int a[555555];
map<int,int> mp ;

int main(){
    int n ;
    scanf("%d",&n);
    double sum = 0 ;
    for (int i = 0 ; i < n ; i++){
        scanf("%d",&a[i]	) ;
        mp[a[i]]++;
        sum+= a[i] ;
    }
    sort( a,a+n ) ;
    int ans = -1 ;
    vector<int> temp ;
    for ( auto x : mp){
        if (ans < x.second){
            if ( !temp.empty() ){
                temp.clear();
            }
            ans = x.second;
            temp.push_back(x.first);
        }else if (ans == x.second) {
            temp.push_back(x.first);
        }
    }
    int ret = 0 ;
    if  ( temp.size() == 1){
        ret = temp[0];
    }else {
        sort(temp.begin(), temp.end());
        ret= temp[1];
    }
    printf("%d\n%d\n%d\n%d\n", (int)Round(sum/n,0) , a[n/2] , ret , a[n-1]- a[0] );
    
}

