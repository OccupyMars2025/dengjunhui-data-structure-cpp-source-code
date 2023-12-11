/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "Vector/Vector.h"

//��e������[r]
template <typename T> 
Rank Vector<T>::insert ( Rank r, T const& e ) { //0 <= r <= size
   expand(); //���Ҫ��������
   for ( Rank i = _size; i > r; i-- ) //�Ժ���ǰ�����Ԫ��
      _elem[i] = _elem[i-1]; //˳�κ���һ����Ԫ
   _elem[r] = e; _size++; //������Ԫ�ز���������
   return r; //������
}

// template Rank Vector<int>::insert ( Rank r, int const& e );