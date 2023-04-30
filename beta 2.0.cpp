#include <iostream>
#include <fstream>
#include <ctime>    
#include <string>
#include <vector>
#include <sstream>
#include <chrono>
#include <cstdlib>
#include <conio.h>
#include<windows.h>
using namespace std;

void gotoxy (int x, int y);
void animacion();
void InsertarNumerosTxt();
void LeerUnTxtBurbuja();
void LeerTxtSeleccion();
void LeerUnTxtInsercion();
int auxiliar(vector<int> &numerosInt, int LimIzquier, int LimDerecho);
void quicksort(vector<int> &numerosInt, int LimIzquier, int LimDerecho);
void LeerTxtQuicksort();

char menu;


int main() {
	animacion();
	system("color 9");
	system("cls");
	
	int op, metodo;
	
	cout<<"Bienvenido :) \n";
	cout<<"Por favor, seleccione la opcion que desea ejecutar\n";
	cout<<"1. Insertar una cantidad de numeros aleatorios y ordenarlos\n";
	cout<<"2. Ordenar una base de datos de numeros de una archivo .txt\n";
	cin>>op;
	
	//opciones para que el usuario elija que desea hacer
	switch(op){
		case 1:
			InsertarNumerosTxt();
		break;
		case 2:
			cout<<"Bienvenido a la opcion de poder ordenar un archivo de texto (nuemeros)\n";
			cout<<"por favor digite el tipo de metodo que desea utilizar para ordenar: \n";
			cout<<"1. Burbuja\n";
			cout<<"2. Seleccion\n";
			cout<<"3. Insercion\n";
			cout<<"4. Quicksort\n";
			cin>>metodo;
			switch(metodo){
				case 1:
					LeerUnTxtBurbuja();
				break;
				case 2:
					LeerTxtSeleccion();
				break;
				case 3:
					LeerUnTxtInsercion();
				break;
				case 4:
					LeerTxtQuicksort();
				break;
			}
		break;
			
	}
	return 0;
}

void gotoxy (int x, int y){
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  	
}

void animacion(){
    int i = 0;
	string inicio[28] = {"G","e","n","e","r","a","d","o","r"," ","d","e"," ","n","u","m","e",
	"r","o","s"," ","U","M","G"," ","1",".","0"};
	gotoxy(45, 12);
	for(int i=0; i<28; i++){
		system("color 3");
		cout<<inicio[i];
		Sleep(100);
	}
	cout<<""<<endl;
    cout<<""<<endl;
    
    while(true){
    if (i == 0) {
    system("color 2");
    system("cls");
    cout<<""<<endl;
    gotoxy(50, 12);
    cout<<"*****"<<endl;
    gotoxy(50, 13);
    cout<<"    *"<<endl;
    gotoxy(50, 14);
    cout<<"*****"<<endl;
    gotoxy(50, 15);
    cout<<"    *"<<endl;
    gotoxy(50, 16);
    cout<<"*****"<<endl;
    gotoxy(50, 17);
    Sleep(50);
    system("cls");
    cout<<""<<endl;
    i = 1;
        
    } else if (i == 1) {
    system("color 1");
    gotoxy(50, 12);
    cout<<"*****"<<endl;
    gotoxy(50, 13);
    cout<<"    *"<<endl;
    gotoxy(50, 14);
    cout<<"*****"<<endl;
    gotoxy(50, 15);
    cout<<"*    "<<endl;
    gotoxy(50, 16);
    cout<<"*****"<<endl;
    gotoxy(50, 17);
    Sleep(50);
    system("cls");
    cout<<""<<endl;
    i = 2;
    
    } else if (i == 2) {
    system("color D");
    gotoxy(50, 12);
	cout<<"   *"<<endl;
	gotoxy(50, 13);
    cout<<"  **"<<endl;
    gotoxy(50, 14);
    cout<<" * *"<<endl;
    gotoxy(50, 15);
    cout<<"   *"<<endl;
    gotoxy(50, 16);
    cout<<"   *"<<endl;
    gotoxy(50, 17);
    Sleep(50);
    system("cls");
    cout<<""<<endl;
	i = 3;
	
    } else if (i == 3) {
    system("color 6");
    gotoxy(50, 12);
    cout<<"*****"<<endl;
    gotoxy(50, 13);
    cout<<"*   *"<<endl;
    gotoxy(50, 14);
    cout<<"*   *"<<endl;
    gotoxy(50, 15);
    cout<<"*   *"<<endl;
    gotoxy(50, 16);
    cout<<"*****"<<endl;
    gotoxy(50, 17);
    Sleep(50);
    system("cls");
	i = 0;	
	}
    if (_kbhit()) {  // Si se presiona una tecla, detener el ciclo
            char key = _getch();
            break;
        }
        }
}

