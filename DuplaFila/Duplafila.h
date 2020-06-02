#pragma once
template <typename Generic>
struct Deck {
	Generic *vector;
	int start;
	int end;
	int qty;
	int size;

	Deck(int deck_size) {
		size = deck_size;
		vector = new Generic[size];
		qty = 0;
		end = -1;
		start = 0;
	}

	~Deck() {
		delete(vector);
	}

	void insertInTheEnd(Generic element) {
		end++;
		if (end == size) {
			end = 0;
		}
		vector[end] = element;
		qty++;
	}

	void insertInStart(Generic element) {
		start--;
		if (start == -1) {
			start = size - 1;
		}
		vector[start] = element;
		qty++;
	}

	Generic removeInStart() {
		Generic temp = vector[start];
		start++;
		if (start == size) {
			start = 0;
		}
		qty--;
		return temp;
	}

	Generic removeInTheEnd(){
		Generic temp = vector[end];
		end--;
		if (end == 1) {
			end = size - 1;
		}
		qty--;
		return temp;
	}

	Generic first() {
		return vector[start];
	}

	Generic last() {
		return vector[end];
	}
	
	bool isFull() {
		return qty == size;
	}

	bool isEmpty() {
		return qty == 0;
	}
};