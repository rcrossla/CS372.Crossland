#include "cs372List.h"
using namespace std;
template <typename Thing>
class Bag {
private:
	
	
	List<Thing> bagList;
public:
	void insert(Thing aThing) {
		
		bagList.push_back(aThing)
	}
	Thing pop() {
		
		return bagList.pop();
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

};



