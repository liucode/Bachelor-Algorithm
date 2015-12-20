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

#include "MatchStringInFile.h"
/*
* Name        : GetTheNextArray
* Description : 为KMP算法得到下一个要匹配的模式串next[] 
* Parameters  : int *pnext            下一个模式串
                const char *pat       待查找的字符串
* Return      : value 0               获取失败
*               value 1               获取成功
*/

int GetNextArray(int *pnext, const char *pat)
{
	int len = strlen(pat);
	int k = 0;
	
    if (len < 1)
    {
        printf("模式串长度为0!\n");
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
* Description : 克努特——莫里斯——普拉特操作，改进的字符串匹配算法
* Parameters  : int *next            下一个模式串
                const char *pat      待查找的字符串
                char *text           文本串（待匹配的字符串）   
				int &cur             当前位置
* Return      : value 0              获取成功
*               value -1             获取失败
*               value -2             获取失败
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
		/*匹配成功指针后移*/
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
* Description : 字符转换成小写字母,非字母字符不做出处理
* Parameters  : char *str            指定字符
*/

void Tolower(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
	{   /*调用系统函数tolower函数*/
        str[i] = tolower(str[i]);
	}
}             

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

int JudgeInput(int argc, char **argv, FILE *fp, FILE *fpout)
{
	/*如果不是命令行参数不是4个，退出*/
    if (argc != 4)
    {
        printf("输入格式错误!\n");
        printf("请输入检索文件名，字符串，输出文件名\n");
        return -1;
    }
	
	fp = fopen(argv[1], "r");
	
	/*如果检索文件不存在，退出*/
    if (fp == NULL)
    {
        printf("检索文件不存在！\n");
        return -2;
    }
	
    int pat_len = strlen(argv[2]);
	
	/*如果字符串的长度大于80，退出*/
	if (pat_len > 80)
	{
        printf("带查找字符串长度不能超过80!\n");
        return -3;
    }
	
	/*如果字符串有中文字符，退出*/
    for (int i = 0; i < pat_len; i++)
    {
        if (argv[2][i] < 0)
        {
            printf("字符串包含非ascii字符!\n");
            return -4;
        }
    }                                 
	
	char *pthparameter = argv[3];

    fpout = fopen(pthparameter, "w+");
	
	/*如果输出文件未打开，退出*/
    if (fpout == NULL)
    {
        printf("输出文件未打开！\n");
        return -5;
    }
	
    fclose (fp);
    fclose (fpout);
    return 1;
	
}                                   

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

int MatchKeyWordInText(int *pnext, char *pat, FILE *fp, FILE *fpout, int Case_Sensitive)
{
    int line = 0;
    int find_sum = 0;
	/*开辟一个100个char大小的空间，将读入的内容放进里面*/
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
	
	/*每次从输入文本读取一行字符串一直到文件尾*/
    while (!feof(fp))
    {
        memset(text, 0, sizeof(text));
        line++;
		/*标记这一行是否匹配成功，初始化为0*/
        int is_find = 0;
        int i = 0;	
		/*ch != -1为如果文件结束会返回一个-1，不然最后一行可能会读取不到*/
        char ch;
		/*读取一行字符，并添加到text数组中 ，如果超过，则动态增加内存*/
        while (!feof(fp) && (ch = fgetc(fp)) != '\n' && ch != -1) 
		{
            text[i++] = ch;
			
            if (i >= length)
            {

                char *newbase = (char*)realloc(text,(length+20)*sizeof(char));
                if (!newbase) 
				{
                    printf("分配内存失败！\n");
                    fputs("分配内存失败！\n", fpout);
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

		/*对这一行进行匹配*/
        int text_len = strlen(text);	
        i = 0;			
		
        while (i < text_len)
        {
            int re;
			
            if ((re = KMP(pnext, text, pat, i)) >= 0)
            {
                is_find = 1;
                find_sum++;				
                printf("在第%d行第%d列匹配成功.\n", line, re+1);
                fprintf(fpout, "在第%d行第%d列匹配成功.\n", line, re+1);
            }
        }
		
        if (is_find)
        {
            fprintf(fpout, "第%d行的内容为：\n", line);
            fputs(text, fpout);
            fputc('\n', fpout);
            fputc('\n', fpout);
        }	
		fprintf(fpout,"-----------------------next--line----------------------------\n");
    }
	
    printf("匹配成功次数为%d.\n", find_sum);
    fprintf(fpout, "匹配成功次数为%d。\n", find_sum);
	
	free(text);
	text = NULL;
	return 1; 
}                                           

# define ansyes 'y'
# define ansno  'n'

int main(int argc,char **argv)
{
    FILE *fp, *fpout;

	/*判断输入格式是否正确*/
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

	/* 判断是否需要区分大小写*/
    char ans[MAXSIZE];
    int Case_Sensitive = -1;
    printf("是否区分大小写?请输入(y\\n):\n");
    scanf("%s", ans);
    
	if (strlen(ans) != 1 || ((ans[0] != ansyes) && (ans[0] != ansno)))
    {
        printf("输入格式错误！\n");
        exit(-2);
    }
    else if (ans[0] == ansyes) 
	{
        Case_Sensitive = 1;
        puts("区分大小写！\n");
    }
    else
	{
        Case_Sensitive = 0;
        puts("不区分大小写！\n");
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
	
	/*文本查找*/
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
