/* generated thread source file - do not edit */
#include "gui_thread.h"

TX_THREAD gui_thread;
void gui_thread_create(void);
static void gui_thread_func(ULONG thread_input);
static uint8_t gui_thread_stack[2048] BSP_PLACE_IN_SECTION_V2(".stack.gui_thread") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
#if (8) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_transfer) && !defined(SSP_SUPPRESS_ISR_DMACELC_EVENT_ELC_SOFTWARE_EVENT_0)
SSP_VECTOR_DEFINE_CHAN(dmac_int_isr, DMAC, INT, 0);
#endif
#endif
dmac_instance_ctrl_t g_transfer_ctrl;
transfer_info_t g_transfer_info =
{ .dest_addr_mode = TRANSFER_ADDR_MODE_FIXED,
  .repeat_area = TRANSFER_REPEAT_AREA_DESTINATION,
  .irq = TRANSFER_IRQ_EACH,
  .chain_mode = TRANSFER_CHAIN_MODE_DISABLED,
  .src_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
  .size = TRANSFER_SIZE_2_BYTE,
  .mode = TRANSFER_MODE_BLOCK,
  .p_dest = (void *) 0x80000004,
  .p_src = (void const *) NULL,
  .num_blocks = 1,
  .length = 0, };
const transfer_on_dmac_cfg_t g_transfer_extend =
{ .channel = 0, .offset_byte = 0, };
const transfer_cfg_t g_transfer_cfg =
{ .p_info = &g_transfer_info, .activation_source = ELC_EVENT_ELC_SOFTWARE_EVENT_0, .auto_enable = false, .p_callback =
          dma_callback,
  .p_context = &g_transfer, .irq_ipl = (8), .p_extend = &g_transfer_extend, };
/* Instance structure to use this module. */
const transfer_instance_t g_transfer =
{ .p_ctrl = &g_transfer_ctrl, .p_cfg = &g_transfer_cfg, .p_api = &g_transfer_on_dmac };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_Blacklight_PWM) && !defined(SSP_SUPPRESS_ISR_GPT2)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 2);
#endif
#endif
static gpt_instance_ctrl_t g_Blacklight_PWM_ctrl;
static const timer_on_gpt_cfg_t g_Blacklight_PWM_extend =
{ .gtioca =
{ .output_enabled = true, .stop_level = GPT_PIN_LEVEL_LOW },
  .gtiocb =
  { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .shortest_pwm_signal = GPT_SHORTEST_LEVEL_OFF, };
static const timer_cfg_t g_Blacklight_PWM_cfg =
{ .mode = TIMER_MODE_PWM, .period = 1, .unit = TIMER_UNIT_FREQUENCY_KHZ, .duty_cycle = 50, .duty_cycle_unit =
          TIMER_PWM_UNIT_PERCENT,
  .channel = 2, .autostart = true, .p_callback = NULL, .p_context = &g_Blacklight_PWM, .p_extend =
          &g_Blacklight_PWM_extend,
  .irq_ipl = (BSP_IRQ_DISABLED), };
/* Instance structure to use this module. */
const timer_instance_t g_Blacklight_PWM =
{ .p_ctrl = &g_Blacklight_PWM_ctrl, .p_cfg = &g_Blacklight_PWM_cfg, .p_api = &g_timer_on_gpt };
#if (8) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_external_irq1) && !defined(SSP_SUPPRESS_ISR_ICU4)
SSP_VECTOR_DEFINE( icu_irq_isr, ICU, IRQ4);
#endif
#endif
static icu_instance_ctrl_t g_external_irq1_ctrl;
static const external_irq_cfg_t g_external_irq1_cfg =
{ .channel = 4,
  .trigger = EXTERNAL_IRQ_TRIG_FALLING,
  .filter_enable = false,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .autostart = true,
  .p_callback = NULL,
  .p_context = &g_external_irq1,
  .p_extend = NULL,
  .irq_ipl = (8), };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq1 =
{ .p_ctrl = &g_external_irq1_ctrl, .p_cfg = &g_external_irq1_cfg, .p_api = &g_external_irq_on_icu };
sf_external_irq_instance_ctrl_t g_sf_external_irq0_ctrl;
const sf_external_irq_cfg_t g_sf_external_irq0_cfg =
{ .event = SF_EXTERNAL_IRQ_EVENT_SEMAPHORE_PUT, .p_lower_lvl_irq = &g_external_irq1, };
/* Instance structure to use this module. */
const sf_external_irq_instance_t g_sf_external_irq0 =
{ .p_ctrl = &g_sf_external_irq0_ctrl, .p_cfg = &g_sf_external_irq0_cfg, .p_api = &g_sf_external_irq_on_sf_external_irq };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_transfer1) && !defined(SSP_SUPPRESS_ISR_DTCELC_EVENT_IIC0_RXI)
#define DTC_ACTIVATION_SRC_ELC_EVENT_IIC0_RXI
#if defined(DTC_ACTIVATION_SRC_ELC_EVENT_ELC_SOFTWARE_EVENT_0) && !defined(DTC_VECTOR_DEFINED_SOFTWARE_EVENT_0)
SSP_VECTOR_DEFINE(elc_software_event_isr, ELC, SOFTWARE_EVENT_0);
#define DTC_VECTOR_DEFINED_SOFTWARE_EVENT_0
#endif
#if defined(DTC_ACTIVATION_SRC_ELC_EVENT_ELC_SOFTWARE_EVENT_1) && !defined(DTC_VECTOR_DEFINED_SOFTWARE_EVENT_1)
SSP_VECTOR_DEFINE(elc_software_event_isr, ELC, SOFTWARE_EVENT_1);
#define DTC_VECTOR_DEFINED_SOFTWARE_EVENT_1
#endif
#endif
#endif

