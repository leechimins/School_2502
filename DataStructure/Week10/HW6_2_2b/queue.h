typedef int element;	// 요소의 타입
typedef struct QueueNode {	// 큐의 노드의 타입 
	element item;
	struct QueueNode* link;
} QueueNode;
typedef struct {		// 큐 ADT 구현
	QueueNode* front, * rear;
} QueueType;

void error(char* message);

// 초기화 함수
void init(QueueType* q);

// 공백 상태 검출 함수
int is_empty(QueueType* q);

// 포화 상태 검출 함수
int is_full(QueueType* q);

// 삽입 함수
void enqueue(QueueType* q, element item);

// 삭제 함수
element dequeue(QueueType* q);