#include <iostream>
#include <vector>
#include "KH_Survey.h"

double GetSumSurvHours(KH_Survey* in_ptr, int in_arr_size) {
	double result = 0;
	for (int i = 0; i < in_arr_size; i++) {
		result += in_ptr[i].GetHours();
	}
	return result;
}

double GetAvgSurvHours(KH_Survey* in_ptr, int in_arr_size) {
	double result = 0;
	if (in_arr_size > 0) {
		result = (GetSumSurvHours(in_ptr, in_arr_size) / in_arr_size);
	}
	return result;
}

//KH_Survey* DuplicateSurvArray(KH_Survey* in_ptr, int in_arr_size) {
//	KH_Survey* dup_arr_ptr = nullptr;
//	dup_arr_ptr = new KH_Survey[in_arr_size];
//	for (int i = 0; i < in_arr_size; i++) {
//		dup_arr_ptr[i] = in_ptr[i];
//	}
//	return dup_arr_ptr;
//}

double* GetSurvHoursArray(KH_Survey* in_ptr,  int in_arr_size) {
	double* temp_arr_ptr = new double[in_arr_size];
	for (int i = 0; i < in_arr_size; i++) {
		temp_arr_ptr[i] = in_ptr[i].GetHours();
	}
	return temp_arr_ptr;
}

double* GetSortedSurvHoursArray(KH_Survey* in_ptr, int in_arr_size) {
	double* hrs_arr_ptr = GetSurvHoursArray(in_ptr, in_arr_size);
	int i, j, min_hours_index, temp;
	for (int i = 0; i < in_arr_size - 1; i++) {
		min_hours_index = i;
		for (int j = i + 1; j < in_arr_size; j++) {
			if (hrs_arr_ptr[j] < hrs_arr_ptr[min_hours_index]) {
				min_hours_index = j;
			}
			temp = hrs_arr_ptr[i];
			hrs_arr_ptr[i] = hrs_arr_ptr[min_hours_index];
			hrs_arr_ptr[min_hours_index] = temp;
		}
	}
	return hrs_arr_ptr;
}

double GetMedianSurvHours(KH_Survey* in_ptr, int in_arr_size) {
	double* hrs_arr_ptr = GetSortedSurvHoursArray(in_ptr, in_arr_size);
	int mid_index;
	double result = 0;
	if (in_arr_size > 0) {
		// EVEN
		if (in_arr_size % 2 == 0) {
			result = (hrs_arr_ptr[in_arr_size / 2] + hrs_arr_ptr[(in_arr_size - 1) / 2]) / 2;
		}
		// ODD
		else {
			result = hrs_arr_ptr[in_arr_size / 2];
		}
	}
	delete[] hrs_arr_ptr;
	return result;
}

std::string GetModeSurvHours(KH_Survey* in_ptr, int in_arr_size) {
	double* hrs_arr_ptr = GetSortedSurvHoursArray(in_ptr, in_arr_size);
	std::vector<double> result;
	std::string result_string = "NONE";
	// FIND MAX COUNT
	int max_count = 0;
	int temp_count = 0;
	int max_index = 0;
	int temp_index = 0;
	for (int i = 0; i < in_arr_size; i++) {
		if (in_ptr[i].GetHours() == in_ptr[temp_index].GetHours()) {
			temp_count++;
		}
		else {
			temp_index = i;
			temp_count = 0;
			temp_count++;
		}
		if (temp_count > 1 && temp_count > max_count) {
			max_count = temp_count;
			max_index = i;
		}
	}
	temp_index = 0;
	temp_count = 0;
	for (int i = 0; i < in_arr_size; i++) {
		if (in_ptr[i].GetHours() == in_ptr[temp_index].GetHours()) {
			temp_count++;
		}
		else {
			temp_index = i;
			temp_count = 0;
			temp_count++;
		}
		if (temp_count == max_count) {
			result.push_back(in_ptr[i].GetHours());
		}
	}
	delete[] hrs_arr_ptr;

	if (result.size() != 0) {
		result_string = "";
		for (auto i = result.begin(); i != result.end(); ++i) {
			result_string += to_string(*i) + ", ";
		}
	}


	return result_string;
}

bool IsValidInput() {
	cin.ignore(INT_MAX, '\n');
	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		
		return false;
	}
	return true;
}

void RunSurvey() {
	KH_Survey* surv_ptr = nullptr;
	int num_surv_students = 0;
	bool is_valid_input = false;
	string in_hours = "0";

	do {
		cout << "Q: How many students were surveyed ?" << endl;
		cout << "A: ";
		cin >> num_surv_students;

		if (!IsValidInput()) {
			cout << "ERROR: Invalid input. Please try again." << endl;
		}
		else if (num_surv_students < 0) {
			cout << "ERROR: Number of students cannot be less than 0. Please enter a number > 0. " << endl;
		}
		else {
			is_valid_input = true;
		}
	} while (!is_valid_input);

	if (is_valid_input) {
		surv_ptr = new KH_Survey[num_surv_students];

		for (int i = 0; i < num_surv_students; i++) {
			bool is_valid_input = false;

			do {
				cout << "Q: How many hours did student#" << i << " play ?" << endl;
				cout << "A: ";
				cin >> in_hours;

				if (!IsValidInput()) {
					cout << "ERROR: Invalid input. Please try again." << endl;
				}
				else if (num_surv_students < 0) {
					cout << "ERROR: Number of students cannot be less than 0. Please enter a number > 0. " << endl;
				}
				else {
					is_valid_input = true;
				}
			} while (!is_valid_input);

			// UPDATE CLASS ATTR IF INPUT IS VALID
			surv_ptr[i].SetHours(stod(in_hours));
			//cout << surv_ptr[i].GetHours() << endl;
		}

		cout << endl;
		cout << "-----RESULT-----" << endl;
		cout << "The average hours per student are: " << to_string(GetAvgSurvHours(surv_ptr, num_surv_students)) << "." << endl;
		cout << "The median is: " << to_string(GetMedianSurvHours(surv_ptr, num_surv_students)) << "." << endl;
		cout << "The mode is: " << (GetModeSurvHours(surv_ptr, num_surv_students)) << "." << endl;
	}
}

int main() {
	RunSurvey();

	system("pause");
	return 0;
}