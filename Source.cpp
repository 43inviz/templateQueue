#include <iostream>
#include "Queue.h"
using namespace std;


void menu() {
	cout << "1 - Add\t\t2 - Dequeue\n";
	cout << "3 - Show\t4 - Is full\n";
	cout << "\t5 - Is empty\n";
	cout << "Enter choice: ";
}

int main() {
	srand(time(0));
	int size = 5;

	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10 + 1;
	}

	Queue<int> que1 (size,arr);

	int choice;
	int deqRes;
	int value;
	bool isFull;
	bool isEmpty;
	do {
		menu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			int value;
			cout << "Enter value: ";
			cin >> value;
			que1.Enqueue(value);
			cout << "\n Element added!\n";
			break;
		case 2:
			deqRes = que1.Dequeue();
			cout << deqRes << endl;
			break;
		case 3:
			que1.show();
			break;
		case 4:
			isFull = que1.isFull();
			if (isFull == true) {
				cout << "Queue is FULL\n";

			}
			else {
				cout << "Queue not FULL\n";
			}
			break;
		case 5:
			isEmpty = que1.isEmpty();
			if (isEmpty == true) {
				cout << "Queue is empty!\n";
			}
			else {
				cout << "Queue is fill\n";
			}
			break;
		default:
			break;
		}

	} while (choice != 0);
	

	return 0;
}