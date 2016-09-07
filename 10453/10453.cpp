/*
 * 10453.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
int main()
{
	int N;
	scanf("%d",&N);
	for(;N--;)
	{
		char a[100001],b[100001];
		scanf(" %s%s",a,b);
		int ret=0;
		int j; 
		for(int i=0 ; a[i] ; i++ )
		{
			for(j=0 ; a[i]!=b[i+j] ; j++)
				ret++;
			for(; j ; j--) 
				b[i+j]=b[i+j-1];
		}
		printf("%d\n",ret);
	}
} 
