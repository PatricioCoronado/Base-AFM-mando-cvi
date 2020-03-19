/********************************************************************************************
	FICHERO:                                                    
	
	Por Patricio Coronado Collado.17/07/2017.
	
	Para comunicar con el puerto COM se utilizan funciones y variables exportadas de 
	PuertoCom.h
*********************************************************************************************/
																								
/*********************************************************************************************
	Copyright © 2017 Patricio Coronado
	
	This file is part of CapturaMuestrasSAMD21.c

    CapturaMuestrasSAMD21.c is free software: you can redistribute it and/or 
	modify it under the terms of the GNU General Public License as published 
	by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CapturaMuestrasSAMD21.c is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CapturaMuestrasSAMD21.c  If not, see <http://www.gnu.org/licenses/>

*********************************************************************************************/	
/*
	Esta cadena es la respuesta que tiene que dar el sistema que queremos controlar
	al recibir un comando SCPI *IDN.
	Obligatorio rellenar la cadena IdentificacionDelInstrumento que debe conincidir con 
	NOMBRE_DEL_SISTEMA_64B(identifiacion del instrumento) en la aplicación de Arduino
*/
char IdentificacionDelInstrumento[] ="Base SPM con Arduino DUE v1.0";
int Marcha=0; 
int ModoContinuo=0;

