/*
 * utils.c
 *
 *  Created on: Feb 24, 2020
 *      Author: bacel
 */

#include "utils.h"

uint32_t map(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
