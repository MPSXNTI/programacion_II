#include <iostream>
#include <string>
#include <cstdlib>

/**
 * @brief Clase Base.
 * 
 */
class Fecha{
    private:
    int dia;
    int mes;
    int anio;

    public:
    /**
     * @brief Constructor de Fecha con parametros.
     * 
     * @param _dia 
     * @param _mes 
     * @param _anio 
     */
    Fecha(int _dia, int _mes, int _anio) {
        dia  = _dia;
        mes  = _mes;
        anio = _anio;
    }

    /**
     * @brief Metodo usado para ajustar el mes y el año cuando se exceden.
     * 
     * @param dias 
     */
    void agregarDias(int dias) {
        dia += dias;
        while (dia > diasEnMes(mes, anio)) {
            dia -= diasEnMes(mes, anio);
            mes++;
            if (mes > 12) {
                mes = 1;
                anio++;
            }
        }
    }

    /**
     * @brief Metodo usado para ajustar el mes y el año cuando los dias son negativos.
     * 
     * @param dias 
     */
    void restarDias(int dias) {
        dia -= dias;
        while (dia <= 0) {
            mes--;
            if (mes < 1) {
                mes = 12;
                anio--;
            }
            dia += diasEnMes(mes, anio);
        }
    }

    /**
     * @brief Calcula la diferencia de años entre el objeto actual y otro objeto Fecha.
     * 
     * @param otra 
     * @return int 
     */
    int diferenciaAnios(const Fecha& otra) const {
        if (this->anio > otra.anio) {
            return this->anio - otra.anio;
        } else {
            return otra.anio - this->anio;
        }
    }

    /**
     * @brief Calcula la diferencia de meses entre el objeto actual y otro objeto Fecha.
     * 
     * @param otra 
     * @return int 
     */
    int diferenciaMeses(const Fecha& otra) const {
        if (this->mes > otra.mes) {
            return this->mes - otra.mes;
        } else {
            return otra.mes - this->mes;
        }
    }

    /**
     * @brief Calcula la diferencia de dias entre el objeto actual y otro objeto Fecha.
     * 
     * @param otra 
     * @return int 
     */
    int diferenciaDias(const Fecha& otra) const {
        if (this->dia > otra.dia) {
            return this->dia - otra.dia;
        } else {
            return otra.dia - this->dia;
        }
    }

    /**
     * @brief Compara si dos objetos fecha son iguales.
     * 
     * @param otra 
     * @return true 
     * @return false 
     */
    bool operator==(const Fecha& otra) const {
        return (dia == otra.dia && mes == otra.mes && anio == otra.anio);
    }

    /**
     * @brief Devuelve un nuevo objeto Fecha con años sumados al actual.
     * 
     * @param cantidad 
     * @return Fecha 
     */
    Fecha sumarAnios(int cantidad) const {
        return Fecha(dia, mes, anio + cantidad);
    }

    /**
     * @brief Devuelve un nuevo objeto Fecha con años restados al actual.
     * 
     * @param cantidad 
     * @return Fecha 
     */
    Fecha restarAnios(int cantidad) const {
        return Fecha(dia, mes, anio - cantidad);
    }

    /**
     * @brief Metodo para accdeder al atributo privado dia.
     * 
     * @return int 
     */
    int getDia()  const  { return dia; }
    /**
     * @brief Metodo para accdeder al atributo privado mes.
     * 
     * @return int 
     */
    int getMes()  const  { return mes; }
    /**
     * @brief Metodo para accdeder al atributo privado año.
     * 
     * @return int 
     */
    int getAnio() const  { return anio; }

    /**
     * @brief Devuelve el numero de dias de un mes especifico, considerando años bisiestos.
     * 
     * @param m 
     * @param a 
     * @return int 
     */
    int diasEnMes(int m, int a) const {
        if (m == 2) { // Febrero
            return (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)) ? 29 : 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        }
        return 31;
    }

    /**
     * @brief Devuelve una representacion en cadena del objeto Fecha en formato DD/MM/YYYY.
     * 
     * @return std::string 
     */
    std::string retornarFecha() const {
        std::string fecha;

        fecha = std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);

        return fecha;
    }
};

/**
 * @brief Clase Hija que hereda de Fecha.
 * 
 */
class FechaHora: public Fecha{
    private:
    int hora;
    int minuto;
    int segundo;

