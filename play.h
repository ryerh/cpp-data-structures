//
//  play.h
//  Data Structure
//
//  Created by ryer on 5/5/15.
//  Copyright (c) 2015 ryer. All rights reserved.
//

#ifndef Data_Structure_play_h
#define Data_Structure_play_h

long fibonacci(long n) {
	//assert(n < 0);
	if(n < 2) {
		return n;
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

long gcd(long m, long n) {
	if (m == n) {
		return m;
	} else if (m > n) {
		return gcd(m - n, n);
	} else {
		return gcd(m, n - m);
	}
}

#endif
