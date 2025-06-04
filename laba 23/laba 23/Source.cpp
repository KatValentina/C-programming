#include <iostream>
#include "Header.h"
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

//������� ��� �������� ������������ �����
bool korrec(const string& a) {
	if (a.empty())
		return false;// ������ ����

	for (char c : a) {
		if (!isdigit(c)) { // ���������, ��� ��� ������� - �����
			return false;
		}
	}

	return true;
}

void merge(UNode& head, UNode left, UNode right) {//��������� 2 ������ ������
	if (!left) {
		head = right;
		return;
	}
	if (!right) {
		head = left;
		return;
	}

	if (left->x <= right->x) {
		head = left;
		merge(head->next, left->next, right);
		if (head->next) head->next->prev = head;
	}
	else {
		head = right;
		merge(head->next, left, right->next);
		if (head->next) head->next->prev = head;
	}

	head->prev = nullptr;
}

void split(UNode& p, UNode& left, UNode& right) {//����� ������ �� ��� �����
	UNode fast = p;
	UNode slow = p;
	UNode prev = nullptr;

	while (fast && fast->next) {
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (prev) prev->next = nullptr;
	left = p;
	right = slow;

	if (right) right->prev = nullptr;
}

void mergeSort(UNode& head) {//������� ��� ���������� ������
	if (!head || !head->next) return;

	UNode left = nullptr;
	UNode right = nullptr;

	split(head, left, right);

	mergeSort(left);
	mergeSort(right);

	merge(head, left, right);
}

//���������� �������� � ������ � �����
void AddLast(UNode& Head, UNode& Tail, int x)
{
	UNode NewUsel = new Usel;
	NewUsel->next = NULL;
	NewUsel->prev = Tail;
	NewUsel->x = x;
	if (Tail) Tail->next = NewUsel;
	Tail = NewUsel;
	if (Head == NULL) Head = Tail; // ���� ������� � ������ 
}

//���������� ������ � ����������
void Board(UNode& Tree, UNode& Tail) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string n, x;
	cout << "������� ���������� ���������: ";
	getline(cin, n);

	while (!korrec(n)) {
		cout << "\n������������ ����, ��������� ����: ";
		getline(cin, n);
	}

	for (int i = 0; i < stoi(n); i++) {
		cout << "������� ����: ";
		getline(cin, x);
		while (!korrec(x)) {
			cout << "\n������������ ����, ������� �����: ";
			getline(cin, x);
		}
		AddLast(Tree, Tail, stoi(x));
	}
}

//���������� ������ ��������
void Rand(UNode& Tree, UNode& Tail) {
	srand(time(0));
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string n;
	int a;
	cout << "������� ���������� ���������: ";
	getline(cin, n);

	while (!korrec(n)) {
		cout << "\n������������ ����, ��������� ����: ";
		getline(cin, n);
	}
	for (int i = 0; i < stoi(n); i++) {
		a = (rand() % 100) + 1;
		AddLast(Tree, Tail, a);
	}
}

//���������� ������ �� �����
void File(UNode& Tree, UNode& Tail) {
	int x;
	fstream f;
	bool isLeft = true; // �������� � ������ ���������
	f.open("Spisok.txt");
	if (!f.is_open()) {
		cout << "��������� �������!";
		return;
	}
	if (!(f >> x)) {
		cout << "���� ���� ��� �������� ������������ ������, ��������� �������" << endl;
		return;
	}
	cout << "������������ � ����� ��������: " << endl;
	do {
		cout << x << " ";
		AddLast(Tree, Tail, x);
	} while (f >> x);
}

//����� ������
void PrintSpisok(UNode& Tree, UNode& Tail) {
	if (Tree == NULL) {
		cout << "������ ������!";
	}
	else {
		UNode p = Tree;
		cout << "\n������������ ������: " << endl;
		while (p) {
			cout << p->x << " ";
			p = p->next;
		}
	}
}

