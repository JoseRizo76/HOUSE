#include "token.h"
#include <WiFi.h>
#include <WebServer.h>
#include <WiFiMulti.h>
#include "login.h"
#include "error.h"
#include "reload.h"
#include "control.h"

WiFiMulti wifiMulti;
WebServer server(80);

bool led1Encendido = false;
bool led2Encendido = false;
bool led3Encendido = false;
boolean loginv = false;

void principal() {
  server.send(200, "text/html", html);
}

void control() {
  if (loginv) {
    String led1Estado = led1Encendido ? "Encendido" : "Apagado";
    String led2Estado = led2Encendido ? "Encendido" : "Apagado";
    String led3Estado = led3Encendido ? "Encendido" : "Apagado";
    server.send(200, "text/html", control_principal);
  } else {
    server.send(200, "text/html", acceso_denegado);
  }
}

void cerrarSesion() {
  loginv = false;
  server.send(200, "text/plain", "Sesión cerrada");
}

void cuentaV() {
  String USUARIO = server.arg("usuario");
  String PASSWORD = server.arg("key");
  Serial.println(USUARIO);
  Serial.println(PASSWORD);
  String response = "";
  if (!strcmp(USUARIO.c_str(), MASTER)) {
    if (!strcmp(PASSWORD.c_str(), MASTERP)) {
      loginv = true;
      server.send(200, "text/html", redireccionando);
    } else {
      // PAGINA DE ERROR
      server.send(200, "text/html", error);
    }
  } else {
    // PAGINA DE USUARIO NO ENCONTRADO
    server.send(200, "text/html", USUARIO_NO_ENCONTRADO);
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
      pinLed = 3;
      break;
    case 2:
      pinLed = 2;
      break;
    case 3:
      pinLed = 4;
      break;
  }

  if (loginv) {
    digitalWrite(pinLed, *ledEncendido ? HIGH : LOW);
  }

  // Crear un mensaje de respuesta
  String mensajeRespuesta = *ledEncendido ? "Encendido" : "Apagado";

  // Enviar la respuesta al cliente
  server.send(200, "text/plain", mensajeRespuesta);
}

void setup() {
  Serial.begin(115200);
  wifiMulti.addAP(ssid, password);

  if(wifiMulti.run() == WL_CONNECTED) {
      delay(500);
      Serial.println("");
      Serial.println("Conexión exitosa. Configurando IP fija...");
      if (WiFi.config(ip, gateway, subnet, dns)) {
        Serial.print("Dirección IP asignada: ");
        Serial.println(WiFi.localIP());
      } else {
        Serial.println("Error al configurar la IP fija.");
      }

      Serial.println(WiFi.SSID());
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());
      Serial.println("Conexión WiFi exitosa");
  }
  else{
    Serial.println("ERROR DE CONEXION WIFI");
  }
/*
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
  */

  server.on("/", HTTP_GET, principal);
  server.on("/login", HTTP_GET, cuentaV);
  server.on("/control", HTTP_GET, control);
  server.on("/controlarLED", HTTP_GET, controlarLED);
  server.on("/cerrarSesion", HTTP_GET, cerrarSesion);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  server.begin();
  Serial.println("SERVIDOR INICIADO");
}

void loop() {
  server.handleClient();
}
