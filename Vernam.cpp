#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int binario(int numero);

class VernamCipher {
public:
    string GenerarClave(int tam) {
        string clave = "";
        char caracter;
        int num = 0;
        for (int i = 0; i < tam; i++) {
            num = rand() % (90 - 65 + 1) + 65;
            caracter = num;
            clave += caracter;
        }
        return clave;
    }

    void Encriptar(string cadena, string clave) {
        convertir(cadena);
        cout << "\nCLAVE EN BINARIO//DECIMAL\n \n";
        convertir(clave);
        XOR(cadena, clave);
    }

    void convertir(string cadena) {
        char c[cadena.size() + 1];
        strcpy(c, cadena.c_str());
        int numbin[cadena.size()];
        cout << "Letra \t|Binario \t |Decimal| \n";
        for (int i = 0; i < cadena.size(); i++) {
            int n = c[i];
            numbin[i] = binario(n);
            cout << cadena[i] << "\t|" << numbin[i] << " \t |" << n << "\t |" << "\n";
        }
    }

    void XOR(string cadena, string clave) {
        string final = "";
        cout << "\nENCRIPTACION EN BINARIO//DECIMAL\n\n";
        cout << "\nLetra \t|Binario \t |Decimal| \n";
        for (int i = 0; i < cadena.size(); i++) {
            int n = cadena[i] ^ clave[i];
            int numbin[cadena.size()];
            numbin[i] = binario(n);
            char x = n;
            final = final + x;
            cout << x << "\t|" << numbin[i] << " \t |" << n << "\t |" << "\n";
        }
        cout << "----------------" << endl;
        cout << "Resultado: " << final << endl;
        system("pause");
        system("cls");
        archivo(final, clave);
    }

    void archivo(string cadena, string clave) {
        ofstream archivo;
        archivo.open("Cifrado.txt");
        archivo << "La palabra cifrada es: " << cadena << endl;
        archivo << "La clave es: " << clave << endl;
        archivo.close();
    }
};

int binario(int numero) {
    int exp, digito;
    double binario;
    exp = 0;
    binario = 0;
    while (numero / 2 != 0) {
        digito = numero % 2;
        binario = binario + digito * pow(10.0, exp);
        exp++;
        numero = numero / 2;
    }
    binario = binario + numero * pow(10.0, exp);
    return binario;
}

int main() {
    //variables
    int resp = 0;
    int tambit = 500;
    char vacio = 0;

    VernamCipher cipher;

    do {
        //Menu de interfaz para el usuario
        cout << "\t----CIFRADO VERNAM----" << endl;
        cout << "Que desea realizar\n  1.Cifrar\n  2.Descifrar\n  3.Salir\n";
        cin >> resp;
        string cadena = "";
        string clave = "";
        char cad[tambit];
        char clav[tambit];
        int i = 0;
        int c = 0;
        //Entra a un switch que valide cada uno de los casos
        switch (resp) {
            case 1:
                cin.ignore();
                cout << "Escriba la palabra que desea cifrar:";
                cin.getline(cad, tambit);
                while (cad[i] != vacio) {
                    cadena += cad[i];
                    i++;
                }
                clave = cipher.GenerarClave(cadena.size());
                cout << "clave generada: " << clave << endl;
                cipher.Encriptar(cadena, clave);
                break;
            case 2:
                cin.ignore();
                cout << "Escriba la palabra que desea descifrar:";
                cin.getline(cad, tambit);
                while (cad[c] != vacio) {
                    cadena += cad[c];
                    c++;
                }
                cout << "Escriba la clave de encriptacion:";
                cin.getline(clav, tambit);
                while (clav[i] != vacio) {
                    clave += clav[i];
                    i++;
                    cout << i;
                }
                cipher.Encriptar(cadena, clave);
                break;
            case 3:
                return 1;
                break;
            default: {
                cout << "¿Que desea realizar?\n\n  1.Cifrar \n  2. Descifrar \n  3.Salir \n";
                cout << "Ingrese una opcion valida \n";
                break;
            }
        }
    } while (resp != 3);
    return 0;
}
