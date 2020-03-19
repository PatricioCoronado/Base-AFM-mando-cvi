/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2019. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  MANDO                            1
#define  MANDO_VELOCIDAD                  2       /* control type: scale, callback function: (none) */
#define  MANDO_FOTODIODO_DOWN             3       /* control type: toggle, callback function: tecla */
#define  MANDO_FOTODIODO_LEFT             4       /* control type: toggle, callback function: tecla */
#define  MANDO_FOTODIODO_RIGHT            5       /* control type: toggle, callback function: tecla */
#define  MANDO_Z3_DOWN                    6       /* control type: toggle, callback function: tecla */
#define  MANDO_Z3_UP                      7       /* control type: toggle, callback function: tecla */
#define  MANDO_Z2_DOWN                    8       /* control type: toggle, callback function: tecla */
#define  MANDO_Z2_UP                      9       /* control type: toggle, callback function: tecla */
#define  MANDO_Z123_DOWN                  10      /* control type: toggle, callback function: tecla */
#define  MANDO_Z123_UP                    11      /* control type: toggle, callback function: tecla */
#define  MANDO_Z1_DOWN                    12      /* control type: toggle, callback function: tecla */
#define  MANDO_Z1_UP                      13      /* control type: toggle, callback function: tecla */
#define  MANDO_FOTODIODO_UP               14      /* control type: toggle, callback function: tecla */
#define  MANDO_LASER_DOWN                 15      /* control type: toggle, callback function: tecla */
#define  MANDO_LASER_LEFT                 16      /* control type: toggle, callback function: tecla */
#define  MANDO_LASER_RIGHT                17      /* control type: toggle, callback function: tecla */
#define  MANDO_LASER_UP                   18      /* control type: toggle, callback function: tecla */
#define  MANDO_FUERZALATERAL              19      /* control type: numeric, callback function: (none) */
#define  MANDO_FUERZANORMAL               20      /* control type: numeric, callback function: (none) */
#define  MANDO_CONTADOR                   21      /* control type: numeric, callback function: (none) */
#define  MANDO_PASOS                      22      /* control type: numeric, callback function: (none) */
#define  MANDO_SUMA                       23      /* control type: numeric, callback function: (none) */
#define  MANDO_DECORATION_4               24      /* control type: deco, callback function: (none) */
#define  MANDO_DECORATION_3               25      /* control type: deco, callback function: (none) */
#define  MANDO_DECORATION_5               26      /* control type: deco, callback function: (none) */
#define  MANDO_DECORATION_2               27      /* control type: deco, callback function: (none) */
#define  MANDO_TEXTMSG_7                  28      /* control type: textMsg, callback function: (none) */
#define  MANDO_TEXTMSG_6                  29      /* control type: textMsg, callback function: (none) */
#define  MANDO_TEXTMSG_5                  30      /* control type: textMsg, callback function: (none) */
#define  MANDO_TEXTMSG_4                  31      /* control type: textMsg, callback function: (none) */
#define  MANDO_TEXTMSG_2                  32      /* control type: textMsg, callback function: (none) */
#define  MANDO_TEXTMSG                    33      /* control type: textMsg, callback function: (none) */
#define  MANDO_ESTADOMARCHAPARO           34      /* control type: string, callback function: (none) */
#define  MANDO_LEDMODO                    35      /* control type: LED, callback function: (none) */
#define  MANDO_LEDMARCHA                  36      /* control type: LED, callback function: (none) */
#define  MANDO_MODO                       37      /* control type: binary, callback function: modo_continuo */
#define  MANDO_ESTADO                     38      /* control type: command, callback function: recibir_estado */
#define  MANDO_TIMER                      39      /* control type: timer, callback function: estado_del_sistema */

