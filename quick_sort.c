#include<stdio.h>
#include<stdlib.h> // rand() �Լ� ���� ���̺귯�� 
#include<time.h> // time() �Լ� ���� ���̺귯��

// �� ���� ����  
void quick_sort(int array[], int low, int high) {
    int pivotpoint;

    if (low <= high) {
        int pivotpoint = partition(array, low, high); // �ǹ�����Ʈ�� �������� ���� ���������� ������  
        quick_sort(array, low, pivotpoint-1); // ���� ���� ����
        quick_sort(array, pivotpoint+1, high); // ������ ���� ���� 
    }
}

// �� ���� �ð� ���� 
int partition(int array[], int low, int high) {

    // �� ���� �˰��� ���� 

    int pivotitem;
    pivotitem = array[low]; // ù��° ���Ҹ� �ǹ����� ���Ѵ�.

    int i = low + 1;
    int j = high;

    // j = low-1; // ������ ����� �ε����� �ǹ����� �۴�.

    for (i = low + 1; i<=high; i++) {
        while (i <= high && pivotitem >= array[i]) // �ǹ����� ū ���� ã�� ���� 
        {
            i++; // low�� ���������� �̵� 
        }
        while (j >= (low + 1)  && pivotitem <= array[high]) // �ǹ����� ���� ���� ã�� ���� 
        {
            high--; // high�� �������� �̵�
        }
        if (i <= j) {
            // j++;
            exchange(array, i, j);
        }
    }
    exchange(array, low, j);

    return j; // �ٲ� �Ǹ��� ��ġ ������ ��ȯ 

}

void exchange(int array[], int ap, int bp) 
{
    int temp;
    temp = array[ap];
    array[ap] = array[bp];
    array[bp] = temp;
}


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

		int *array; 
	    array = malloc(sizeof(int)*n);
	    srand((unsigned int)time(NULL)); // �Ź� �ٸ� �õ尪 ���� 
	    int random = 0;
	    
        for (k=0; k<n; k++) {
            random = rand()%20000+1; // ���� ���� 
            array[k] = random;
        }
        
        // ���� ���� �ð�
        start = (double)clock() / CLOCKS_PER_SEC;
        
        // ���� �Լ� ȣ�� 
        quick_sort(array, 0, n-1); // 100, 500, 1000, 5000, 10000

         // ���� ���� �ð� 
        end = (double)clock() / CLOCKS_PER_SEC;

        p_time = end-start;
        printf("���α׷� ���� �ð� : %.9lf\n", p_time);

        sum += p_time;
    }

    printf("�� test case�� ���� 5ȸ �ݺ� ������ ����� ��հ� : %.9lf\n", sum/5);
	
    
    return 0;
}

