/***********************************************************************************************************************
 * Copyright [2015-2017] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 *
 * This file is part of Renesas SynergyTM Software Package (SSP)
 *
 * The contents of this file (the "contents") are proprietary and confidential to Renesas Electronics Corporation
 * and/or its licensors ("Renesas") and subject to statutory and contractual protections.
 *
 * This file is subject to a Renesas SSP license agreement. Unless otherwise agreed in an SSP license agreement with
 * Renesas: 1) you may not use, copy, modify, distribute, display, or perform the contents; 2) you may not use any name
 * or mark of Renesas for advertising or publicity purposes or in connection with your use of the contents; 3) RENESAS
 * MAKES NO WARRANTY OR REPRESENTATIONS ABOUT THE SUITABILITY OF THE CONTENTS FOR ANY PURPOSE; THE CONTENTS ARE PROVIDED
 * "AS IS" WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, AND NON-INFRINGEMENT; AND 4) RENESAS SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, OR
 * CONSEQUENTIAL DAMAGES, INCLUDING DAMAGES RESULTING FROM LOSS OF USE, DATA, OR PROJECTS, WHETHER IN AN ACTION OF
 * CONTRACT OR TORT, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE CONTENTS. Third-party contents
 * included in this file may be subject to different terms.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * File Name    : sf_wifi_api.h
 * Description  : This layer provides APIs to manage WiFi device driver.
 ***********************************************************************************************************************/

#ifndef SF_WIFI_API_H
#define SF_WIFI_API_H

/*******************************************************************************************************************//**
 * @ingroup SF_Interface_Library
 * @defgroup SF_WIFI_API SF WIFI Framework Interface
 * @brief RTOS-integrated SF WIFI Framework Interface.
 *
 * @section SF_WIFI_API_SUMMARY Summary
 *
 * This SSP Interface provides access to the ThreadX-aware SF WIFI Framework.
 *
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"

/* Common macro for SSP header files. There is also a corresponding SSP_FOOTER macro at the end of this file. */
SSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** Major Version of the API defined in this file */
#define SF_WIFI_API_VERSION_MAJOR (1U)
/** Minor Version of the API defined in this file */
#define SF_WIFI_API_VERSION_MINOR (2U)

#define SF_WIFI_SSID_LENGTH                 (32U)  ///< WiFi SSID length
#define SF_WIFI_SECURITY_KEY_LENGTH         (128U) ///< WiFi Security Key length
#define SF_WIFI_MAC_ADDR_LENGTH             (6U)   ///< WiFi MAC address length
#define SF_WIFI_WPS_PIN_LENGTH              (8U)   ///< WiFi WPS Pin length

#define SF_WIFI_TRUE                  (1U) ///< Boolean True condition
#define SF_WIFI_FALSE                 (0U) ///< Boolean False condition

#define SF_WIFI_NULL_BYTE             ((uint8_t)'\0')      ///< NULL Byte
#define SF_WIFI_SIZE_FOR_NULL_BYTE    (1U)                 ///< Size in byte for NULL

/** IP Address Generation Macro */
#define SF_WIFI_IPV4_ADDRESS(a, b, c, d)   ((((uint32_t) a) << (24U)) | (((uint32_t) b) << (16U)) |  \
                                            (((uint32_t) c) << (8U))  |  ((uint32_t) d))

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
/** IP address version */
typedef enum e_sf_wifi_ip_addr_version
{
    SF_WIFI_IP_ADDR_VERSION_4,     ///< IPv4 address
    SF_WIFI_IP_ADDR_VERSION_6      ///< IPv6 address
} sf_wifi_ip_addr_version_t;

/** WiFi Interface mode */
typedef enum e_sf_wifi_interface_mode
{
    SF_WIFI_INTERFACE_MODE_AP,        ///< Access Point mode 
    SF_WIFI_INTERFACE_MODE_CLIENT     ///< Station Mode 
} sf_wifi_interface_mode_t;

