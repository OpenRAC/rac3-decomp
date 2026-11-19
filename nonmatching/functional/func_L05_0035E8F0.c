/* functional: high. Read block by block from the PAL asm (state 0 mask build, state 1 hit loop, tail with the 0x83 flag, default call). The srav by a possibly -1 shift is written as shift & 31 (MIPS uses the low 5 bits). 257 word diffs vs retail (regalloc/scheduling; frame 0xA0 matches). */
#include "vu0.h"
typedef struct { s32 f0, f4, f8; f32 timer; } Ent_35E8F0;
extern void *func_L01_00447490(void *, s32, s32);
extern f32 func_L01_004474E8(void *, void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern s32 func_L05_003F88B0(void);
extern void func_003C4A40(void *, void *);
extern void func_L01_0044BB30(void *, void *, s32, f32, f32);
extern void func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L04_00325460(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L05_0035E8F0(u8 *obj) {
    u8 *d;
    u8 *t;
    Ent_35E8F0 *ents;
    s32 shift;
    s32 i;
    s32 count;
    f32 dist;
    f32 timer;
    vu0_v4 v;

    d = *(u8 **)(obj + 0x68);
    ents = (Ent_35E8F0 *)(d + 0x90);
    if (obj[0x20] == 1) {
        t = func_L01_00447490(obj, -1, 0);
        dist = func_L01_004474E8(obj, t);
        if (t != 0 && dist != 0.0f) {
            shift = -1;
            if (func_L01_003FB640(t, 1, *(void **)(t + 0x20), 0.1f) != 0) {
                shift = func_L05_003F88B0();
            }
            count = d[0x80];
            for (i = 0; i < count; i++) {
                if (((ents[i].f0 >> (shift & 31)) & 1) == 0) {
                    continue;
                }
                if (ents[i].f8 & *(u16 *)(obj + 0x7C)) {
                    continue;
                }
                func_003C4A40(obj, d + 0x70);
                timer = ents[i].timer - *(f32 *)(t + 0x2C);
                ents[i].timer = timer;
                if (timer <= 0.0f) {
                    ents[i].timer = 0.0f;
                    *(s32 *)(obj + 0x9C) |= ents[i].f4;
                    func_L01_0044BB30(obj, t, -1, 0.5f, 13.0f);
                    if (*(s8 *)(d + 0x82) != -1) {
                        func_003A52A0(*(s8 *)(d + 0x82), 0, obj);
                    }
                    func_0038CF68(&v, t + 0x10, 0.08f);
                    func_L01_00451FE0(obj, 1 << i, &v, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                    *(u16 *)(obj + 0x7C) &= ~(1 << i);
                    while (d[0x80] != 0 && ents[d[0x80] - 1].timer == 0.0f) {
                        d[0x80]--;
                    }
                }
                break;
            }
        }
        obj[0xA8] = 0xFF;
        if (d[0x80] == 0 && d[0x83] != 0) {
            if (*(s8 *)(d + 0x81) != -1) {
                func_003A52A0(*(s8 *)(d + 0x81), 0, obj);
            }
            func_L04_00325460(obj + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 1.0f, 20.0f, 1, 1, 0, 0);
            func_003C2880(obj);
            return;
        }
    } else if (obj[0x20] == 0) {
        *(s32 *)(obj + 0x9C) = 0;
        *(u16 *)(obj + 0x7C) = 0;
        for (i = 0; i < d[0x80]; i++) {
            if (ents[i].f0 != 0 && 0.0f < ents[i].timer) {
                *(u16 *)(obj + 0x7C) |= 1 << i;
            }
        }
        if (d[0x84] != 0) {
            *(u16 *)(obj + 0x34) |= 0x8000;
        }
        func_L01_004450F0(obj, 1, -1);
    }
    func_L01_0044ABD0(obj, d + 0x70);
}