//------------------------------------------------------------------------------------------
// Ficheros include                                                          
//------------------------------------------------------------------------------------------
#include <ansi_c.h>
#include <cvirte.h>
#include <userint.h>
#include <rs232.h>
#include <utility.h>
#include <formatio.h>
#include <string.h>
#include <analysis.h>
#include "PuertoCOM.h"
#include "mando.h"
//------------------------------------------------------------------------------------------
// Constantes
//------------------------------------------------------------------------------------------
#define PP_TOP  60	  
#define PP_LEFT 60	
//------------------------------------------------------------------------------------------
// Prototipos de funciones
//------------------------------------------------------------------------------------------
int carga_panel_del_mando(void);
void desactiva_todas_las_teclas(int,int);
//------------------------------------------------------------------------------------------
// Variables
//------------------------------------------------------------------------------------------
int MandoHandle=0;
/*********************************************************************************************
		                   FUNCION PRINCIPAL                                     
**********************************************************************************************/
 int main (int argc, char *argv[])
{
	short int PuertoAbierto=-1;
	if (InitCVIRTE (0, argv, 0) == 0) return -1;
	//PuertoAbierto=pcom_abre_puerto_serie();
	pcom_muestra_el_panel_de_mensajes(PP_TOP,PP_LEFT);//Muestra el tráfico por el puerto
	pcom_modo_pcom(0);//Para poner los paneles en modo master
	DisplayPanel (MensajesHandle);
	// Si no se abre un puerto automáticamente, muestra el panel de configuración
	//pcom_muestra_el_panel_de_configuracion(PANEL_MODO_TOP,100,300);
	pcom_abre_puerto_serie(); 
	//if(PuertoAbierto==-1)pcom_muestra_el_panel_de_configuracion(PANEL_MODO_TOP,100,300);
	MandoHandle = LoadPanel (0/* TOP LEVEL */, "mando.uir", MANDO);
	DisplayPanel (MandoHandle);
	RunUserInterface (); 
	return 0;
}
/**********************************************************************************************
							PULSACION DE UNA TECLA
***********************************************************************************************/
int CVICALLBACK tecla (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
int estado,velocidad,vel,pasos, motor, sentido;
if (event==EVENT_COMMIT)
{
	GetCtrlVal (MandoHandle, control, &estado);
	desactiva_todas_las_teclas(control,estado);
	
	if(estado) //Si es un comando de marcha
		
	{
		//Lee datos del comando
		switch (control)
		{
			case MANDO_Z1_UP:
				motor = 1;
				sentido= 1;
			break;
			case MANDO_Z1_DOWN:
				motor = 1;
				sentido = 0;
			break;
			case MANDO_Z2_UP:
				motor = 2;
				sentido = 1;
			break;
			case MANDO_Z2_DOWN:
				motor = 2;
				sentido = 0;
			break;
			case MANDO_Z3_UP:
				motor = 3;
				sentido = 1;
			break;
			case MANDO_Z3_DOWN:
				motor = 3;
				sentido = 0;
			break;
			case MANDO_Z123_UP:
				motor = 7;
				sentido = 1;
			break;
			case MANDO_Z123_DOWN:
				motor = 7;
				sentido = 0;
			break;	

		
			case MANDO_LASER_RIGHT:
				motor = 11;
				sentido = 1;
			break;
			case MANDO_LASER_LEFT:
				motor = 11;
				sentido = 0;
			break;

			case MANDO_LASER_UP:
				motor = 12;
				sentido = 1;
			break;
			case MANDO_LASER_DOWN:
				motor = 12;
				sentido = 0;
			break;
		
			case MANDO_FOTODIODO_UP:
				motor = 10;
				sentido = 1;

			break;
			case MANDO_FOTODIODO_DOWN:			
				motor = 10;
				sentido = 0;
			break;
			case MANDO_FOTODIODO_RIGHT:
				motor = 13;
				sentido = 1;

			break;
			case MANDO_FOTODIODO_LEFT:
				motor = 13;
				sentido = 0;
			break;
		}//switch
		GetCtrlVal(MandoHandle,MANDO_VELOCIDAD,&vel);
		GetCtrlVal (MandoHandle, MANDO_PASOS, &pasos);
		switch (vel)//Da valor a la velocidad
		{
			case 1:
				velocidad=1;
				break;
			case 2:
				velocidad = 5;
				break;
			case 3:
				velocidad = 15;			
				break;
			case 4:
				velocidad = 30;			
				break;
			case 5:
				velocidad = 60;			
				break;
		}//switch (vel)
		//Envía el comando de marcha
		sprintf(CadenaComando,"%s %u %u %u %u","BTH:MARCHA ", motor , velocidad, sentido ,pasos);
		Marcha=1;
		ENVIAR_COMANDO_AL_SISTEMA(MOSTRAR) 	
		// Anuncia que el sistema está en marcha
		SetCtrlVal(MandoHandle,MANDO_LEDMARCHA,1); 
		SetCtrlVal(MandoHandle,MANDO_ESTADOMARCHAPARO,"marcha");	
	}//if(estado)
	else // Si es un  comando de paro lo envía 
	{
		sprintf(CadenaComando,"%s","BTH:PARO");
		ENVIAR_COMANDO_AL_SISTEMA(MOSTRAR) 
		Marcha=0;	
	}
}
	return 0;
}
/**********************************************************************************************
			ACTUALIZA EL ESTADO DE LAS TECLAS SEGUN LO QUE SE HA PULSADO
			Los argumentos de entrada son el control pulsado y el estado
***********************************************************************************************/
void desactiva_todas_las_teclas(int cntrl,int est)
{
	SetCtrlVal (MandoHandle, MANDO_Z1_UP, 0);//Desactiva todos los botones
	SetCtrlVal (MandoHandle, MANDO_Z1_DOWN, 0);
	SetCtrlVal (MandoHandle, MANDO_Z2_UP, 0);
	SetCtrlVal (MandoHandle, MANDO_Z2_DOWN, 0);
	SetCtrlVal (MandoHandle, MANDO_Z3_UP, 0);
	SetCtrlVal (MandoHandle, MANDO_Z3_DOWN, 0);
	SetCtrlVal (MandoHandle, MANDO_LASER_UP, 0);
	SetCtrlVal (MandoHandle, MANDO_LASER_DOWN, 0);
	SetCtrlVal (MandoHandle, MANDO_LASER_RIGHT, 0);
	SetCtrlVal (MandoHandle, MANDO_LASER_LEFT, 0);
	SetCtrlVal (MandoHandle, MANDO_FOTODIODO_UP, 0);
	SetCtrlVal (MandoHandle, MANDO_FOTODIODO_DOWN, 0);
	SetCtrlVal (MandoHandle, MANDO_FOTODIODO_RIGHT, 0);
	SetCtrlVal (MandoHandle, MANDO_FOTODIODO_LEFT, 0);
	if(cntrl) SetCtrlVal (MandoHandle, cntrl, est);//Activa/desactiva solo el pulsado
}
/**********************************************************************************************
				Timer
***********************************************************************************************/

