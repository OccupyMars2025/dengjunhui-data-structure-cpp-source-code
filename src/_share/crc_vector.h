/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "Vector/Vector.h"

template <typename T> 
void crc ( Vector<T> & V ) { //统计向量的特征（所有元素之和）
   T crc = 0; 
   Crc<T> *visit = new Crc<T> ( crc );
   V.traverse ( *visit ); //以crc为基本操作进行遍历
   printf ( "total_sum =" ); print ( crc ); printf ( "\n" ); //输出统计得到的特征
}