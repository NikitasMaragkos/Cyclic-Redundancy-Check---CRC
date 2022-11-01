#include "functions.h"


using namespace std;

void random_initialization_of_M(int length_of_M, vector<int>* M) {
	//srand(time(NULL));
	
	for (int i = 0; i < length_of_M; i++) {
		int random = rand() % 2;
		if (i == 0) {
			M->push_back(1);
			continue;
		}
		if ( random == 0)
			M->push_back(0);
		else
			M->push_back(1);
	}
	//print_vector(*M);
}

void transform_string_to_vector(string* string_of_numbers, vector<int>* M) {
	for (int i = 0; i < string_of_numbers->size(); i++)
		M->push_back( (*string_of_numbers)[i] - '0');
}

void  transform_vector_to_number(vector<int>* M, unsigned long long* number){
	*number = 0;
	int factorial = 1;
	for (int i = M->size() - 1; i >= 0 ; i--) {
		*number = *number + (unsigned long long)(factorial * M->at(i));
		factorial = factorial * 2;
	}
}

void print_vector(vector<int> M) {

	cout << "\n";
	for (int i = 0; i < M.size(); i++) 
		cout << M.at(i);
}

void  transform_number_to_vector(unsigned long long number, vector<int>* M) {
	for (int i = M->size()-1; i >= 0; i--) {
		(*M)[i] = number % 2;
		number = number / 2;
	}
}

void transmit_with_ber(float error_rate, vector<int> T1, vector<int>* T2) {
	int number_for_rand = 1 / error_rate;
	//srand(time(NULL));
	for (int i = 0; i < T1.size(); i++) {
		if ( (rand() % number_for_rand) == 0)
			T2->at(i) = (T1[i] + 1) % 2;
		else
			T2->at(i) = T1[i];
	}
}


void calculate_FCS(vector<int> M, vector<int> P, vector<int>* FCS) {
	int position = 0;
	while ( position <= M.size() - P.size() ) {
		int flag = 0;
		int counter_for_add_to_position = 0;
		//cout << "\n~~~~";
		for (int i = 0; i < P.size(); i++) {
			M[i + position] = M[i + position] ^ P[i];
			//cout << M[i + position];
			if ((M[i + position] == 1) && (flag == 0)) {
				counter_for_add_to_position = i;
				flag = 1;
			}		
		}
		if(counter_for_add_to_position == 0)
			counter_for_add_to_position = P.size();
		position = position + counter_for_add_to_position;
		//cout << "\n~~~~"<<position;
	}
	for (int j = 0; j < FCS->size(); j++)
		FCS->at(j) = M.at( M.size() - FCS->size() + j );
}

void add_FCS_to_T(vector<int> FCS, vector<int>* T) {
	for (int j = 0; j < FCS.size(); j++)
		T->at(T->size() - FCS.size() + j) = FCS[j];
}

int check_zero_vector(vector<int> vect) {
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i] == 1)
			return 0;
	}
	return 1;
}


int receiver_check(vector<int> T1 , vector<int> T2, vector<int> P, unsigned long long t1, unsigned long long t2, unsigned long long p, int* number_of_none_error, int* number_of_detection_error, int* number_of_undetected_error) {
	vector<int> remainder;
	remainder.resize(P.size() - 1);
	calculate_FCS(T2, P, &remainder);
	//print_vector(remainder);
	if (check_zero_vector(remainder) ) {
		if (t1 == t2) {
			//cout << "\n" << t1 << "  " << t2 << "  " << p;
			//print_vector(T1);
			*number_of_none_error = *number_of_none_error + 1;
			return 0;
		}
		else {
			*number_of_undetected_error = *number_of_undetected_error + 1;
			cout << "\nThere was an undetected error!!\n"<<"Original message";
			print_vector(T1);
			cout << "\nReceived message";
			print_vector(T2);
			return 1;
		}
	}
	else {
		//cout << "\n" << t1 << "  " << t2 << "  " << p;
		*number_of_detection_error = *number_of_detection_error + 1;
		cout << "\nThere was a detected error!!\n" << "Original message";
		print_vector(T1);
		cout << "\nReceived message";
		print_vector(T2);
		return 2;
	}
	

}