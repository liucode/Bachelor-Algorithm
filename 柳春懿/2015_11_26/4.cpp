#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
int count = 0;


void swap(char *predata , char *data)
{
	char temp = *predata;
	*predata = *data;
	*data = temp;
}

int isempty(char *data,int key,int len)
{
	for(int i=key;i<len;i++)
	{
		if(data[i]==data[len])
			return false;
	}
	return true;
}

void func(char *data,int key,int len)//迭代的求解
{
	if(key==len)
	{
		for(int k=0;k<len;k++)
		{
			//printf("%c",data[k]);
		}
					count++;
		//printf("\n");
		
	}
	for(int i=key;i<len;i++)
	{	
		if(isempty(data,key,i))
		{
			swap(&data[key],&data[i]);
            func(data,key+1,len);
		    swap(&data[i],&data[key]);
		}
	}

}



int notin(char *data,int len,int e)
{
     for(int i=0;i<len;i++)
	 {
		 if(e==data[i])
			 return false;
	 }
	 return true;
}



void funco(char *outdata,int outlen,char *data,int datalen)
{
	if(outlen == datalen)
	{
		for(int k=0;k<datalen;k++)
		{
		//	printf("%c",outdata[k]);
		}
		outlen = 0;
		printf("\n");
        return;
		
	}
    for(int i=0;i<datalen;i++)
	{
          if(notin(outdata,outlen,data[i]))
		  {
            outdata[outlen] = data[i];
			funco(outdata,outlen+1,data,datalen);
		  }
	}

}

void main()
{
	char data[10]="123456789";
	char out[10];
	func(data,0,10);
    //fp=fopen("1.txt","w");
	//funco(out,0,data,9);
    printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
	printf("%d",count);

}
