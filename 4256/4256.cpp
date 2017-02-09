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
    int root = find_(inorder, preorder[0] , n ) ;
    if ( root != 0 ){
        postorder(preorder+1, inorder , root);
    }
    
    if (root != n-1 ) { //남아 있으면,
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

