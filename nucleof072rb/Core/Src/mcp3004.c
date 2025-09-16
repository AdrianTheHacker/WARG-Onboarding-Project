/*
 * mcp3004.c
 *
 *  Created on: Sep 15, 2025
 *      Author: Adrian Tarantino
 */

#include <stdint.h>

#include "mcp3004.h"

static uint8_t open(mcp3004_hardware_configuration_t *mcp3004_hardware_configuration) {
	HAL_GPIO_WritePin(mcp3004_hardware_configuration->control_gpio_port, mcp3004_hardware_configuration->control_gpio_pin, GPIO_PIN_RESET);
	return 0;
}

static uint8_t close(mcp3004_hardware_configuration_t *mcp3004_hardware_configuration) {
	HAL_GPIO_WritePin(mcp3004_hardware_configuration->control_gpio_port, mcp3004_hardware_configuration->control_gpio_pin, GPIO_PIN_SET);
	return 0;
}

static uint8_t read(mcp3004_hardware_configuration_t *mcp3004_hardware_configuration, mcp3004_data_t* mcp3004_data) {
	const uint8_t BUFFER_LENGTH = 2;
	uint8_t buffer[2];

	HAL_SPI_Receive(mcp3004_hardware_configuration->spi_handler, buffer, BUFFER_LENGTH, 1000);
	mcp3004_data->value = (buffer[1] << 8) + buffer[0];
	return 0;
}

static uint8_t select_channel(mcp3004_hardware_configuration_t *mcp3004_hardware_configuration, mcp3004_data_t *mcp3004_data, uint8_t channel) {
	const uint8_t BUFFER_LENGTH = 2;
	uint8_t buffer[2];

	buffer[0] = 1;
	buffer[1] = 128 + (channel << 4);

	HAL_SPI_Transmit(mcp3004_hardware_configuration->spi_handler, buffer, BUFFER_LENGTH, 1000);
	return 0;
}