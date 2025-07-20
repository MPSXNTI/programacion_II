#include <iostream>
#include <string>
#include <cstdlib>

// Para generar documentación de código con doxygen

// 1) Asegurarse que en el directorio de trabajo está el archivo Doxyfile. Revise que la línea 1740
//    tenga la siguiente configuración:
//    GENERATE_LATEX = NO

// 2) Para generar en forma automática comentarios compatibles con Doxygen,
//    debe escribir la secuencia /** y luego Shift+Enter.

// 3) Cuando tenga su código comentado, habra la Paleta de Comandos de VS Code (Control+Shift+P)
//    y busque el comando "Generate Doxygen Documentation"

// 4) La acción anterior creará un subdirectorio 'html'. En el explorador de archivos de su computador,
//    abra el archivo 'index.html' con su navegador preferido.

// Recuerde :
//   a) debe modificar la variable TARGET en el archivo 'Makefile' según los requerimmientos de la tarea.
//   b) utilizar el archivo Makefile para compilar su código ('make all') y comprobrar su funcionamiento ('make run').
//   c) antes de entregar su trabajo, debe ejecutar 'make clean' en el archivo 'Makefile'

/**
 * @brief Clase Base.
 * 
 */
class Componente {

    protected:
    float energiaConsumida;
    float cargaProcesamiento;

    public:
    /**
     * @brief Metodo para mostrar estado del componente.
     * 
     */
    virtual void mostrarEstado() const {

        std::cout << "Energia Consumida: " << energiaConsumida << " Watt, Carga Procesamiento: " << cargaProcesamiento << "%" << std::endl;

    }

};

/**
 * @brief Clase hija de Componente.
 * 
 */
class Procesamiento : public Componente {

    protected:
    float frecuencia;
    int cores;

    public:
    /**
     * @brief Sobreescribe el metodo mostrar estado del componente.
     * 
     */
    virtual void mostrarEstado() override {

        Componente::mostrarEstado();

        std::cout << "Frecuencia: " << frecuencia << " GHz, Cores: " << cores << std::endl;

    }

};

/**
 * @brief Clase hija de Componente.
 * 
 */
class Almacenamiento : public Componente {

    protected:
    float capacidadAlmacenamiento;
    float velocidadAcceso;
    std::string tipoInterfaz;

    public:
    /**
     * @brief Sobreescribe el metodo mostrar estado del componente.
     * 
     */
    virtual void mostrarEstado() override {

        Componente::mostrarEstado();

        std::cout << "Capacidad: " << capacidadAlmacenamiento << " GB, Velocidad: " << velocidadAcceso << " MB/s, Interfaz: " << tipoInterfaz << std::endl;

    }

};

/**
 * @brief Clase hija de Procesamiento.
 * 
 */
class CPU : public Procesamiento {

    private:
    int numeroProcesador;
    int cacheL3;

    public:
    /**
     * @brief Constructor de la clase CPU con parametros.
     * 
     * @param _energiaConsumida 
     * @param _cargaProcesamiento 
     * @param _frecuencia 
     * @param _cores 
     * @param _numeroProcesador 
     * @param _cacheL3 
     */
    CPU(float _energiaConsumida, float _cargaProcesamiento, float _frecuencia, float _cores, int _numeroProcesador, int _cacheL3) {
        energiaConsumida   = _energiaConsumida;
        cargaProcesamiento = _cargaProcesamiento;
        frecuencia         = _frecuencia;
        cores              = _cores;
        numeroProcesador   = _numeroProcesador;
        cacheL3            = _cacheL3;
    }

    /**
     * @brief Metodo para mostrar el estado creado en la clase Componente y compartido en la clase Procesamiento.
     * 
     */
    void estadoProcesamiento() const {

        Procesamiento::mostrarEstado();

    }

    /**
     * @brief Sobreescribe el metodo mostrar estado del componente.
     * 
     */
    void mostrarEstado() override {

        std::cout << "CPU - Numero de Procesador: " << numeroProcesador << ", Cache L3: " << cacheL3 << " MB" << std::endl;

    }

};

/**
 * @brief Clase hija de Procesamiento.
 * 
 */
class GPU : public Procesamiento {

    private:
    float memoria;

    public:
    /**
     * @brief Constructor de la clase GPU con parametros.
     * 
     * @param _energiaConsumida 
     * @param _cargaProcesamiento 
     * @param _frecuencia 
     * @param _cores 
     * @param _memoria 
     */
    GPU(float _energiaConsumida, float _cargaProcesamiento, float _frecuencia, float _cores, float _memoria) {
        energiaConsumida   = _energiaConsumida;
        cargaProcesamiento = _cargaProcesamiento;
        frecuencia         = _frecuencia;
        cores              = _cores;
        memoria            = _memoria;
    }

    /**
     * @brief Metodo para mostrar el estado creado en la clase Componente y compartido en la clase Procesamiento.
     * 
     */
    void estadoProcesamiento() const {

        Procesamiento::mostrarEstado();

    }

    /**
     * @brief Sobreescribe el metodo mostrar estado del componente.
     * 
     */
    void mostrarEstado() override {

        std::cout << "GPU - Ancho de Banda: " << memoria << " GB/s" << std::endl;

    }

};

/**
 * @brief Clase hija de Almacenamiento.
 * 
 */
class HDD : public Almacenamiento {

    private:
    int rpm;
    int memoriaCache;