//parte donde se genera un txt y se ordena
void InsertarNumerosTxt(){
	// Obtener la semilla del generador de numeros aleatorios
	srand(time(0));
	char op;
	
	// Obtener la cantidad de numeros aleatorios a generar
	int numNumeros;
	cout << "Ingrese la cantidad de numeros aleatorios a generar: ";
	cin >> numNumeros;
	  
	// Crear un objeto ofstream para escribir en un archivo
	ofstream archivo("ordenando.txt");
	
	// Verificar si se abrio el archivo exitosamente
	if (archivo.is_open()) {
		// Generar y escribir los numeros aleatorios en el archivo separados por comas
	    cout << "Numeros aleatorios generados: ";
	    for (int i = 0; i < numNumeros; i++) {
	    	int numero = rand() % 100;  // Generar numero aleatorio entre 0 y 99
	    	if (i != numNumeros - 1) {
	        	archivo << numero <<  " ";  // Escribir numero en el archivo seguido de una coma
	        	cout<< numero << ", ";
	    	} else {
	        	archivo << numero << endl;  // Escribir ultimo numero en el archivo seguido de un salto de linea
	        	cout<< numero << endl;
	    	}
		}
		// Cerrar el archivo
		archivo.close();
		cout << "\nNumeros aleatorios generados y guardados en el archivo exitosamente." << endl;
	} else {
	    cout << "Error al crear el archivo." << endl;
	}
	
	//opciones para ordenar con el archivo local modificado
	cout<<"Desea ordenar los numeros? s/n: ";
	cin>>op;
	
	if(op == 's' || op == 'S'){
		int seleccionado;
		cout<<"Por favor, elija un tipo de ordenamiento: \n";
		cout<<"1. Ordenamiento por burbuja\n";
		cout<<"2. Ordenamiento por seleccion\n";
		cout<<"3. Ordenamiento por insercion\n";
		cout<<"4. Ordenamiento por quicksort\n";
		cin>>seleccionado;
		
		vector<int> numerosInt; //crear un vector de tipo entero
		string linea;
				
		ifstream archivoLectura("ordenando.txt");
		
		//ordenamiento por metodo de burbuja
		if(seleccionado == 1){
			auto tiempoInicial = chrono::high_resolution_clock::now();
			cout<<"\n Haz elejido Ordenamiento por Burbuja, ordenando Numeros........ ";
			ofstream burbuja("burbuja.txt", ios::app);
				
			if(archivoLectura.is_open()){
				//leer contenido del txt y ordenarlo burbuja	    
				while (getline(archivoLectura, linea)) {
					istringstream iss(linea);
					
					int numeroInt2;
						
					//identifica el espacio para separar
					while (iss >> numeroInt2) {
				        numerosInt.push_back(numeroInt2);
					}
				}
					
				//metodo de burbuja ordenamiento
				int tam = numerosInt.size();
					
				for (int i = 0; i < tam - 1; i++) {
				    for (int j = 0; j < tam - 1 - i; j++) {
				        if (numerosInt[j] > numerosInt[j + 1]) {
				            swap(numerosInt[j], numerosInt[j + 1]);
				        }
				    }
				}
				//imprime valores ordenados
				cout << "\nLos numeros enteros ordenados son: ";
				for (size_t i = 0; i < numerosInt.size(); i++) {
				    int numero = numerosInt[i];
				    burbuja << numero << ", ";
				    cout << numero << " ";
				}
				burbuja.close();
				
				auto tiempoFinal = chrono::high_resolution_clock::now();
				chrono::duration<double> tiempoCon = tiempoFinal - tiempoInicial;
				
				int horas = chrono::duration_cast<chrono::hours>(tiempoCon).count();
			    tiempoCon -= chrono::duration_cast<chrono::hours>(tiempoCon);
			    int minutos = chrono::duration_cast<chrono::minutes>(tiempoCon).count();
			    tiempoCon -= chrono::duration_cast<chrono::minutes>(tiempoCon);
			    int segundos = chrono::duration_cast<chrono::seconds>(tiempoCon).count();
				cout << "\n\nTiempo de ejecucion: " << horas << " horas, " << minutos << " minutos y " << segundos << " segundos." <<endl;
				
				cout << "\nDesea regresar al menu principal? (s/n): ";
				cin >> menu;
				if(menu == 's' || menu == 'S'){
					system("cls");
					main();	
				}
			}
			archivoLectura.close();
		}
		
		//ordenamiendo por metodo de seleccion
		if(seleccionado == 2){
			auto tiempoInicial = chrono::high_resolution_clock::now();
			cout<<"\n Haz elejido Ordenamiento por Seleccion, ordenando Numeros........ ";
			ofstream seleccion("seleccion.txt", ios::app);
			
			if(archivoLectura.is_open()){
				while(getline(archivoLectura, linea)){
					
					istringstream iss(linea);
					string numeroStr;
					int numeroInt2;
					
					while (iss >> numeroInt2) {
			            numerosInt.push_back(numeroInt2);
					}
				}
				
				//Seleccion
				int tam = numerosInt.size();
				int i, j, aux, min;
				
				for(i = 0; i < tam; i++){
					min = i;
					for(j = i + 1; j < tam; j++){
						if(numerosInt[j] < numerosInt[min]){
							min = j;
						}
					}
					aux = numerosInt[i];
					numerosInt[i] = numerosInt[min];
					numerosInt[min] = aux;
				}
				
				//resultado
			    for (size_t i = 0; i < numerosInt.size(); i++) {
			    	int numero = numerosInt[i];
			    	seleccion << numero << ", ";
			        cout << numero << " ";
			    }
			    seleccion.close();
			    archivoLectura.close();
				auto tiempoFinal = chrono::high_resolution_clock::now();
				chrono::duration<double> tiempoCon = tiempoFinal - tiempoInicial;
				
				int horas = chrono::duration_cast<chrono::hours>(tiempoCon).count();
			    tiempoCon -= chrono::duration_cast<chrono::hours>(tiempoCon);
			    int minutos = chrono::duration_cast<chrono::minutes>(tiempoCon).count();
			    tiempoCon -= chrono::duration_cast<chrono::minutes>(tiempoCon);
			    int segundos = chrono::duration_cast<chrono::seconds>(tiempoCon).count();
				cout << "\n\nTiempo de ejecucion: " << horas << " horas, " << minutos << " minutos y " << segundos << " segundos." <<endl;
				
				cout << "\nDesea regresar al menu principal? (s/n): ";
				cin >> menu;
				if(menu == 's' || menu == 'S'){
					system("cls");
					main();	
				}
			}
		}
		
		//ordenamiento por metodo de insercion
		if(seleccionado == 3){
			auto tiempoInicial = chrono::high_resolution_clock::now();
			ofstream insercion("insercion.txt", ios::app);
				
			cout<<"\n Haz elejido Ordenamiento por Insercion, ordenando Numeros........ ";
			if (archivoLectura.is_open()) {
				// Leer contenido del txt
				while (getline(archivoLectura, linea)) {
				    istringstream iss(linea);
				    int numeroInt2;
				
				    // Identifica el espacio para separar
				    while (iss >> numeroInt2) {
				        numerosInt.push_back(numeroInt2);
				    }
				}
				
				// Metodo de ordenamiento por insercion
				int tam = numerosInt.size();
				
				for (int i = 1; i < tam; i++) {
				    int valorActual = numerosInt[i];
				    int j = i - 1;
				
				    while (j >= 0 && numerosInt[j] > valorActual) {
				        numerosInt[j + 1] = numerosInt[j];
				        j--;
				    }
				    numerosInt[j + 1] = valorActual;
				}
				
				// Imprime valores ordenados
				cout << "\nLos numeros enteros ordenados son: ";
				for (size_t i = 0; i < numerosInt.size(); i++) {
				    int numero = numerosInt[i];
				    insercion << numero << ", ";
				    cout << numero << " ";
				}
				insercion.close();
				
				auto tiempoFinal = chrono::high_resolution_clock::now();
				chrono::duration<double> tiempoCon = tiempoFinal - tiempoInicial;
				
				int horas = chrono::duration_cast<chrono::hours>(tiempoCon).count();
			    tiempoCon -= chrono::duration_cast<chrono::hours>(tiempoCon);
			    int minutos = chrono::duration_cast<chrono::minutes>(tiempoCon).count();
			    tiempoCon -= chrono::duration_cast<chrono::minutes>(tiempoCon);
			    int segundos = chrono::duration_cast<chrono::seconds>(tiempoCon).count();
				cout << "\n\nTiempo de ejecucion: " << horas << " horas, " << minutos << " minutos y " << segundos << " segundos." <<endl;
				
				cout << "\nDesea regresar al menu principal? (s/n): ";
				cin >> menu;
				if(menu == 's' || menu == 'S'){
					system("cls");
					main();	
				}
			}
		}
		
		//metodo de ordenamiento quicksort
		if(seleccionado == 4){
			auto tiempoInicial = chrono::high_resolution_clock::now();
			cout<<"\n Haz elejido Ordenamiento por Quicksort, ordenando Numeros........ \n";
	
			ofstream Quicksort("quicksort.txt", ios::app);
			
			if (archivoLectura.is_open()) {
				// Leer contenido del txt
				while (getline(archivoLectura, linea)) {
				    istringstream iss(linea);
				    int numeroInt2;
				
				    // Identifica el espacio para separar
				    while (iss >> numeroInt2) {
				        numerosInt.push_back(numeroInt2);
				    }
				}
			}
		
			// metodo
		    int tama = numerosInt.size();
		    quicksort(numerosInt, 0, tama - 1);
		
			//resultado9
			cout<<"El orden es: ";
		    for (int i = 0; i < tama; i++) {
		        cout << numerosInt[i] << " ";
		        Quicksort << numerosInt[i] << ", ";
		    }
		    Quicksort.close();
		    
			auto tiempoFinal = chrono::high_resolution_clock::now();
			chrono::duration<double> tiempoCon = tiempoFinal - tiempoInicial;
			
			int horas = chrono::duration_cast<chrono::hours>(tiempoCon).count();
		    tiempoCon -= chrono::duration_cast<chrono::hours>(tiempoCon);
		    int minutos = chrono::duration_cast<chrono::minutes>(tiempoCon).count();
		    tiempoCon -= chrono::duration_cast<chrono::minutes>(tiempoCon);
		    int segundos = chrono::duration_cast<chrono::seconds>(tiempoCon).count();
			cout << "\n\nTiempo de ejecucion: " << horas << " horas, " << minutos << " minutos y " << segundos << " segundos." <<endl;
			
			cout << "\nDesea regresar al menu principal? (s/n): ";
			cin >> menu;
			if(menu == 's' || menu == 'S'){
				system("cls");
				main();	
			}
		}
		archivoLectura.close();
	
	}	
}

