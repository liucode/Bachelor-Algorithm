#include <stdio.h>
#include <string.h>


void FormatString(char str[],int len)
{
	char outstr[100];
	int i=0;
	int k=0;
	int flog = 0;
	while(i<=len)
	{
		while(str[i]==' ')
		{
			 if(i==0||i==len-1)
				flog = 3;
			 if(flog==3)
                i++;
			 else
			 {
				 flog = 1;
				 i++;
			 }
		}
		if(flog==1)
		{
			outstr[k]=' ';
			k++;
			flog = 0;
		}
		else
		{
           outstr[k] = str[i];
		   i++;
		   k++;
		   flog = 0;
		}

	}
	puts(outstr);
	printf("%d",strlen(outstr));
}

void main()
{
	char str[100];
	gets(str);
	FormatString(str,strlen(str));
}
