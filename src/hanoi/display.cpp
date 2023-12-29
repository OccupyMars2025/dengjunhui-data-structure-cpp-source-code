/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "hanoi/hanoi.h"

/******************************************************************************************
 * ���ջS�ڸ߶�i�ķֲ�
 ******************************************************************************************/
void display ( Stack<Disk>& S, Rank i ) {
   Rank diskR = ( i < S.size() && i >= 0 ) ? S[i] : 0; //ͨ��Vecotr[]�ӿڣ���ȡ�߶�i�����ӵİ뾶
   for ( Rank j = 0; j < nDisk - diskR; j++ )   printf ( " " );
   for ( Rank j = 0; j < diskR; j++ )    printf ( "=" );
   printf ( "|" );
   for ( Rank j = 0; j < diskR; j++ )    printf ( "=" );
   for ( Rank j = 0; j < nDisk - diskR; j++ )   printf ( " " );
}

/******************************************************************************************
 * ��ʾ����ջ���ݣ�ʹ��ȫ�ֱ�����
 ******************************************************************************************/
void displayHanoi() {
   // system ( "clear" );   
   printf ( "\n\n" );
   for ( int i = nDisk - 1; i >= 0; i-- ) //�Զ����£���ÿһ�߶Ȳ�Σ���������ࣩ��������
   { 
      display ( Sx, i ); 
      display ( Sy, i ); 
      display ( Sz, i ); 
      printf ( "\n" ); 
   }
   for ( int j = 0; j < 3 * ( 2 * nDisk + 1 ); j++ )   printf ( "=" );   printf ( "\n" ); //��ʾ����
   getchar();
}