//ordenamiento de bases de datos externas
void LeerUnTxtBurbuja(){
	auto tiempoInicial = chrono::high_resolution_clock::now();
	string ruta;
	vector<int> numerosInt; // declaro un vertor de tipo entero
	string linea;
	
	cout<<"\n Haz elejido Ordenamiento por Burbuja, ordenando Numeros........ ";
	//solicito la ruta del archivo
	cout<<"\nPor favor, ingrese la ruta del archivo a ordenar\n";
	cout<<"ejemplo: C:/Users/(nombre de su base).txt"<<endl;
	cin.ignore();
	getline(cin, ruta);
	
	//modo lectura del archivo
	ifstream archivoLectura(ruta);
	
	if(archivoLectura.is_open()){
		//leer contenido del txt y ordenarlo burbuja	    
		while (getline(archivoLectura, linea)) {
			
			istringstream iss(linea);
			string numeroStr;
			int numeroInt2;
			
			//identifica la separecion por espacios del txt
			while (iss >> numeroInt2) {
	            numerosInt.push_back(numeroInt2);
			}
		}
		
		//metodo de burbuja ordenamiento
		int tam = numerosInt.size();
		
	    for (int i = 0; i < tam - 1; ++i) {
	        for (int j = 0; j < tam - 1 - i; ++j) {
	            if (numerosInt[j] > numerosInt[j + 1]) {
	                swap(numerosInt[j], numerosInt[j + 1]);
	            }
	        }
	    }
	    //imprime valores ordenados
	    cout << "\nLos numeros enteros ordenados son: ";
	    for (size_t i = 0; i < numerosInt.size(); i++) {
	    	int numero = numerosInt[i];
	        cout << numero << " ";
	    }
		archivoLectura.close();
		auto tiempoFinal = chrono::high_resolution_clock::now();
		chrono::duration<double> tiempoCon = tiempoFinal - tiempoInicial;
		
		int horas = chrono::duration_cast<chrono::hours>(tiempoCon).count();
	    tiempoCon -= chrono::duration_cast<chrono::hours>(tiempoCon);
	    int minutos = chrono::duration_cast<chrono::minutes>(tiempoCon).count();
	    tiempoCon -= chrono::duration_cast<chrono::minutes>(tiempoCon);
	    int segundos = chrono::duration_cast<chrono::seconds>(tiempoCon).count();
		cout << "\n\nTiempo de ejecucion: " << horas << " horas, " << minutos << " minutos y " << segundos << " segundos." <<endl;
		
		cout << "\nDesea regresar al menu principal? (s/n): ";
		cin >> menu;
		if(menu == 's' || menu == 'S'){
			system("cls");
			main();	
		}
	}
}

