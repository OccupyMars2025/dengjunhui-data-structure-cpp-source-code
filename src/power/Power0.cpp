/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/
#include "power/Power.h"

// int64_t powerBF ( int64_t a, int n ) { //a^n�㷨�������棩��n >= 0
//    assert(a >= 2 && n >= 0);

//    int64_t pow = 1; //O(1)
//    while ( 0 < n ) { //O(n)
//       pow *= a; //O(1)
//       n--; //O(1)
//    }
//    return pow; //O(1)
// } //powerBF()

int64_t powerBF ( int64_t a, int n ) {
   int64_t pow = 1;
   while (n > 0)
   {
      pow *= a;
      --n;
   }
   return pow;
}
