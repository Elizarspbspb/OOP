#define legal_psw "my.good.password" 
#include <iostream>
#include <cstring>

using namespace std; 

int main() { 
	char user_psw[666]; 
	cout << "crackme 00h\nenter passwd:"; 
	cin >> user_psw; 
	if (strcmp(legal_psw, user_psw)) 
		cout << "wrong password\n"; 
	else 
		cout << "password ok\nhello, legal user!\n"; 
	cin >> user_psw; 
	return 0; 
} 
