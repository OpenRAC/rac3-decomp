#include "common.h"

/* NTSC-U counterpart of func_L08_00407380 (src/levels/08_aquatos/L08_00407380.c) */
/* localdecomp:start func_L08_00404140 */
typedef int u128_t_407380 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_407380;
typedef struct {
    u8 pad0[0x30];
    s32 mode;
    s32 timer;
    u8 pad38[0xC];
    s16 count;
    u8 pad46[0x1A0 - 0x46];
    u8 *mobys[1];
} G_407380;
extern G_407380 D_L08_001E6080_00404140;
extern u8 *D_L08_002386F0_00404140[];
extern u8 D_L08_001D6A90_00404140[4];
extern u8 D_L08_001D6A94_00404140[4];
extern u8 D_L08_001D6A98_00404140[4];
__asm__(".extern D_L08_001D6A90_00404140, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L01_00420D88(void);
extern void func_003A04A0(void *, s32);
extern void func_003A26D0(void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern void func_L01_00421438(void *);
extern void func_L01_00402498(void *, void *);
extern void func_L08_00403E80(s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32);

/* from func_L10_00407D40 (the same code in level 10) */
void func_L08_00404140(void) {
    s32 i;
    u8 *o;
    s32 t;
    s32 i2;
    V4_407380 d;

    func_L01_00420D88();
    for (i = 0; i < D_L08_001E6080_00404140.count; i++) {
        o = D_L08_001E6080_00404140.mobys[i];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0xE29) {
            *(u16 *)(o + 0x34) |= 0x800;
        }
        if (*(s16 *)(o + 0xAA) == 0xD54) {
            o[0x63] = 0;
            for (i2 = 0; D_L08_002386F0_00404140[i2] != 0; i2++) {
                if (D_L08_002386F0_00404140[i2][0x63] != 0) {
                    D_L08_002386F0_00404140[i2][0x63] = 1;
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
            func_L01_0044EB38(o, D_L08_001D6A90_00404140, 0x80505080, 0x80404038, 0.031997703f);
        } else if (t == 0x1977) {
            func_L01_0044EB38(o, D_L08_001D6A94_00404140, 0x8080AAAA, 0x80464646, 0.0378154702f);
        } else if (t == 0x1766) {
            func_L01_0044EB38(o, D_L08_001D6A98_00404140, 0x80AAAAFF, 0x80646496, 0.110537529f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00402498(func_L01_00421438, o);
        }
    }
    if (D_001D545C == 8) {
        if (D_L08_001E6080_00404140.mode == 1 && D_L08_001E6080_00404140.timer == 0x34F) {
            *(u128_t_407380 *)&d = 0;
            d.x = -0.6f;
            d.z = -1.0f;
            func_L08_00403E80(2, &d, 0xF, 5, 0x64, 0x32, 0x20208000, 0x20408020, 0x50408020, 1.0f, 1.0f);
        }
    }
}
/* localdecomp:end func_L08_00404140 */