void AddToTree(PNode& Tree, UNode& Head) {
	if (!Head) {
		return; 
	}

	// ������� ������� ������� ������
	UNode slow = Head;
	UNode fast = Head;
	UNode prev = nullptr;

	// ���������� ��� ��������� ��� ���������� �������� ��������
	while (fast && fast->next) {
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	// slow �� ������� �������
	Tree = new Node; 
	Tree->key = slow->x; 
	Tree->left = nullptr;
	Tree->right = nullptr;

	// ������ ����� ��������� ������ �� ����� � ������ �������
	if (prev) {
		prev->next = nullptr; // ��������� ������ �� ��� �����
		AddToTree(Tree->left, Head); 
	}

	// �������� ������� ������� �� ����� ����� ������
	UNode rightHead = slow->next; 
	slow->next = nullptr; 
	AddToTree(Tree->right, rightHead); 
}



// ���������� �������� � �������� ������ 
void AddToOneEl(PNode& Tree, int data)
{
	if (!Tree) {
		Tree = new Node;
		Tree->key = data;
		Tree->left = NULL;
		Tree->right = NULL;
		return;
	}

	queue<PNode> q;//���������� ������� ��� ��������
	q.push(Tree);

	while (!q.empty()) {
		PNode current = q.front();
		q.pop();

		if (!current->left) {
			current->left = new Node;
			current->left->key = data;
			current->left->left = NULL;
			current->left->right = NULL;
			return;
		}
		else if (!current->right) {
			current->right = new Node;
			current->right->key = data;
			current->right->left = NULL;
			current->right->right = NULL;
			return;
		}
		else {
			q.push(current->left);
			q.push(current->right);
		}
	}
}


//���������� ��������� � ������ � ����������
void Keyboard(PNode& Tree) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	bool isLeft = true; // �������� � ������ ���������

	string n, x;
	cout << "������� ���������� ���������: ";
	getline(cin, n);

	while (!korrec(n)) {
		cout << "\n������������ ����, ��������� ����: ";
		getline(cin, n);
	}

	for (int i = 0; i < stoi(n); i++) {
		cout << "������� ����: ";
		getline(cin, x);
		while (!korrec(x)) {
			cout << "\n������������ ����, ������� �����: ";
			getline(cin, x);
		}
		// ������������� �������� �����������
		AddToOneEl(Tree,stoi( x));
	}
}

//���������� ������ ���������� �������
void Random(PNode& Tree) {
	srand(time(0));
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string n;
	int x;
	bool isLeft = true; // �������� � ������ ���������
	cout << "������� ���������� ���������: ";
	getline(cin, n);

	while (!korrec(n)) {
		cout << "\n������������ ����, ��������� ����: ";
		getline(cin, n);
	}
	for (int i = 0; i < stoi(n); i++) {
		x = (rand() % 100) + 1;
		AddToOneEl(Tree, x);
	}
}

//���������� ������ �� �����
void ToFile(PNode& Tree) {
	int x;
	fstream f;
	bool isLeft = true; // �������� � ������ ���������
	f.open("Tree.txt");
	if (!f.is_open()) {
		cout << "��������� �������!";
		return;
	}
	if (!(f >> x)) {
		cout << "���� ���� ��� �������� ������������ ������, ��������� �������";
		return;
	}
	cout << "������������ � ����� ��������: " << endl;
	do {
		cout << x << " ";
		AddToOneEl(Tree, x);
	} while (f >> x);
}

//����� ������
void Print(PNode& Tree, string const& rpref, string const& cpref, string const& lpref) {
	if (!Tree) return;
	if (Tree->right)
		Print(Tree->right, rpref + "   ", rpref + " +--", rpref + " | ");
	cout << cpref << to_string(Tree->key) << endl;
	if (Tree->left)
		Print(Tree->left, lpref + " | ", lpref + " +--", lpref + "   ");
}

//����� ������ � ������� ������-�����-����
vector<int> inOrder(Node* root) {
	vector<int> res;
	Node* curr = root;

	while (curr != nullptr) {
		// ���� ��� ������� �������, ������ ����� �������� ������� ����
		if (curr->right == nullptr) {
			res.push_back(curr->key);
			curr = curr->left;
		}
		else {
			// ������� ������ ������� �������� ����
			Node* prev = curr->right;

			// ���� ����� ����� ���� � ������ ���������
			while (prev->left != nullptr && prev->left != curr) {
				prev = prev->left;
			}

			// ���� ����� ��������� ��������, ������ ����� ������� � ������ ���������
			if (prev->left == nullptr) {
				res.push_back(curr->key); 
				prev->left = curr;        
				curr = curr->right;       
			}
			else {
				// ���� ����� ��� ����, ������ ����� ������� � ����� ���������
				prev->left = nullptr;      
				curr = curr->left;
			}
		}
	}

	return res;
}


