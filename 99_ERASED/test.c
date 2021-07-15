#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	void *dst;
	void *src;

	dst = (void *)malloc(1);
	src = (void *)malloc(1);
	memcpy(dst, src, 1);
	printf("1\n");
	//memcpy(dst, 0, 1);
	//printf("2\n");
	//memcpy(0, src, 1);
	//printf("3\n");
	memcpy(0, 0, 0);
	printf("4\n");
	memcpy(0, 0, 5);
	printf("5\n");
	memcpy(dst, dst, 1);
	printf("6\n");
}