/** WiFi WEP Key Format */
typedef enum e_sf_wifi_wep_key_format
{
    SF_WIFI_WEP_KEY_FORMAT_ASCII,       ///< WEP Key in ASCII
    SF_WIFI_WEP_KEY_FORMAT_HEX,         ///< WEP Key in Hex
} sf_wifi_wep_key_format_t;

/** WiFi Security type */
typedef enum e_sf_wifi_security_type
{
    SF_WIFI_SECURITY_TYPE_OPEN,                 ///< Open. No encryption used.
    SF_WIFI_SECURITY_TYPE_WEP,                  ///< 128-bit WEP OPEN ASCII
    SF_WIFI_SECURITY_TYPE_WPA,                  ///< WiFi Protected Access
    SF_WIFI_SECURITY_TYPE_WPA2                  ///< WiFi Protected Access v2
} sf_wifi_security_type_t;

/** WiFi Encryption type */
typedef enum e_sf_wifi_encryption_type
{
    SF_WIFI_ENCRYPTION_TYPE_AUTO,     ///< Automatic selection of encryption protocol. 
    SF_WIFI_ENCRYPTION_TYPE_TKIP,     ///< Temporal Key Integrity Protocol. Used by WPA. 
    SF_WIFI_ENCRYPTION_TYPE_CCMP,     ///< CTR mode with CBC-MAC Protocol. Used by WPA2
    SF_WIFI_ENCRYPTION_TYPE_WEP,      ///< WEP mode. Used by WEP
    SF_WIFI_ENCRYPTION_TYPE_NONE      ///< No Encryption. Used by Open Security type
} sf_wifi_encryption_type_t;

/** WiFi BSS type */
typedef enum e_sf_wifi_bss_type
{
    SF_WIFI_BSS_TYPE_INFRASTRUCTURE = 0, ///< Infrastructure network
    SF_WIFI_BSS_TYPE_ADHOC = 1, ///< 802.11 ad-hoc IBSS network
    SF_WIFI_BSS_TYPE_ANY = 2, ///< Either infrastructure or ad-hoc network
    SF_WIFI_BSS_TYPE_UNKNOWN = -1 ///< BSS type is unknown
} sf_wifi_bss_type_t;

/** WiFi Hardware mode */
typedef enum e_sf_wifi_interface_hw_mode
{
    SF_WIFI_INTERFACE_HW_MODE_11A,        ///< 802.11a 
    SF_WIFI_INTERFACE_HW_MODE_11B,        ///< 802.11b 
    SF_WIFI_INTERFACE_HW_MODE_11G,        ///< 802.11g 
    SF_WIFI_INTERFACE_HW_MODE_11N         ///< 802.11n 
} sf_wifi_interface_hw_mode_t;

/** WiFi RTS flag */
typedef enum e_sf_wifi_rts
{
    SF_WIFI_RTS_DISABLE,                    ///< Disable RTS/CTS handshake
    SF_WIFI_RTS_ENABLE,                     ///< Enable RTS/CTS handshake
} sf_wifi_rts_t;

/** WiFi Preamble type */
typedef enum e_sf_wifi_preamble
{
    SF_WIFI_PREAMBLE_SHORT,                     ///< Use short preamble
    SF_WIFI_PREAMBLE_LONG,                      ///< Use long preamble
} sf_wifi_preamble_t;

/** WiFi WMM flag */
typedef enum e_sf_wifi_wmm
{
    SF_WIFI_WMM_DISABLE,                    ///< Disable WMM
    SF_WIFI_WMM_ENABLE,                     ///< Enable WMM
} sf_wifi_wmm_t;

/** WiFi High Throughput flag */
typedef enum e_sf_wifi_high_throughput
{
    SF_WIFI_HIGH_THROUGHPUT_DISABLE,                    ///< Disable high throughput mode
    SF_WIFI_HIGH_THROUGHPUT_ENABLE,                  ///< Enable high throughput mode. Also requires WMM to be enabled.
} sf_wifi_high_throughput_t;

