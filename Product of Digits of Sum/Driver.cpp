/*
August 30- Sep 5th Weekly Challenge
Products of Digits of Sum
*/


#include <iostream>
#include <string>
#include <vector> 
#include <sstream>

using namespace std;


//SEPERATE DIGITS
vector<int> seperateDigits(string digitsString) {
	vector<int> singleDigits;

	stringstream ss(digitsString);
	while (ss.good()) {
		string placeholder;
		getline(ss, placeholder, ',');
		singleDigits.push_back(stoi(placeholder));
	}

	return singleDigits;
}

//SUM OF ALL DIGITS IN VECTOR
int addDigits(vector<int> singleDigits) {
	int sumOfDigits = 0;
	for (size_t i = 0; i < singleDigits.size(); i++) {
		sumOfDigits += singleDigits[i];
	}

	return sumOfDigits;
}


//PRODUCT OF ALL DIGITS IN VECTOR
int productOfDigits(vector<int> allSingleDigits) {
	int productOfDigits = 1;
	for (size_t i = 0; i < allSingleDigits.size(); i++) {
		productOfDigits *= allSingleDigits[i];
	}
	return productOfDigits;
}


int productOfDigitsOfSum(string digitsString) {
	vector<int> singleDigits = seperateDigits(digitsString);

	int sumOfDigits = addDigits(singleDigits);

	string stringOfDigits = to_string(sumOfDigits);

	//LOOPS THROUGH STRING OF DIGITS AND CONVERTS TO INTEGER
	vector<int> seperatedDigits;
	for (int i = 0; i < stringOfDigits.length(); i++) {
		int placeholder = stringOfDigits[i] - 48;
		seperatedDigits.push_back(placeholder);
	}

	
	int productOfSingleDigits = productOfDigits(seperatedDigits);

	//IF THE DIGIT IS LONGER THAN 1 RECALL THE FUNCTION WITH THE CURRENT PRODUCT, IF NOT PRINT THE ANSWER
	if (to_string(productOfSingleDigits).length() != 1) {
		productOfDigitsOfSum(to_string(productOfSingleDigits));
	}
	else {
		cout << "Answer: " << productOfSingleDigits << endl;
		return productOfSingleDigits;
	}
}



int main() {
	string digitsString;

	//GET DIGITS FROM CONSOLE THEN PASS THEM TO THE productOfDigitsOfSum FUNCTION
	cout << "Please enter the digits seperated by a comma." << endl;
	cin >> digitsString;
	

	
	//SEND INTEGERS TO productOfDigitsOfSum FUNCTION
	return productOfDigitsOfSum(digitsString);
}