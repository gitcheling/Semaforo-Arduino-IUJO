class Led{
    private:
        int pin;

    public:

    Led(int num){
        pin = num;
    }

    void configurar(){
        pinMode(pin, OUTPUT);
    }

    void encender(){
        digitalWrite(pin, 1);
    }

    void apagar(){
        digitalWrite(pin, 0);
    }

};

Led ledRojo1(2);
Led ledAmarillo1(3);
Led ledVerde1(4);
Led ledAzul1(5);

Led ledRojo2(6);
Led ledAmarillo2(7);
Led ledVerde2(8);
Led ledAzul2(9);

Led ledRojo3(10);
Led ledAmarillo3(11);
Led ledVerde3(12);
Led ledAzul3(13);

Led ledRojo4(A0);
Led ledAmarillo4(A1);
Led ledVerde4(A2);
Led ledAzul4(A3);



void setup(){
    ledRojo1.configurar();
    ledAmarillo1.configurar();
    ledVerde1.configurar();
    ledAzul1.configurar();

    ledRojo2.configurar();
    ledAmarillo2.configurar();
    ledVerde2.configurar();
    ledAzul2.configurar();

    ledRojo3.configurar();
    ledAmarillo3.configurar();
    ledVerde3.configurar();
    ledAzul3.configurar();

    ledRojo4.configurar();
    ledAmarillo4.configurar();
    ledVerde4.configurar();
    ledAzul4.configurar();
}

void loop(){
    ledVerde1.encender();
    ledRojo2.encender();
    ledRojo3.encender();
    ledRojo4.encender();
    delay(3000);

    ledVerde1.apagar();
    ledAmarillo1.encender();
    delay(3000);

    ledAmarillo1.apagar();
    ledRojo1.encender();
    ledAzul1.encender();
    delay(3000);

    ledAzul1.apagar();
    ledRojo2.apagar();
    ledVerde2.encender();
    delay(3000);

    ledVerde2.apagar();
    ledAmarillo2.encender();
    delay(3000);

    ledAmarillo2.apagar();
    ledRojo2.encender();
    ledAzul2.encender();
    delay(3000);

    ledAzul2.apagar();
    ledRojo3.apagar();
    ledVerde3.encender();
    delay(3000);

    ledVerde3.apagar();
    ledAmarillo3.encender();
    delay(3000);

    ledAmarillo3.apagar();
    ledRojo3.encender();
    ledAzul3.encender();
    delay(3000);

    ledAzul3.apagar();
    ledRojo4.apagar();
    ledVerde4.encender();
    delay(3000);

    ledVerde4.apagar();
    ledAmarillo4.encender();
    delay(3000);

    ledAmarillo4.apagar();
    ledRojo4.encender();
    ledAzul4.encender();
    delay(3000);

    ledAzul4.apagar();
    ledRojo1.apagar();
}