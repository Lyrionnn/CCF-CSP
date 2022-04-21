#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Doc
{
	char title[10];
	char word[100];
	int F[100];
};
struct Doc D[100];

int main (void)
{
	//input part
	int N;				//the number of the total documents
	scanf("%d",&N);
	
	for(int k=0;k<N;k++)              //documents information
	{
	
	int i;								//title
	i=0;
	scanf("%s",D[i].title);
		getchar(); 
	/*do
	{
	scanf("%c", D[k].title[i]);
	} while (D[k].title[i++] != '\n');  //scanf receive tab and ¡®\n¡¯£¬ end with ¡®\n¡¯
	D[k].title[i] = '\0';*/
	
	int j;								//words
	j=0;
	D[k].word[j]=getchar();
	while(D[k].word[j]!='#')	
	{
		if(D[k].word[j]==' '||D[k].word[j]=='\n')
		{
			j=j-1;
		}
		else
		{
			j=j+1;
			scanf("%c",&D[k].word[j]);
		}
	}
	
	int r;							//F(repeat)
	for(r=0;r<j;r++)                //calculate F,not given repeat and same
	{
		D[k].F[r] = 0;
			for(int n=0;n<j;n++)
			{
				if(D[k].word[n] == D[k].word[r])
					D[i].F[r]++;
			}	
	}
	for(r=0;r<j;r++)             //given reapeat
	{
	    if(D[k].F[r]>1)
		{
		for(int n=r+1;n<j;n++)
		{
			if(D[k].word[n] == D[k].word[r])
					D[i].F[n]=0;
		}	
		}	
	}	
	}
	
	//comparation part
	int M;				//M times conparation
	double result[100]; 
	int docnumber1,docnumber2;
	char compdoc1[10];
	char compdoc2[10];
	scanf("%d",&M);
	int c;
	for(c=0;c<M;c++)
	{
	scanf("%s%s",compdoc1,compdoc2);
	
	for(int f=0;f<N;f++)
	{
			if(strcmp(D[f].title,compdoc1) == 0){
				docnumber1=f;
			}
			if(strcmp(D[f].title,compdoc2) == 0){
			    docnumber2=f;
			}
	}
	double norm1=0;
	double norm2=0;
	double norms1;
	double norms2;
	double distance=0;
	for(int b=0;D[docnumber1].word[b]!='#';b++)
	{
		norm1=norm1+(D[docnumber1].F[b])*(D[docnumber1].F[b]);
		norms1=sqrt(norm1);
	}
	
	for(int b=0;D[docnumber2].word[b]!='#';b++)
	{
		norm2=norm2+(D[docnumber2].F[b])*(D[docnumber2].F[b]);
		norms2=sqrt(norm2);
	}
    // biaoji double distance=0;
    
	for(int i = 0;D[docnumber1].word[i] != '#' && i < 100; i++ )
	{
		for(int j = 0;D[docnumber2].word[j] != '#' && j < 100 ; j++ ){
			if(D[docnumber1].F[i] == D[docnumber2].word[j]){
				distance=distance+D[docnumber1].F[i] * D[docnumber2].F[j];
			}
		}
	}
	result[c]=acos(distance / norms1*norms2);
}
	
	//output part
	int o;
	for(o=0;o<M;o++)
	printf("Case %d: %.3lf\n",o+1 ,result[o]);	
	return 0;
	
}
