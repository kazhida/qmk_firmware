/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef QMK_FIRMWARE_TI_IOX_16BIT_H
#define QMK_FIRMWARE_TI_IOX_16BIT_H

#define ALL_OUTPUT 0
#define ALL_INPUT 0xFF
#define ALL_LOW 0
#define ALL_HIGH 0xFF

void pca9555_init(uint8_t slave_addr);

void pca9555_set_config(uint8_t slave_addr, uint8_t port, uint8_t conf);

void pca9555_set_output(uint8_t slave_addr, uint8_t port, uint8_t conf);

uint8_t pca9555_readPins(uint8_t slave_addr, uint8_t port);



#endif //QMK_FIRMWARE_TI_IOX_16BIT_H
