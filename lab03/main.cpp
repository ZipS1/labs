#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define NOT_FOUND -1

using std::string, std::vector, std::cout, std::cin, std::endl;

bool cmp(const string str1, const string str2)
{
	if (str1.length() == str2.length())
		return str1 < str2;
	else return str1.length() < str2.length();
}

void output(vector<string> words)
{
	for (int i = 0; i < words.size(); i++)
		cout << words[i] << " ";

	cout << endl;
}

int firstLetterFromStr(string str, string letters)
{
	size_t letterIndex = letters.length();
	for (char letter : letters)
		if (auto pos = str.find(letter) != string::npos)
			if (pos < letterIndex)
				letterIndex = pos;

	return letterIndex == letters.length() ? NOT_FOUND : letterIndex;
}

string transform(string str)
{
	if (str.length() <= 2)
		return str;

	const string vowels = "aoe";

	int index = firstLetterFromStr(str, vowels);
	if (index == NOT_FOUND)
		return str;

	return str.substr(index) + str.substr(0, index);
}

int main()
{
	cout << "Enter words (type \"0\" to stop): ";
	vector <string> words;
	string word;
	cin >> word;
	while (word != "0")
	{
		words.push_back(word);
		cin >> word;
	}

	sort(words.begin(), words.end(), cmp);
	cout << "Sorted: ";
	output(words);

	std::transform(words.begin(), words.end(), words.begin(), transform);
	cout << "Transformed: ";
	output(words);

	return 0;
}
