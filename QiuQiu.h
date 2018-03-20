//
//  QiuQiu.h
//  Data Structure
//
//  Created by ryer on 15/4/14.
//  Copyright (c) 2015年 ryer. All rights reserved.
//

#ifndef Data_Structure_QiuQiu_h
#define Data_Structure_QiuQiu_h

#define SPACE 100

typedef int eType;

eType MiniDb[SPACE]={0};
int length=0;


void CheckPosition(int index){
	if (index < 0 || index > length){
		printf("Query out of range");
		exit(0);
	}
}
eType Query(int index) {
	CheckPosition(index);
	
	return MiniDb[index];
}

void Update(int index, eType e) {
	CheckPosition(index);
	
	MiniDb[index]=e;
}

void Add(int index, eType e){
	int i=0;
	CheckPosition(index);
	
	// 如果插入的位置刚好是最后一个，就直接插入到末尾
	if (length==index) {
		MiniDb[index] = e;
		length++;
	}else{ // 如果插入的位置不是最后一个，就得移动元素
		
		// 下面这个循环在移动元素
		for (i=length-1; i>=index; i--) {
			// 移动元素
			MiniDb[i+1] = MiniDb[i];
		}
		// 让长度增加一位
		length++;
		
		// 元素移动完毕后，插入新元素
		MiniDb[index] = e;
	}
}

void Delete(int index){
	int i=0;
	if (index<0 || index>=length) {
		printf("Delete out of range\n");
	}
	else{
		for (i=index; i<length; i++) {
			MiniDb[i]= MiniDb[i+1];
		}
		
		length--;
	}
}

#endif
