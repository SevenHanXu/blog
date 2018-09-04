/*************************************************************************
	> File Name: binary_search_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  9/ 4 20:48:48 2018
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode{
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode;

BSTNode *get_new_node(int key){
    BSTNode *p = (BSTNode *)malloc(sizeof(BSTNode));
    p->lchild = p->rchild = NULL;
    p->key = key;
    return p;
}

BSTNode *insert(BSTNode *tree, int key){
    if(tree == NULL) tree = get_new_node(key);
    if(tree->key == key) return tree;
    if(key < tree->key) tree->lchild = insert(tree->lchild, key);
    else tree->rchild = insert(tree->rchild, key);
    return tree;
}

BSTNode *predecessor(BSTNode *tree){
    BSTNode *p = tree->lchild;
    while(p->rchild){
        p = p->rchild;
    }
    return p;
}

BSTNode *delete_node(BSTNode *tree, int key){
    if(tree == NULL) return NULL;
    if(key < tree->key){
        tree->lchild =  delete_node(tree->lchild, key);
    }else if(key > tree->key){
        tree->rchild =  delete_node(tree->rchild, key);
    }else{
        if(tree->lchild == NULL && tree->rchild == NULL){
            free(tree);
            return NULL;
        }else if(tree->lchild == NULL || tree->rchild == NULL){
            BSTNode *ret_tree = (tree->lchild ? tree->lchild : tree->rchild);
            free(tree);
            return ret_tree;
        }else{
            BSTNode *pre_node = predecessor(tree);
            tree->key = pre_node->key;
            tree->lchild = delete_node(tree->lchild, pre_node->key);
        }
    }
    return tree;
}

int search(BSTNode *tree, int key){
    if(tree == NULL) return 0;
    if(tree->key == key) return 1;
    if(key < tree->key) return search(tree->lchild, key);
    return search(tree->rchild, key);
}

void in_order(BSTNode *tree){
    if(tree == NULL) return ;
    in_order(tree->lchild);
    printf("%d ", tree->key);
    in_order(tree->rchild);
    return ;
}

void clear(BSTNode *tree){
    if(tree == NULL) return ;
    clear(tree->lchild);
    clear(tree->rchild);
    free(tree);
    return ;
}

int main(){
    int op, value;
    BSTNode *tree = NULL;
    while(~scanf("%d%d", &op, &value)){
        switch(op){
            case 1: tree = insert(tree, value);break;
            case 2: tree = delete_node(tree, value); break;
            case 3: printf("search(%d) = %d\n", value, search(tree, value));break;
            case 4: in_order(tree);printf("\n");break;
        }
    }
    return 0;
}
