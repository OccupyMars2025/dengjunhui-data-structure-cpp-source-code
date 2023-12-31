/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

//通过zag旋转调整，将BST子树x拉伸成最左侧通路
template <typename T> 
void stretchByZag( BinNodePosi<T>& x ) {
   int c = 0; //记录旋转次数
   BinNodePosi<T> p = x; 
   while ( p->rc ) p = p->rc; //最大节点，必是子树最终的根
   while ( x->lc ) x = x->lc; //转至初始最左侧通路的末端
   for ( ; x != p; x = x->parent ) { //若x右子树已空，则上升一层
      while ( x->rc ) //否则，反复地
      {
         x->zag(); //以x为轴做zag旋转
         c++;
      }
   } //直到抵达子树的根
   
   printf ( "\nsize = %d, height = %d, #zag = %d\n\n", x->size(), x->height, c );
}
