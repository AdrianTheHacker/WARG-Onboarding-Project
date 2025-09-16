/*
 * mcp3004.h
 *
 *  Created on: Sep 15, 2025
 *      Author: Adrian Tarantino
 */

#ifndef INC_MCP3004_H_
#define INC_MCP3004_H_

#include <stdint.h>

#include "main.h"

typedef struct {
  int *control_gpio_port;
  int control_gpio_pin;
  SPI_HandleTypeDef *spi_handler;
} mcp3004_hardware_configuration_t;

typedef struct {
  uint16_t value;
} mcp3004_data_t;

static uint8_t open(mcp3004_hardware_configuration_t *mcp3004_hardware_configuration);
static uint8_t close(mcp3004_hardware_configuration_t *mcp3004_hardware_configuration); 
static uint8_t read(mcp3004_hardware_configuration_t *mcp3004_hardware_configuration, mcp3004_data_t* mcp3004_data);
static uint8_t select_channel(mcp3004_hardware_configuration_t *mcp3004_hardware_configuration, mcp3004_data_t *mcp3004_data, uint8_t channel);

#endif /* INC_MCP3004_H_ */
