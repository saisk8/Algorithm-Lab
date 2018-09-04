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


void createRandOrderFiles(){
	FILE * fp;
	int i,loop=0,k;
	srand(time(NULL));
	for(i=50;i<=1000;i*=loop%2==1?2:5){
		char fileName[BUFF_SIZE]={ };
		snprintf(fileName,BUFF_SIZE-1,"InputFiles/in_rand%d.txt",i);
		printf("%s\n",fileName);
		fp=fopen(fileName,"w");
		fprintf(fp,"%d%s\n",i," [total number of elements]");	
		int j,count=0;
		for(k=1;k<=i/10;k++){
			for(j=10;j>0;j--)
				fprintf(fp,"%d%s%d%s\n",(rand()%(i/5))," [element-",++count,"]");
		}
		fclose(fp);
		loop++;
	}
}

int main(){
	createInputFilesDir("InputFiles");
	createRandOrderFiles();
	return 0;
}
