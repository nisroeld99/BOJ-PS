/*
 * 2965.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int main() {

	int a,b,c;
	scanf("%d%d%d",&a,&b,&c) ;
	printf("%d\n", b-a > c-b ? b-a-1 : c-b-1 ) ;
	return 0  ;
}
