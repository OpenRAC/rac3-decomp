/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_003B37B0, the NTSC-U twin of func_L01_003B4FB0, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 0 words differ with its file's flags.
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_003B4FB0 (src/levels/shared/L01_003B1F50.c) */
/* localdecomp:start func_L01_003B37B0 */
typedef struct {
    u8 *w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 w24;
} St_3B37B0;
typedef struct { u8 p0[0x18]; void (*f18)(void); } V_3B37B0;
extern u8 *D_L01_001E009C;
extern s32 D_L01_001DE788[2];
__asm__(".extern D_L01_001DE788, 8");
extern s32 D_00142660[];
extern u8 D_001426E0[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s16 D_001A4DBC[];
extern f32 D_001A7404[];
extern f32 D_L01_001DF9D0;
__asm__(".extern D_L01_001DF9D0, 16");
extern void func_L01_003B3C98(void *, void *);
extern void func_L01_003B3D00(void *, void *, s32);
extern void func_L01_003B1100(void *);
extern void func_L01_003B2AC8(s32, s32, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00328D78(void);
extern void func_003DFF90(s32);
extern s32 func_L01_00328B90(void *);
extern s32 func_L01_00328BE0(void *);
extern void func_L01_00416B38(s32);
extern void func_L01_00326950(void *);
extern void func_0039FF28(s32, s32, s32);
extern s32 func_00388398(void *);
extern void func_L01_004EA040(void);
extern void func_L01_00452F40(void *, s32);
extern void func_L01_004FC518(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern V_3B37B0 *func_L01_00438468(s32, s32);
extern s32 func_L01_004B6C68(void);

void func_L01_003B37B0(u8 *o) {
    St_3B37B0 *s1;
    u8 *s0;
    u8 *t;
    s32 v;
    s32 k;
    u32 x;
    s32 b;
    V_3B37B0 *r;

    s1 = *(St_3B37B0 **)(o + 0x68);
    if (o[0x20] == 0) {
        func_L01_003B3C98(o, s1);
    }
    switch (o[0x20]) {
    case 1:
        *(u16 *)(o + 0x34) |= 2;
        break;
    case 2:
        if (func_L01_00452EC8(o) != 0) {
            if (s1->w10 != 0) {
                s1->w14 = 2;
            } else {
                s1->w14 = 0xF0;
            }
            if (s1->wC != 0) {
                if (s1->w18 != -1) {
                    t = D_L01_001E009C + (s1->w18 << 8);
                    t[0x30] = 0xFF;
                    *(u16 *)(t + 0x34) &= 0xFFFD;
                }
                s0 = *(u8 **)(s1->w0 + 0x68);
                if (*(s32 *)(s0 + 0x54) != 0) {
                    v = func_L01_00328D78();
                    s1->w1C = v;
                    D_00142660[0] += v;
                    func_003DFF90(0xB4);
                } else {
                    s1->w1C = 0;
                }
                if (s0[0x52] != 0 && (func_L01_00328B90(s1->w0) == 0 || func_L01_00328BE0(s1->w0) == 0)) {
                    k = D_L01_001DE788[s0[0x52]];
                    s1->w20 = k;
                    func_L01_00416B38(k);
                } else {
                    s1->w20 = 0;
                }
                if (s1->w18 != -1) {
                    x = (*(s32 *)s0 & 0x7FF) + ((D_001D545C & 0x1F) << 11);
                    D_001426E0[0xE6] = x;
                    D_001426E0[0xE5] = x >> 8;
                }
                b = D_001426E0[0xBD];
                func_L01_00326950(s1->w0);
                if (b == 0 && D_001426E0[0xBD] != 0) {
                    s1->w24 = 1;
                    func_0039FF28(1, 0, 0);
                } else {
                    s1->w24 = 0;
                }
                D_001A4DBC[0] = 0x12C;
            }
        }
        if (s1->wC != 0 && s1->w10 == 0) {
            D_001A7404[0] = 300.0f;
        }
        if (func_00388398(&s1->w14) != 0) {
            if (s1->wC == 0) {
                func_L01_004EA040();
            }
            if (s1->w18 != -1 && s1->wC != 0) {
                func_L01_00452F40(D_L01_001E009C + (s1->w18 << 8), 1);
                if (D_001D545C == 0x1A) {
                    func_L01_004FC518(0x74, 1);
                }
                func_L01_00441FB8(o, 3, -1);
            } else if (s1->w10 != 0) {
                if (s1->wC != 0 && s1->w4 != 0) {
                    func_L01_00441FB8(o, 5, -1);
                } else {
                    func_L01_00441FB8(o, 7, -1);
                }
            } else {
                func_L01_00441FB8(o, 4, -1);
            }
        } else if (s1->w10 == 0) {
            if (s1->wC != 0) {
                func_L01_003B2AC8(0xA82, s1->w1C, s1->w20, s1->w24);
            } else {
                func_L01_003B2AC8(0xA83, 0, 0, 0);
            }
        }
        break;
    case 3:
        if (func_L01_00452EC8(o) != 0) {
            r = func_L01_00438468(0x19E1, 0x6C);
            r->f18();
        }
        if (func_L01_004B6C68() == 0) {
            D_001426E0[0xE5] = 0;
            D_001426E0[0xE6] = 0;
            if (s1->wC != 0 && s1->w4 != 0) {
                func_L01_00441FB8(o, 5, -1);
            } else {
                func_L01_00441FB8(o, 7, -1);
            }
        }
        break;
    case 4:
        if (func_L01_00452EC8(o) != 0) {
            s1->w14 = 0x28;
        }
        if (s1->wC != 0) {
            func_L01_003B2AC8(0xA82, s1->w1C, s1->w20, s1->w24);
        } else {
            func_L01_003B2AC8(0xA83, 0, 0, 0);
        }
        if (func_00388398(&s1->w14) != 0) {
            D_L01_001DF9D0 = 2.0f;
            if (s1->wC != 0 && s1->w4 != 0) {
                func_L01_00441FB8(o, 5, -1);
            } else {
                func_L01_00441FB8(o, 7, -1);
            }
        } else {
            D_L01_001DF9D0 = (1.0f - (f32)s1->w14 / 40.0f) * 1.1f;
        }
        break;
    case 5:
        func_L01_003B3D00(o, s1, s1->w8);
        func_L01_00441FB8(o, 6, -1);
        break;
    case 6:
        if (func_L01_00452EC8(o) != 0) {
            s1->w14 = 0x14;
        }
        if (func_00388398(&s1->w14) != 0) {
            D_L01_001DF9D0 = 0.0f;
            func_L01_00441FB8(o, 7, -1);
        } else {
            D_L01_001DF9D0 = ((f32)s1->w14 / 20.0f) * 1.1f;
        }
        break;
    case 7:
        func_L01_003B1100(s1->w0);
        func_L01_00441FB8(o, 1, -1);
        break;
    }
}
/* localdecomp:end func_L01_003B37B0 */
