#ifndef GRAPH_H
#define GRAPH_H

/**
 * ================数据结构定义：邻接表图===================
 */

#define VERTEX_NUM 12 // 图的顶点数量

typedef enum { FALSE, TRUE } Boolean;

typedef enum { ERROR, OK } Status;

typedef struct _vertex { // 顶点
	char data[32];
	float score;
	Boolean visited;
	struct _vertex *next;
} Vertex;

typedef struct _algraph { // 邻接表
	Vertex *vertexes[VERTEX_NUM];
} ALGraph;

Status CreateGraph(ALGraph *g) {
	int i;
	for (i = 0; i < VERTEX_NUM; i++) {
		g->vertexes[i] = NULL;
	}
	return OK;
}

Status DestroyGraph(ALGraph *g) {
	int i;
	for (i = 0; i < VERTEX_NUM; i++) {
		Vertex *head = g->vertexes[i];
		Vertex *next = head->next;
		while (next != NULL) {
			Vertex *next_of_next = next->next;
			free(next);
			next = next_of_next;
		}
	}
	return OK;
}

Vertex *LocateVertex(ALGraph *g, char *data) {
	int i;
	for (i = 0; i < VERTEX_NUM; i++) {
		if (strcmp(g->vertexes[i]->data, data) == 0) {
			return g->vertexes[i];
		}
	}
	return NULL;
}

Status InsertVertex(ALGraph *g, Vertex *v) {
	int i = 0;
	while (g->vertexes[i] != NULL) {
		if (i == VERTEX_NUM - 1) // 顶点数量已满
			return ERROR;
		i++;
	}
	g->vertexes[i] = v;
	return OK;
}

Status InsertArc(ALGraph *g, Vertex *v1, Vertex *v2) {
	int i = 0;

	for (i = 0; i < VERTEX_NUM; i++) {
		if (g->vertexes[i] == v1) {
			// Create a copy of v2
			Vertex *tmp = (Vertex *)malloc(sizeof(Vertex));
			strcpy(tmp->data, v2->data);
			tmp->next = v1->next;
			// Insert new Vertex node into adjacent list
			v1->next = tmp;
			break;
		}
	}

	return OK;
}

int CountIndegree(ALGraph *g, Vertex *v) {
	int count = 0;
	int i;
	for (i = 0; i < VERTEX_NUM; i++) {
		if (!g->vertexes[i]->visited) {
			Vertex *next_vertex = g->vertexes[i]->next;
			while (next_vertex != NULL) {
				if (strcmp(v->data, next_vertex->data) == 0)
					count++;
				next_vertex = next_vertex->next;
			}
		}
	}
	return count;
}

void PrintGraph(ALGraph *g) {
	int i;
	printf("\n图中包含的数据如下：\n");
	for (i = 0; i < VERTEX_NUM; i++) {
		Vertex *next_vertex = g->vertexes[i]->next;
		printf("%s(%f) -> ", g->vertexes[i]->data, g->vertexes[i]->score);
		while (next_vertex != NULL) {
			printf("%s, ", next_vertex->data);
			next_vertex = next_vertex->next;
		}
		printf("\n");
	}
}

#endif