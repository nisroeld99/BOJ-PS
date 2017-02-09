/*
 * 4256.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int find_(int*arr, int root, int n){
    for (int i = 0 ; i<n; i++){
        if ( arr[i] ==root )
            return i ;
        
    }
    return -1 ;
}

void postorder(int*preorder , int*inorder, int n ){
    int root = find_(inorder, preorder[0] , n ) ;  // inorder상에서 root를 찾아 . root왼쪽은 왼쪽tree, 오른쪽은 오른쪽tree
    if ( root != 0 ){  //가장왼쪽 끝갈때까지, 이동, ( preorder +1 하는 이유는, 이게좌측이동이랑 같다. )  0이면 가장 좌측아래
        postorder(preorder+1, inorder , root);
    }
    
    if (root != n-1 ) { //  우측 아래갈떄까지 조사,  root+1 하는 이유? root(1개) + 좌축 tree 제외한 우측 트리 추츨 root가
        postorder(preorder+root+1 , inorder+root+1, n-root-1) ;
    }
    printf("%d ", preorder[0] ) ;
}

int main() {
    int tc;
    scanf("%d",&tc);
    int inorder[1111];
    int preorder[1111];

    while (tc--){
        int n ;
        scanf("%d",&n);
        for (int i =0 ; i<n; i++){
            scanf("%d", &preorder[i] ) ;
        }
        for (int i =0 ; i<n; i++){
            scanf("%d",&inorder[i] ) ;
        }
        postorder(preorder,inorder,n);	
        printf("\n");
    }
    
    
    
    return 0  ;
}

