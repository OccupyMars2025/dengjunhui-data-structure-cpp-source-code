/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "power/Power.h"

// inline int64_t sqr ( int64_t a ) { return a * a; } //平方：若是连续执行，很快就会数值溢出！

// int64_t power2 ( int n ) { //幂函数2^n算法（优化递归版），n >= 0
//    assert(n >= 0);

//    if ( 0 == n ) return 1; //递归基；否则，视n的奇偶分别递归
//    return ( n & 1 ) ? (sqr ( power2 ( n >> 1 ) ) << 1) : (sqr ( power2 ( n >> 1 ) ));
// } //O(logn) = O(r)，r为输入指数n的比特位数


int64_t power2 (int n) {
   if(n <= 0){
      return 1;
   }

   int64_t temp = power2(n >> 1);
   if(1 & n) {
      return (temp * temp) << 1;
   } else {
      return (temp * temp);
   }
}