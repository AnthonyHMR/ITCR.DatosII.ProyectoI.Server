![LogoTEC](https://www.tec.ac.cr/sites/default/files/media/branding/logo-tec.png)
# Área Académica de Ingeniería en Computadores
## Algoritmos y Estructuras de Datos II
### Profesor:
#### Antonio González Torres
### Estudiantes:
#### Anthony Montero
#### Juan Peña
## Proyecto I - SI 2021
Se trata de un programa llamado mserver, indicando como parámetros el puerto en el que está escuchando y el tamaño en bytes de la memoria total.
## Acerca del servidor
El servidor realiza un solo malloc de memoria total. El servidor tiene un mapa interno de todo el bloque de memoria. Por ejemplo, al inicio, puede reservar 1 MB de memoria real. Con cada solicitud recibida de C!, El servidor maneja las compensaciones para determinar la posición de cada variable en C! dentro del bloque de memoria real. ¡El servidor escucha las solicitudes de C! enviado por el IDE en formato JSON. Cuando el IDE C! enviar una solicitud debe indicar al menos el tipo de dato, el nombre de la variable y el tamaño a reservar. El servidor maneja la memoria automáticamente. ¡Es decir, C! nunca tendrá que liberar memoria ni solicitar crearla. El servidor mantiene el recuento de referencias y cada cierto tiempo ejecuta el recolector de basura que elimina los espacios de memoria a los que no se hace referencia.

## Bibliotecas necesarias 
Este proyecto fue realizado en Ubuntu(Linux) en el lenguaje C++
Primero se necesita una biblioteca de manejo de archivos JSON. Se puede instalar con los siguientes comandos:
````
sudo apt-get update
sudo apt-get install nlohmann-json3-dev
````
Además, se necesita la biblioteca lib boost. Se puede instalar con los siguientes comandos:
````
sudo apt update -y
sudo apt install -y libboost-all-dev
````

[Doxygen documentation link](https://github.com/AnthonyHMR/ITCR.DatosII.ProyectoI.Server/blob/main/doc/html.zip) <br/>
[Github wiki documentation](https://github.com/AnthonyHMR/ITCR.DatosII.ProyectoI.Server/wiki)<br/>
[Link del archivo PDF con el resumen de la documentación externa](https://github.com/AnthonyHMR/ITCR.DatosII.ProyectoI.Server/blob/main/doc/Docu%20Proyecto%201.pdf)
