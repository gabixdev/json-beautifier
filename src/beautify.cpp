// Created by gabixdev
// Licensed under WTFPL

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	string whitespace = "    ";

	long level = 0;
	char c;
	bool ignore_next = false;
	bool in_string = false;

	while (cin.get(c)) {
		switch (c) {
			case '[':
			case '{':
				if (in_string) {
					cout << c;
					break;
				}
				level++;
				cout << c << endl;
				for (int i = 0; i < level; i++)
					cout << whitespace;
				break;
			case ']':
			case '}':
				if (in_string) {
					cout << c;
					break;
				}
				if (level != 0)
					level--;
				cout << endl;
				for (int i = 0; i < level; i++)
					cout << whitespace;
				cout << c;
				break;
			case ',':
				if (in_string) {
					cout << ",";
					break;
				}
				cout << "," << endl;
				for (int i = 0; i < level; i++)
					cout << whitespace;
				break;
			case '\\':
				if (ignore_next)
					ignore_next = false;
				else
					ignore_next = true;
				cout << "\\";
				break;
			case '"':
				if (!ignore_next)
					in_string = !in_string;
				cout << "\"";
				break;
			case ' ':
				if (in_string)
					cout << " ";
				break;
			case ':':
				cout << ":";
				if (!in_string)
					cout << " ";
				break;
			case '\r':
			case '\n':
				break;
			default:
				if (ignore_next)
					ignore_next = false;
				cout << c;
				break;
		}
	}
	return 0;
}