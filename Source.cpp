


#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class MyList
{
private:

	struct nodes
	{
		double myValue;
		struct nodes* next;
	};

	nodes* head;

public:

	MyList()
	{
		head = nullptr;
	}

	~MyList()
	{
		nodes* nodePtr;
		nodes* next;

		nodePtr = head;

		while (nodePtr != nullptr)
		{
			next = nodePtr->next;

			delete nodePtr;

			nodePtr = next;
		}
	}

	void appendNode(double num)
	{
		nodes* newNode;
		nodes* nodePtr;

		newNode = new nodes;
		newNode->myValue = num;
		newNode->next = nullptr;
		if (!head)
			head = newNode;
		else
		{
			nodePtr = head;

			while (nodePtr->next)
				nodePtr = nodePtr->next;

			nodePtr->next = newNode;

		}
	}
	void insertNode(double num)
	{
		nodes* newNode;
		nodes* nodePtr;
		nodes* previousNode = nullptr;

		newNode = new nodes;
		newNode->myValue = num;

		if (!head)
		{
			head = newNode;
			newNode->next = nullptr;
		}
		else
		{
			nodePtr = head;

			previousNode = nullptr;

			while (nodePtr != nullptr && nodePtr->myValue < num)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			if (previousNode == nullptr)
			{
				head = newNode;
				newNode->next = nodePtr;
			}

			else
			{
				previousNode->next = newNode;
				newNode->next = nodePtr;
			}

		}

	}
	void deleteNode(double num) {
		nodes* nodePtr;
		nodes* previousNode;

		if (!head)
			return;
		if (head->myValue == num)
		{
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
		else
		{
			nodePtr = head;

			while (nodePtr != nullptr && nodePtr->myValue != num)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			if (nodePtr)
			{
				previousNode->next = nodePtr->next;
				delete nodePtr;
			}
		}
	}

	void displayList()
	{
		nodes* nodePtr;

		nodePtr = head;

		while (nodePtr)
		{

			cout << nodePtr->myValue << endl;

			nodePtr = nodePtr->next;
		}
	}
	

	
};

int main()
{
	MyList newList;

	double value1;
	double value2;
	double value3;
	double value4;
	double value5;

	cout << "Please enter four double values." << endl;
	cin >> value1;
	cout << endl;
	cin >> value2;
	cout << endl;
	cin >> value3;
	cout << endl;
	cin >> value4;
	cout << endl;
	newList.appendNode(value1);
	newList.appendNode(value2);
	newList.appendNode(value3);
	newList.appendNode(value4);

	cout << "Here is the list:";
	cout << endl;
	newList.displayList();

	cout << endl;
	cout << "Please enter a double to insert into the list. ";
	cout << endl;
	cin >> value5;
	newList.insertNode(value5);

	cout << endl;
	cout << "Here is the list again:" << endl;
	newList.displayList();

	
}


