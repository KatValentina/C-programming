#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//�������� ���� ��������� ������
class Node
{
public:
	int key; // �������������� ���� (����)
	Node* left, * right; // ��������� �� �������
};
typedef Node* PNode; // ��������� �� �������

//�������� ���� ������������ ������
class Usel
{
public:
	int x;
	Usel* next, * prev; // ������ �� �������� ���� 
};
typedef Usel* UNode; // ��� ������ ���������� �� ���� 

//���������� �������� � ������ � �����
void AddLast(UNode& Head, UNode& Tail, int x);

//�������� �� ���������� ����
bool korrec(const string& a);

//���������� ������ � ����������
void Board(UNode& Tree, UNode& Tail);

//���������� ������ ��������
void Rand(UNode& Tree, UNode& Tail);

//���������� ������ �� �����
void File(UNode& Tree, UNode& Tail);

//����� ������
void PrintSpisok(UNode& Tree, UNode& Tail);


//���������� ������� �� ������
void merge(UNode& head, UNode left, UNode right);
void split(UNode& source, UNode& left, UNode& right);
void mergeSort(UNode& head);

void AddToTree(PNode& Tree, UNode& Head);

//���������� �������� � ������
void AddToOneEl(PNode& Tree, int data);

//���������� ��������� � ������
void Keyboard(PNode& Tree);

//���������� ������ ���������� �������
void Random(PNode& Tree);

//���������� ������ �� �����
void ToFile(PNode& Tree);

//����� ������
void Print(PNode& Tree, string const& rpref, string const& cpref, string const& lpref);

//����� ������ ������-�����-����
vector<int> inOrder(Node* root);