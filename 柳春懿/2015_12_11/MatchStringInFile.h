
/*
* Copyright (c) 2015,�������������������ι�˾
* All rights reserved.
*
* �ļ����ƣ�MatchStringInFile
* ժ    Ҫ����ָ���ı��ļ�����ָ�����ַ���������������ָ�����ļ��С�
*
* ��ǰ�汾��1.1
* ��    �ߣ���ʢ
* ������ڣ�2015��12��03��
*/

//�궨��
#define MAXSIZE 100 //�ַ��������������
#define ansyes 'y'
#define ansno  'n'

//����ͷ�ļ�
#include <stdio.h>//c���Եı�׼�������
#include <stdlib.h>//�������ֺ궨��
#include <malloc.h>//���ٿռ�ͷ�ļ�
#include <string.h>//�ַ�������ͷ�ļ�
#include <ctype.h>//���ຯ��
#include <iostream>//c++��׼�������

//����Ϊ��������
/*
* Name        : GetTheNextArray
* Description : ΪKMP�㷨�õ���һ��Ҫƥ���ģʽ��next[] 
* Parameters  : int *pnext            ��һ��ģʽ��
                const char *pat       �����ҵ��ַ���
* Return      : value 0               ��ȡʧ��
*               value 1               ��ȡ�ɹ�
*/

int GetNextArray(int *pnext, const char *pat);

/*
* Name        : KMP
* Description : ��Ŭ�ء���Ī��˹���������ز������Ľ����ַ���ƥ���㷨
* Parameters  : int *next            ��һ��ģʽ��
                const char *pat      �����ҵ��ַ���
                char *text           �ı�������ƥ����ַ�����   
				int &cur             ��ǰλ��
* Return      : value 0              ��ȡ�ɹ�
*               value -1             ��ȡʧ��
*               value -2             ��ȡʧ��
*/
int KMP(int *pnext, char *text, const char *pat, int &cur);

/*
* Name        : Tolower
* Description : �ַ�ת����Сд��ĸ,����ĸ�ַ�����������
* Parameters  : char *str            ָ���ַ�
*/
void Tolower(char *str);

/*
* Name        : JudgeInput
* Description : �ж�����������Ƿ���ȷ��Ч��
* Parameters  : int argc             ��������
                char **argv          ��Ų���������
                FILE *fp             ��ƥ����ļ� 
				FILE *fpout          ���д����ļ�
* Return      : value 0              ��ȡʧ��
*               value 1              ��ȡ�ɹ�
*/
int JudgeInput(int argc, char **argv, FILE *fp, FILE *fpout);

/*
* Name        : MatchKeyWordInText
* Description : ���ı���������еĽ���ָ���ַ���ƥ�䡣
* Parameters  : int *next            ��һ��ģʽ��
                char *pat            �����ҵ��ַ���
                FILE *fp             ��ƥ����ļ� 
				FILE *fpout          ���д����ļ�
				int Case_Sensitive   ָ���Ƿ���д�Сд���ֵĹؼ���
* Return      : value 0              ��ȡʧ��
*               value -1             ��ȡʧ��
*               value 1              ��ȡ�ɹ�
*/
int MatchKeyWordInText(int *pnext, char *pat, FILE *fp, FILE *fpout, int Case_Sensitive);