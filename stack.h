#ifndef STACK_H
#define STACH_H

/**
* ================数据结构定义：栈===================
*/

typedef struct _stack {
	Vertex *base[VERTEX_NUM];
	int size;
} Stack;

Status CreateStack(Stack *s) {
	s->size = 0;
	return OK;
}

void Push(Stack *s, Vertex *v) {
	assert(s->size <= VERTEX_NUM);
	s->base[s->size++] = v;
}

Vertex *Pop(Stack *s) {
	assert(s->size > 0);
	return s->base[--s->size];
}

Status DestroyStack(Stack *s) {
	s->size = 0;
	return OK;
}

#endif