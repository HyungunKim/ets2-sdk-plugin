/**
 * @file scssdk_telemetry_eut2.h
 *
 * @brief ETS 2 telemetry specific constants.
 */
#ifndef SCSSDK_TELEMETRY_EUT2_H
#define SCSSDK_TELEMETRY_EUT2_H

#include "../scssdk.h"
#include "../common/scssdk_telemetry_common_configs.h"
#include "../common/scssdk_telemetry_common_channels.h"
#include "../common/scssdk_telemetry_truck_common_channels.h"
#include "../common/scssdk_telemetry_trailer_common_channels.h"

SCSSDK_HEADER

/**
 * @name Value used in the scs_sdk_init_params_t::game_version
 *
 * Changes in the major version indicate incompatible changes (e.g. changed interpretation
 * of the channel value). Change of major version is highly discouraged, creation of
 * alternative channel is preferred solution if necessary.
 * Changes in the minor version indicate compatible changes (e.g. added channel, more supported
 * value types). Removal of channel is also compatible change however it is recommended
 * to keep the channel with some default value.
 *
 * Changes:
 * 1.01 - added brake_air_pressure_emergency channel and air_pressure_emergency config
 * 1.02 - replaced cabin_orientation channel with cabin_offset channel
 * 1.03 - fixed reporting of invalid index value for wheels.count attribute
 * 1.04 - added lblinker_light and rblinker_light channels
 * 1.05 - fixed content of brand_id and brand attributes
 * 1.06 - fixed index value for selector_count attribute. It is now SCS_U32_NIL as the
 *        attribute is not indexed. For backward compatibility additional copy with
 *        index 0 is also present however it will be removed in the future.
 * 1.07 - fixed calculation of cabin_angular_acceleration channel.
 * 1.08 - a empty truck/trailer configuration event is generated when truck is removed
 *        (e.g. after completion of quick job)
 * 1.09 - added time and job related info
 * 1.10 - added information about liftable axes
 * 1.11 - u32 channels can provide u64 as documented, added displayed_gear channel, increased
 *        maximal number of supported wheel channels to 14
 * 1.12 - added information about transmission (differential_ratio, forward_ratio, reverse_ratio),
 *        navigation channels (navigation_distance, navigation_time, navigation_speed_limit)
 *        and adblue related data are now provided.
 */
//@{
#define SCS_TELEMETRY_EUT2_GAME_VERSION_1_00            SCS_MAKE_VERSION(1, 0)
#define SCS_TELEMETRY_EUT2_GAME_VERSION_1_01            SCS_MAKE_VERSION(1, 1)
#define SCS_TELEMETRY_EUT2_GAME_VERSION_1_02            SCS_MAKE_VERSION(1, 2)
#define SCS_TELEMETRY_EUT2_GAME_VERSION_1_03            SCS_MAKE_VERSION(1, 3)
#define SCS_TELEMETRY_EUT2_GAME_VERSION_1_04            SCS_MAKE_VERSION(1, 4)
#define SCS_TELEMETRY_EUT2_GAME_VERSION_1_05            SCS_MAKE_VERSION(1, 5)  // Patch 1.4
#define SCS_TELEMETRY_EUT2_GAME_VERSION_1_06            SCS_MAKE_VERSION(1, 6)
#define SCS_TELEMETRY_EUT2_GAME_VERSION_1_07            SCS_MAKE_VERSION(1, 7)  // Patch 1.6
#define SCS_TELEMETRY_EUT2_GAME_VERSION_1_08            SCS_MAKE_VERSION(1, 8)  // Patch 1.9
#define SCS_TELEMETRY_EUT2_GAME_VERSION_1_09            SCS_MAKE_VERSION(1, 9)  // Patch 1.14 beta
#define SCS_TELEMETRY_EUT2_GAME_VERSION_1_10            SCS_MAKE_VERSION(1, 10) // Patch 1.14
#define SCS_TELEMETRY_EUT2_GAME_VERSION_1_11            SCS_MAKE_VERSION(1, 11)
#define SCS_TELEMETRY_EUT2_GAME_VERSION_1_12            SCS_MAKE_VERSION(1, 12) // Patch 1.17
#define SCS_TELEMETRY_EUT2_GAME_VERSION_CURRENT         SCS_TELEMETRY_EUT2_GAME_VERSION_1_12
//@}

// Game specific units.
//
// @li The game uses Euro as internal currency provided
//     by the telemetry unless documented otherwise.

// Channels defined in scssdk_telemetry_common_channels.h,
// scssdk_telemetry_truck_common_channels.h and
// scssdk_telemetry_trailer_common_channels.h are supported
// with following exceptions and limitations as of v1.00:
//
// @li Rolling rotation of trailer wheels is determined from linear
//     movement.
// @li The pressures, temperatures and voltages are not simulated.
//     They are very loosely approximated.

// Configurations defined in scssdk_telemetry_common_configs.h are
// supported with following exceptions and limitations as of v1.00:
//
// @li The localized strings are not updated when different in-game
//     language is selected.

SCSSDK_FOOTER

#endif // SCSSDK_TELEMETRY_EUT2_H

/* eof */
