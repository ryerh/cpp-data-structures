//
//  sort.h —— 排序算法
//  Data Structure
//
//  Created by ryer on 5/4/15.
//  Copyright (c) 2015 ryer. All rights reserved.
//

#ifndef Data_Structure_sort_h
#define Data_Structure_sort_h

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 冒泡排序
 */
template <typename Comparable>
void BubbleSort(vector<Comparable> &a) {
	int i, j;
	for (i = (int)a.size() - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

/**
 * 选择排序
 */
template <typename Comparable>
void SelectionSort(vector<Comparable> &a) {
	int i, j, key;
	int n = (int)a.size();
	for (i = 0; i < n; i++) {
		key = i;
		for (j = i + 1; j < n; j++) {
			if (a[key] > a[j]) {
				key = j;
			}
		}
		if(key != i) {
			swap(a[i], a[key]);
		}
	}
}

/**
 * 插入排序
 */
template <typename Comparable>
void InsertionSort(vector<Comparable> &a) {
	int i, j, key;
	int n = (int)a.size();
	for (i = 1; i < n; i++) {
		key = a[i];
		for (j = i; j > 0 && a[j - 1] > key; j--) {
			a[j] = a[j - 1];
		}
		a[j] = key;
	}
}

/**
 * 归并排序
 */
template <typename Comparable>
void MergeArray(vector<Comparable> &a, vector<Comparable> &tmp,
				int begin, int mid, int end) {
	// 合并 ator & btor 到 ctor
	int ator = begin;
	int btor = mid + 1;
	int ctor = begin;
	
	// 合并到临时空间
	while (ator <= mid && btor <= end) {
		tmp[ctor++] = a[ator] < a[btor] ? a[ator++] : a[btor++];
	}
	while (ator <= mid) {
		tmp[ctor++] = a[ator++];
	}
	while (btor <= end) {
		tmp[ctor++] = a[btor++];
	}
	// 保存合并后的内容
	for (int i = begin; i <= end; i++) {
		a[i] = tmp[i];
	}
}

template <typename Comparable>
void Merge(vector<Comparable> &a, vector<Comparable> &tmp,
		   int begin, int end) {
	int mid = (begin + end) / 2;
	if (begin < end) {
		// 左串分割
		Merge(a, tmp, begin, mid);
		// 右串分割
		Merge(a, tmp, mid + 1, end);
		// 合并左右子串
		MergeArray(a, tmp, begin, mid, end);
	}
}

template <typename Comparable>
void MergeSort(vector<Comparable> &a) {
	vector<Comparable> tmp(a.size());
	Merge(a, tmp, 0, (int)a.size() - 1);
	a = tmp;
}

/**
 * 快速排序
 */
template <typename Comparable>
void QuickInsertion(vector<Comparable> &a, int begin, int end) {
	int i, j, key;
	for (i = begin; i <= end; i++) {
		key = a[i];
		for (j = i; j > begin && a[j - 1] > key; j--) {
			a[j] = a[j - 1];
		}
		a[j] = key;
	}
}

template <typename Comparable>
int FindPivot(vector<Comparable> &a, int begin, int end) {
	int mid = (begin + end) / 2;
	if (a[begin] > a[end]) {
		swap(a[begin], a[end]);
	}
	if (a[mid] > a[end]) {
		swap(a[mid], a[end]);
	}
	if (a[begin] > a[mid]) {
		swap(a[begin], a[mid]);
	}
	swap(a[mid], a[end]);
	return end;
}

template <typename Comparable>
void Partion(vector<Comparable> &a, int begin, int end) {
	if (end - begin < 10) {
		int pivot = FindPivot(a, begin, end);
		int i = begin;
		int j = end - 1;

		while (true) {
			while (a[i] < a[pivot]) i++;
			while (a[j] > a[pivot]) j--;
				   
			if (i < j) swap(a[i], a[j]);
			else break;
		}
		
		swap(a[i], a[pivot]);
		Partion(a, begin, i-1);
		Partion(a, i+1, end);
	} else {
		QuickInsertion(a, begin, end);
	}
}

template <typename Comparable>
void QuickSort(vector<Comparable> &a) {
	Partion(a, 0, (int)a.size() - 1);
}

/**
 * 打印数组
 */
template <typename T>
void PrintArray(string info, const vector<T> &arr) {
	cout << info;
	for_each(begin(arr), end(arr), [](int v) { cout << v << " "; });
	cout << endl << endl;
}

/**
 * 创建一个排序测试单元
 */
void CreateTestUnit(function<void(vector<int> &)> sort) {
	vector<int> a(100);
	
	generate(begin(a), end(a), [] { return rand() % 100; });
	
	PrintArray("before: ", a);
	sort(a);
	PrintArray("sorted: ", a);

}

#endif // Data_Structure_sort_h
