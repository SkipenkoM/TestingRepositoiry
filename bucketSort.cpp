#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void bucketSort(int*, int);
int sizeArrayFile(FILE*, char*);
int* createArrayFile(FILE*, int, char*);


int main() {
	
	long time1;
	long time2;
	long MS;
	
	int size = 0;
	FILE *filein, *fileout;	
	
	if ((fileout=fopen("sortedRAbucketSort.txt","w"))==NULL) {
		printf("NO!\n");
		exit(1);
	};		
	
		printf("Sorting random array\n");
		char namearr[] = "array.txt";
		int maxsizeArr = 300000;
		for(size = 5000; size<=(maxsizeArr-5000); size= size+5000){
			int* data =  createArrayFile(filein, size, namearr);
		//	printf("%d\n", size);
			printf("Size %d elements\n", size);
				time1 = clock();
				bucketSort(data, size);
				time2 = clock();
				MS = time2 - time1;
			printf("Time passes=%ld ms\n", MS);
		//	printf("%ld\n", MS);
			free(data);
		}
		{
		int* data =  createArrayFile(filein, size, namearr);
		//	printf("%d\n", size);
			printf("Size %d elements\n", size);
				time1 = clock();
				bucketSort(data, size);
				time2 = clock();
				MS = time2 - time1;
			printf("Time passes=%ld ms\n", MS);
		//	printf("%ld\n", MS);
		for(int i=0;i<size;++i){
    		fprintf(fileout,"%d ", data[i]);
		};
		fclose(fileout);
		free(data);
		}
		
	if ((fileout=fopen("sortedSAbucketSort.txt","w"))==NULL) {
		printf("NO!\n");
		exit(1);
	};			
		
		printf("Sorting sorted array\n");
		char namesortedarr[] = "sortedArray.txt";
		int maxsizeSArr = 300000;
		for(size = 5000; size<=(maxsizeSArr-5000); size= size+5000){
			int* data =  createArrayFile(filein, size, namesortedarr);
		//	printf("%d\n", size);
			printf("Size %d elements\n", size);
				time1 = clock();
				bucketSort(data, size);
				time2 = clock();
				MS = time2 - time1;
			printf("Time passes=%ld ms\n", MS);
		//	printf("%ld\n", MS);
			free(data);
		}
		{
		int* data =  createArrayFile(filein, size, namesortedarr);
		//	printf("%d\n", size);
			printf("Size %d elements\n", size);
				time1 = clock();
				bucketSort(data, size);
				time2 = clock();
				MS = time2 - time1;
			printf("Time passes=%ld ms\n", MS);
		//	printf("%ld\n", MS);
		for(int i=0;i<size;++i){
    		fprintf(fileout,"%d ", data[i]);
		};
		fclose(fileout);
		free(data);
		}

	if ((fileout=fopen("sortedRSAbucketSort.txt","w"))==NULL) {
		printf("NO!\n");
		exit(1);
	};			
		
		printf("Sorting reverse sorted array\n");
		char namerevsortedarr[] = "reverseSortedArray.txt";
		int maxsizeRSArr = 300000;
		for(size = 5000; size<=(maxsizeRSArr-5000); size= size+5000){
			int* data =  createArrayFile(filein, size, namerevsortedarr);
		//	printf("%d\n", size);
			printf("Size %d elements\n", size);
				time1 = clock();
				bucketSort(data, size);
				time2 = clock();
				MS = time2 - time1;
			printf("Time passes=%ld ms\n", MS);
		//	printf("%ld\n", MS);
			free(data);
		}
		{
		int* data =  createArrayFile(filein, size, namesortedarr);
		//	printf("%d\n", size);
			printf("Size %d elements\n", size);
				time1 = clock();
				bucketSort(data, size);
				time2 = clock();
				MS = time2 - time1;
			printf("Time passes=%ld ms\n", MS);
		//	printf("%ld\n", MS);
		for(int i=0;i<size;++i){
    		fprintf(fileout,"%d ", data[i]);
		};
		fclose(fileout);
		free(data);
		}
		
	if ((fileout=fopen("sortedMAbucketSort.txt","w"))==NULL) {
		printf("NO!\n");
		exit(1);
	};			
		
		printf("Sorting monotonous array\n");
		char namemonoarr[] = "monotonousArray.txt";
		int maxsizeMArr = 300000;
		for(size = 5000; size<=(maxsizeMArr-5000); size= size+5000){
			int* data =  createArrayFile(filein, size, namemonoarr);
		//	printf("%d\n", size);
			printf("Size %d elements\n", size);
				time1 = clock();
				bucketSort(data, size);
				time2 = clock();
				MS = time2 - time1;
			printf("Time passes=%ld ms\n", MS);
		//	printf("%ld\n", MS);
			free(data);
		}
		{
		int* data =  createArrayFile(filein, size, namemonoarr);
		//	printf("%d\n", size);
			printf("Size %d elements\n", size);
				time1 = clock();
				bucketSort(data, size);
				time2 = clock();
				MS = time2 - time1;
			printf("Time passes=%ld ms\n", MS);
		//	printf("%ld\n", MS);
		for(int i=0;i<size;++i){
    		fprintf(fileout,"%d ", data[i]);
		};
		fclose(fileout);
		free(data);
		}		
		
		
}

void bucketSort(int A[], int n){  
    int i, j;  
    int B[n]; 
    for (i = 0; i < n; i++){
    	B[i] = 0;
	}
    for (i = 0; i < n; i++){
    	(B[A[i]])++;
	}
    for (i = 0, j = 0; i < n; i++){
    	for(; B[i] > 0; (B[i])--){
        	A[j++] = i;
		}
	}         
}   

int sizeArrayFile(FILE *file, char* name ){
	int size;
	int s;
		file=fopen(name,"rb"); 
	if(file==NULL){
		puts("File not found");
		return 0;
	}
	else{
		while ((fscanf(file, "%d",&s)!=EOF)){    
			if(!file){
				break;
			}     
        	size+=1;
		}
	fclose(file);
	return size;	
	}
}

int* createArrayFile(FILE *file, int size, char* name  ){
	int s;
	file=fopen(name ,"rb"); 
	if(file==NULL){
		puts("File not found");
		return 0;
	}
	else{
		sizeArrayFile(file, name );	
		int *data = (int*) malloc(size*sizeof(int)); 
		rewind(file);   
		for(int i=0;i<size;i++){
    		fscanf(file, "%d",&data[i]);
		}
		fclose(file);
		return data;
	}
}

