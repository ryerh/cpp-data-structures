//
//  dac.h —— 分治算法
//  Data Structure
//
//  Created by ryer on 5/8/15.
//  Copyright (c) 2015 ryer. All rights reserved.
//

#ifndef Data_Structure_dac_h
#define Data_Structure_dac_h

#include <iostream>
#include <tuple>
#include "utilities.h"
using namespace std;

/**
 * 最大子序列和
 */
tuple<int,int,int> find_max_crossing_subarray(const IntArray &a, size_t begin, size_t end) {
	int lsum = INT_MIN;
	int rsum = INT_MIN;
	int sum = 0;
	size_t lmax = 0;
	size_t rmax = 0;
	size_t mid = (begin + end) / 2;
	size_t i;
	
	for (i = mid, sum = 0; i >= begin; i--) {
		sum += a[i];
		if (sum > lsum) {
			lsum = sum;
			lmax = i;
		} else {
			break;
		}
	}
	
	for (i = mid, sum = 0; i < end; i++) {
		sum += a[i];
		if (sum > rsum) {
			rsum = sum;
			rmax = i;
		} else {
			break;
		}
	}
	
	return make_tuple(lmax, rmax, lsum + rsum);
}

#endif
