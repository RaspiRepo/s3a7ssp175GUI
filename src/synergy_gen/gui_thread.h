/* generated thread header file - do not edit */
#ifndef GUI_THREAD_H_
#define GUI_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
extern "C" void gui_thread_entry(void);
#else
extern void gui_thread_entry(void);
#endif
#include "r_dmac.h"
#include "r_transfer_api.h"
#include "r_gpt.h"
#include "r_timer_api.h"
#include "r_icu.h"
#include "r_external_irq_api.h"
#include "sf_external_irq.h"
#include "r_dtc.h"
#include "r_transfer_api.h"
#include "r_riic.h"
#include "r_i2c_api.h"
#include "sf_touch_panel_i2c.h"
#include "sf_touch_panel_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/* Transfer on DMAC Instance. */
extern const transfer_instance_t g_transfer;
#ifndef dma_callback
void dma_callback(transfer_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_Blacklight_PWM;
#ifndef NULL
void NULL(timer_callback_args_t *p_args);
#endif
/* External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq1;
#ifndef NULL
void NULL(external_irq_callback_args_t *p_args);
#endif
/** SF External IRQ on SF External IRQ Instance. */
extern const sf_external_irq_instance_t g_sf_external_irq0;
/* Transfer on DTC Instance. */
extern const transfer_instance_t g_transfer1;
#ifndef NULL
void NULL(transfer_callback_args_t *p_args);
#endif
/* Transfer on DTC Instance. */
extern const transfer_instance_t g_transfer0;
#ifndef NULL
void NULL(transfer_callback_args_t *p_args);
#endif
extern const i2c_cfg_t g_i2c0_cfg;
/** I2C on RIIC Instance. */
extern const i2c_master_instance_t g_i2c0;
#ifndef NULL
void NULL(i2c_callback_args_t *p_args);
#endif

extern riic_instance_ctrl_t g_i2c0_ctrl;
extern const riic_extended_cfg g_i2c0_extend;
#define SYNERGY_NOT_DEFINED (1)            
#if (SYNERGY_NOT_DEFINED == g_transfer0)
#define g_i2c0_P_TRANSFER_TX (NULL)
#else
#define g_i2c0_P_TRANSFER_TX (&g_transfer0)
#endif
#if (SYNERGY_NOT_DEFINED == g_transfer1)
#define g_i2c0_P_TRANSFER_RX (NULL)
#else
#define g_i2c0_P_TRANSFER_RX (&g_transfer1)
#endif
#undef SYNERGY_NOT_DEFINED
#define g_i2c0_P_EXTEND (&g_i2c0_extend)
/** SF Touch Panel on SF Touch Panel I2C Instance. */
extern const sf_touch_panel_instance_t g_sf_touch_panel_i2c0;
/** Messaging Framework Instance */
extern const sf_message_instance_t g_sf_message0;
void g_sf_touch_panel_i2c0_err_callback(void *p_instance, void *p_data);
void sf_touch_panel_i2c_init0(void);
extern TX_MUTEX g_lcd_mutex;
extern TX_EVENT_FLAGS_GROUP g_provision_lock;
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* GUI_THREAD_H_ */
