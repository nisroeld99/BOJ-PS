/*
 * 9095.cpp
 * Copyright (C) 2016 helloworld <helloworld@choehyeong-gyuui-MacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int d[12];
int go(int n){
	if (n<1) return 0;
	int & ret =d[n];
	if (ret!=-1) return ret;
	return ret= go(n-1) +go(n-2) +go(n-3);
}
int main(){
	int n;
	cin >> n;
	memset(d,-1,sizeof(d));
	d[1]=1;
	d[2]=2;
	d[3]=4;
	while (n--){
		int sc;
		scanf("%d",&sc);
		printf("%d\n",go(sc));
	}

	return 0 ;
}
