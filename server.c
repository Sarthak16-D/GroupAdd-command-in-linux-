#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void encryptpas(char pass[])
{
  int i=0;
  while(pass[i]!='\0')
  {
  			pass[i] = pass[i] + 3; //the key for encryption is 3 that is added to ASCII value
  			i++;
  		}

}
int uniqid(int id)
{
  char line[1000];
  FILE *fp=fopen("group.txt","r");
  while ( fgets ( line, sizeof line, fp ) != NULL )
  {
  char *token = strtok(line, ":");
  token = strtok(NULL, ":");
  token = strtok(NULL, ":");
	int flag=atoi(token);
  if(flag==id)
  {  printf("id already exists enter a different id");
    exit(0);
		return 0;
	 }
}
fclose(fp);
}
