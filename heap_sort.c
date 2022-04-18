#include<stdio.h>
#include<stdlib.h> // rand() �Լ� ���� ���̺귯�� 
#include<time.h> // time() �Լ� ���� ���̺귯��
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
    double sum = 0; // ���� ��� �ð� ����
    	
    // 5���� �ݺ� ���� 
    int count = 5;
    for (i=1; i<=count; i++) {
		printf("%d�� ����\n", i);
		
		printf("������ ���� ������ �Է��ϼ��� : ");
    	scanf("%d", &n);

        // array ����� 
		int *array; 
	    array = malloc(sizeof(int)*n);

        int size = sizeof(array) / sizeof(int);

	    srand((unsigned int)time(NULL)); // �Ź� �ٸ� �õ尪 ���� 
	    int random = 0;
	    
        for (k=0; k<n; k++) {
            random = rand()%20000+1; // ���� ���� 
            array[k] = random;
        }
        
        // ���� ���� �ð�
        start = (double)clock() / CLOCKS_PER_SEC;
        
        // ���� �Լ� ȣ�� 
        heap_sort(size, array); // 100, 500, 1000, 5000, 10000

         // ���� ���� �ð� 
        end = (double)clock() / CLOCKS_PER_SEC;

        p_time = end-start;
        printf("���α׷� ���� �ð� : %.9lf\n", p_time);

        sum += p_time;
    }

    printf("�� test case�� ���� 5ȸ �ݺ� ������ ����� ��հ� : %.9lf\n", sum/5);
	
    
    return 0;
}


// �� ���� ����  
// struct heap
// {
//     // int S[1...n]; // S�� �ε����� 1���� n����
//     int *array; 
// 	    array = malloc(sizeof(int)*n);
//     int heapsize; // heapsize�� 0���� n������ ��
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
    // p_node = array[0]; // ��Ʈ���� Ű�� ���
    // array[1] = array[heapsize]; // �ٴڿ� �ִ� Ű�� ��Ʈ�� �̵�
    // size = size - 1; // �ٴ� ��带 �����ϱ� 
    siftdown(array, 0, i); // ���� �����ϰ� ������
    
    return p_node;
}

void makeheap (int size, int array[]) // n : size
{
    int parent;
    // H.heapsize = n;
    for (parent = size/2 - 1; parent >= 0; parent--) {
        siftdown(array, parent, size); // swap
        // Max_Heapify(arr, parent, length);	// �� ���� �ǽ�.
        // heapify(arr, i, size);
    }
}

void heap_sort (int size, int array[])
{
    makeheap(size, array); // buildHeap(arr, size);
    removekeys(size, array);
}

// ������ ȸ���� ������ Ű�� �Ÿ��� 
void siftdown (int array[], int parent, int size)
{
    int *temp;
    int left, right, largerchild;
    // parent : H�� �Ѹ� ����
    // largerchild : ū Ű�� ���� parent�� �ڽ� ���� 

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


