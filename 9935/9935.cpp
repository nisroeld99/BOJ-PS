/*
 * 9935.cpp
 *
 */
#include <iostream>
#include <stack>
using namespace std;
typedef pair<int ,int>  ii ;
stack<ii> st;
bool c [1111111];
int main(){
    string s1,s2;
    cin >> s1 >>s2;
    for (int i =0 ; i< s1.size() ; i++){
        if ( s1[i]== s2[0] ){
            st.push(ii( i, 0 )) ;
            if ( st.top().second == s2.size()-1){ //끝에 도달했으면
                for (int i = 0 ; i< s2.size() ; i++ ){
                    c[st.top().first] = true ;
                    st.pop();
                }
            }
        }
        else {
            if (!st. empty()){
                auto temp = st.top();
                int idx = temp.first;
                int idx_s2 = temp.second;
                if ( s1[i] == s2[idx_s2 +1]){//다음 문자열이 맞으면
                    st.push(ii( i , idx_s2+1 )) ;
                    
                    if ( idx_s2 +1 == s2.size()-1){ //끝에 도달했으면
                        for (int i = 0 ; i< s2.size() ; i++ ){
                            c[st.top().first] = true ;
                            st.pop();
                        }
                    }
                }
                else {
                    while (!st.empty())
                        st.pop();
                }
                
            }
            
        }
    }
    int cnt = 0 ;
    for (int i=0 ; i< s1.size();i++){
        if ( !c[i] ){
            printf("%c",s1[i]);
            
        }else
            cnt ++ ;
    }
    if ( cnt == s1.size() )
        printf("FRULA\n");
}

