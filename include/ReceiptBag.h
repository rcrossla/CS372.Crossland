using namespace std;
#include "Vector.h"

template <typename Thing>
class ReceiptBag {
private:
	
	Vector<int> Receipt;
	Vector<Thing> Bag;
	

public:
	
	
	int insertBag(Thing aThing){
		int receipt = (Bag.size()-1) + 100;

		Bag.push_back(aThing);

		return receipt;
	}
	void insertReceipt(int receipt) {

		Receipt.push_back(receipt);

	}
	Thing deleteBag(int receipt) {
		Thing number = 0;

		for (int i = 0; i < Receipt.size(); i++) {
			if (Receipt.get(i) == receipt) {
				//found
				number = Bag.get(i);
				
				
				for (int x = i; x < Bag.size(); x++) {
					Bag.put(Bag.get(x + 1), x);
				}
				Bag.pop();
				
			}
		}	
		return number;
	}
	void deleteReceipt(int receipt) {
		Thing number = 0;

		for (int i = 0; i < Receipt.size(); i++) {
			if (Receipt.get(i) == receipt) {
				//found
				number = Receipt.get(i);
				

				for (int x = i; x < Receipt.size(); x++) {
					Receipt.put(Receipt.get(x + 1), x);
				}
				Receipt.pop();

			}
		}
		
	}
	void traverseBag() {

		Bag.traverse();

	}
	void traverseReceipt() {

		Receipt.traverse();
	}
	int size() {

		return Bag.size();
		
	}

};