int CVICALLBACK estado_del_sistema (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			if(Marcha || ModoContinuo)
			{
				sprintf(CadenaComando,"BTH:EST?");
				ENVIAR_COMANDO_AL_SISTEMA(MOSTRAR) 		
			}
		break;
	}
	return 0;
}
/**********************************************************************************************
 	Función que se ejecuta cuando se recibe un dato automáticamente
***********************************************************************************************/
 void pcom_datos_recibidos(void)
{
	char firma[4];
	int EstadoMarchaParo,Contador;
	float fuerzaNormal,fuerzaLateral,suma;

	if(CadenaRespuesta[0]=='1')//Primero mira a ver si es una indicación de paro
	{
		SetCtrlVal(MandoHandle,MANDO_LEDMARCHA,0); 
		SetCtrlVal(MandoHandle,MANDO_ESTADOMARCHAPARO,"paro");
		desactiva_todas_las_teclas(0,0); 
		Marcha=0;
	}
	// Ahora mira a ver si es la cadena de estado, si lo es refresca el estado del sistema	
	if (CadenaRespuesta[0]=='E' && CadenaRespuesta[1]=='S' && CadenaRespuesta[2]=='T' )
	{	
		sscanf(CadenaRespuesta,"%s %f %f %f %u %u",firma,&fuerzaNormal,&fuerzaLateral,&suma,&EstadoMarchaParo,&Contador);
		
		if (EstadoMarchaParo==10)
		{
			SetCtrlVal(MandoHandle,MANDO_ESTADOMARCHAPARO,"marcha");
			SetCtrlVal(MandoHandle,MANDO_LEDMARCHA,1); 
			Marcha=1;
		}
		if (EstadoMarchaParo==5)
		{
			SetCtrlVal(MandoHandle,MANDO_ESTADOMARCHAPARO,"paro");
			SetCtrlVal(MandoHandle,MANDO_LEDMARCHA,0); 
			desactiva_todas_las_teclas(0,0); 
			Marcha=0;
		}
		SetCtrlVal(MandoHandle,MANDO_CONTADOR,Contador);
		SetCtrlVal(MandoHandle,MANDO_FUERZANORMAL,fuerzaNormal);
		SetCtrlVal(MandoHandle,MANDO_FUERZALATERAL,fuerzaLateral);
		SetCtrlVal(MandoHandle,MANDO_SUMA,suma);
	}
	return;
}
/**********************************************************************************************
	función para poner o no la comunicación en modo continuo
***********************************************************************************************/

int CVICALLBACK modo_continuo (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int modo;
	switch (event)
	{
		case EVENT_COMMIT:
		GetCtrlVal(MandoHandle,MANDO_MODO,&modo);	
		SetCtrlVal(MandoHandle,MANDO_LEDMODO,modo); 
		if(modo) 
		{
			//SetCtrlAttribute(MandoHandle,MANDO_TIMER, ATTR_ENABLED,1);	
			ModoContinuo=1;
			
		}
		else
		{
			//SetCtrlAttribute(MandoHandle,MANDO_TIMER, ATTR_ENABLED,0);	
			ModoContinuo=0;
		}
			
			
		
		break;
	}
	return 0;
}
/**********************************************************************************************
			función para pedir el estado del sistema
**********************************************************************************************/

int CVICALLBACK recibir_estado (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			sprintf(CadenaComando,"BTH:EST?");
			ENVIAR_COMANDO_AL_SISTEMA(MOSTRAR)

			break;
	}
	return 0;
}
/*********************************************************************************************/
