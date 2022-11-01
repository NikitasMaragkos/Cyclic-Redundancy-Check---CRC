#pragma once
#include<vector>
#include<string>
#include <stdio.h>
#include <iostream>
#include <time.h>


void random_initialization_of_M(int length_of_M, std::vector<int>* M);

void transform_string_to_vector(std::string* string_of_numbers, std::vector<int>* M);

void transform_vector_to_number( std::vector<int>* M, unsigned long long* number);

void print_vector(std::vector<int> M);

void transform_number_to_vector(unsigned long long number, std::vector<int>* M);

void transmit_with_ber(float error_rate, std::vector<int> T1, std::vector<int>* T2);

void calculate_FCS(std::vector<int> M, std::vector<int> P, std::vector<int>* FCS);

void add_FCS_to_T(std::vector<int> FCS, std::vector<int>* T);

int check_zero_vector(std::vector<int> vect);

int receiver_check(std::vector<int> T1, std::vector<int> T2, std::vector<int> P, unsigned long long t1, unsigned long long t2, unsigned long long p, int* number_of_none_error, int* number_of_detection_error, int* number_of_undetected_error);
