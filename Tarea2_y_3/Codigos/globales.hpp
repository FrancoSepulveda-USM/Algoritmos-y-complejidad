// globales.hpp
#ifndef GLOBALES_HPP
#define GLOBALES_HPP

#include <map>
#include <vector>

extern std::map<char, int> alfabeto;                     // Declaración de la variable global, alfabeto ingles
extern std::vector<std::vector<int>> transponer;         // Declaración de la variable global, tabla de costos de transponer una letra por otra
extern std::vector<std::vector<int>> sustituir;          // Declaración de la variable global, tabla de costos de susitituir una letra por otra
extern std::vector<int> insertar;                        // Declaración de la variable global, tabla de costos de insertar una letra
extern std::vector<int> deletear;                        // Declaración de la variable global, tabla de costos de eliminar una letra

#endif // GLOBALES_HPP

