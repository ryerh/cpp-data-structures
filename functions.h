#ifndef FUNTIONS_H
#define FUNTIONS_H

void GetInputData(ALGraph *pg, Vertex vertexes[]) {
	int i;
	int edge_count = 16;

	char data[32];
	float score;

	char fir[32];
	char snd[32];

	printf("��ѧ�ƻ����Ƴ���\n");
	printf("������%d�ſγ̵ġ����� ѧ�֡����ո������\n", VERTEX_NUM);

	strcpy(vertexes[0].data, "������ƻ���");
	strcpy(vertexes[1].data, "��ɢ��ѧ");
	strcpy(vertexes[2].data, "���ݽṹ");
	strcpy(vertexes[3].data, "�������");
	strcpy(vertexes[4].data, "���Ե���ƺͷ���");
	strcpy(vertexes[5].data, "�����ԭ��");
	strcpy(vertexes[6].data, "����ԭ��");
	strcpy(vertexes[7].data, "����ϵͳ");
	strcpy(vertexes[8].data, "�ߵ���ѧ");
	strcpy(vertexes[9].data, "���Դ���");
	strcpy(vertexes[10].data, "��ͨ����");
	strcpy(vertexes[11].data, "��ֵ����");

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

	printf("�γ�������ϣ�������γ����޹�ϵͼ�ı�����");
	scanf("%d", &edge_count);
	printf("������γ����޹�ϵ�ԣ��ո������\n");
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
	// ===============��2������ʱ����==============
	printf("\n��ѡ��γ̱��ŷ�ʽ��\n");
	printf("1. ����ѿ�����\n");
	printf("2. ��ʱƽ������\n");
	printf("��ѡ�񷽰�(1|2): ");
	scanf("%d", &choice);
	printf("�γ̱��Ž�����£�\n");

	// ����ƽ����
	score_sum = 0.0;
	for (i = 0; i < VERTEX_NUM; i++) {
		score_sum += vertexes[i].score;
	}
	avg_score = score_sum / Max_Term;

	if (choice == 1) {
		printf("�γ̾����ܵؼ�����ǰ����ѧ����\n");
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
			printf("��%dѧ����: %s - %f\n", term_counter, vtx->data, vtx->score);
		}
	}

	if (choice == 2) {
		printf("�γ�ƽ�����ŵ�ÿ��ѧ��\n");
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
			printf("��%dѧ����: %s - %f\n", term_counter, vtx->data, vtx->score);
		}
	}
}

#endif