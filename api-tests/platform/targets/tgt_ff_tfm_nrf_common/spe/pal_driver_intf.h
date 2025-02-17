 /** @file
  * Copyright (c) 2019-2020, Arm Limited or its affiliates. All rights reserved.
  * SPDX-License-Identifier : Apache-2.0
  *
  * Copyright (c) 2021 Nordic Semiconductor ASA.
  * SPDX-License-Identifier : Apache-2.0
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  *  http://www.apache.org/licenses/LICENSE-2.0
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
 **/

#ifndef _PAL_DRIVER_INTF_H_
#define _PAL_DRIVER_INTF_H_

#include "pal_uart.h"
#include "pal_nvmem.h"
#include "pal_wd_cmsdk.h"

/* Following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */

/**
  * @brief Event generator unit type
  */
typedef struct {                                /*!< (@ 0x4001B000) EGU0_NS Structure                                          */
  __OM  uint32_t  TASKS_TRIGGER[16];            /*!< (@ 0x00000000) Description collection: Trigger n for triggering
                                                                    the corresponding TRIGGERED[n] event                       */
  __IM  uint32_t  RESERVED[16];
  __IOM uint32_t  SUBSCRIBE_TRIGGER[16];        /*!< (@ 0x00000080) Description collection: Subscribe configuration
                                                                    for task TRIGGER[n]                                        */
  __IM  uint32_t  RESERVED1[16];
  __IOM uint32_t  EVENTS_TRIGGERED[16];         /*!< (@ 0x00000100) Description collection: Event number n generated
                                                                    by triggering the corresponding TRIGGER[n]
                                                                    task                                                       */
  __IM  uint32_t  RESERVED2[16];
  __IOM uint32_t  PUBLISH_TRIGGERED[16];        /*!< (@ 0x00000180) Description collection: Publish configuration
                                                                    for event TRIGGERED[n]                                     */
  __IM  uint32_t  RESERVED3[80];
  __IOM uint32_t  INTEN;                        /*!< (@ 0x00000300) Enable or disable interrupt                                */
  __IOM uint32_t  INTENSET;                     /*!< (@ 0x00000304) Enable interrupt                                           */
  __IOM uint32_t  INTENCLR;                     /*!< (@ 0x00000308) Disable interrupt                                          */
} NRF_EGU_Type;                                 /*!< Size = 780 (0x30c)                                                        */

/* Define EGU peripheral to be used in tests */
#define NRF_EGU5_S ((NRF_EGU_Type*) 0x50020000UL)
#define NRF_EGU5   (NRF_EGU5_S)


void pal_uart_init(uint32_t uart_base_addr);
void pal_print(const char *str, int32_t data);
int pal_nvmem_write(addr_t base, uint32_t offset, void *buffer, int size);
int pal_nvmem_read(addr_t base, uint32_t offset, void *buffer, int size);
int pal_wd_timer_init(addr_t base_addr, uint32_t time_us, uint32_t timer_tick_us);
int pal_wd_timer_enable(addr_t base_addr);
int pal_wd_timer_disable(addr_t base_addr);
int pal_wd_timer_is_enabled(addr_t base_addr);
void pal_generate_interrupt(void);
void pal_disable_interrupt(void);
#endif /* _PAL_DRIVER_INTF_H_ */
