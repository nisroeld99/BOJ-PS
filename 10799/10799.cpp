/*
 * 10799.cpp
 *
 */
#include <stack>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
   // freopen("input.txt", "r" , stdin);
    string s1;
    cin >> s1 ;
    stack <char> st;
    bool check = true ;
    int ans = 0 ;
    for (int i = 0;  i< s1.size() ; i++ ) {
        if ( s1[i] == '('){
            st.push('(');
            check= true;
        }
        else { // ')' 일때
            if ( check == true ){ // 레이저 판별
                st.pop();
                ans += st.size();
                check = false ;
            }else {
                st.pop() ;
                ans ++ ;
                check = false;
            }
        }
    }
    printf("%d\n", ans );
}
