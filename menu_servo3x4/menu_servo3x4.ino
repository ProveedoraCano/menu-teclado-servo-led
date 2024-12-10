#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Definir el LCD (dirección 0x27, 16 columnas, 2 filas)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definir las filas y columnas del teclado 3x4
const byte filas = 4;
const byte columnas = 3;

// Pines conectados al teclado (ajustados a tu mapeo)
byte pinesFilas[] = {13, 12, 11, 10};
byte pinesColumnas[] = {9, 8, 7};

// Mapa de las teclas
char teclas[4][3] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// Crear objeto del teclado
Keypad teclado1 = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas);

// Definir pines de los LEDs
const int LED_ROJO_PIN = 4;
const int LED_AMARILLO_PIN = 3;
const int LED_VERDE_PIN = 2;

// Definir el pin para el Servo
const int SERVO_PIN = 5;
Servo servo;

void setup() {
  // Inicializar el monitor serial
  Serial.begin(9600);

  // Inicializar el LCD
  lcd.init();
  lcd.backlight();

  // Configurar los pines de los LEDs como salida
  pinMode(LED_ROJO_PIN, OUTPUT);
  pinMode(LED_AMARILLO_PIN, OUTPUT);
  pinMode(LED_VERDE_PIN, OUTPUT);

  // Inicializar el servo
  servo.attach(SERVO_PIN);

  // Mostrar mensaje inicial en el LCD
  lcd.setCursor(0, 0);
  lcd.print("Seleccionar Menu");
  lcd.setCursor(0, 1);
  lcd.print("1. Opcion 1");
}

void loop() {
  // Verifica si alguna tecla fue presionada
  char tecla_presionada = teclado1.getKey();

  if (tecla_presionada) {
    // Apagar los LEDs antes de encender el nuevo
    digitalWrite(LED_ROJO_PIN, LOW);
    digitalWrite(LED_AMARILLO_PIN, LOW);
    digitalWrite(LED_VERDE_PIN, LOW);

    // Mostrar en el monitor serial
    Serial.print("Tecla: ");
    Serial.println(tecla_presionada);

    // Limpiar la pantalla LCD
    lcd.clear();

    // Procesar la tecla presionada
    switch (tecla_presionada) {
      case '1':
        lcd.setCursor(0, 0);
        lcd.print("LED Rojo Activado");
        digitalWrite(LED_ROJO_PIN, HIGH);
        break;

      case '2':
        lcd.setCursor(0, 0);
        lcd.print("LED Amarillo Activado");
        digitalWrite(LED_AMARILLO_PIN, HIGH);
        break;

      case '3':
        lcd.setCursor(0, 0);
        lcd.print("LED Verde Activado");
        digitalWrite(LED_VERDE_PIN, HIGH);
        break;

      case '4':
        lcd.setCursor(0, 0);
        lcd.print("Controlando Servo");
        servo.write(90);  // Mover el servo a 90 grados
        delay(1000);      // Esperar 1 segundo
        servo.write(0);   // Regresar el servo a 0 grados
        break;

      case '*': // Regresar al menú principal
        lcd.setCursor(0, 0);
        lcd.print("Menu Principal");
        lcd.setCursor(0, 1);
        lcd.print("1. Opcion 1");
        break;

      default:
        lcd.setCursor(0, 0);
        lcd.print("Tecla no asignada");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Seleccionar Menu");
        lcd.setCursor(0, 1);
        lcd.print("1. Opcion 1");
        break;
    }
  }
}
