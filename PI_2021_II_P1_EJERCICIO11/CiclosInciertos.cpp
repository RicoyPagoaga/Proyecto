#include <iostream>
#include <string>


using namespace std;

int main() {
	int numero;
	cout << "Ingrese un numero" << endl;
	cin >> numero;
	while ((numero < 20) && (numero >= 10))
	{
		cout << "Ingrese un numero" << endl;
		cin >> numero;

	}
	system("pause");
	return 0;
}