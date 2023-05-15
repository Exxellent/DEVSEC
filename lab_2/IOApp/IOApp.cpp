
#include <iostream>
#include <time.h>
int main()
{
	FILE* fptr;
	fopen_s(&fptr, "test.kek", "r+");
	if (fptr == 0) {
		printf("Error with open\n");
		return 1;
	}
	char buf[1024] = { 0 };
	fread_s(buf, 1024, sizeof(char), 1024, fptr);
	printf_s("File content: %s\n\n", buf);
	getchar();

	time_t rawtime;
	struct tm timeinfo;
	char bufWrite[1024] = { "Rahmatullaev.R.R"};
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	strftime(bufWrite, sizeof(bufWrite), "%Y-%m-%d %H:%M:%S", &timeinfo);

	fseek(fptr, 0, 0);
	fwrite(bufWrite, sizeof(char), 1024, fptr);
	fflush(fptr);
	fclose(fptr);
	return 0;
}
