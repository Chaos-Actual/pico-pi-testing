/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include "pico/stdlib.h"
#include "mine.h"
#include "lcd.h"
#include "sun.h"
#include <time.h>

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    stdio_init_all();
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);
    sleep_ms(11950);
    printf("Here1");
    time_t tm = time(NULL);
    printf("Here2");
    unsigned int sunrise;
    unsigned int sunset;
    getRiseSet(tm, &sunrise, &sunset,Sun); 

    printf("/n sunrise %s",ctime(sunrise));

    printf("Here5\n");


    

    
    i2c_init(i2c_default,100*1000);
    
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);

    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    
    //  Make the I2C pins available to picotool
   // bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN,GPIO_FUNC_I2C));

    lcd_init();
    printf("hell0 6");
    char lcd_text[18] = "SUP BITCH!";
    lcd_string(lcd_text);

    while (true) {
        mytest();
        printf("\n %s",time);
        printf("hello this is the const %d \n",MAX_CHARS);
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }
#endif
}

