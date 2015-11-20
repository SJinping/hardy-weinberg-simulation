
#include "function.h"
#include <math.h>
#include <iostream>

#using <mscorlib.dll>






// process different file names
char* cjoin(char a[],char b[],char c[])
{	
	char *mainchr=new char[];
	for(int i=0;a[i]!='\0';i++) mainchr[i]=a[i];
	for(int j=0;b[j]!='\0';j++) mainchr[i+j]=b[j];
	for(int k=0;c[k]!='\0';k++) mainchr[i+j+k]=c[k];
	mainchr[i+j+k]='\0';
	return mainchr;
};