#define  PC                               2
#define  PC_FOTODIODO_DOWN                2       /* control type: toggle, callback function: pc_tecla */
#define  PC_FOTODIODO_LEFT                3       /* control type: toggle, callback function: pc_tecla */
#define  PC_FOTODIODO_RIGHT               4       /* control type: toggle, callback function: pc_tecla */
#define  PC_Z3_DOWN                       5       /* control type: toggle, callback function: pc_tecla */
#define  PC_Z3_UP                         6       /* control type: toggle, callback function: pc_tecla */
#define  PC_Y_DOWN                        7       /* control type: toggle, callback function: pc_tecla */
#define  PC_Y_UP                          8       /* control type: toggle, callback function: pc_tecla */
#define  PC_Z2_DOWN                       9       /* control type: toggle, callback function: pc_tecla */
#define  PC_Z2_UP                         10      /* control type: toggle, callback function: pc_tecla */
#define  PC_X_DOWN                        11      /* control type: toggle, callback function: pc_tecla */
#define  PC_X_UP                          12      /* control type: toggle, callback function: pc_tecla */
#define  PC_Z123_DOWN                     13      /* control type: toggle, callback function: pc_tecla */
#define  PC_Z123_UP                       14      /* control type: toggle, callback function: pc_tecla */
#define  PC_Z1_DOWN                       15      /* control type: toggle, callback function: pc_tecla */
#define  PC_Z1_UP                         16      /* control type: toggle, callback function: pc_tecla */
#define  PC_FOTODIODO_UP                  17      /* control type: toggle, callback function: pc_tecla */
#define  PC_LASER_DOWN                    18      /* control type: toggle, callback function: pc_tecla */
#define  PC_LASER_LEFT                    19      /* control type: toggle, callback function: pc_tecla */
#define  PC_LASER_RIGHT                   20      /* control type: toggle, callback function: pc_tecla */
#define  PC_LASER_UP                      21      /* control type: toggle, callback function: pc_tecla */
#define  PC_FUERZALATERAL                 22      /* control type: numeric, callback function: (none) */
#define  PC_FUERZANORMAL                  23      /* control type: numeric, callback function: (none) */
#define  PC_FRECUENCIA                    24      /* control type: numeric, callback function: pc_cambiar_frecuencia */
#define  PC_Y                             25      /* control type: textMsg, callback function: (none) */
#define  PC_X                             26      /* control type: textMsg, callback function: (none) */
#define  PC_PASOS                         27      /* control type: numeric, callback function: pc_enviar_pasos */
#define  PC_HUMEDAD                       28      /* control type: numeric, callback function: (none) */
#define  PC_TEMPERATURA                   29      /* control type: numeric, callback function: (none) */
#define  PC_LEDMARCHA                     30      /* control type: LED, callback function: (none) */
#define  PC_SUMA                          31      /* control type: numeric, callback function: (none) */
#define  PC_TEXTMSG_7                     32      /* control type: textMsg, callback function: (none) */
#define  PC_TEXTMSG_6                     33      /* control type: textMsg, callback function: (none) */
#define  PC_ONDA                          34      /* control type: slide, callback function: pc_cambia_onda */
#define  PC_TEXTMSG_5                     35      /* control type: textMsg, callback function: (none) */
#define  PC_TEXTMSG_4                     36      /* control type: textMsg, callback function: (none) */
#define  PC_RESOLUCION                    37      /* control type: slide, callback function: pc_cambia_resolucion */
#define  PC_TEXTMSG_2                     38      /* control type: textMsg, callback function: (none) */
#define  PC_LEERCONTADOR                  39      /* control type: command, callback function: pc_leer_contador */
#define  PC_LEERPASOS                     40      /* control type: command, callback function: pc_leer_pasos */
#define  PC_TEXTMSG                       41      /* control type: textMsg, callback function: (none) */
#define  PC_PARO                          42      /* control type: command, callback function: pc_paro */
#define  PC_MARCHA                        43      /* control type: command, callback function: pc_marcha */
#define  PC_ESTADO                        44      /* control type: command, callback function: pc_recibir_estado */
#define  PC_TIMERAMBIENTE                 45      /* control type: timer, callback function: timer_pc */
#define  PC_MOTORACTIVO                   46      /* control type: slide, callback function: pc_cambia_motor_activo */
#define  PC_SENTIDO                       47      /* control type: slide, callback function: pc_cambia_sentido */


     /* Control Arrays: */

#define  CTRLARRAY                        1

     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK estado_del_sistema(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK modo_continuo(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pc_cambia_motor_activo(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pc_cambia_onda(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pc_cambia_resolucion(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pc_cambia_sentido(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pc_cambiar_frecuencia(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pc_enviar_pasos(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pc_leer_contador(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pc_leer_pasos(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pc_marcha(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pc_paro(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pc_recibir_estado(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pc_tecla(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK recibir_estado(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK tecla(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK timer_pc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
