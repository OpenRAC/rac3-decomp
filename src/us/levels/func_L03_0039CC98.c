#include "common.h"

/* NTSC-U counterpart of func_L03_0039E470 (src/levels/03_starship_phoenix/L03_0039E470.c) */
typedef struct {
    u8 pad0[0x20]; u8 st; u8 pad21[2]; u8 b23;
    u8 pad24[0x60 - 0x24]; u8 b60;
    u8 pad61[0x68 - 0x61]; void *p68;
} S_0039E470;
typedef struct {
    u8 pad0[0x23]; u8 b23;
} T_0039E470;
typedef struct {
    u8 pad0[0x144]; s16 h144;
    u8 pad146[0x250 - 0x146]; void *p250;
    u8 pad254[0x268 - 0x254]; s16 h268;
    u8 pad26A[0x300 - 0x26A]; T_0039E470 *p300;
    u8 pad304[0x309 - 0x304]; u8 b309; s16 h30A; f32 f30C; u8 b310;
} P_0039E470;

/* localdecomp:start func_L03_0039CC98 */
extern void func_L03_0039CF70(void *);
extern void func_L03_0039D118();
extern s32 func_L01_00452EC8(void *);
extern s32 func_003883C8(void *);
extern void func_L03_0039D4C8(void *, s32);
extern void func_L01_004576E8(void *);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L03_0032CED8(void *, void *);
extern s32 func_L03_0032CF80(void *, void *);
extern s32 func_L03_0039D710(void *);
extern void func_L03_0039D638(void *, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_0044EB78(void *, void *, s32, s32, f32);

void func_L03_0039CC98(S_0039E470 *s) {
    P_0039E470 *p;
    func_L03_0039CF70(s);
    func_L03_0039D118(s);
    p = s->p68;
    switch (s->st) {
    case 2:
        if (func_L01_00452EC8(s)) {
            p->f30C = 1.0f / (f32)p->h268;
        }
        s->b23 = (s32)((1.0f - p->f30C * (f32)p->h268) * 128.0f);
        if (func_003883C8(&p->h268)) {
            s->b23 = 0x80;
            func_L03_0039D4C8(s, 3);
        }
        if (p->p300 != 0) {
            p->p300->b23 = s->b23;
        }
        break;
    case 3:
        func_L01_004576E8(s);
        func_L03_0039D4C8(s, 5);
    case 4:
        if (func_L01_00451078(s, (u8 *)p + 0x70) & 2) {
            func_L03_0039D4C8(s, 5);
        }
        break;
    case 5:
        func_L01_004576E8(s);
        if (func_003883C8(&p->h30A)) {
            if (p->h144 == 1) {
                if (func_L03_0032CED8(p->p250, s) != 0) {
                    func_L03_0039D4C8(s, 6);
                } else {
                    func_L03_0039D4C8(s, 8);
                }
            }
        }
        break;
    case 6:
        if (p->p300 != 0) {
            if (p->b309 < 0xFF) p->b309++;
            if (func_L03_0039D710(s)) p->b310 = 1;
        }
        func_L03_0039D638(s, 3.0f);
        if (p->b310 != 0 && p->b309 >= 0x1E) {
            func_L03_0039D4C8(s, 7);
        }
        if (p->h144 != 1) {
            func_L03_0032CF80(p->p250, s);
            func_L03_0039D4C8(s, 5);
        } else if (func_L03_0032CED8(p->p250, s) == 0) {
            func_L03_0039D4C8(s, 8);
        }
        break;
    case 7:
        func_L03_0039D638(s, 3.0f);
        if (s->b60 & 2) {
            p->h30A = func_0037E1D8(0x1E) + 0x3C;
            func_L03_0039D4C8(s, 6);
        }
        break;
    case 8:
        func_L03_0039D638(s, 5.0f);
        if (p->h144 != 1) {
            func_L03_0039D4C8(s, 5);
        } else if (func_L03_0032CED8(p->p250, s) != 0) {
            func_L03_0039D4C8(s, 6);
        }
        break;
    case 1:
    default:
        break;
    }
    func_L01_0044EB78(s, (u8 *)p + 0x270, 2, 1, 1.5f);
}
/* localdecomp:end func_L03_0039CC98 */
