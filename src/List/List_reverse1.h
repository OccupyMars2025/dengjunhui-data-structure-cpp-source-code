/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> 
void List<T>::reverse() { //前后倒置
   ListNodePosi<T> p = header; ListNodePosi<T> q = trailer; //头、尾节点
   for ( Rank i = 2; i <= _size; i += 2 ) //（从首、末节点开始）由外而内，捉对地
      swap( ( p = p->succ )->data, ( q = q->pred )->data ); //交换对称节点的数据项
}



// template <typename T> 
// void List<T>::reverse() { //前后倒置
//    if(_size < 2) return;

//    for(ListNodePosi<T> p1 = header->succ, p2 = trailer->pred;  p1 != p2; p1 = p1->succ, p2 = p2->pred) {
//       swap(p1->data, p2->data);
//    }
// }