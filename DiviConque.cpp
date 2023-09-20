#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> cadenasDividas;
string parte;
string cadenaSinAsterisco;
void DivideConquistaras(string cadena)
{
    istringstream stream(cadena);
    
    while(true)
    {
        if(getline(stream,parte,'*'))
        {
            
            cadenasDividas.push_back(parte+'*');
        }
        if(!getline(stream,parte,'*'))
        {
            int indice=0;
            for(string cadena:cadenasDividas)
            {   
                indice+=cadena.size();
            }
            
            for(int i=indice;i<cadena.size();i++)
            {
                cadenaSinAsterisco+=cadena[i];
            }

            cadenasDividas.push_back(cadenaSinAsterisco);
            
            break; 
        }
    }   
}
vector<string> divideSubCadena(string cadena)
{
    vector<string> vectorCadenas;
    string cadenitaSin;
    string cadenaCon;

    for(int i=0;i<cadena.size()-2;i++)
    {
        cadenitaSin+=cadena[i];
    }
    cadenaCon+=cadena[cadena.size()-2];
    cadenaCon+=cadena[cadena.size()-1];

    vectorCadenas.push_back(cadenitaSin);
    vectorCadenas.push_back(cadenaCon);
    
    return vectorCadenas;
}


int main()
{
    string cadena;
    int cantidad;

    bool tieneAsterisco=false;
    int contadorAsterisco=0;
    
    cout<<"Cadena: ";cin>>cadena;
    cout<<"Cantidad: ";cin>>cantidad;
    
    for(char caracter:cadena)
    {
        if(caracter=='*')
        {
            tieneAsterisco=true;
            contadorAsterisco++;
        }   
    }
    if(cadena[cadena.size()-1]=='*' && contadorAsterisco==1)
    {
        cadenasDividas.push_back(cadena);
    }
    else if(tieneAsterisco)
    {
        DivideConquistaras(cadena);
    }
    else
    {
        cadenasDividas.push_back(cadena);
    }

    cout<<"Imprimiendo cadena divida:"<<endl;
    //Hacer un array bidimensional
    vector<string> vectorSubCadena;
    for(string& subCadena:cadenasDividas)
    {
        cout<<subCadena<<endl;
        if(subCadena.size()>2)
        {
            vectorSubCadena=divideSubCadena(subCadena);
        }
        else{

        }
    }
    cout<<"Imprimiendo subCadena de una cadena dividida"<<endl;
    for(string& cadena:vectorSubCadena)
    {
        cout<<cadena<<endl;
    }
    return 0;
}