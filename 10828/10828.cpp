/*
 * 10828.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std; 

int main() {
	int n ;
	scanf("%d",&n) ;
	stack <int> st ; 
	while ( n--){
		string s1;
		cin >> s1;
		int n1 ;

		if ( s1 == "push" ) {
			scanf("%d", &n1 ) ;
			st.push(n1 ) ;
		}else if ( s1 == "pop"){
			if ( !st.empty () ) {
				printf("%d\n" ,	st.top()) ;
				st.pop();
			}else {
				printf("-1\n");
			}
		}
		else if ( s1 == "top"){
			if ( !st.empty () ) {
				printf("%d\n" ,	st.top()) ;
			}else {
				printf("-1\n");
			}
		}else if ( s1 == "size"){
			printf("%d\n", st.size() ) ;	
		}else if ( s1== "empty" ) {
			printf("%d\n",st.empty() ) ;
		}
	}
		


	return 0  ;
}
