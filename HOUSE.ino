#include "token.h"
#include <WiFi.h>
#include <WebServer.h>
#include <WiFiMulti.h>

WiFiMulti wifiMulti;
WebServer server(80);

bool led1Encendido = false;  // Estado inicial del LED 1
bool led2Encendido = false;  // Estado inicial del LED 2
bool led3Encendido = false;  // Estado inicial del LED 3

void principal() {
  server.send(200, "text/html", html);
}

void cuentaV() {
  String USUARIO = server.arg("usuario");
  String PASSWORD = server.arg("key");
  Serial.println(USUARIO);
  Serial.println(PASSWORD);
  String response = "";
  if (!strcmp(USUARIO.c_str(), MASTER)) {
    if (!strcmp(PASSWORD.c_str(), MASTERP)) {
      String led1Estado = led1Encendido ? "Encendido" : "Apagado";
      String led2Estado = led2Encendido ? "Encendido" : "Apagado";
      String led3Estado = led3Encendido ? "Encendido" : "Apagado";
      String response = R""(
        <html>
          <body>
            <button onclick="controlarLED(1)">APARATO 1 ESTADO )"" + led1Estado + R""(</button>
            <button onclick="controlarLED(2)">APARATO 2 ESTADO )"" + led2Estado + R""(</button>
            <button onclick="controlarLED(3)">APARATO 3 ESTADO )"" + led3Estado + R""(</button>
            <a href="/" target="_self" rel="noopener noreferrer"><button>CERRAR SESION</button></a>
            <script>
              function controlarLED(led) {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function() {
                  if (this.readyState == 4 && this.status == 200) {
                    // Actualizar la página después de controlar el LED
                    location.reload();
                  }
                };
                xhttp.open("GET", "/controlarLED?led=" + led, true);
                xhttp.send();
              }
            </script>
          </body>
        </html>
      )"";
      server.send(200, "text/html", response);
    } else {
      digitalWrite(2, LOW);
      response = R""( 
        <!DOCTYPE html>
        <html lang="es">
        <head>
            <meta charset="UTF-8">
            <meta http-equiv="X-UA-Compatible" content="IE=edge">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Error: Contraseña Incorrecta</title>
        </head>
        <body>
            <h1>ERROR: Contraseña Incorrecta</h1>
            <a href="/" target="_self" rel="noopener noreferrer" ><button>Volver al Menú Principal</button></a>
        </body>
        </html>
      )"";
      server.send(200, "text/html", response);
    }
  } else {
    response = R""( "<html><body><h1>USUARIO NO ENCONTRADO</h1><a href="/" target="_self" rel="noopener noreferrer" ><button>Volver al Menú Principal</button></a></body></html>"; )"";
    server.send(200, "text/html", response);
  }
}
void controlarLED() {
  int led = server.arg("led").toInt();

  if (led < 1 || led > 3) {
    server.send(400, "text/plain", "Número de LED no válido");
    return;
  }

  bool* ledEncendido;
  switch (led) {
    case 1:
      ledEncendido = &led1Encendido;
      break;
    case 2:
      ledEncendido = &led2Encendido;
      break;
    case 3:
      ledEncendido = &led3Encendido;
      break;
  }

  *ledEncendido = !(*ledEncendido);

  // Configurar el pin del LED
  int pinLed;
  switch (led) {
    case 1:
      pinLed = 2;
      break;
    case 2:
      pinLed = 3;
      break;
    case 3:
      pinLed = 4;
      break;
  }

  // Cambiar el estado del pin del LED
  digitalWrite(pinLed, *ledEncendido ? HIGH : LOW);

  // Crear un mensaje de respuesta
  String mensajeRespuesta = *ledEncendido ? "LED encendido" : "LED apagado";

  // Enviar la respuesta al cliente
  server.send(200, "text/plain", mensajeRespuesta);
}


void setup() {
  Serial.begin(115200);
  wifiMulti.addAP(ssid, password);

  Serial.println("CONECTANDO A WIFI...");
  if (wifiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("Conexión exitosa");
    Serial.println(WiFi.SSID());
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("Conexión WiFi exitosa");
  } else {
    Serial.print("ERROR DE CONEXION");
  }

  server.on("/", HTTP_GET, principal);
  server.on("/login", HTTP_GET, cuentaV);
  server.on("/controlarLED", HTTP_GET, controlarLED);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  server.begin();
  Serial.println("SERVIDOR INICIADO");
}

void loop() {
  server.handleClient();
}
