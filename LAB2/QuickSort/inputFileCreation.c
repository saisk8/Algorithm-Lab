#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h> 
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<time.h>
#define BUFF_SIZE 200
void createInputFilesDir(char * dirName){
	DIR * dir = opendir(dirName);
	if(dir){
	    closedir(dir);
	}
	else if (dir == NULL){
		if(mkdirat(AT_FDCWD,dirName,S_IRWXU | S_IRWXG | S_IRWXO)!=0){
			perror("File creation error");
		}
	}
	else{
	    perror("opendir() failed");
	}
}

void createAscOrderFiles(){
	FILE * fp;
	int i;
	for(i=100;i<=100000;i*=10){
		char fileName[BUFF_SIZE]={ };
		snprintf(fileName,BUFF_SIZE-1,"InputFiles/in_asce%d.txt",i);
		printf("%s\n",fileName);
		fp=fopen(fileName,"w");
		int j,count=0;
		fprintf(fp,"%d%s\n",i," [total number of elements]");
		for(j=-i;j<i;j+=2)
			fprintf(fp,"%d%s%d%s\n",j," [element-",++count,"]");
		fclose(fp);
	}
	

}
void createDescOrderFiles(){
	FILE * fp;
	int i;
	for(i=100;i<=100000;i*=10){
		char fileName[BUFF_SIZE]={ };
		snprintf(fileName,BUFF_SIZE-1,"InputFiles/in_desc%d.txt",i);
		printf("%s\n",fileName);
		fp=fopen(fileName,"w");
		int j,count=0;
		fprintf(fp,"%d%s\n",i," [total number of elements]");
		for(j=i;j>-i;j-=2){
			fprintf(fp,"%d%s%d%s\n",j," [element-",++count,"]");
		}

		fclose(fp);
	}
}
void createRandOrderFiles(){
	FILE * fp;
	int i;
	srand(time(NULL));
	for(i=100;i<=100000;i*=10){
		char fileName[BUFF_SIZE]={ };
		snprintf(fileName,BUFF_SIZE-1,"InputFiles/in_rand%d.txt",i);
		printf("%s\n",fileName);
		fp=fopen(fileName,"w");
		fprintf(fp,"%d%s\n",i," [total number of elements]");	
		int j,count=0;
		for(j=1;j<=i;j++)
			fprintf(fp,"%d%s%d%s\n",(rand()%(2*i+1)-i)," [element-",++count,"]");
		fclose(fp);
	}
}

int main(){
	createInputFilesDir("InputFiles");
	createAscOrderFiles();
	createDescOrderFiles();
	createRandOrderFiles();
	return 0;
}
