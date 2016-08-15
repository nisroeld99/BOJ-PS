/*
 *  10874   
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int main(){
	int n ;
	scanf("%d",&n);
	int dab [11] ;  
	for (int i= 1;  i<= 10 ; i++ ) {
		dab[i] = ( (i-1) % 5) +1 ;
	}

	for (int i =1 ; i<=n ; i++){
			int cnt = 0 ;
			for (int j =1 ; j<=10 ; j++ ){
				int sc;
				scanf("%d",&sc);
				if (dab[j] == sc ){
					cnt ++ ;
				}
			} 
			if (cnt == 10 ) {
				printf("%d\n", i ) ;
			}
	}
	return 0 ;
}
