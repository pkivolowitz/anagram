#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc <= 1) {
		cout << "The file name to read must be given." << endl;
	}
	else {
		// There is at least one argument.
		ifstream f(argv[1]);
		if (f) {
			string line;
			// The file is open.
			// For every line, read it in.
			while (getline(f, line)) {
				int delta = 1;
				int letter_counters[26] = { 0 };
				// for every character, examine / process it
				for (size_t i = 0; i < line.size(); i++) {
					char c = line[i];
					if (isalpha(c) || c == '?')
					{
						if (c == '?') {
							delta = -1;
							continue;
						}
					}
					// If we get here, c is an alphabetic char possibly upper case.
					c = tolower(c);
					// Now we are sure c is a lower case alphabetic character.
					letter_counters[c - 'a'] += delta;
				}
				// Write the code here that would check to see if all of the entries
				// in letter_counters were zero. If they are, we have an anagram.
				
			}
			f.close();
		}
		else {
			cout << "Could not open file: " << argv[1] << endl;
		}
	}
#if defined(WIN32) || defined(_WIN64)
	system("pause");
#endif 
	return 0;
}