/*
 * 1744.cpp
 *
 */
/*
 * 1744.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int>pos;
vector<int>neg;
int one = 0 ;
int cnt_z = 0 ;
int main() {
    
    int n;
    cin >> n;
    for (int i = 0 ; i <n ; i++ ){
        int sc;
        scanf("%d",&sc);
        if (sc== 0 )cnt_z ++ ;
        else if ( sc ==1 ) one ++ ;
        else if (sc<0 ) neg.push_back(sc);
        else if (sc>0 ) pos.push_back(sc);
        
    }
    
    sort ( neg.begin() ,neg.end() ) ;
    sort ( pos.begin() ,pos.end() ,greater<int>() ) ;
    
    int ans = one ;
    if ((int) neg.size() %2 ==0 ){
        for (int i = 0 ; i<neg.size() ; i=i+2 ){
            ans += (neg[i]*neg[i+1]);
        }
    }else {
        for (int i = 0 ;i <neg.size() ;i= i+2) {
            if (i == neg.size()-1 ) break;
            ans += (neg[i]*neg[i+1]);
        }
        if ( cnt_z >0 ){
        
        }
        else {
                ans += neg[neg.size()-1];
        }
    }
    
    if ( (int) pos.size() %2 ==0 ) {
        for (int i = 0 ; i< pos.size() ; i=i+2) {
            ans += (pos[i] * pos[i+1]) ;
        }	
        
    }else {
        for (int i = 0 ; i< pos.size() ; i=i+2) {
            if (i== pos.size()-1 ) break;
            ans += (pos[i] * pos[i+1]) ;
        }
        ans+= pos[ (int)pos.size()-1 ]; 
    }
    
    printf("%d\n",ans);
    return 0  ;
}

