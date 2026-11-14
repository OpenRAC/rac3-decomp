#include "common.h"

/* NTSC-U counterpart of func_L12_00425A50 (src/levels/12_rilgar/L12_00425A50.c): 0.0733038 -> 0.0610865; 0.0383972 -> 0.0319977; 0.0453786 -> 0.0378155; 0.132645 -> 0.110538; 776 -> 931 */
/* localdecomp:start func_L12_00422B10 */
typedef int u128_t_425A50 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_425A50;
typedef struct {
    u8 pad0[0x30];
    s32 mode;
    s32 timer;
    u8 pad38[0xC];
    s16 count;
    u8 pad46[0x1A0 - 0x46];
    u8 *mobys[1];
} G_425A50;
extern G_425A50 D_L12_001E6B40;
extern u8 *D_L12_0023AA30[];
extern u8 D_L12_001D6AE0_00422B10[4];
extern u8 D_L12_001D6AE4_00422B10[4];
extern u8 D_L12_001D6AE8_00422B10[4];
extern s32 D_001D545C;
extern u8 D_L12_001E27A0[];
__asm__(".extern D_L12_001D6AE0_00422B10, 4");
extern void func_L01_00420D88(void);
extern void func_003A04A0(void *, s32);
extern void func_003A26D0(void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern void func_L01_00421438(void *);
extern void func_L01_00402498(void *, void *);
extern void func_L01_004210C0(void);
extern void func_L01_00420F18(void *, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern void func_L12_00422968(u8 *, void *, void *, void *);

void func_L12_00422B10(void) {
    s32 i;
    u8 *o;
    s32 t;
    s32 i2;
    u8 **p;
    G_425A50 *g;
    V4_425A50 a;
    V4_425A50 b;
    V4_425A50 c;
    V4_425A50 d;

    func_L01_00420D88();
    for (i = 0; i < D_L12_001E6B40.count; i++) {
        o = D_L12_001E6B40.mobys[i];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0xE29) {
            *(u16 *)(o + 0x34) |= 0x800;
        }
        if (*(s16 *)(o + 0xAA) == 0xD54) {
            o[0x63] = 0;
            for (i2 = 0; D_L12_0023AA30[i2] != 0; i2++) {
                if (D_L12_0023AA30[i2][0x63] != 0) {
                    D_L12_0023AA30[i2][0x63] = 1;
                }
            }
            func_003A04A0(o, 0);
            func_L01_004026A0(func_003A26D0, o);
        }
        if (o == 0) {
            continue;
        }
        t = *(s16 *)(o + 0xAA);
        if (t == 0xFA0) {
            if (*(u8 **)(o + 0x68) != 0) {
                func_L01_0044EB38(o, *(u8 **)(o + 0x68) + 0xC, 0x80AAAAD2, 0x80396464, 0.061086528f);
            }
        } else if (t == 0x1DEE || t == 0x19BC) {
            func_L01_0044EB38(o, D_L12_001D6AE0_00422B10, 0x80505080, 0x80404038, 0.031997703f);
        } else if (t == 0x1977) {
            func_L01_0044EB38(o, D_L12_001D6AE4_00422B10, 0x8080AAAA, 0x80464646, 0.0378154702f);
        } else if (t == 0x1766) {
            func_L01_0044EB38(o, D_L12_001D6AE8_00422B10, 0x80AAAAFF, 0x80646496, 0.110537529f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00402498(func_L01_00421438, o);
        }
    }
    if (D_001D545C == 0xC) {
        g = &D_L12_001E6B40;
        if (g->mode == 2) {
            for (i = 0; i < D_L12_001E6B40.count; i++) {
                *(s16 *)(D_L12_001E6B40.mobys[i] + 0xB4) = 1;
            }
        } else if (g->mode == 3 && g->timer < 0x3A3) {
            func_L01_004210C0();
            func_00388830(&a, D_L12_001E27A0, 10.0f);
            if (func_0037E1D8(2) == 0) {
                func_00388830(&b, D_L12_001E27A0 + 0x10, -15.0f);
                func_00388830(&c, D_L12_001E27A0 + 0x10, -25.0f);
            } else {
                func_00388830(&b, D_L12_001E27A0 + 0x10, 15.0f);
                func_00388830(&c, D_L12_001E27A0 + 0x10, 25.0f);
            }
            if (func_0037E1D8(5) == 0) {
                func_L12_00422968(D_L12_001E6B40.mobys[0], &a, &b, &c);
            }
            if (D_L12_001E6B40.timer % 20 == 0 && func_0037E1D8(3) == 0) {
                *(u128_t_425A50 *)&d = 0;
                d.x = 18.0f;
                d.z = -2.0f;
                func_L01_00420F18(&d, 8.0f, 0.5f, 2.0f);
            }
        }
    }
}
/* localdecomp:end func_L12_00422B10 */
