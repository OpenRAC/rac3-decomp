#include "common.h"

/* NTSC-U counterpart of func_L03_00321DD0 (src/levels/03_starship_phoenix/L03_00321DD0.c): 60 Hz timer (3600 for 3000) */
/* localdecomp:start func_L03_003218F0 */
typedef struct Obj_00322548 {
    u8 pad0[0x30];
    u8 f30;
    u8 pad31[0x33];
    void (*f64)(struct Obj_00322548 *);
    u8 pad68[0x98];
} Obj_00322548;

typedef struct { s32 f0; s32 f4; u8 pad8[4]; s32 fC; u8 pad10[0x14]; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; u8 pad44[0x26]; s16 f6A; u8 f6C; } S_00321DD0;

extern s32 D_001A8114[];
extern s32 D_001A8318[];
extern s32 D_00142C10[];
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C;
extern u8 D_00142CA0[];
extern u8 D_001426E0[];
extern u8 D_001A4C60[];
extern void func_L03_00321BF8(void *);
extern void func_L03_00321C80(void *);
extern void func_L03_00322068(u8 *, s32);
extern void func_L01_004B73B8(void);
extern s32 func_L01_004B6C68(void);
extern void func_L01_00417F60(s32, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L01_00452F40(u8 *, s32);
extern void func_00399F90(void);
extern s32 func_003883C8(void *);
extern s32 func_0037E0F0(void *, s32, s32);
extern Obj_00322548 *D_L03_001DFA1C;

void func_L03_003218F0(u8 *a) {
    S_00321DD0 *s = *(S_00321DD0 **)(a + 0x68);
    s32 v;

    func_L03_00321BF8(a);
    func_L03_00321C80(a);
    switch (a[0x20]) {
    case 0:
        func_L01_004B73B8();
        if (D_00142CA0[0x22] != 0) {
            v = s->f40;
        } else if (D_001426E0[0x28] != 0) {
            v = s->f3C;
        } else if (D_001426E0[0x20] != 0) {
            v = s->f38;
        } else if (D_001426E0[0x3D] != 0) {
            v = s->f34;
        } else if (D_001426E0[0x74] != 0) {
            v = s->f30;
        } else if (D_00142CA0[0x1E] == 0) {
            goto L24;
        } else {
            if (D_001426E0[0xC] == 0) {
                D_001426E0[0xC] = 1;
                func_00399F90();
                D_001426E0[0x16] = 1;
                func_00399F90();
            }
            v = s->f28;
        }
        func_L03_00322068(a, v);
        break;
    L24:
        func_L03_00322068(a, s->f24);
        s->f6C = 0xFF;
        func_L01_00441FB8(a, 1, -1);
        break;
    case 1:
        if (D_001426E0[8] != 0) {
            func_L01_00441FB8(a, 2, -1);
            break;
        }
        if (func_L01_004B6C68() == 0) {
            s32 m = D_001A8114[0];
            s32 bit = 1 << D_001D545C;
            if (!(m & bit)) {
                func_L01_00417F60(0xB9C, 0x3F);
            }
        }
        if (s->f6C == 0xFF) {
            if (func_0037E0F0(D_001A4C60, s->fC, 0) != 0) {
                s->f6C = 0;
                s->f6A = 3600;
                func_L01_00417F60(0xA1C, 9);
            }
        } else if (func_003883C8(&s->f6A) != 0) {
            s->f6A = 3600;
            if (func_0037E0F0(D_001A4C60, s->f0, 0) != 0) {
                s->f6C = (s->f6C + 1) % 3;
                func_L01_00417F60(0xA1C + s->f6C, 9 + s->f6C);
            }
        }
        break;
    case 2:
        if (D_001426E0[9] != 0) {
            func_L01_00441FB8(a, 4, -1);
        } else if (func_0037E0F0(D_001A4C60, s->f4, 0) != 0) {
            D_001426E0[9] = 1;
            func_00399F90();
            func_L01_00452F40((u8 *)(D_L03_001DFA1C + s->f2C), 1);
            func_L01_00441FB8(a, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004B6C68() == 0) {
            if ((D_00142C10[0] & 0x20000) != 0) {
                s32 m = D_001A8318[0];
                s32 bit = 1 << D_001D545C;
                if (!(m & bit)) {
                    func_L01_00417F60(0xCB8, 0x6A);
                }
                func_L01_00441FB8(a, 4, -1);
            }
        }
        break;
    case 4:
    default:
        break;
    }
}
/* localdecomp:end func_L03_003218F0 */
