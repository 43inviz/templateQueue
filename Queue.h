#pragma once
using namespace std;

template<typename T>
class Queue
{
	int capacity;

	T* queue;

	int size;

public:
	
	Queue(int size,T* queue);
	Queue() :Queue{ 0,nullptr }{}
	~Queue();
	bool isFull();
	bool isEmpty();
	int getSize();
	void Enqueue(T val);
	T Dequeue();

	void show();
};

template<typename T>
inline Queue<T>::Queue(int size, T* queue)
{
	this->capacity = size + 5;
	this->size = size;
	this->queue = new T[capacity];
	for (int i = 0; i < capacity; i++) {
		this->queue[i] = queue[i];
	}
}

template<typename T>
inline Queue<T>::~Queue()
{
	if (queue != nullptr) {
		delete[] queue;
	}
}

template<typename T>
inline bool Queue<T>::isFull()
{
	if (this->size == this->capacity) {
		return true;
	}
	return false;
}

template<typename T>
inline bool Queue<T>::isEmpty()
{
	if (this->size == 0) {
		return true;
	}
	return false;
}

template<typename T>
inline int Queue<T>::getSize()
{
	return this->size;
}

template<typename T>
inline void Queue<T>::Enqueue(T val)
{
	if (isFull()) {

		this->capacity *=2;

		T* copyQue = new T[capacity];

		for (int i = 0; i < this->size; i++) {
			copyQue[i] = this->queue[i];
		}

		delete[] this->queue;
		this->queue = copyQue;

	}

	this->queue[this->size] = val;
	this->size++;
}

template<typename T>
inline T Queue<T>::Dequeue()
{
	T result = 0;

	if (!isEmpty()) {
		result = this->queue[0];

		for (int i = 0; i < this->size - 1; i++) {
			this->queue[i] = this->queue[i + 1];
		}

		this->size--;
	}
	return result;
}

template<typename T>
inline void Queue<T>::show()
{
	for (int i = 0; i < this->size; i++) {
		cout << this->queue[i] << " ";
	}
	cout << endl;
}