dtc_instance_ctrl_t g_transfer1_ctrl;
transfer_info_t g_transfer1_info =
{ .dest_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
  .repeat_area = TRANSFER_REPEAT_AREA_DESTINATION,
  .irq = TRANSFER_IRQ_END,
  .chain_mode = TRANSFER_CHAIN_MODE_DISABLED,
  .src_addr_mode = TRANSFER_ADDR_MODE_FIXED,
  .size = TRANSFER_SIZE_1_BYTE,
  .mode = TRANSFER_MODE_NORMAL,
  .p_dest = (void *) NULL,
  .p_src = (void const *) NULL,
  .num_blocks = 0,
  .length = 0, };
const transfer_cfg_t g_transfer1_cfg =
{ .p_info = &g_transfer1_info,
  .activation_source = ELC_EVENT_IIC0_RXI,
  .auto_enable = false,
  .p_callback = NULL,
  .p_context = &g_transfer1,
  .irq_ipl = (BSP_IRQ_DISABLED) };
/* Instance structure to use this module. */
const transfer_instance_t g_transfer1 =
{ .p_ctrl = &g_transfer1_ctrl, .p_cfg = &g_transfer1_cfg, .p_api = &g_transfer_on_dtc };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_transfer0) && !defined(SSP_SUPPRESS_ISR_DTCELC_EVENT_IIC0_TXI)
#define DTC_ACTIVATION_SRC_ELC_EVENT_IIC0_TXI
#if defined(DTC_ACTIVATION_SRC_ELC_EVENT_ELC_SOFTWARE_EVENT_0) && !defined(DTC_VECTOR_DEFINED_SOFTWARE_EVENT_0)
SSP_VECTOR_DEFINE(elc_software_event_isr, ELC, SOFTWARE_EVENT_0);
#define DTC_VECTOR_DEFINED_SOFTWARE_EVENT_0
#endif
#if defined(DTC_ACTIVATION_SRC_ELC_EVENT_ELC_SOFTWARE_EVENT_1) && !defined(DTC_VECTOR_DEFINED_SOFTWARE_EVENT_1)
SSP_VECTOR_DEFINE(elc_software_event_isr, ELC, SOFTWARE_EVENT_1);
#define DTC_VECTOR_DEFINED_SOFTWARE_EVENT_1
#endif
#endif
#endif

