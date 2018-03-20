//
//  seqlist.h
//  Data Structure
//
//  Created by ryer on 15/4/4.
//  Copyright (c) 2015年 ryer. All rights reserved.
//

#ifndef Data_Structure_seqlist_h
#define Data_Structure_seqlist_h

#include <stdio.h>
#include <stdlib.h>

typedef int elType;

typedef struct _seq_list {
	elType *data;
	int length;
	int capacity;
} SeqList;

typedef enum _seq_list_global_constant {
	ALLOCATE_FAIL = 0,
	REALLOCATE_FAIL = 0,
	OVERFLOW = 0,
	SUCCESS = 1,
	INIT_CAPACITY = 16,
} SEQLIST_STATUS;

SEQLIST_STATUS initList(SeqList *l);
SEQLIST_STATUS destoryList(SeqList *l);
SEQLIST_STATUS insertElement(SeqList *l, int pos, elType el);
SEQLIST_STATUS deleteElement(SeqList *l, int pos);
elType getElement(SeqList *l, int pos);
SEQLIST_STATUS setElement(SeqList *l, int pos, elType newValue);
SEQLIST_STATUS _check_pos(SeqList *_l, int _pos);
SEQLIST_STATUS _reserve_capacity(SeqList *_l);
void printList(SeqList *l);

SEQLIST_STATUS initList(SeqList *l)
{
	l->data = (elType *)malloc(INIT_CAPACITY * sizeof(elType));
	if (l->data == NULL) {
		exit(ALLOCATE_FAIL);
	}
	l->length = 0;
	l->capacity = INIT_CAPACITY;
	return SUCCESS;
}

SEQLIST_STATUS destoryList(SeqList *l)
{
	if (l->data != NULL) {
		free(l->data);
		l->data = NULL;
	}
	
	return SUCCESS;
}

SEQLIST_STATUS insertElement(SeqList *l, int pos, elType el)
{
	int i = 0;
	if (pos<0 || pos>l->length) {
		return OVERFLOW;
	}
	if (l->length >= l->capacity) {
		_reserve_capacity(l);
	}
	for (i=l->length; i>pos; i--) {
		l->data[i] = l->data[i-1];
	}
	l->data[pos] = el;
	l->length++;
	
	return SUCCESS;
}

SEQLIST_STATUS deleteElement(SeqList *l, int pos)
{
	int i = 0;
	if (pos<0 || pos>=l->length) {
		return OVERFLOW;
	}
	for (i=l->length; i>pos; i--) {
		l->data[i] = l->data[i-1];
	}
	l->length--;
	
	return SUCCESS;
}

elType getElement(SeqList *l, int pos)
{
	if (pos<0 || pos>=l->length) {
		return 0;
	}
	return l->data[pos];
}

SEQLIST_STATUS setElement(SeqList *l, int pos, elType newValue)
{
	if (pos<0 || pos>=l->length) {
		return OVERFLOW;
	}
	l->data[pos] = newValue;
	return SUCCESS;
}

SEQLIST_STATUS _check_pos(SeqList *_l, int _pos)
{
	if (_pos<0 || _pos>_l->length) {
		return OVERFLOW;
	}
	return SUCCESS;
}

SEQLIST_STATUS _reserve_capacity(SeqList *_l)
{
	elType *newBase = NULL;
	int newCapacity = (_l->capacity * 2 + 1) * sizeof(elType);
	newBase = (elType *)realloc(_l->data, newCapacity);
	if (newBase == NULL) {
		return REALLOCATE_FAIL;
	}
	
	_l->data = newBase;
	_l->capacity = newCapacity;
	return SUCCESS;
}

void printList(SeqList *l)
{
	for (int i=0; i<l->length; i++) {
		printf("%d ", l->data[i]);
	}
	printf("\n");
}


#endif