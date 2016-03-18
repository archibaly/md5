#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

int main()
{
	int i;
	char str[] = "Hello World!";
	unsigned char buf[16];
	md5_ctx ctx;

	md5_init(&ctx);
	md5_update(&ctx, (char *)str, strlen(str));
	md5_final(&ctx, buf);

	for (i = 0; i < 16; i++)
		printf("%02x", buf[i]);
	printf("\n");

	md5_file("md5.h", buf);

	for (i = 0; i < 16; i++)
		printf("%02x", buf[i]);
	printf("\n");

	char result[33];

	for (i = 0; i < 16; i++)
		sprintf(result + i * 2, "%02x", buf[i]);
	printf("%s\n", result);

	return 0;
}