/** WiFi SSID Broadcast flag */
typedef enum e_sf_wifi_ssid_broadcast
{
    SF_WIFI_SSID_BROADCAST_DISABLE,                 ///< Disable SSID Broadcast
    SF_WIFI_SSID_BROADCAST_ENABLE,                  ///< Enable SSID Broadcast
} sf_wifi_ssid_broadcast_t;

/** WiFi WDS Flasg */
typedef enum e_sf_wifi_wds
{
    SF_WIFI_WDS_DISABLE,                    ///< Disable WDS
    SF_WIFI_WDS_ENABLE,                     ///< Enable WDS
} sf_wifi_wds_t;

/** WiFi Mandatory High Throughput flag */
typedef enum e_sf_wifi_mandatory_high_throughput
{
    SF_WIFI_MANDATORY_HIGH_THROUGHPUT_DISABLE,                  ///< Disable Mandatory HT requirement
    SF_WIFI_MANDATORY_HIGH_THROUGHPUT_ENABLE,                   ///< Enable mandatory HT requirement
} sf_wifi_mandatory_high_throughput_t;

/** WiFi Auto Negotiation flag */
typedef enum e_sf_wifi_auto_negotiation
{
    SF_WIFI_AUTO_NEGOTIATION_DISABLE,                   ///< Auto negotiation disable
    SF_WIFI_AUTO_NEGOTIATION_ENABLE,                    ///< Auto negotiation enable
} sf_wifi_auto_negotiation_t;

/** WiFi Framework AccessContol mode */
typedef enum e_sf_wifi_access_control
{
    SF_WIFI_ACCESS_CONTROL_DISABLE,                  ///< Disable MAC address matching
    SF_WIFI_ACCESS_CONTROL_DENY,                     ///< Deny association to stations on the MAC list.
    SF_WIFI_ACCESS_CONTROL_ALLOW,                    ///< Allow association to stations on the MAC list.
} sf_wifi_access_control_t;

/** WiFi WPS mode */
typedef enum e_sf_wifi_wps_mode
{
    SF_WIFI_WPS_MODE_PUSHBUTTON,            ///< WPS Push button method
    SF_WIFI_WPS_MODE_PIN,                   ///< WPS pin method
} sf_wifi_wps_mode_t;

/** IP address information */
typedef struct st_sf_wifi_ip_addr
{
    sf_wifi_ip_addr_version_t version;  ///< IP Address Version : v4 or v6
    union                               ///< Union that holds either IPv4 or IPv6 address
    {
        uint32_t v4;
        uint32_t v6[4];
    } addr;                             ///< IP address
} sf_wifi_ip_addr_t;

/** Configuration about underlying device driver. */
typedef struct st_sf_wifi_info
{
    uint8_t     * p_chipset;    ///< Pointer to sting showing WiFi chipset/driver information
    uint16_t      rssi;         ///< Received signal strength indication
    uint16_t      noise_level;  ///< Signal to noise ratio
    uint16_t      link_quality; ///< Signal strength / quality
} sf_wifi_info_t;

/** WiFi Framework event codes */
typedef enum e_sf_wifi_event
{
    SF_WIFI_EVENT_RX                = (1 << 0),  ///< Packet received event
    SF_WIFI_EVENT_AP_CONNECT        = (1 << 1),  ///< Device Associated Successfully with AP
    SF_WIFI_EVENT_AP_DISCONNECT     = (1 << 2),  ///< Device Disconnected with AP
    SF_WIFI_EVENT_CLIENT_CONNECT    = (1 << 3),  ///< Client Associated Successfully with device AP
    SF_WIFI_EVENT_CLIENT_DISCONNECT = (1 << 4),  ///< Client Disconnected from device AP
} sf_wifi_event_t;

/** WiFi framework callback parameter definition */
typedef struct st_sf_wifi_callback_arg
{
    sf_wifi_event_t     event;                              ///< Event code
    uint8_t           * p_data;                             ///< Packet data
    uint32_t            length;                             ///< Packet Data length
    uint8_t             mac_addr[SF_WIFI_MAC_ADDR_LENGTH];  ///< Client station MAC address
    void const        * p_context;                          ///< Context provided to user during callback
} sf_wifi_callback_args_t;

