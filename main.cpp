#include "iostream"
#include "string"
#include <cstdlib>
#include <unistd.h>

using namespace std;
//Variables globales
unsigned int respuesta = 0;

//Funciones
void preguntarObjetivo(); //Pregunta que quieres hacer

bool preguntarSiElObjetivoEsConTemporizador(); //Pregunta si hay temprozador

string preguntarTiempo(); //Pregunta el tiempo que desea poner al temporizador

int main()
{
    preguntarObjetivo();

    //en caso de que la respuesta de a un valor invalido

    while (::respuesta < 1 || ::respuesta > 3)
    {
        system("clear");

        cout << "Insert a valid value" << endl;
        cout << endl;

        sleep(1); //Espero 1 segundo

        preguntarObjetivo();
    }

    switch (::respuesta)
    {
    //Apagar y suspender
    case 1:
        if (preguntarSiElObjetivoEsConTemporizador() == true)
        {
            //Pregunta el tiempo del temporizador

            string comando = "sudo shutdown -H " + preguntarTiempo();

            cout << comando;

            system((comando.c_str())); //Transforma el comando par aque la terminal lo pueda entender
        }
        else
        {
            //Apagar

            system("sudo shutdown now");
        }

        break;

    case 2:
        system(" sudo systemctl suspend -i");
        break;
    //Reiniciar
    case 3:
        system("sudo reboot");

        break;
    }

    return 0;
}

void preguntarObjetivo()
{
    //Alamacena la respuesta y lo pasa a número
    string respuesta = "";

    cout << "Insert:" << endl;

    cout << "1 to shutdown," << endl;

    cout << "2 to suspend," << endl;

    cout << "3 to reboot" << endl;

    cout << ":";

    cin >> respuesta;

    ::respuesta = atoi(respuesta.c_str()); //Combierte el string

    cout << endl;
}

bool preguntarSiElObjetivoEsConTemporizador()
{

    bool salida = false;

    string respuesta = "";

    cout << "Do you want to add a timer[y/n]?:";

    cin >> respuesta;

    if (respuesta[0] == 'y' || respuesta[0] == 'Y')
    {
        salida = true;
    }

    return salida;
}

string preguntarTiempo()
{
    int devolucion = 0; //Almacena lo que se va a devolver

    string respuesta = ""; //Almacena la respuesta

    while (devolucion < 1)
    {
        cout << "How long do you want the timer? (in minutes)" << endl;

        cout << ":";

        cin >> respuesta;

        devolucion = atoi(respuesta.c_str()); //Combierte la respuesta en un int

        if (devolucion < 1)
        {
            cout << "Insert a valid value" << endl;
            cout << endl;

            //borra la pantalla

            sleep(1); //Espero 1 segundo

            system("clear"); //borra la pantalla
        }
    }

    return respuesta;
}
