/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for a Generic STM32F103 board.
 */

/*
 * Board identifier.
 */
#define BOARD_GOOSE60_REV1
#define BOARD_NAME              "jykb goose60 rev-1 STM32F103C8T6 board - stm32duino bootloader"

/*
 * Board frequencies.
 */
#define STM32_LSECLK            32768
#define STM32_HSECLK            8000000

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
#define STM32F103xB

/*
 * IO pins assignments
 */

/* on-board */

#define GPIOA_LED               8
#define GPIOD_OSC_IN            0
#define GPIOD_OSC_OUT           1

/* In case your board has a "USB enable" hardware
   controlled by a pin, define it here. (It could be just
   a 1.5k resistor connected to D+ line.)
*/

#define GPIO_USB_DISC           2
#define GPIO_USB_DISC_PORT      GPIOB

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 *
 * The digits have the following meaning:
 *   0 - Analog input.
 *   1 - Push Pull output 10MHz.
 *   2 - Push Pull output 2MHz.
 *   3 - Push Pull output 50MHz.
 *   4 - Digital input.
 *   5 - Open Drain output 10MHz.
 *   6 - Open Drain output 2MHz.
 *   7 - Open Drain output 50MHz.
 *   8 - Digital input with PullUp or PullDown resistor depending on ODR.
 *   9 - Alternate Push Pull output 10MHz.
 *   A - Alternate Push Pull output 2MHz.
 *   B - Alternate Push Pull output 50MHz.
 *   C - Reserved.
 *   D - Alternate Open Drain output 10MHz.
 *   E - Alternate Open Drain output 2MHz.
 *   F - Alternate Open Drain output 50MHz.
 * Please refer to the STM32 Reference Manual for details.
 */

/*
 * Port A setup.
 * Everything input with pull-up except:
 * PA0  - Push Pull output  (row1)
 * PA1  - Normal input      (PA1)
 * PA2  - Push Pull output  (row3)
 * PA3  - Push Pull output  (row5)
 * PA4  - Normal input      (PA4)
 * PA5  - Alternate output  (SCK)
 * PA6  - Normal input      (MISO)
 * PA7  - Alternate output  (MOSI)
 * PA8  - Push Pull output  (CAPS_LED)
 * PA9  - Alternate output  (USART1 TX).
 * PA10 - Normal input      (USART1 RX).
 * PA11 - Normal input      (USB-)
 * PA12 - Normal input      (USB+)
 * PA13 - SWDIO
 * PA14 - SWCLK
 * PA15 - Push Pull output  (row4)
 */
#define VAL_GPIOACRL            0xB4B83383      /*  PA7...PA0 */
#define VAL_GPIOACRH            0x388444B3      /* PA15...PA8 */
#define VAL_GPIOAODR            0xFFFFFFFF

/*
 * Port B setup.
 * Everything input with pull-up except:
 * PB10    - Push Pull output  (USB switch).
 *
 * PB0     - Normal input      (row11)
 * PB1     - Normal input      (row12)
 * PB2     - Push Pull output  (USBEN)
 * PB3     - Normal input      (col5)
 * PB4     - Normal input      (col6)
 * PB5     - Normal input      (col7)
 * PB6     - Normal input      (col8)
 * PB7     - Normal input      (col9)
 * PB8     - Push Pull output  (row2)
 * PB9     - Normal input      (col10)
 * PB10    - Normal input      (col14)
 * PB11    - Normal input      (col13)
 * PB12    - Normal input      (col3)
 * PB13    - Normal input      (col2)
 * PB14    - Normal input      (col1)
 * PB15    - Normal input      (col4)
 */
#define VAL_GPIOBCRL            0x88888388      /*  PB7...PB0 */
#define VAL_GPIOBCRH            0x88888883      /* PB15...PB8 */
#define VAL_GPIOBODR            0xFFFFFFFF

/*
 * Port C setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOCCRL            0x88888888      /*  PC7...PC0 */
#define VAL_GPIOCCRH            0x88888888      /* PC15...PC8 */
#define VAL_GPIOCODR            0xFFFFFFFF

/*
 * Port D setup.
 * Everything input with pull-up except:
 * PD0  - Normal input (XTAL).
 * PD1  - Normal input (XTAL).
 */
#define VAL_GPIODCRL            0x88888844      /*  PD7...PD0 */
#define VAL_GPIODCRH            0x88888888      /* PD15...PD8 */
#define VAL_GPIODODR            0xFFFFFFFF

/*
 * Port E setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOECRL            0x88888888      /*  PE7...PE0 */
#define VAL_GPIOECRH            0x88888888      /* PE15...PE8 */
#define VAL_GPIOEODR            0xFFFFFFFF

/*
 * USB bus activation macro, required by the USB driver.
 */
/* The point is that most of the generic STM32F103* boards
   have a 1.5k resistor connected on one end to the D+ line
   and on the other end to some pin. Or even a slightly more
   complicated "USB enable" circuit, controlled by a pin.
   That should go here.

   However on some boards (e.g. one that I have), there's no
   such hardware. In which case it's better to not do anything.
*/

#define usb_lld_connect_bus(usbp)       palClearPad(GPIO_USB_DISC_PORT, GPIO_USB_DISC)


/*
 * USB bus de-activation macro, required by the USB driver.
 */

#define usb_lld_disconnect_bus(usbp)    palSetPad(GPIO_USB_DISC_PORT, GPIO_USB_DISC)


#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
