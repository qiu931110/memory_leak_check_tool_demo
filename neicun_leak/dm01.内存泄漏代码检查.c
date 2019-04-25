// stdafx.cpp : 只包括标准包含文件的源文件
// neicun_leak.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用
#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>
//#include <stdio.h>
//#include "memwatch.h"

int getMem(char **myp)
{
	char *p = NULL;

	p = (char *)malloc(100);   //mwMalloc(100,__FILE__,__LINE__)

	strcpy(p, "aaaabbbb");
	*myp = p;
	return 0;
}

void main()
{
	char *myp = NULL;
	getMem(&myp);
	printf("%s \n", myp);

	if (myp != NULL)
	{
		free(myp);
	}
	
	printf("hello...\n");
	system("pause");
	return ;
}
