/*
 * 1158.cpp
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main(){
    
    int n , m;
    scanf("%d%d",&n,&m);
    vector<int> v;
    for (int i = 1 ; i<=n;i++){
        v.push_back(i);
    }
    printf("<");
    
    int kill = -1 ;
    for (int i = 0 ; i<n; i++){
        kill = (kill + m) % ((v.size()));
        printf("%d",v[kill]);
        v.erase(  v.begin() + (kill--) )  ;
        if ( v.size() == 0) break;
        printf(", ");
    }
    printf(">");
    
    
}
