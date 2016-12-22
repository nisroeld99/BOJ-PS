/*
 * 9012.cpp
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

	int tc ;
	scanf("%d", &tc) ;
	stack <int> st; 
	while (tc--){
		while (!st.empty() ) st.pop() ;
		string s1;
		cin >> s1 ;
		bool check = false ; 
		for (int i = 0 ; i < s1.size() ; i++ ) {
			if ( s1[i] == '(' ) {
				st.push(1) ;	
			}
			else {
				if ( st.size () == 0) {
					printf("NO\n" ) ; 
					check = true ;
					break; 
				}else {
					st.pop() ; 
				}
			}
		}
		if ( !check  ) {
			printf("YES\n");
		} 
		if ( st.size() > 0 ) {
			printf("NO\n"); 	
		}
	}


	return 0  ;
}
