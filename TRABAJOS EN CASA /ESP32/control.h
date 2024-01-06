String control_principal = R""(
 
 <!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="https://kit.fontawesome.com/892f23a568.js"></script>
    <style>
      body {
        background-color:  #0f181f;
        height: 90vh;
        width: 90vw;
        justify-content: center;
        align-items: center;
        display: flex;
        flex-direction: column;
      }
      .cuadro{
        display: flex; 
        flex-direction: column;
        align-items: center;
        justify-content: center;
      }

      .contenedor{
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        position: absolute;
      }

        .buttonContainer {
            display: flex;
            border: 2px solid #ee1f25; 
            background-color: #ee1f25;
            border-radius: 35px; 
            overflow: hidden; 
            margin-bottom: 10px;
            margin-left:2vh;
            width: 100px;
            align-items: center;
            box-shadow: 10px 10px 30px black;
        }
        .buttonContainer.on {
            border: 2px solid #0c9545; 
            background-color: #0c9545;
        }
        .buttonContainer.on p{
          color: #dfdedc;
        }

        .circleButton {
            width: 50px;
            height: 50px;
            border-radius: 50%;
            background-color: #111a21; 
            cursor: pointer;
            transition: background-color 0.5s, transform 0.1s;
            z-index: 3;
        }

        .circleButton.on {
            background-color:#111a21;
            transform: translateX(50px);
        }

        .buttonContainer a {
            text-decoration: none;
            color: #333;
        }

        .buttonContainer p{
          color: white;
          position: absolute;
          z-index: 1;
          letter-spacing: 2px;
          font-weight: bold;
          margin-left: 10px;
          text-indent: 4px;
        }
        .fa-arrow-right-from-bracket{
          color: rgb(255, 0, 0);
          text-shadow: 3px 3px 30px red;
          font-size: 40px;
          font-weight: bold;
          top: 30px;
          position: absolute;
          right: 20px;
          animation: loga 2s infinite alternate-reverse;
        }
        
        @keyframes loga{
          33%{
            color: greenyellow;
            text-shadow: 3px 3px 30px greenyellow;
          }
          66%{
            color: blue;
            text-shadow: 3px 3px 30px blue;
          }
        }
        @media (max-width: 480px) {
            .cuadro p {
                margin-top: 10%; /* Ajusta según sea necesario */
            }
        }

        .logout:hover{
          box-shadow: 4px 4px 20px blue;
          border: none;
        }
        .cuadro p{
          position: relative;
          font-weight: bold;
          letter-spacing: 2px;
          color: white;
          font-size: 16px;
          left: 14px;
          margin-bottom: 3px;
        }
        
    </style>
    <title>Círculo de Activación con Borde</title>
</head>

<div class="contenedor">
    <div class="cuadro">
        <p>LAMPARA</p>
    </div>
    <div class="buttonContainer" onclick="controlarLEDAnimacion(1)">
        <p>ON OFF</p>
        <div class="circleButton"></div>
    </div>
    <div class="cuadro">
        <p>LAMPARA</p>
    </div>
    <div class="buttonContainer" onclick="controlarLEDAnimacion(2)">
        <p>ON OFF</p>
        <div class="circleButton"></div>
    </div>
    <div class="cuadro">
        <p>LAMPARA</p>
    </div>
    <div class="buttonContainer" onclick="controlarLEDAnimacion(3)">
        <p>ON OFF</p>
        <div class="circleButton"></div>
    </div>
</div>

<a href="/" target="_self" rel="noopener noreferrer">
    <i class="fa-solid fa-arrow-right-from-bracket" onclick="cerrarSesion()"></i>
</a>

<script>
    // Al cargar la página, aplicar la clase 'on' según las cookies
    document.querySelectorAll('.buttonContainer').forEach(function(container, index) {
        var circleButton = container.querySelector('.circleButton');
        circleButton.classList.toggle('on', getCookie('led' + (index + 1)) === 'Encendido');
        container.classList.toggle('on', getCookie('led' + (index + 1)) === 'Encendido');
    });

    function setCookie(name, value) {
        document.cookie = name + '=' + value;
    }

    function getCookie(name) {
        var match = document.cookie.match(new RegExp('(^| )' + name + '=([^;]+)'));
        if (match) return match[2];
    }

    function controlarLEDAnimacion(circleNumber) {
        var container = document.querySelector('.buttonContainer:nth-child(' + circleNumber * 2 + ')');
        var circleButton = container.querySelector('.circleButton');
        circleButton.classList.toggle('on');
        container.classList.toggle('on');
        controlarLED(circleNumber);
    }

    function controlarLED(led) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                setCookie('led' + led, xhttp.responseText);
            }
            if (this.readyState == 4 && this.status == 200) {
                location.reload();
            }
        };
        xhttp.open("GET", "/controlarLED?led=" + led, true);
        xhttp.send();
    }

    function cerrarSesion() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {};
        xhttp.open("GET", "/cerrarSesion", true);
        xhttp.send();
    }
</script>
</body>
</html>
)"";