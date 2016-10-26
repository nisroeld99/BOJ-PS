/*
 * 1254.cpp
 *
 */
/*
 * 1254.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
string str ;
string temp;
bool isPal(int s, int e){
    if ( s+1== e ){
        if (temp[s] == temp[e] )
            return true;
        else
            return false ;
    }
    if (s==e){
        return true ;
    }
    if ( temp[s] ==temp[e] ) {
        return isPal (s+1,e-1) ;
    }
    else{
        return false;
    }
}

int main() {
    cin >> str;
    int size =(int) str.size();
    str = " " + str;
    temp = str;
    
    
    int idx = 1;
    while (true ) {
        if ( isPal(1,size) ) {
            printf("%d\n" , (int)temp.size() -1) ;
            return  0 ;
        }else {
            temp=str;
            for (int i = idx; i>=1; i--){
                temp += str[i];
            }
        }
        idx ++ ;
        size ++ ;
        
    }
    
    return 0  ;
}

