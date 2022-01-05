#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * left;
	struct node * right;
} * root = NULL;

void PrintSelectedLevel(struct node * rootTemp, int level){
	if (rootTemp == NULL)
		return;
	if (level == 1)
		printf("%d ", rootTemp -> data);
	else if (level > 1) {
		PrintSelectedLevel(rootTemp -> left, level - 1);
		PrintSelectedLevel(rootTemp -> right, level - 1);
	}
}

void PrintAllLevels(struct node * rootTemp){
	int i = 0;
	for (i = 1; i <= Height(rootTemp, 0); i++){
		printf("Height : %d -> ", i);
		
		PrintSelectedLevel(rootTemp, i);
		printf("\n");
	}
}

int Height(struct node * rootTemp, int height){
	if(rootTemp == NULL)
		return height;
	int heightLeft = Height(rootTemp -> left, height + 1), heightRight = Height(rootTemp -> right, height + 1);
	
	if(heightLeft > heightRight)
		return heightLeft;
	return heightRight;
}

struct node * CreateNode(int data){
	struct node * newNode = (struct node *) malloc (sizeof(struct node));
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;

	return newNode;
}

void AddNode(int data, struct node * rootTemp){
	if(rootTemp == NULL){
		root = CreateNode(data);
		return;
	}
	
	if(data < rootTemp -> data){
		if(rootTemp->left == NULL){
			rootTemp -> left = CreateNode(data);
		}
		else{
			AddNode(data, rootTemp -> left);
		}
	}
	else{
		if(rootTemp->right == NULL){
			rootTemp -> right = CreateNode(data);
		}
		else{
			AddNode(data, rootTemp -> right);
		}
	}
}

int main(){
	
	AddNode(5, root);
	AddNode(10, root);
	AddNode(4, root);
	AddNode(8, root);
	AddNode(6, root);
	AddNode(1, root);
	AddNode(3, root);
	AddNode(9, root);
	AddNode(7, root);
	AddNode(6, root);
	
	PrintAllLevels(root);

	return 0;
}
