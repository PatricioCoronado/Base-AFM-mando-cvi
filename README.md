# PCOM
Monitor de puerto serie para Arduino con LabWindows/CVI
Communicate Arduino through Serial with your PC easily with PCOM

This project facilitates communication between Arduino and your PC through the Serial.

If you include the "IdentificaArduino.ico" code in your Arduino application and fill in the string: char Instrument [] = "Name of my instrument" With the name you want to give the Arduino application, when running PCOM it can find the port your Arduino was connected to and will recognize it by its identification. The first time PCOM will look for your Arduino in the COM ports, but if it finds it, next time it will connect automatically. You can also have several Arduinos with their different identification without problems.

I leave the source code. PCOM is programmed with LabWindows/CVI. You just have to install the LabWindows/CVI RTE http://www.ni.com/download/labwindowscvi-run-time-engine-2012/3032/en/ Copy files from LabWindowsCVI directory to some directory in your PC and execute the exe file.

If you want a communication system between Arduino and your PC to make virtual instrumentation at a professional level, look at: https://github.com/PatricioCoronado/Virtual-instrumentation-Arduino-LabWindows-CVI

Recognition: I use a LabWindows/CVI version licensed by SEGAINVEX at the Universidad Autónoma de Madrid.

Español: Comunica Arduino a través de Serial con tu PC fácilmente con PCOM

Este proyecto facilita la comunicación entre Arduino y su PC a través de Serial.

Incluye el código "IdentificaArduino.ico" en tu aplicación Arduino y completa la cadena: char Instrument [] = "Nombre de mi instrumento" Con el nombre que desea darle a la aplicación Arduino, al ejecutar PCOM puede encontrar el puerto COM donde Arduino esta conectado y lo reconocerá por su identificación. La primera vez, PCOM buscará su Arduino en los puertos COM, pero si lo encuentra, la próxima vez se conectará automáticamente. También puedes tener varios arduinos con su diferente identificación sin problemas.

Os dejo el código fuente. PCOM está programado con LabWindows/CVI. Solo tiene que instalar LabWindows/CVI RTE http://www.ni.com/download/labwindowscvi-run-time-engine-2012/3032/en/ Copie los archivos del directorio LabWindowsCVI a algún directorio de su PC y ejecute archivo exe.

Si desea un sistema de comunicación entre Arduino y su PC para crear instrumentación virtual a nivel profesional, visite: https://github.com/PatricioCoronado/Virtual-instrumentation-Arduino-LabWindows-CVI

Reconocimiento: uso una versión de LabWindows / CVI con licencia de SEGAINVEX en la Universidad Autónoma de Madrid.
