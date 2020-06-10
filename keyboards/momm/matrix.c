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
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <string.h>
#include "matrix.h"
#include "quantum.h"

#include "debug.h"

//---- pca9555.h ----
#define PCA9555_PORT0 0
#define PCA9555_PORT1 1

#define ALL_OUTPUT 0
#define ALL_INPUT 0xFF
#define ALL_LOW 0
#define ALL_HIGH 0xFF

void pca9555_init(uint8_t slave_addr);

void pca9555_set_config(uint8_t slave_addr, uint8_t port, uint8_t conf);

void pca9555_set_output(uint8_t slave_addr, uint8_t port, uint8_t conf);

uint8_t pca9555_readPins(uint8_t slave_addr, uint8_t port);

//---- pca9555.c ----

#include "i2c_master.h"

#define SLAVE_TO_ADDR(n)   (n<<1)
#define TIMEOUT 100

enum {
    CMD_INPUT_0 = 0,
    CMD_INPUT_1,
    CMD_OUTPUT_0,
    CMD_OUTPUT_1,
    CMD_INVERSION_0,
    CMD_INVERSION_1,
    CMD_CONFIG_0,
    CMD_CONFIG_1
};

void pca9555_init(uint8_t slave_addr) {
    static uint8_t s_init = 0;
    if (!s_init) {
        i2c_init();
        s_init=1;
    }

  // TODO: could check device connected
  //i2c_start(SLAVE_TO_ADDR(slave) | I2C_WRITE);
  //i2c_stop();
}

void pca9555_set_config(uint8_t slave_addr, uint8_t port, uint8_t conf) {
  uint8_t addr = SLAVE_TO_ADDR(slave_addr);
  uint8_t cmd = port ? CMD_OUTPUT_1 : CMD_OUTPUT_0;

  i2c_status_t ret = i2c_writeReg(addr, cmd, &conf, sizeof(conf), TIMEOUT);
  if (ret != I2C_STATUS_SUCCESS) {
    print("pca9555_set_config::FAILED\n");
  }
}

void pca9555_set_output(uint8_t slave_addr, uint8_t port, uint8_t conf) {
  uint8_t addr = SLAVE_TO_ADDR(slave_addr);
  uint8_t cmd = port ? CMD_CONFIG_1 : CMD_CONFIG_0;

  i2c_status_t ret = i2c_writeReg(addr, cmd, &conf, sizeof(conf), TIMEOUT);
  if (ret != I2C_STATUS_SUCCESS) {
    print("pca9555_set_output::FAILED\n");
  }
}

uint8_t pca9555_readPins(uint8_t slave_addr, uint8_t port) {
  uint8_t addr = SLAVE_TO_ADDR(slave_addr);
  uint8_t cmd = port ? CMD_INPUT_1 : CMD_INPUT_0;

  uint8_t data = 0;
  i2c_status_t ret = i2c_readReg(addr, cmd, &data, sizeof(data), TIMEOUT);
  if (ret != I2C_STATUS_SUCCESS) {
    print("pca9555_readPins::FAILED\n");
  }
  return data;
}

//_____COMMON__________________________________________________________________
// user-defined overridable functions
__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }
__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }
__attribute__((weak)) void matrix_init_user(void) {}
__attribute__((weak)) void matrix_scan_user(void) {}


//_____COULD BE COMMON_________________________________________________________
/* matrix state(1:on, 0:off) */
/*static*/ matrix_row_t raw_matrix[MATRIX_ROWS];
/*static*/ matrix_row_t matrix[MATRIX_ROWS];

#if (MATRIX_COLS <= 8)
#    define print_matrix_header()  print("\nr/c 01234567\n")
#    define print_matrix_row(row)  print_bin_reverse8(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop(matrix[i])
#    define ROW_SHIFTER ((uint8_t)1)
#elif (MATRIX_COLS <= 16)
#    define print_matrix_header()  print("\nr/c 0123456789ABCDEF\n")
#    define print_matrix_row(row)  print_bin_reverse16(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop16(matrix[i])
#    define ROW_SHIFTER ((uint16_t)1)
#elif (MATRIX_COLS <= 32)
#    define print_matrix_header()  print("\nr/c 0123456789ABCDEF0123456789ABCDEF\n")
#    define print_matrix_row(row)  print_bin_reverse32(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop32(matrix[i])
#    define ROW_SHIFTER  ((uint32_t)1)
#endif