dtc_instance_ctrl_t g_transfer0_ctrl;
transfer_info_t g_transfer0_info =
{ .dest_addr_mode = TRANSFER_ADDR_MODE_FIXED,
  .repeat_area = TRANSFER_REPEAT_AREA_SOURCE,
  .irq = TRANSFER_IRQ_END,
  .chain_mode = TRANSFER_CHAIN_MODE_DISABLED,
  .src_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
  .size = TRANSFER_SIZE_1_BYTE,
  .mode = TRANSFER_MODE_NORMAL,
  .p_dest = (void *) NULL,
  .p_src = (void const *) NULL,
  .num_blocks = 0,
  .length = 0, };
const transfer_cfg_t g_transfer0_cfg =
{ .p_info = &g_transfer0_info,
  .activation_source = ELC_EVENT_IIC0_TXI,
  .auto_enable = false,
  .p_callback = NULL,
  .p_context = &g_transfer0,
  .irq_ipl = (BSP_IRQ_DISABLED) };
/* Instance structure to use this module. */
const transfer_instance_t g_transfer0 =
{ .p_ctrl = &g_transfer0_ctrl, .p_cfg = &g_transfer0_cfg, .p_api = &g_transfer_on_dtc };
#if !defined(SSP_SUPPRESS_ISR_g_i2c0) && !defined(SSP_SUPPRESS_ISR_IIC0)
SSP_VECTOR_DEFINE_CHAN(iic_rxi_isr, IIC, RXI, 0);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_i2c0) && !defined(SSP_SUPPRESS_ISR_IIC0)
SSP_VECTOR_DEFINE_CHAN(iic_txi_isr, IIC, TXI, 0);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_i2c0) && !defined(SSP_SUPPRESS_ISR_IIC0)
SSP_VECTOR_DEFINE_CHAN(iic_tei_isr, IIC, TEI, 0);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_i2c0) && !defined(SSP_SUPPRESS_ISR_IIC0)
SSP_VECTOR_DEFINE_CHAN(iic_eri_isr, IIC, ERI, 0);
#endif
riic_instance_ctrl_t g_i2c0_ctrl;
const riic_extended_cfg g_i2c0_extend =
{ .timeout_mode = RIIC_TIMEOUT_MODE_SHORT, };
const i2c_cfg_t g_i2c0_cfg =
{ .channel = 0, .rate = I2C_RATE_STANDARD, .slave = 0x48, .addr_mode = I2C_ADDR_MODE_7BIT, .sda_delay = 300,
#define SYNERGY_NOT_DEFINED (1)            
#if (SYNERGY_NOT_DEFINED == g_transfer0)
  .p_transfer_tx = NULL,
#else
  .p_transfer_tx = &g_transfer0,
#endif
#if (SYNERGY_NOT_DEFINED == g_transfer1)
  .p_transfer_rx = NULL,
#else
  .p_transfer_rx = &g_transfer1,
#endif
#undef SYNERGY_NOT_DEFINED	
  .p_callback = NULL,
  .p_context = (void *) &g_i2c0, .rxi_ipl = (12), .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (12), .p_extend =
          &g_i2c0_extend, };
/* Instance structure to use this module. */
const i2c_master_instance_t g_i2c0 =
{ .p_ctrl = &g_i2c0_ctrl, .p_cfg = &g_i2c0_cfg, .p_api = &g_i2c_master_on_riic };
#if defined(__ICCARM__)
#define g_sf_touch_panel_i2c0_err_callback_WEAK_ATTRIBUTE
#pragma weak g_sf_touch_panel_i2c0_err_callback  = g_sf_touch_panel_i2c0_err_callback_internal
#elif defined(__GNUC__)
#define g_sf_touch_panel_i2c0_err_callback_WEAK_ATTRIBUTE   __attribute__ ((weak, alias("g_sf_touch_panel_i2c0_err_callback_internal")))
#endif
void g_sf_touch_panel_i2c0_err_callback(void *p_instance, void *p_data)
g_sf_touch_panel_i2c0_err_callback_WEAK_ATTRIBUTE;
sf_touch_panel_i2c_instance_ctrl_t g_sf_touch_panel_i2c0_ctrl;
const sf_touch_panel_i2c_cfg_t g_sf_touch_panel_i2c0_cfg_extend =
{ .p_lower_lvl_i2c = &g_i2c0, .p_lower_lvl_irq = &g_sf_external_irq0, .pin = IOPORT_PORT_01_PIN_15, .p_chip =
          &g_sf_touch_panel_i2c_chip_sx8654, };
