/*
 *  3040   
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int a[10];
int d[10];
void go ( int now , int sum ,int cnt ) 
{
	if (now == 10 ){
		if ( cnt == 7 && sum == 100 ){
			for (int i =1  ;i <10 ; i++){
				if ( d[i] ) {
					printf("%d\n",a[i]); 
				}
			}		
		}
		return ;
	}
	
	d[now] =1; 
	go (now +1 , sum+a[now] , cnt+1 ) ;
	d[now] = 0;
	 
	go ( now +1 , sum, cnt);
	return ;
}

int main(){
	for (int i =1 ; i<=9 ; i++ ){
		scanf("%d",&a[i]) ;
	}
	go ( 1 , 0 ,0) ;


}
