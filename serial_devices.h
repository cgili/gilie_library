

#ifndef SERIAL_DEVICES_H_
#define SERIAL_DEVICES_H_
#include <stddef.h> 
#include <stdio.h>



enum status_t
{
    STATUS_OK,
    STATUS_CORRENTE_BAIXA,
    STATUS_CORRENTE_ALTA,
    STATUS_FREQUENCIA_BAIXA,
    STATUS_FREQUENCIA_ALTA,
    STATUS_VIN_BAIXO,
    STATUS_VIN_ALTO
};



#if (__STDC_VERSION__ >= 201710L)
enum cmd_inp_t
#else 
enum cmd_inp_t : uint8_t
#endif
{
    CMD_INP_GET_VERSION,    // Retorna controle de versoes [uint8 PCI - uint8 BOM - uint8 SW]
    CMD_INP_SET_ADDRESS,    // Salva endereco de rede, endereco 0 (broadcast) e botao auxiliar. 
    CMD_INP_GET_VALUES      // 
};


//
//serial.packet.size = 14;
//
//serial.packet.data[0] = analog[0];
//serial.packet.data[1] = analog[0] >> 8;
//
//serial.packet.data[2] = analog[1];
//serial.packet.data[3] = analog[1] >> 8;
//
//serial.packet.data[4] = analog[2];
//serial.packet.data[5] = analog[2] >> 8;
//
//serial.packet.data[6] = analog[3];
//serial.packet.data[7] = analog[3] >> 8;
//
//serial.packet.data[8] = analog[4];
//serial.packet.data[9] = analog[4] >> 8;
//
//serial.packet.data[10] = analog[5];
//serial.packet.data[11] = analog[5] >> 8;
//
//serial.packet.data[12] = inputs;
//serial.packet.data[13] = inputs >> 8;



#if (__STDC_VERSION__ >= 201710L)
enum cmd_out_t
#else 
enum cmd_out_t : uint8_t
#endif
{
    CMD_OUT_GET_VERSION,    // Retorna controle de versoes [uint8 PCI - uint8 BOM - uint8 SW]
    CMD_OUT_SET_ADDRESS,    // Salva endereco de rede, endereco 0 (broadcast) e botao auxiliar. 
    CMD_OUT_SET_OUTPUT      // Seta o nivel das 12 saidas ( uint8_t 0b1111, saidas 12,11,10,9 - uint8_t 0b11111111, saidas 8 a 1)
};



#if (__STDC_VERSION__ >= 201710L)
enum cmd_pus_t
#else 
enum cmd_pus_t : uint8_t
#endif
{
    CMD_PUS_GET_VERSION,    // Retorna controle de versoes [uint8 PCI - uint8 BOM - uint8 SW]
    CMD_PUS_GET_SFCV,        // Retorna os valores status, frequencia, corrente e tensao (uint8 status [enum status_t] - int freq [Hz] - int corrente [mA] - float tensao [V])
    CMD_PUS_SET_ON_OFF,     // Liga ou desliga potencia (uint8 state) on=1 - off=0
    CMD_PUS_SET_ADDRESS,         // Salva endereco de rede, endereco 0 (broadcast) e botao auxiliar. 
    CMD_PUS_GET_OTHERS          // Retorna outras variaveis (int amp [bin] - float duty, float integral)
};




enum fita_led_cmd 
{
	FITA_LED_CMD_SET_RGB_ALL = 1,	// Define 3 bytes de rgb para toda a fita
	FITA_LED_CMD_SET_BLACK_ALL,		// Apaga toda a fita
	FITA_LED_CMD_LOAD_RGB_POSITION,	// Envia uma cor respecífica para um frame_buffer, mas não envia para fita
	FITA_LED_CMD_SEND_FRAME,        // Mostra na fita o buffer pre carregado
	FITA_LED_CMD_SEND_LIGHT_FADE,   // Funcao brihlo arlternando de uma cor  
    FITA_LED_CMD_SEND_LOADING,       // Funcao "carregando"
    FITA_LED_CMD_COME_AND_GO,       // Funcao vai e vem
    FITA_LED_CMD_SET_NUM_LEDS,      // Seta o numero de segmentos de led
    FITA_LED_CMD_GET_VERSION,        // retorna a versao do SW
    FITA_LED_CMD_SET_ACK          // Habilita/desabilita ack  
};




#if __STDC_VERSION__ >= 201710L
enum serial_device_t
#else 
enum serial_device_t : uint8_t
#endif
{
	SERIAL_DEVICE_FITA_LED = 'L',
    SERIAL_DEVICE_PUS = 'P',
    SERIAL_DEVICE_OUTPUT = 'O',
    SERIAL_DEVICE_INPUT = 'I'
};


#endif