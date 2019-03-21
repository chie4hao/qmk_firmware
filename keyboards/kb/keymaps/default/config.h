
#ifndef CONFIG_CHIE4_H
#define CONFIG_CHIE4_H

#include "../../config.h"

// Increase "Tap" detection window. Avoid missing 'q' or 'z' when typing slowly.
#undef TAPPING_TERM
#define TAPPING_TERM 250

#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD
#define ONESHOT_TIMEOUT 300

#define IGNORE_MOD_TAP_INTERRUPT

#define MOUSEKEY_DELAY             300
#define MOUSEKEY_INTERVAL          50
#define MOUSEKEY_MAX_SPEED         10
#define MOUSEKEY_TIME_TO_MAX       20
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#endif
