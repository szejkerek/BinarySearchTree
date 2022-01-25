#pragma once
#include <fstream>
#include <iostream>
#include <memory>

template<class T>
class BST
{
private:
	template<class T>
	class node {
	public:
		T val;
		std::unique_ptr<node> left;
		std::unique_ptr<node> right;


		node(T& _val) : val(_val), left(nullptr), right(nullptr) {}
		node() : val(NULL), left(nullptr), right(nullptr) {}
		node(node&& n) : val(n.val), left(n.left), right(n.right)
		{
			n.val = NULL;
			n.left = nullptr;
			n.right = nullptr;
		}

		void deleteNode()
		{
			val = NULL;
			left = nullptr;
			right = nullptr;
		}
		friend std::ostream& operator<<(std::ostream& out, node<T>& nod)
		{

			out << "----------------" << std::endl;

				out << "Value: " << nod.val << std::endl;

			if (nod.left == NULL)
				out << "Left: " << "NULL" << std::endl;
			else
				out << "Left: " << nod.left << std::endl;

			if (nod.right == NULL)
				out << "Right: " << "NULL" << std::endl;
			else
				out << "Right: " << nod.right;

					return out;
		}
	}; 

	
	std::unique_ptr<node<T>> root; //ROOT

	//Prywatne metody
	void _insert(std::unique_ptr<node<T>>& current, T value);
	node<T>* _search(std::unique_ptr<node<T>>& current, T key);
	void _copy(std::unique_ptr<BST<T>::node<T>>& mainRoot, std::unique_ptr<BST<T>::node<T>>& destiniationRoot);
	int _height(std::unique_ptr<BST<T>::node<T>>& current);
	void _inorderTraversal(std::unique_ptr<BST<T>::node<T>>& current);
	void _postorderTraversal(std::unique_ptr<BST<T>::node<T>>& current);
	void _preorderTraversal(std::unique_ptr<BST<T>::node<T>>& current);
	void _deleteTree(std::unique_ptr<BST<T>::node<T>>& current);

	//Operacje na plikach
	void _saveToFile(std::unique_ptr<BST<T>::node<T>>& current, std::ostream& ofile);
	void _loadFromFile(std::unique_ptr<BST<T>::node<T>>& current, std::ifstream& ifile);
	void _serializeBinary(std::unique_ptr<BST<T>::node<T>>& current, std::ostream& ofile);
	void _deserializeBinary(std::unique_ptr<BST<T>::node<T>>& current, std::ifstream& ifile);

public:
	//Konstruktor bezargumentowy
	BST();

	//Konstruktor jednoargumentowy
	BST(const T& val);

	//Konstruktor przenosz¹cy
	BST(BST&& tree);

	//Konstruktor kopiuj¹cy
	BST(BST& tree);
	
	//Wstawianie elementu
	void insert(T value);

	//Wyszukiwanie danego elementu drzewa po wartoœci
	T* search(T value);

	//Funkcja zwracaj¹ca wysokoœæ drzewa
	int height();

	//Usuniêcie ca³ego drzewa
	void deleteTree();


	void inorderTraversal();
	void postorderTraversal();
	void preorderTraversal();

	//Serializacja danych do pliku
	void saveToFile();
	void saveToFile(std::string file_name);
	void serializeBinary(std::string file_name);


	//Deserializacja danych z pliku
	void loadFromFile();
	void loadFromFile(std::string file_name);
	void deserializeBinary(std::string file_name);
	

	//Operator przeniesienia
	BST<T>& operator=(BST&& tree);
	//Operator przypisania
	BST<T>& operator=(BST& tree);
	
};

template<class T>
inline void BST<T>::_insert(std::unique_ptr<BST<T>::node<T>>& current, T value)
{
	if (current == nullptr)
	{
		current = std::make_unique<node<T>>(value);
		return;
	}

	if (value < current->val)
	{
		_insert(current->left, value);
	}
	else
	{
		_insert(current->right, value);
	}
}

template<class T>
inline BST<T>::node<T>* BST<T>::_search(std::unique_ptr<BST<T>::node<T>>& current, T key)
{
	if (current != NULL)
	{
		if (key == current->val)
		{
			return current.get();
		}

		if (key < current->val)
		{
			return _search(current->left, key);
		}
		else
		{
			return _search(current->right, key);
		}
	}
	else
	{
		return NULL;
	}
}

template<class T>
inline void BST<T>::_copy(std::unique_ptr<BST<T>::node<T>>& mainRoot, std::unique_ptr<BST<T>::node<T>>& otherRoot)
{
	if (otherRoot == NULL)
	{
		return;
	}
	_insert(mainRoot, otherRoot->val);
	_copy(mainRoot, otherRoot->left);
	_copy(mainRoot, otherRoot->right);
}

template<class T>
inline void BST<T>::_inorderTraversal(std::unique_ptr<BST<T>::node<T>>& current)
{
	if (current == NULL)
	{
		return;
	}
		_inorderTraversal(current->left);
		std::cout << current->val<<"\n";
		_inorderTraversal(current->right);
	
}

template<class T>
inline void BST<T>::_postorderTraversal(std::unique_ptr<BST<T>::node<T>>& current)
{
	if (current == NULL)
	{
		return;
	}
		_postorderTraversal(current->left);
		_postorderTraversal(current->right);
		std::cout << current->val << " ";
}

