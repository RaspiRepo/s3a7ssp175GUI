/* generated messaging source file - do not edit */
#include "sf_message.h"
#ifndef SF_MESSAGE_CFG_QUEUE_SIZE
#define SF_MESSAGE_CFG_QUEUE_SIZE (16)
#endif
TX_QUEUE gui_thread_message_queue;
static uint8_t queue_memory_gui_thread_message_queue[SF_MESSAGE_CFG_QUEUE_SIZE];
static sf_message_subscriber_t gui_thread_message_queue_0_0 =
{ .p_queue = &gui_thread_message_queue, .instance_range =
{ .start = 0, .end = 0 } };
static sf_message_subscriber_t *gp_group_SF_MESSAGE_EVENT_CLASS_LCD_DISPLAY[] =
{ &gui_thread_message_queue_0_0, };
static sf_message_subscriber_list_t g_list_SF_MESSAGE_EVENT_CLASS_LCD_DISPLAY =
{ .event_class = SF_MESSAGE_EVENT_CLASS_LCD_DISPLAY, .number_of_nodes = 1, .pp_subscriber_group =
          gp_group_SF_MESSAGE_EVENT_CLASS_LCD_DISPLAY };
sf_message_subscriber_list_t *p_subscriber_lists[] =
{ &g_list_SF_MESSAGE_EVENT_CLASS_LCD_DISPLAY, NULL };
void g_message_init(void);
void g_message_init(void)
{
    tx_queue_create (&gui_thread_message_queue, (CHAR *) "GUIThread Message Queue", 1,
                     &queue_memory_gui_thread_message_queue, sizeof(queue_memory_gui_thread_message_queue));
}