/** WiFi Provisioning parameters */
typedef struct st_sf_wifi_provisioning
{
    sf_wifi_interface_mode_t    mode;                                             ///< Select AP or Client mode
    uint8_t                     channel;                                          ///< RF Channel number
    uint8_t                     ssid[SF_WIFI_SSID_LENGTH + 1];                    ///< SSID
    sf_wifi_security_type_t     security;                                         ///< Security type
    sf_wifi_encryption_type_t   encryption;                                       ///< Encryption type
    uint8_t                     key[SF_WIFI_SECURITY_KEY_LENGTH];                 ///< Pre-shared key
    void                        (*p_callback)(sf_wifi_callback_args_t * p_args); ///< Pointer to Connection status notification callback function
} sf_wifi_provisioning_t;

/** Define the WiFi configuration parameters */
typedef struct st_sf_wifi_cfg
{
    uint8_t                             mac_addr[6];                ///< MAC address of WiFi Device
    sf_wifi_interface_hw_mode_t         hw_mode;                    ///< Modulation type: 11a/b/g/n
    uint8_t                             tx_power;                   ///< Sets transmit power in dBm
    sf_wifi_rts_t                       rts;                        ///< RTS/CTS handshake flag
    uint16_t                            fragmentation;              ///< Fragmentation threshold
    uint8_t                             dtim;                       ///< Delivery traffic indication message interval
    sf_wifi_high_throughput_t           high_throughput;            ///< High-throughput mode. Only valid for 802.11n
    sf_wifi_preamble_t                  preamble;                   ///< Preamble type
    sf_wifi_wmm_t                       wmm;                        ///< WiFi Multimedia Mode flag. If enabled, also requires
    uint8_t                             max_stations;               ///< Maximum permitted stations. Valid in AP mode only.
    sf_wifi_ssid_broadcast_t            ssid_broadcast;             ///< SSID broadcast flag. Valid in AP mode only.
    sf_wifi_access_control_t            access_control;             ///< Mode of access control MAC list
    uint32_t                            beacon;                     ///< Beacon interval. Valid in AP mode only
    uint32_t                            station_inactivity_timeout; ///< Station inactivity timeout value. Valid in AP mode only.
    sf_wifi_wds_t                       wds;                        ///< WDS flag. Valid in AP mode only.
    void                              * p_buffer_pool_rx;           ///< Pointer to Network stack Rx buffer pool
    sf_wifi_mandatory_high_throughput_t req_high_throughput;        ///< Only allow HT mode. Valid in AP mode only
    void (*p_callback)(sf_wifi_callback_args_t * p_args);          ///< Pointer to callback function
    void const                        * p_context;                  ///< User defined context passed into callback function
    void const                        * p_extend;                   ///< Instance specific configuration
} sf_wifi_cfg_t;

/** Define the statistic and error counters for this IP instance. */
typedef struct st_sf_wifi_stats
{
    uint32_t rx_pkts;        ///< Packets received successfully
    uint32_t tx_pkts;        ///< Packets transmitted successfully
    uint32_t tx_err;         ///< Transmit errors
} sf_wifi_stats_t;

/** Define the structure to store the SSID scan information */
typedef struct st_sf_wifi_scan
{
    sf_wifi_interface_hw_mode_t hw_mode;                        ///< Hardware mode 802.11a/b/g/n
    uint8_t                     rssi;                           ///< Signal Strength
    uint8_t                     ssid[SF_WIFI_SSID_LENGTH + 1];  ///< SSID name
    uint8_t                     bssid[SF_WIFI_MAC_ADDR_LENGTH]; ///< Basic Service Set Identification (i.e. MAC address of Access Point)
    uint8_t                     channel;                        ///< Radio channel that the AP beacon was received on
    sf_wifi_security_type_t     security;                       ///< Security type
    sf_wifi_encryption_type_t   encryption;                     ///< Encryption type
    sf_wifi_bss_type_t          bss_type;                       ///< Network type
} sf_wifi_scan_t;

