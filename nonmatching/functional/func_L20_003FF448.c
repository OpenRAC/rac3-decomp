/* functional: high. Same calls/stores/order as retail; vector ops via COP2 asm; only register allocation and scheduling differ. */
#include "vu0.h"
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void *func_L05_00468EA8(void *, void *, void *, s32, s32);
extern vu0_v4 D_L20_001E2E00;
extern vu0_v4 D_L20_001DF6D0[2];
extern s32 D_L20_001DF6B0;
extern f32 D_L20_001DF6B4;
extern f32 D_L20_001DF6B8;
extern f32 D_L20_001DF6BC;
extern f32 D_L20_001DF6C0;
extern f32 D_L20_001DF6C4;
extern f32 D_L20_001DF6C8;
extern u8 D_L20_001DF698[];
void func_L20_003FF448(void *arg) {
    vu0_v4 dir;
    vu0_v4 pos;
    vu0_v4 mat[4];
    vu0_v4 off;
    vu0_v4 delta;
    vu0_v4 target;
    u8 *v = *(u8 **)((u8 *)arg + 0x68);
    s32 i, j, flag;
    *(vu0_q *)&dir = 0;
    for (i = 0; i < 2; i++) {
        func_003C2F58(*(void **)(v + 0x3EC), 2, &pos);
        func_003C2EC0(*(void **)(v + 0x3EC), 2, mat);
        func_0038D028(&off, &D_L20_001DF6D0[i], mat);
        __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%0\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0"
                : "+m"(pos) : "m"(off) : "vf1", "vf2");
        __asm__("lqc2 $vf1,0(%1)\n\tsqc2 $vf1,%0"
                : "=m"(target) : "r"(&D_L20_001E2E00), "m"(D_L20_001E2E00) : "vf1");
        __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf2,$vf1\n\tsqc2 $vf1,%0"
                : "=m"(delta) : "m"(pos), "m"(target) : "vf1", "vf2");
        func_0038CF68(&delta, &delta, D_L20_001DF6C8);
        __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0"
                : "=m"(pos) : "m"(pos), "m"(delta) : "vf1", "vf2");
        for (j = 0; j < D_L20_001DF6B0; j++) {
            func_003C4C18(&pos, D_L20_001DF6B4);
            dir.x = func_003824E0(D_L20_001DF6B8, D_L20_001DF6BC) * 0.020000001f;
            dir.y = func_003824E0(D_L20_001DF6B8, D_L20_001DF6BC) * 0.020000001f;
            dir.z = func_003824E0(D_L20_001DF6C0, D_L20_001DF6C4) * 0.020000001f;
            flag = func_00382468(2);
            func_L05_00468EA8(&pos, &dir, D_L20_001DF698, flag, func_00382468(3) - 1);
        }
    }
}
