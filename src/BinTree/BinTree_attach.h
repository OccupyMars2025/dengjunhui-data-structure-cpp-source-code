/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //将S当作节点x的左子树接入二叉树，S本身置空
BinNodePosi<T> BinTree<T>::attachAsLeftSubtree( BinNodePosi<T> x, BinTree<T>*& S) { // x->lc == NULL
   if ( x->lc = S->_root ) {
      x->lc->parent = x; //接入
   }
   _size += S->_size; 
   updateHeightAbove( x ); //更新全树规模与x所有祖先的高度(include x)
   
   S->_root = NULL; 
   S->_size = 0; 
   release( S ); 
   S = NULL; 
   return x; //释放原树，返回接入位置
}

template <typename T> // 将S当作节点x的右子树接入二叉树，S本身置空
BinNodePosi<T> BinTree<T>::attachAsRightSubtree( BinNodePosi<T> x, BinTree<T>*& S ) { // x->rc == NULL
   if ( x->rc = S->_root ) {
      x->rc->parent = x; //接入
   }
   _size += S->_size; 
   updateHeightAbove( x ); //更新全树规模与x所有祖先的高度
   
   S->_root = NULL; 
   S->_size = 0; 
   release( S ); 
   S = NULL; 
   return x; //释放原树，返回接入位置
}
