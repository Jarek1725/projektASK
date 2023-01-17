#include <iostream>
#include <vector>

using namespace std;

void findLongestCommonSubstringOptimal(string& firstInput, string& secondInput, string& output) {
	int maxLength = 0;
	vector<vector<int>> L(firstInput.length()+1, vector<int>(secondInput.length()+1, 0));

	for (int firstInputIndex = 0; firstInputIndex < firstInput.length(); firstInputIndex++)
		for (int secondInputIndex = 0; secondInputIndex < secondInput.length(); secondInputIndex++)
			if (firstInput[firstInputIndex] != secondInput[secondInputIndex]) L[firstInputIndex + 1][secondInputIndex + 1] = 0;
			else
			{
				L[firstInputIndex + 1][secondInputIndex + 1] = 1 + L[firstInputIndex][secondInputIndex];
				if (L[firstInputIndex + 1][secondInputIndex + 1] > maxLength)
				{
					maxLength = L[firstInputIndex + 1][secondInputIndex + 1];
				}
			}

	cout << maxLength << endl;
}


bool isNextLetterSame(int firstInputIndex, int secondInputIndex, string& firstInput, string& secondInput) {
	return 	(firstInputIndex < firstInput.length() &&
		secondInputIndex < secondInput.length() &&
		firstInput[firstInputIndex] == secondInput[secondInputIndex]);
}

void findLongestCommonSubstringNotOptimal(string& firstInput, string& secondInput, string& output) {
	int maxLength = 0, currentLength = 0, maxLengthIndex;
	for (int firstInputIndex = 0; firstInputIndex < firstInput.length(); firstInputIndex++) {
		for (int secondInputIndex = 0; secondInputIndex < secondInput.length(); secondInputIndex++) {
			if (firstInput[firstInputIndex] == secondInput[secondInputIndex]) {
				currentLength = 1;
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
			}
		}
	}
	output = secondInput.substr(maxLengthIndex - maxLength, maxLength);
}

char generateRandomChar() {
	return 'A' + rand()%26;
}

void generateRandomString(string& input, int length) {
	for (int i = 0; i < length; i++) {
		input += generateRandomChar();
	}
}

int main()
{
	srand(time(NULL));

	string firstString = "", secondString = "", longestCommonSubstringNotOptimal = "", longestCommonSubstringOptimal;
	generateRandomString(firstString, 50000);
	generateRandomString(secondString, 50000);

//	cout << firstString << endl;
//	cout << secondString << endl;


	clock_t tStart1 = clock();
	findLongestCommonSubstringNotOptimal(firstString, secondString, longestCommonSubstringNotOptimal);
	printf("Time taken: %.2fs\n", (double)(clock() - tStart1) / CLOCKS_PER_SEC);
	cout << longestCommonSubstringNotOptimal.length() << endl;

	clock_t tStart2 = clock();
	findLongestCommonSubstringOptimal(firstString, secondString, longestCommonSubstringOptimal);
	printf("Time taken: %.2fs\n", (double)(clock() - tStart2) / CLOCKS_PER_SEC);

}
