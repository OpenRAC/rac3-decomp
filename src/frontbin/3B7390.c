#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003E7E48(s32, s32);
/* --- end of declarations from other files --- */


/* localdecomp:start func_003B7390 */
extern s32 func_003BB118(u32);
extern s32 func_00381FF0();
extern s32 D_001D8AC0[2];
extern s32 func_003E7D70(s32, s32);
extern s32 func_003BB148(s32);
extern s32 func_003E7A18(s32, s32);
extern s32 func_0011B2E8(char *, const char *, ...);
extern char D_001D8AE8[];
extern char D_001D8AF0[];
extern char D_001D8B00[];
extern char D_001D8B10[];
extern char D_001D8B18[];
extern char D_001D8B28[];
extern char D_001D8B30[];
typedef struct { s32 f0; s32 f4; } E_003B7390;
extern E_003B7390 D_0037FA58_003B7390[];
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

void func_003B7390(void) {
    s32 t, r;
    s32 i;
    s32 state;
    s32 message;
    s32 text;
    s32 hours;
    s32 minutes;
    s32 value;

    for (i = 0; i < 4; i++) {
        func_003E7D70(i + 0x4C0008, 0x80808080);
        state = D_00142430_003B7390.slots[i].state;
        if (state <= 0) {
            s32 text = func_003BB118(0) + i * 0x20;
            func_0011B2E8((char *)text, D_001D8AE8, func_00381FF0(0x238));
            func_0011B2E8((char *)(func_003BB118(1) + i * 0x20), D_001D8AF0);
            func_0011B2E8((char *)(func_003BB118(2) + i * 0x20), D_001D8B00, 0, 0);
            func_0011B2E8((char *)(func_003BB118(3) + i * 0x20), D_001D8B10);
            func_003E7E48(i + 0x4C0008, func_003BB148(0));
            func_003E7A18(i + 0x4C0040, 1);
            func_003E7A18(i + 0x4C0044, 0);
        } else {
            if ((u32)(state - 1) < 2 || state == 4 || state == 8 || state == 27 || state == 28 ||
                state == 9 || state == 29 || state == 5 || state == 13 || state == 23 ||
                state == 10 || state == 18 || state == 14) {
                if (state > 0) {
                    message = D_0037FA58_003B7390[state % 60].f4;
                } else {
                    message = D_0037FA58_003B7390[1].f4;
                }
            } else {
                if (state > 0) {
                    message = D_0037FA58_003B7390[state % 60].f0;
                } else {
                    message = D_0037FA58_003B7390[1].f0;
                }
            }
            text = func_00381FF0(message);
            func_0011B2E8((char *)(func_003BB118(0) + i * 0x20), D_001D8AE8, text);
            func_0011B2E8((char *)(func_003BB118(1) + i * 0x20), D_001D8B18,
                          D_00142430_003B7390.slots[i].b[0], D_00142430_003B7390.slots[i].b[1], D_00142430_003B7390.slots[i].b[2]);
            t = D_00142430_003B7390.slots[i].time;
            hours = t / 216000;
            minutes = t / 3600 - hours * 60;
            if (hours >= 100) {
                hours = 99;
                minutes = 59;
            }
            func_0011B2E8((char *)(func_003BB118(2) + i * 0x20), D_001D8B00, hours, minutes);
            value = D_00142430_003B7390.slots[i].score;
            if (value > 9999999) {
                value = 9999999;
            }
            func_0011B2E8((char *)(func_003BB118(3) + i * 0x20), D_001D8B28, value);
            r = func_003BB148(state);
            if (r <= 0) {
                func_003E7E48(i + 0x4C0008, func_003BB148(0));
                func_003E7A18(i + 0x4C0040, 1);
            } else {
                func_003E7E48(i + 0x4C0008, r);
                func_003E7A18(i + 0x4C0040, 0);
            }
            value = D_00142430_003B7390.slots[i].count;
            if (value >= 100) {
                value = 99;
            }
            if (value != 0) {
                func_003E7A18(i + 0x4C0044, 1);
                func_003E7A18(i + 0x4C0048, 1);
                func_0011B2E8((char *)&D_001D8AC0[i], D_001D8B30, value);
            } else {
                func_003E7A18(i + 0x4C0044, 0);
                func_003E7A18(i + 0x4C0048, 0);
            }
        }
    }
}
/* localdecomp:end func_003B7390 */
