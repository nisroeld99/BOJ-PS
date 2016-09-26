/*
 * 2959.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int main() {
	vector<int>v;
	int a,b,c,d;
	scanf("%d%d%d%d", &a,&b,&c,&d);
	
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	
	sort(v.begin() , v.end() ) ;

	printf("%d\n" , v[0]* v[2] ) ;

	return 0;

}
