#include "common.h"

/* NTSC-U save slot display passes the first two record bytes in the opposite order. */
extern s32 func_U_003E28E0(s32, s32);

/* localdecomp:start func_U_003B1EB0 */
extern s32 func_U_003B5C38(u32);
extern s32 func_U_0037DF98();
extern s32 D_U_001D8AF0[2];
extern s32 func_U_003E2808(s32, s32);
extern s32 func_U_003B5C68(s32);
extern s32 func_U_003E24B0(s32, s32);
extern s32 func_0011B2E8(char *, const char *, ...);
extern char D_U_001D8B18[];
extern char D_U_001D8B20[];
extern char D_U_001D8B30[];
extern char D_U_001D8B40[];
extern char D_U_001D8B48[];
extern char D_U_001D8B58[];
extern char D_U_001D8B60[];
typedef struct { s32 f0; s32 f4; } E_003B7390;
extern E_003B7390 D_U_0037BAA8_003B7390[];
typedef struct {
    s32 state;
    s32 score;
    s32 count;
    s32 time;
    u8 pad10[5];
    u8 b[3];
    u8 pad18[4];
} Slot_003B7390;
typedef struct {
    u8 pad0[0x30];
    Slot_003B7390 slots[4];
} Save_003B7390;
extern Save_003B7390 D_00142430_003B7390;

void func_U_003B1EB0(void) {
    s32 t, r;
    s32 i;
    s32 state;
    s32 message;
    s32 text;
    s32 hours;
    s32 minutes;
    s32 value;

    for (i = 0; i < 4; i++) {
        func_U_003E2808(i + 0x4C0008, 0x80808080);
        state = D_00142430_003B7390.slots[i].state;
        if (state <= 0) {
            s32 text = func_U_003B5C38(0) + i * 0x20;
            func_0011B2E8((char *)text, D_U_001D8B18, func_U_0037DF98(0x238));
            func_0011B2E8((char *)(func_U_003B5C38(1) + i * 0x20), D_U_001D8B20);
            func_0011B2E8((char *)(func_U_003B5C38(2) + i * 0x20), D_U_001D8B30, 0, 0);
            func_0011B2E8((char *)(func_U_003B5C38(3) + i * 0x20), D_U_001D8B40);
            func_U_003E28E0(i + 0x4C0008, func_U_003B5C68(0));
            func_U_003E24B0(i + 0x4C0040, 1);
            func_U_003E24B0(i + 0x4C0044, 0);
        } else {
            if ((u32)(state - 1) < 2 || state == 4 || state == 8 || state == 27 || state == 28 ||
                state == 9 || state == 29 || state == 5 || state == 13 || state == 23 ||
                state == 10 || state == 18 || state == 14) {
                if (state > 0) {
                    message = D_U_0037BAA8_003B7390[state % 60].f4;
                } else {
                    message = D_U_0037BAA8_003B7390[1].f4;
                }
            } else {
                if (state > 0) {
                    message = D_U_0037BAA8_003B7390[state % 60].f0;
                } else {
                    message = D_U_0037BAA8_003B7390[1].f0;
                }
            }
            text = func_U_0037DF98(message);
            func_0011B2E8((char *)(func_U_003B5C38(0) + i * 0x20), D_U_001D8B18, text);
            func_0011B2E8((char *)(func_U_003B5C38(1) + i * 0x20), D_U_001D8B48,
                          D_00142430_003B7390.slots[i].b[1], D_00142430_003B7390.slots[i].b[0], D_00142430_003B7390.slots[i].b[2]);
            t = D_00142430_003B7390.slots[i].time;
            hours = t / 216000;
            minutes = t / 3600 - hours * 60;
            if (hours >= 100) {
                hours = 99;
                minutes = 59;
            }
            func_0011B2E8((char *)(func_U_003B5C38(2) + i * 0x20), D_U_001D8B30, hours, minutes);
            value = D_00142430_003B7390.slots[i].score;
            if (value > 9999999) {
                value = 9999999;
            }
            func_0011B2E8((char *)(func_U_003B5C38(3) + i * 0x20), D_U_001D8B58, value);
            r = func_U_003B5C68(state);
            if (r <= 0) {
                func_U_003E28E0(i + 0x4C0008, func_U_003B5C68(0));
                func_U_003E24B0(i + 0x4C0040, 1);
            } else {
                func_U_003E28E0(i + 0x4C0008, r);
                func_U_003E24B0(i + 0x4C0040, 0);
            }
            value = D_00142430_003B7390.slots[i].count;
            if (value >= 100) {
                value = 99;
            }
            if (value != 0) {
                func_U_003E24B0(i + 0x4C0044, 1);
                func_U_003E24B0(i + 0x4C0048, 1);
                func_0011B2E8((char *)&D_U_001D8AF0[i], D_U_001D8B60, value);
            } else {
                func_U_003E24B0(i + 0x4C0044, 0);
                func_U_003E24B0(i + 0x4C0048, 0);
            }
        }
    }
}
/* localdecomp:end func_U_003B1EB0 */
