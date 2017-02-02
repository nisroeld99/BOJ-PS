/*
 * 10808.cpp
 * 
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int main() {
	/*
	 * 알파벳이 26개이므로 알파벳마다 갯수를 저장할 배열을 만들면된다. 
	  */
	int alpha[30]={};  // 알파벳 갯수 저장할배열 
	string s1;
	cin >> s1;
	
	for (int i = 0 ; i < s1.size() ; i++)
		alpha[ s1[i] -'a' ]  ++ ;
	
	for (int i = 0 ; i < 26 ; i++) 
		printf("%d " , alpha[i] );

	printf("\n");
	return 0 ; 	
}
