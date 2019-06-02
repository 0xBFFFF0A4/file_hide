#include <stdio.h>

int chrlen(char * chr)
{
	int x = 0;
	while(chr[x] != '\0')
		{x ++;}
	return x;
}

int main(int argc, char * argv[])
{
	if (argc == 3)
	{
		FILE *file;
		long filelen = 0;
		file = fopen(argv[2], "rb");

		if (file == NULL)
		{
			printf("[!] Cannot open:%s", argv[2]);
			return 0;
		}
		//Filesize
		fseek(file, 0, SEEK_END);
		filelen = ftell(file);
		rewind(file);

		char filedata[filelen];
		fread(filedata, 1, filelen, file);
		char filename[chrlen(argv[1])+chrlen(argv[2])+1];
		sprintf(filename, "%s:%s", argv[1], argv[2]);

		FILE *fileads;
		fileads = fopen(filename, "wb");
		fwrite(filedata, sizeof(char), filelen, fileads);
		fclose(file);
		fclose(fileads);
		return 0;
	}
	else
	{
		printf("[*] Usage: %s <target file> <file to hide>", argv[0]);
		return 0;
	}	

}	