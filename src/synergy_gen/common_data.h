/* generated common header file - do not edit */
#ifndef COMMON_DATA_H_
#define COMMON_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "sf_message.h"
#include "sf_message_payloads.h"
#include "r_fmi.h"
#include "r_fmi_api.h"
#include "r_elc.h"
#include "r_elc_api.h"
#include "r_ioport.h"
#include "r_ioport_api.h"
#include "r_cgc.h"
#include "r_cgc_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
extern void g_message_init(void);

/* SF Message on SF Message Instance. */
extern const sf_message_instance_t g_sf_message0;
void g_sf_message0_err_callback(void *p_instance, void *p_data);
void sf_message_init0(void);
/** FMI on FMI Instance. */
extern const fmi_instance_t g_fmi;
/** ELC Instance */
extern const elc_instance_t g_elc;
/** IOPORT Instance */
extern const ioport_instance_t g_ioport;
/** CGC Instance */
extern const cgc_instance_t g_cgc;
void g_common_init(void);
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* COMMON_DATA_H_ */
