#include "action_layer.h"
#include <stdio.h>

#define L_BASE 0
#define L_QWERTY 1
#define L_SYMBOL (1 << 2)
#define L_NUMBER (1 << 3)
#define L_NAV (1 << 4)
#define L_MOUSE (1 << 5)
#define L_MEDIA (1 << 6)
//#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Colemak Mod-DH");
    break;
  case L_QWERTY:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
    break;
  case L_SYMBOL:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Symbol");
    break;
  case L_NUMBER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Number");
    break;
  case L_NAV:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Navigation");
    break;
  case L_MOUSE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Mouse");
    break;
  case L_MEDIA:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Media");
    break;
//   case L_ADJUST:
//   case L_ADJUST_TRI:
//     snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
//     break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%u", layer_state);
  }

  return layer_state_str;
}
