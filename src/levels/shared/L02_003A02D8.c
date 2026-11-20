#include "common.h"

typedef struct {
    u8 pad0[16];
    s32 unk10;
} C39E3B8;
typedef struct {
    u8 pad0[220];
    s32 unkDC;
} V39E3B8;
typedef struct {
    u8 pad0[36];
    C39E3B8 *unk24;
    u8 pad28[52 - 40];
    u16 unk34;
    u8 pad36[104 - 54];
    V39E3B8 *pVars;
    u8 pad6C[152 - 108];
    s32 unk98;
    u8 pad9C[256 - 156];
} M39E3B8;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} V_003A0200;
typedef struct {
    u8 pad0[0x24];
    f32 f24;
} C_003A0200;
typedef struct {
    u8 pad0[0x36];
    s16 f36;
    u8 pad38[0x100 - 0x38];
} M_003A0200;
typedef struct {
    u8 pad0[0x24];
    C_003A0200 *f24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[0x43 - 0x30];
    u8 f43;
    u8 pad44[0x68 - 0x44];
    V_003A0200 *f68;
} O_003A0200;

/* declared by functions of L02_003A0158.c, which this file was cut from */
extern void func_003C3A10(O_003A0200 *, s32, s32, s32);
extern void func_L01_004450F0(O_003A0200 *, s32, s32);

/* localdecomp:start func_L02_003A02D8 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_003A02D8;

typedef struct {
    s32 f0;
    s32 f4;
    f32 f8;
    f32 fC;
    u8 pad10[8];
    u8 f18;
    u8 pad19;
    u8 f1A;
    u8 f1B;
    s32 f1C;
    Vec_003A02D8 f20;
} V_003A02D8;

typedef struct {
    u8 pad0[0xDC];
    s32 fDC;
    u8 padE0[0x100 - 0xE0];
    Vec_003A02D8 f100;
    u8 pad110[0x10];
    void *f120;
} P_003A02D8;

typedef struct {
    u8 pad0[0x10];
    Vec_003A02D8 pos;
    u8 f20;
    u8 pad21[0x43 - 0x21];
    u8 f43;
    u8 pad44[0x68 - 0x44];
    void *vars;
    u8 pad6C[0x95 - 0x6C];
    u8 f95;
    u8 pad96[0x100 - 0x96];
} Mob_003A02D8;

extern u8 D_001A4C60[];
extern u8 D_L02_001E1300[];
extern Mob_003A02D8 *D_L02_001DE99C_003A02D8;
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_0033D178(void *);
extern void func_003C3A10(O_003A0200 *, s32, s32, s32);
extern void func_L01_004450F0(O_003A0200 *, s32, s32);

static __inline__ Mob_003A02D8 *target_003A02D8(V_003A02D8 *v) {
    if (v->f18) {
        return D_L02_001DE99C_003A02D8 + v->f4;
    }
    return D_L02_001DE99C_003A02D8 + v->f0;
}

s32 func_L02_003A02D8(Mob_003A02D8 *obj, s32 a1) {
    V_003A02D8 *v;
    Mob_003A02D8 *m;
    P_003A02D8 *pv;

    if (func_0038CF38(&obj->pos, D_001A4C60) < 3.0f) {
        return 0;
    }
    if (func_0038CF38(&obj->pos, D_L02_001E1300) < 3.0f) {
        return 0;
    }
    v = obj->vars;
    if (v->f1A == 0xFF || v->f1B < v->f1A) {
        v->f18 = a1 & 1;
        if (obj->f20 != 1) {
            return 0;
        }
        if (obj->f95 != 1) {
            return 0;
        }
        if (func_L01_0033D178(D_L02_001DE99C_003A02D8 + v->f0) != 0) {
            if (v->f4 != -1) {
                if (func_L01_0033D178(D_L02_001DE99C_003A02D8 + v->f4) == 0) {
                    return 0;
                }
            }
            m = target_003A02D8(v);
            m->pos = obj->pos;
            pv = m->vars;
            pv->fDC = 0;
            if (v->f1C >= 0) {
                pv->f120 = D_L02_001DE99C_003A02D8 + v->f1C;
                pv->f100 = v->f20;
            }
            v->f8 = 0.0f;
            v->fC = 0.0f;
            if (obj->f43 != 1) {
                func_003C3A10((O_003A0200 *)obj, 1, 0, 0);
            }
            func_L01_004450F0((O_003A0200 *)obj, 1, 2);
            if (v->f1A != 0xFF) {
                v->f1B++;
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L02_003A02D8 */
