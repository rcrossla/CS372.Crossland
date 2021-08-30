#include "cs372List.h"

using namespace std;

template <typename Thing>
class Bag {
private:
	List<Thing> bagList;

public:
	void insert(Thing aThing) {
		
		bagList.push_back(aThing);
	}
	void pop() {
		
		bagList.pop_back();
	}
	bool empty() {

		return bagList.empty();
	}
	int size() {
		
		return bagList.size();
	}
	int count(Thing aThing) {
		int totalFound = 0;
		int baglistsize = bagList.size();
		for (int i = 0; i < baglistsize; i++) {
			if (bagList[i] == aThing) {
				totalFound++;
			}
		}
		return totalFound;
	}
	void traverse(void(*doIt)(Thing data)) {
		bagList.traverse(doIt);
	}

	Thing back() {
		return bagList.back();
	}

};



