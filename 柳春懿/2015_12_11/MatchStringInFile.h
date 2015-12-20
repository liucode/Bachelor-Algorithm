
/*
* Copyright (c) 2015,西工大科信软件有限责任公司
* All rights reserved.
*
* 文件名称：MatchStringInFile
* 摘    要：对指定文本文件检索指定的字符串，将结果输出到指定的文件中。
*
* 当前版本：1.1
* 作    者：尹盛
* 完成日期：2015年12月03日
*/

//宏定义
#define MAXSIZE 100 //字符串数组最大容量
#define ansyes 'y'
#define ansno  'n'

//引入头文件
#include <stdio.h>//c语言的标准输入输出
#include <stdlib.h>//包括部分宏定义
#include <malloc.h>//开辟空间头文件
#include <string.h>//字符串处理头文件
#include <ctype.h>//分类函数
#include <iostream>//c++标准输入输出

//以下为函数申明
/*
* Name        : GetTheNextArray
* Description : 为KMP算法得到下一个要匹配的模式串next[] 
* Parameters  : int *pnext            下一个模式串
                const char *pat       待查找的字符串
* Return      : value 0               获取失败
*               value 1               获取成功
*/

int GetNextArray(int *pnext, const char *pat);

/*
* Name        : KMP
* Description : 克努特——莫里斯——普拉特操作，改进的字符串匹配算法
* Parameters  : int *next            下一个模式串
                const char *pat      待查找的字符串
                char *text           文本串（待匹配的字符串）   
				int &cur             当前位置
* Return      : value 0              获取成功
*               value -1             获取失败
*               value -2             获取失败
*/
int KMP(int *pnext, char *text, const char *pat, int &cur);

/*
* Name        : Tolower
* Description : 字符转换成小写字母,非字母字符不做出处理
* Parameters  : char *str            指定字符
*/
void Tolower(char *str);

/*
* Name        : JudgeInput
* Description : 判定输入的命令是否正确有效。
* Parameters  : int argc             参数个数
                char **argv          存放参数的数组
                FILE *fp             待匹配的文件 
				FILE *fpout          结果写入的文件
* Return      : value 0              获取失败
*               value 1              获取成功
*/
int JudgeInput(int argc, char **argv, FILE *fp, FILE *fpout);

/*
* Name        : MatchKeyWordInText
* Description : 在文本中逐个逐行的进行指定字符的匹配。
* Parameters  : int *next            下一个模式串
                char *pat            待查找的字符串
                FILE *fp             待匹配的文件 
				FILE *fpout          结果写入的文件
				int Case_Sensitive   指定是否进行大小写区分的关键字
* Return      : value 0              获取失败
*               value -1             获取失败
*               value 1              获取成功
*/
int MatchKeyWordInText(int *pnext, char *pat, FILE *fp, FILE *fpout, int Case_Sensitive);