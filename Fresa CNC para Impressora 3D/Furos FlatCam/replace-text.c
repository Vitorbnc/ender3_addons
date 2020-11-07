#include <stdio.h>
#include <string.h>

#define NAME_LEN 256
#define LINE_LEN 256

char * NAME_END = "-ok.gcode";
char *FIND = "F3.00\n";
char *REPLACE = "F100.00\n";

int main (int argc, char **argv){
	char* outName[NAME_LEN];
	char* line[LINE_LEN];
	FILE *inFile, *outFile;
	inFile = fopen(argv[1],"r");
	strcpy(outName,argv[1]);
	strcat(outName,NAME_END);
	outFile = fopen(outName,"w");
	while(fgets(line,LINE_LEN,inFile)!=NULL){
		char* buf;
		if((buf = strstr(line,FIND))!=NULL)
			strcpy(buf,REPLACE);
		fputs(line,outFile);
			
				
	}

	fclose(inFile);
	fclose(outFile);
	
	
}