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
void verificandoAsteriscoEnlaCadena(string cadena)
{
    bool tieneAsterisco=false;
    int contadorAsterisco=0;
    for(char caracter:cadena)
    {
        if(caracter=='*')
        {
            tieneAsterisco=true;
            contadorAsterisco++;
        }   
    }
    //En caso que la cadena sea : ab*
    if(cadena[cadena.size()-1]=='*' && contadorAsterisco==1)
    {
        cadenasDividas.push_back(cadena);
    }
    else if(tieneAsterisco)
    {
        //En caso tenga asterisco en el medio por ejemplo a*b* o a*b
        DivideConquistaras(cadena);
    }
    else
    {
        //En caso se una expresion sin Asterisco
        cadenasDividas.push_back(cadena);
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
vector<string> separarO(string cadena)
{
    vector<string> elementos;
    string elemento;

    istringstream stream(cadena);

    while(getline(stream,elemento,'|'))
    {
        elementos.push_back(elemento);
    }

    return elementos;
}

//Regla 1:Si es un cadenaSimple
//Regla 2: Si termina en asterisco ab*
//Regla 3: Si tiene varios o tiene un asterisco al final
int main()
{
    string cadena;
    int cantidad;

    vector<string> alfabetoGenerado;
    
    cout<<"Cadena: ";cin>>cadena;
    cout<<"Cantidad: ";cin>>cantidad;
    
    //El primer for no hace mas que iterar nuestra logica craneada
    int contador=0;

    //Separar por categorias

    for(string cadena:separarO(cadena))
    {
        verificandoAsteriscoEnlaCadena(cadena);


        cout<<contador+1<<".Imprimiendo cadena divida:"<<endl;
        //Hacer un array bidimensional

        vector<vector<string>> subCadenasSeparadas;
        vector<string> vectorSubCadena;
        
        for(string& subCadena:cadenasDividas)
        {
            cout<<subCadena<<endl;
            if(subCadena.size()>2)
            {
                vectorSubCadena = divideSubCadena(subCadena);
                subCadenasSeparadas.push_back(vectorSubCadena);
            }
            else{
                
            }
        }
        cout<<"Imprimiendo subCadenas de una cadena ya dividida"<<endl;
        for(int i=0;i<subCadenasSeparadas.size();++i)
        {
            for(int j=0;j<subCadenasSeparadas[0].size();++j)
            {
                cout<<subCadenasSeparadas[i][j]<<endl;
            }
        }

        contador++;
    }

    
    return 0;
}