//
// File:   vector.h
// Author: Adam.Lewis@athens.edu
// Purpose:
// Implement dynamically sized arrays
#pragma once
using namespace std;

template <typename T>
class Vector {
private:
	T* arr = new T[1];
	int vCapacity = 1;
	int length = 1;
	void expand(int newCapacity) {
		T* temp = new T[newCapacity];
		for (int i = 0; i < length - 1; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		vCapacity = newCapacity;
		arr = temp;
	}
public:
	void put(T data, int index) {
		if (index == vCapacity) {
			push_back(data);
		}
		else {
			arr[index] = data;
		}
	}

	void push_back(T data)
	{
		// if number of elements is equal to capacity
		// than we need to reallocate and deep copy
		if (length == vCapacity) {
			expand(2 * vCapacity);
		}
		arr[length-1] = data;
		length++;
	}
	T get(int index) {
		if (index < 0 || index > length) {
			cerr << "Vector: index out of bounds on access" << endl;
			exit(1);
		}
		else {
			return arr[index];
		}
	}
	int size() {
		return length;
	}
	int capacity()
	{
		return vCapacity;
	}
	void traverse() {
		for (int i = 0; i < length-1; i++) {
			cout << arr[i] << endl;
		}
		cout << endl;
	}
	//
	// Constructors and destructor
	// Default constructor, setup an empty vector.
	Vector() {
		arr = new T[1];
		vCapacity = 1;
		length = 1;
	}
	// Copy constructor: Kill the old stuff in old array, and 
	// deepcopy contents of source.
	Vector(Vector& obj) {
		// Reset self
		this->arr = new T[obj.capacity()];
		for (int i = 0; i < obj.size(); i++) {
			this->put(i, obj.get(i));
		}
		this->vCapacity = obj.capacity();
	}
	// Destructor: Do the normal stuff.
	~Vector() {
		delete[] arr;
		arr = nullptr;
	}
	// operator overrides
	// Equality: 
	// Assume two of our vectors are equal if they are the same size and
	// corresponding elements are equal.   We also assume the template type supports
	// the comparison operator.
	bool operator==(Vector& other) const
	{
		if (other.size() != length) {
			return false;
		}
		else {
			for (int i = 0; i < length; i++) {
				if (arr[i] != other.get(i)) {
					return false;
				}
			}
		}
		return true;
	}
	T& operator[](int i) {
		if (i < 0) {
			cerr << endl << "Vector index out of bounds" << endl;
			exit(1);
		}
		// Dynamically allocating, so if the index is larger than
		// the capacity, then just expand and zero fill.
		if (i > vCapacity) {
			expand(i);
			length = vCapacity;
		}
		return arr[i];
	}

	Vector& operator=(const Vector& source) {
		// Do a self check.
		if (this == &source)
		{
			return *this;
		}
		// Reset self
		delete[] arr;
		arr = new T[1];
		vCapacity = 1;
		length = 1;
		for (int i = 0; i < source.size(); i++) {
			push_back(source.get(i));
		}
		return *this;
	}

	T pop() {
		T lastItem = arr[length];
		if (length > 1) {
			// can't remove the last item
			length--;
		}
		return lastItem;
	}
};
