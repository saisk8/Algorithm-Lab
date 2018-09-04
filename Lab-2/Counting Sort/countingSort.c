#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>
#define BUFFER_SIZE 100
unsigned long comparisions=0,swap=0;

void countingSort(int arr[],int max,int size){
    int i, j;
    int B[size], C[max+1];

    for (i = 0; i <= max; i++)
	C[i] = 0;
	for(i = 0; i < size; i++)
	B[i]=0;

    for (j = 0; j <size; j++){
	//printf("%d %d\n",arr[j],C[arr[j]]);
	C[arr[j]] = C[arr[j]] + 1;
	}
int k=0;
	for(k=0;k<=max;k++)
		printf("%d ",C[k]);
printf("\n");
    for (i = 1; i <= max; i++)
	C[i] = C[i] + C[i-1];
 	
	for(k=0;k<=max;k++)
		printf("%d ",C[k]);
printf("\n");
    for (j = size-1; j >= 0; j--){
        B[C[arr[j]]] = arr[j];
        C[arr[j]] = C[arr[j]] - 1;
    }

	for(k=0;k<size;k++)
		printf("%d ",B[k]);
printf("\n");
	for(i = 0; i < size; i++){
		arr[i]=B[i];
	}
    	
	
}

void sortFiles(char * inPrefix,char * outPrefix){
	int i,loop=0;
	for(i=50;i<=1000;i*=(loop%2==1?2:5)){
		int arr[i],j=0;
		char inSuffix[BUFFER_SIZE]={ };
		char outSuffix[BUFFER_SIZE]={ };
		char * inputFileName=malloc(sizeof(char)*BUFFER_SIZE);
		char * outputFileName=malloc(sizeof(char)*BUFFER_SIZE);
		snprintf(inSuffix,BUFFER_SIZE-1,"%d.txt",i);
		snprintf(outSuffix,BUFFER_SIZE-1,"%d.txt",i);
		strcpy(inputFileName,inPrefix);
		strcpy(outputFileName,outPrefix);
		inputFileName=strcat(inputFileName,inSuffix);
		outputFileName=strcat(outputFileName,outSuffix);
		printf("inputFileName :: %s \n outputFileName :: %s\n",inputFileName,outputFileName);
		FILE *fp;
		fp=fopen(inputFileName,"r");
		if(fp!=NULL){
			int num,count=0,max=0;
			char lineBuffer[BUFFER_SIZE*2];
			while((fgets(lineBuffer,BUFFER_SIZE*2,fp))!=NULL){
				if(sscanf(lineBuffer,"%d",&num)!=1){
					perror("Line formatting error");
				    	exit(EXIT_FAILURE);
				}
				if(count!=0){
					arr[j]=num;
					comparisions++;
					if(arr[j]>max)
						max=arr[j];
					j++;
				}
					
				count++;
				printf("j :: %d , num :: %d\n",j,num);
			}
			
			fclose(fp);
			countingSort(arr,max,i);
			
			fp=fopen(outputFileName,"w");
			fprintf(fp,"%lu [number of comparison] \n",comparisions);
			fprintf(fp,"%lu [number of swap]\n",swap);
			for(j=0;j<i;j++)
				fprintf(fp,"%d\n",arr[j]);
			comparisions=0;
			swap=0;
			fclose(fp);
			loop++;

		}else{
			perror("File open error");
		}
		
	}
}


void createDirectory(char * dirName){
	DIR * dir=opendir(dirName);
	if(dir==NULL){
		if(mkdirat(AT_FDCWD,dirName,S_IRWXU | S_IRWXG | S_IRWXO)!=0)
			perror("Directory creation error");
	}else if(dir){
		closedir(dir);
	}else{
		perror("opendir error");
	}
		
}

int main(){
	createDirectory("OutputFiles");
	
		sortFiles("InputFiles/in_rand","OutputFiles/out_rand");

}
