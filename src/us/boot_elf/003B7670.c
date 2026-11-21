#include "common.h"

/* NTSC-U counterpart of func_003B7748 (src/boot_elf/text/3B7748.c): new string addresses; the date prints b[1] before b[0] (month/day) */
/* localdecomp:start func_U_003B7670 */
extern s32 D_U_001D8AF0[2];
extern s32 func_U_003BB3F8(u32);
extern s32 func_U_003E80A0(s32, s32);
extern s32 func_U_003823F0();
extern s32 func_U_003E7FC8(s32, s32);
extern s32 func_U_003BB428(s32);
extern s32 func_U_003E7C70(s32, s32);
extern s32 func_0011B2E8(char *, const char *, ...);
extern char D_U_001D8B18[];
extern char D_U_001D8B20[];
extern char D_U_001D8B30[];
extern char D_U_001D8B40[];
extern char D_U_001D8B48[];
extern char D_U_001D8B58[];
extern char D_U_001D8B60[];
typedef struct { s32 f0; s32 f4; } E_003B7670;
extern E_003B7670 D_U_0037FAE8[];
typedef struct {
    s32 state;
    s32 score;
    s32 count;
    s32 time;
    u8 pad10[5];
    u8 b[3];
    u8 pad18[4];
} Slot_003B7670;
typedef struct {
    u8 pad0[0x30];
    Slot_003B7670 slots[4];
} Save_003B7670;
extern Save_003B7670 D_00142430_003B7670;

void func_U_003B7670(void) {
    s32 t, r;
    s32 i;
    s32 state;
    s32 message;
    s32 text;
    s32 hours;
    s32 minutes;
    s32 value;

    for (i = 0; i < 4; i++) {
        func_U_003E7FC8(i + 0x4C0008, 0x80808080);
        state = D_00142430_003B7670.slots[i].state;
        if (state <= 0) {
            s32 text = func_U_003BB3F8(0) + i * 0x20;
            func_0011B2E8((char *)text, D_U_001D8B18, func_U_003823F0(0x238));
            func_0011B2E8((char *)(func_U_003BB3F8(1) + i * 0x20), D_U_001D8B20);
            func_0011B2E8((char *)(func_U_003BB3F8(2) + i * 0x20), D_U_001D8B30, 0, 0);
            func_0011B2E8((char *)(func_U_003BB3F8(3) + i * 0x20), D_U_001D8B40);
            func_U_003E80A0(i + 0x4C0008, func_U_003BB428(0));
            func_U_003E7C70(i + 0x4C0040, 1);
            func_U_003E7C70(i + 0x4C0044, 0);
        } else {
            if ((u32)(state - 1) < 2 || state == 4 || state == 8 || state == 27 || state == 28 ||
                state == 9 || state == 29 || state == 5 || state == 13 || state == 23 ||
                state == 10 || state == 18 || state == 14) {
                if (state > 0) {
                    message = D_U_0037FAE8[state % 60].f4;
                } else {
                    message = D_U_0037FAE8[1].f4;
                }
            } else {
                if (state > 0) {
                    message = D_U_0037FAE8[state % 60].f0;
                } else {
                    message = D_U_0037FAE8[1].f0;
                }
            }
            text = func_U_003823F0(message);
            func_0011B2E8((char *)(func_U_003BB3F8(0) + i * 0x20), D_U_001D8B18, text);
            func_0011B2E8((char *)(func_U_003BB3F8(1) + i * 0x20), D_U_001D8B48,
                          D_00142430_003B7670.slots[i].b[1], D_00142430_003B7670.slots[i].b[0], D_00142430_003B7670.slots[i].b[2]);
            t = D_00142430_003B7670.slots[i].time;
            hours = t / 216000;
            minutes = t / 3600 - hours * 60;
            if (hours >= 100) {
                hours = 99;
                minutes = 59;
            }
            func_0011B2E8((char *)(func_U_003BB3F8(2) + i * 0x20), D_U_001D8B30, hours, minutes);
            value = D_00142430_003B7670.slots[i].score;
            if (value > 9999999) {
                value = 9999999;
            }
            func_0011B2E8((char *)(func_U_003BB3F8(3) + i * 0x20), D_U_001D8B58, value);
            r = func_U_003BB428(state);
            if (r <= 0) {
                func_U_003E80A0(i + 0x4C0008, func_U_003BB428(0));
                func_U_003E7C70(i + 0x4C0040, 1);
            } else {
                func_U_003E80A0(i + 0x4C0008, r);
                func_U_003E7C70(i + 0x4C0040, 0);
            }
            value = D_00142430_003B7670.slots[i].count;
            if (value >= 100) {
                value = 99;
            }
            if (value != 0) {
                func_U_003E7C70(i + 0x4C0044, 1);
                func_U_003E7C70(i + 0x4C0048, 1);
                func_0011B2E8((char *)&D_U_001D8AF0[i], D_U_001D8B60, value);
            } else {
                func_U_003E7C70(i + 0x4C0044, 0);
                func_U_003E7C70(i + 0x4C0048, 0);
            }
        }
    }
}
/* localdecomp:end func_U_003B7670 */
