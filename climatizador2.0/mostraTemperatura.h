#ifndef _MOSTRA_TEMPERATURA_H
#define _MOSTRA_TEMPERATURA_H

/**************************************************************************************************************************

   Autor: Marcelo Henrique Moraes
   E-mail: marceloh220@hotmail.com
   Copyright (c) 2017 Marcelo Henrique Moraes

   Projeto Casa Sustentavel: Climatizador de AR
   https://github.com/marceloh220/Climatizador.git

   Projeto core Marcelino
   https://github.com/marceloh220/Marcelino.git

   MCU: Atmega328p
   Arduino IDE 1.8.2
   Marcelino Atmega328/p (Arduino/Genuino Uno/Nano)
   F_CPU 16MHz (Cristal externo)

    This application is a free software, you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3.0 of the License, or (at your option) any later version.
    This application is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY, without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    https://www.gnu.org/licenses/gpl-3.0.en.html

***************************************************************************************************************************/

//Funcao que mostra no display a temperaturas
void mostraTemperatura()
{
	display.set(0, 0);                      	//Posiciona cursor na coluna 0 / linha 0
	display.print("T.Ambien:");
	display.print(temperatura.ambiente());
	display.write((uint8_t)0);              	//Mostra caracter simbolo graus
	display.print("C  ");
	display.set(0, 1);                      	//Posiciona cursor na coluna 0 / linha 1
	display.print("T.Refrig:");
	display.print(temperatura.refrigerada());
	display.write((uint8_t)0);              	//Mostra caracter simbolo graus
	display.print("C  ");
}//fim da funcao mostraTemperatura

#endif
