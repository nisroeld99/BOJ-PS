/*
 *  2675   
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int n ;
		string s;
		cin >> n >> s; 
		for (int i=0; i<s.size () ; i++){
			for (int j= 0 ; j<n ; j++ ){
				printf("%c", s[i] ) ;
			}
		}
		printf("\n");
	}

}
