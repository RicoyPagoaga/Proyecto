#include <iostream>
#include <string>
#include <exception>

using namespace std;

struct detalle {
	int linea;
	string producto;
	double cantidad;
	double precio;
	double isv;
	double descuento;
	double subtotalDetalle;
};

struct factura {
	string fecha;
	string cliente;
	double subtotal;
	double isv;
	double descuento;
	double totalPagar;
	detalle arregloDetalles[3];

}facturas[3];

double subTotalDetalle(double cantidad, double precio, double descuento, double isv) {
	double subtotaldetalle;
	double neto = (cantidad * precio);
	subtotaldetalle = neto - (neto * descuento) + (neto * isv);
	return subtotaldetalle;
}

double redondear(double valor, int CantidadDecimales) {
	const double multiplicador = pow(10.00, CantidadDecimales);
	return ceil(valor * multiplicador) / multiplicador;
}

int main() {

	for (int i = 0; i < 3; i++)
	{
		cout << "Tienda supernatural" << endl;
		cout << "Ingrese la fecha:" << endl;
		cin.ignore();
		getline(cin, facturas[i].fecha);
		cout << "Ingrese el nombre del cliente: " << endl;
		getline(cin, facturas[i].cliente);
		for (int j = 0; j < 3; j++)
		{
			cout << "Linea: " << j + 1 << endl;
			cout << "Ingrese el producto a adquirir:" << endl;
			cin.ignore();
			getline(cin, facturas[i].arregloDetalles[j].producto);
			do
			{
				cout << "Ingrese la cantidad de " << facturas[i].arregloDetalles[j].producto << " que llevara" << endl;
				cin >> facturas[i].arregloDetalles[j].cantidad;
				if (facturas[i].arregloDetalles[j].cantidad <= 0)
				{
					cout << "cantidad no aceptada" << endl;
				}
			} while (facturas[i].arregloDetalles[j].cantidad <= 0);
			;
			do
			{
				cout << "Ingrese el precio del producto: " << endl;
				cin >> facturas[i].arregloDetalles[j].precio;
				if (facturas[i].arregloDetalles[j].precio <= 0)
				{
					cout << "cantidad no aceptada" << endl;
				}
			} while (facturas[i].arregloDetalles[j].precio <= 0);
			do
			{
				cout << "Ingrese el descuento de este producto:" << endl;
				cin >> facturas[i].arregloDetalles[j].descuento;
				if (facturas[i].arregloDetalles[j].descuento <= 0)
				{
					cout << "cantidad no aceptada" << endl;
				}
			} while (facturas[i].arregloDetalles[j].descuento <= 0);
			do
			{
				cout << "Ingrese el Isv: " << endl;
				cin >> facturas[i].arregloDetalles[j].isv;
				if (facturas[i].arregloDetalles[j].isv <= 0)
				{
					cout << "cantidad no aceptada" << endl;
				}
			} while (facturas[i].arregloDetalles[j].isv <= 0);
			cout << "El subTotal detalle : " << subTotalDetalle(facturas[i].arregloDetalles[j].cantidad, facturas[i].arregloDetalles[j].precio, facturas[i].arregloDetalles[j].descuento, facturas[i].arregloDetalles[j].isv) << endl;
			facturas[i].subtotal += subTotalDetalle(facturas[i].arregloDetalles[j].cantidad, facturas[i].arregloDetalles[j].precio, facturas[i].arregloDetalles[j].descuento, facturas[i].arregloDetalles[j].isv);
			facturas[i].isv += facturas[i].arregloDetalles[j].isv;
			facturas[i].descuento += facturas[i].arregloDetalles[j].descuento;
		}
		facturas[i].totalPagar = facturas[i].subtotal - facturas[i].descuento + facturas[i].isv;
		int j = 0;
		cout << "producto"<<facturas[i].arregloDetalles[j].producto;
		system("pause");
		return 0;
	}