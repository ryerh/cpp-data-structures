//
//  DecimalConverter.h
//  Data Structure
//
//  Created by ryer on 15/6/21.
//  Copyright (c) 2015年 ryer. All rights reserved.
//

#ifndef Data_Structure_DecimalConverter_h
#define Data_Structure_DecimalConverter_h


//
//  main.cpp
//
//  实现一个 C++ 类，用于实现 10 进制数与 N 进制数之间的相互转换，
//  N 为 2-36，当某位上的值大于 9 时，约定 A 表示 10，……，Z 表示 35。
//

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;

/**
 * 十进制数类
 */
class Decimal
{
public:
	/**
	 * 构造函数
	 */
	Decimal()
	{
		char i;
		// num_map 保存 '0' ~ '9', 'a' ~ 'z'
		for (i = '0'; i <= '9'; i++)
			num_map.push_back(i);
		for (i = 'a'; i <= 'z'; i++)
			num_map.push_back(i);
		value = INT_MIN;
	}
	
	/**
	 * 任意进制转十进制
	 */
	int ParseFrom(string from, int n)
	{
		assert(n >= 2 && n <= 36);
		value = 0;
		int len = (int)from.size();
		// 基于指数运算计算十进制值
		for(int i = len - 1; i >= 0; i--)
		{
			char digit = from[i];
			int number = (digit <= '9') ? digit - '0' : digit - 'a' + 10;
			value += number * pow(n, len - i - 1);
		}
		return value;
	}
	
	/**
	 * 十进制转任意进制，递归驱动函数
	 */
	string ConvertTo(int n)
	{
		assert(n >= 2 && n <= 36);
		// 除数取余法计算任意进制，利用 num_map 转换 10 ~ 35 的数字为 'a' ~ 'z'
		vector<int> tmp;
		string ret = "";
		convert(tmp, value, n);
		
		for(size_t i = 0, len = tmp.size(); i < len; i++)
			ret += num_map[tmp[i]];
		
		return ret;
	}
	
	/**
	 * 重载 = 运算符
	 */
	void operator=(int n)
	{
		value = n;
	}
	
private:
	/**
	 * 十进制转任意进制，递归函数
	 */
	void convert(vector<int> &vec, int value, int n)
	{
		int s = value / n;
		int y = value % n;
		vec.insert(vec.begin(), y);
		if(s >= n)
			convert(vec, s, n);
		else if(s != 0)
			vec.insert(vec.begin(), s);
	}
	
	/**
	 * 输出一个 Decimal 对象的 value 值的友元函数
	 */
	friend ostream & operator<<(ostream &out, const Decimal &dec);
	
	vector<char> num_map;
	int value;
};

ostream & operator<<(ostream &out, const Decimal &dec)
{
	out << dec.value;
	return out;
}

int test_main(int argc, const char * argv[]) {
	// 创建一个 10 进制数类 Decimal 的对象
	Decimal dec_number;
	
	// 16 进制 “123d687” 转换为 10 进制
	dec_number.ParseFrom("12d687", 16);
	cout << dec_number << endl; // 输出：1234567
	
	// 10 进制 1234567 转换为 16 进制
	dec_number = 1234567;
	cout << dec_number.ConvertTo(16); // 输出：12d687
	
	return 0;
}


#endif
