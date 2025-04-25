#include <iostream>

using namespace std;

//��������� ���� �����
class Node
{
public:
	//���� ����� � �������, ���������� �� ���� �� ������ �����
	double data;
	Node* left;
	Node* right;

	//�����������
	Node(double value = 0) : data(value), left(nullptr), right(nullptr)
	{
		cout << "Node contructor(value)\n";
	}

	//����������
	virtual ~Node()
	{
		cout << "Node destructor\n";
	}
};

//��������� ���� ������ ������
class BinaryTree
{
private:
	//���� � ���������� ���� �����
	Node* root;

	//�������� ����� ��� ��������� ��� �����
	void RemoveTree(Node* node)
	{
		//���� ���� �� ��������� ����� � ����� �����, �� ��������� ��� ����� ����������, ��� ����� �����
		if (node->left != nullptr)
		{
			RemoveTree(node->left);
		}

		//���� ������ �� ��������� ����� � ����� �����, �� ��������� ��� ����� ����������, ��� ������� �����
		if (node->right != nullptr)
		{
			RemoveTree(node->right);
		}

		//��������� �������� �����
		delete node;
	}

	//�������� ����� ��� ����������� ������ ������
	void InOrderRecursive(Node* node)
	{
		//��������� ��� ����� ���������� ��� ����� ����� ���� �� ������ �� ����
		//�������� �������� � ��������� �������� ��� ������� �����
		if (node == nullptr) return;

		InOrderRecursive(node->left);
		cout << node->data << " ";
		InOrderRecursive(node->right);
	}

	//�������� ����� ��� ����������� ������ ������
	void PostOrderRecursive(Node* node)
	{
		//��������� ��� ����� ���������� ��� ����� ����� ���� �� ������ �� ����
		//��������� �������� ��� ������� ����� � �������� ��������
		if (node == nullptr) return;

		InOrderRecursive(node->left);
		InOrderRecursive(node->right);
		cout << node->data << " ";
	}
public:
	//�����������, ���� ���������� ����� ������ �� nullptr
	BinaryTree() : root(nullptr)
	{
		cout << "Binary tree default constructor\n";
	}

	//����������, ���� ����� �� �����
	~BinaryTree()
	{
		Clear();
		cout << "Binary tree destructor\n";
	}

	//����� ��������� �����
	void insert(const double val)
	{
		//���� ����� ����� �� �����, �� ���������� � ����� �����
		if (root == nullptr)
		{
			root = new Node(val);
			return;
		}

		Node* node = root;

		//���� �� �������� ���� ��� ����� �� nullptr
		while (node != nullptr)
		{
			//���� ��������, ��� �� ���������� ������� ��������� �����
			if (node->data == val)
			{
				//�������� �������
				cout << "Repeated meaning, " << val << " was not insert\n";
				return;
			}
			//�����, ���� ��������, ��� �� ���������� ����� �� �������� �����
			else if (node->data > val)
			{
				//���� ���� �� ��������� ����� ����� ����, ���������� ���� ��� �����
				if (node->left == nullptr)
				{
					node->left = new Node(val);
					return;
				}

				//���� ���� �� ��������� ����� � �����, �� ������ ���� ��������
				node = node->left;
			}
			//�����, ���� ��������, ��� �� ���������� ����� �� �������� �����
			else
			{	//���� ������ �� ��������� ����� ����� ����, ���������� ���� ��� �����
				if (node->right == nullptr)
				{
					node->right = new Node(val);
					return;
				}

				//���� ������ �� ��������� ����� � �����, �� ������ ���� ��������
				node = node->right;
			}
		}
	}

	//����� ��������� ��� �����
	void Clear()
	{
		//���� ����� �� ������ ��������� �����
		if (root != nullptr)
		{
			RemoveTree(root);
			root = nullptr;
		}
	}

	//����� ��� ������ ������� ���������� �������
	void InOrderShow()
	{
		cout << "In order traversal: ";
		InOrderRecursive(root);
		cout << endl;
	}

	//����� ��� ������ ������� �������� �������
	void PostOrderShow()
	{
		cout << "Post order traversal: ";
		PostOrderRecursive(root);
		cout << endl;
	}
};

int main()
{
	BinaryTree tree1;

	tree1.insert(5);
	tree1.insert(4);
	tree1.insert(51);
	tree1.insert(6);
	tree1.insert(4);
	tree1.insert(1);
	
	tree1.InOrderShow();
	tree1.PostOrderShow();
}