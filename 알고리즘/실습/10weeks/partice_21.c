#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200


typedef struct TreeNode {
	int key;
	char ch;
	struct TreeNode* left;
	struct TreeNode* right;
} element; 
typedef struct {
	element* heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_min_heap(HeapType* h, element* item) {
	int i = ++(h->heap_size);
	while (
		(i != 1) &&	// 최상위 노드
		(item->key < h->heap[i / 2]->key)) {	//맨 마지막에서 추가 후 부모 노드와 비교
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element* delete_min_heap(HeapType* h) {
	int parent, child;
	element* item, *temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) &&
			(h->heap[child]->key) > h->heap[child + 1]->key)
			child++;
		if (temp->key < h->heap[child]->key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;

}

element* make_tree(element* left, element* right) {
	element* node = (element*)malloc(sizeof(element));
	node->left = left;
	node->right = right;
	return node;
}

void destroy_tree(element* root) {
	if (root == NULL) return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}

int is_leaf(element* root) {
	return !(root->left) && !(root->right);
}
void print_array(int codes[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}

void print_codes(element* root, int codes[], int top) {
	if (root->left) {
		codes[top] = 1;
		print_codes(root->left, codes, top + 1);
	}
	if (root->right) {
		codes[top] = 0;
		print_codes(root->right, codes, top + 1);
	}
	if (is_leaf(root)) {
		printf("%c: ", root->ch);
		print_array(codes, top);
	}
}


void huffman_tree(int freq[], char ch_list[], int n) {
	HeapType* heap = create();
	init(heap);
	for (int i = 0; i < n; i++) {
		element* node = make_tree(NULL, NULL);
		node->ch = ch_list[i];
		node->key = freq[i];
		insert_min_heap(heap, node);
	}

	for (int i = 1; i < n; i++) {
		element* e1 = delete_min_heap(heap);
		element* e2 = delete_min_heap(heap);

		element* x = make_tree(e1, e2);
		x->key = e1->key + e2->key;
		printf("%d+%d=%d\n", e1->key, e2->key, x->key);

		insert_min_heap(heap, x);
	}
	element* e = delete_min_heap(heap);
	int top = 0;
	int codes[100];
	print_codes(e, codes, top);
}

int index_arr(char* arr, int size, char val) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == val) return i; 
	}
	return -1;
}

int main(void) {
	char ch_list[] = { 's', 'i', 'n', 't', 'e' };
	int freq[] = { 4, 6, 8, 12, 15 };
	//char ch_list[] = { 'i', 's', 'n', 't', 'e' };
	//int freq[] = { 6, 4, 8, 12, 15 };
	huffman_tree(freq, ch_list, 5);

 
	char* string = "This study is toward interactive dynamic mapping on web based on open source.\
 Among available interactive mapping of open source libraries, D3.js was chosen.\
 It is a JavaScript library with capability to bind arbitrary data and provides \
 open source mapping framework. Analysis of geo-statistical data is designed using R,\
 a package and programming language for statistical data analysis. \
 This work implemented an integrated user interface with these separate frameworks, \
 and provides a mobile web app application for client sides.";

	char alphbet[] = {
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u'
		,'v','w','x','y','z'
	};
	int freqA[] = {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	};
	for (int i = 0; i < strlen(string); i++) {
		int index = index_arr(alphbet, 26, string[i]);
		if (index >= 0) {
			freqA[index] = freqA[index] + 1;
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", freqA[i]);
	}
	printf("\n");
	for (int i = 0; i < 26; i++) {
		printf("%c ", alphbet[i]);
	} 

	for (int i = 0; i < 26; i++) {
		printf("%d ", freqA[i]);
	}
	printf("\n");
	for (int i = 0; i < 26; i++) {
		printf("%c ", alphbet[i]);
	}
	printf("\n");

	

	huffman_tree(freqA, alphbet, 26);
 
	return 0;
}
