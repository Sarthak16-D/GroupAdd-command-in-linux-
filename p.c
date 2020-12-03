#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include "server.h"
int main(int argc,char *argv[])
{
	int c,id;
  char *gname,*usern=" ",*pass,*adminstr=" ";

	while((c=getopt(argc,argv,"g:p:n:u:ha:"))!=-1)
	{
		switch(c)
		{
			case 'g':
				id=atoi(optarg);
				uniqid(id);
				break;
			case 'p':
				pass=optarg;
				break;

			case 'n':
				gname=optarg;
				break;
			case 'u':
				usern=optarg;
				break;
			case 'h':
				printf("\t options available\n-g ...to specify the group id\n-n ... to specify the group name\n-p ...for password\n-u ... to enter a comma seperated list of users\n-h ...for viewing the man page\n");
				break;
			case 'a':
				adminstr=optarg;
				break;
			case '?':
				if (optopt == 'g' || optopt == 'p' || optopt == 'n')
					fprintf(stderr,"option -%c needs argument\n",optopt);
				else
					fprintf(stderr,"unknown option -%c",optopt);
				break;
			default:
				fprintf(stderr,"getopt");
		}
	}
int res;

encryptpas(pass);
FILE *fp=fopen("group.txt","a"),*fs=fopen("gshadow.txt","a");
fprintf(fp,"%s:x:%d:%s\n",gname,id,usern);
printf("GROUP CREATED SUCCESSFULLY\n");
fclose(fp);
fprintf(fs,"%s:%s:%s:%s\n",gname,pass,adminstr,usern);
fclose(fs);
return 0;
}
