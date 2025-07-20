#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

/**
 * @file tarea05_doxygen.cc
 * @brief Implementación de clases para manejar información de personas.
 * 
 * Este archivo contiene las definiciones de las clases `NombreApellidos`, `Direccion`, `Persona` y `DB`.
 * Se utiliza para gestionar datos personales y realizar operaciones sobre ellos.
 */

/**
 * @class DBaddException
 * @brief Clase de excepción para manejo de errores en la base de datos.
 */
class DBaddException : public std::exception {
    private:
    std::string msg;
	
    public:
    /**
     * @brief Constructor de la excepción.
     * @param m Mensaje de error.
     */
    DBaddException(std::string m){
        msg = m;
    }
    /**
     * @brief Método que devuelve el mensaje de error.
     * @return Mensaje de error.
     */
    const char* what() const noexcept override {
		return(msg.c_str());
	}
};

/**
 * @class NombreApellidos
 * @brief Clase que representa el nombre y apellidos de una persona.
 */
class NombreApellidos {
    private:
    std::string nombre;
    std::string apellido1;
    std::string apellido2;

    public:
    /**
     * @brief Constructor de la clase.
     * @param _nombre Nombre de la persona.
     * @param _apellido1 Primer apellido.
     * @param _apellido2 Segundo apellido.
     */
    NombreApellidos(std::string _nombre, std::string _apellido1, std::string _apellido2){
        nombre    = _nombre;
        apellido1 = _apellido1;
        apellido2 = _apellido2;
    }

    /**
     * @brief Método que devuelve una representación en cadena del nombre completo.
     * @return Cadena con el nombre completo.
     */
    std::string toString(){
        return(nombre + " " + apellido1 + " " + apellido2);
    }

    /**
     * @brief Obtiene el nombre de la persona.
     * @return Nombre de la persona.
     */
    std::string getNombre() {
        return nombre;
    }

    /**
     * @brief Obtiene el primer apellido de la persona.
     * @return Primer apellido de la persona.
     */
    std::string getApellido1() {
        return apellido1;
    }

    /**
     * @brief Obtiene el segundo apellido de la persona.
     * @return Segundo apellido de la persona.
     */
    std::string getApellido2() {
        return apellido2;
    }
};

/**
 * @class Direccion
 * @brief Clase que representa la dirección de una persona.
 */
class Direccion {
    private:
    std::string calle;
    int         nro;
    std::string ciudad;

    public:
    /**
     * @brief Constructor de la clase.
     * @param _calle Calle de la dirección.
     * @param _nro Número de la dirección.
     * @param _ciudad Ciudad de la dirección.
     */
    Direccion(std::string _calle, int _nro, std::string _ciudad){
        calle  = _calle;
        nro    = _nro;
        ciudad = _ciudad;
    }

    /**
     * @brief Método que devuelve una representación en cadena de la dirección.
     * @return Cadena con la dirección.
     */
    std::string toString(){
        return(calle + " " + std::to_string(nro) + " " + ciudad);
    }

    /**
     * @brief Obtiene la calle de la dirección.
     * @return Calle de la dirección.
     */
    std::string getCalle() {
        return calle;
    }

    /**
     * @brief Obtiene el número de la dirección.
     * @return Número de la dirección.
     */
    int getNro() {
        return nro;
    }

    /**
     * @brief Obtiene la ciudad de la dirección.
     * @return Ciudad de la dirección.
     */
    std::string getCiudad() {
        return ciudad;
    }
};

/**
 * @class Persona
 * @brief Clase que representa a una persona.
 */
class Persona {
    private:
    NombreApellidos nombreCompleto;
    int             edad;
    std::string     paisOrigen;
    Direccion       direccion;

    public:
    /**
     * @brief Constructor por defecto de la clase.
     */
    Persona(): nombreCompleto(" ", " ", " "), direccion(" ", 0, " ") {
        paisOrigen = " ";
        edad       = 0;
    }

    /**
     * @brief Constructor de la clase.
     * @param _nombreCompleto Nombre completo de la persona.
     * @param _paisOrigen País de origen.
     * @param _edad Edad de la persona.
     * @param _direccion Dirección de la persona.
     */
    Persona(NombreApellidos _nombreCompleto, 
            std::string     _paisOrigen,  
            int             _edad,
            Direccion       _direccion): nombreCompleto(_nombreCompleto),
                                         direccion(_direccion) {
        paisOrigen = _paisOrigen;
        edad       = _edad;
    }

