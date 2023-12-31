/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> 
BinNodePosi<T>& Splay<T>::search( const T& e ) { //在伸展树中查找e
   BinNodePosi<T> p = BST<T>::search( e );
   this->_root = splay( p ? p : this->_hot ); //将最后一个被访问的节点伸展至根
   return this->_root;
} //与其它BST不同，无论查找成功与否，_root都指向最后被访问的节点