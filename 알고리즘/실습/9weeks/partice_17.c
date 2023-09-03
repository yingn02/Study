#include <stdio.h> 

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
// ���� ��ȸ

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}
// ���� ��ȸ
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
// ���� ��ȸ
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

int main(void) {
	TreeNode n1 = { 5, NULL, NULL };
	TreeNode n2 = { 4, NULL, NULL };
	TreeNode n3 = { 3, NULL, NULL };
	TreeNode n4 = { 2, &n1,  NULL };
	TreeNode n5 = { 1, &n3,  &n2 };
	TreeNode n6 = { 0, &n5,  &n4 };
	TreeNode* root = &n6;

	printf("���� ��ȸ");
	inorder(root);
	printf("\n");
	printf("���� ��ȸ");
	preorder(root);
	printf("\n");
	printf("���� ��ȸ");
	postorder(root);
	printf("\n");
	return 0;
}
