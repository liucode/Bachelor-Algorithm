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

#include "MatchStringInFile.h"
/*
* Name        : GetTheNextArray
* Description : ΪKMP�㷨�õ���һ��Ҫƥ���ģʽ��next[] 
* Parameters  : int *pnext            ��һ��ģʽ��
                const char *pat       �����ҵ��ַ���
* Return      : value 0               ��ȡʧ��
*               value 1               ��ȡ�ɹ�
*/

int GetNextArray(int *pnext, const char *pat)
{
	int len = strlen(pat);
	int k = 0;
	
    if (len < 1)
    {
        printf("ģʽ������Ϊ0!\n");
        return 0;
    }
	
    pnext[0] = -1;
    pnext[1] = 0;
	
    for (int i = 2; i <= len; i++)
    {
        while (k >= 0 && pat[i-1] != pat[k])
		{
			k = pnext[k];
			pnext[i] = ++k;
		}
    }
	
    return 1;
}

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

int KMP(int *pnext, char *text, const char *pat, int &cur)
{
    int len_pat = strlen(pat);
    int len_text = strlen(text);
	
	if (len_pat < 1 || len_text < 1 || len_text < len_pat)
    {
		return -1;
	}
	
	int j = 0;
	
    while (cur < len_text)
    {
		/*ƥ��ɹ�ָ�����*/
        if (j == -1 || pat[j] == text[cur])
		{
            cur++;
            j++;
        }
        else
		{
			j = pnext[j];
		}
        if (j == len_pat)
		{
			return cur - j;
		}
    }
	
    return -2;
}                                          

/*
* Name        : Tolower
* Description : �ַ�ת����Сд��ĸ,����ĸ�ַ�����������
* Parameters  : char *str            ָ���ַ�
*/

void Tolower(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
	{   /*����ϵͳ����tolower����*/
        str[i] = tolower(str[i]);
	}
}             

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

int JudgeInput(int argc, char **argv, FILE *fp, FILE *fpout)
{
	/*������������в�������4�����˳�*/
    if (argc != 4)
    {
        printf("�����ʽ����!\n");
        printf("����������ļ������ַ���������ļ���\n");
        return -1;
    }
	
	fp = fopen(argv[1], "r");
	
	/*��������ļ������ڣ��˳�*/
    if (fp == NULL)
    {
        printf("�����ļ������ڣ�\n");
        return -2;
    }
	
    int pat_len = strlen(argv[2]);
	
	/*����ַ����ĳ��ȴ���80���˳�*/
	if (pat_len > 80)
	{
        printf("�������ַ������Ȳ��ܳ���80!\n");
        return -3;
    }
	
	/*����ַ����������ַ����˳�*/
    for (int i = 0; i < pat_len; i++)
    {
        if (argv[2][i] < 0)
        {
            printf("�ַ���������ascii�ַ�!\n");
            return -4;
        }
    }                                 
	
	char *pthparameter = argv[3];

    fpout = fopen(pthparameter, "w+");
	
	/*�������ļ�δ�򿪣��˳�*/
    if (fpout == NULL)
    {
        printf("����ļ�δ�򿪣�\n");
        return -5;
    }
	
    fclose (fp);
    fclose (fpout);
    return 1;
	
}                                   

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

