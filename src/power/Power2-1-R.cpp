/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "power/Power.h"

inline int64_t sqr ( int64_t a ) { return a * a; } //ƽ������������ִ�У��ܿ�ͻ���ֵ�����

int64_t power2 ( int n ) { //�ݺ���2^n�㷨���Ż��ݹ�棩��n >= 0
   assert(n >= 0);

   if ( 0 == n ) return 1; //�ݹ����������n����ż�ֱ�ݹ�
   return ( n & 1 ) ? (sqr ( power2 ( n >> 1 ) ) << 1) : (sqr ( power2 ( n >> 1 ) ));
} //O(logn) = O(r)��rΪ����ָ��n�ı���λ��