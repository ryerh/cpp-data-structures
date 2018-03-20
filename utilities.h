//
//  utilities.h
//  Data Structure
//
//  Created by ryer on 5/8/15.
//  Copyright (c) 2015 ryer. All rights reserved.
//

#ifndef Data_Structure_utilities_h
#define Data_Structure_utilities_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int> IntArray;
typedef vector<int>::iterator IntAtor;
typedef vector<int>::const_iterator CIntAtor;

const string SPACE = " ";

template <typename Printable>
void echo(const vector<Printable> &a) {
	for (auto i : a) {
		cout << i << SPACE;
	}
	cout << endl;
}

void gswap(void *pa, void *pb, size_t size) {
	char buffer[size];
	memcpy(buffer, pa, size);
	memcpy(pa, pb, size);
	memcpy(pb, buffer, size);
}

int maximum(const int *arr, const int n) {
	assert(arr != NULL);
	int cmp = 0;
	int *pa = (int *)arr;
	
	if (n < 1) {
		return INT32_MIN;
	} else if (n == 1) {
		return *pa;
	} else {
		cmp = maximum(pa + 1, n - 1);
		if (*pa > cmp) {
			return *pa;
		} else {
			return cmp;
		}
	}
}

void str_reverse(const char *s, char *dst, const int n) {
	if (n < 1) {
		*dst = '\0';
	} else {
		*dst = *(s + n - 1);
		str_reverse(s, dst + 1, n - 1);
	}
}

#endif
