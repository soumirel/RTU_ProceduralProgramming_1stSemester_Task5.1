#include <iostream>

#include <fstream>
#include <string>

#define NOMINMAX
#include <Windows.h>


using namespace std;


int inputIntCorrect(){
	int input_number;
	while (!(cin >> input_number)){
		cout << "������������ ���� ������. ����������, ������� �������� ������:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input_number;
}


char inputCharCorrect(){
	string line;
	while (!(cin >> line) and line.length() != 1){
		cout << "������������ ���� ������. ����������, ������� �������� ������:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return line[0];
}


int inputPositiveNumberCorrect() {
	int input_number;
	while (!(cin >> input_number) || (input_number <= 0)) {
		cout << "������������ ���� ������. ����������, ������� �������� ������:\n";
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
		cout << "���� �� ����� ���� ������.\n";
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
					cout << "������ " << stringNumber << " ( ��������� " << stringCounter << " ���� ):\t\t";

				}
				else {
				cout << "������ " << stringNumber << " ( ��������� " << stringCounter << " ��� ):\t\t";
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
			cout << "\t\t����� ��������� " << fileCounter << " ���\n";
		}
		else {
			cout << "� ������ ������ ���������� ������� \"" << desiredSymbol << "\"\n";
		}
	}
	else {
		cout << "���� �� ����� ���� ������.\n";
	}

	file.close();
}


void findCharAtSpecificString(char desiredSymbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int neededLineNumber;
	cout << "������� ����� ������������ ������\n";
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
					cout << "������ � " << neededLineNumber << "\n";
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
					cout << "� " << neededLineNumber << "�� ������ �� ����������� �������� \"" << desiredSymbol << "\"\n";
				}
			}
		}
		if (counterLineNumber < neededLineNumber) {
			cout << "� ������ ������ ����� ������, ��� " << neededLineNumber << "\n";
		}
	}
	else {
		cout << "���� �� ����� ���� ������.\n";
	}
	file.close();
}


void findSpecificChar(char desiredSymbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int neededSymbolNumber;
	cout << "������� ����� �������.\n";
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
				cout << "������ \"" << desiredSymbol << "\" ��� ������� #" << neededSymbolNumber << " ��������� � c����� #" << neededStringNumber << ":\n";
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
			cout << "������ \"" << desiredSymbol << "\" ����������� � ������, �� �� ���������� ������, ��� " << neededSymbolNumber << "\n";
		}
		if (!isDesiredSymbolFind)
		{
			cout << "� ������ ��� �������� \"" << desiredSymbol << "\"\n";
		}
		if (neededSymbolNumber > counterAllSymbolsAtFile) {
			cout << "� ������ �������� ������, ��� �������� ���� �������� (" << neededSymbolNumber << ")\n";
		}
	}
	else {
		cout << "���� �� ����� ���� ������.\n";
	}

	file.close();
}

void searchingChar()
{
	char neededSymbol;
	cout << "������� ������������ ��� ������:\n";
	neededSymbol = inputCharCorrect();

	int condition;
	bool isAnswer = false;
	while (!isAnswer){
		cout << "����� ������� ��� ����������?\n1. ��� ������� � �����.\n2. ���������� ������.\n3. ���������� ������.\n";
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
			cout << "� ��� �� �������";
			break;
		}
	}
}
void main() {
	setlocale(LC_ALL, "Russian");

	cout << "������������ ������� �5. ��������� ��������� ������\n\n";
	cout << "1. (������ 12) ������ ������ �� �����.\n2. (������ 33) ����� �������� � ��������� ����� �� ��������� �������.\n";

	int task;
	bool isExit = false;
	while (!isExit){
		cout << "\n������� ����� �������, ���� �� ������ ��������� �������� - ������� 0\n";
		task = inputIntCorrect();
		switch (task){
		case 0:
			cout << "�� ��������!\n";
			isExit = true;
			break;
		case 1:
			cout << "������ ������ �� �����.\n";
			readText();
			break;
		case 2:
			cout << "����� �������� � ��������� ����� �� ��������� �������.\n";
			searchingChar();
			break;
		default:
			cout << "� ��� �� �������. ������� ����� ������ ���������.\n";
			break;
		}
	}
}