#include <iostream>

using namespace std;

typedef struct node {
	int a;
	node* prev;
	node* next;
}node;

typedef struct node_structure {
	node* head;
	node* tail;
	
	int size;
}node_structure;


class link {
public:
	link();
	~link();
	node_structure* init();

	void insert(int idx, int num);
	void remove(int idx);
	void linked_push(int input1);
	void print();
	void reverse_print();
	void new_structure_size();

	node* linked_list = new node;


private:
	node_structure* new_structure;

};



void link::linked_push(int input1) {
	node* newNode = new node;
	node* preNode = new_structure->head;

	newNode->a = input1;

	if (new_structure->size == 0) {
		new_structure->head = newNode;
	}
	else {
		
		preNode = new_structure->tail;
		
		preNode->next = newNode;
		newNode->prev = preNode;
	}

	new_structure->tail = newNode;
	new_structure->size++;
	if (new_structure->head != NULL) {
		new_structure->head->prev = new_structure->tail;
		new_structure->tail->next = new_structure->head;
	}
	return;
}

link::link() {
	new_structure = new node_structure;
	new_structure->head = NULL;
	new_structure->tail = NULL;
	new_structure->size = 0;
}

link::~link() {
	delete new_structure;
}

void link::print() {
	node* current_Node = new_structure->head;

	for (int i=0; i < new_structure->size;i++) {
		cout << i << "번째 노드 값 : " << current_Node->a << endl;
		current_Node = current_Node->next;
	}
	return;
}

void link::reverse_print() {
	node* current_Node = new_structure->tail;

	for (int i = new_structure->size ; 0 < i;i--) {
		cout << i-1 << "번째 노드 값 : " << current_Node->a << endl;
		current_Node = current_Node->prev;
	}
	return;
}

void link::new_structure_size() {
	cout << " ※현재 연결 리스트 노드의 수※ : " << new_structure->size << endl;
}

void link::insert(int idx, int num) {
	if (new_structure->size < idx) {
		cout << "insert fail" << endl;
		return;
	}

	node* newNode = new node;
	node* preNode = new_structure->head;
	newNode->a = num;

	for (int i = 1; i < idx; i++) {
		preNode = preNode->next;
	}

	newNode->prev = preNode;
	newNode->next = preNode->next;
	preNode->next = newNode;
	newNode->next->prev = newNode;

	if (new_structure->size == idx) new_structure->tail = newNode;
	new_structure->size++;

	return;
}

void link::remove(int idx) {
	node* curNode = new_structure->head;
	if (idx < 0 || idx >= new_structure->size){
		cout << " 지울 index가 존재하지 않습니다." << endl;
		return;
	}
	for (int i = 1; i <= idx; i++) {
		curNode = curNode->next;
	}

	if (idx == 0) {
		if (new_structure->size == 1) {
			new_structure->head = NULL;
			new_structure->tail = NULL;
			new_structure->size--;
			return;
		}
		new_structure->head = curNode->next;
		new_structure->head->prev = new_structure->tail;
		new_structure->tail->next = new_structure->head;

		delete curNode;
	}

	else if (new_structure->size - 1 != idx) {
		curNode->prev->next = curNode->next;
		curNode->next->prev = curNode->prev;

		delete curNode;
	}

	else if (new_structure->size - 1 == idx) {
		new_structure->tail = curNode->prev;
		curNode->prev->next = new_structure->head;

		delete curNode;
	}

	new_structure->size--;
	return;
}

int main() {
	link* linked_list = new link();
	int input_a,input_b;
	while (1) {
		cout << " 1: 입력" << endl;
		cout << " 2: 중간 입력" << endl;
		cout << " 3: 삭제 " << endl;
		cout << " 4: 출력 " << endl;
		cout << " 5: 역출력" << endl;
		cout << " 6: 프로그램 종료 " << endl;
		int l;
		cout << " 사용 할 프로그램 번호 :  ";
		cin >> l;
		switch (l) {


			int k;
		case 1:
			cout << "입력할 리스트의 수 : ";
			cin >> k;
			for (int i = 0;i < k;i++) {
				cout << i << "번째 노드의 값 : ";
				cin >> input_a;
				linked_list->linked_push(input_a);
			}
			cout << "현재 입력된 값 : " << endl;;
			linked_list->print();
			continue;
			
		case 2:
			cout << " 중간 삽입 할 번호 : ";
			cin >> input_a;
			linked_list->new_structure_size();
			cout << "삽입 할 값  : ";
			cin >> input_b;
			linked_list->insert(input_a, input_b);

			cout << "현재 입력된 값 : " << endl;;
			linked_list->print();
			continue;
		case 3:
			cout << "삭제할 리스트 번호 : ";
			cin >> k;
			linked_list->remove(k);

			cout << "현재 입력된 값 : " << endl;;
			linked_list->print();
			continue;
		case 4:
			
			linked_list->print();
			continue;
		case 5:
			linked_list->reverse_print();
			continue;
		case 6:
			break;
		}
		break;
	}
	
	delete linked_list;

	return 0;
}
