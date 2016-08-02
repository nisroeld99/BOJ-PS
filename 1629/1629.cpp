#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
unsigned long long go(unsigned long long a, unsigned long long b ,unsigned long long c){
    if ( b ==0) return 1;
    if (b %2 ==1 ) return a*go(a, b-1,c)%c; // 지수가 홀수 일때,
    else {
        unsigned long long half = go ( a, b/2,c)%c; // 지수가 짝수 일때, 
        return (half%c*half%c)%c;
    }
 
}
 
int main(){
    unsigned long long a,b,c;
    scanf("%llu %llu %llu",&a,&b,&c);
    printf("%llu\n",go(a,b,c));
     
}
