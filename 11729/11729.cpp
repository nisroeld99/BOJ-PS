/*
 * 11729.cpp
 *
 */
#include <algorithm>
#include <iostream>

using namespace std;



void go (int num, int from, int to){
    if (num == 0){
        return ;
    }
    go (num-1 ,from ,6-from-to);
    printf("%d %d\n",from, to);
    go (num-1 , 6-from-to, to );
    
}

int main(){
    int n ;
    scanf("%d",&n);
    printf("%d\n",(1<<n)-1);
    go ( n, 1, 3);
    
}