int MatchKeyWordInText(int *pnext, char *pat, FILE *fp, FILE *fpout, int Case_Sensitive)
{
    int line = 0;
    int find_sum = 0;
	/*����һ��100��char��С�Ŀռ䣬����������ݷŽ�����*/
    char *text = (char*)malloc(MAXSIZE*sizeof(char));
	
	if (text == NULL)
	{
		return -1;
	}
	
    int length = MAXSIZE;
    if (fp == NULL || fpout == NULL)
	{
		return -2;
	}
	
	/*ÿ�δ������ı���ȡһ���ַ���һֱ���ļ�β*/
    while (!feof(fp))
    {
        memset(text, 0, sizeof(text));
        line++;
		/*�����һ���Ƿ�ƥ��ɹ�����ʼ��Ϊ0*/
        int is_find = 0;
        int i = 0;	
		/*ch != -1Ϊ����ļ������᷵��һ��-1����Ȼ���һ�п��ܻ��ȡ����*/
        char ch;
		/*��ȡһ���ַ�������ӵ�text������ �������������̬�����ڴ�*/
        while (!feof(fp) && (ch = fgetc(fp)) != '\n' && ch != -1) 
		{
            text[i++] = ch;
			
            if (i >= length)
            {

                char *newbase = (char*)realloc(text,(length+20)*sizeof(char));
                if (!newbase) 
				{
                    printf("�����ڴ�ʧ�ܣ�\n");
                    fputs("�����ڴ�ʧ�ܣ�\n", fpout);
                    return -3;
                }
                text = newbase;      
				length += 20;				
            }
        }

		 text[i++] = '\0';
		 //puts(text);
		if (!Case_Sensitive)
		{
			Tolower(text);
		}

		/*����һ�н���ƥ��*/
        int text_len = strlen(text);	
        i = 0;			
		
        while (i < text_len)
        {
            int re;
			
            if ((re = KMP(pnext, text, pat, i)) >= 0)
            {
                is_find = 1;
                find_sum++;				
                printf("�ڵ�%d�е�%d��ƥ��ɹ�.\n", line, re+1);
                fprintf(fpout, "�ڵ�%d�е�%d��ƥ��ɹ�.\n", line, re+1);
            }
        }
		
        if (is_find)
        {
            fprintf(fpout, "��%d�е�����Ϊ��\n", line);
            fputs(text, fpout);
            fputc('\n', fpout);
            fputc('\n', fpout);
        }	
		fprintf(fpout,"-----------------------next--line----------------------------\n");
    }
	
    printf("ƥ��ɹ�����Ϊ%d.\n", find_sum);
    fprintf(fpout, "ƥ��ɹ�����Ϊ%d��\n", find_sum);
	
	free(text);
	text = NULL;
	return 1; 
}                                           

# define ansyes 'y'
# define ansno  'n'

int main(int argc,char **argv)
{
    FILE *fp, *fpout;

	/*�ж������ʽ�Ƿ���ȷ*/
    if (!JudgeInput(argc, argv, fp, fpout))
    {
		exit(-1);
	}
	
    fp = fopen(argv[1], "r");
    fpout = fopen(argv[3], "w+");
	
    if (fp == NULL || fpout == NULL)
	{
		return 0;
	}

	/* �ж��Ƿ���Ҫ���ִ�Сд*/
    char ans[MAXSIZE];
    int Case_Sensitive = -1;
    printf("�Ƿ����ִ�Сд?������(y\\n):\n");
    scanf("%s", ans);
    
	if (strlen(ans) != 1 || ((ans[0] != ansyes) && (ans[0] != ansno)))
    {
        printf("�����ʽ����\n");
        exit(-2);
    }
    else if (ans[0] == ansyes) 
	{
        Case_Sensitive = 1;
        puts("���ִ�Сд��\n");
    }
    else
	{
        Case_Sensitive = 0;
        puts("�����ִ�Сд��\n");
    }
	
    int pat_len = strlen(argv[2]);
    char *pat = (char*)malloc((pat_len+1)*sizeof(char));
    strncpy(pat,argv[2], pat_len);
    pat[pat_len] = '\0';
	
    if (!Case_Sensitive)
	{
        Tolower(pat);
	}
	
    int *pnext = (int*)malloc((pat_len+1)*sizeof(int));
	
	if (pnext == NULL)
	{
		return -1;
	}
	else
	{
		GetNextArray(pnext, pat);
	}
	
	/*�ı�����*/
    if (!MatchKeyWordInText(pnext, pat, fp, fpout, Case_Sensitive))
    {
		exit(-2);
	}	
    
	free(pat);
	pat = NULL;
	free(pnext);
	pnext = NULL;
	
    fclose(fp);
    fclose(fpout);
    return 0;
}
