#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void countSort(int*, int, int);
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
	
	if ((fileout=fopen("sortedCount.txt","w"))==NULL) {
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
				/*int max = 0;
				for(int i=0;i<size;++i){
     			scanf("%d",&data[i]);
     				if(data[i]>max){
     					max=data[i];
					}
    			}*/
				countSort(data, size, 99);
				printf("Size %d elements\n", size);
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

void countSort(int A[], int n, int k)
{
	//printf("E1");
    int i, j;
    int B[n], C[100];
    //printf("L2");
    for (i = 0; i <= k; i++)
        C[i] = 0;
    //printf("L3");
    for (j = 1; j <= n; j++)
        C[A[j]] = C[A[j]] + 1;
    //printf("L4");
    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    //printf("L5");
    for (j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    for (i = 1; i <= n; i++){
		A[i]=B[i];
    }
}


/*
void countSort(int* arr, int n, int exp){
    int output[n];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++){
    	count[(arr[i] / exp) % 10]++;
	}
    for (i = 1; i < 10; i++){
    	count[i] += count[i - 1];
	}
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++){
    	arr[i] = output[i];
	}
}
*/
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
