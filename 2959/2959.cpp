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
	/*
	 * 가장 큰 사각형 만드려면 , 첫번쨰, 3번째 길이가 각각의 변이 되어야한다.   여러가지 방법이 있지만, 배운 stl을 써먹자면 , 
	 *  sort해서 , v[0] , v[2] 값을 곱해줌 
	 * */
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
