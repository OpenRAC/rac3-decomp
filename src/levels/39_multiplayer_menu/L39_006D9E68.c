#include "common.h"

typedef struct Loc_006DA090 {
    s16 f00;
    u8 pad02[0x26];
    s32 f28;
    s32 f2C;
    u8 f30[0x40];
} Loc_006DA090;
typedef struct Obj_006DA090 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    s32 f50;
    s32 f54;
} Obj_006DA090;

/* declared by functions of L39_006D8E90.c, which this file was cut from */
extern Obj_006DA090 *D_L39_0024D760;
s32 func_001206F4(void *, s32);
void func_001961E8(void *);
s32 func_001961F8(void);
extern u16 D_L39_00249EE8[];
void func_L39_005958A0(void *, void *, s32);
extern Obj_006DA090 *D_L39_0024D760 __attribute__((section(".data")));

/* localdecomp:start func_L39_006D9E68 */
/* best: 75 diff with file flags (float 0.6f goes via $gp lit; --mode N --as ps2as builds it inline).
   Remaining: retail schedules lw 0x54 before the a3 branch and puts s0=0 / s2=0 in the jal / beqz delay
   slots; ours puts lw 0x54 in the bnez slot and leaves a nop. Tried: init placement, function-scope inits, switch. */
s32 func_L39_006DD608(s32, void *, s32);
s32 func_001206F4(void *, s32);
void func_L39_005958A0(void *, void *, s32);
void *func_0017EC38(void *);
void func_001961E8(void *);
s32 func_001961F8(void);
extern s32 func_L39_006D9328(void *, void *);
s32 func_00381FF0(s32);
void func_L39_006872E8(void *, s32, s32, s32, s32, f32);
extern void *D_001DC204_sda;
__asm__(".extern D_L39_0024D760, 16");
extern u16 D_L39_00249EE8[];

s32 func_L39_006D9E68(s32 a0, s32 a1, void *a2, s32 a3) {
    Loc_006DA090 loc;
    Obj_006DA090 *p;
    s32 r;
    s32 x;
    s32 y;
    void *z;

    p = D_L39_0024D760;
    x = p->f50;
    y = p->f54;
    z = *(void **)((u8 *)p + 0x48);
    if (!a3) {
        u8 *q = (u8 *)func_L39_006D9328(z, (void *)a1);
        s32 s1 = 0;
        s32 s2 = 0;
        if (q != 0) {
            s32 t = *(s32 *)(q + 0x40);
            if (t == 0) {
                s1 = func_00381FF0(0x1855);
            } else if (t == 3) {
                s1 = func_00381FF0(0x184F);
                s2 = func_00381FF0(0x1854);
            }
        }
        if (s1 != 0) {
            func_L39_006872E8(D_001DC204_sda, s1, s2, 4, 0, 0.6f);
            return 0;
        }
    }
    r = func_L39_006DD608(y, a2, 0);
    if (r != 0) {
        loc.f00 = D_L39_00249EE8[0];
        func_001206F4((u8 *)&loc + 0x15, x);
        loc.f28 = 1;
        loc.f2C = a1;
        func_L39_005958A0(loc.f30, a2, 0x40);
        func_001961E8(func_0017EC38(&loc));
        if (func_001961F8() != 0) {
            p->f10 = 0x3F;
            if (p->f14 == 0) {
                p->f14 = 0x3F;
            }
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D9E68 */
