/*************************************************************************
	> File Name: AVL.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  9/ 5 11:58:05 2018
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define max(a, b)({\
    __typeof (a)  tempa = (a), tempb = (b);\
    tempa > tempb ? tempa : tempb;\
})

typedef struct Node{
    int key, height;
    struct Node *lchild, *rchild;
}Node;

Node  __NIL;
#define NIL (&__NIL)

int static_init(){
    NIL->lchild = NIL->rchild = NULL;
    NIL->height = 0;
    return 0;
}

int ______temp = static_init();

Node *init(int key){
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild = NIL;
    p->key = key;
    p->height = 1;
    return p;
}

void Up(Node *root){
    root->height = max(root->lchild->height, root->rchild->height) + 1;
}

Node *left_rotate(Node *root){
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    Up(root);
    Up(temp);
    return temp;
}

Node *right_rotate(Node *root){
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    Up(root);
    Up(temp);
    return temp;
}

Node *__maintain(Node *root, int flag){
    if(flag){
        if(root->lchild->rchild->height > root->lchild->lchild->height){
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    }else{
        if(root->rchild->lchild->height > root->rchild->rchild->height){
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    return root;
}


Node *maintain(Node *root){
    if(abs(root->lchild->height - root->rchild->height) < 2) return root;
    root = __maintain(root, root->lchild->height > root->rchild->height);
    return root;
}

Node *insert(Node *root, int key){
    if(root == NIL) return init(key);
    if(root->key == key){
        return root;
    }else if(key < root->key){
        root->lchild = insert(root->lchild, key);
    }else{
        root->rchild = insert(root->rchild, key);
    }
    Up(root);
    root = maintain(root);
    return root;
}

void clear(Node *root){
    if(root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void pre_inorder(Node *root){
    if(root == NIL) return ;
    printf("%d (%d %d)\n", root->key, root->lchild->key, root->rchild->key);
    pre_inorder(root->lchild);
    pre_inorder(root->rchild);
    return ;
}
 
int main(){
    int n, a;
    Node *root = NIL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        root = insert(root, a);
        printf("insert info : \n");
        pre_inorder(root);
        printf("------------\n");
    }
    clear(root);
    return 0;
}
