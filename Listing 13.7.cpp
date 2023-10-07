//insertion sort array of integers`


#include<bits/stdc++.h>
using namespace std;

//working properly

template<class T>

class Array
{
	private:
		T*a;
	int size;

	public: 
			Array (int n) {
				size = n;
				a = new T[n];
			}
			~Array(){
				delete a;
			}

	void inputArray();
	 void outputArray();
	  void insertionSort();
};

template <class T>

void Array <T>:: inputArray(){

		int i;
	cout << "\nEnter" << size << " elements of array\n\n";

		for (i=0;i< size; i++) {
		 cin >> a[i];
	}	
}
template<class T>
void Array <T>:: outputArray(){

		int i;
		 for (i = 0; i < size; i++) {

		cout << a[i]<< "\t";
	}
	cout<<endl;
}

template <class T>

 void Array<T>::insertionSort()
 {
 
	int k, temp, j;

	for (k = 1; k <= size-1; k++ ) {

	temp = a[k];

	j=k-1;
	while(( temp<a[j]) && (j>=0)){
	a[j+1]= a[j];
	j = j-1;
}
	a[j+1] = temp;
	}
}

int main()
{

	int n;
	
	cout << "Enter size of array: ";
 	cin >>n;

	Array<int> a(n);

	a.inputArray();

	cout << "\n\nInput array is: ";

	a.outputArray();

	a.insertionSort();

	cout << "\n\nSorted array is: ";
	 a.outputArray();
}
