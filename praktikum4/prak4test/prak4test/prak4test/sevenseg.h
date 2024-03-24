/*
 * sevenseg.h
 *
 * Created: 03.12.2023 14:07:01
 *  Author: welly
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

#ifndef SEVENSEG_H
#define SEVENSEG_H

void out(int x);

#endif