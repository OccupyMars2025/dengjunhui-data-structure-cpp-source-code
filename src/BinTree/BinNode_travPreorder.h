/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "Stack/Stack.h" //引入栈模板类
#include "BinNode_travPreorder_R.h"
#include "BinNode_travPreorder_I1.h"
#include "BinNode_travPreorder_I2.h"

template <typename T> template <typename VST> //元素类型、操作器
void BinNode <T>::travPre( VST& visit, int algorithm_id ) { //二叉树先序遍历算法统一入口
   // switch ( rand() % 3 ) { //此处暂随机选择以做测试，共三种选择
   switch(algorithm_id){
      case 0 : 
         travPre_R( this, visit ); 
         break; //递归版
      case 1 : 
         travPre_I1( this, visit ); 
         break; //迭代版#1
      case 2 : 
         travPre_I2( this, visit ); 
         break; //迭代版#2
      default : 
         assert(0);
         break;
   }
}