    /**
     * @brief Método que devuelve una representación en cadena de la persona.
     * @return Cadena con la información de la persona.
     */
    std::string toString() {
        return(nombreCompleto.toString() + "," + paisOrigen +  "," + std::to_string(edad) + "," + direccion.toString());
    }

    /**
     * @brief Obtiene el nombre de la persona.
     * @return Nombre de la persona.
     */
    std::string getNombre() {
        return nombreCompleto.getNombre();
    }

    /**
     * @brief Obtiene el primer apellido de la persona.
     * @return Primer apellido de la persona.
     */
    std::string getApellido1() {
        return nombreCompleto.getApellido1();
    }

    /**
     * @brief Obtiene el segundo apellido de la persona.
     * @return Segundo apellido de la persona.
     */
    std::string getApellido2() {
        return nombreCompleto.getApellido2();
    }

    /**
     * @brief Obtiene la edad de la persona.
     * @return Edad de la persona.
     */
    int getEdad() {
        return edad;
    }

    /**
     * @brief Obtiene el país de origen de la persona.
     * @return País de origen de la persona.
     */
    std::string getPaisOrigen() {
        return paisOrigen;
    }

    /**
     * @brief Obtiene la calle de la dirección de la persona.
     * @return Calle de la dirección.
     */
    std::string getCalle() {
        return direccion.getCalle();
    }

    /**
     * @brief Obtiene el número de la dirección de la persona.
     * @return Número de la dirección.
     */
    int getNro() {
        return direccion.getNro();
    }

    /**
     * @brief Obtiene la ciudad de la dirección de la persona.
     * @return Ciudad de la dirección.
     */
    std::string getCiudad() {
        return direccion.getCiudad();
    }
};

/**
 * @class DB
 * @brief Clase que representa una base de datos de personas.
 */
class DB {
    private:
    // No modificar
    Persona* personas;  // Puntero a un arreglo dinámico de Persona
    int size;          // Tamaño de la base de datos
    int last;

    public:
    // Constructor que recibe el tamaño
    // No modificar
    /**
     * @brief Constructor que recibe el tamaño de la base de datos.
     * @param n Tamaño de la base de datos.
     */
    DB(int n)  {
        size = n;
        personas = new Persona[size];  // Asignar memoria para el arreglo
        last = 0;
    }

    // Destructor para liberar memoria
    // No modificar
    /**
     * @brief Destructor para liberar memoria.
     */
    ~DB() {
        delete[] personas;  
    }

    // Método para agregar una persona en una posición específica
    /**
     * @brief Método para agregar una persona a la base de datos.
     * @param persona Persona a agregar.
     * @throw DBaddException Si se intenta agregar más personas de las permitidas.
     */
    void add(Persona& persona) {
        if (last >= size) {
            throw DBaddException("Índice fuera de rango.");
        }
        personas[last] = persona;
        last++;
    }

    // Método para mostrar la información de todas las personas
    /**
     * @brief Método para mostrar los registros de todas las personas.
     */
    void mostrarRegistros() {
        for (int i = 0; i < last; i++) {
            std::cout << "Registro " << i << ": " << personas[i].toString() << "\n";
        }
    }

    /**
     * @brief Selecciona y muestra personas según su país de origen.
     * @param pais País de origen a filtrar.
     */
    void seleccionarPaisOrigen(const std::string& pais) {
        std::cout << "Personas de origen: " << pais << "\n";
        for (int i = 0; i < last; i++) {
            if (personas[i].getPaisOrigen() == pais) {
                std::cout << personas[i].toString() << "\n";
            }
        }
    }

    /**
     * @brief Selecciona y muestra personas según su ciudad de residencia.
     * @param ciudad Ciudad de residencia a filtrar.
     */
    void seleccionarCiudadResidencia(const std::string& ciudad) {
        std::cout << "Personas en la ciudad: " << ciudad << "\n";
        for (int i = 0; i < last; i++) {
            if (personas[i].getCiudad() == ciudad) {
                std::cout << personas[i].toString() << "\n";
            }
        }
    }

