    /* Мигание LED
 * ------------
 *
 * Включает и выключает светодиод (LED) подсоединенный  
 * к выходу 13, с интервалом в 2 секунды
 *
 */

    int pinB = 12; //ж
    int pinA = 13;//крint pinA = 13;//кр
    int pinC = 11;//зел
    int state = 0;
    int k = 0;

    int l1 = 0;
    int l2 = 0;

    void setup() {
        Serial.begin(9600);
        pinMode(pinA, OUTPUT);
        pinMode(pinB, OUTPUT);// устанавливаем вывод 13 как выход
        pinMode(pinC, OUTPUT);
    }

    void stitchL1(){
      if(l1 ==0){
        l1 = millis();
      }
    }

    void loop() {
      Serial.println("sdfdsfd");
        if (state == 0) {
          stitchL1();
            digitalWrite(pinC, HIGH);   // включаем LED
            delay(2000);
            if (k == 0) {
                k = 1;
            } else {
                k = k * (-1);
            }
            state = state + k;
            digitalWrite(pinC, LOW);
            for( int i=0;i<4;i++){
               digitalWrite(pinC, HIGH);   // включаем LED
            delay(500);
            digitalWrite(pinC, LOW);
            delay(500);
            } 
        }
        if (state == 1) {
            digitalWrite(pinB, HIGH);   // включаем LED
            delay(1500);
            digitalWrite(pinB, LOW);
            digitalWrite(pinA, LOW);
            state = state + k;
        }
        if (state == 2) {
            digitalWrite(pinA, HIGH);   // включаем LED
            delay(2000);
            k = k * (-1);
            state = 1;
             delay(300);
        }
    }