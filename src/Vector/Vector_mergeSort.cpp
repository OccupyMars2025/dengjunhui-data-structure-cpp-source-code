/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "Vector/Vector.h"

//�����鲢���� [lo, hi)
template <typename T> 
void Vector<T>::mergeSort( Rank lo, Rank hi ) { // 0 <= lo < hi <= size
   /*DSA*/ 
   printf ( "\tVector<T>::mergeSort [%3d, %3d)\n", lo , hi );
   if ( hi - lo < 2 ) return; //��Ԫ��������Ȼ���򣬷���...
   Rank mi = ( lo + hi ) / 2; //���е�Ϊ��
   mergeSort( lo, mi ); mergeSort( mi, hi ); //ǰ׺����׺�ֱ�����
   merge( lo, mi, hi ); //�鲢
}