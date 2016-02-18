// Задаём номера портов для светодиодов
int GPin = 11; // Зелёный
int YPin = 12; // Жёлтый
int RPin = 13; // Красный
int switchPin = 7; // Порт кнопки
boolean lastButton = LOW; // Устанавливаем последнее значение кнопки - выключено
boolean currentButton = LOW; // Устанавливаем текущее значение кнопки - включено
boolean ledOn = false; // Состояние светофора: false - выключен (мигает жёлтый), true - включен
boolean yellowOn = LOW; // Мигающий жёлтый.
unsigned long loopTime; // Вспомогающая переменная для цикла
unsigned long currentTime; // Переменная хранящая текущее значение времени
 
void setup() {
  // Устанавливаем 3 порта как выход для светодиодов и один как вход для отслеживания кнопки
  pinMode(GPin, OUTPUT);
  pinMode(YPin, OUTPUT);
  pinMode(RPin, OUTPUT);
  pinMode(switchPin, INPUT);
  currentTime = millis();
  loopTime = currentTime;
}
 
// Функция для лучшего отрабатывания нажатия на кнопку - ждёт установившегося значения, а затем передаёт его в программу.
boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  if(last != current)
  {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}
 
void loop() {
  currentButton = debounce(lastButton);
  if(lastButton == LOW && currentButton == HIGH) // При нажатии на кнопку включаем\выключаем светофор
  {
    ledOn = !ledOn;
  }
  lastButton = currentButton;
  currentTime = millis();
 
  // Цикл действий при выключенном светофоре
  if(currentTime >= (loopTime + 500) && ledOn == false)
  {
    yellowOn = !yellowOn; // Инвертируем значение переменной.
    digitalWrite(GPin, LOW);
    digitalWrite(YPin, yellowOn);
    digitalWrite(RPin, LOW);
    loopTime = currentTime;
  }
 
  // Цикл действий при включенном светофоре
  if(ledOn == true) {
    // Горит зелёный
    if(currentTime >= loopTime && currentTime < (loopTime + 10000)) {       digitalWrite(GPin, HIGH);       digitalWrite(YPin, LOW);       digitalWrite(RPin, LOW);     }
// Зелёный начинает мигать     
 
if(currentTime >= (loopTime + 10000) && currentTime < (loopTime + 10500)) {
       digitalWrite(GPin, LOW);
}
if(currentTime >= (loopTime + 10500) && currentTime < (loopTime + 11000)) {
       digitalWrite(GPin, HIGH);
}
if(currentTime >= (loopTime + 11000) && currentTime < (loopTime + 11500)) {
      digitalWrite(GPin, LOW);
}
if(currentTime >= (loopTime + 11500) && currentTime < (loopTime + 12000)) {
      digitalWrite(GPin, HIGH);
}
if(currentTime >= (loopTime + 12000) && currentTime < (loopTime + 12500)) {
       digitalWrite(GPin, LOW);
}
if(currentTime >= (loopTime + 12500) && currentTime < (loopTime + 13000)) {
       digitalWrite(GPin, HIGH);
}
if(currentTime >= (loopTime + 13000) && currentTime < (loopTime + 13500)) {
       digitalWrite(GPin, LOW);
}
if(currentTime >= (loopTime + 13500) && currentTime < (loopTime + 1400)) {
       digitalWrite(GPin, HIGH);
}
if(currentTime >= (loopTime + 14000) && currentTime < (loopTime + 14300)) {
       digitalWrite(GPin, LOW);
}
// Загорается жёлтый
if(currentTime >= (loopTime + 14300) && currentTime < (loopTime + 17500)) {
       digitalWrite(YPin, HIGH);
}
// Загорается красный
if(currentTime >= (loopTime + 17500) && currentTime < (loopTime + 27500)) {
       digitalWrite(YPin, LOW);       digitalWrite(RPin, HIGH);
}
// Загорается красный с жёлтым
if(currentTime >= (loopTime + 27500) && currentTime < (loopTime + 30500)) {
       digitalWrite(YPin, HIGH);
}
// Загорается зелёный
if(currentTime >= (loopTime + 30500)) {
      digitalWrite(GPin, HIGH);
      digitalWrite(YPin, LOW);
      digitalWrite(RPin, LOW);
      loopTime = currentTime;
    }
  }
}
