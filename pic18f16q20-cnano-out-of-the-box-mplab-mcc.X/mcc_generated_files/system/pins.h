/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA2 aliases
#define Button_TRIS                 TRISAbits.TRISA2
#define Button_LAT                  LATAbits.LATA2
#define Button_PORT                 PORTAbits.RA2
#define Button_WPU                  WPUAbits.WPUA2
#define Button_OD                   ODCONAbits.ODCA2
#define Button_ANS                  ANSELAbits.ANSELA2
#define Button_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define Button_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define Button_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define Button_GetValue()           PORTAbits.RA2
#define Button_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define Button_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define Button_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define Button_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define Button_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define Button_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define Button_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define Button_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RC4 aliases
#define IO_RC4_TRIS                 TRISCbits.TRISC4
#define IO_RC4_LAT                  LATCbits.LATC4
#define IO_RC4_PORT                 PORTCbits.RC4
#define IO_RC4_WPU                  WPUCbits.WPUC4
#define IO_RC4_OD                   ODCONCbits.ODCC4
#define IO_RC4_ANS                  ANSELCbits.ANSELC4
#define IO_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_RC4_GetValue()           PORTCbits.RC4
#define IO_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_RC4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_RC4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_RC4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define IO_RC4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define IO_RC4_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define IO_RC4_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.WPUC5
#define IO_RC5_OD                   ODCONCbits.ODCC5
#define IO_RC5_ANS                  ANSELCbits.ANSELC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_RC5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC7 aliases
#define LED_TRIS                 TRISCbits.TRISC7
#define LED_LAT                  LATCbits.LATC7
#define LED_PORT                 PORTCbits.RC7
#define LED_WPU                  WPUCbits.WPUC7
#define LED_OD                   ODCONCbits.ODCC7
#define LED_ANS                  ANSELCbits.ANSELC7
#define LED_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LED_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LED_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LED_GetValue()           PORTCbits.RC7
#define LED_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LED_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LED_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/