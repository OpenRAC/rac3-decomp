#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003DDDE0 */
typedef struct P_3DDDE0 {
    u8 p0[0x30];
    vu0_v4 v30;
    u8 p40[0x2C];
    s32 w6c;
    vu0_v4 v70;
    vu0_v4 v80;
    s32 w90;
    f32 f94;
    f32 f98;
    s16 h9c;
    u8 b9e;
    u8 b9f;
    s32 wa0;
    s8 a4;
    s8 a5;
    s8 a6;
    s8 a7;
    u8 ba8;
    u8 ba9;
    u8 paA[2];
    s32 wac;
    s32 wb0;
    s32 wb4;
    s32 wb8;
} P_3DDDE0;
typedef struct O_3DDDE0 {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 b20;
    u8 p21[3];
    struct O_3DDDE0 *p24;
    u8 p28[0xC];
    u16 flags;
    u8 p36[0xC];
    u8 b42;
    u8 b43;
    u8 p44[4];
    s32 w48;
    u8 p4c[0x14];
    u8 b60;
    u8 p61[7];
    P_3DDDE0 *p68;
    u8 p6c[0x2A];
    u16 h96;
    s32 w98;
    u8 p9c[0xE];
    s16 id;
    u8 pac[4];
    u8 bb0;
    u8 pb1[0x1F];
    vu0_v4 vd0;
    u8 pe0[0x10];
    vu0_v4 vf0;
} O_3DDDE0;
typedef struct Q_3DDDE0 {
    u8 p0[0xD0];
    u8 bd0;
    u8 pd1[0xB];
    O_3DDDE0 *wdc;
    u8 pe0[0x20];
} Q_3DDDE0;
typedef struct A_3DDDE0 {
    u8 p0[0x35C];
    O_3DDDE0 *w35c;
    s32 w360;
    u8 p364[10];
    s16 h36e;
} A_3DDDE0;

extern s32 D_001D545C;
extern O_3DDDE0 *D_L05_001DFB9C;
extern u8 *D_L05_001DFC80;
extern u8 *D_L05_001DFC80_003DDDE0;
__asm__(".extern D_L05_001DFC80_003DDDE0, 16");
extern u8 D_L05_001BBC40[];
extern A_3DDDE0 D_001A4BE0;
extern u8 D_001A4BE0_003DDDE0[];
extern u8 D_001A4C60[];
extern u8 D_001A4CE0[];
extern u8 D_001A30B0[];
typedef struct { u8 b[0x80]; } Snd80_3DDDE0;
extern Snd80_3DDDE0 D_001A30B0_003DDDE0[];