void LeerTxtSeleccion(){
	auto tiempoInicial = chrono::high_resolution_clock::now();
	string ruta;
	vector<int> numerosInt; // declaro un vertor de tipo entero
	string linea;
	
	cout<<"\n Haz elejido Ordenamiento por Burbuja, ordenando Numeros........ ";
	//solicito la ruta del archivo
	cout<<"\nPor favor, ingrese la ruta del archivo a ordenar\n";
	cout<<"ejemplo: C:/Users/(nombre de su base).txt"<<endl;
	cin.ignore();
	getline(cin, ruta);
	
	//modo lectura del archivo
	ifstream archivoLectura(ruta);
	
	if(archivoLectura.is_open()){
		while(getline(archivoLectura, linea)){
			
			istringstream iss(linea);
			string numeroStr;
			int numeroInt2;
			
			while (iss >> numeroInt2) {
	            numerosInt.push_back(numeroInt2);
			}
		}
		
		//Seleccion
		int tam = numerosInt.size();
		int i, j, aux, min;
		
		for(i = 0; i < tam; i++){
			min = i;
			for(j = i + 1; j < tam; j++){
				if(numerosInt[j] < numerosInt[min]){
					min = j;
				}
			}
			aux = numerosInt[i];
			numerosInt[i] = numerosInt[min];
			numerosInt[min] = aux;
		}
		
		//resultado
	    for (size_t i = 0; i < numerosInt.size(); i++) {
	    	int numero = numerosInt[i];
	        cout << numero << " ";
	    }
	    archivoLectura.close();
		auto tiempoFinal = chrono::high_resolution_clock::now();
		chrono::duration<double> tiempoCon = tiempoFinal - tiempoInicial;
		
		int horas = chrono::duration_cast<chrono::hours>(tiempoCon).count();
	    tiempoCon -= chrono::duration_cast<chrono::hours>(tiempoCon);
	    int minutos = chrono::duration_cast<chrono::minutes>(tiempoCon).count();
	    tiempoCon -= chrono::duration_cast<chrono::minutes>(tiempoCon);
	    int segundos = chrono::duration_cast<chrono::seconds>(tiempoCon).count();
		cout << "\n\nTiempo de ejecucion: " << horas << " horas, " << minutos << " minutos y " << segundos << " segundos." <<endl;
		
		cout << "\nDesea regresar al menu principal? (s/n): ";
		cin >> menu;
		if(menu == 's' || menu == 'S'){
			system("cls");
			main();	
		}
	}
}

