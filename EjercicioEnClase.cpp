#include<iostream>
#include<vector>
using namespace std;

vector<string> siTieneUnAsterisco(string expresionRegular , int cantidad)
{
    char caracterQueSeRepite,caracterQueNoSeRepite;
    vector<string> cadenasAsterisco;
    string cadenaIterada=" ";
    for(size_t i=0;i < expresionRegular.length();i++)
    {
        char caracter=expresionRegular[i];
        if(caracter=='*')
        {
            caracterQueSeRepite = expresionRegular[i-1];
        }
        if(i==expresionRegular.length()-1)
        {
            caracterQueNoSeRepite = expresionRegular[i];
        }
    }
    for(int i=0;i< cantidad + 1 ;i++)
    {
        for(int j=0;i<cantidad;i++)
        {

        }
        if(i==0)
        {
            if(caracterQueNoSeRepite)
            {
                cadenasAsterisco.push_back(cadenaIterada);
            }
            else
            {
                cadenaIterada+=caracterQueNoSeRepite;
                cadenasAsterisco.push_back(cadenaIterada);
            }
        }
        else
        {
            if(caracterQueNoSeRepite)
            {
                cadenaIterada+=caracterQueSeRepite;
                cadenaIterada+=caracterQueNoSeRepite;
                cadenasAsterisco.push_back(cadenaIterada);
            }
        }
        
    }

    return cadenasAsterisco;
}

int main()
{

    string expresionRegular;


    int cantidad;
    bool tieneUnO=false,tieneUnAsterisco=false;

    cout<<"Digite la expresion Regular:";cin>>expresionRegular;

    cout<<"Cantidad: ";cin>>cantidad;

    string cadena;
    char caracter;
    for(size_t i=0;i < expresionRegular.length();i++)
    {
        caracter=expresionRegular[i];
        if(caracter=='|')
        {
            tieneUnO=true;
        }
        if(caracter=='*')
        {
            tieneUnAsterisco=true;
        }

    }
    if(tieneUnO==false && tieneUnAsterisco== false)
    {
        cout<<"Expresion: "<<expresionRegular;
    }    
    vector<string> vectorAlfabeto=siTieneUnAsterisco(expresionRegular,cantidad);

    for(string caracteresI : vectorAlfabeto)
    {
        cout<<caracteresI<<endl;
    }
    return 0;
}