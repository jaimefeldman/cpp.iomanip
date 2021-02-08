#include <iostream>
#include <iomanip>
#include <string>
#include "ConsoleColors.h"
#include <bitset>
#include <locale>
#include <ctime>
#include "Persona.hpp"

using namespace std;

// Estructura para personalizar la salida de separador de miles.
// usa el header locale
struct custom_locale : numpunct<char> {
    char_type do_thousands_sep() const override { return '.'; } // Separador de miles
    char_type do_decimal_point() const override { return ','; } // Separador decimal
    string_type do_grouping() const override { return "\3"; }   // Dígitos entre cada separador de miles
};

struct no_separator : std::numpunct<char> {
protected:
    virtual string_type do_grouping() const
        { return "\000"; } // groups of 0 (disable)
};

int main(int argc, char **argv)
{
  Persona *persona = new Persona("jaime", "feldman", 45, MASCULINO);
  int x = 7;

  cout << endl << foreground_green << "Prueba de la Libreria iomanip para manipulación de la salida cout en C++" << no_color << endl << endl;

  cout << setw(15)  << left << "Fecha"
       << setw(15)  << left << "Nombre"
       << setw(15)  << left << "Apellido" 
       << setw(6)   << left << "Edad" 
       << setw(15)  << left << "Estatura"
       << setw(10)  << left << "Hex"
       << setw(10)  << left << "Octal"
       << setw(10)  << left << "Bin"
       << setw(10)  << left << "Sueldo"
       << endl; 

  cout << string(115, '-') << endl;

  custom_locale my_locale;
  cout.imbue(locale(cout.getloc(), &my_locale));

  cout << setw(15)  << left << "una fecha"
       << setw(15)  << left << "Jaime"
       << setw(15)  << left << "Feldman" 
       << setw(6)   << left << 45 
       << setw(15)  << left << 1.69
       << setw(10)  << left <<  hex << 1230
       << setw(10)  << left <<  oct << 1230
       << setw(10)  << left << bitset<8>(x) 
       << dec << fixed << setprecision(0) << "$" << setw(17) << left << 150000000000
       << endl << endl; 

  cout << "(setbase 16) numero 100: " << setbase(16) << 100 << endl;
  cout << "probando un numero con normalidad de locale: " << dec << 10550 << endl;
  cout << endl << "[Objeto Persona]" << endl << *persona << endl << endl;
  
  delete persona;
  persona = nullptr;
  return 0;
}
