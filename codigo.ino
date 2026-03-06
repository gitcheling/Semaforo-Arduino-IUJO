//------------------------------------------------------------------------------------------------------
// Clase
//------------------------------------------------------------------------------------------------------

class Led {
  private:
    int pin;
  
  public:
  
  /* Led(int num): El nombre del constructor y el parámetro que recibe.

	:: Los dos puntos indican que se va a empezar la lista de inicialización.

	pin(num): Significa "toma el valor de num y ponlo directamente en la propiedad pin".

	{}: El cuerpo del constructor está vacío porque ya hiciste todo el trabajo antes de entrar.

	Nota: Si se tuviera mas variables se vería así:

      Led(int p, int b) : pin(p), brillo(b) {
        // Aquí se podría poner un Serial.print("Led creado"); si se quisiera
      }
*/
    Led(int num) : pin(num) {}
    
    void configurar() { pinMode(pin, OUTPUT); }
    void encender()   { digitalWrite(pin, HIGH); }
    void apagar()     { digitalWrite(pin, LOW); }
};



//------------------------------------------------------------------------------------------------------
// Variables
//------------------------------------------------------------------------------------------------------

// Creamos un ARREGLO de objetos Led. 
// Es mucho más fácil de manejar que 16 variables sueltas.
Led leds[] = {
  Led(2), Led(3), Led(4), Led(5),    // Grupo 1: Rojo, Amarillo, Verde, Azul
  Led(6), Led(7), Led(8), Led(9),    // Grupo 2
  Led(10), Led(11), Led(12), Led(13),// Grupo 3
  Led(A0), Led(A1), Led(A2), Led(A3) // Grupo 4
};

// Índices base para cada grupo de 4 LEDs (numerados segun sus índices en el array)
const int GRUPO1 = 0;  // LEDs 0,1,2,3
const int GRUPO2 = 4;  // LEDs 4,5,6,7
const int GRUPO3 = 8;  // LEDs 8,9,10,11
const int GRUPO4 = 12; // LEDs 12,13,14,15

// Desplazamientos (offsets) dentro de cada grupo
const int ROJO     = 0;
const int AMARILLO = 1;
const int VERDE    = 2;
const int AZUL     = 3;

// Constantes para que el código sea legible
const int TOTAL_LEDS = 16;


//------------------------------------------------------------------------------------------------------
// Función para manejar el semáforo
//------------------------------------------------------------------------------------------------------
void secuenciaSemaforo(int base) {
  // 1. Verde encendido (y el resto del grupo apagado)
  leds[base + VERDE].encender();
  leds[base + ROJO].apagar();
  delay(3000);
  
  // 2. Cambiar Verde por Amarillo
  leds[base + VERDE].apagar();
  leds[base + AMARILLO].encender();
  delay(3000);
  
  // 3. Cambiar Amarillo por Rojo y Azul
  leds[base + AMARILLO].apagar();
  leds[base + ROJO].encender();
  leds[base + AZUL].encender();
  delay(3000);
  
  // 4. Apagar Azul (el rojo se queda prendido para el siguiente turno)
  leds[base + AZUL].apagar();
}



//------------------------------------------------------------------------------------------------------
// Configuración de leds
//------------------------------------------------------------------------------------------------------
void setup() {
  // Configuramos todos los leds en una sola línea
  for(int i = 0; i < TOTAL_LEDS; i++) {
    leds[i].configurar();
    
    // Empezar con todos los ROJOS encendidos 
    if (i % 4 == 0) leds[i].encender();
  }
}



//------------------------------------------------------------------------------------------------------
// Bucle
//------------------------------------------------------------------------------------------------------
void loop() {
  // El semáforo 1 avanza, el resto espera en rojo
  secuenciaSemaforo(GRUPO1);
  
  // El semáforo 2 avanza, el resto espera en rojo
  secuenciaSemaforo(GRUPO2);
  
  // El semáforo 3 avanza...
  secuenciaSemaforo(GRUPO3);
  
  // El semáforo 4 avanza...
  secuenciaSemaforo(GRUPO4);
}
