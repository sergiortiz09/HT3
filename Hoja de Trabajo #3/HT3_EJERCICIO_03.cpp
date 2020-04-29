
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct vehiculos{
	string placa;
	string marca;
	int anho;
	float precio;
};
void mp(); //definicion de la funcion 
void inventario();
void leer_archivo();
int main(){	
	mp();	
	//return 0;
}
void mp(){ // menu principal
	
	int resp;
	//string nombrearchivo;
	//cout<<"Indique nombre de archivo: ";
	//getline(cin,nombrearchivo);
	
	do{
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Vehiculo al Inventario "<<"\n";
		cout<<" 2 - Mostrar Catalogo de Vehiculos "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			inventario();			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}
void inventario(){
	string placa_v;
	string marca_v;
	int anho_v;
	float precio_v;
	ofstream archivo; //grabar archivo
	fflush(stdin);
	cout<<"Ingrese Placa: "<<endl;
	getline(cin,placa_v);
	fflush(stdin);
	cout<<"Ingrese Marca: "<<endl;
	getline(cin,marca_v);
	cout<<"Ingrese Ano: "<<endl;
	cin>>anho_v;	
	cout<<"Ingrese Precio: "<<endl;
	cin>>precio_v;
	
	archivo.open("HT3_EJERCICIO_03.txt",ios::app); //abrir archivo append
	archivo<<placa_v<<"\t"<<marca_v<<"\t"<<anho_v<<"\t"<<precio_v<<endl;
	archivo.close();	
}
void leer_archivo(){
	ifstream archivo; //leer archivo 
	archivo.open("HT3_EJERCICIO_03.txt",ios::in); // leer archivo
	int lineas,i=0;
	string s,linea;	
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	vehiculos recordset[lineas];
	
	archivo.open("HT3_EJERCICIO_03.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	/*Leer datos del archivo*/
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        archivo>>recordset[i].placa>>recordset[i].marca>>recordset[i].anho>>recordset[i].precio;
    }
    archivo.close(); 
    for(int i = 0; i <lineas; i++){
    	cout<<recordset[i].placa<<" "<<recordset[i].marca<<" "<<recordset[i].anho<<" "<<recordset[i].precio<<endl;
    //	sumatoriasalarial+=recordset[i].salario;
	}
	system("Pause");
	

}
