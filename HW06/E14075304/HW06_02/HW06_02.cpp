//HW06_02
//許笙杰 機械一乙 E14075304
#include<iostream>
#include<string>
using namespace std;

int main() {
	string content = "The supply of game for London is going steadily up. "
					"Head-keeper Hudson, we believe, has been now told to receive all orders for fly "
					"paper and for preservation of your hen pheasant's life.";		// Content of letter
	string separators = " .,-";		// Word delimeters
	size_t start = content.find_first_not_of(separators);		// Index of the start of the word
	size_t end = 0;		// Index of the end of the word

	cout << "Content:" << endl << content << endl << endl;		// Show content

	cout << "Answer:" << endl;
	int word_count = 0;		

	// Do these until no word
	while (start != string::npos) {
		end = content.find_first_of(separators, start + 1);		// Find end of word

		// If we cannot find a separator, set end = last + 1
		if (end == string::npos)
			end = content.length();

		word_count++;		// Increase word count

		// Output the found word for every 3 words (start from first word)
		if (word_count % 3 == 1)
			cout << content.substr(start, end - start) << " ";

		start = content.find_first_not_of(separators, end + 1);		// First character of next word
	}
	cout << endl;
	system("pause");
	return 0;
}