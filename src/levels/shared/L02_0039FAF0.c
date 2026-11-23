#include "common.h"
#include "vu0.h"

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

/* localdecomp:start func_L02_0039FAF0 */
typedef struct {
    s32 w0;
    s32 w4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 pad14[3];
    u8 b17;
    u8 b18;
    u8 b19;
    u8 pad1A[2];
    s32 w1C;
    f32 v20[4];
} St_0039FAF0;
typedef struct Obj_0039FAF0 Obj_0039FAF0;
struct Obj_0039FAF0 {
    u8 pad0[0x10];
    f32 pos[4];
    u8 b20;
    u8 pad21[0x31 - 0x21];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x43 - 0x36];
    u8 b43;
    u8 pad44[0x60 - 0x44];
    u8 b60;
    u8 pad61[7];
    St_0039FAF0 *p68;
    u8 pad6C[0x95 - 0x6C];
    u8 b95;
    u8 pad96[0xB0 - 0x96];
    u8 bB0;
    u8 padB1[0xC0 - 0xB1];
    vu0_q m[3];
    u8 padF0[0x100 - 0xF0];
};
typedef struct {
    u8 pad0[0xDC];
    s32 wDC;
} V_0039FAF0;

extern Obj_0039FAF0 *D_L02_001DE99C;
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern s32 func_L01_0044C108(void *);
extern void func_L02_003A0030_0039FAF0(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L02_003A02D8(void *, s32);
extern void func_L02_00335DB0(void *);
extern void func_L02_003A0158(s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L02_003A0C18(void *);
extern void func_L02_003A0058(void *, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L02_003A0498(u8 *);
extern s32 func_00382468(s32);
extern void func_L02_003A0978(void *);
extern s32 func_L01_004561B8(void *);

void func_L02_0039FAF0(Obj_0039FAF0 *o) {
    St_0039FAF0 *s;
    Obj_0039FAF0 *m;
    Obj_0039FAF0 *n;
    f32 tmp[4];
    f32 r;
    V_0039FAF0 *p;

    if (func_L01_0044C108(o->pos) == 0) {
        return;
    }
    func_L02_003A0030_0039FAF0(o);
    s = o->p68;
    if (s->w1C >= 0) {
        m = D_L02_001DE99C;
        m = m + s->w1C;
        func_0038D000(tmp, s->v20, m->m);
        vec_add_ba(o->pos, tmp, m->pos);
        o->h34 |= 0x100;
        o->m[0] = m->m[0];
        o->m[1] = m->m[1];
        o->m[2] = m->m[2];
    }
    switch (o->b95) {
    case 1:
        if (s->b17 != 0 && o->b31 == 0) {
            if (s->b19 == 0 || (D_001BBC40[D_001D545C][o->bB0] & 0x80) == 0) {
                func_L02_003A02D8(o, 0);
            }
        }
        break;
    case 2:
        if (o->b60 & 2) {
            m = &D_L02_001DE99C[s->b18 != 0 ? s->w4 : s->w0];
            func_L02_00335DB0(m);
            func_L02_003A0158(s->b18 != 0 ? s->w4 : s->w0, 2);
            *(vu0_q *)m->pos = *(vu0_q *)o->pos;
            m->pos[2] += -1.1f;
            if (o->b43 != 2) {
                func_003C3A10(o, 2, 0, 0);
            }
            func_L01_004450F0(o, 2, 3);
        }
        break;
    case 3:
        if (o->b60 & 2) {
            if (o->b43 != 0) {
                func_003C3A10(o, 0, 0, 0);
            }
            o->b95 = 1;
        }
        break;
    }
    switch (o->b20) {
    case 1:
        break;
    case 2:
        r = func_0038DAB8(s->f10, 0.0628318563f);
        s->f10 = r;
        s->f8 += 0.030000001f;
        if (s->f8 >= 1.0f) {
            s->f8 = 1.0f;
        }
        if (s->f8 > 0.5f) {
            s->fC += 0.060000002f;
            if (s->fC >= 1.0f) {
                s->fC = 1.0f;
                func_L02_003A0C18(o);
                func_L01_004450F0(o, 3, -1);
            }
        }
        func_L02_003A0058(o, s->b18 != 0 ? s->w4 : s->w0, 1.0f, 0.1f, 1.0f, 3.0f, -0.55f, 3.0f, s->f8);
        func_L01_00404808(func_L02_003A0498, o);
        if (func_00382468(3) == 0) {
            func_L02_003A0978(o);
        }
        break;
    case 3:
        if (func_L01_004561B8(o) != 0) {
            s->f8 = 0;
        }
        s->f8 += 0.18f;
        if (s->f8 >= 1.0f) {
            s->f8 = 1.0f;
            func_L01_004450F0(o, 4, -1);
        }
        func_L02_003A0058(o, s->b18 != 0 ? s->w4 : s->w0, 0.1f, 2.0f, 3.0f, 0.5f, 3.0f, 3.0f, s->f8);
        break;
    case 4:
        if (func_L01_004561B8(o) != 0) {
            s->f8 = 0;
        }
        s->f8 += 0.096f;
        if (s->f8 >= 1.0f) {
            func_L02_003A0158(s->b18 != 0 ? s->w4 : s->w0, 0);
            s->f8 = 1.0f;
            func_L01_004450F0(o, 5, -1);
        }
        func_L02_003A0058(o, s->b18 != 0 ? s->w4 : s->w0, 2.0f, 1.0f, 0.5f, 1.0f, 3.0f, 3.0f, s->f8);
        break;
    case 5:
        n = &D_L02_001DE99C[s->b18 != 0 ? s->w4 : s->w0];
        if (fabs_asm(n->pos[2] - o->pos[2]) < 0.1f) {
            p = (V_0039FAF0 *)n->p68;
            if (s->w1C < 0) {
                p->wDC = 2;
            } else {
                p->wDC = 0;
            }
            func_L01_004450F0(o, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L02_0039FAF0 */
