// CPP program to implement Simpson's rule
#include<iostream>
using namespace std;

// Given function to be integrated
float func( float x){
	return (1 / ( 1 + x * x ));
}

// Function to perform calculations
float calculate(float ll, float ul, int n ){
	float value;
	float interval_size = (ul - ll)
						/ n;
	float sum = func(ll) + func(ul);

	// Calculates value till integral limit
	for (int i = 1 ; i < n ; i++){
		if (i % 3 == 0)
			sum = sum + 2 * func(ll + i * interval_size);
		else
			sum = sum + 3 * func(ll + i * interval_size);
	}
	return ( 3 * interval_size / 8 ) * sum ;
}

// Driver Code
int main(){
	int n = 10;
	float ll = 1;
	float ul = 10;
	float integral_res = calculate(ll, ul,
								n);

	cout << integral_res;
	return 0;
}
