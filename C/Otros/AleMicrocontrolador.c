//declarar variables
unsigned int adc;
float v;

void main() {
     //ADC
     ADC_Init(); //inicializa el modulo de ADC
     TRISC=0;  //salida
     PORTC=0;  //el primer valor es 0

     //PWM   (pin 16 (2) y 17 (1))
     PWM1_Init(5000);  //inicia el modulo de PWM con una frecuencia de 50Hz --> definida por usuario
                       //Frecuencia= 1/periodo --> 60Hz es la máxima frecuencia ala cual el ojo humano detecta un cambio
     PWM1_Start();      //inicializa el modulo PWM
    // PWM1_Set_Duty(0);  //establece el duty ratio (0=0%, 127=50%, 255=100%)

     while(1){
              adc=ADC_Read(0); //comienza la lectura con # canal
              v=adc*255.0/1023.0; //conversión de la lectura ADC a voltaje.
                                  //el valor de 1023 sale de que el ADC trabaja a 10 bits (2^10=1024 (0-1023))
              PWM1_Set_Duty(v);
   }
}