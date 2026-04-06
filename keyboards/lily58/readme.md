# keyboard info
https://shop.beekeeb.com/products/allium58-glp-wired-kit
https://github.com/beekeeb/Allium58
https://docs.beekeeb.com/allium58-keyboard

# Specs & Features
* Wired keyboard, 58 Keys
* Column staggered keys with 3 thumb keys
* RP2040 Sea Picro Controllers with 16MB Flash Memory
* Hotswappable GLP Low Profile Sockets - Compatible with Gateron low profile v1.0 (KS-27) and v2.0 (KS-33) key switches

## RP2040 Sea Picro Controllers
https://joshajohnson.com/sea-picro/


## building / compile
original

```bash
qmk compile -kb lily58 -km allium58 -e CONVERT_TO=promicro_rp2040
```

this is deprecated. need find a better one
https://www.reddit.com/r/olkb/comments/112n7x4/help_needed_flashing_my_qmk_layout_to_pi_pico/

```bash
qmk compile -kb lily58 -km allium58 -e CONVERT_TO=rp2040_ce
```
