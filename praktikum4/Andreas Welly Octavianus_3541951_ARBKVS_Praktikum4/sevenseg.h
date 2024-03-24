/*
 * sevenseg.h
 *
 * Created: 09.11.2023 13:59:11
 *  Author: welly
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

#ifndef SEVENSEG_H
#define SEVENSEG_H

void out(int x);

#endif
