//
//  singlelist.h
//  Data Structure
//
//  Created by ryer on 15/8/8.
//  Copyright (c) 2015年 ryer. All rights reserved.
//

#ifndef Data_Structure_singlelist_h
#define Data_Structure_singlelist_h

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int ElemType;

typedef struct _slist_node
{
	ElemType data;
	struct slist_node *next;
} Node, *SingleList;

void CreateList(SingleList *list)
{
	*list = NULL;
}

void InsertNode(Node *node)
{
	
}

#endif
