/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "Queue/Queue.h" //引入队列


// template <typename T> template <typename VST> //元素类型、操作器
// void BinNode<T>::travLevel( VST& visit ) { //二叉树层次遍历算法
//    printf("travLevel\n");
   
//    Queue<BinNodePosi<T>> Q; 
//    Q.enqueue( this ); //引入辅助队列，根节点入队

//    while ( !Q.empty() ) { //在队列再次变空之前，反复迭代
//       BinNodePosi<T> x = Q.dequeue(); 
//       visit( x->data ); //取出队首节点并访问之
//       if ( HasLChild( *x ) ) Q.enqueue( x->lc ); //左孩子入队
//       if ( HasRChild( *x ) ) Q.enqueue( x->rc ); //右孩子入队
//    }
// }


template <typename T> template <typename VST>
void BinNode<T>::travLevel(VST& visit) {
   Queue<BinNodePosi<T>> queue;
   queue.enqueue(this);
   BinNodePosi<T> x;

   while (!queue.empty())
   {
      x = queue.dequeue();
      visit(x->data);
      if(x->lc) {
         queue.enqueue(x->lc);
      }
      if(x->rc){
         queue.enqueue(x->rc);
      }
   }
   
}