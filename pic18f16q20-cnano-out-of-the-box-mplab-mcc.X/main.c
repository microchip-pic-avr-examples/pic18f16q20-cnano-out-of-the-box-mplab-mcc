 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
� [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include <string.h>

#define BLINK_DELAY         500
#define RAMP_DELAY          300
#define DV_START_VALUE      0x03
#define DV_STOP_VALUE       0xFC
/*
    Main application
*/

typedef enum {BLINKY, BUTTON, RAMP} programs_t;

static uint8_t Unblocking_Read(void);
static void Print_Menu(void);
static void CLI_Execute_Command(uint8_t);
static void CLI_Run(void);
static void DEMO_Run(void);
static void Blink_LED(void);
static void Button_LED(void);
static void Send_DataVisualizer_Data(char txData);
static void Send_DataVisualizer_Ramp(void);

static programs_t current_program = BLINKY;

int main(void)
{
        SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global High Interrupts 
    //INTERRUPT_GlobalInterruptHighEnable(); 

    // Disable the Global High Interrupts 
    //INTERRUPT_GlobalInterruptHighDisable(); 

    // Enable the Global Low Interrupts 
    //INTERRUPT_GlobalInterruptLowEnable(); 

    // Disable the Global Low Interrupts 
    //INTERRUPT_GlobalInterruptLowDisable(); 
        
    SYSTEM_Initialize();
    Print_Menu();

    while(1)
    {
        CLI_Run();
        DEMO_Run();
    }    
}

static uint8_t Unblocking_Read(void) 
{
    if(UART1_IsRxReady() != 0) /* boolean */
    {
        return UART1_Read();
    }
    else
    {
        return '\0';
    }
}

static void Print_Menu(void)
{
    printf("\n\r");
    printf("********************************************************************************************************\n\r");
    printf("*                       Out of the box application for PIC18F16Q20 Curiosity Nano                      *\n\r");
    printf("********************************************************************************************************\n\r");
    printf("*        MMMMMMMMMNddhysyyyysyyhdmMMNNNMMMMM                                                           *\r\n");
    printf("*        MMMMMMmhssssssssssssssssshMNmmMMMMM                                                           *\r\n");
    printf("*        MMMMdyssssssssssssssssssssyNMMMMMMM                                                           *\r\n");
    printf("*        MMmyssssso-`.ossssssso-.-osymMMMMMM                                                           *\r\n");
    printf("*        Mdssssss/`   `/sssss:    `+ssdMMMMM       __  __ _                     _     _                *\r\n");
    printf("*        mssssss/       -sss-       /ssyNMMM      |  \\/  (_)                   | |   (_)               *\r\n");
    printf("*        yssssoso-       .oso.       -ssymMM      | \\  / |_  ___ _ __ ___   ___| |__  _ _ __           *\r\n");
    printf("*        ysso- -ss/`      `/ss-       .ossdM      | |\\/| | |/ __| '__/ _ \\ / __| '_ \\| | '_ \\          *\r\n");
    printf("*        ys+`   .os+`       :ss/`      `/ssh      | |  | | | (__| | | (_) | (__| | | | | |_) |         *\r\n");
    printf("*        y:      `+so-       .os+`       :sh      |_|  |_|_|\\___|_|  \\___/ \\___|_| |_|_| .__/          *\r\n");
    printf("*        m`      -osss/       -sso-       /M                                           | |             *\r\n");
    printf("*        Mh`   `/ssssss+`    :sssss/     -NM                                           |_|             *\r\n");
    printf("*        MMm: -osssssssso-`.+sssssss+`  +NMM                                                           *\r\n");
    printf("*        MMMMhysssssssssssssssssssssso+mMMMM                                                           *\r\n");
    printf("*        MMMMMMNdysssssssssssssssssydNMMMMMM                                                           *\r\n");
    printf("*        MMMMMMMMMNmdhyyysssyyhhdmMMMMMMMMMM                                                           *\r\n");
    printf("********************************************************************************************************\n\r");
    printf("*                                                                                                      *\n\r");
    printf("* -Press a key corresponding to a program:                                                             *\n\r");
    printf("*  '1' - Default program; Blinking LED                                                                 *\n\r");
    printf("*  '2' - LED turns on while button is pressed                                                          *\n\r");
    printf("*  '3' - An ascending ramp visible in MPLAB Data Visualizer sent through UART while button is pressed  *\n\r");
    printf("*                                                                                                      *\n\r");
    printf("* -Press any other key to view the menu again.                                                         *\n\r");
    printf("*                                                                                                      *\n\r");
    printf("********************************************************************************************************\n\r");
}

static void CLI_Execute_Command(uint8_t command)
{
    switch(command)
    {
        case '1':
            current_program = BLINKY;
            printf("Program changed to blink LED\r\n");
            break;
        case '2':
            LED_SetHigh();
            current_program = BUTTON;
            printf("Program changed to press button to turn on LED\r\n");
            break;
        case '3':
            LED_SetHigh();
            current_program = RAMP;
            printf("Program changed to press button to send a ramp through UART\r\n");
            break;
        default:
            Print_Menu();
            break;
    }
}

static void CLI_Run(void)
{
    uint8_t ch = 0;
    
    ch = Unblocking_Read();
    
    if((ch != '\n') && (ch != '\r') && (ch != '\0'))
    {
        CLI_Execute_Command(ch);
    }
}

static void DEMO_Run(void)
{
    if(current_program == BLINKY)
    {
        Blink_LED();
    }
    else if(current_program == BUTTON)
    {
        Button_LED();
    }
    else if(current_program == RAMP)
    {
        Send_DataVisualizer_Ramp();
    }
}

static void Blink_LED(void)
{
    LED_Toggle();
    __delay_ms(BLINK_DELAY);
}

static void Button_LED(void)
{
    if(Button_GetValue())
    {
        LED_SetHigh();
    }
    else
    {
        LED_SetLow();
    }
}

static void Send_DataVisualizer_Data(char txData)
{
    while(!(UART1_IsTxReady()));
    UART1_Write(txData);  
}

static void Send_DataVisualizer_Ramp(void)
{
    static uint8_t counter = 0;

    if(!Button_GetValue())
    {
        Send_DataVisualizer_Data(DV_START_VALUE);
        Send_DataVisualizer_Data(counter++);
        Send_DataVisualizer_Data(DV_STOP_VALUE);
        __delay_ms(RAMP_DELAY);
    }
}    
