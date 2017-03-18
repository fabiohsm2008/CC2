#include <iostream>
#include <string>
using namespace std;

int billetes[] = {200, 100, 50, 20, 10, 5, 2, 1};
float moneditas[] = {0.5, 0.2, 0.1};

//int contBills[8];
//float contMoneds[3];

float askAmount(){
	float am;
	cout << "Ingrese la cantidad: ";
	cin >> am;
	if (am >999999.90){
		cout << "Cantidad excedida.";
		return askAmount();
	}
	return am;
}

void totalBills(float amount){
	int i = 0, cont, num = int(amount);
	string res, need, sol;
	amount -= num;
	//cout << num << " " << amount << endl;
	for(i; i<8; i++){
		cont = 0;
		if (num >= billetes[i]){
			cont = num / billetes[i];
			if (num > 1)
				sol = " soles.\n";
			else
				sol = " sol.\n";
			num %= billetes[i];//cont++;
			//cout << num << endl;
		}
		if (cont == 0) //comentar este if si se quiere que aparezca "0 monedas de..."
			continue;
		if (i < 5)
			if (cont == 1){
				res = " billete ";
				need = "necesita ";
			}else{
				res = " billetes ";
				need = "necesitan ";
			}
		else
			if (cont == 1){
				res = " moneda ";
				need = "necesita ";
			} else {
				res = " monedas ";
				need = "necesitan ";
			}
		cout << "Se " << need << cont << res << "de " << billetes[i] << sol;
	}
	for(i = 0; i<3; i++){
		cont = 0;
		while (amount > moneditas[i]){
			amount -= moneditas[i];
			cont++;
		}
		if (cont == 0) //comentar este if si se quiere que aparezca "0 monedas de..."
			continue;
		else if (cont == 1) {
			res = " moneda ";
			need = "necesita ";
		} else {
			res = " monedas ";
			need = "necesitan ";
		}
		cout << "Se " << need << cont << res << "de " << moneditas[i] << " soles.\n"; 
	}
	
}

int main() {
	totalBills(askAmount());
	return 0;
}

