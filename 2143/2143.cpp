/*
 * 2143.cpp
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef unsigned long long ull;

vector<ull> a;
vector<ull> b ;
int inputA[1001];
int inputB[1001];
int main(){
    
    freopen("input.txt", "r", stdin);
    ull t;
    scanf("%llu" , &t);
    int n ;
    cin >> n ;
    
    for (int i = 0 ; i<n; i++){
        scanf("%d",&inputA[i]);
    }
    for (int i = 0;  i<n ; i++){
        ull sum = 0 ;
        for (int j= 0 ;i+j<n;j++){
            sum+= inputA[i+j];
            a.push_back(sum);
        }
    }
    int m;
    cin >> m ;
    for (int i = 0 ; i<m ; i++){
        scanf("%d",&inputB[i]);
    }
    for (int i = 0;  i<m ; i++){
        ull sum = 0 ;
        for (int j= 0 ;i+j<m;j++){
            sum+= inputB[i+j];
            b.push_back( sum );
        }
    }
    ull dab = 0 ;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for (int i = 0 ; i< a.size(); i++){
        
        int temp =(upper_bound(b.begin(),b.end(), t-a[i]) -lower_bound(b.begin(), b.end(), t- a[i]) );
        dab += temp ;
        
    }
    
    cout << dab<< endl;
    
}
