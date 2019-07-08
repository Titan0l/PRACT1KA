

#include <fstream>
#include <iostream>
using namespace std;


int main() {

	const int len = 81;

	char line[len];

	ifstream fin("text.txt");
	if (!fin) {
		cout << "Ошибка открытия файла." << endl; return 1;
	}

	while (fin.getline(line, len)) {

		char * p = line;
		int flag = 0;

		for (; *p; ++p) {
			if ((isspace(*p) || ispunct(*p))) flag = 0; // пробел или переход на новую строку

			else {
				if (!flag && strchr("AEIOUY", toupper(*p)))
					*p = toupper(*p); // заменяет на прописную букву
				flag = 1;
			}
		}
		cout << line << endl;

	}

	system("pause");
}