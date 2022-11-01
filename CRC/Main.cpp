#include "functions.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
	int loop = 1;
	int choice, n, k;
	float error_rate;
	vector<int> M, F, T1, T2, P;
	//vector<int> M{1,0,1,0,0,0,1,1,0,1 };
	string p_as_string;
	unsigned long long m, f, t1, t2, p;        //The corresponding integer numbers of M, F, T, P for less calculations. t1 is before the transmission.
	int number_of_none_error, number_of_detection_error, number_of_undetected_error;
	int total_transmitions;




	while (loop) {

		cout << "\n~~~~~~~~~~~MENU~~~~~~~~~~~\n"
			<< "0. Exit programm\n"
			<< "1. Make a simple transmission.\n"
			<< "2. Make several transmissions and output statistics.\n"
			<< "\nYour choice:";
		cin >> choice;

		switch (choice) {
		case 0:
			return 0;
		case 1:
			number_of_none_error = 0; 
			number_of_detection_error = 0;
			number_of_undetected_error = 0;
			cout << "\nGive the k:";
			cin >> k;
			M.reserve(k);
			random_initialization_of_M(k, &M);      //initialize M
			//print_vector(M);
			transform_vector_to_number(&M, &m);
			cout << "\nGive P:";
			cin >> p_as_string;
			cout << "\nGive the error rate for transimission:";
			cin >> error_rate;
			n = p_as_string.length() - 1;
			F.resize(n);
			T1.resize(k + n);
			T2.resize(k + n);
			P.reserve(n+1);
			transform_string_to_vector(&p_as_string, &P);
			//print_vector(P);
			transform_vector_to_number(&P , &p);
			t1 = m * pow(2, n);
			transform_number_to_vector(t1, &T1);
			//print_vector(T1);
			//print_vector(P);
			calculate_FCS(T1, P, &F);
			add_FCS_to_T(F, &T1);
			transform_vector_to_number(&T1, &t1);
			//print_vector(F);
			//f = t1 % p;
			//t1 = t1 +(p - f);
			//t1 = t1 - f;
			//cout << "\n" << m << "  " << f << "  " << p << "   " << t1;
			//transform_number_to_vector(t1,&T1);
			//print_vector(T1);
			//transform_number_to_vector(f, &F);
			transmit_with_ber(error_rate, T1, &T2);
			transform_vector_to_number(&T2, &t2);
			receiver_check(T1, T2, P, t1, t2, p, &number_of_none_error, &number_of_detection_error, &number_of_undetected_error);
			M.resize(0);
			M.shrink_to_fit();
			P.resize(0);
			P.shrink_to_fit();
			F.resize(0);
			F.shrink_to_fit();
			T1.resize(0);
			T1.shrink_to_fit();
			T2.resize(0);
			T2.shrink_to_fit();
			//p_as_string.resize(0);
			break;
		case 2:
			cout << "\nGive the number of transmitions:";
			cin >> total_transmitions;
			number_of_none_error = 0;
			number_of_detection_error = 0;
			number_of_undetected_error = 0;
			k = 10;
			p_as_string = "110101";
			error_rate = 0.001;
			for (int j = 0; j < total_transmitions; j++) {
				M.reserve(k);
				random_initialization_of_M(k, &M);      //initialize M
				transform_vector_to_number(&M, &m);
				n = p_as_string.length() - 1;
				F.resize(n);
				T1.resize(k + n);
				T2.resize(k + n);
				P.reserve(n + 1);
				transform_string_to_vector(&p_as_string, &P);
				//print_vector(P);
				transform_vector_to_number(&P, &p);
				t1 = m * pow(2, n);
				transform_number_to_vector(t1, &T1);
				calculate_FCS(T1, P, &F);
				add_FCS_to_T(F, &T1);
				transform_vector_to_number(&T1, &t1);
				//f = t1 % p;
				//t1 = t1 + (p - f);
				//cout << "\n" << m << "  " << f << "  " << p << "   " << t1;
				//transform_number_to_vector(t1, &T1);
				//print_vector(T1);
				//transform_number_to_vector(f, &F);
				transmit_with_ber(error_rate, T1, &T2);
				transform_vector_to_number(&T2, &t2);
				receiver_check(T1, T2, P, t1, t2, p, &number_of_none_error, &number_of_detection_error, &number_of_undetected_error);
				M.resize(0);
				M.shrink_to_fit();
				P.resize(0);
				P.shrink_to_fit();
				F.resize(0);
				F.shrink_to_fit();
				T1.resize(0);
				T1.shrink_to_fit();
				T2.resize(0);
				T2.shrink_to_fit();
			}
			cout << "\nFrom " << total_transmitions << " tests we had:\n"
				<< "\nPercentage of none error:" << number_of_none_error << "/" << total_transmitions << " which is: " << (float)(number_of_none_error) / total_transmitions
				<< "\nPercentage of detected error:" << number_of_detection_error << "/" << total_transmitions << " which is: " << (float)(number_of_detection_error) / total_transmitions
				<< "\nPercentage of undetected error:" << number_of_undetected_error << "/" << total_transmitions << " which is: " << (float)(number_of_undetected_error) / total_transmitions;

			break;

		}

	}


	return 0;
}