const sf_touch_panel_cfg_t g_sf_touch_panel_i2c0_cfg =
{ .hsize_pixels = 240, .vsize_pixels = 320, .priority = 3, .update_hz = 10, .p_message = &g_sf_message0, .p_extend =
          &g_sf_touch_panel_i2c0_cfg_extend,
  .event_class_instance = 0, .rotation_angle = 0 };
/* Instance structure to use this module. */
const sf_touch_panel_instance_t g_sf_touch_panel_i2c0 =
{ .p_ctrl = &g_sf_touch_panel_i2c0_ctrl, .p_cfg = &g_sf_touch_panel_i2c0_cfg, .p_api =
          &g_sf_touch_panel_on_sf_touch_panel_i2c };
/*******************************************************************************************************************//**
 * @brief      Initialization function that the user can choose to have called automatically during thread entry.
 *             The user can call this function at a later time if desired using the prototype below.

 *             - void g_sf_touch_panel_i2c0_err_callback(void * p_instance, void * p_data)
 *
 * @param[in]  p_instance arguments used to identify which instance caused the error and p_data Callback arguments used to identify what error caused the callback.
 **********************************************************************************************************************/
void g_sf_touch_panel_i2c0_err_callback_internal(void *p_instance, void *p_data);
void g_sf_touch_panel_i2c0_err_callback_internal(void *p_instance, void *p_data)
{
    /** Suppress compiler warning for not using parameters. */
    SSP_PARAMETER_NOT_USED (p_instance);
    SSP_PARAMETER_NOT_USED (p_data);

    /** An error has occurred. Please check function arguments for more information. */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR (0);
}
/*******************************************************************************************************************//**
 * @brief     This is sf touch panel initialization function. User Can call this function in the application if required with the below mentioned prototype.
 *            - void sf_touch_panel_i2c_init0(void)
 **********************************************************************************************************************/
void sf_touch_panel_i2c_init0(void)
{
    ssp_err_t ssp_err_g_sf_touch_panel_i2c0;
    ssp_err_g_sf_touch_panel_i2c0 = g_sf_touch_panel_i2c0.p_api->open (g_sf_touch_panel_i2c0.p_ctrl,
                                                                       g_sf_touch_panel_i2c0.p_cfg);
    if (SSP_SUCCESS != ssp_err_g_sf_touch_panel_i2c0)
    {
        g_sf_touch_panel_i2c0_err_callback ((void *) &g_sf_touch_panel_i2c0, &ssp_err_g_sf_touch_panel_i2c0);
    }
}
TX_MUTEX g_lcd_mutex;
TX_EVENT_FLAGS_GROUP g_provision_lock;
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void gui_thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */
    UINT err_g_lcd_mutex;
    err_g_lcd_mutex = tx_mutex_create (&g_lcd_mutex, (CHAR *) "LCD Mutex", TX_NO_INHERIT);
    if (TX_SUCCESS != err_g_lcd_mutex)
    {
        tx_startup_err_callback (&g_lcd_mutex, 0);
    }
    UINT err_g_provision_lock;
    err_g_provision_lock = tx_event_flags_create (&g_provision_lock, (CHAR *) "New Event Flags");
    if (TX_SUCCESS != err_g_provision_lock)
    {
        tx_startup_err_callback (&g_provision_lock, 0);
    }

    UINT err;
    err = tx_thread_create (&gui_thread, (CHAR *) "GUIThread", gui_thread_func, (ULONG) NULL, &gui_thread_stack, 2048,
                            5, 5, 10, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&gui_thread, 0);
    }
}

static void gui_thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */
    /** Call initialization function if user has selected to do so. */
#if (1)
    sf_touch_panel_i2c_init0 ();
#endif

    /* Enter user code for this thread. */
    gui_thread_entry ();
}