    public:
    /**
     * @brief Constructor de FechaHora con parametros.
     * 
     * @param _dia 
     * @param _mes 
     * @param _anio 
     * @param _hora 
     * @param _minuto 
     * @param _segundo 
     */
    FechaHora(int _dia, int _mes, int _anio,
              int _hora, int _minuto, int _segundo)
              : Fecha(_dia, _mes, _anio) {
        hora    = _hora;
        minuto  = _minuto;
        segundo = _segundo;
    }

    /**
     * @brief Sobreescriben el comporatmiento para sumar dias, devolviendo un nuevo objeto FechaHora.
     * 
     * @param dias 
     * @return FechaHora 
     */
    FechaHora sumarDias(int dias) const {
        FechaHora nuevaFecha = *this;
        nuevaFecha.Fecha::agregarDias(dias);
        return nuevaFecha;
    }

    /**
     * @brief Sobreescriben el comporatmiento para restar dias, devolviendo un nuevo objeto FechaHora.
     * 
     * @param dias 
     * @return FechaHora 
     */
    FechaHora restarDias(int dias) const {
        FechaHora resultado = *this;
        resultado.Fecha::restarDias(dias);
        return resultado;
    }

    /**
     * @brief Suma horas, ajustando dias segun sea necesario.
     * 
     * @param horas 
     * @return FechaHora 
     */
    FechaHora sumarHoras(int horas) const {
        FechaHora nuevaFechaHora = *this;
        nuevaFechaHora.hora += horas;

        while (nuevaFechaHora.hora >= 24) {
            nuevaFechaHora.hora -= 24;
            nuevaFechaHora.agregarDias(1);
        }

        return nuevaFechaHora;
    }

    /**
     * @brief resta horas, ajustando dias segun sea necesario.
     * 
     * @param horas 
     * @return FechaHora 
     */
    FechaHora restarHoras(int horas) const {
        FechaHora nuevaFechaHora = *this;

        int diasARestar = horas / 24;
        int horasRestantes = horas % 24;

        nuevaFechaHora.Fecha::restarDias(diasARestar);

        nuevaFechaHora.hora -= horasRestantes;

        while (nuevaFechaHora.hora < 0) {
            nuevaFechaHora.hora += 24;
            nuevaFechaHora.Fecha::restarDias(1);
        }

        return nuevaFechaHora;
    }

    /**
     * @brief Calcula la diferencia de horas entre el objeto actual y otro objeto FechaHora.
     * 
     * @param otra 
     * @return int 
     */
    int diferenciaHoras(const FechaHora& otra) const {
        if (this->hora > otra.hora) {
            return this->hora - otra.hora;
        } else {
            return otra.hora - this->hora;
        }
    }

    /**
     * @brief Calcula la diferencia de minutos entre el objeto actual y otro objeto FechaHora.
     * 
     * @param otra 
     * @return int 
     */
    int diferenciaMinutos(const FechaHora& otra) const {
        if (this->minuto > otra.minuto) {
            return this->minuto - otra.minuto;
        } else {
            return otra.minuto - this->minuto;
        }
    }

    /**
     * @brief Calcula la diferencia de minutos entre el objeto actual y otro objeto FechaHora.
     * 
     * @param otra 
     * @return int 
     */
    int diferenciaSegundos(const FechaHora& otra) const {
        if (this->segundo > otra.segundo) {
            return this->segundo - otra.segundo;
        } else {
            return otra.segundo - this->segundo;
        }
    }

    /**
     * @brief Compara si dos objetos FechaHora son iguales.
     * 
     * @param otra 
     * @return true 
     * @return false 
     */
    bool operator==(const FechaHora& otra) const {
        return Fecha::operator==(otra) && hora == otra.hora && minuto == otra.minuto && segundo == otra.segundo;
    }
    
    /**
     * @brief Devuelve un nuevo objeto con años sumados.
     * 
     * @param cantidad 
     * @return FechaHora 
     */
    FechaHora sumarAnios(int cantidad) const {
        Fecha nuevaFecha = Fecha::sumarAnios(cantidad);
        return FechaHora(nuevaFecha.getDia(), nuevaFecha.getMes(), nuevaFecha.getAnio(), hora, minuto, segundo);
    }

    /**
     * @brief Devuelve un nuevo objeto con años restados.
     * 
     * @param cantidad 
     * @return FechaHora 
     */
    FechaHora restarAnios(int cantidad) const {
        Fecha nuevaFecha = Fecha::restarAnios(cantidad);
        return FechaHora(nuevaFecha.getDia(), nuevaFecha.getMes(), nuevaFecha.getAnio(), hora, minuto, segundo);
    }

