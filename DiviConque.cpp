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

//Regla 1:Si es un cadenaSimple Osea No tiene asteriscos

bool regla1(string cadena)
{
    //De momento cumple
    bool cumpleRegla=true;

    for(int i=0;i<cadena.size();i++)
    {
        if(cadena[i]=='*')
        {
            //Pero si no se encuentra
            cumpleRegla=false;
            break;
        }
    }

    return cumpleRegla;
}
//Regla 2: Si termina en asterisco ab*

bool regla2(string cadena)
{
    bool cumpleRegla=false;
    int contador=0;
    for(int i=0;i<cadena.size();i++)
    {
        if(cadena[i]=='*')
        {
            //Pero si no se encuentra
            contador++;
        }
    }

    if(contador==1 && cadena[cadena.size()-1]=='*'&&cadena.size()>2){
        cumpleRegla=true;
    }

    return cumpleRegla;
}
//Regla 3: para a*
bool regla3(string cadena)
{
    bool cumpleRegla=false;
    if(cadena.size() == 2 && cadena[cadena.size()-1]=='*')
    {
        cumpleRegla=true;
    }
    return cumpleRegla;
}
//Regla 4: para a*b
bool regla4(string cadena)
{
    bool cumpleRegla=false;
    if(cadena.size() == 3 && cadena[cadena.size()-2]=='*')
    {
        cumpleRegla=true;
    }
    return cumpleRegla;
}
//Regla 5: para a*b*
bool regla5(string cadena)
{
    bool cumpleRegla=false;
    if(cadena.size() == 4 && cadena[1]=='*' && cadena[cadena.size()-1]=='*')
    {
        cumpleRegla=true;
    }
    return cumpleRegla;
}


vector<string> funcionParaCadenaAsteriscoAlFinalRegla2(string cadena,int cantidad)
{
    vector<string> cadenasGeneradas;
    string parteSinasterisco;
    string generadorCaracter;
    for(int i=0;i<cadena.size()-2;i++)
    {
        parteSinasterisco+=cadena[i];
    }

    cadenasGeneradas.push_back(parteSinasterisco);

    for(int i=0;i<cantidad;i++)
    {
        generadorCaracter+=cadena[cadena.size()-2];
        cadenasGeneradas.push_back(parteSinasterisco+generadorCaracter);
    }

    return cadenasGeneradas;
}
vector<string> funcionRegla3(string cadena, int cantidad)
{
    vector<string> cadenasGeneradas;
    string generadorCaracter;

    cadenasGeneradas.push_back(" ");
    for(int i=0;i<cantidad;i++)
    {
        generadorCaracter+=cadena[0];
        cadenasGeneradas.push_back(generadorCaracter);
    }

    return cadenasGeneradas;
}

vector<string> funcionRegla4(string cadena,int cantidad)
{
    vector<string> cadenasGeneradas;
    string parteSinAsterisco; 
    string generadorCaracter;
    parteSinAsterisco+= cadena[cadena.size()-1];
    cadenasGeneradas.push_back(parteSinAsterisco);

    for(int i=0;i<cantidad;i++)
    {
        generadorCaracter+=cadena[0];
        cadenasGeneradas.push_back(generadorCaracter+parteSinAsterisco);
    }
}
vector<string> funcionRegla5(string cadena,int cantidad)
{
    vector<string> cadenasGeneradas;
    string caracter1;
    caracter1+=cadena[0];
    string caracter2;
    caracter2+=cadena[cadena.size()-1];
    string generadorCaracter1;
    string generadorCaracter2;

    cadenasGeneradas.push_back(" ");
    cadenasGeneradas.push_back(caracter1);
    cadenasGeneradas.push_back(caracter2);
    for(int i=0;i<cantidad;i++)
    {
        
        for(int j=0;i<cantidad;j++)
        {

        }
    }

    return cadenasGeneradas;
}



int main()
{
    string cadena;
    int cantidad;
    vector<vector<string>> alfabeto4;
    vector<string> alfabeto3;
    vector<vector<string>> alfabetoGenerado2;
    vector<string> alfabetoGenerado1;
    
    cout<<"Cadena: ";cin>>cadena;
    cout<<"Cantidad: ";cin>>cantidad;
    
    //El primer for no hace mas que iterar nuestra logica craneada
    int contador=0;

    //Separar por categorias

    for(string cadena:separarO(cadena))
    {
        if(regla1(cadena))
        {
            alfabetoGenerado1.push_back(cadena);
        }
        else if(regla2(cadena))
        {
            vector<string> cadenasIteradasParaRegla2 = funcionParaCadenaAsteriscoAlFinalRegla2(cadena,cantidad);
            alfabetoGenerado2.push_back(cadenasIteradasParaRegla2);
        }
        else if(regla3(cadena))
        {
            // verificandoAsteriscoEnlaCadena(cadena);
            // cout<<contador+1<<".Imprimiendo cadena divida:"<<endl;
            // //Hacer un array bidimensional

            // vector<vector<string>> subCadenasSeparadas;
            // vector<string> vectorSubCadena;
            
            // for(string& subCadena:cadenasDividas)
            // {
            //     cout<<subCadena<<endl;
            //     if(subCadena.size()>2)
            //     {
            //         vectorSubCadena = divideSubCadena(subCadena);
            //         subCadenasSeparadas.push_back(vectorSubCadena);
            //     }
            //     else{
                    
            //     }
            // }
            // cout<<"Imprimiendo subCadenas de una cadena ya dividida"<<endl;
            // for(int i=0;i<subCadenasSeparadas.size();++i)
            // {
            //     for(int j=0;j<subCadenasSeparadas[0].size();++j)
            //     {
            //         cout<<subCadenasSeparadas[i][j]<<endl;
            //     }
            // }
            // contador++;

            alfabeto3 = funcionRegla3(cadena,cantidad);

        }
        else if(regla4(cadena))
        {
            vector<string> cadenasIteradasParaRegla4 =funcionRegla4(cadena,cantidad);
            alfabeto4.push_back(cadenasIteradasParaRegla4);
        }
        else if(regla5(cadena))
        {

        }

    }

    

    cout<<"Imprimiendo alfabeto"<<endl;
    //Juntando
    vector<string> AlfabetoFinal=alfabetoGenerado1;
    if(alfabetoGenerado2.size()>0)
    {
        for(int i=0;i<alfabetoGenerado2.size();++i)
        {
            for(int j=0;j<alfabetoGenerado2[i].size();++j)
            {
                AlfabetoFinal.push_back(alfabetoGenerado2[i][j]);
            }
        }
    }
    for(int i=0;i<alfabeto3.size();i++)
    {
        AlfabetoFinal.push_back(alfabeto3[i]);
    }
    if(alfabeto4.size()>0)
    {
        for(int i=0;i<alfabeto4.size();++i)
        {
            for(int j=0;j<alfabeto4[i].size();++j)
            {
                AlfabetoFinal.push_back(alfabeto4[i][j]);
            }
        }
    }
    //Ordenando

    //Imprimiendo
    for(int i=0;i<AlfabetoFinal.size();i++)
    {
        cout<<AlfabetoFinal[i]<<endl;
    }

    return 0;
}