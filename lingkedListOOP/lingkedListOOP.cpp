#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
	int noMhs;
	char nama[20];
	Node* next;
};

class List
{
	Node* START;
public:
	List();
	void addNode();
	bool Search(int nim, Node** current, Node** previous);
	bool listEmpty();
	bool delNode(int element);
	void traverse();
};

List::List()
{
	START = NULL;
}

void List::addNode()	//Menambah sebuah Node ke dalam list
{
	int nim;
	char nm[20];
	cout << "\nMasukan Nomor Mahasiswa : ";
	cin >> nim;
	cout << "\nMasukan Nama : ";
	cin >> nm;

	Node* nodeBaru = new Node;
	nodeBaru->noMhs = nim;
	strcpy_s(nodeBaru->nama, nm);

	if (START == NULL || nim <= START->noMhs)
	{ 
		if ((START != NULL) && (nim == START->noMhs))
		{
			cout << "\nDuplikasi noMhs tidak diijinkan\n";
			return;
		}
		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}
	Node* previous, * current;

	current = START;
	previous = START;

	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "\nDuplikasi noMhs tidak diijinkan\n";
			return;
		}
		previous = current;
		current = current->next;
	}
	//jika loop di atas dieksekusi, previous dan current akan menempati posisi dimana ditempatkan
	nodeBaru->next = current;
	previous->next = nodeBaru;
}

bool List::listEmpty()
{
	if (START == NULL)
		return true;
	else
		return false;
}

bool List::delNode(int nim) //Menghapus node dari dalam list
{
	Node* current, * previous;
	if (Search(nim, &previous, &current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = START->next;

	delete current;
	return true;
}

//check apakah node yang dimaksud ada di dalam list atau tidak
bool List::Search(int nim, Node** previous, Node** current)
{
	*previous = START;
	*current = START;
	while ((*current != NULL) && (nim != (*current)->noMhs))
	{
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

void List::traverse()//mengunjungi dan membaca data dalam list
{
	if (listEmpty())
		cout << "\nList Kosong";
	else
	{
		cout << endl << "Data di dalam list adalah: " << endl;
		Node* currentNode;
		for (currentNode = START; currentNode != NULL; currentNode = currentNode->next)
		{
			cout << currentNode->noMhs << "		" << currentNode->nama << "\n";
		}
		cout << endl;
	}
}

int main()
{
	List mhs;
	int nim;
	char ch;
	while (1)
	{
		cout << endl << "Menu";
		cout << endl << "1. Menambah data ke dalam list" << endl;
		cout << "2. Menghapus data dari dalam list" << endl;
		cout << "3. Menampilkan semua data di dalam list" << endl;
		cout << "4. Mencari data dalam list" << endl;
		cout << "5. Keluar" << endl;
		cout << endl << "Masukan pilihan (1-5): ";
		cin >> ch;
		switch (ch)
		{
		