/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once


// template <typename T> 
// int Vector<T>::dedup() { //删除无序向量中重复元素（错误版）
//    int oldSize = _size; //记录原规模
//    for ( Rank i = 1; i < _size; i++ ) { //逐一考查_elem[i]
//       Rank j = find ( _elem[i], 0, i ); //在_elem[i]的前驱中寻找与之雷同者（至多一个）
//       if ( 0 <= j ) remove ( j ); //若存在，则删除之（但在此种情况，下一迭代不必做i++）
//    }
//    return oldSize - _size; //向量规模变化量，即被删除元素总数
// }



template <typename T> 
int Vector<T>::dedup() {
    printf("src/Vector/Vector_deduplicate_2.h\n");
    
    Rank oldSize = _size;
    for(Rank i = 1; i < _size;) {
        int index_of_duplicate = find(_elem[i], 0, i);
        if(index_of_duplicate >= 0) {
            remove(index_of_duplicate);
        } else {
            ++i;
        }
    }

    return oldSize - _size;
}