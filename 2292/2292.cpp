#include<stdio.h>
int N,cnt,sum;
int main()
{
    int i;
    scanf("%d",&N);
    cnt=1;
    sum=1;
    while(sum<N)
    {
        sum+=cnt*6;
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}
