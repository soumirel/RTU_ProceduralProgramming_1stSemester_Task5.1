#include <iostream>

#include <fstream>
#include <string>

#define NOMINMAX
#include <Windows.h>


using namespace std;


int inputIntCorrect(){
	int input_number;
	while (!(cin >> input_number)){
		cout << "Некорректный ввод данных. Пожалуйста, введите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input_number;
}


char inputCharCorrect(){
	string line;
	while (!(cin >> line) and line.length() != 1){
		cout << "Некорректный ввод данных. Пожалуйста, введите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return line[0];
}


int inputPositiveNumberCorrect() {
	int input_number;
	while (!(cin >> input_number) || (input_number <= 0)) {
		cout << "Некорректный ввод данных. Пожалуйста, введите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input_number;
}


void readText() {
	fstream file;
	file.open("textForTask5.txt");
	if (file) {
		string getLine;
		while (!file.eof()) {
			getline(file, getLine);
			cout << getLine << endl;
		}
	} 
	else {
		cout << "Файл не может быть открыт.\n";
	}
	cout << (9 % 2);
	file.close();
}


void findAllCharsAtText(char desiredSymbol) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	fstream file;
	file.open("textForTask5.txt");

	if (file) {
		string getString;
		int stringNumber = 0;
		int stringCounter = 0;
		int fileCounter = 0;
		while (!file.eof()) {
			getline(file, getString);

			stringNumber++;
			stringCounter = 0;

			for (int i = 0; i < getString.length(); i++) {
				if (getString[i] == desiredSymbol) {
					stringCounter++;
				}
			}
			fileCounter += stringCounter;
			if (stringCounter != 0) {
				bool isNonTypicalTimesWord = ((stringCounter % 10 == 2) ||
					(stringCounter % 10 == 3) || (stringCounter % 10 == 4)) &&
					((stringCounter < 10) || (stringCounter > 20));
				if (isNonTypicalTimesWord) {
					cout << "Строка " << stringNumber << " ( встречено " << stringCounter << " раза ):\t\t";

				}
				else {
				cout << "Строка " << stringNumber << " ( встречено " << stringCounter << " раз ):\t\t";
				}
				for (int k = 0; k < getString.length(); k++) {
					if (getString[k] == desiredSymbol) {
						SetConsoleTextAttribute(hConsole, 240);
					}
					else {
						SetConsoleTextAttribute(hConsole, 15);
					}
					cout << getString[k];

				}
				SetConsoleTextAttribute(hConsole, 15);
				cout << endl;
			}
		}
		if (fileCounter > 0) {
			cout << "\t\tВсего встречено " << fileCounter << " раз\n";
		}
		else {
			cout << "В данном тексте отсутсвуют символы \"" << desiredSymbol << "\"\n";
		}
	}
	else {
		cout << "Файл не может быть открыт.\n";
	}

	file.close();
}


void findCharAtSpecificString(char desiredSymbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int neededLineNumber;
	cout << "Введите номер интересующей строки\n";
	neededLineNumber = inputPositiveNumberCorrect();

	fstream file;
	file.open("textForTask5.txt");
	if (file) {
		string getLine;
		int counterLineNumber = 0;
		bool isStringFind = false;
		while (!file.eof()) {
			getline(file, getLine);
			counterLineNumber++;

			if (counterLineNumber == neededLineNumber) {
				for (size_t i = 0; i < getLine.length(); i++) {
					if (getLine[i] == desiredSymbol) {
						isStringFind = true;
					}
				}
				if (isStringFind) {
					cout << "Строка № " << neededLineNumber << "\n";
					for (size_t i = 0; i < getLine.length(); i++) {
						if (getLine[i] == desiredSymbol) {
							SetConsoleTextAttribute(hConsole, 240);
							cout << getLine[i];
						}
						else {
							cout << getLine[i];
						}
						SetConsoleTextAttribute(hConsole, 15);
					}
					cout << "\n";
				}
				else {
					cout << "В " << neededLineNumber << "ой строке не встретилось символов \"" << desiredSymbol << "\"\n";
				}
			}
		}
		if (counterLineNumber < neededLineNumber) {
			cout << "В данном тексте строк меньше, чем " << neededLineNumber << "\n";
		}
	}
	else {
		cout << "Файл не может быть открыт.\n";
	}
	file.close();
}


void findSpecificChar(char desiredSymbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int neededSymbolNumber;
	cout << "Введите номер символа.\n";
	neededSymbolNumber = inputPositiveNumberCorrect();

	fstream file;
	file.open("textForTask5.txt");
	if (file) {
		string getLine;
		int counterStringNumber = 0;
		int counterSymbolsAtFile = 0;
		int neededSymbolNumberAtString;
		int neededStringNumber;
		int counterAllSymbolsAtFile = 0;
		int counterDesiredSymblosAtFile = 0;
		bool isFindNeededString = false;
		bool isDesiredSymbolFind = false;
		while (!file.eof()) {
			getline(file, getLine);
			counterStringNumber++;
			counterAllSymbolsAtFile += getLine.length();

			for (int i = 0; i < getLine.length(); i++) {
				if (getLine[i] == desiredSymbol) {
					counterDesiredSymblosAtFile++;
					isDesiredSymbolFind = true;
					if (counterDesiredSymblosAtFile == neededSymbolNumber)
					{
						neededStringNumber = counterStringNumber;
						neededSymbolNumberAtString = i;
						isFindNeededString = true;
					}
				}
			}
			if (isFindNeededString) {
				cout << "Символ \"" << desiredSymbol << "\" под номером #" << neededSymbolNumber << " находится в cтроке #" << neededStringNumber << ":\n";
				for (int k = 0; k < getLine.length(); k++) {
					if (getLine[k] == desiredSymbol && neededSymbolNumberAtString == k) {
						SetConsoleTextAttribute(hConsole, 240);
						cout << getLine[k];
					}
					else {
						cout << getLine[k];
					}
					SetConsoleTextAttribute(hConsole, 15);
				}
				isFindNeededString = false;
				cout << endl;
			}
		}
		if ((neededSymbolNumber > counterDesiredSymblosAtFile) && isDesiredSymbolFind) {
			cout << "Символ \"" << desiredSymbol << "\" присутсвует в тексте, но их количество меньше, чем " << neededSymbolNumber << "\n";
		}
		if (!isDesiredSymbolFind)
		{
			cout << "В тексте нет символов \"" << desiredSymbol << "\"\n";
		}
		if (neededSymbolNumber > counterAllSymbolsAtFile) {
			cout << "В тексте символов меньше, чем ввёденное вами значение (" << neededSymbolNumber << ")\n";
		}
	}
	else {
		cout << "Файл не может быть открыт.\n";
	}

	file.close();
}

void searchingChar()
{
	char neededSymbol;
	cout << "Введите интересующий вас символ:\n";
	neededSymbol = inputCharCorrect();

	int condition;
	bool isAnswer = false;
	while (!isAnswer){
		cout << "Какое условие вас интересует?\n1. Все символы в файле.\n2. Конкретная строка.\n3. Конкретный символ.\n";
		condition = inputIntCorrect();

		switch (condition){
		case 1:
			isAnswer = true;
			findAllCharsAtText(neededSymbol);
			break;
		case 2:
			isAnswer = true;
			findCharAtSpecificString(neededSymbol);
			break;
		case 3:
			isAnswer = true;
			findSpecificChar(neededSymbol);
			break;
		default:
			cout << "Я вас не понимаю";
			break;
		}
	}
}
void main() {
	setlocale(LC_ALL, "Russian");

	cout << "Практическое задание №5. Обработка текстовых файлов\n\n";
	cout << "1. (задача 12) Чтение текста из файла.\n2. (задача 33) Поиск элемента в текстовом файле по заданному условию.\n";

	int task;
	bool isExit = false;
	while (!isExit){
		cout << "\nВведите номер задания, если вы хотите закончить проверку - введите 0\n";
		task = inputIntCorrect();
		switch (task){
		case 0:
			cout << "До свидания!\n";
			isExit = true;
			break;
		case 1:
			cout << "Чтение текста из файла.\n";
			readText();
			break;
		case 2:
			cout << "Поиск элемента в текстовом файле по заданному условию.\n";
			searchingChar();
			break;
		default:
			cout << "Я вас не понимаю. Введите номер задачи корректно.\n";
			break;
		}
	}
}