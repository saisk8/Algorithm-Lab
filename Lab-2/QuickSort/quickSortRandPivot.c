#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<time.h>
#include<sys/stat.h>
#include<fcntl.h>
#define BUFFER_SIZE 100
unsigned long swap=0,comparisions=0;
void exchange(int * val1,int * val2){
	
	int temp=*val1;
	*val1=*val2;
	*val2=temp;
	++swap;
}

int partition(int arr[],int startIndex,int endIndex){
	int pivot=arr[startIndex];
	int i=startIndex,j;
	for(j=startIndex+1;j<=endIndex;j++){
		comparisions++;
		if(arr[j]<=pivot){
			i++;
			exchange(&arr[i],&arr[j]);
		}
	}
	exchange(&arr[i],&arr[startIndex]);
	return (i);
}

int randomPartion(int arr[],int startIndex,int endIndex){
	int pivot=(rand()%(endIndex-startIndex+1))+startIndex;
	exchange(&arr[pivot],&arr[startIndex]);
	return partition(arr,startIndex,endIndex);
}

void QuickSort(int arr[],int startIndex,int endIndex){
	if(startIndex<endIndex){
		int partitionIndex=randomPartion(arr,startIndex,endIndex);
		QuickSort(arr,startIndex,partitionIndex-1);
		QuickSort(arr,partitionIndex+1,endIndex);
	}
}

void createOutputFilesDir(char * dirName){
	DIR * dir = opendir(dirName);
	if(dir){
	    closedir(dir);
	}
	else if (dir == NULL){
		if(mkdirat(AT_FDCWD,dirName,S_IRWXU | S_IRWXG | S_IRWXO)!=0)
			perror("File creation error");
	}
	else{
	    perror("opendir() failed");
	}
}
void writeInReadMeFile(char * programName,char * fileName){
	FILE * fp;
	fp=fopen("readme.txt","a");
	fprintf(fp,"%s\t\t%s\t%10lu\t\t%10lu\n",programName,fileName,comparisions,swap);
	fclose(fp);
	

}

void createReadMeFile(){
	FILE *fp;
	fp=fopen("readme.txt","r");
	if(fp==NULL){
		
		fp=fopen("readme.txt","w");
		fprintf(fp,"%s","programName\t\t\tinputFile\t\t\tComaprisions\t\tSwaps\n");
	}else{
		fclose(fp);
		fp=fopen("readme.txt","a");
		fseek(fp,0,SEEK_END);
		if(ftell(fp)==0){
			printf("inside ftell== 0");
			fprintf(fp,"%s","programName\t\t\tinputFile\t\t\tComaprisions\t\tSwaps\n");
		}
		
	}
	fclose(fp);
}

void sortFiles(char * inPrefix,char * outPrefix){
	FILE *fp;
	int i;
	for(i=100;i<=100000;i*=10){
		int arr[i],j=0;
		char inputSuffix[BUFFER_SIZE]={ },outputSuffix[BUFFER_SIZE]={ };
		snprintf(inputSuffix,BUFFER_SIZE-1,"%d.txt",i);
		snprintf(outputSuffix,BUFFER_SIZE-1,"%d.txt",i);
		char * inputFileName=malloc(sizeof(char)*BUFFER_SIZE),* outputFileName=malloc(sizeof(char)*BUFFER_SIZE);
		strcpy(inputFileName,inPrefix);
		strcpy(outputFileName,outPrefix);
		inputFileName=strcat(inputFileName,inputSuffix);
		outputFileName=strcat(outputFileName,outputSuffix);
		printf("InputFile :: %s \nOutputFile:: %s\n",inputFileName,outputFileName);
		fp=fopen(inputFileName,"r");
		if(fp!=NULL){
			int num,count=0;
			char lineBuffer[BUFFER_SIZE*2];
			while((fgets(lineBuffer,BUFFER_SIZE*2,fp))!=NULL){
				 if (sscanf(lineBuffer, "%d", &num) != 1) {
				    perror("Line formatting error");
				    exit(EXIT_FAILURE);
				}
				if(count!=0)
					arr[j++]=num;
				count++;
			}
			int k;
			
			fclose(fp);
			QuickSort(arr,0,i-1);
			fp=fopen(outputFileName,"w");
			fprintf(fp,"%lu [number of comparison] \n",comparisions);
			fprintf(fp,"%lu [number of swap]\n",swap);
			writeInReadMeFile("QuickSortRandomPivot",inputFileName);
			for(j=0;j<i;j++)
				fprintf(fp,"%d\n",arr[j]);
			fclose(fp);
			comparisions=0;
			swap=0;
			printf("InputFile :: %s \nOutputFile:: %s\n",inputFileName,outputFileName);
			
		}else{
			perror("File Not Found");
		}
		
		
	}
}	



int main(){
	createOutputFilesDir("RandPivOut");
	char inputPrefix[3][20]={"InputFiles/in_asce","InputFiles/in_desc","InputFiles/in_rand"};
	char outputPrefix[3][20]={"RandPivOut/out_asce","RandPivOut/out_desc","RandPivOut/out_rand"};
	createReadMeFile();
	int i;
	for(i=0;i<3;i++){
			sortFiles(inputPrefix[i],outputPrefix[i]);
	}

return 0;
}


