/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "queen_stack.h"

Rank N = 0; //���̴�С

void displayRow ( Queen& q ) { //��ӡ��ǰ�ʺ󣨷�����col�У�������
   printf ( "%2d: ", q.x );
   Rank i = 0;
   while ( i++ < q.y ) { 
      printf ( "[ ]" );
   }
   printf ( "[x]" );
   while ( i++ < N ) {
      printf ( "[ ]" );
   }
   printf ( "%2d\n", q.y );
}

void displayProgress ( Stack<Queen>& S, Rank nQueen ) { //����������ʾ�Ѳ�Ľ�չ
   system ( "clear" );
   N = nQueen; 
   S.traverse ( displayRow );
   if ( nQueen <= S.size() ) {
      cout  << nSolu << " solution(s) found after " << nCheck << " check(s)\a";
      getchar();
   }
}