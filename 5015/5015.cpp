/*
 * 5015.cpp
 *
 */
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

int d[101][101]; // wild i 번째 char,
string wild;
string str;
bool go (int w, int s ){
    
    int &ret = d[w][s];
    if ( ret !=-1 )return ret;
    
    if ( w < wild.length() && s< str.size() && wild[w]==str[s] ){
        return ret = go (w+1 ,s+1 );
    }
    
    if ( w == wild.size() )
        return ret = (s == str.size());
    
    if ( wild[w] == '*'){
        if ( go (w+1,s) || (s < str.size() && go (w,s+1)) ){
            return ret = 1 ;
        }
    }
    
    return 0 ;
    
}
int main(){
    
    cin >> wild;
    vector<string>ans;
    int n;
    scanf("%d",&n);
    for (int i= 0  ; i<n;i++){
        memset ( d, -1,sizeof(d));
        cin >> str;
        if ( go (0,0)){
            ans .push_back(str);
        }
        
    }
    
    for (auto x : ans) {
        cout << x <<endl ;
    }
}
