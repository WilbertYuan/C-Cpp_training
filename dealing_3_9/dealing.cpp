#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstdio>

int main()
{
	// FILE* freopen(const char* filename, const char* mode, FILE * stream);

	FILE* pre_stdout = stdout;
	
	FILE* p = freopen("start", "w+", stdout);
	if (p != NULL)
		exit(1);
	printf("dhskjfhasdlkfhsdaklhfdskahfkdsalhfkjldsafhkdlshfkjladshfkldashfkljdsahfkd");

	return 0;
}