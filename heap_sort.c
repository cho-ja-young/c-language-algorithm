#include<stdio.h>
#include<stdlib.h> // rand() 함수 포함 라이브러리 
#include<time.h> // time() 함수 포함 라이브러리
typedef int bool;
#define true 1
#define false 0

void swap(int *a, int *b);
void removekeys (int size, int array[]);
int root (int array[], int size, int i);
void makeheap (int size, int array[]);
void heap_sort (int size, int array[]);
void heap_sort (int size, int array[]);
void siftdown (int array[], int parent, int size);

int main(void)
{
	int i, j, n, k;
    double start, end;
    double p_time = 0;
    double sum = 0; // 수행 결과 시간 저장
    	
    // 5번씩 반복 수행 
    int count = 5;
    for (i=1; i<=count; i++) {
		printf("%d차 수행\n", i);
		
		printf("정렬할 숫자 개수를 입력하세요 : ");
    	scanf("%d", &n);

        // array 만들기 
		int *array; 
	    array = malloc(sizeof(int)*n);

        int size = sizeof(array) / sizeof(int);

	    srand((unsigned int)time(NULL)); // 매번 다른 시드값 생성 
	    int random = 0;
	    
        for (k=0; k<n; k++) {
            random = rand()%20000+1; // 난수 생성 
            array[k] = random;
        }
        
        // 정렬 시작 시간
        start = (double)clock() / CLOCKS_PER_SEC;
        
        // 정렬 함수 호출 
        heap_sort(size, array); // 100, 500, 1000, 5000, 10000

         // 정렬 끝난 시간 
        end = (double)clock() / CLOCKS_PER_SEC;

        p_time = end-start;
        printf("프로그램 수행 시간 : %.9lf\n", p_time);

        sum += p_time;
    }

    printf("각 test case에 대해 5회 반복 실행한 결과의 평균값 : %.9lf\n", sum/5);
	
    
    return 0;
}


// 힙 정렬 정리  
// struct heap
// {
//     // int S[1...n]; // S의 인덱스는 1부터 n까지
//     int *array; 
// 	    array = malloc(sizeof(int)*n);
//     int heapsize; // heapsize는 0부터 n사이의 값
// }

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void removekeys (int size, int array[])
{
    int i; // = treeSize
    for (i = size - 1; i >= 0; i--) {
        root(array, size, i);
        //swap(&arr[0], &arr[treeSize]);
        //heapify(arr, 0,treeSize);
    }
}

int root (int array[], int size, int i)
{
    int p_node;
    int *temp;

    swap(&array[0], &array[i]);
    // p_node = array[0]; // 루트에서 키값 얻기
    // array[1] = array[heapsize]; // 바닥에 있는 키를 루트로 이동
    // size = size - 1; // 바닥 노드를 삭제하기 
    siftdown(array, 0, i); // 힙을 적절하게 재정리
    
    return p_node;
}

void makeheap (int size, int array[]) // n : size
{
    int parent;
    // H.heapsize = n;
    for (parent = size/2 - 1; parent >= 0; parent--) {
        siftdown(array, parent, size); // swap
        // Max_Heapify(arr, parent, length);	// 힙 유지 실시.
        // heapify(arr, i, size);
    }
}

void heap_sort (int size, int array[])
{
    makeheap(size, array); // buildHeap(arr, size);
    removekeys(size, array);
}

// 힙성질 회복할 때까지 키값 거르기 
void siftdown (int array[], int parent, int size)
{
    int *temp;
    int left, right, largerchild;
    // parent : H의 뿌리 마디
    // largerchild : 큰 키를 가진 parent의 자식 마디 

    left = 2 * parent + 1;
    right = 2 * parent + 2;
    
    // keytype siftkey;
    bool spotfound;

    // siftkey = H.array[i];
    // parent = i;
    // spotfound = false;

    while (2 * parent <= size && !spotfound) {
        if ((2 * parent + 1) < size && (array[2 * parent + 1] > array[parent])) {
            largerchild = 2 * parent + 1;
        }
        else {
            largerchild = parent;
        }

        if ((2 * parent + 2) < size && (array[2 * parent + 2] > array[largerchild])) {
            largerchild = 2 * parent + 2;
        }
        else {
            spotfound = true;
        }

        if (largerchild != parent) {
            swap(&array[parent], &array[largerchild]);
            siftdown(array, largerchild, size);
        }
    }
    // array[parent] = siftkey;
}