//metodo de insercion
void LeerUnTxtInsercion(){
	auto tiempoInicial = chrono::high_resolution_clock::now();
	string ruta;
	vector<int> numerosInt; // declaro un vertor de tipo entero
	string linea;
	
	cout<<"\n Haz elejido Ordenamiento por Insercion, ordenando Numeros........ \n";
	
	cout<<"Por favor, ingrese la ruta del archivo a ordenar\n";
	cout<<"ejemplo: C:/Users/(nombre de su base).txt"<<endl;
	cin.ignore();
	getline(cin, ruta);
	
	//modo lectura del archivo
	ifstream archivoLectura(ruta);
				
	if (archivoLectura.is_open()) {
		// Leer contenido del txt
		while (getline(archivoLectura, linea)) {
			istringstream iss(linea);
			int numeroInt2;
				
			// Identifica el espacio para separar
			while (iss >> numeroInt2) {
				numerosInt.push_back(numeroInt2);
			}
		}
				
		// Metodo de ordenamiento por inserción
		int tam = numerosInt.size();
				
		for (int i = 1; i < tam; i++) {
			int valorActual = numerosInt[i];
			int j = i - 1;
				
			while (j >= 0 && numerosInt[j] > valorActual) {
				numerosInt[j + 1] = numerosInt[j];
				j--;
			}
			numerosInt[j + 1] = valorActual;
		}
				
		// Imprime valores ordenados
		cout << "\nLos numeros enteros ordenados son: ";
		for (size_t i = 0; i < numerosInt.size(); i++) {
			int numero = numerosInt[i];
			cout << numero << " ";
		}
		archivoLectura.close();
		auto tiempoFinal = chrono::high_resolution_clock::now();
		chrono::duration<double> tiempoCon = tiempoFinal - tiempoInicial;
		
		int horas = chrono::duration_cast<chrono::hours>(tiempoCon).count();
	    tiempoCon -= chrono::duration_cast<chrono::hours>(tiempoCon);
	    int minutos = chrono::duration_cast<chrono::minutes>(tiempoCon).count();
	    tiempoCon -= chrono::duration_cast<chrono::minutes>(tiempoCon);
	    int segundos = chrono::duration_cast<chrono::seconds>(tiempoCon).count();
		cout << "\n\nTiempo de ejecucion: " << horas << " horas, " << minutos << " minutos y " << segundos << " segundos." <<endl;
		
		cout << "\nDesea regresar al menu principal? (s/n): ";
		cin >> menu;
		if(menu == 's' || menu == 'S'){
			system("cls");
			main();	
		}
	}
}

