#include<stdio.h>
#include<stdlib.h> // rand() �Լ� ���� ���̺귯�� 
#include<time.h> // time() �Լ� ���� ���̺귯��

// ���� ���� ����  
void merge_sort(int array[], int left, int right) {
    int middle;

    if (left < right) {
        middle = (left+right)/2; // �߰� ��ġ ���
        merge_sort(array, left, middle); // ���� ����Ʈ ���� 
        merge_sort(array, middle+1, right); // ���� ����Ʈ ���� 
        merge(array, left, middle, right); // �ΰ��� �κ� �迭�� ����
    }
}

// �պ� ���� �ð� ���� 
void merge(int array[], int left, int middle, int right) {

    // ���� ���� �˰��� ���� 
    int i = left;
	int j = middle+1;
	int k = left;
	int n = right+1;
	int l = 0;

    int *tmp; 
    tmp = malloc(sizeof(int)*n); // ���ο� �迭  

    // ���� ���ĵ� array ���� 
    while (i<=middle && j<=right) {
        if (array[i]<=array[j]) {
            tmp[k++] = array[i++];
        }
        else {
            tmp[k++] = array[j++];
        }
    }

	// ���� �ִ� ������ �ϰ� ����
    while(i<=middle) {
    	tmp[k++] = array[i++];
	}
	
	// ���� �ִ� ������ �ϰ� ����
    while(j<=right) {
    	tmp[k++] = array[j++];
	}

    // �迭 tmp[](�ӽ� �迭)�� ����Ʈ�� �迭 array[]�� �纹��
    for(l = left; l <= right; l++) {
        array[l] = tmp[l];
    }

}

int main(void)
{
	int i, j, temp, n, k;
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
        merge_sort(array, 0, n-1); // 100, 500, 1000, 5000, 10000

         // ���� ���� �ð� 
        end = (double)clock() / CLOCKS_PER_SEC;

        p_time = end-start;
        printf("���α׷� ���� �ð� : %.9lf\n", p_time);

        sum += p_time;
    }

    printf("�� test case�� ���� 5ȸ �ݺ� ������ ����� ��հ� : %.9lf\n", sum/5);
	
    
    return 0;
}