extern s32 func_L01_004561B8(void *);
extern s32 func_L01_00456250(void *);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3938(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0043B510(s32);
extern void func_L05_00451150(void *, s32);
extern void func_L05_004512F8(void *, void *, void *, s32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern f32 func_0038D098(f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L05_003DDDE0(O_3DDDE0 *o) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    P_3DDDE0 *p;
    s32 s0;
    s32 s1;
    s32 a1;
    s32 a0;
    f32 f;
    u8 *qq;
    u8 *A;
    vu0_v4 *va;
    vu0_v4 *vb;
    u16 h;
    Snd80_3DDDE0 *e;

    h = o->h96;
    *(vu0_q *)&a = *(vu0_q *)&o->pos;
    p = o->p68;
    *(vu0_q *)&b = *(vu0_q *)&o->vf0;
    if (!(0xFFFE < h)) {
        o->h96 = h + 1;
    }
    switch (o->b20) {
    case 0:
        if (p->w90 == -1 && p->a4 == p->w90 && p->ba9 == 0) {
            o->flags |= 2;
            func_L01_004450F0(o, 6, -1);
            return;
        }
        if (p->wb8 != 0) {
            if (D_L05_001BBC40[o->bb0 + D_001D545C * 16] & 0x80) {
                p->wb4 = -1;
            }
        }
        p->w6c |= 1;
        p->f98 = 0.0f;
        *(vu0_q *)&p->v70 = *(vu0_q *)&o->pos;
        *(vu0_q *)&p->v80 = *(vu0_q *)&o->vf0;
        func_L05_00451150(o, p->h9c);
        if (o->bb0 != 0xFF && (D_L05_001BBC40[o->bb0 + D_001D545C * 16] & 0x80) && p->wb8 == 0) {
            if (p->w90 != -1) {
                *(vu0_q *)&o->pos = *(vu0_q *)(D_L05_001DFC80 + 0x30 + (p->w90 << 7));
                *(vu0_q *)&o->vf0 = *(vu0_q *)(D_L05_001DFC80_003DDDE0 + 0x70 + (p->w90 << 7));
            }
            o->flags |= 2;
            if (p->a6 != -1) {
                func_003C3938(o, p->a6, 0);
            }
            func_L01_004450F0(o, 5, -1);
        } else {
            if (p->a4 != -1) {
                func_003C3938(o, p->a4, 0);
            }
            func_L01_004450F0(o, 1, -1);
        }
        break;
    case 1:
        s1 = 1;
        if (o->b60 & 2) {
            if (p->a4 == -1) {
                o->w48 = 0;
            } else if (o->b43 != p->a4) {
                func_003C3A10(o, p->a4, 0, 5);
            } else {
                o->w48 = 0;
            }
        }
        if (p->a4 != -1) {
            if (o->b42 != p->a4) {
                s1 = 0;
            }
        }
        if (p->wb4 != -1) {
            if (func_L01_00456250((u8 *)D_L05_001DFB9C + (p->wb4 << 8)) == 0) {
                s1 = 0;
            }
        }
        if (p->wa0 != -1) {
            if (func_L01_00456500(D_001A4C60, p->wa0) != 0) {
                func_L01_00456230(o, 1);
            }
        }
        if (p->ba9 != 0) {
            if (D_001A4BE0.w35c == o && D_001A4BE0.w360 != 0 && D_001A4BE0.h36e == 0) {
                func_L01_00456230(o, 1);
            }
        }
        if (s1 != 0 && func_L01_00456250(o) != 0) {
            if (p->b9e != 0) {
                func_L01_0043B510(o->bb0);
            }
            if (p->a5 != -1 && o->b43 != p->a5) {
                func_003C3A10(o, p->a5, 0, 5);
            }
            func_L01_004450F0(o, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(o) != 0) {
            if (o->id == 0x166D || o->id == 0x166A || o->id == 0x1CB6 || o->id == 0x1D72 || o->id == 0x1D3D || o->id == 0x1618) {
                a0 = p->wac;
                if (a0 == -1 || *(O_3DDDE0 **)&(e = &D_001A30B0_003DDDE0[a0])->b[0xDC] != o || e->b[0xD0] == 0) {
                    p->wac = func_003A52A0(0, 4, o);
                }
            }
        }
        p->f98 = p->f98 + 1.0f / ((p->f94 * 5.0f + 2.0f) / 6.0f);
        if (1.0f < p->f98) {
            p->f98 = 1.0f;
        }
        func_L05_004512F8(o, &p->v70, &p->v80, p->w90, (1.0f - func_0038D098(p->f98 * 3.14159274f)) * 0.5f);
        if (o->b60 & 2) {
            if (p->a6 == -1) {
                o->w48 = 0;
            } else if (o->b43 != p->a6) {
                func_003C3A10(o, p->a6, 0, 5);
            } else {
                o->w48 = 0;
            }
        }
        if (1.0f <= p->f98) {
            a1 = p->wac;
            if (a1 != -1) {
                Snd80_3DDDE0 *e = &D_001A30B0_003DDDE0[a1];
                if (*(O_3DDDE0 **)&e->b[0xDC] == o && e->b[0xD0] != 0) {
                    func_003A4F28(a1);
                }
            }
            p->wac = -1;
            p->f98 = 1.0f;
            if (p->b9f != 0) {
                o->w98 = 0;
            }
            if (p->ba8 != 0) {
                func_L01_004450F0(o, 5, -1);
            } else {
                func_L01_004450F0(o, 3, -1);
            }
        }
        break;
    case 3:
        s0 = 1;
        if (o->b60 & 2) {
            if (p->a6 == -1) {
                o->w48 = 0;
            } else if (o->b43 != p->a6) {
                func_003C3A10(o, p->a6, 0, 5);
            } else {
                o->w48 = 0;
            }
        }
        if (p->a6 != -1) {
            if (o->b42 != p->a6) {
                s0 = 0;
            }
        }
        if (p->wa0 != -1) {
            if (func_L01_00456500(D_001A4C60, p->wa0) == 0) {
                func_L01_00456230(o, 0);
            }
        }
        if (p->wb0 != -1) {
            if ((p->wb0 * 5 + 2) / 6 < o->h96) {
                func_L01_00456230(o, 0);
            } else {
                func_L01_00456230(o, 1);
            }
        }
        if (s0 != 0 && func_L01_00456250(o) == 0) {
            if (p->b9e != 0) {
                func_L01_0043B510(o->bb0);
            }
            if (p->a7 != -1 && o->b43 != p->a7) {
                func_003C3A10(o, p->a7, 0, 5);
            }
            func_L01_004450F0(o, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(o) != 0) {
            if (o->id == 0x166D || o->id == 0x166A || o->id == 0x1CB6 || o->id == 0x1D72 || o->id == 0x1D3D || o->id == 0x1618) {
                a0 = p->wac;
                if (a0 == -1 || *(O_3DDDE0 **)&(e = &D_001A30B0_003DDDE0[a0])->b[0xDC] != o || e->b[0xD0] == 0) {
                    p->wac = func_003A52A0(0, 4, o);
                }
            }
        }
        p->f98 = p->f98 - 1.0f / ((p->f94 * 5.0f + 2.0f) / 6.0f);
        if (p->f98 < 0.0f) {
            p->f98 = 0.0f;
        }
        func_L05_004512F8(o, &p->v70, &p->v80, p->w90, (1.0f - func_0038D098(p->f98 * 3.14159274f)) * 0.5f);
        if (o->b60 & 2) {
            if (p->a4 == -1) {
                o->w48 = 0;
            } else if (o->b43 != p->a4) {
                func_003C3A10(o, p->a4, 0, 5);
            } else {
                o->w48 = 0;
            }
        }
        A = (u8 *)&D_001A4BE0_003DDDE0;
        if (*(O_3DDDE0 **)(A + 0x35C) == o) {
            vec_sub_ab(&c, A + 0x80, &o->pos);
            f = func_0038CE68(&c, &o->vd0);
            f = f < 0.0f ? p->f98 - 1.0f : 1.0f - p->f98;
            func_0038CE20(&c, &o->vd0, f);
            vec_add_ba(D_001A4CE0, D_001A4CE0, &c);
        }
        if (p->f98 <= 0.0f) {
            a1 = p->wac;
            if (a1 != -1) {
                Snd80_3DDDE0 *e = &D_001A30B0_003DDDE0[a1];
                if (*(O_3DDDE0 **)&e->b[0xDC] == o && e->b[0xD0] != 0) {
                    func_003A4F28(a1);
                }
            }
            p->wac = -1;
            p->f98 = 0.0f;
            if (p->b9f != 0) {
                o->w98 = *(s32 *)((u8 *)o->p24 + 0x10);
            }
            if (p->ba8 != 0) {
                func_L01_004450F0(o, 5, -1);
            } else {
                func_L01_004450F0(o, 1, -1);
            }
        }
        break;
    case 5:
        o->flags |= 2;
        break;
    }
    if (o->b20 < 5) {
        vec_sub_ba(&c, &o->pos, &a);
        func_003C4DA8(&p->v30, &c, &b, &o->vf0);
    }
}
/* localdecomp:end func_L05_003DDDE0 */