/** Define the structure for WiFi WPS Control */
typedef struct st_sf_wifi_wps
{
    sf_wifi_wps_mode_t          wps_mode;                                                       ///< WPS method Push-button or Pin
    uint8_t                     wps_key[SF_WIFI_WPS_PIN_LENGTH + SF_WIFI_SIZE_FOR_NULL_BYTE];   ///< WPS pin. Used only with WPS pin method,
                                                                                                ///< PIN should be NULL terminated
    uint8_t                     timeout_seconds;                                                ///< WPS timeout value in seconds
    void (*p_callback)(sf_wifi_callback_args_t * p_args);                                       ///< Pointer to callback function to be called on changed in client's
                                                                                                ///< connection status with AP or client connected/disconnected
} sf_wifi_wps_t;


/** WiFi Framework control structure */
typedef struct st_sf_wifi_ctrl
{
    /** Storage for information needed for each WiFi device driver in the system. */
    void * p_driver_handle;
} sf_wifi_ctrl_t;

/** Framework API structure.  Implementations will use the following API. */
typedef struct st_sf_wifi_api
{
    /**
     * @brief Initializes the network interface for data transfers
     *
     * Initial driver configuration, enable the driver link, enable interrupts and
     * make device ready for data transfer.
     *
     * @param[in, out] p_ctrl Pointer to user-provided storage for the control block.
     * @param[in]      p_cfg  Pointer to WiFi configuration structure.
     */
    ssp_err_t (*open)(sf_wifi_ctrl_t * p_ctrl, sf_wifi_cfg_t const * const p_cfg);

    /**
     * @brief De-initialize the network interface and may put
     * it in low power mode or power it off. Close the driver, disable the driver link,
     * disable interrupt.
     *
     * @param[in, out]  p_ctrl  Pointer to the control block for the WiFi module.
     */
    ssp_err_t (*close)(sf_wifi_ctrl_t * const p_ctrl);

    /**
     * @brief Add the given MAC address to the multicast filter list.
     *
     * @param[in]  p_ctrl  Pointer to the control block for the WiFi module.
     * @param[in]  p_mac_addr  Pointer to the Mac address.
     */
    ssp_err_t (*multicastListAdd)(sf_wifi_ctrl_t * const p_ctrl, uint8_t const * const p_mac_addr);

    /**
     * Delete the given MAC address from the multicast filter list.
     *
     * @param[in]  p_ctrl  Pointer to the control block for the WiFi module.
     * @param[in]  p_mac_addr  Pointer to the Mac address.
     */
    ssp_err_t (*multicastListDelete)(sf_wifi_ctrl_t * const p_ctrl, uint8_t const * const p_mac_addr);

    /**
     * @brief Get the interface statistics.
     *
     * @param[in]   p_ctrl              Pointer to the control block for the WiFi module.
     * @param[out]  p_wifi_device_stats Pointer to the WiFi module data statistics.
     */
    ssp_err_t (*statisticsGet)(sf_wifi_ctrl_t * const p_ctrl, sf_wifi_stats_t * const p_wifi_device_stats);

    /**
     * @brief Transmit data packet
     *
     * @param[in]  p_ctrl  Pointer to the control block for the WiFi module.
     * @param[in]  p_buf   Pointer to transmit buffer
     * @param[in]  length  Transmit buffer length
     */
    ssp_err_t (*transmit)(sf_wifi_ctrl_t * const p_ctrl, uint8_t * const p_buf, uint32_t length);

    /** 
     * @brief Set WiFi module provisioning which will configure the module in AP or Client mode.
     *
     * @param[in]  p_ctrl               Pointer to the control block for the WiFi module.
     * @param[in]  p_wifi_provisioning  Pointer to WiFi provisioning structure
     */
    ssp_err_t (*provisioningSet)(sf_wifi_ctrl_t * const p_ctrl,
            sf_wifi_provisioning_t const * const p_wifi_provisioning);

    /** 
     * @brief Get the provisioning information of WiFi module.
     *
     * @param[in]  p_ctrl               Pointer to the control block for the WiFi module.
     * @param[out]  p_wifi_provisioning  Pointer to WiFi provisioning structure
     */
    ssp_err_t (*provisioningGet)(sf_wifi_ctrl_t * const p_ctrl, sf_wifi_provisioning_t * const p_wifi_provisioning);

    /** 
     * @brief Get WiFi module information.
     *
     * @param[in]  p_ctrl       Pointer to the control block for the WiFi module.
     * @param[out]  p_wifi_info  Pointer to WiFi module information structure
     */
    ssp_err_t (*infoGet)(sf_wifi_ctrl_t * const p_ctrl, sf_wifi_info_t * const p_wifi_info);

    /** 
     * @brief Scan for WiFi SSIDs.
     *
     * @param[in]  p_ctrl  Pointer to the control block for the WiFi module.
     * @param[out]  p_scan  Pointer to structure which will hold scan result. It is the responsibility of the caller
     *                     to ensure that adequate space is available to hold scan results.
     * @param[in, out]  p_cnt   Pointer to variable, specifying maximum number of SSID's to scan and will be updated
     *                     to number of actual SSIDs scanned by device
     */
    ssp_err_t (*scan)(sf_wifi_ctrl_t * const p_ctrl, sf_wifi_scan_t * const p_scan, uint8_t * const p_cnt);

    /** 
     * @brief Adds a MAC address to the Access Control List. Valid in AP mode only.
     *
     * @param[in]  p_ctrl  Pointer to the control block for the WiFi module.
     * @param[in]  p_mac   Pointer to MAC address
     */
    ssp_err_t (*ACLAdd)(sf_wifi_ctrl_t * const p_ctrl, uint8_t const * const p_mac);

    /**
     * @brief Deletes a MAC address from Access Control List. Valid in AP mode only.
     *
     * @param[in]  p_ctrl  Pointer to the control block for the WiFi module.
     * @param[in]  p_mac   Pointer to MAC address
     */
    ssp_err_t (*ACLDelete)(sf_wifi_ctrl_t * const p_ctrl, uint8_t const * const p_mac);

    /**
     * @brief Get WiFi module MAC address
     *
     * @param[in]  p_ctrl  Pointer to the control block for the WiFi module.
     * @param[out]  p_mac   Pointer to MAC address
     */
    ssp_err_t (*macAddressGet)(sf_wifi_ctrl_t * const p_ctrl, uint8_t * const p_mac);

    /**
     * @brief Set WiFi module MAC address
     *
     * @param[in]  p_ctrl  Pointer to the control block for the WiFi module.
     * @param[in]  p_mac   Pointer to MAC address
     */
    ssp_err_t (*macAddressSet)(sf_wifi_ctrl_t * const p_ctrl, uint8_t const * const p_mac);

    /**
     * @brief Start WiFi WPS
     *
     * @param[in]  p_ctrl  Pointer to the control block for the WiFi module.
     * @param[in]  p_wps   Pointer to WiFi WPS configuration
     */
    ssp_err_t (*wpsStart)(sf_wifi_ctrl_t * const p_ctrl, sf_wifi_wps_t const * const p_wps);

    /** 
     * @brief Gets version and stores it in provided pointer p_version.
     *
     * @param[out]  p_version pointer to memory location to return version number
     */
    ssp_err_t (*versionGet)(ssp_version_t * const p_version);
} sf_wifi_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_sf_wifi_instance
{
    sf_wifi_ctrl_t      * p_ctrl;       ///< Pointer to the control structure for this instance
    sf_wifi_cfg_t const * p_cfg;        ///< Pointer to the configuration structure for this instance
    sf_wifi_api_t const * p_api;        ///< Pointer to the API structure for this instance
} sf_wifi_instance_t;
/*******************************************************************************************************************//**
 * @} (end defgroup SF_WIFI_API)
 **********************************************************************************************************************/

/* Common macro for SSP header files. There is also a corresponding SSP_HEADER macro at the top of this file. */
SSP_FOOTER
#endif /* SF_WIFI_API_H */
