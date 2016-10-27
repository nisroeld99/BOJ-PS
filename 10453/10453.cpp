/*
 * 10453.cpp
 *
 */

/*
 *  10453.cpp
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    
    while (tc--){
        string s1,s2;
        cin >> s1 >> s2;
        vector<int>v1,v2;
        for (int i = 0 ; i <s1.size(); i++)
            if ( s1[i] == 'a')
                v1.push_back(i);
            
        
        for (int i = 0 ;i<s2.size(); i++)
            if ( s2[i] == 'a')
                v2.push_back(i);
        
        int ans = 0 ;
        for (int i = 0 ; i<v1.size(); i++)
            ans += abs(v1[i] - v2[i] ) ;
        
        printf("%d\n", ans );
    }
}

