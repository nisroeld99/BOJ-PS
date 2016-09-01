/*
 *  6502   
 */
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int main(){
  int cnt = 1 ;
  while (true){
		int sc;
		scanf("%d",&sc) ;
		if (sc == 0 ) break;
		int sc2,sc3;
		scanf("%d%d",&sc2,&sc3);
		if ( 2*sc >= sqrt(sc2*sc2 + sc3*sc3  ) ) {
			printf("Pizza %d fits on the table.\n",cnt++);
		}else {
			printf("Pizza %d does not fit on the table.\n",cnt++);
		}
	}	
	return 0;
}
