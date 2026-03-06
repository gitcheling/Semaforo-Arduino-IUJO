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
