#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__
 
#define TRUE 1
#define FALSE 0
 
typedef int Data; 
 
typedef struct _node
{
    Data data;
    struct _node *next; // 이렇게 struct포인터로 지정하는 이유는 보통 
                        //int a = 8; int *b; b = &a; 라고 하듯이 서로 자료형을 맞추어주는것이다
}Node;
 
typedef struct _lQueue
{
    Node *front;
    Node *rear;
} LQueue;
 
typedef LQueue Queue;
 
void QueueInit(Queue *pq); // 큐 초기화
int QIsEmpty(Queue *pq); // 큐가 비어있는지 확인하는 함수
 
void Enqueue(Queue *pq, Data data); // 큐에 값 넣을때
Data Dequeue(Queue *pq); // 큐에서 값 뺄때
Data QPeek(Queue *pq); 
 
#endif


// 출처: https://www.crocus.co.kr/280 [Crocus]
