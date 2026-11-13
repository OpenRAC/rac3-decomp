#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L10_00407D40 */
typedef int u128_t_407D40 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_407D40;
typedef struct {
    u8 pad0[0x30];
    s32 mode;
    s32 timer;
    u8 pad38[0xC];
    s16 count;
    u8 pad46[0x1A0 - 0x46];
    u8 *mobys[1];
} G_407D40;
extern G_407D40 D_L10_001E5F00;
extern u8 *D_L10_00238770[];
extern u8 D_L10_001D6AE0[4];
extern u8 D_L10_001D6AE4[4];
extern u8 D_L10_001D6AE8[4];
extern s32 D_001D545C;
extern u8 D_L12_001E2720[];
__asm__(".extern D_L10_001D6AE0, 4");
extern void func_L01_00423AB8(void);
extern void func_003A58C0(void *, s32);
extern void func_003A7AF8(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);
extern void func_L01_00424168(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00423DF0(void);
extern void func_L01_00423C48(void *, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern u8 D_L10_001D6C58[8];
extern u8 D_L10_001D6C98[8];
extern u8 D_L10_001D6CC0[8];
extern u8 *D_L10_001D6C50;
extern f32 D_L10_001D6C2C;
extern f32 D_L10_001DEC50;
__asm__(".extern D_L10_001D6C58, 8");
__asm__(".extern D_L10_001D6C98, 8");
__asm__(".extern D_L10_001D6CC0, 8");
__asm__(".extern D_L10_001DEC50, 4");
extern void func_L03_00411778(s32, s32);
extern void func_L08_004070C0(s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L10_004079E0(void *);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0042B068(s32, s32);
extern void func_L10_00407378(s32, s32, f32);
extern void func_L10_003E5E68(float);
extern void func_L04_004CA0B0(void);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L10_00407D40(void) {
    s32 i;
    u8 *o;
    s32 t;
    s32 i2;
    u8 **p;
    G_407D40 *g;
    V4_407D40 d;

    func_L01_00423AB8();
    for (i = 0; i < D_L10_001E5F00.count; i++) {
        o = D_L10_001E5F00.mobys[i];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0xE29) {
            *(u16 *)(o + 0x34) |= 0x800;
        }
        if (*(s16 *)(o + 0xAA) == 0xD54) {
            o[0x63] = 0;
            for (i2 = 0; D_L10_00238770[i2] != 0; i2++) {
                if (D_L10_00238770[i2][0x63] != 0) {
                    D_L10_00238770[i2][0x63] = 1;
                }
            }
            func_003A58C0(o, 0);
            func_L01_00404A10(func_003A7AF8, o);
        }
        if (o == 0) {
            continue;
        }
        t = *(s16 *)(o + 0xAA);
        if (t == 0xFA0) {
            if (*(u8 **)(o + 0x68) != 0) {
                func_L01_00451DB8(o, *(u8 **)(o + 0x68) + 0xC, 0x80AAAAD2, 0x80396464, 0.073303834f);
            }
        } else if (t == 0x1DEE || t == 0x19BC) {
            func_L01_00451DB8(o, D_L10_001D6AE0, 0x80505080, 0x80404038, 0.038397245f);
        } else if (t == 0x1977) {
            func_L01_00451DB8(o, D_L10_001D6AE4, 0x8080AAAA, 0x80464646, 0.045378566f);
        } else if (t == 0x1766) {
            func_L01_00451DB8(o, D_L10_001D6AE8, 0x80AAAAFF, 0x80646496, 0.13264504f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00404808(func_L01_00424168, o);
        }
    }
    if (D_001D545C == 0xA) {
        g = &D_L10_001E5F00;
        if (g->mode == 1) {
            func_L03_00411778(0x1BE, 0x29E);
        } else if (g->mode == 2) {
            func_L01_00423DF0();
            if (g->timer == 0xBBF) {
                qzero(&d);
                d.z += 2.0f;
                func_L08_004070C0(3, &d, 0x14, 2, 0x64, 0x32, 0x60204080, 0x80204080, 0x80204080, 1.0f, 1.0f);
            } else if (g->timer == 0xA82) {
                qzero(&d);
                d.z += 1.0f;
                func_L08_004070C0(4, &d, 0x14, 2, 0x64, 0x32, 0x60204080, 0x80204080, 0x80204080, 1.0f, 1.0f);
            }
            D_L10_001D6C50 = D_L10_001D6C58;
            func_L10_004079E0(D_L10_001D6C98);
        } else if (g->mode == 3) {
            if ((g->timer % 50 == 0 && func_00382468(2) == 0) || g->timer == 0x19 || g->timer == 0xE5 || g->timer == 0x177) {
                *(u128_t_407D40 *)&d = 0;
                d.x = 20.0f;
                d.z = 2.0f;
                func_L01_00423C48(&d, 15.0f, 0.1f, func_003824E0(2.0f, 5.0f));
            }
        } else if (g->mode == 5) {
            f32 f;
            if (g->timer == 1) {
                func_L01_0042B068(2, 0);
            }
            f = 1.0f;
            if (g->timer >= 0x22E) {
                f = 0.8f;
            }
            func_L10_00407378(0, 1, f);
        } else if (g->mode == 6) {
            func_L10_003E5E68(4096.0f);
            if (g->timer == 0xC) {
                d = *(V4_407D40 *)(g->mobys[0] + 0x10);
                func_L01_003303B8(&d, 0, 0, 0, 0, 5, 0, 0, 3.0f, 0.0f, 0.0f, 2.0f,
                                  0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            }
            if (g->timer >= 0x53) {
                if (g->timer == 0x53) {
                    D_L10_001D6C2C = 9999.0f;
                }
                func_L10_00407378(0, 1, 1.0f);
            }
            if (D_L10_001E5F00.timer >= 0x17F) {
                D_L10_001DEC50 = (f32)(D_L10_001E5F00.timer - 0x17F) / 200.0f;
            }
        } else if (g->mode == 7) {
            func_L04_004CA0B0();
            D_L10_001D6C50 = D_L10_001D6C58;
            func_L10_004079E0(D_L10_001D6CC0);
        }
    }
}
/* localdecomp:end func_L10_00407D40 */
