#include "common.h"

/* NTSC-U counterpart of func_L39_00563370 (src/levels/shared/L39_00563370.c): f14 = 30 against PAL's 25 (60 Hz) */
/* localdecomp:start func_L39_00562850 */
#include "vu0.h"

extern u8 *func_003BCFB0(s32, s32);
extern void func_00388BD0(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_L01_004C5830(s32);
extern f32 func_L01_004C5828(void);
extern void func_L39_005F0CE0(s32, s32, void *);
extern f32 D_L39_0024B628;
__asm__(".extern D_L39_0024B628, 4");
extern f32 D_L39_0024D814;
extern u8 D_L39_003CD080[];
extern vu0_v4 D_L39_0024D740_00562850 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D740_00562850, 16");
extern vu0_v4 D_L39_0024D750 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D750, 16");
extern vu0_v4 D_L39_0024D760_00562850 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D760_00562850, 16");
extern u8 D_L39_0024D770_00562850[] __attribute__((section(".sdata")));
extern s32 D_L39_0024D780[] __attribute__((section(".sdata")));
extern s32 D_L39_0024D790[] __attribute__((section(".sdata")));
extern s16 D_L39_0024D7D0[] __attribute__((section(".sdata")));

typedef struct {
    f32 f0;
    s32 pad4[2];
    s32 fC;
    s32 f10;
    s32 f14;
    s16 a18[4];
    s32 a20[4];
    s32 pad30[4];
    u8 *f40;
} V_00562850;

u8 *func_L39_00562850(u8 *arg0)
{
    u8 *m;
    V_00562850 *v;
    u8 *b;
    vu0_v4 *r2;

    m = func_003BCFB0(0x1B37, 0x80);
    if (m != 0) {
        v = *(V_00562850 **)(m + 0x68);
        v->f40 = arg0;
        m[0x30] = 0xFF;
        m[0x20] = 1;
        *(u16 *)(m + 0x34) |= 0x41;
        func_00388BD0(m + 0xC0, m + 0xF0);
        {
            s32 j;

            for (j = 3; j >= 0; j--) {
                D_L39_0024D780[j] = 0;
            }
        }
        b = D_L39_003CD080;
        func_00388830(b, m + 0xC0, D_L39_0024B628);
        r2 = (vu0_v4 *)(m + 0xE0);
        D_L39_0024D740_00562850 = *r2;
        func_00388830(b + 0x140, m + 0xD0, D_L39_0024B628);
        D_L39_0024D750 = *(vu0_v4 *)(m + 0xC0);
        func_00388830(b + 0x280, r2, D_L39_0024B628);
        D_L39_0024D760_00562850 = *(vu0_v4 *)(m + 0xD0);
        vec_add_ba(b + 0x3C0, m + 0xC0, r2);
        func_00388830(b + 0x3C0, b + 0x3C0, D_L39_0024B628);
        func_00388758(D_L39_0024D770_00562850, b + 0x3C0, m + 0xD0);
        {
            s32 j;

            for (j = 7; j >= 0; j--) {
                D_L39_0024D790[j] = 0;
            }
        }
        {
            s32 j;

            for (j = 4; j >= 0; j--) {
                D_L39_0024D7D0[j] = 0;
            }
        }
        D_L39_0024D814 = 1.0f;
        func_L01_004C5830(0);
        v->f0 = func_L01_004C5828();
        *(vu0_v4 *)(m + 0x10) = *(vu0_v4 *)(v->f40 + 0xA0);
        v->fC = -1;
        v->f10 = 0;
        v->f14 = 0x1E;
        {
            s32 j;

            for (j = 3; j >= 0; j--) {
                v->a18[j] = 0;
            }
        }
        {
            s32 j;

            for (j = 3; j >= 0; j--) {
                v->a20[j] = 0;
            }
        }
        func_L39_005F0CE0(1, 0, m);
    }
    return m;
}
/* localdecomp:end func_L39_00562850 */