__attribute__ ((weak))
uint8_t matrix_rows(void) {
  return MATRIX_ROWS;
}

__attribute__ ((weak))
uint8_t matrix_cols(void) {
  return MATRIX_COLS;
}

__attribute__ ((weak))
matrix_row_t matrix_get_row(uint8_t row) {
  return matrix[row];
}

__attribute__ ((weak))
uint8_t matrix_key_count(void) {
  uint8_t count = 0;
  for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
    count += matrix_bitpop(i);
  }
  return count;
}

__attribute__ ((weak))
void matrix_print(void) {
  print_matrix_header();

  for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
    phex(row); print(": ");
    print_matrix_row(row);
    print("\n");
  }
}


//_____CUSTOM MATRIX 'LITE'____________________________________________________
__attribute__ ((weak))
void custom_matrix_init(void) {
}

__attribute__ ((weak))
bool custom_matrix_scan(matrix_row_t current_matrix[]) {
  bool changed = true;
  return changed;
}

__attribute__ ((weak))
void matrix_init(void) {

  custom_matrix_init();

  // initialize matrix state: all keys off
  for (uint8_t i=0; i < MATRIX_ROWS; i++) {
    raw_matrix[i] = 0;
    matrix[i] = 0;
  }

  debounce_init(MATRIX_ROWS);

  matrix_init_quantum();
}

__attribute__ ((weak))
uint8_t matrix_scan(void) {
  bool changed = custom_matrix_scan(raw_matrix);

  debounce(raw_matrix, matrix, MATRIX_ROWS, changed);

  matrix_scan_quantum();
  return 1;
}

//---- matrix.c ----
// PCA9555 slave addresses
#define IC1 0x20
#define IC2 0x21

//_____Utility funcs___________________________________________________________

static void init_pins(void) {
  // init all cols high - IC2 all input
  pca9555_set_config(IC2, PCA9555_PORT0, ALL_INPUT);//same as initial state
  pca9555_set_config(IC2, PCA9555_PORT1, ALL_INPUT);//same as initial state

  // init all rows - IC1 port0 input
  pca9555_set_config(IC1, PCA9555_PORT0, ALL_INPUT);//same as initial state
}

static void select_row(uint8_t row) {
  // For the XD84 all rows are on the same IC and port
  // so its safe enough to assume here row == pin
  uint8_t pin = row;
  uint8_t mask = 1 << pin;

  pca9555_set_output(IC1, PCA9555_PORT0, ALL_HIGH & (~mask));
  pca9555_set_config(IC1, PCA9555_PORT0, ALL_INPUT & (~mask));
}

static uint16_t read_cols(void) {
  uint16_t state_1 = pca9555_readPins(IC2, PCA9555_PORT0);
  uint16_t state_2 = pca9555_readPins(IC2, PCA9555_PORT1);

  // For the XD84 all cols are on the same IC and mapped sequentially
  // while this technically gives 16 column reads,
  // the 16th column can never be set so is safely ignored
  return ~((state_2 << 8) | state_1);
}

/*


 */
static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
  // Store last value of row prior to reading
  matrix_row_t last_row_value = current_matrix[current_row];

  // Clear data in matrix row
  current_matrix[current_row] = 0;

  // Select row and wait for row selecton to stabilize
  select_row(current_row);
  wait_us(30);

  current_matrix[current_row] = read_cols();

  // No need to Unselect row as the next `select_row` will blank everything

  return (last_row_value != current_matrix[current_row]);
}

//_____CUSTOM MATRIX IMPLEMENTATION____________________________________________________

void custom_matrix_init(void) {
  pca9555_init(IC1);
  pca9555_init(IC2);

  init_pins();
}

bool custom_matrix_scan(matrix_row_t current_matrix[]) {
  bool changed = false;
  for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
    changed |= read_cols_on_row(current_matrix, current_row);
  }
  return changed;
}