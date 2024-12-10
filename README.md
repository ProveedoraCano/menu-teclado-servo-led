# Proyecto Arduino: Menú con Servo, LEDs y Pantalla LCD

Este proyecto utiliza un Arduino con un teclado matricial, un módulo LCD I2C, un servo y tres LEDs para crear un menú interactivo. A través del menú, los usuarios pueden seleccionar distintas opciones para controlar los LEDs o mover el servo. 

### 🛠️ Componentes Necesarios
- 1 Arduino Uno (o similar)
- 1 Pantalla LCD 16x2 con módulo I2C
- 1 Teclado matricial 4x3
- 1 Servo (como SG90)
- 3 LEDs (rojo, amarillo, verde)
- Resistencias de 220Ω (para los LEDs)
- Cables y protoboard

### 📋 Esquema de Conexión
| Componente          | Arduino Pin        |
|---------------------|--------------------|
| LCD SDA             | A4 (SDA en I2C)   |
| LCD SCL             | A5 (SCL en I2C)   |
| Teclado Filas       | 13, 12, 11, 10     |
| Teclado Columnas    | 9, 8, 7            |
| LED Rojo            | 4                  |
| LED Amarillo        | 3                  |
| LED Verde           | 2                  |
| Servo               | 5 (PWM)            |

### 🚀 Características
1. **Control de LEDs:** Selecciona opciones en el menú para encender los LEDs (rojo, amarillo, verde).
2. **Control del Servo:** Controla el movimiento del servo con una opción del menú.
3. **Pantalla LCD:** Muestra mensajes interactivos relacionados con el menú y las acciones realizadas.
4. **Teclado Matricial:** Interfaz para navegar y seleccionar las opciones del menú.

### 💻 Instalación
1. Clona este repositorio:
   ```bash
   git clone https://github.com/tuusuario/menu-servo-led.git
   cd menu-servo-led
