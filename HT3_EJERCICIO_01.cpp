#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct jugadores{
	string nombre;
	int edad;
	string nacio;
	float salario;
};
void mp();
void leer_archivo();
void grabar_archivo();
int main(){
	mp();
}

void mp(){
	
	int resp;
	
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Jugador "<<"\n";
		cout<<" 2 - Mostrar Jugadores "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			grabar_archivo();			
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

void grabar_archivo(){
	
	string nombre_juga;
	string nacio_juga;
	int edad_juga;
	float salario_juga = 2500,incremento=0;
	fflush(stdin);
	cout<<"Ingrese Nombre del Jugador: "<<endl;
	getline(cin,nombre_juga);
	fflush(stdin);
	cout<<"Ingrese Edad del Jugador: "<<endl;
	cin>>edad_juga;
	cout<<"Ingrese Nacionalidad del Jugador: "<<endl;
	cin>>nacio_juga;
	
	
	if(nacio_juga[0] != 'G'){
		if(edad_juga >= 15 ){
		salario_juga += 1400;
		incremento = salario_juga;
	}
	else if(edad_juga >= 21){
		salario_juga += 1500;
		incremento = salario_juga;
	}
	else if(edad_juga >= 25){
		salario_juga += 1200;
		incremento = salario_juga;
	}
	else  if(edad_juga > 30){
		salario_juga += 800;
		incremento = salario_juga;
	}
	}
	
	ofstream archivo;  
	archivo.open("HT3_EJERCICIO_01.txt",ios::app);
	
	
	archivo<<nombre_juga<<"\t"<<edad_juga<<"\t"<<nacio_juga<<"\t"<<salario_juga<<endl;
	archivo.close();
}
void leer_archivo(){
	ifstream archivo; 
	archivo.open("HT3_EJERCICIO_01.txt",ios::in);
	int lineas,i=0;
	string s,linea;
	float sumatoriasalarial=0.00;	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1); 
	}
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	jugadores recordset[lineas];
	
	archivo.open("HT3_EJERCICIO_01.txt",ios::in);
		if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}
	
	
	
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
      
        archivo>>recordset[i].nombre>>recordset[i].edad>>recordset[i].nacio>>recordset[i].salario;
    }
    archivo.close(); 
    for(int i = 0; i < lineas; i++){
    	cout<<recordset[i].nacio<<" "<<recordset[i].nombre<<" "<<recordset[i].edad<<" "<<recordset[i].salario<<endl;
    	sumatoriasalarial+=recordset[i].salario;
	}
	cout<<"Sumatorial total: "<<sumatoriasalarial<<endl;;
	system("PAUSE");
}