// las funciones de abajo son para Quicksort
int auxiliar(vector<int> &numerosInt, int LimIzquier, int LimDerecho) {
    int pivot = numerosInt[LimDerecho];
    int i = LimIzquier - 1;

    for (int j = LimIzquier; j <= LimDerecho - 1; j++) {
        if (numerosInt[j] < pivot) {
            i++;
            swap(numerosInt[i], numerosInt[j]);
        }
    }
    swap(numerosInt[i + 1], numerosInt[LimDerecho]);
    return i + 1;
}

void quicksort(vector<int> &numerosInt, int LimIzquier, int LimDerecho) {
    if (LimIzquier < LimDerecho) {
        int pivot = auxiliar(numerosInt, LimIzquier, LimDerecho);
        quicksort(numerosInt, LimIzquier, pivot - 1);
        quicksort(numerosInt, pivot + 1, LimDerecho);
    }
}

void LeerTxtQuicksort(){
	auto tiempoInicial = chrono::high_resolution_clock::now();
	string ruta;
	vector<int> numerosInt;

	cout<<"\n Haz elejido Ordenamiento por Quicksort, ordenando Numeros........ \n";	

	cout<<"Por favor, ingrese la ruta del archivo a ordenar\n";
	cout<<"ejemplo: C:/Users/(nombre de su base).txt"<<endl;
	cin.ignore();
	getline(cin, ruta);

	ifstream archivoLectura(ruta);

    int numero;
    while (archivoLectura >> numero) {
        numerosInt.push_back(numero);
    }
    archivoLectura.close();

    int tama = numerosInt.size();
    quicksort(numerosInt, 0, tama - 1);
	
	cout<<"\nEl orden es: ";
    for (int i = 0; i < tama; i++) {
        cout << numerosInt[i] << " ";
    }
	auto tiempoFinal = chrono::high_resolution_clock::now();
	chrono::duration<double> tiempoCon = tiempoFinal - tiempoInicial;
	
	int horas = chrono::duration_cast<chrono::hours>(tiempoCon).count();
    tiempoCon -= chrono::duration_cast<chrono::hours>(tiempoCon);
    int minutos = chrono::duration_cast<chrono::minutes>(tiempoCon).count();
    tiempoCon -= chrono::duration_cast<chrono::minutes>(tiempoCon);
    int segundos = chrono::duration_cast<chrono::seconds>(tiempoCon).count();
	cout << "\n\nTiempo de ejecucion: " << horas << " horas, " << minutos << " minutos y " << segundos << " segundos." <<endl;
	
	cout << "\nDesea regresar al menu principal? (s/n): ";
	cin >> menu;
	if(menu == 's' || menu == 'S'){
		system("cls");
		main();	
	}
}
