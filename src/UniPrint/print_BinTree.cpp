/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "UniPrint/print.h"

/******************************************************************************************
 * �����������ӡ
 ******************************************************************************************/
#include "Bitmap/Bitmap.h" //ʹ��λͼ��¼��֧ת��

#define ROOT 0
#define L_CHILD 1
#define R_CHILD -1*L_CHILD

/******************************************************************************************
 * ����BinTree
 ******************************************************************************************/
template <typename T> //Ԫ������
void UniPrint::p ( BinTree<T> & bt ) { //����
   printf ( "[name]%s [address]%p [size]%d:\n", typeid ( bt ).name(), (void*) &bt, bt.size() ); //������Ϣ
   Bitmap* branchType = new Bitmap; //��¼��ǰ�ڵ����ȵķ���
   printBinTree ( bt.root(), -1, ROOT, branchType ); //��״�ṹ
   release ( branchType ); 
   printf ( "\n" );
}

// /******************************************************************************************
//  * ����BinTreeʵ�ֵ�BST
//  ******************************************************************************************/
// template <typename T> //Ԫ������
// void UniPrint::p ( BST<T> & bt ) { //����
//    printf ( "%s[%d]*%d:\n", typeid ( bt ).name(), (int) &bt, bt.size() ); //������Ϣ
//    Bitmap* branchType = new Bitmap; //��¼��ǰ�ڵ����ȵķ���
//    printBinTree ( bt.root(), -1, ROOT, branchType ); //��״�ṹ
//    release ( branchType ); printf ( "\n" );
// }

// /******************************************************************************************
//  * ����BSTʵ�ֵ�AVL
//  * ���е��õ�BinNode�Ĵ�ӡ���̣�������ʾBF״̬
//  ******************************************************************************************/
// template <typename T> //Ԫ������
// void UniPrint::p ( AVL<T> & avl ) { //����
//    printf ( "%s[%d]*%d:\n", typeid ( avl ).name(), (int) &avl, avl.size() ); //������Ϣ
//    Bitmap* branchType = new Bitmap; //��¼��ǰ�ڵ����ȵķ���
//    printBinTree ( avl.root(), -1, ROOT, branchType ); //��״�ṹ
//    release ( branchType ); printf ( "\n" );
// }

// /******************************************************************************************
//  * ����BSTʵ�ֵ�RedBlack
//  * ���е��õ�BinNode�Ĵ�ӡ���̣�������ʾBF״̬
//  ******************************************************************************************/
// template <typename T> //Ԫ������
// void UniPrint::p ( RedBlack<T> & rb ) { //����
//    printf ( "%s[%d]*%d:\n", typeid ( rb ).name(), (int) &rb, rb.size() ); //������Ϣ
//    Bitmap* branchType = new Bitmap; //��¼��ǰ�ڵ����ȵķ���
//    printBinTree ( rb.root(), -1, ROOT, branchType ); //��״�ṹ
//    release ( branchType ); printf ( "\n" );
// }

// /******************************************************************************************
//  * ����BSTʵ�ֵ�Splay
//  * ����Splay��������bf֮��ĸ��ӱ�ʶ�����ӡ������BST��ȫһ��
//  ******************************************************************************************/
// template <typename T> //Ԫ������
// void UniPrint::p ( Splay<T> & bt ) { //����
//    printf ( "%s[%d]*%d:\n", typeid ( bt ).name(), (int) &bt, bt.size() ); //������Ϣ
//    Bitmap* branchType = new Bitmap; //��¼��ǰ�ڵ����ȵķ���
//    printBinTree ( bt.root(), -1, ROOT, branchType ); //��״�ṹ
//    release ( branchType ); printf ( "\n" );
// }

/******************************************************************************************
 * �����������������ͳһ��ӡ
 * node->rc  =>  node  =>  node->lc
 ******************************************************************************************/
template <typename T> //Ԫ������
static void printBinTree ( BinNodePosi<T> bt, int depth, int type, Bitmap* bType ) {
   if ( !bt ) return;
   if ( -1 < depth ) //���õ�ǰ��Ĺ����־
      (R_CHILD == type) ? bType->set ( depth ) : bType->clear ( depth );
   // getchar();
   printBinTree ( bt->rc, depth + 1, R_CHILD, bType ); //�����������ϣ�
   print ( bt ); printf ( " *" );
   for ( int i = -1; i < depth; i++ ) {//�������ڸ���
      if ( ( 0 > i ) || bType->test ( i ) == bType->test ( i + 1 ) ) //�Ĺ����Ƿ�һ�£�����ȷ��
         printf("        "); //�Ƿ�Ӧ��
      else  
         // printf ( "��    " ); //��ӡ����
         printf("|       ");
   }
   switch ( type ) {
      case  R_CHILD  :  
         // printf ( "����" ); 
         printf("|``");
         break;
      case  L_CHILD  :  
         // printf ( "����" );  
         printf("|__");
         break;
      default:  
         // printf ( "����" );  
         printf("---");
         break; //root
   }
   print ( bt );
#if defined(DSA_HUFFMAN)
   if ( IsLeaf ( *bt ) ) bType->print ( depth + 1 ); //���Huffman����
#endif
   printf ( "\n" );
   // getchar();
   printBinTree ( bt->lc, depth + 1, L_CHILD, bType ); //�����������£�
}