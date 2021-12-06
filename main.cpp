#include "iostream"
#include "string"
#include <cstdlib>
#include <unistd.h>

using namespace std;
//Variables globales
unsigned int respuesta = 0;
unsigned int numeroMaximoRespuestas = 5;

//Funciones
void preguntarObjetivo(); //Pregunta que quieres hacer

string preguntarTiempo(); //Pregunta el tiempo que desea poner al temporizador

void imprimirOpcion(string); //Imprime la oción correspondiente

int main()
{
    string comando = "";
    preguntarObjetivo();

    //en caso de que la respuesta de a un valor invalido

    while (::respuesta < 1 || ::respuesta > ::numeroMaximoRespuestas)
    {
        system("clear");

        cout << "Insert a valid value" << endl;
        cout << endl;

        sleep(1); //Espero 1 segundo

        preguntarObjetivo();
    }

    switch (::respuesta)
    {
    //Apagar
    case 1:
        system("sudo shutdown now");
        cout << endl;
        cout << endl;

        break;

    //Apagado temporizado
    case 2:

        comando = "sudo shutdown " + preguntarTiempo();

        system((comando.c_str())); //Transforma el comando par aque la terminal lo pueda entender

        cout << endl;
        cout << endl;
        break;

        //reiniciar

    case 3:

        system("sudo reboot");

        break;

    case 4:

        comando = "sudo shutdown -r " + preguntarTiempo();

        system((comando.c_str())); //Transforma el comando par aque la terminal lo pueda entender

        cout << endl;
        cout << endl;

        break;
    //suspender
    case 5:
        system(" sudo systemctl suspend -i");
        break;
    }

    return 0;
}

void preguntarObjetivo()
{

    //Alamacena la respuesta y lo pasa a número
    string respuesta = "";

    cout << "Insert:" << endl;

    imprimirOpcion("shutdown"); //1

    imprimirOpcion("timed shutdown"); //2

    imprimirOpcion("reboot"); //3

    imprimirOpcion("timed reboot"); //4

    imprimirOpcion("suspend"); //5

    cout << ":";

    cin >> respuesta;

    ::respuesta = atoi(respuesta.c_str()); //Combierte el string

    cout << endl;
}

//Pregunta y devuelve el tiempo que se ha de añadir el temporizador
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

void imprimirOpcion(string opcion)
{

    static int numero = 1;

    cout << numero << " to " + opcion << "," << endl;

    numero++;

    if (numero == ::numeroMaximoRespuestas + 1)
    {
        numero = 1;
    }
}
