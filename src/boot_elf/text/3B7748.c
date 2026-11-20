#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B6CD8.c's earlier functions (tools/port_from_us.py) */
extern void func_00393340(s32);
extern void func_0039E9C0(s32);
extern void func_003BB5A8(s32);
extern s32 func_003BB760(s32);
extern s32 D_001D8AA0;
extern s32 D_001D8A9C;
extern s32 D_001D8AAC;
extern s32 D_001D8AB0;
extern s32 D_001D8AA4;
extern s32 D_001D8AA8;
extern u8 D_001D5BDC[];
extern u8 D_001D5BDC_003B6DB0[];
extern void func_003A5748(s32, s32, s32);
typedef struct { u8 on; u8 pad[7]; } F;
typedef struct { void (*fn)(); s32 pad; } T;
extern s32 D_001D8A18_003B6E78;
extern F D_001D8A48_003B6E78[1];
extern T D_001D8A4C[1];
typedef struct { s32 a[7]; } R;
extern R D_142430[];
extern void func_003B6C00();
extern void func_003B6CC8();
extern void func_003B6D28();
extern void func_003B6D68();
extern void func_003B6E50();
extern f32 D_001D8A68;
extern f32 D_001D8A6C;
extern f32 D_001D8A70;
extern f32 D_001D8A74;
extern f32 D_001D8A78;
extern f32 D_001D8A7C;
extern f32 D_001D8A80;
extern f32 D_001D8A84;
extern f32 D_001D8A88;
extern f32 D_001D8A8C;
extern f32 D_001D8A90;
extern f32 D_001D8A94;
extern f32 D_001D8A98;
extern f32 D_001D8AD0;
extern f32 D_001D8AD4;
extern f32 D_001D8AD8;
extern f32 D_001D8ADC;
extern f32 D_001D8AE0;
extern s32 D_001D8AC0[2];
extern void func_003BB538(void);
extern void func_003E9808();
extern s32 func_003BB4D0(u32);
extern s32 func_003E93A0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E82D8(s32, s32);
extern s32 func_003E7E80(s32, s32);
extern s32 func_003E7CE0(s32, s32, s32);
extern s32 func_003E94F0_003B6F48(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E9628(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E9020(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8E10(s32, s32, s32, s32, s32);
extern s32 func_003E89E8(s32, s32);
extern s32 func_003E8AC8(s32, s32);
extern s32 func_003E8700(s32, s32);
extern s32 D_001D8A18_003B7640;
extern s32 func_003823D0();
extern s32 func_003B9650(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);

/* localdecomp:start func_003B7748 */
extern s32 func_003E8128(s32, s32);
extern s32 func_003BB500(s32);
extern s32 func_003E7DD0(s32, s32);
extern s32 func_0011B2E8(char *, const char *, ...);
extern char D_001D8AE8[];
extern char D_001D8AF0[];
extern char D_001D8B00[];
extern char D_001D8B10[];
extern char D_001D8B18[];
extern char D_001D8B28[];
extern char D_001D8B30[];
typedef struct { s32 f0; s32 f4; } E_003B7748;
extern E_003B7748 D_0037FA58_003B7748[];
typedef struct {
    s32 state;
    s32 score;
    s32 count;
    s32 time;
    u8 pad10[5];
    u8 b[3];
    u8 pad18[4];
} Slot_003B7748;
typedef struct {
    u8 pad0[0x30];
    Slot_003B7748 slots[4];
} Save_003B7748;
extern Save_003B7748 D_00142430_003B7748;

void func_003B7748(void) {
    s32 t, r;
    s32 i;
    s32 state;
    s32 message;
    s32 text;
    s32 hours;
    s32 minutes;
    s32 value;

    for (i = 0; i < 4; i++) {
        func_003E8128(i + 0x4C0008, 0x80808080);
        state = D_00142430_003B7748.slots[i].state;
        if (state <= 0) {
            s32 text = func_003BB4D0(0) + i * 0x20;
            func_0011B2E8((char *)text, D_001D8AE8, func_003823D0(0x238));
            func_0011B2E8((char *)(func_003BB4D0(1) + i * 0x20), D_001D8AF0);
            func_0011B2E8((char *)(func_003BB4D0(2) + i * 0x20), D_001D8B00, 0, 0);
            func_0011B2E8((char *)(func_003BB4D0(3) + i * 0x20), D_001D8B10);
            func_003E8200(i + 0x4C0008, func_003BB500(0));
            func_003E7DD0(i + 0x4C0040, 1);
            func_003E7DD0(i + 0x4C0044, 0);
        } else {
            if ((u32)(state - 1) < 2 || state == 4 || state == 8 || state == 27 || state == 28 ||
                state == 9 || state == 29 || state == 5 || state == 13 || state == 23 ||
                state == 10 || state == 18 || state == 14) {
                if (state > 0) {
                    message = D_0037FA58_003B7748[state % 60].f4;
                } else {
                    message = D_0037FA58_003B7748[1].f4;
                }
            } else {
                if (state > 0) {
                    message = D_0037FA58_003B7748[state % 60].f0;
                } else {
                    message = D_0037FA58_003B7748[1].f0;
                }
            }
            text = func_003823D0(message);
            func_0011B2E8((char *)(func_003BB4D0(0) + i * 0x20), D_001D8AE8, text);
            func_0011B2E8((char *)(func_003BB4D0(1) + i * 0x20), D_001D8B18,
                          D_00142430_003B7748.slots[i].b[0], D_00142430_003B7748.slots[i].b[1], D_00142430_003B7748.slots[i].b[2]);
            t = D_00142430_003B7748.slots[i].time;
            hours = t / 216000;
            minutes = t / 3600 - hours * 60;
            if (hours >= 100) {
                hours = 99;
                minutes = 59;
            }
            func_0011B2E8((char *)(func_003BB4D0(2) + i * 0x20), D_001D8B00, hours, minutes);
            value = D_00142430_003B7748.slots[i].score;
            if (value > 9999999) {
                value = 9999999;
            }
            func_0011B2E8((char *)(func_003BB4D0(3) + i * 0x20), D_001D8B28, value);
            r = func_003BB500(state);
            if (r <= 0) {
                func_003E8200(i + 0x4C0008, func_003BB500(0));
                func_003E7DD0(i + 0x4C0040, 1);
            } else {
                func_003E8200(i + 0x4C0008, r);
                func_003E7DD0(i + 0x4C0040, 0);
            }
            value = D_00142430_003B7748.slots[i].count;
            if (value >= 100) {
                value = 99;
            }
            if (value != 0) {
                func_003E7DD0(i + 0x4C0044, 1);
                func_003E7DD0(i + 0x4C0048, 1);
                func_0011B2E8((char *)&D_001D8AC0[i], D_001D8B30, value);
            } else {
                func_003E7DD0(i + 0x4C0044, 0);
                func_003E7DD0(i + 0x4C0048, 0);
            }
        }
    }
}
/* localdecomp:end func_003B7748 */
