/*
 * 11726.cpp
 * Copyright (C) 2016 helloworld <helloworld@choehyeong-gyuui-MacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
const int mod = 10007;
int d[1001];
int go(int n ){
	if (n==1) return 1;
	if (n==2) return 2;
	int &ret = d[n];
	if (ret!=-1) return ret;
	return ret = go(n-1)%mod + go(n-2)%mod ;
}

int main(){
	int n;
	cin >> n;
	memset(d,-1,sizeof(d));
	printf("%d\n",go(n)%mod );
	
	return 0 ;
}
