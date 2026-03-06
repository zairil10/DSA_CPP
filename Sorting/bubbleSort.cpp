#include<iostream>
using namespace std;

void bubbleSort(int a[], int size);


int main() {

	int arr[] = {8, 10, 1, 4, 2, 5, 7, 3, 6, 9};
	int size = sizeof(arr)/sizeof(arr[0]);

	bubbleSort(arr, size);

	for(int sortedElement: arr){
		cout << sortedElement << '\n';

	}


	return 0;
}


void bubbleSort(int a[], int size) {

	int temp=0;

	for(int i =0; i < size-1; i++){
		for(int j=0; j < size-i-1; j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}

		}

	}


}
