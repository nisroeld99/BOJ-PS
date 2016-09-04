/*
 * 2331.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int main() {

	int n , m ;
	cin >> n >> m ;
	int c[296000];
	c[n] = 1 ;
	for (int i =2 ; ; i++ ) {
		int temp = 0  ;
		while (n != 0 ) {
			int gobtemp =  1 ;
			for (int i = 0 ; i<m ; i++ ){
				gobtemp *= (n%10) ;
			}
			temp +=gobtemp;
			n/=10; 
		}
		if ( c[temp] ){
			printf("%d\n",c[temp]-1 ) ;
			break ;
		} 
		n = temp ; 
		c[temp] = i ;
	}


	return 0  ;
}
