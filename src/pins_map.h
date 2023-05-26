
#include "mbed.h"

//AIN
AnalogIn shleif_1(PA_0);
AnalogIn shleif_2(PA_1);
AnalogIn shleif_3(PA_2);
AnalogIn shleif_4(PA_3);
AnalogIn shleif_5(PA_4);
AnalogIn shleif_6(PA_5);
AnalogIn shleif_7(PA_6);
AnalogIn shleif_8(PA_7);
AnalogIn shleif_9(PC_0);
AnalogIn shleif_10(PC_1);
AnalogIn shleif_11(PC_2);
AnalogIn shleif_12(PC_3);
//RELAYS
DigitalOut relay1(PD_12);
DigitalOut relay2(PD_13);
DigitalOut relay3(PD_14);
DigitalOut relay4(PD_15);
//DO
DigitalOut do1(PD_8);
DigitalOut do2(PD_9);
DigitalOut do3(PD_10);
DigitalOut do4(PD_11);
//DO_DIAG
DigitalIn diag1(PE_12);
DigitalIn diag2(PE_13);
DigitalIn diag3(PE_14);
DigitalIn diag4(PE_15);
//SERIAL CONSOLE
#define USART1_TX PA_9
#define USART1_RX PA_10
//RS485-1
//#define USART3_TX PB_10
//#define USART3_RX PB_11
//RS-485-2
//ETH
//SPI spi3(PB_5, PB_4, PB_3); // mosi, miso, sclk
DigitalOut cs(PB_7);
DigitalOut rst(PB_6);
//SD
