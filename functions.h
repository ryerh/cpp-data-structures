#ifndef FUNTIONS_H
#define FUNTIONS_H

void GetInputData(ALGraph *pg, Vertex vertexes[]) {
	int i;
	int edge_count = 16;

	char data[32];
	float score;

	char fir[32];
	char snd[32];

	printf("教学计划编制程序\n");
	printf("请输入%d门课程的“名称 学分”，空格隔开：\n", VERTEX_NUM);

	strcpy(vertexes[0].data, "程序设计基础");
	strcpy(vertexes[1].data, "离散数学");
	strcpy(vertexes[2].data, "数据结构");
	strcpy(vertexes[3].data, "汇编语言");
	strcpy(vertexes[4].data, "语言的设计和分析");
	strcpy(vertexes[5].data, "计算机原理");
	strcpy(vertexes[6].data, "编译原理");
	strcpy(vertexes[7].data, "操作系统");
	strcpy(vertexes[8].data, "高等数学");
	strcpy(vertexes[9].data, "线性代数");
	strcpy(vertexes[10].data, "普通物理");
	strcpy(vertexes[11].data, "数值分析");

	vertexes[0].score = 2;
	vertexes[1].score = 3;
	vertexes[2].score = 4;
	vertexes[3].score = 3;
	vertexes[4].score = 2;
	vertexes[5].score = 3;
	vertexes[6].score = 4;
	vertexes[7].score = 4;
	vertexes[8].score = 7;
	vertexes[9].score = 5;
	vertexes[10].score = 2;
	vertexes[11].score = 3;

	for (i = 0; i < VERTEX_NUM; i++) {
		scanf("%s %f", vertexes[i].data, &vertexes[i].score);
		vertexes[i].visited = FALSE;
		vertexes[i].next = NULL;
		InsertVertex(pg, &vertexes[i]);
	}

	printf("课程输入完毕，请输入课程先修关系图的边数：");
	scanf("%d", &edge_count);
	printf("请输入课程先修关系对，空格隔开：\n");
	for (i = 0; i < edge_count; i++) {
		scanf("%s %s", fir, snd);
		InsertArc(pg, LocateVertex(pg, fir), LocateVertex(pg, snd));
	}
	InsertArc(pg, vertexes + 0, vertexes + 1);
	InsertArc(pg, vertexes + 0, vertexes + 2);
	InsertArc(pg, vertexes + 1, vertexes + 2);
	InsertArc(pg, vertexes + 0, vertexes + 3);
	InsertArc(pg, vertexes + 2, vertexes + 4);
	InsertArc(pg, vertexes + 3, vertexes + 4);
	InsertArc(pg, vertexes + 10, vertexes + 5);
	InsertArc(pg, vertexes + 4, vertexes + 6);
	InsertArc(pg, vertexes + 2, vertexes + 6);
	InsertArc(pg, vertexes + 2, vertexes + 7);
	InsertArc(pg, vertexes + 5, vertexes + 7);
	InsertArc(pg, vertexes + 8, vertexes + 9);
	InsertArc(pg, vertexes + 8, vertexes + 10);
	InsertArc(pg, vertexes + 8, vertexes + 11);
	InsertArc(pg, vertexes + 9, vertexes + 11);
	InsertArc(pg, vertexes + 0, vertexes + 11);
}

void TopologicalSort(ALGraph *g, Stack *s) {
	int i;
	for (i = 0; i < VERTEX_NUM; i++) {
		if (!g->vertexes[i]->visited) {
			int in_count = CountIndegree(g, g->vertexes[i]);
			if (in_count == 0) {
				g->vertexes[i]->visited = TRUE;
				Push(s, g->vertexes[i]);
				TopologicalSort(g, s);
			}
		}
	}
}

void ArrangementSort(Stack *ps, Vertex vertexes[]) {
	int i;
	int Max_Term = 6;
	float Max_Score = 10.0;
	float score_sum = 0.0;
	float avg_score = 0;
	int term_counter = 1;
	int choice;
	// ===============第2步：课时安排==============
	printf("\n请选择课程编排方式：\n");
	printf("1. 尽早把课上完\n");
	printf("2. 课时平均安排\n");
	printf("请选择方案(1|2): ");
	scanf("%d", &choice);
	printf("课程编排结果如下：\n");

	// 计算平均分
	score_sum = 0.0;
	for (i = 0; i < VERTEX_NUM; i++) {
		score_sum += vertexes[i].score;
	}
	avg_score = score_sum / Max_Term;

	if (choice == 1) {
		printf("课程尽可能地集中在前几个学期中\n");
		score_sum = 0.0;
		term_counter = 1;
		for (i = 0; i < VERTEX_NUM; i++) {
			Vertex *vtx = Pop(ps);
			if (score_sum + vtx->score > Max_Score) {
				score_sum = 0;
				term_counter++;
			}
			else {
				score_sum += vtx->score;
			}
			printf("第%d学期上: %s - %f\n", term_counter, vtx->data, vtx->score);
		}
	}

	if (choice == 2) {
		printf("课程平均安排到每个学期\n");
		score_sum = 0.0;
		term_counter = 1;
		for (i = 0; i < VERTEX_NUM; i++) {
			Vertex *vtx = Pop(ps);
			if (score_sum + vtx->score >= avg_score || score_sum + vtx->score > Max_Score) {
				score_sum = 0;
				term_counter++;
			}
			else {
				score_sum += vtx->score;
			}
			printf("第%d学期上: %s - %f\n", term_counter, vtx->data, vtx->score);
		}
	}
}

#endif