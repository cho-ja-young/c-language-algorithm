#include<stdio.h>
#include<stdlib.h> // rand() �Լ� ���� ���̺귯�� 
#include<time.h> // time() �Լ� ���� ���̺귯��

//��ȯ ���� �ð� ���� 
double exchange_sort() {
    double start, end;
    double p_time = 0;

    
    // ��ȯ ���� �˰��� ���� 
    int i, j, temp, n;
    printf("������ ���� ������ �Է��ϼ��� : ");
    scanf("%d", &n);
    int *array; 
    array = malloc(sizeof(int)*n);
    srand((unsigned int)time(NULL)); // �Ź� �ٸ� �õ尪 ���� 
    int random = 0;
	
	// ���� ���� �ð�
    start = (double)clock() / CLOCKS_PER_SEC;

    for (i=0; i<n; i++) {
        random = rand()%20000+1; // ���� ���� 
        array[i] = random;
    }

    for (i=0; i<(n-1); i++) {
        for (j=(i+1); j<n; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
	

    // ���� ���� �ð� 
    end = (double)clock() / CLOCKS_PER_SEC;

    p_time = end-start;
    printf("���α׷� ���� �ð� : %.9lf\n", p_time);

    return p_time;
}

int main(void)
{
    int i, j = 0; 
    double sum = 0; // ���� ��� �ð� ����

    // 5���� �ݺ� ���� 
    int count = 5;
    for (i=1; i<=count; i++) {
        printf("%d�� ����\n", i);
        // ���� �Լ� ȣ�� 
        sum += exchange_sort(); // 100, 500, 1000, 5000, 10000
    }

    printf("�� test case�� ���� 5ȸ �ݺ� ������ ����� ��հ� : %.9lf\n", sum/5);
	
    
    return 0;
}
