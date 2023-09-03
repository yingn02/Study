#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;
typedef struct GraphType {
	int n;
	char value[MAX_VERTICES];
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;
void init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}
void insert_vertex(GraphType* g, int index, char value) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->value[index] = value;
}
void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류\n");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}
void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %c의 인접 리스트 ", g->value[i]);
		while (p != NULL) {
			printf("-> %c ", g->value[p->vertex]);
			p = p->link;
		}
		printf("\n");
	}
}

int main() {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	int n;
	int a[MAX_VERTICES];
	char str[80];
	FILE* fp = NULL;
	fopen_s(&fp, "graph.txt", "r");
	if (fp != NULL) {
		init(g);
		fscanf_s(fp, "%d", &n);
		g->n = n;
		for (int i = 0; i < n; i++) {
			fscanf_s(fp, "%s", str, 80);
			insert_vertex(g, i, str[0]);
			//printf("%s %d %d %d %d\n", str, a, b, c, d);
			for (int j = 0; j < n; j++) {
				fscanf_s(fp, "%d", &a[j]);
				if (a[j] != 0) {
					insert_edge(g, i, j);
				}
			}
		}
		fclose(fp);
	}
	print_adj_list(g);
	free(g);
	return 0;
}
