#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int getMax(int*, int);
void countSort(int, int, int);
void radixSort(int*, int);
int sizeArrayFile(FILE*, char*);
int* createArrayFile(FILE*, int, char*);

int main() {
	
	long time1;
	long time2;
	long MS;
	
	int size = 0;
	FILE *filein, *fileout;	
	
	if ((fileout=fopen("sortedRAradixSort.txt","w"))==NULL) {
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
				radixSort(data, size);
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
				radixSort(data, size);
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
		
	if ((fileout=fopen("sortedSAradixSort.txt","w"))==NULL) {
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
				radixSort(data, size);
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
				radixSort(data, size);
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

	if ((fileout=fopen("sortedRSAradixSort.txt","w"))==NULL) {
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
				radixSort(data, size);
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
				radixSort(data, size);
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
	getchar();
}

int getMax(int arr[], int n){
    int mx = arr[0];
    int i;
    for (i = 1; i < n; i++){
    	if (arr[i] > mx){
        	mx = arr[i];
		}
	}       
    return mx;
}
 
void countSort(int arr[], int n, int exp){
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

void radixSort(int arr[], int n){
    int m = getMax(arr, n);
    int exp;
    for (exp = 1; m / exp > 0; exp *= 10){
    	countSort(arr, n, exp);
	}
}

int sizeArrayFile(FILE *file, char name[]){
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

int* createArrayFile(FILE *file, int size, char name[]){
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
