# ITCR.DatosII.ProyectoI.Server
A program called mserver is executed, indicating as parameters the port on which it is listening and the size in bytes of the total memory.
## Server side of the project.
The server performs a single total memory malloc. The server has an internal map of the entire memory block. For example, at startup you can reserve 10MB of real memory. With each request received from C !, the server handles offsets to determine the position of each variable in C! within the actual memory block.
The server listens for requests from C! sent by the IDE in JSON format. When the IDE C! send a request must indicate at least the type of data, the name of the variable and the size to be reserved. The server handles memory automatically. That is, C! you never have to free memory or request to create it. 
The server keeps the reference count and every so often it executes the garbage collector that eliminates the memory spaces that are not referenced.

## Libraries needed
This project runs on Ubuntu C++
First a JSON files handling library is needed. It could be install with the following commands:
````
sudo apt-get update
sudo apt-get install nlohmann-json3-dev
````
Also, the lib boost library is needed. It could be install with the following commands:
````
sudo apt update -y
sudo apt install -y libboost-all-dev
````

[Doxygen documentation link](https://github.com/AnthonyHMR/ITCR.DatosII.ProyectoI.Server/blob/main/doc/html.zip)
