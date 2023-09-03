#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef int element;
typedef struct TreeNode {
	//element key;
	char name[100];	    //추가
	char phone[100]; 	//추가
	struct TreeNode* left, * right;
} TreeNode;

//TreeNode* new_node(int item) {
TreeNode* new_node(char name[], char phone[]) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	//temp->key = item;
	strcpy_s(temp->name, sizeof(temp->name), name);
	strcpy_s(temp->phone, sizeof(temp->name), phone);
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}
//TreeNode* insert_node(TreeNode* node, int key) {
TreeNode* insert_node(TreeNode* node, char name[], char phone[]) { //수정
	if (node == NULL)
		return new_node(name, phone);  //return new_node(key);
	if (strcmp(name, node->name) < 0) // 수정 //if (key < node->key)
		node->left = insert_node(node->left, name, phone); //node->left = insert_node(node->left, key);
	else if (strcmp(name, node->name) > 0) //else if (key > node->key)
		node->right = insert_node(node->right, name, phone); //node->right = insert_node(node->right, key);
	return node;
}

//TreeNode* delete_node(TreeNode* root, int key) {
TreeNode* delete_node(TreeNode* root, char name[]) {
	if (root == NULL)
		return root;
	if (strcmp(name, root->name) < 0)//if (key < root->key)
		root->left = delete_node(root->left, name); //root->left = delete_node(root->left, key);
	else if (strcmp(name, root->name) > 0) //else if (key > root->key)
		root->right = delete_node(root->right, name); //root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* temp = min_value_node(root->right);
		//root->key = temp->key;
		strcpy_s(root->name, sizeof(root->name), temp->name);
		strcpy_s(root->phone, sizeof(root->phone), temp->phone);
		//root->right = delete_node(root->right, temp->key);
		root->right = delete_node(root->right, temp->name);
	}
	return root;
}


//추가 및 수정
//TreeNode* search(TreeNode* node, int key) {
TreeNode* search(TreeNode* node, char name[]) {
	if (node == NULL) return NULL;
	//if (key == node->key) return node;
	if (strcmp(name, node->name) == 0) return node;
	//else if (key < node->key)
	else if (strcmp(name, node->name) < 0)
		return search(node->left, name);
	else
		return search(node->right, name);
}

//추가 및 수정
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%s]: [%s] \n", root->name, root->phone);
		inorder(root->right);
	}
}


void ClearLineFromReadBuffer(void) {
	while (getchar() != '\n');
}

void save(TreeNode* root, FILE *fp) {
	if (root) {
		save(root->left, fp);
		if (fp != NULL) {
			fprintf(fp, "[%s]: [%s] \n", root->name, root->phone);
		}
		save(root->right, fp);
	}
}

int main(void)
{
	char command, name[100], phone[100];
	TreeNode* root = NULL, * p; 
	FILE* fp = NULL;

	do {
		fflush(stdin);
		printf("삽입(i), 파일 저장(S), 탐색(s), 삭제(d), 전체(p): ");
		command = getchar();
		fflush(stdin);
		switch (command) {
		case 'i':
			printf("친구의 이름: ");
			scanf_s("%s", name, 100);
			fflush(stdin);
			printf("친구의 전화번호: ");
			scanf_s("%s", phone, 100);			
			fflush(stdin); 
			root = insert_node(root, name, phone);
			break;
		case 'd':
			printf("  > 삭제 단어: ");
			fgets(name, sizeof(name), stdin);
			fflush(stdin);
			root = delete_node(root, name);
			break;
		case 'p':
			inorder(root);
			printf("\n");
			break;
		case 'S':
			fopen_s(&fp, "address.txt", "wt");
			save(root, fp);
			fclose(fp);
			break;
		case 's':
			printf("친구의 이름: ");
			scanf_s("%s", name, 100);
			fflush(stdin);
			p = search(root, name);
			if (p != NULL) {
				printf("%s의 전화번호: %s\n", name, p->phone);
			}
			else {
				printf("전화번호가 없습니다.\n");
			}
			break;
		}
		ClearLineFromReadBuffer();
	} while (command != 'q');
}