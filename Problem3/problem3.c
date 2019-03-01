

#include<stdio.h>
#include<string.h>
#include <stdlib.h>


void mygrep(FILE*, char*);
void myreplace(FILE *fp,char *find, char * replace);
int  main(int argc,char *argv[])
{

	int behaviour;
	FILE *fp;
	char *filename=argv[2];
	char *find=argv[3];
	char * replace;
	if(argv[1]=="mygrep" )
	{
		if(argc != 3)
		{
			printf("usage\t./mygrep filename <string-to-search>\n");
			exit(1);
		}
		behaviour = 1;
	}
	else if(argv[1]=="myreplace")
	{
		if(argc != 4)
		{
			printf("\t./myreplace filename  <string-to-search> <string-to-replace>");
			exit(1);
		}
		behaviour = 0;
		replace = argv[3];
	}
	else
	{
		behaviour = -1;
	}

	fp=fopen(filename,"rt");

	if(behaviour == 1)
	{
		mygrep(fp,find);		

	}
	else if ( behaviour == 0 )
	{
		myreplace(fp,find,replace);			

	}
	
	fclose(fp);			

	return 0;
}


void mygrep(FILE *fp,char *find)
{
	char c1[500];
	while(fgets(c1,500,fp))
	{
		if(strstr(c1,find))
			printf("%s",c1);
	}
}
void myreplace(FILE *fp,char *find, char * replace)
{

}

