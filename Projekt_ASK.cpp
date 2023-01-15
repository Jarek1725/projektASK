#include <iostream>
using namespace std;

bool isNextLetterSame(int firstInputIndex, int secondInputIndex, string& firstInput, string& secondInput) {
	return 	(firstInputIndex < firstInput.length() &&
		secondInputIndex < secondInput.length() &&
		firstInput[firstInputIndex] == secondInput[secondInputIndex]);
}

void findLongestCommonSubstring(string& firstInput, string& secondInput, string& output) {
	int maxLength = 0, currentLength = 0, maxLengthIndex;
	for (int firstInputIndex = 0; firstInputIndex < firstInput.length(); firstInputIndex++) {
		for (int secondInputIndex = 0; secondInputIndex < secondInput.length(); secondInputIndex++) {
			while (isNextLetterSame(firstInputIndex + currentLength,
				secondInputIndex + currentLength,
				firstInput,
				secondInput)) {
				currentLength++;
			}
			if (maxLength < currentLength) {
				maxLength = currentLength;
				maxLengthIndex = secondInputIndex + currentLength;
			}
			currentLength = 0;
		}
	}
	output = secondInput.substr(maxLengthIndex-maxLength, maxLength);
}

char generateRandomChar() {
	return 'A' + rand() % 26;
}

void generateRandomString(string& input, int length) {
	for (int i = 0; i < length; i++) {
		input += generateRandomChar();
	}
}

int main()
{
	srand(time(NULL));

	string firstString = "", secondString = "", longestCommonSubstring = "";
	generateRandomString(firstString, 15);
	generateRandomString(secondString, 15);

	cout << firstString << endl;
	cout << secondString << endl;

	findLongestCommonSubstring(firstString, secondString, longestCommonSubstring);

	cout << longestCommonSubstring << endl;
}
