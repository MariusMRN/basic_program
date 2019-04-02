#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <math.h>
#include <string>

using namespace std;

string todo;
void todop();

void clear_screen(char fill = ' ') {

	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}

void help() {

	cout << "\n########################################################\n\n"
		 << " sum - Calculate the sum of X numbers" << endl
		 << " b_digit - Calculate the biggest digit from a number" << endl
		 << " divisors - How many divisors a number have" << endl
		 << " gauss - Gauss sum" << endl
		 << " prime_check - Check if a number is prime" << endl
	 	 << " arithmetic - Calculate the arithmetic avg of numbers" << endl
		 << " sqroot - Get the square root of a number" << endl
		 << " convert - convert somethig to something\n" << endl
		 << "########################################################\n\n";
	return todop();
}

float sum() {

	int n;
	float v[100], suma = 0;

	cout << "* Insert the number of numbers you want: ";
	cout << "\n > "; cin >> n;

	for (int i = 1; i <= n; i++) {

			cout << "\n Insert 1 number ("<< i << " of " << n << ") > ";
			cin >> v[i];
	}

	for (int i = 1; i <= n; i++)
		suma += v[i];
	return suma;
}

int biggest_digit(){

	int n, max1 = 1, ld;

	cout << "Insert the number from where you want to get the biggest digit: "
		 << "\n > "; cin >> n;

	int aux = n;

	while (n) {
		ld = n % 10;
		if (ld >= max1)
			max1 = ld;
		
		n /= 10;
	}

	return max1;

}

int divisors_number() {

	long long int n, counter = 0;

	cout << "Insert the number from where you want to get the divisors number: "
		 << "\n > "; cin >> n;

	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			counter++;

	return counter;

}

 /*int all_divisors() {

	long long int n, v[1000];

	for (int i = 1; i <= read_n(); i++)
		if (read_n() % 1 == 0) {
			v[i] = i;
			return i;
		}

} */

int gauss() {

	int n, sum = 0;

	cout << "Insert n: "
		<< "\n > "; cin >> n;

	for (int i = 1; i <= n; i++)
		sum += i;

	return sum;
		
}

int prime_check() {

	int n;

	cout << "Insert the number to check if it's prime or not:"
		 << "\n > "; cin >> n;

	if (n <= 2)
		return 0;

	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
		else
			return 1;
}

float arithmetic_avg() {

	int n, counter = 0; 
	float v[100], sum = 0, ma = 0;

	cout << "You want to calculate the avg of how many numbers: "
		<< "\n > "; cin >> n;

	for (int i = 1; i <= n; i++) {

		cout << "\n Insert 1 number (" << i << " of " << n << ") > "; 
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		sum += v[i];
		counter++;
	}

	ma = sum / counter;

	return ma;

}

float square_root() {

	long long int n;
	float sqroot;

	cout << "Insert the number from where you want to get the square root"
		<< "\n > "; cin >> n;

	sqroot = sqrt(n);

	return sqroot;

}

void convert() {

	clear_screen();

	cout << " What do you want to convert ?" << endl << endl
		<< " 1 - temperature " << endl
		<< " 2 - meters" << endl;

	cin >> todo;

	if (todo == "1" ) {

		float celsius, fahrenheit, value;

		cout << "You want to convert celsius to fahrenheit or fahrenheit to celsius?\n\n1 -> celsius to fahrenheit\n2 -> fahrenheit to celsius"
			<< "\n > "; cin >> value;

		if (value == 1) {

			cout << "Insert celsius value"
				<< "\n > "; cin >> celsius;

			cout << endl << endl << celsius << " celsius degrees, in fahrenheit means " << celsius * 9 / 5 + 32 << " degrees" << endl << endl;

		}

		if (value == 2) {

			cout << "Insert fahrenheit value"
				<< "\n > "; cin >> fahrenheit;

			cout << endl << endl << fahrenheit << " fahrenheit degrees, in celsius means " << (fahrenheit - 32) * 5 / 9 << " degrees" << endl << endl;
		}

	}

	if (todo == "2") {

		int meters;

		clear_screen();

		cout << "Enter your meters value: " << endl;

		cin >> meters;

		cout << "\nIn what do you want to transform your meters" << endl
			 << " 1 - km " << endl
			 << " 2 - hm " << endl
			 << " 3 - dam " << endl
			 << " 4 - dm " << endl
			 << " 5 - cm " << endl
			 << " 6 - mm " << endl << endl;

		cin >> todo;

		if (todo == "1")
			cout << "Your " << meters << " meters transformed in dam means " << meters / 1000 << " dam " << endl << endl;

		if (todo == "2")
			cout << "Your " << meters << " meters transformed in dam means " << meters / 100 << " hm " << endl << endl;

		if (todo == "3")
			cout << "Your " << meters << " meters transformed in dam means " << meters / 10 << " km " << endl << endl;

		if (todo == "4")
			cout << "Your " << meters << " meters transformed in dam means " << meters * 10 << " dm " << endl << endl;

		if (todo == "5")
			cout << "Your " << meters << " meters transformed in dam means " << meters * 10 << " cm " << endl << endl;

		if (todo == "6")
			cout << "Your " << meters << " meters transformed in dam means " << meters * 10 << " mm " << endl << endl;
	}
}

