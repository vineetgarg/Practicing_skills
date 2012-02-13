//Fibonacci even valued term sum
#include<iostream>

int main() {
	unsigned long int first_term = 1;
	unsigned long int second_term = 2;
	unsigned long int next_term = first_term + second_term;
	unsigned long int total_sum=2;

	while( next_term < 4000000 ){

		if( next_term % 2 == 0 )
			total_sum += next_term;

		next_term = first_term + second_term;
		first_term = second_term;
		second_term = next_term;


	}


	std::cout<<"Total Sum: "<<total_sum;
}
