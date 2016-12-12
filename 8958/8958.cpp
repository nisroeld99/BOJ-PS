/*
 * 8958.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int main() {

	int n ;
	cin >> n ;

	while (n--){
		string s1;
		cin >> s1;
		int sum = 0 ;
		int check_num = 0 ;
		for (int i = 0 ; i<s1.size(); i++) {
			if ( s1[i] == 'O' ) {
				check_num ++;
				sum+= check_num ; 
			}else {
				check_num = 0 ; 	
			}	
		}
		printf ( "%d\n" , sum ) ;
	}


	return 0  ;
}