void back();

void todop() {

	cout << "[!] For help, type help [!]\n\n\n > ";
	cin >> todo;

	if ((todo != "help") && (todo != "sum") && (todo != "b_digit") && (todo != "divisors") && (todo != "gauss") && (todo != "prime_check") && (todo != "arithmetic") && (todo != "sqroot") && (todo != "convert") ) {
		cout << "\nUnknown command.\n\n";
		return todop();
	}

	if (todo == "help") {
		help();
	}

	if (todo == "sum") {
		cout << endl << endl << "[!] Sum is: " << sum() << endl << endl;

		back();

	}

	if (todo == "b_digit") {
		cout << endl << endl << "The biggest digit is " << biggest_digit() << endl << endl;
		
		back();

	}

	if (todo == "divisors") {
		cout << endl << endl << "The divisros number is: " << divisors_number() << endl << endl;

		back();

	}

	if (todo == "gauss") {
		cout << endl << endl << "Gauss sum is: " << gauss() << endl << endl;
		
		back();

	}

	if (todo == "prime_check") {
		cout << endl << "The number is prime: " << prime_check() << endl << endl;
		cout << "1 - True \n0 - False\n\n";

		back();

	}

	if (todo == "arithmetic") {
		cout << endl << endl << "The arithmetic avg is: " << fixed << setprecision(2) << arithmetic_avg() << endl << endl;
		
		back();

	}

	if (todo == "sqroot") {
		cout << endl << endl << "The square root of your number is: " << square_root() << endl << endl;

		back();

	}

	if (todo == "convert") {
		convert();

		back();
	}

}

void back() {

	string x;

	cout << "Type back to go back" << endl; cin >> x;
	if (x == "back") {
		clear_screen();
		return todop();
	}
	else if (x != "back")
		return back();
}


int main() {

	todop();

/*	cout << "[!] For help, type help [!]\n\n\n > ";
	cin >> todo;

// CHECK WHAT TO DO 

	if ( (todo != "help") && (todo != "sum") && (todo != "b_digit") && (todo != "divisors") && (todo != "gauss") && (todo != "prime_check") && (todo != "arithmetic")) {
		cout << "\nUnknown command.\n\n";
		return main();
	}

	if (todo == "help") {
		help();
		return main();
	}
	
	if (todo == "sum") {
		cout << endl << endl << "[!] Sum is: " << sum() << endl << endl;
		
		back(todo);

	}

	if (todo == "b_digit") {
		cout << endl << endl << "The biggest digit is " << biggest_digit() << endl << endl;
		cout << "Type back to go back" << endl; cin >> todo;
		if (todo == "back") {
			clear_screen();
			return main();
		}
	}

	if (todo == "divisors") {
		cout << endl << endl << "The divisros number is: " << divisors_number() << endl << endl;
		cout << "Type back to go back" << endl; cin >> todo;
		if (todo == "back") {
			clear_screen();
			return main();
		}
	}

	if (todo == "gauss") {
		cout << endl << endl << "Gauss sum is: " <<gauss() << endl << endl;
		cout << "Type back to go back" << endl; cin >> todo;
		if (todo == "back") {
			clear_screen();
			return main();
		}
	}

	if (todo == "prime_check") {
		cout << endl << "The number is prime: " << prime_check() << endl << endl;
		cout << "1 - True \n0 - False\n\n";
		cout << "Type back to go back" << endl; cin >> todo;
		if (todo == "back") {
			clear_screen();
			return main();
		}
	}

	if (todo == "arithmetic") {
		cout << endl << endl << "The arithmetic avg is: " << fixed << setprecision(2) << arithmetic_avg() << endl << endl;
		cout << "Type back to go back" << endl; cin >> todo;
		if (todo == "back") {
			clear_screen();
			return main();
		}
	} */
	system("pause");
}