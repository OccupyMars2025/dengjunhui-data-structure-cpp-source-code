/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "List/List.h"

template <typename T> 
void checkOrder( List<T>& L ) { //判断列表是否整体有序
   int nInv = 0; //逆序计数器
   CheckOrder<T> *visitor = new CheckOrder<T>( nInv, L.first()->data );
   L.traverse( *visitor ); //进行遍历
   if ( 0 < nInv )
      printf( "Unsorted with %d adjacent inversion(s)\n", nInv );
   else
      printf( "Sorted\n" );
}