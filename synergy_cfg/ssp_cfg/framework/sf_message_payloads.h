/* generated messaging header file - do not edit */
#ifndef SF_MESSAGE_PAYLOADS_H_
#define SF_MESSAGE_PAYLOADS_H_
#include "sf_touch_panel_api.h"
#include "lcd_display_api.h"
typedef union u_sf_message_payload
{
    sf_touch_panel_payload_t sf_touch_panel_payload;
    lcd_display_payload_t lcd_display_payload;
} sf_message_payload_t;
#endif /* SF_MESSAGE_PAYLOADS_H_ */
