/*
 * 9252.cpp
 *
 */
#include <stack>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int d[1001][1001];
int main() {

	string s1,s2;
	cin >> s1>>s2;
	int s1size, s2size ;
	s1size = (int) s1.size();
	s2size = (int) s2.size() ;
	s1= " " + s1;
	s2 = " " + s2;
	for (int i =1 ; i<=s1size ; i++ ) 
	{
		for (int j=1 ;j<=s2size ;j++){
			if (s1[i]== s2[j] )
			{
				d[i][j] =d[i-1][j-1]+1;
			}else {
				d[i][j] = max (d[i-1][j] , d[i][j-1] ) ;
			}
		}
	}
	printf("%d\n",d[s1size][s2size]);
	stack<char> dab; 
	while (s1size >=1 && s2size>=1) {
		if (d[s1size-1][s2size] == d[s1size][s2size] ){
			s1size -- ;
		}	
		else if (d[s1size][s2size] == d[s1size][s2size-1]) {
			s2size -- ;
		} 
		else if ( d[s1size][s2size] == d[s1size-1][s2size-1] +1) {
			dab.push(s1[s1size] ) ;
			s1size --;
			s2size -- ;
		}
	}
	while (!dab.empty()){
		printf("%c", dab.top()) ;
		dab.pop();
	}printf("\n");

	return 0  ;
}
