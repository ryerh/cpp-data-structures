//
//  linkedlist.h
//  Data Structure
//
//  Created by ryer on 15/4/4.
//  Copyright (c) 2015年 ryer. All rights reserved.
//

#ifndef Data_Structure_linkedlist_h
#define Data_Structure_linkedlist_h

#include <stdio.h>
#include <stdlib.h>

typedef int elType;
typedef struct _node Node;
typedef struct _linked_list LinkedList;

// 单链表节点
struct _node {
	elType data;
	Node *next;
};

// 单链表
struct _linked_list {
	Node *HEAD;
};

// 初始化单链表
void InitList(LinkedList *l) {
	Node *head = NULL;
	head = (Node *)malloc(sizeof(Node));
	if (head == NULL) {
		printf("Init failed, cant allocate memory");
		exit(0);
	}
	head->next = NULL;
	l->HEAD = head;
}

// 销毁单链表
void DestroyList(LinkedList *l) {
	Node *iterator = NULL;
	Node *curNode = NULL;
	
	iterator = l->HEAD;
	if (iterator->next == NULL) {
		return;
	} // 空链表直接退出
	
	// 此时iterator指向HEAD
	while (iterator->next != NULL) {
		iterator = iterator->next;
		curNode = iterator;
		free(curNode);
		curNode = NULL;
	}
	
	// 补刀
	l->HEAD->next = NULL;
}

// 插入元素
void InsertElement(LinkedList *l, int pos, elType e) {
	int i = 0;
	Node *iterator = NULL;
	Node *newNode = NULL;
	
	// 移动iterator到待插入节点的前一个位置
	iterator = l->HEAD;
	for (i=0; i<pos; i++) {
		if (iterator == NULL) break;
		iterator = iterator->next;
	}
	
	// 正常情况下iterator指向pos的前一个位置
	if (iterator == NULL) {
		printf("指定的pos不存在，插入失败\n");
		return;
	}
	
	// 创建新节点
	newNode = (Node *)malloc(sizeof(Node));
	newNode->data = e;
	newNode->next = iterator->next;
	// 插入节点
	iterator->next = newNode;
}

elType DeleteElement(LinkedList *l, int pos) {
	int i = 0;
	elType data = 0;
	Node *iterator = NULL;
	Node *curNode = NULL;
	
	// 移动iterator到待删除节点的前一个位置
	iterator = l->HEAD;
	for (i=0; i<pos; i++) {
		if (iterator == NULL) break;
		iterator = iterator->next;
	}
	
	//正常情况下iterator指向pos的前一个位置
	if (iterator == NULL) {
		printf("指定的pos不存在，删除失败\n");
		return 0;
	}
	
	// 保存要删除节点的指针和数据
	curNode = iterator->next;
	data = curNode->data;
	
	// 摘除节点，释放内存
	iterator->next = curNode->next;
	free(curNode);
	curNode = NULL;
	
	// 返回删除节点的值
	return data;
}

void ConcatList(LinkedList *dst, LinkedList *src) {
	Node *dstItr = NULL;
	Node *srcItr = NULL;
	Node *newNode = NULL;
	
	dstItr = dst->HEAD;
	while (dstItr->next != NULL) {
		dstItr = dstItr->next;
	} // dstItr 指向最后一个元素，如果dst为空，dstItr指向HEAD
	
	srcItr = src->HEAD;
	while (srcItr->next != NULL) {
		srcItr = srcItr->next;
		
		newNode = (Node *)malloc(sizeof(Node));
		if (newNode == NULL) {
			printf("alloc node failed");
			return;
		}
		newNode->data = srcItr->data;
		newNode->next = NULL;
		
		dstItr->next = newNode;
		dstItr = newNode;
	}
}

void PrintList(LinkedList *l) {
	Node *iterator = l->HEAD;
	
	if (iterator->next == NULL) {
		printf("list is empty");
		return;
	}
	
	while (iterator->next != NULL) {
		iterator = iterator->next;
		printf("%d ", iterator->data);
	}
	
	printf("\n");
}

#endif
