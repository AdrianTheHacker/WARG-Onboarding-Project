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
  GPIO_TypeDef *control_gpio_port;
  int control_gpio_pin;
  SPI_HandleTypeDef *spi_handler;
} mcp3004_hardware_configuration_t;

typedef struct {
  uint16_t value;
} mcp3004_data_t;

uint8_t mcp3004_open(mcp3004_hardware_configuration_t *mcp3004_hardware_configuration);
uint8_t mcp3004_close(mcp3004_hardware_configuration_t *mcp3004_hardware_configuration);
uint8_t mcp3004_read(mcp3004_hardware_configuration_t *mcp3004_hardware_configuration, mcp3004_data_t* mcp3004_data);
uint8_t mcp3004_select_channel(mcp3004_hardware_configuration_t *mcp3004_hardware_configuration, uint8_t channel);

#endif /* INC_MCP3004_H_ */
