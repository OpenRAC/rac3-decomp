#include "common.h"

/* NTSC-U counterpart of func_L07_003BB410 (src/levels/07_annihilation_nation/L07_003BB410.c) */
/* localdecomp:start func_L07_003B9B20 */
typedef struct State_003BB410 {
    u8 pad[0x94];
    f32 last;
    f32 ratio;
    u8 p9c[4];
    s16 state;
    u16 fA2;
    u16 flags;
    s16 timerA6;
    s16 timerA8;
    s16 timerAA;
    s16 count;
} State_003BB410;
typedef struct Game_003BB410 {
    u8 pad[0x84];
    f32 time;
    u8 p88[0x2850 - 0x88];
    s32 value;
} Game_003BB410;
extern Game_003BB410 D_001A4BE0;
extern f32 func_0037E250(f32, f32);
extern void func_L07_003B9E78(s32);
extern void func_L07_003B9EB8(void *);
extern void func_L07_003B9F50(void *);
extern s32 func_L07_003BA1D8(s16);
extern s32 func_L07_003A0D08(void);
extern void func_003883C8(void *);

void func_L07_003B9B20(void *arg) {
    State_003BB410 *p = *(State_003BB410 **)((u8 *)arg + 0x68);
    f32 ratio;

    ratio = (D_001A4BE0.time - 220.0f) / 280.0f;
    if (p->ratio < ratio) {
        p->ratio = ratio;
    }
    if ((f32)D_001A4BE0.value != p->last) {
        if ((f32)D_001A4BE0.value < p->last) {
            if ((((u8)p->flags ^ 1) & 1) && p->ratio > 0.48214287f) {
                func_L07_003A0BC0(0x5F, (s32)arg, 0, 0x78);
                p->flags |= 1;
            } else if (p->timerA6 == 0) {
                func_L07_003B9F50(arg);
            }
            p->timerA6 = 2400;
        }
        p->last = D_001A4BE0.value;
    }
    if (p->count >= 5) {
        if (p->timerAA == 0) {
            func_L07_003A0BC0(func_0037E208(0x4A, 0x4E) & 0xFF, (s32)arg, 0, 0x78);
            p->timerAA = 2400;
        }
        p->count = 0;
    }
    switch (func_L07_003BA1D8(p->state)) {
    case 0:
        func_L07_003A0BC0(0x5D, (s32)arg, 0, 0x78);
        break;
    case 1:
        if (func_0037E250(0.0f, 1.0f) < 0.9f) {
            func_L07_003B9E78((s32)arg);
        }
        break;
    case 2: {
        f32 r = func_0037E250(0.0f, 1.0f);
        if (r < 0.5f) {
            func_L07_003A0BC0(0x60, (s32)arg, 0, 0x78);
        } else if (r < 0.9f) {
            func_L07_003B9E78((s32)arg);
        }
        break;
    }
    case 3: {
        f32 r = func_0037E250(0.0f, 1.0f);
        if (r < 0.5f) {
            func_L07_003A0BC0(func_0037E208(0x6F, 0x72) & 0xFF, (s32)arg, 0, 0x78);
        } else if (r < 0.9f) {
            func_L07_003B9E78((s32)arg);
        }
        break;
    }
    case 4: {
        f32 r = func_0037E250(0.0f, 1.0f);
        if (r < 0.25f) {
            func_L07_003A0BC0(0x5E, (s32)arg, 0, 0x78);
        } else if (r < 0.9f) {
            func_L07_003B9E78((s32)arg);
        }
        break;
    }
    case 7:
        func_L07_003B9E78((s32)arg);
        break;
    case 10:
        if (!(p->flags & 8)) {
            func_L07_003A0BC0(0x61, (s32)arg, 0, 0x78);
            p->flags |= 8;
        }
        break;
    }
    if (p->timerA8 == 0 && func_L07_003A0D08() >= 180) {
        func_L07_003B9EB8(arg);
        p->timerA8 = func_0037E1D8(60) + 120;
    }
    func_003883C8(&p->timerA6);
    func_003883C8(&p->timerAA);
    func_003883C8(&p->timerA8);
}
/* localdecomp:end func_L07_003B9B20 */
