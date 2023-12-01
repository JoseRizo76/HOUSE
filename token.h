/*
DECALRACION DE VARIABLES DE MANERA QUE SEA PRIVADA Y PARA PROTECCION DEL CODIGO
*/
const char *ssid = "POCO-F3";
const char *password = "Jose Rizo";
/*
const char *ssid2 = "Casa Dalmata";
const char *password2 = "Primos2021";a



IPAddress ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(8, 8, 8, 8);
*/


//VARIABLES DE ACCESO ALA SERVIDOR 
char MASTER[20]  = "Jose";
char MASTERP[20] = "14122022";


const char *html = R""(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="https://kit.fontawesome.com/892f23a568.js" crossorigin="anonymous"></script>
    <title>HOUSE</title>
    <!-- <link rel="stylesheet" href="styles.css"> -->
</head>
<body>

  <style>

body {
  margin: 0;
  padding: 0;
  height: 100vh;
  align-items: center;
  justify-content: center;
  background: url('https://drive.google.com/uc?export=download&id=1k1ah7Ou1dCBt4xB910juAncKkpD-S0XU') no-repeat fixed;
  background-size: cover;
}

@media (max-width: 450px) {
  .contenedor {
    width: 80%;
  }
}

.contenedor{
  height: 100vh;
  width: 100vw;
  display: flex;
  align-items: center;
  justify-content: center;
}

.tarjeta{
  height: 400px;
  width: 350px;
  background-color: #101010;
  border-radius: 10%;
  box-shadow: 16px 14px 20px #0000008c;
  position: relative;
  overflow: hidden;
  display: flex;
  align-items: center;
  justify-content: center;
}

.tarjeta::before{
  content: "";
  position: absolute;
  height: 500px;
  width: 500px;
  background-image: conic-gradient(red 20deg, transparent 120deg);
  animation: rotar 2.3s linear infinite;
}

@keyframes rotar{
  from{
      transform: rotate(0deg);
  }
  to{
      transform: rotate(-360deg);
  }
}

::placeholder{
  font-size: 12px;
  font-style: oblique;
  letter-spacing: 0px;
}
.tarjeta::after{
  content: "";
  position: absolute;
  height: 390px;
  width: 340px;
  background-color: #101010;
  border-radius: 10%;
  box-shadow: inset 16px 14px 20px #0000008c;;
}
.informacion{
  height: 380px;
  width: 320px;
  background-color: #101010;
  border-radius: 10%;
  position: relative;
  overflow: hidden;
  display: flex;
  align-items: center;
  justify-content: center;
}

.fa-user-gear{
  position: absolute;
  z-index: 1;
  color: red;
  background-color: transparent;
  top: 150px;
  left: 28px;
  font-size: 20px;
} 

.usuario{
  position: absolute;
  z-index: 1;
  color: rgb(255, 255, 255);
  background-color: transparent;
  box-shadow: 3px 3px 10px rgba(255, 0, 0, 1);
  text-align: center;
  letter-spacing: 1px;
  border-radius: 10px;
  border: solid 2px red;
  width: 220px;
  height: 25px;
  top: 145px;
  left: 60px;
  font-size: 15px;
  font-weight:bold;
}
.usuario:focus{
  z-index: 1;
  color:rgb(255, 255, 255);
  box-shadow: 6px 6px 20px 0px rgb(2, 23, 255);
  font-size: 18px;
  background-color: transparent;
  letter-spacing: 3px;
}
.contrasena:focus{
  z-index: 1;
  color:rgb(255, 252, 252);
  box-shadow: 6px 6px 20px 0px rgb(2, 23, 255);
  font-size: 18px;
  letter-spacing: 2px;
}

.contrasena{
  position: absolute;
  z-index: 1;
  color: rgb(255, 255, 255);
  background-color: transparent;
  text-align: center;
  box-shadow: 3px 3px 10px rgba(255, 0, 0, 0.638);
  border-radius: 10px;
  border: solid 2px red;
  width: 220px;
  height: 25px;
  top: 190px;
  left: 60px;
  font-size: 15px;
  letter-spacing: 1px;
} 
.fa-key{
  position: absolute;
  z-index: 1;
  color: red;
  background-color: transparent;
  top: 200px;
  left: 30px;
  font-size: 20px;
}
.texto{
  position: absolute;
  z-index: 1;
  color: red;
  background-color: transparent;
  top: 80px;
  font-size: 20px;
  letter-spacing: 1px;
}
.fa-house-lock{
  position: absolute;
  z-index: 1;
  color: #000000;
  background-color: transparent;
  top: 10px;
  font-size: 60px;
  animation: principal 1.5s alternate-reverse infinite;
}

@keyframes principal{
  0%{text-shadow: 5px 5px 5px rgb(255, 0, 0);}
  33%{text-shadow: 5px 6px 7px rgb(255, 0, 0);}
  33%{text-shadow: 5px 6px 7px blue;}
  66%{text-shadow: 5px 6px 7px blue;}
  66%{text-shadow: 5px 6px 7px rgb(106, 255, 0);}
  100%{text-shadow: 1px 1px 1px rgb(106, 255, 0);}
}


.enviar{
  position: absolute;
  z-index: 1;
  color: rgb(255, 255, 255);
  background-color: black;
  text-align: center;
  border-radius: 10px;
  border: solid 2px red;
  width: 227px;
  height: 30px;
  box-shadow: 4px 4px 15px rgb(255, 0, 0);
  top: 240px;
  left: 60px;
  letter-spacing: 2px;
  font-style: oblique ;
  font-weight: bold;
} 
.enviar:hover {
  color: rgb(6, 250, 55);
  box-shadow: 4px 4px 15px blue;
  border: none ;
}

.fa-arrow-right-to-bracket{
  position: absolute;
  z-index: 1;
  color: red;
  background-color: transparent;
  top: 10px;
  font-size: 25px;
  left: 25px;
  top: 242px;
}
#showPassword{
  position: absolute;
  z-index: 1;
  color: red;
  background-color: transparent;
  top: 10px;
  left: 30px;
  top: 282px;
}
.mostrarc{
  position: absolute;
  z-index: 1;
  color: rgb(255, 255, 255);
  background-color: transparent;
  top: 10px;
  font-size: 15px;
  left: 65px;
  top: 268px;
}
  </style>

  <div class="contenedor">
    <form action='/login' method='get'>
      <div class="tarjeta"> 
        <div class="informacion">
          <h2 class="texto">BIENVENIDO</h2>
          <i class="fas fa-house-lock"></i>
          <i class="fas fa-user-gear"></i>
          <input type="text" id="usuario" class="usuario" placeholder="USUARIO" name="usuario" required autocomplete="off">
          <i class="fas fa-key"></i>
          <input type="password" id="password" class="contrasena" placeholder="CONTRASEÑA" name="key" required>
          <i class="fas fa-arrow-right-to-bracket"></i>
          <button type="submit" class="enviar">INICIAR SESION</button>
          <input type="checkbox" id="showPassword" onchange="togglePasswordVisibility()">
          <p class="mostrarc">MOSTRAR CONTRASEÑA</p>
        </div>
      </div>
    </form>
  </div>
  <script>
    function togglePasswordVisibility() {
        var passwordInput = document.getElementById("password");
        var showPasswordCheckbox = document.getElementById("showPassword");
  
        if (showPasswordCheckbox.checked) {
            passwordInput.type = "text";
        } else {
            passwordInput.type = "password";
        }
    }
  </script>  
</body>
</html>
)"";
