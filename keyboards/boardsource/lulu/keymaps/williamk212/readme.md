## specs
controller: rp2040
number of keys: 58

TODO: setup layer for gaming

## custom configurations
```
// potentially fixing the home row delays
// https://www.reddit.com/r/ErgoMechKeyboards/comments/1q1jo3c/urobs_zmk_timeless_home_row_mods_ported_to_native/
// https://github.com/urob/zmk-config?tab=readme-ov-file#timeless-homerow-mods
#define TAPPING_TERM 250
#define PERMISSIVE_HOLD
#define FLOW_TAP_TERM 150
#define CHORDAL_HOLD
#define SPECULATIVE_HOLD
 
```

## build
1. from qmk_userspace, run: `qmk compile -kb boardsource/lulu/rp2040  -km williamk212`. file `boardsource_lulu_rp2040_williamk212.uf2` should be generated
2. unplug keyboard
3. hold top left most key and plug in cable
4. drive should be mounted
5. then copy the file `boardsource_lulu_rp2040_williamk212.uf2`
