/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

// #define POW(c) (1 << (c)) //2^c
// #define MASK(c) (((unsigned long) -1) / (POW(POW(c)) + 1)) //以2^c位为单位分组，相间地全0和全1
// // MASK(0) = 55555555(h) = 01010101010101010101010101010101(b)
// // MASK(1) = 33333333(h) = 00110011001100110011001100110011(b)
// // MASK(2) = 0f0f0f0f(h) = 00001111000011110000111100001111(b)
// // MASK(3) = 00ff00ff(h) = 00000000111111110000000011111111(b)
// // MASK(4) = 0000ffff(h) = 00000000000000001111111111111111(b)

// //输入：n的二进制展开中，以2^c位为单位分组，各组数值已经分别等于原先这2^c位中1的数目
// #define ROUND(n, c) (((n) & MASK(c)) + ((n) >> POW(c) & MASK(c))) //运算优先级：先右移，再位与
// //过程：以2^c位为单位分组，相邻的组两两捉对累加，累加值用原2^(c + 1)位就地记录
// //输出：n的二进制展开中，以2^(c + 1)位为单位分组，各组数值已经分别等于原先这2^(c + 1)位中1的数目

// int countOnes2 ( unsigned int n ) { //统计整数n的二进制展开中数位1的总数
//    n = ROUND ( n, 0 ); //以02位为单位分组，各组内前01位与后01位累加，得到原先这02位中1的数目
//    n = ROUND ( n, 1 ); //以04位为单位分组，各组内前02位与后02位累加，得到原先这04位中1的数目
//    n = ROUND ( n, 2 ); //以08位为单位分组，各组内前04位与后04位累加，得到原先这08位中1的数目
//    n = ROUND ( n, 3 ); //以16位为单位分组，各组内前08位与后08位累加，得到原先这16位中1的数目
//    n = ROUND ( n, 4 ); //以32位为单位分组，各组内前16位与后16位累加，得到原先这32位中1的数目
//    return n; //返回统计结果
// } //32位字长时，O(log_2(32)) = O(5) = O(1)


// ============== Just write it again by hand ===================

// /**
// MASK(0) = 01010101010101010101010101010101(b) 
// MASK(1) = 00110011001100110011001100110011(b)
// MASK(2) = 00001111000011110000111100001111(b)
// MASK(3) = 00000000111111110000000011111111(b)
// MASK(4) = 00000000000000001111111111111111(b)
// */
// int countOnes2(unsigned int n) {
//    n = n & MASK(0) + (n >> 1) & MASK(0);
//    n = n & MASK(1) + (n >> 2) & MASK(1);
//    n = n & MASK(2) + (n >> 4) & MASK(2);
//    n = n & MASK(3) + (n >> 8) & MASK(3);
//    n = n & MASK(4) + (n >> 16) & MASK(4);

//    return n;
// }


// /*
// Caution: add enough () to the macro definition
// 1. add the outest () to the definition of MASK(c)
// 2. add an outer () to "(n) & MASK(c)"
// */
// #define POW(c) (1 << (c))
// #define MASK(c) (((unsigned int) -1) / (POW(POW(c)) + 1))
// #define ROUND(n, c) (((n) & MASK(c)) + (((n) >> POW(c)) & MASK(c)))

// int countOnes2(unsigned int n) {
//    n = ROUND(n, 0);
//    n = ROUND(n, 1);
//    n = ROUND(n, 2);
//    n = ROUND(n, 3);
//    n = ROUND(n, 4);

//    return n;
// }


/*
MASK(0) = 01010101010101010101010101010101
MASK(1) = 00110011001100110011001100110011
MASK(2) = 00001111000011110000111100001111
MASK(3) = 00000000111111110000000011111111
MASK(4) = 00000000000000001111111111111111
*/

// int countOnes2(unsigned int n) {
//    n = (n & MASK(0)) + ((n >> 1) & MASK(0));
//    n = (n & MASK(1)) + ((n >> 2) & MASK(1));
//    n = (n & MASK(2)) + ((n >> 4) & MASK(2));
//    n = (n & MASK(3)) + ((n >> 8) & MASK(3));
//    n = (n & MASK(4)) + ((n >> 16) & MASK(4));
//    return n;
// }

#define POW2(x) (1 << (x))
#define MASK(x) (((unsigned int)-1)/(POW2(POW2(x)) + 1))
#define ROUND(n, i) (((n) & MASK(i)) + (((n) >> POW2(i)) & MASK(i)))

int countOnes2(unsigned int n) {
   n = ROUND(n, 0);
   n = ROUND(n, 1);
   n = ROUND(n, 2);
   n = ROUND(n, 3);
   n = ROUND(n, 4);

   return n;
}