template<class T>
inline void BST<T>::_preorderTraversal(std::unique_ptr<BST<T>::node<T>>& current)
{
	if (current == NULL)
	{
		return;
	}
	std::cout << current->val << " ";
	_preorderTraversal(current->left);
	_preorderTraversal(current->right);
}

template<class T>
inline void BST<T>::_deleteTree(std::unique_ptr<BST<T>::node<T>>& current)
{
	if (current == nullptr)
		return;

	_deleteTree(current->left);
	_deleteTree(current->right);

	current->deleteNode();
	current = nullptr;
}

template<class T>
inline int BST<T>::_height(std::unique_ptr<BST<T>::node<T>>& current)
{
	if (current == nullptr)
	{
		return -1;
	}

	int leftHeight = _height(current->left);
	int rightHeight = _height(current->right);

	if (leftHeight > rightHeight)
	{
		return leftHeight + 1;
	}
	else
	{
		return rightHeight + 1;
	}

}

template<class T>
inline void BST<T>::_saveToFile(std::unique_ptr<BST<T>::node<T>>& current, std::ostream& ofile)
{
	if (current == NULL)
	{
		return;
	}
	ofile << current->val<<"\n";
	_saveToFile(current->left, ofile);
	_saveToFile(current->right, ofile);
}

template<class T>
inline void BST<T>::_serializeBinary(std::unique_ptr<BST<T>::node<T>>& current, std::ostream& ofile)
{
	if (current == NULL)
	{
		return;
	}
	ofile.write((char*)&current->val, sizeof(current->val));
	_serializeBinary(current->left, ofile);
	_serializeBinary(current->right, ofile);
}

template<class T>
inline void BST<T>::_loadFromFile(std::unique_ptr<BST<T>::node<T>>& current, std::ifstream& ifile )
{
	
	if (ifile.is_open())
	{
		T temp;
		std::string line;
		_deleteTree(root);

		while (ifile >> temp)
		{			
			insert(temp);
		}
	}
}

template<class T>
inline void BST<T>::_deserializeBinary(std::unique_ptr<BST<T>::node<T>>& current, std::ifstream& ifile)
{

	if (ifile.is_open())
	{
		T temp;
		std::string line;

		while (ifile.read((char*)&temp, sizeof(temp)))
		{
			_insert(current,temp);
		}
	}
}

template<>
inline void BST<std::string>::_deserializeBinary(std::unique_ptr<BST<std::string>::node<std::string>>& current, std::ifstream& ifile)
{

	if (ifile.is_open())
	{
		std::string temp;
		std::string line;

		while (ifile.read((char*)&temp, sizeof(temp)))
		{
			_insert(current, temp);
		}
	}
}

template<class T>
inline void BST<T>::insert(T value)
{
	_insert(root, value);
}

template<class T>
inline T* BST<T>::search(T value)
{
	return &_search(root, value)->val;
}

template<class T>
inline int BST<T>::height()
{
	return _height(root);
}

template<class T>
inline void BST<T>::deleteTree()
{
	_deleteTree(root);
}

template<class T>
inline void BST<T>::inorderTraversal()
{
	_inorderTraversal(root);
}

template<class T>
inline void BST<T>::postorderTraversal()
{
	_postorderTraversal(root);
}

template<class T>
inline void BST<T>::preorderTraversal()
{
	_preorderTraversal(root);
}

template<class T>
inline void BST<T>::saveToFile(std::string file_name)
{
	std::ofstream file;
	file.open(file_name, std::ios::binary);
	if (file.good())
	{
		_saveToFile(root, file);
	}
	else
	{
		std::cout << "Couldn't open file" << std::endl;
	}
}

template<class T>
inline void BST<T>::serializeBinary(std::string file_name)
{
	std::ofstream file;
	file.open(file_name, std::ios::binary);
	if (file.good())
	{
		_serializeBinary(root, file);
	}
	else
	{
		std::cout << "Couldn't open file" << std::endl;
	}
	file.close();
}

template<class T>
inline void BST<T>::deserializeBinary(std::string file_name)
{
	std::ifstream file;
	file.open(file_name, std::ios::binary);
	if (file.good())
	{
		_deserializeBinary(root, file);
	}
	else
	{
		std::cout << "Couldn't open file" << std::endl;
	}
	file.close();
}

template<class T>
inline void BST<T>::saveToFile()
{
	saveToFile("default_serialization_file.bin");
}

template<class T>
inline void BST<T>::loadFromFile(std::string file_name)
{
	std::ifstream file;
	file.open(file_name, std::ios::in);
	if (file.good())
	{
		_loadFromFile(root, file);
	}
	else
	{
		std::cout << "Couldn't open file" << std::endl;
	}
}

template<class T>
inline void BST<T>::loadFromFile()
{
	loadFromFile("default_serialization_file.bin");
}

template<class T>
inline BST<T>& BST<T>::operator=(BST&& tree)
{
	root = move(tree.root);
	return *this;
}

template<class T>
inline BST<T>& BST<T>::operator=(BST& tree)
{
	_copy(root, tree.root);
	return *this;
}

template<class T>
inline BST<T>::BST()
{
	root = nullptr;
}

template<class T>
inline BST<T>::BST(const T& val)
{
	insert(val);
}

template<class T>
inline BST<T>::BST(BST<T>&& tree) : root (move(tree.root))
{
	tree.root = NULL;
}

template<class T>
inline BST<T>::BST(BST& tree)
{
	_copy(root, tree.root);
}

