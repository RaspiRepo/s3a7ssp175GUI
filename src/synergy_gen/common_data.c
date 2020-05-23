/* generated common source file - do not edit */
#include "common_data.h"
#if defined(__ICCARM__)
#define g_sf_message0_err_callback_WEAK_ATTRIBUTE
#pragma weak g_sf_message0_err_callback  = g_sf_message0_err_callback_internal
#elif defined(__GNUC__)
#define g_sf_message0_err_callback_WEAK_ATTRIBUTE   __attribute__ ((weak, alias("g_sf_message0_err_callback_internal")))
#endif
void g_sf_message0_err_callback(void *p_instance, void *p_data)
g_sf_message0_err_callback_WEAK_ATTRIBUTE;
extern sf_message_subscriber_list_t *p_subscriber_lists[];
sf_message_instance_ctrl_t g_sf_message0_ctrl;
static uint8_t g_sf_message0_work_buffer[2048];
/* Configures the messaging framework */
sf_message_cfg_t g_sf_message0_cfg =
{ .p_work_memory_start = &g_sf_message0_work_buffer, .work_memory_size_bytes = 2048, .buffer_size =
          sizeof(sf_message_payload_t),
  .pp_subscriber_lists = p_subscriber_lists, .p_block_pool_name = (uint8_t *) "sf_msg_blk_pool" };
/* Instance structure to use this module. */
const sf_message_instance_t g_sf_message0 =
{ .p_ctrl = &g_sf_message0_ctrl, .p_cfg = &g_sf_message0_cfg, .p_api = &g_sf_message_on_sf_message };
/*******************************************************************************************************************//**
 * @brief      This is a weak example initialization error function.  It should be overridden by defining a user  function 
 *             with the prototype below.
 *             - void g_sf_message0_err_callback(void * p_instance, void * p_data)
 *
 * @param[in]  p_instance arguments used to identify which instance caused the error and p_data Callback arguments used to identify what error caused the callback.
 **********************************************************************************************************************/
void g_sf_message0_err_callback_internal(void *p_instance, void *p_data);
void g_sf_message0_err_callback_internal(void *p_instance, void *p_data)
{
    /** Suppress compiler warning for not using parameters. */
    SSP_PARAMETER_NOT_USED (p_instance);
    SSP_PARAMETER_NOT_USED (p_data);

    /** An error has occurred. Please check function arguments for more information. */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR (0);
}
/*******************************************************************************************************************//**
 * @brief     Initialization function that the user can choose to have called automatically during thread entry.
 *            The user can call this function at a later time if desired using the prototype below.

 *            - void sf_message_init0(void)
 **********************************************************************************************************************/
void sf_message_init0(void)
{
    ssp_err_t ssp_err_g_sf_message0;

    /* Initializes Messaging Framework Queues */
    g_message_init ();

    /* Opens the messaging framework */
    ssp_err_g_sf_message0 = g_sf_message0.p_api->open (g_sf_message0.p_ctrl, g_sf_message0.p_cfg);
    if (SSP_SUCCESS != ssp_err_g_sf_message0)
    {
        /* Error returns, check the cause. */
        g_sf_message0_err_callback ((void *) &g_sf_message0, &ssp_err_g_sf_message0);
    }
}
/* Instance structure to use this module. */
const fmi_instance_t g_fmi =
{ .p_api = &g_fmi_on_fmi };
const elc_instance_t g_elc =
{ .p_api = &g_elc_on_elc, .p_cfg = NULL };
const ioport_instance_t g_ioport =
{ .p_api = &g_ioport_on_ioport, .p_cfg = NULL };
const cgc_instance_t g_cgc =
{ .p_api = &g_cgc_on_cgc, .p_cfg = NULL };
void g_common_init(void)
{
    /** Call initialization function if user has selected to do so. */
#if (1)
    sf_message_init0 ();
#endif
}