    public:
    /**
     * @brief Constructor de la clase HDD con parametros.
     * 
     * @param _energiaConsumida 
     * @param _cargaProcesamiento 
     * @param _capacidadAlmacenamiento 
     * @param _velocidadAcceso 
     * @param _tipoInterfaz 
     * @param _rpm 
     * @param _memoriaCache 
     */
    HDD(float _energiaConsumida, float _cargaProcesamiento, float _capacidadAlmacenamiento, float _velocidadAcceso, std::string _tipoInterfaz, int _rpm, int _memoriaCache) {
        energiaConsumida        = _energiaConsumida;
        cargaProcesamiento      = _cargaProcesamiento;
        capacidadAlmacenamiento = _capacidadAlmacenamiento;
        velocidadAcceso         = _velocidadAcceso;
        tipoInterfaz            = _tipoInterfaz;
        rpm                     = _rpm;
        memoriaCache            = _memoriaCache;
    }

    /**
     * @brief Metodo para mostrar el estado creado en la clase Componente y compartido en la clase Almacenamiento.
     * 
     */
    void estadoAlmacenamiento() const {

        Almacenamiento::mostrarEstado();

    }

    /**
     * @brief Sobreescribe el metodo mostrar estado del componente.
     * 
     */
    void mostrarEstado() override {

        std::cout << "Velocidad de Rotacion: " << rpm << " rpm, Cache: " << memoriaCache << " MB" << std::endl;

    }

};

/**
 * @brief Clase hija de Almacenamiento.
 * 
 */
class SSD : public Almacenamiento {

    private:
    std::string tipoMemoria;

    public:
    /**
     * @brief Constructor de la clase SSD con parametros.
     * 
     * @param _energiaConsumida 
     * @param _cargaProcesamiento 
     * @param _capacidadAlmacenamiento 
     * @param _velocidadAcceso 
     * @param _tipoInterfaz 
     * @param _tipoMemoria 
     */
    SSD(float _energiaConsumida, float _cargaProcesamiento, float _capacidadAlmacenamiento, float _velocidadAcceso, std::string _tipoInterfaz, std::string _tipoMemoria) {
        energiaConsumida        = _energiaConsumida;
        cargaProcesamiento      = _cargaProcesamiento;
        capacidadAlmacenamiento = _capacidadAlmacenamiento;
        velocidadAcceso         = _velocidadAcceso;
        tipoInterfaz            = _tipoInterfaz;
        tipoMemoria             = _tipoMemoria;
    }

    /**
     * @brief Metodo para mostrar el estado creado en la clase Componente y compartido en la clase Almacenamiento.
     * 
     */
    void estadoAlmacenamiento() const {

        Almacenamiento::mostrarEstado();

    }

    /**
     * @brief Sobreescribe el metodo mostrar estado del componente.
     * 
     */
    void mostrarEstado() override {

        std::cout << "Tipo de Memoria: " << tipoMemoria << std::endl;

    }

};

/**
 * @brief Clase hija de HDD y SSD.
 * 
 */
class SSHD : public HDD, public SSD {

    public:
    /**
     * @brief Constructor de la clase SSHD con parametros sin implementacion.
     * 
     * @param _energiaConsumida 
     * @param _cargaProcesamiento 
     * @param _capacidadAlmacenamiento 
     * @param _velocidadAcceso 
     * @param _tipoInterfaz 
     * @param _rpm 
     * @param _memoriaCache 
     * @param _tipoMemoria 
     */
    SSHD(float _energiaConsumida, float _cargaProcesamiento, float _capacidadAlmacenamiento, float _velocidadAcceso, std::string _tipoInterfaz, int _rpm, int _memoriaCache, std::string _tipoMemoria) : HDD(_energiaConsumida, _cargaProcesamiento, _capacidadAlmacenamiento, _velocidadAcceso, _tipoInterfaz, _rpm, _memoriaCache), SSD(_energiaConsumida, _cargaProcesamiento, _capacidadAlmacenamiento, _velocidadAcceso, _tipoInterfaz, _tipoMemoria){}

    /**
     * @brief Metodo que muestra el metodo estadoAlmacenamiento implementado en la clase SSD.
     * 
     */
    void estadoAlmacenamiento() const {

        SSD::estadoAlmacenamiento();

    }

    /**
     * @brief Sobreescribe el metodo mostrar estado del componente.
     * 
     */
    void mostrarEstado() override {

        HDD::mostrarEstado();
        SSD::mostrarEstado();

    }
};

/**
 * @brief Función principal.
 * 
 * Crea y muestra el estado de varios componentes de procesamiento y almacenamiento.
 * 
 * @return void
 */
int main() {
    CPU cpu(70, 40, 3.5, 8, 1, 16);
    GPU gpu(130, 60, 1.5, 2048, 448);
    HDD hdd(9, 30, 1000, 150, "SATA", 7200, 64);
    SSD ssd(2.5, 20, 500, 550, "NVMe", "TLC");
    SSHD sshd(9, 50, 2000, 200, "SATA", 7200, 64, "MLC");

    std::cout << "Estado del CPU: " << "\n";
    cpu.estadoProcesamiento();
    cpu.mostrarEstado();
    std::cout << "\nEstado de la GPU: " << "\n";
    gpu.estadoProcesamiento();
    gpu.mostrarEstado();
    std::cout << "\nEstado del HDD: " << "\n";
    hdd.estadoAlmacenamiento();
    hdd.mostrarEstado();
    std::cout << "\nEstado del SSD: " << "\n";
    ssd.estadoAlmacenamiento();
    ssd.mostrarEstado();
    std::cout << "\nEstado del SSHD: " << "\n";
    sshd.estadoAlmacenamiento();
    sshd.mostrarEstado();

    return 0;
}