    /**
     * @brief Devuelve una representacion en cadena del tiempo en formato HH:MM:SS.
     * 
     * @return std::string 
     */
    std::string retornarTiempo() const {
        std::string tiempo;

        tiempo = std::to_string(hora) + ":" + std::to_string(minuto) + ":" + std::to_string(segundo);

        return tiempo;
    }
};

/**
 * @brief Muestra un mensaje y datos de un objeto Fecha.
 * 
 * @param msg 
 * @param f 
 */
void mostrar(const std::string& msg, const Fecha& f) {
    std::cout << msg << ": " << f.retornarFecha() << "\n";
}

/**
 * @brief Muestra un mensaje y datos de un objeto FechaHora.
 * 
 * @param msg 
 * @param t 
 */
void mostrar(const std::string& msg, const FechaHora& t) {
    std::cout << msg << ": " << t.retornarFecha() << " " << t.retornarTiempo() << "\n";
}

void pruebas(){
    // Ejemplo de definiciones
    Fecha f0 = Fecha(21,10, 2024);
    Fecha f1 = Fecha(21,10, 2024);
    Fecha f2 = Fecha(25,12, 2024);
    // Imprimir
    mostrar("f0", f0);
    mostrar("f1", f1);
    mostrar("f2", f2);

    std::cout << "\n";

    FechaHora fh0 = FechaHora(26,11,1986,18,45,00);
    FechaHora fh1 = FechaHora(17, 2,1996,23,50,50);
    FechaHora fh2 = FechaHora(17, 2,1996,23,50,50);
    // Imprimir
    mostrar("fh0", fh0);
    mostrar("fh1", fh1);
    mostrar("fh2", fh2);

    std::cout << "\n";

    // Sumar Dias
    FechaHora fh5 = fh2.sumarDias(4);
    mostrar("fh2 + 4 dias", fh5);
    // Restar Dias
    FechaHora fh6 = fh2.restarDias(4);
    mostrar("fh2 - 4 dias", fh6);

    std::cout << "\n";
    
    // Diferencia Años
    std::cout << "Diferencia de años entre fh0 y fh1: "
              << fh0.diferenciaAnios(fh1) << " años" << "\n";
    // Diferencia Meses
    std::cout << "Diferencia de meses entre fh0 y fh1: "
              << fh0.diferenciaMeses(fh1) << " meses" << "\n";
    // Diferencia Dias
    std::cout << "Diferencia de dia entre fh0 y fh1: "
              << fh0.diferenciaDias(fh1) << " dia" << "\n";
    
    std::cout << "\n";
    
    // Sumar Horas
    FechaHora fh3 = fh2.sumarHoras(48);
    mostrar("fh2 + 48 horas", fh3);
    // Restar Horas
    FechaHora fh7 = fh2.restarHoras(48);
    mostrar("fh2 - 48 horas", fh7);

    std::cout << "\n";

    // Diferencia Horas
    std::cout << "Diferencia de horas entre fh0 y fh1: "
              << fh0.diferenciaHoras(fh1) << " horas" << "\n";
    // Diferencia Minutos
    std::cout << "Diferencia de minutos entre fh0 y fh1: "
              << fh0.diferenciaMinutos(fh1) << " minutos" << "\n";
    // Diferencia Segundos
    std::cout << "Diferencia de segundos entre fh0 y fh1: "
              << fh0.diferenciaSegundos(fh1) << " segundos" << "\n";

    std::cout << "\n";
    
    // Sumar Anios
    FechaHora fh4 = fh2.sumarAnios(19);
    mostrar("fh2 + 19 años", fh4);
    // Restar Anios
    FechaHora fh8 = fh2.restarAnios(19);
    mostrar("fh2 - 19 años", fh8);

    std::cout << "\n";

    // Comprobar que f0 es igual a f1
    if (f0 == f1) {
        std::cout << "f0 es igual a f1" << "\n";
    } else {
        std::cout << "f0 no es igual a f1" << "\n";
    }
    // Comprobar que  fh0 es igual a fh1
    if (fh0 == fh1) {
        std::cout << "fh0 es igual a fh1" << "\n";
    } else {
        std::cout << "fh0 no es igual a fh1" << "\n";
    }
}

int main(int argc, char* argv[]){
    pruebas();
    return(EXIT_SUCCESS);
}