/*************************************************************************
	> File Name: Double_Array_Trie.c
	> Author: 
	> Mail: 
	> Created Time: 二  9/ 4 15:54:52 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct DANode{
	int base, check;
	
}DANode;

typedef struct Node{
	int flag;
	struct Trie *next[BASE];
}Node, *Trie;



Node *get_node(){
	Node *p = (Node *)calloc(sizeof(Node), 1);
	p->flag = 0;
	return p;
}

void clear(Trie root){
	if(root == NULL) return ;
	for(int i = 0; i < BASE; i++){
		free(root->next[i]);
	}
	free(root);
	return ;
}

Node *insert(Trie root, const char *str){
	if(root == NULL) root = get_node();
	Node *p = root;
	for(int i = 0; str[i]; i++){
		int ind = str[i] - BEGIN_LETTER;
		if(p->next[ind] == NULL) p->next[ind] = get_node();
		p = p->next[ind];
	}
	p->flag = 1;
	return root;
}

Node *search(Trie root, const char *str){
	Node *p = root;
	int i = 0;
	while (p && str[i]) {
		int ind = str[i++] - BEGIN_LETTER;
		p = p->next[ind];
	}
	return (p && p->flag);
}

void get_random_string(char *str){
	int len = 0;
	len = rand() % 10 + 1;
	for(int i = 0; i < len; i++) str[i] = BEGIN_LETTER + rand() % BASE;
	str[len] = 0;
	return ;
}

void output(Trie root, char *str, int level){
	if(root == NULL) return ;
	str[level] = 0;
	if(root->flag) printf("find word: %s\n", str);
	for(int i = 0; i < BASE; i++){
		if(root->next[i] == NULL) continue;
		str[level] = i + BEGIN_LETTER;
		output(root->next[i], str, level + 1);
	}
	return ;
}


void output_da(DANode *data, char *str, int level, int ind){
	if(data == NULL) return ;
	str[level] = 0;
	if(data[ind].check < 0) printf("Double Array find word: %s\n", str);
	for(int i = 0; i < BASE; i++){
		if(abs(data[data[ind].base + i].check) != ind) continue;
		str[level] = i + BEGIN_LETTER;
		output_da(data, str, level + 1, data[ind].base + i);
	}
	return ;
}



int get_base(Node *node, DANode *data){
	int base = 2, flag = 0;
	while(!flag){
		flag = 1;
		for(int i = 0; i < BASE; i++){
			if(data[base + i].check == 0) continue;
			flag = 0;
			break;
		}
		base += (!flag);
	}
	return base;
}



void build(Node *node, DANode *data, int ind){
	if(node == NULL) return ;
	if(node->flag) data[ind].check = -data[ind].check;
	data[ind].base = get_base(node, data);
	for(int i = 0; i < BASE; i++){
		if(node->next[i] == NULL) continue;
		data[data[ind].base + i].check = ind;
	}
	for(int i = 0; i < BASE; i++){
		if(node->next[i] == NULL) continue;
		build(node->next[i], data, data[ind].base + i);
	}
	return ;
}


int main(){
	srand(time(0));
	#define CNT 10
	char str[50];
	Node *root = NULL;
	for(int i = 0; i < CNT; i++){
		get_random_string(str);
		root = insert(root, str);
		printf("insert %s to Trie\n", str);
	}
	output(root, str, 0);
	
	
	
	DANode *data = (DANode *)calloc(sizeof(DANode) , (CNT) * 100);
	build(root, data, 1);
	output_da(data, str, 0, 1);//	根结点地址， str， 
	#undef CNT
	return 0;
}
