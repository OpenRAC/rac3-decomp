#include "common.h"

/* localdecomp:start func_L39_00563370 */
#include "vu0.h"

extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_L01_004C93E0(s32);
extern f32 func_L01_004C93D8(void);
extern void func_L39_005F33E0(s32, s32, void *);
extern f32 D_L39_0024B518;
__asm__(".extern D_L39_0024B518, 4");
extern f32 D_L39_0024D714;
extern u8 D_L39_003CCF80[];
extern vu0_v4 D_L39_0024D640 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D640, 16");
extern vu0_v4 D_L39_0024D650 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D650, 16");
extern vu0_v4 D_L39_0024D660 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D660, 16");
extern u8 D_L39_0024D670[] __attribute__((section(".sdata")));
extern s32 D_L39_0024D680[] __attribute__((section(".sdata")));
extern s32 D_L39_0024D690[] __attribute__((section(".sdata")));
extern s16 D_L39_0024D6D0[] __attribute__((section(".sdata")));

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
} V_00563370;

u8 *func_L39_00563370(u8 *arg0)
{
    u8 *m;
    V_00563370 *v;
    u8 *b;
    vu0_v4 *r2;

    m = func_003C24B0(0x1B37, 0x80);
    if (m != 0) {
        v = *(V_00563370 **)(m + 0x68);
        v->f40 = arg0;
        m[0x30] = 0xFF;
        m[0x20] = 1;
        *(u16 *)(m + 0x34) |= 0x41;
        func_0038D308(m + 0xC0, m + 0xF0);
        {
            s32 j;

            for (j = 3; j >= 0; j--) {
                D_L39_0024D680[j] = 0;
            }
        }
        b = D_L39_003CCF80;
        func_0038CF68(b, m + 0xC0, D_L39_0024B518);
        r2 = (vu0_v4 *)(m + 0xE0);
        D_L39_0024D640 = *r2;
        func_0038CF68(b + 0x140, m + 0xD0, D_L39_0024B518);
        D_L39_0024D650 = *(vu0_v4 *)(m + 0xC0);
        func_0038CF68(b + 0x280, r2, D_L39_0024B518);
        D_L39_0024D660 = *(vu0_v4 *)(m + 0xD0);
        vec_add_ba(b + 0x3C0, m + 0xC0, r2);
        func_0038CF68(b + 0x3C0, b + 0x3C0, D_L39_0024B518);
        func_0038CE90(D_L39_0024D670, b + 0x3C0, m + 0xD0);
        {
            s32 j;

            for (j = 7; j >= 0; j--) {
                D_L39_0024D690[j] = 0;
            }
        }
        {
            s32 j;

            for (j = 4; j >= 0; j--) {
                D_L39_0024D6D0[j] = 0;
            }
        }
        D_L39_0024D714 = 1.0f;
        func_L01_004C93E0(0);
        v->f0 = func_L01_004C93D8();
        *(vu0_v4 *)(m + 0x10) = *(vu0_v4 *)(v->f40 + 0xA0);
        v->fC = -1;
        v->f10 = 0;
        v->f14 = 0x19;
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
        func_L39_005F33E0(1, 0, m);
    }
    return m;
}
/* localdecomp:end func_L39_00563370 */

INCLUDE_ASM("asm/levels", func_L39_005635D0);
