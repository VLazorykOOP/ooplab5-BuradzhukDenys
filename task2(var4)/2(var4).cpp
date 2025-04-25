#include <iostream>

using namespace std;

//Створюємо клас вузол
class Node
{
public:
	//Поля класу з данними, посиланням на лівий та правий вузол
	double data;
	Node* left;
	Node* right;

	//Конструктор
	Node(double value = 0) : data(value), left(nullptr), right(nullptr)
	{
		cout << "Node contructor(value)\n";
	}

	//Деструктор
	virtual ~Node()
	{
		cout << "Node destructor\n";
	}
};

//Стоврюємо клас бінарне дерево
class BinaryTree
{
private:
	//Поле з вказівником типу вузол
	Node* root;

	//Закритий метод для видалення всіх вузлів
	void RemoveTree(Node* node)
	{
		//Якщо зліва від поточного вузла є інший вузол, то викликаємо цей метод рекурсивно, для лівого вузла
		if (node->left != nullptr)
		{
			RemoveTree(node->left);
		}

		//Якщо справа від поточного вузла є інший вузол, то викликаємо цей метод рекурсивно, для правого вузла
		if (node->right != nullptr)
		{
			RemoveTree(node->right);
		}

		//Видаляємо поточний вузол
		delete node;
	}

	//Закритий метод для послідовного обходу дерева
	void InOrderRecursive(Node* node)
	{
		//Викликаємо цей метод рекурсивно для лівого вузла поки не дійдемо до кінця
		//Виводимо значення і аналогічно виконуємо для правого вузла
		if (node == nullptr) return;

		InOrderRecursive(node->left);
		cout << node->data << " ";
		InOrderRecursive(node->right);
	}

	//Закритий метод для зворотнього обходу дерева
	void PostOrderRecursive(Node* node)
	{
		//Викликаємо цей метод рекурсивно для лівого вузла поки не дійдемо до кінця
		//Аналогічно виконуємо для правого вузла і виводимо значення
		if (node == nullptr) return;

		InOrderRecursive(node->left);
		InOrderRecursive(node->right);
		cout << node->data << " ";
	}
public:
	//Конструктор, який встановлює корінь дерева на nullptr
	BinaryTree() : root(nullptr)
	{
		cout << "Binary tree default constructor\n";
	}

	//Деструктор, який знищує всі вузли
	~BinaryTree()
	{
		Clear();
		cout << "Binary tree destructor\n";
	}

	//Метод ставлення вузлів
	void insert(const double val)
	{
		//Якщо корінь нікуди не вказує, то вставляємо в нього вузол
		if (root == nullptr)
		{
			root = new Node(val);
			return;
		}

		Node* node = root;

		//Поки не знайдемо місце яке вказує на nullptr
		while (node != nullptr)
		{
			//Якщо значення, яке ми вставляємо дорівнює поточному вузлу
			if (node->data == val)
			{
				//Виводимо помилку
				cout << "Repeated meaning, " << val << " was not insert\n";
				return;
			}
			//Інкше, якщо значення, яке ми вставляємо менше за поточний вузол
			else if (node->data > val)
			{
				//Якщо зліва від поточного вузла нічого немає, вставляємо туди цей вузол
				if (node->left == nullptr)
				{
					node->left = new Node(val);
					return;
				}

				//Якщо зліва від поточного вузла є вузол, то робимо його поточним
				node = node->left;
			}
			//Інкше, якщо значення, яке ми вставляємо більше за поточний вузол
			else
			{	//Якщо справа від поточного вузла нічого немає, вставляємо туди цей вузол
				if (node->right == nullptr)
				{
					node->right = new Node(val);
					return;
				}

				//Якщо справа від поточного вузла є вузол, то робимо його поточним
				node = node->right;
			}
		}
	}

	//Метод видалення всіх вузлів
	void Clear()
	{
		//Якщо корінь не пустий видаляємо вузли
		if (root != nullptr)
		{
			RemoveTree(root);
			root = nullptr;
		}
	}

	//Метод для виводу значень послідовним обзодом
	void InOrderShow()
	{
		cout << "In order traversal: ";
		InOrderRecursive(root);
		cout << endl;
	}

	//Метод для виводу значень зворотнім обходом
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