/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "Bitmap/Bitmap.h"
#include <cassert>

Rank primeNLT( Rank low, Rank n, const char* file ) { //根据file文件中的记录，在[low, n)内取最小的素数
   assert((low >= 0));
   Bitmap B( file, n ); // file已经按位图格式记录了[0, n)的所有素数，因此只要
   while ( low < n ) {//从 low 开始，逐位地
      if ( B.test( low ) ) low++; //测试，即可
      else return low; //返回首个发现的素数
   }
   return -1;
   // return low; //若没有这样的素数，返回n（实用中不能如此简化处理）
}
