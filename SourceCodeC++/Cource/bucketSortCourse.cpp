#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void bucketSort(int*, int);
void printArray(int*, int);
int sizeArrayFile(FILE*, char*);
int* createArrayFile(FILE*, int, char*);

int main() {
	
	long time1;
	long time2;
	long MS;
	
	struct timespec mt1, mt2; 
	long int tt;     
	
	
	FILE *filein, *fileout;	
	
	if ((fileout=fopen("sortedBucket.txt","w"))==NULL) {
		printf("NO!\n");
		exit(1);
	};		
	
		printf("Sorting random array\n");
		char namearr[] = "reverseSortedArray.txt";
		int size = sizeArrayFile(filein, namearr);
			printf("Size %d elements\n", size);
		int* data =  createArrayFile(filein, size, namearr);
				//clock_gettime (CLOCK_REALTIME, &mt1);
				time1 = clock();
				bucketSort(data, size);
				//clock_gettime (CLOCK_REALTIME, &mt2);
				time2 = clock();
				MS = time2 - time1;
				//tt=(mt2.tv_nsec - mt1.tv_nsec);
			printf("Time passes=%ld\n", MS);
			//printf (" Times passed = %ld ns\n",tt);
			for(int i=0;i<size;++i){
    			fprintf(fileout,"%d ", data[i]);
			};	
			free(data);	
}

void bucketSort(int* array, int n){  
    int i, j;  
    int count[n]; 
    for (i = 0; i < n; i++){
    	count[i] = 0;
	}
    for (i = 0; i < n; i++){
    	(count[array[i]])++;
	}
    for (i = 0, j = 0; i < n; i++){
    	for(; count[i] > 0; (count[i])--){
        	array[j++] = i;
		}
	}         
}   

void printArray(int* array, int size ){
	for (int i = 0; i < size; ++i){
		printf("%d  ", array[i]);
	}
	printf("\n");
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
