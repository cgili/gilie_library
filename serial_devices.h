

#ifndef SERIAL_DEVICES_H_
#define SERIAL_DEVICES_H_
#include <stddef.h> 
#include <stdio.h>

#define VERSION 15


enum status_pus_t
{
    STATUS_PUS_CORRENTE_BAIXA = 1,
    STATUS_PUS_CORRENTE_ALTA,
    STATUS_PUS_FREQUENCIA_BAIXA,
    STATUS_PUS_FREQUENCIA_ALTA,
    STATUS_PUS_VIN_BAIXO,
    STATUS_PUS_VIN_ALTO,
    STATUS_PUS_AMP_BAIXA,
    STATUS_PUS_AMP_ALTA,
    STATUS_PUS_OFF,
    STATUS_PUS_ON,
    STATUS_PUS_RS485_PODRE,
};


#if (__STDC_VERSION__ >= 201710L)
enum cmd_sus_t
#else 
enum cmd_sus_t : uint8_t
#endif
{
    CMD_SUS_GET_VERSION,    // Retorna controle de versoes [uint8 PCI - uint8 BOM - uint8 SW]
    CMD_SUS_SET_ADDRESS,    // Salva endereco de rede, endereco 0 (broadcast) e botao auxiliar. 
    CMD_SUS_GET_VALUES,     // [float rms (bin) - float frequencia kHz]
    CMD_SUS_GET_WINDOW      // [120 samples over 8bits > total 30 bytes]    
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
enum cmd_tmp_t
#else 
enum cmd_tmp_t : uint8_t
#endif
{
    CMD_TMP_GET_VERSION,    // Retorna controle de versoes [uint8 PCI - uint8 BOM - uint8 SW]
    CMD_TMP_SET_ADDRESS,    // Salva endereco de rede, endereco 0 (broadcast) e botao auxiliar. 
    CMD_TMP_GET_TEMPERATURE   // Retorna o status e valor da temperatura (uint8_t status [1 erro, 0 ok] - float temperatura)
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
    SERIAL_DEVICE_INPUT = 'I',
    SERIAL_DEVICE_TEMPERATURE = 'T',
    SERIAL_DEVICE_SUS = 'S'                 // US tracker
};


#endif