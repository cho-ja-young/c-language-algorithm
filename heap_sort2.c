#include<stdio.h>
#include<stdlib.h> // rand() �Լ� ���� ���̺귯�� 
#include<time.h> // time() �Լ� ���� ���̺귯��
typedef int bool;
#define true 1
#define false 0

void swap(int *a, int *b);
void removekeys (int* array, int size);
void root (int* array, int size);
void makeheap (int* array, int size); // n : size
void heap_sort (int* array, int size);
void siftdown (int* array, int size, int parent);

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
        heap_sort(array, size); // 100, 500, 1000, 5000, 10000

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

void removekeys (int* array, int size)
{
    int temp; // = treeSize
    while(size > 1) {
        root(array, size);
        //swap(&arr[0], &arr[treeSize]);
        //heapify(arr, 0,treeSize);
    }
}

void root (int* array, int size)
{
    swap(&array[0], &array[size-1]);
    // p_node = array[0]; // ��Ʈ���� Ű�� ���
    // array[1] = array[heapsize]; // �ٴڿ� �ִ� Ű�� ��Ʈ�� �̵�
    // size = size - 1; // �ٴ� ��带 �����ϱ� 
    siftdown(array, size, 0); // ���� �����ϰ� ������
    
}

void makeheap (int* array, int size) // n : size
{
    int parent = size/2-1;
    // H.heapsize = n;
    for (parent; parent >= 0; parent--) {
        siftdown(array, size, parent); // swap
        // Max_Heapify(arr, parent, length);	// �� ���� �ǽ�.
        // heapify(arr, i, size);
    }
}

void heap_sort (int* array, int size)
{
    makeheap(array, size); // buildHeap(arr, size);
    int temp;
    while(size > 1){
        temp = array[0];
        array[0] = array[size-1];
        array[size-1] = temp;
        
        size--;
        siftdown(array, size, 0);
    }
}

// ������ ȸ���� ������ Ű�� �Ÿ��� 
void siftdown (int* array, int size, int parent)
{
    int temp;
    int left, right, largerchild;
    int parent_node = parent; // parent node index
    // parent : H�� �Ѹ� ����
    // largerchild : ū Ű�� ���� parent�� �ڽ� ���� 

    left = 2 * parent + 1;
    right = 2 * parent + 2;
    
    largerchild = parent_node;
    
    // keytype siftkey;

    // siftkey = H.array[i];
    // parent = i;
    // spotfound = false;

    if (left < size && (array[left] > array[largerchild])) {
        largerchild = left;
    }

    if (right < size && (array[right] > array[largerchild])) {
        largerchild = right;
    }

    if(parent_node != largerchild){
        temp = array[largerchild];
        array[largerchild] = array[parent_node];
        array[parent_node] = temp;

        siftdown(array, size, largerchild);
    }
    // array[parent] = siftkey;
}


