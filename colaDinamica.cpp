// esto es para hacer la cola. 

#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

struct Nodo{
	int numero;
	Nodo *sig;
};
struct Cola{
	Nodo *entrada;
	Nodo *salida;
};

void encolar (int numero, Cola *cola){
	Nodo *aux = new Nodo ();
	aux -> numero = numero;
	aux -> sig = NULL;
	
	if (cola->salida == NULL){
		cola -> salida = aux;
	}else{
		cola -> entrada -> sig = aux;
	}
	cola -> entrada = aux;
}
void desencolar (Cola *cola){
	if (cola -> salida != NULL){
		if (cola -> salida == cola -> entrada) {
			cola->salida = cola->salida -> sig;
			cola->entrada = cola->entrada -> sig;
		}else{
			cola -> salida = cola -> salida -> sig;
		}
	}
}

void imprimir (Cola *cola){
	Nodo *aux = new Nodo ();
	aux = cola -> salida;
	while (aux != NULL){
		cout << ("  +") <<aux->numero;
		aux = aux -> sig;
	}
	cout << "\\\\ Entrada de datos. ";
}

int contadorNecesarioParaQueSeCreeAleatorio = -1;
int azar (int numeroMaximoAleatorio){
	int numero;
	srand (time(NULL));  //me proporciona un numero aleatorio cada vez que lanzo el programa de nuevo. 
	if (contadorNecesarioParaQueSeCreeAleatorio == -1){
		contadorNecesarioParaQueSeCreeAleatorio = rand()%100;
	}else{
		contadorNecesarioParaQueSeCreeAleatorio++;
	}
	srand (contadorNecesarioParaQueSeCreeAleatorio);
	numero = rand()%numeroMaximoAleatorio;
	return numero;
}

int main (){
	cout << ("\n Funcionamiento de Cola, las órdenes son: encolar, desencolar, imprimir");
	Cola *miCola = new Cola ();
	miCola -> entrada = NULL;
	miCola -> salida = NULL;
	
	bool verdad = true;
	char orden[20];
	int numero = 0;
	
	while (verdad == true){
		cout << ("\n Escriba la orden:  ");
		cin.getline (orden, 20, '\n');
		
		if (strcmp (orden, "salir") == 0){
			verdad = false;
			cout << ("Se va a salir del programa.");
		}else if (strcmp (orden, "encolar") == 0){
			numero = azar (100);
			encolar (numero, miCola);
		}else if (strcmp (orden, "imprimir") == 0){
			cout << ("Se va a imprimir la Cola.");
			imprimir (miCola);
		}else if (strcmp (orden, "desencolar") == 0){
			cout << ("Se va a desencolar. ");
			desencolar (miCola);
		}else{
			cout << ("No se ha entendido la orden. ");	
		}
	}
	return 0;
}






