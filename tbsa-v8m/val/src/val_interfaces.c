/** @file
 * Copyright (c) 2018, Arm Limited or its affiliates. All rights reserved.
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

#include "val_interfaces.h"

/* Secure structure with VAL APIs to be used by test/s */
const tbsa_val_api_t tbsa_val_s_api = {
    .print                     = val_print,
    .set_status                = val_set_status,
    .get_status                = val_get_status,
    .err_check_set             = val_err_check_set,
    .report_status             = val_report_status,
    .memcpy                    = val_memcpy,
    .execute_in_trusted_mode   = val_execute_in_trusted_mode,
    .nvram_read                = val_nvram_read,
    .nvram_write               = val_nvram_write,
    .system_reset              = val_system_reset,
    .system_reset_type         = val_system_reset_type,
    .firmware_version_update   = val_firmware_version_update,
    .firmware_version_read     = val_firmware_version_read,
    .test_initialize           = val_test_initialize,
    .mem_reg_read              = val_mem_reg_read,
    .mem_read                  = val_mem_read,
    .mem_reg_write             = val_mem_reg_write,
    .mem_write                 = val_mem_write,
    .is_secure_address         = val_is_secure_address,
    .interrupt_setup_handler   = val_interrupt_setup_handler,
    .interrupt_restore_handler = val_interrupt_restore_handler,
    .interrupt_route           = val_interrupt_route,
    .interrupt_disable         = val_interrupt_disable,
    .interrupt_enable          = val_interrupt_enable,
    .interrupt_set_pending     = val_interrupt_set_pending,
    .interrupt_clear_pending   = val_interrupt_clear_pending,
    .interrupt_get_pending_status = val_interrupt_get_pending_status,
    .target_get_config         = val_target_get_config,
    .timer_init                = val_timer_init,
    .timer_enable              = val_timer_enable,
    .timer_disable             = val_timer_disable,
    .timer_interrupt_clear     = val_timer_interrupt_clear,
    .wd_timer_init             = val_wd_timer_init,
    .wd_timer_enable           = val_wd_timer_enable,
    .wd_timer_disable          = val_wd_timer_disable,
    .is_wd_timer_enabled       = val_is_wd_timer_enabled,
    .crypto_key_generate       = val_crypto_key_generate,
    .fuse_get_lcs              = val_fuse_get_lcs,
    .crypto_validate_public_key= val_crypto_validate_public_key,
    .crypto_get_key_info       = val_crypto_get_key_info,
    .crypto_set_base_addr      = val_crypto_set_base_addr,
    .crypto_revoke_key         = val_crypto_revoke_key,
    .fuse_ops                  = val_fuse_ops,
    .get_fuse_info             = val_get_fuse_info,
    .debug_get_status          = val_debug_get_status,
    .debug_set_status          = val_debug_set_status,
    .dpm_set_state             = val_dpm_set_state,
    .dpm_get_state             = val_dpm_get_state,
    .dpm_set_access_ns_only    = val_dpm_set_access_ns_only,
    .mpc_configure_security_attribute    = val_mpc_configure_security_attribute,
};

/* NSC entry functions(to Trusted APIs) to be used by Non-trusted test/s */
__attribute__((section(".tbsa_ns_data")))
const tbsa_val_api_t tbsa_val_ns_api = {
    .print                     = val_print_nsc,
    .set_status                = val_set_status_nsc,
    .get_status                = val_get_status_nsc,
    .err_check_set             = val_err_check_set_nsc,
    .report_status             = val_report_status_nsc,
    .memcpy                    = val_memcpy_nsc,
    .execute_in_trusted_mode   = val_execute_in_trusted_mode_nsc,
    .nvram_read                = val_nvram_read_nsc,
    .nvram_write               = val_nvram_write_nsc,
    .system_reset              = val_system_reset_nsc,
    .system_reset_type         = val_system_reset_type_nsc,
    .firmware_version_update   = val_firmware_version_update_nsc,
    .firmware_version_read     = val_firmware_version_read_nsc,
    .test_initialize           = val_test_initialize_nsc,
    .mem_reg_read              = val_mem_reg_read_nsc,
    .mem_read                  = val_mem_read_nsc,
    .mem_reg_write             = val_mem_reg_write_nsc,
    .mem_write                 = val_mem_write_nsc,
    .is_secure_address         = val_is_secure_address_nsc,
    .interrupt_setup_handler   = val_interrupt_setup_handler_nsc,
    .interrupt_restore_handler = val_interrupt_restore_handler_nsc,
    .interrupt_route           = val_interrupt_route_nsc,
    .interrupt_disable         = val_interrupt_disable_nsc,
    .interrupt_enable          = val_interrupt_enable_nsc,
    .interrupt_set_pending     = val_interrupt_set_pending_nsc,
    .interrupt_clear_pending   = val_interrupt_clear_pending_nsc,
    .interrupt_get_pending_status = val_interrupt_get_pending_status_nsc,
    .target_get_config         = val_target_get_config_nsc,
    .timer_init                = val_timer_init_nsc,
    .timer_enable              = val_timer_enable_nsc,
    .timer_disable             = val_timer_disable_nsc,
    .timer_interrupt_clear     = val_timer_interrupt_clear_nsc,
    .wd_timer_init             = val_wd_timer_init_nsc,
    .wd_timer_enable           = val_wd_timer_enable_nsc,
    .wd_timer_disable          = val_wd_timer_disable_nsc,
    .is_wd_timer_enabled       = val_is_wd_timer_enabled_nsc,
    .crypto_key_generate       = val_crypto_key_generate_nsc,
    .fuse_get_lcs              = val_fuse_get_lcs_nsc,
    .crypto_validate_public_key= val_crypto_validate_public_key_nsc,
    .get_fuse_info             = val_get_fuse_info_nsc,
    .crypto_get_key_info       = val_crypto_get_key_info_nsc,
    .crypto_set_base_addr      = val_crypto_set_base_addr_nsc,
    .crypto_revoke_key         = val_crypto_revoke_key_nsc,
    .fuse_ops                  = val_fuse_ops_nsc,
    .debug_get_status          = val_debug_get_status_nsc,
    .debug_set_status          = val_debug_set_status_nsc,
    .dpm_set_state             = val_dpm_set_state_nsc,
    .dpm_get_state             = val_dpm_get_state_nsc,
    .dpm_set_access_ns_only    = val_dpm_set_access_ns_only_nsc,
    .mpc_configure_security_attribute    = val_mpc_configure_security_attribute_nsc,
};
