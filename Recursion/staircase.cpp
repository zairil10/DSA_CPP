#include<iostream>
using namespace std;

int staircase(int n);

int main(){

	int n = 5;

	cout << staircase(n) << '\n';


  return 0;
}

int staircase(int n){
	
	if(n==0) return 1;
	if(n < 1) return 0;

	return staircase(n-1) +staircase(n-2)+staircase(n-3);
}
