/*
 * 9251.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int d[1111][1111];
string s1,s2;
int main() {
	cin >> s1 >> s2;
	int s1size = (int)s1.size();
	int s2size = (int)s2.size() ;
	s1= " " + s1;
	s2= " " + s2;
	for (int i =1 ; i<=s1size; i++ ){
		for (int j=1 ; j<= s2size; j++){
			if (s1[i] == s2[j]){
				d[i][j] = d[i-1][j-1] + 1 ;
			}else {
				d[i][j] = max ( d[i-1][j] , d[i][j-1] ) ;
			}
		}
	}
	printf("%d\n", d[s1size][s2size] ) ;	


	return 0  ;
}
