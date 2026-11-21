#include "common.h"

/* NTSC-U counterpart of func_L39_0056CC48 (src/levels/shared/L39_0056CC48.c): 1817 -> 2180; 0.09 -> 0.075 */
/* localdecomp:start func_L39_0056BF58 */
#include "vu0.h"

typedef int u128_0056CC48 __attribute__((mode(TI)));

extern u8 D_L39_0024DF80[];
extern s32 D_L39_0024B968[2];
extern vu0_v4 D_L39_0025F860;
extern s32 D_L39_0024145C;
__asm__(".extern D_L39_0024145C, 16");
extern void func_00388830(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L01_003E2378(void *);
extern s32 func_L01_003F9498(void *, s32, u8 *, f32);
extern s32 func_L01_003E60C8(void *, s32, void *, f32);
extern s32 func_L01_003E5D00(void *, void *, s32, f32, f32);

s32 func_L39_0056BF58(u8 *a0) {
    vu0_v4 dir0;
    vu0_v4 pos;
    vu0_v4 dir;
    vu0_v4 step;
    vu0_v4 old;
    vu0_v4 d;
    u8 *m;
    u8 *cam;
    u8 *st;
    u8 *pl;
    u8 *pls;
    u8 *sub;
    s32 ret;
    s32 flag;
    s32 i;
    f32 sp;
    f32 dist;
    s32 *q;

    ret = 0;
    m = *(u8 **)(a0 + 0x70);
    sub = m + 0x60;
    cam = m + 0x180;
    *(u128_0056CC48 *)&dir0 = *(u128_0056CC48 *)(m + 0x180);
    st = m + 0x210;
    pl = D_L39_0024DF80 + *(s32 *)(a0 + 0x94) * 0x460;
    dist = 0.0f;
    *(u128_0056CC48 *)&pos = *(u128_0056CC48 *)(m + 0xB0);
    pls = pl + 0x150;
    func_00388830(&dir, &dir0, 1.0f);
    sp = 0.35f;
    flag = 0;
    if (D_L39_0024145C == 0x30 || D_L39_0024145C == 0x1C) {
        if (!(D_L39_0024B968[*(s32 *)(a0 + 0x94)] & 0x20)) {
            flag = 1;
            D_L39_0024B968[*(s32 *)(a0 + 0x94)] |= 0x20;
        }
    }
    for (i = 0; i < (s32)(*(f32 *)(st + 0x40) - 1.0f); i++) {
        if (i > 0 && func_L01_003E2378(&pos) == 0
            && func_L01_003F9498(&pos, D_L39_0024B968[*(s32 *)(a0 + 0x94)], *(u8 **)(pls + 0xF0), sp) != 0
            && func_L01_003E60C8(a0, i, &pos, sp) == 0) {
            *(u128_0056CC48 *)&step = *(u128_0056CC48 *)&D_L39_0025F860;
            *(u128_0056CC48 *)&old = *(u128_0056CC48 *)&pos;
            if (func_L01_003E5D00(a0, &pos, i, dist, sp) != 0) {
                ret = 1;
                if (fabs_asm(*(f32 *)(*(u8 **)(pls + 0x134) + 0x100)) > 0.05f) {
                    {
                        vu0_q qa, qb;
                        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(step));
                        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(old));
                        __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
                        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qa));
                    }
                    func_00388830(&d, &d, 1.0f);
                    if (fabs_asm(func_00388730(pl + 0x90, &d)) < 0.75f) {
                        *(s16 *)(st + 0x34) = 0x884;
                        *(f32 *)(st + 0x30) += 0.075000003f;
                        if (*(f32 *)(cam + 0x2C) - *(f32 *)(st + 0x30) < 0.2f) {
                            *(f32 *)(st + 0x30) = *(f32 *)(cam + 0x2C) - 0.2f;
                        }
                    }
                }
                {
                    vu0_q qa, qb;
                    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(pos));
                    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(sub + 0x50)));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
                    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qa));
                }
                func_00388830(cam, &d, *(f32 *)(cam + 0x2C) - *(f32 *)(st + 0x30));
                func_00388830(&dir, cam, 1.0f);
            }
        }
        sp += *(f32 *)(st + 0x44) * *(f32 *)(st + 0x3C);
        dist += sp;
        func_003886E8(&step, &dir, sp * ((*(f32 *)(cam + 0x2C) - *(f32 *)(st + 0x30)) / *(f32 *)(cam + 0x2C)));
        {
            vu0_q qa, qb;
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(pos));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(step));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(qa));
        }
    }
    if (D_L39_0024145C == 0x30 || D_L39_0024145C == 0x1C) {
        if (flag) {
            q = &D_L39_0024B968[*(s32 *)(a0 + 0x94)];
            *q &= ~0x20;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_0056BF58 */