    /**
     * @brief Selecciona y muestra personas según su apellido.
     * @param apellido Apellido a filtrar.
     */
    void seleccionarApellido(const std::string& apellido) {
        std::cout << "Personas con apellido: " << apellido << "\n";
        for (int i = 0; i < last; i++) {
            if (personas[i].getApellido1() == apellido) {
                std::cout << personas[i].toString() << "\n";
            }
        }
    }

    /**
     * @brief Selecciona y muestra personas según su nombre.
     * @param nombre Nombre a filtrar.
     */
    void seleccionarNombre(const std::string& nombre) {
        std::cout << "Personas con nombre: " << nombre << "\n";
        for (int i = 0; i < last; i++) {
            if (personas[i].getNombre() == nombre) {
                std::cout << personas[i].toString() << "\n";
            }
        }
    }
};

/********************************************
 * Declaración de funcion cargarDatos()     *
 * Necesario para la compilación del código *
 * No modificar                             *
 ********************************************/
/**
 * @brief Función para cargar datos en la base de datos.
 * @param baseDatos Referencia a la base de datos a cargar.
 */
void cargarDatos(DB& baseDatos);

/**
 * @brief Función de pruebas para demostrar el uso de las clases.
 */
void pruebas(){
    int sizeDB = 130;
    DB baseDatos(sizeDB);

    // Carga la base de datos con 130 registros aleatorios
    cargarDatos(baseDatos);
    
    // Se crear el registro 131.
    Persona p130(NombreApellidos("Carla","Perez","Reyes"),
                 "Perú",28,
                 Direccion("El Progreso",75,"Arica")); 
    
    // Se agrega el registro creado.
    // El método debe generar una excepción y debe ser capturada.
    // La excepción se debe llamar DBaddException
    // modifique para que capture la excepción
    try {
        // Se agrega el registro creado.
        baseDatos.add(p130); // Ahora se captura la excepción
    } catch (const DBaddException& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    
    baseDatos.mostrarRegistros();
    std::cout << "***** Seleccionar por País de Origen *****\n";
    baseDatos.seleccionarPaisOrigen("Perú");
    std::cout << "***** Seleccionar por Ciudad de Residencia *****\n";
    baseDatos.seleccionarCiudadResidencia("Rancagua");
    std::cout << "***** Seleccionar por apellido *****\n";
    baseDatos.seleccionarApellido("Garcia");
    std::cout << "***** Seleccionar por nombre *****\n";
    baseDatos.seleccionarNombre("Carla");
}

/**
 * @brief Función principal del programa.
 * @param argc Número de argumentos.
 * @param argv Arreglo de argumentos.
 * @return Código de salida del programa.
 */
int main(int argc, char* argv[]){
    pruebas();
    return(EXIT_SUCCESS);
}

/*********************************
 * Funciones de apoyo a la tarea *
 * No modificar                  *
 *********************************/
void cargarDatos(DB& baseDatos){
    Persona p0(NombreApellidos("Juan","Perez","Gonzalez"),"Chile",24,Direccion("Manso de Velasco",67,"Santiago")); baseDatos.add(p0);
    Persona p1(NombreApellidos("Maria","Gonzalez","Lopez"),"Argentina",30,Direccion("Huérfanos",34,"Valparaíso")); baseDatos.add(p1);
    Persona p2(NombreApellidos("Pedro","Ramirez","Morales"),"Bolivia",45,Direccion("Pedro Montt",15,"Concepción")); baseDatos.add(p2);
    Persona p3(NombreApellidos("Ana","Diaz","Silva"),"Perú",29,Direccion("San Pablo",88,"La Serena")); baseDatos.add(p3);
    Persona p4(NombreApellidos("Luis","Martinez","Rojas"),"Colombia",35,Direccion("Amunategui",22,"Antofagasta")); baseDatos.add(p4);
    Persona p5(NombreApellidos("Laura","Fernandez","Castillo"),"México",40,Direccion("Lira",10,"Temuco")); baseDatos.add(p5);
    Persona p6(NombreApellidos("Javier","Garcia","Alvarez"),"Uruguay",50,Direccion("San Diego",99,"Rancagua")); baseDatos.add(p6);
    Persona p7(NombreApellidos("Claudia","Morales","Ortiz"),"Ecuador",22,Direccion("Matta",43,"Punta Arenas")); baseDatos.add(p7);
    Persona p8(NombreApellidos("Diego","Rojas","Navarro"),"Paraguay",31,Direccion("Santa Rosa",56,"Iquique")); baseDatos.add(p8);
    Persona p9(NombreApellidos("Carla","Perez","Reyes"),"Chile",28,Direccion("La Habana",75,"Arica")); baseDatos.add(p9);
    Persona p10(NombreApellidos("Juan","Perez","Garcia"),"Argentina",24,Direccion("San Vicente",20,"Santiago")); baseDatos.add(p10);
    Persona p11(NombreApellidos("Maria","Ramirez","Martinez"),"Bolivia",34,Direccion("Independencia",5,"Valparaíso")); baseDatos.add(p11);
    Persona p12(NombreApellidos("Pedro","Lopez","Rojas"),"Perú",27,Direccion("Bellavista",80,"Concepción")); baseDatos.add(p12);
    Persona p13(NombreApellidos("Ana","Gonzalez","Diaz"),"Colombia",31,Direccion("Nueva de Santiago",90,"La Serena")); baseDatos.add(p13);
    Persona p14(NombreApellidos("Luis","Martinez","Alvarez"),"México",22,Direccion("San Pablo",60,"Antofagasta")); baseDatos.add(p14);
    Persona p15(NombreApellidos("Laura","Fernandez","Garcia"),"Uruguay",29,Direccion("Vicuña Mackenna",25,"Temuco")); baseDatos.add(p15);
    Persona p16(NombreApellidos("Javier","Garcia","Ramirez"),"Ecuador",38,Direccion("Los Libertadores",10,"Rancagua")); baseDatos.add(p16);
    Persona p17(NombreApellidos("Claudia","Navarro","Morales"),"Paraguay",26,Direccion("Manuel Montt",42,"Punta Arenas")); baseDatos.add(p17);
    Persona p18(NombreApellidos("Diego","Rojas","Silva"),"Chile",40,Direccion("La Florida",55,"Iquique")); baseDatos.add(p18);
    Persona p19(NombreApellidos("Carla","Perez","Reyes"),"Argentina",30,Direccion("Carmen",72,"Arica")); baseDatos.add(p19);
    Persona p20(NombreApellidos("Juan","Perez","Gonzalez"),"Bolivia",45,Direccion("La Alameda",67,"Santiago")); baseDatos.add(p20);
    Persona p21(NombreApellidos("Maria","Gonzalez","Lopez"),"Perú",30,Direccion("San Francisco",34,"Valparaíso")); baseDatos.add(p21);
    Persona p22(NombreApellidos("Pedro","Ramirez","Morales"),"Colombia",45,Direccion("O'Higgins",15,"Concepción")); baseDatos.add(p22);
    Persona p23(NombreApellidos("Ana","Diaz","Silva"),"México",29,Direccion("Salvador",88,"La Serena")); baseDatos.add(p23);
    Persona p24(NombreApellidos("Luis","Martinez","Rojas"),"Uruguay",35,Direccion("Las Heras",22,"Antofagasta")); baseDatos.add(p24);
    Persona p25(NombreApellidos("Laura","Fernandez","Castillo"),"Ecuador",40,Direccion("San Ignacio",10,"Temuco")); baseDatos.add(p25);
    Persona p26(NombreApellidos("Javier","Garcia","Alvarez"),"Paraguay",50,Direccion("San Luis",99,"Rancagua")); baseDatos.add(p26);
    Persona p27(NombreApellidos("Claudia","Morales","Ortiz"),"Chile",22,Direccion("San José",43,"Punta Arenas")); baseDatos.add(p27);
    Persona p28(NombreApellidos("Diego","Rojas","Navarro"),"Argentina",31,Direccion("Las Torres",56,"Iquique")); baseDatos.add(p28);
    Persona p29(NombreApellidos("Carla","Perez","Reyes"),"Bolivia",28,Direccion("La Serena",75,"Arica")); baseDatos.add(p29);
    Persona p30(NombreApellidos("Juan","Perez","Gonzalez"),"Perú",24,Direccion("Pajaritos",67,"Santiago")); baseDatos.add(p30);
    Persona p31(NombreApellidos("Maria","Gonzalez","Lopez"),"Colombia",30,Direccion("San Pedro",34,"Valparaíso")); baseDatos.add(p31);
    Persona p32(NombreApellidos("Pedro","Ramirez","Morales"),"México",45,Direccion("La Paz",15,"Concepción")); baseDatos.add(p32);
    Persona p33(NombreApellidos("Ana","Diaz","Silva"),"Uruguay",29,Direccion("Antonia",88,"La Serena")); baseDatos.add(p33);
    Persona p34(NombreApellidos("Luis","Martinez","Rojas"),"Ecuador",35,Direccion("San Lorenzo",22,"Antofagasta")); baseDatos.add(p34);
    Persona p35(NombreApellidos("Laura","Fernandez","Castillo"),"Paraguay",40,Direccion("21 de Mayo",10,"Temuco")); baseDatos.add(p35);
    Persona p36(NombreApellidos("Javier","Garcia","Alvarez"),"Chile",50,Direccion("Rio de Janeiro",99,"Rancagua")); baseDatos.add(p36);
    Persona p37(NombreApellidos("Claudia","Morales","Ortiz"),"Argentina",22,Direccion("El Bosque",43,"Punta Arenas")); baseDatos.add(p37);
    Persona p38(NombreApellidos("Diego","Rojas","Navarro"),"Bolivia",31,Direccion("Los Olmos",56,"Iquique")); baseDatos.add(p38);
    Persona p39(NombreApellidos("Carla","Perez","Reyes"),"Perú",28,Direccion("La Floresta",75,"Arica")); baseDatos.add(p39);
    Persona p40(NombreApellidos("Juan","Perez","Gonzalez"),"Colombia",45,Direccion("San Diego",20,"Santiago")); baseDatos.add(p40);
    Persona p41(NombreApellidos("Maria","Gonzalez","Lopez"),"México",30,Direccion("El Mañío",34,"Valparaíso")); baseDatos.add(p41);
    Persona p42(NombreApellidos("Pedro","Ramirez","Morales"),"Uruguay",45,Direccion("Los Andes",15,"Concepción")); baseDatos.add(p42);
    Persona p43(NombreApellidos("Ana","Diaz","Silva"),"Ecuador",29,Direccion("La Victoria",88,"La Serena")); baseDatos.add(p43);
    Persona p44(NombreApellidos("Luis","Martinez","Rojas"),"Paraguay",35,Direccion("El Arrayán",22,"Antofagasta")); baseDatos.add(p44);
    Persona p45(NombreApellidos("Laura","Fernandez","Castillo"),"Chile",40,Direccion("La Estrella",10,"Temuco")); baseDatos.add(p45);
    Persona p46(NombreApellidos("Javier","Garcia","Alvarez"),"Argentina",50,Direccion("San Felipe",99,"Rancagua")); baseDatos.add(p46);
    Persona p47(NombreApellidos("Claudia","Morales","Ortiz"),"Bolivia",22,Direccion("Los Castaños",43,"Punta Arenas")); baseDatos.add(p47);
    Persona p48(NombreApellidos("Diego","Rojas","Navarro"),"Perú",31,Direccion("La Cruz",56,"Iquique")); baseDatos.add(p48);
    Persona p49(NombreApellidos("Carla","Perez","Reyes"),"Colombia",28,Direccion("El Progreso",75,"Arica")); baseDatos.add(p49);
    Persona p50(NombreApellidos("Juan","Perez","Gonzalez"),"México",24,Direccion("La Pintana",67,"Santiago")); baseDatos.add(p50);
    Persona p51(NombreApellidos("Maria","Gonzalez","Lopez"),"Uruguay",30,Direccion("San Rafael",34,"Valparaíso")); baseDatos.add(p51);
    Persona p52(NombreApellidos("Pedro","Ramirez","Morales"),"Ecuador",45,Direccion("La Isla",15,"Concepción")); baseDatos.add(p52);
    Persona p53(NombreApellidos("Ana","Diaz","Silva"),"Paraguay",29,Direccion("San Vicente",88,"La Serena")); baseDatos.add(p53);
    Persona p54(NombreApellidos("Luis","Martinez","Rojas"),"Chile",35,Direccion("El Tamarugo",22,"Antofagasta")); baseDatos.add(p54);
    Persona p55(NombreApellidos("Laura","Fernandez","Castillo"),"Argentina",40,Direccion("La Cantala",10,"Temuco")); baseDatos.add(p55);
    Persona p56(NombreApellidos("Javier","Garcia","Alvarez"),"Bolivia",50,Direccion("El Cobre",99,"Rancagua")); baseDatos.add(p56);
    Persona p57(NombreApellidos("Claudia","Morales","Ortiz"),"Perú",22,Direccion("La Soledad",43,"Punta Arenas")); baseDatos.add(p57);
    Persona p58(NombreApellidos("Diego","Rojas","Navarro"),"Colombia",31,Direccion("La Vega",56,"Iquique")); baseDatos.add(p58);
    Persona p59(NombreApellidos("Carla","Perez","Reyes"),"México",28,Direccion("El Mirador",75,"Arica")); baseDatos.add(p59);
    Persona p60(NombreApellidos("Juan","Perez","Gonzalez"),"Uruguay",45,Direccion("El Sol",20,"Santiago")); baseDatos.add(p60);
    Persona p61(NombreApellidos("Maria","Gonzalez","Lopez"),"Ecuador",30,Direccion("Los Vientos",34,"Valparaíso")); baseDatos.add(p61);
    Persona p62(NombreApellidos("Pedro","Ramirez","Morales"),"Paraguay",45,Direccion("El Trébol",15,"Concepción")); baseDatos.add(p62);
    Persona p63(NombreApellidos("Ana","Diaz","Silva"),"Chile",29,Direccion("La Cañada",88,"La Serena")); baseDatos.add(p63);
    Persona p64(NombreApellidos("Luis","Martinez","Rojas"),"Argentina",35,Direccion("La Nieve",22,"Antofagasta")); baseDatos.add(p64);
    Persona p65(NombreApellidos("Laura","Fernandez","Castillo"),"Bolivia",40,Direccion("La Luz",10,"Temuco")); baseDatos.add(p65);
    Persona p66(NombreApellidos("Javier","Garcia","Alvarez"),"Perú",50,Direccion("Los Queñes",99,"Rancagua")); baseDatos.add(p66);
    Persona p67(NombreApellidos("Claudia","Morales","Ortiz"),"Colombia",22,Direccion("El Sendero",43,"Punta Arenas")); baseDatos.add(p67);
    Persona p68(NombreApellidos("Diego","Rojas","Navarro"),"México",31,Direccion("La Esperanza",56,"Iquique")); baseDatos.add(p68);
    Persona p69(NombreApellidos("Carla","Perez","Reyes"),"Uruguay",28,Direccion("El Bosque",75,"Arica")); baseDatos.add(p69);
    Persona p70(NombreApellidos("Juan","Perez","Gonzalez"),"Ecuador",24,Direccion("Los Pajaritos",67,"Santiago")); baseDatos.add(p70);
    Persona p71(NombreApellidos("Maria","Gonzalez","Lopez"),"Paraguay",30,Direccion("San Pedro",34,"Valparaíso")); baseDatos.add(p71);
    Persona p72(NombreApellidos("Pedro","Ramirez","Morales"),"Chile",45,Direccion("La Paz",15,"Concepción")); baseDatos.add(p72);
    Persona p73(NombreApellidos("Ana","Diaz","Silva"),"Argentina",29,Direccion("Antonia",88,"La Serena")); baseDatos.add(p73);
    Persona p74(NombreApellidos("Luis","Martinez","Rojas"),"Bolivia",35,Direccion("San Lorenzo",22,"Antofagasta")); baseDatos.add(p74);
    Persona p75(NombreApellidos("Laura","Fernandez","Castillo"),"Perú",40,Direccion("21 de Mayo",10,"Temuco")); baseDatos.add(p75);
    Persona p76(NombreApellidos("Javier","Garcia","Alvarez"),"Colombia",50,Direccion("Rio de Janeiro",99,"Rancagua")); baseDatos.add(p76);
    Persona p77(NombreApellidos("Claudia","Morales","Ortiz"),"México",22,Direccion("El Bosque",43,"Punta Arenas")); baseDatos.add(p77);
    Persona p78(NombreApellidos("Diego","Rojas","Navarro"),"Uruguay",31,Direccion("Los Olmos",56,"Iquique")); baseDatos.add(p78);
    Persona p79(NombreApellidos("Carla","Perez","Reyes"),"Ecuador",28,Direccion("La Floresta",75,"Arica")); baseDatos.add(p79);
    Persona p80(NombreApellidos("Juan","Perez","Gonzalez"),"Paraguay",45,Direccion("San Diego",20,"Santiago")); baseDatos.add(p80);
    Persona p81(NombreApellidos("Maria","Gonzalez","Lopez"),"Chile",30,Direccion("El Mañío",34,"Valparaíso")); baseDatos.add(p81);
    Persona p82(NombreApellidos("Pedro","Ramirez","Morales"),"Argentina",45,Direccion("Los Andes",15,"Concepción")); baseDatos.add(p82);
    Persona p83(NombreApellidos("Ana","Diaz","Silva"),"Bolivia",29,Direccion("La Victoria",88,"La Serena")); baseDatos.add(p83);
    Persona p84(NombreApellidos("Luis","Martinez","Rojas"),"Perú",35,Direccion("El Arrayán",22,"Antofagasta")); baseDatos.add(p84);
    Persona p85(NombreApellidos("Laura","Fernandez","Castillo"),"Colombia",40,Direccion("La Estrella",10,"Temuco")); baseDatos.add(p85);
    Persona p86(NombreApellidos("Javier","Garcia","Alvarez"),"México",50,Direccion("San Felipe",99,"Rancagua")); baseDatos.add(p86);
    Persona p87(NombreApellidos("Claudia","Morales","Ortiz"),"Uruguay",22,Direccion("Los Castaños",43,"Punta Arenas")); baseDatos.add(p87);
    Persona p88(NombreApellidos("Diego","Rojas","Navarro"),"Ecuador",31,Direccion("La Cruz",56,"Iquique")); baseDatos.add(p88);
    Persona p89(NombreApellidos("Carla","Perez","Reyes"),"Paraguay",28,Direccion("El Progreso",75,"Arica")); baseDatos.add(p89);
    Persona p90(NombreApellidos("Juan","Perez","Gonzalez"),"Chile",24,Direccion("La Pintana",67,"Santiago")); baseDatos.add(p90);
    Persona p91(NombreApellidos("Maria","Gonzalez","Lopez"),"Argentina",30,Direccion("San Rafael",34,"Valparaíso")); baseDatos.add(p91);
    Persona p92(NombreApellidos("Pedro","Ramirez","Morales"),"Bolivia",45,Direccion("La Isla",15,"Concepción")); baseDatos.add(p92);
    Persona p93(NombreApellidos("Ana","Diaz","Silva"),"Perú",29,Direccion("San Vicente",88,"La Serena")); baseDatos.add(p93);
    Persona p94(NombreApellidos("Luis","Martinez","Rojas"),"Colombia",35,Direccion("El Tamarugo",22,"Antofagasta")); baseDatos.add(p94);
    Persona p95(NombreApellidos("Laura","Fernandez","Castillo"),"México",40,Direccion("La Cantala",10,"Temuco")); baseDatos.add(p95);
    Persona p96(NombreApellidos("Javier","Garcia","Alvarez"),"Uruguay",50,Direccion("El Cobre",99,"Rancagua")); baseDatos.add(p96);
    Persona p97(NombreApellidos("Claudia","Morales","Ortiz"),"Ecuador",22,Direccion("La Soledad",43,"Punta Arenas")); baseDatos.add(p97);
    Persona p98(NombreApellidos("Diego","Rojas","Navarro"),"Paraguay",31,Direccion("La Vega",56,"Iquique")); baseDatos.add(p98);
    Persona p99(NombreApellidos("Carla","Perez","Reyes"),"Chile",28,Direccion("El Mirador",75,"Arica")); baseDatos.add(p99);
    Persona p100(NombreApellidos("Juan","Perez","Gonzalez"),"Argentina",45,Direccion("El Sol",20,"Santiago")); baseDatos.add(p100);
    Persona p101(NombreApellidos("Maria","Gonzalez","Lopez"),"Bolivia",30,Direccion("Los Vientos",34,"Valparaíso")); baseDatos.add(p101);
    Persona p102(NombreApellidos("Pedro","Ramirez","Morales"),"Perú",45,Direccion("El Trébol",15,"Concepción")); baseDatos.add(p102);
    Persona p103(NombreApellidos("Ana","Diaz","Silva"),"Colombia",29,Direccion("La Cañada",88,"La Serena")); baseDatos.add(p103);
    Persona p104(NombreApellidos("Luis","Martinez","Rojas"),"México",35,Direccion("La Nieve",22,"Antofagasta")); baseDatos.add(p104);
    Persona p105(NombreApellidos("Laura","Fernandez","Castillo"),"Uruguay",40,Direccion("La Luz",10,"Temuco")); baseDatos.add(p105);
    Persona p106(NombreApellidos("Javier","Garcia","Alvarez"),"Ecuador",50,Direccion("Los Queñes",99,"Rancagua")); baseDatos.add(p106);
    Persona p107(NombreApellidos("Claudia","Morales","Ortiz"),"Paraguay",22,Direccion("El Sendero",43,"Punta Arenas")); baseDatos.add(p107);
    Persona p108(NombreApellidos("Diego","Rojas","Navarro"),"Chile",31,Direccion("La Esperanza",56,"Iquique")); baseDatos.add(p108);
    Persona p109(NombreApellidos("Carla","Perez","Reyes"),"Argentina",28,Direccion("El Bosque",75,"Arica")); baseDatos.add(p109);
    Persona p110(NombreApellidos("Juan","Perez","Gonzalez"),"Bolivia",45,Direccion("Los Pajaritos",67,"Santiago")); baseDatos.add(p110);
    Persona p111(NombreApellidos("Maria","Gonzalez","Lopez"),"Perú",30,Direccion("San Pedro",34,"Valparaíso")); baseDatos.add(p111);
    Persona p112(NombreApellidos("Pedro","Ramirez","Morales"),"Colombia",45,Direccion("La Paz",15,"Concepción")); baseDatos.add(p112);
    Persona p113(NombreApellidos("Ana","Diaz","Silva"),"México",29,Direccion("Antonia",88,"La Serena")); baseDatos.add(p113);
    Persona p114(NombreApellidos("Luis","Martinez","Rojas"),"Uruguay",35,Direccion("San Lorenzo",22,"Antofagasta")); baseDatos.add(p114);
    Persona p115(NombreApellidos("Laura","Fernandez","Castillo"),"Ecuador",40,Direccion("21 de Mayo",10,"Temuco")); baseDatos.add(p115);
    Persona p116(NombreApellidos("Javier","Garcia","Alvarez"),"Paraguay",50,Direccion("Rio de Janeiro",99,"Rancagua")); baseDatos.add(p116);
    Persona p117(NombreApellidos("Claudia","Morales","Ortiz"),"Chile",22,Direccion("El Bosque",43,"Punta Arenas")); baseDatos.add(p117);
    Persona p118(NombreApellidos("Diego","Rojas","Navarro"),"Argentina",31,Direccion("Los Olmos",56,"Iquique")); baseDatos.add(p118);
    Persona p119(NombreApellidos("Carla","Perez","Reyes"),"Bolivia",28,Direccion("La Floresta",75,"Arica")); baseDatos.add(p119);
    Persona p120(NombreApellidos("Juan","Perez","Gonzalez"),"Perú",24,Direccion("San Diego",20,"Santiago")); baseDatos.add(p120);
    Persona p121(NombreApellidos("Maria","Gonzalez","Lopez"),"Colombia",30,Direccion("El Mañío",34,"Valparaíso")); baseDatos.add(p121);
    Persona p122(NombreApellidos("Pedro","Ramirez","Morales"),"México",45,Direccion("Los Andes",15,"Concepción")); baseDatos.add(p122);
    Persona p123(NombreApellidos("Ana","Diaz","Silva"),"Uruguay",29,Direccion("La Victoria",88,"La Serena")); baseDatos.add(p123);
    Persona p124(NombreApellidos("Luis","Martinez","Rojas"),"Ecuador",35,Direccion("El Arrayán",22,"Antofagasta")); baseDatos.add(p124);
    Persona p125(NombreApellidos("Laura","Fernandez","Castillo"),"Paraguay",40,Direccion("La Estrella",10,"Temuco")); baseDatos.add(p125);
    Persona p126(NombreApellidos("Javier","Garcia","Alvarez"),"Chile",50,Direccion("San Felipe",99,"Rancagua")); baseDatos.add(p126);
    Persona p127(NombreApellidos("Claudia","Morales","Ortiz"),"Argentina",22,Direccion("Los Castaños",43,"Punta Arenas")); baseDatos.add(p127);
    Persona p128(NombreApellidos("Diego","Rojas","Navarro"),"Bolivia",31,Direccion("La Cruz",56,"Iquique")); baseDatos.add(p128);
    Persona p129(NombreApellidos("Carla","Perez","Reyes"),"Perú",28,Direccion("El Progreso",75,"Arica")); baseDatos.add(p129);
}
