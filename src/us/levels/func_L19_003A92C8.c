#include "common.h"

/* NTSC-U counterpart of func_L19_003AAEA0 (src/levels/shared/L19_003AAEA0.c) */
/* localdecomp:start func_L19_003A92C8 */
#include "vu0.h"

typedef struct M_003AAEA0 {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 b20;
    u8 p21[0x21];
    u8 b42;
    u8 b43;
    u8 p44[0x1C];
    u8 b60;
    u8 p61[7];
    void *w68;
    u8 p6C[0x29];
    u8 b95;
    u8 p96[0x14];
    s16 hAA;
} M_003AAEA0;

typedef struct {
    u8 p0[0xA4];
    f32 fA4;
    u8 pA8[0x188];
    M_003AAEA0 *w230;
    s16 h234;
    u8 p236[0xA];
    s32 w240;
    s32 w244;
    f32 f248;
    s32 w24C;
    f32 f250;
    f32 f254;
    f32 f258;
    u8 p25C[8];
    s32 w264;
    s32 w268;
    f32 f26C;
    s32 w270;
    s32 w274;
    s32 w278;
    s32 w27C;
    u8 p280[8];
    f32 f288;
    u8 p28C[4];
    u8 x290[0x20];
    u8 x2B0[4];
} V_003AAEA0;

typedef struct {
    s32 n;
    s32 pad[3];
    vu0_v4 pt[1];
} P_003AAEA0;

extern u8 D_001A30B0[];
extern P_003AAEA0 *D_L19_0021D500_003A92C8[];
extern s32 D_L19_001DE5A4;
extern s32 D_L19_001DE5A0;
extern f32 D_L19_001DE598;
__asm__(".extern D_L19_001DE5A4, 4");
__asm__(".extern D_L19_001DE5A0, 4");
__asm__(".extern D_L19_001DE598, 4");

extern s32 func_L01_00448E90(void *);
extern s32 func_L19_003A9BF8();
extern void func_003BD360(void *);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern void func_00389018(void *, s32, f32);
extern u8 *func_0037E0B8(void *);
extern void func_L01_00457440(void *, void *);
extern f32 func_003887A0(void *);
extern void func_003BEC60(f32 *, f32, f32 *, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00457728(void *, void *);
extern f32 func_00388A28(f32, f32);
extern s32 func_L01_00458A08(void *, f32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00457590(void *, void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_00388398(void *);
extern f32 func_L01_00436500(void *);
extern void func_003BD9A0(void *, s32, void *);
extern void func_003886E8(void *, void *, f32);
extern char *func_L19_003B65B0(s32, void *, void *, s32, s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00402498(void *, void *);
extern void func_L19_003AA000(void *);
extern void func_L19_003A9F10(void *);

void func_L19_003A92C8(M_003AAEA0 *m) {
    V_003AAEA0 *v;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 mtx[4];
    vu0_v4 c;
    f32 speed;
    u8 *e;
    s32 h;

    if (func_L01_00448E90(&m->pos) == 0) {
        return;
    }
    v = m->w68;
    if (func_L19_003A9BF8(m) != 0) {
        func_003BD360(m);
        return;
    }
    switch (m->b95) {
    case 1:
        if (func_L01_00452EF0(m) != 0) {
            if (m->b43 != 0) {
                func_003BE4F0(m, 0, 0, 6);
            }
            h = v->w278;
            if (h != -1) {
                e = D_001A30B0 + (h << 7);
                if (*(void **)(e + 0xDC) == m && e[0xD0] != 0) {
                    func_0039FB08(h);
                }
            }
            v->w278 = -1;
        }
        {
            s32 h2 = v->w278;
            u8 *e2;
            if (h2 == -1 || (e2 = D_001A30B0 + (h2 << 7), *(void **)(e2 + 0xDC) != m) || e2[0xD0] == 0) {
                v->w278 = func_0039FE80(0, 4, m);
            }
        }
        if (v->w27C > 0) {
            v->h234 = 0;
            v->w230 = 0;
        }
        if (v->h234 == 1) {
            v->w27C = 600;
            func_L01_00441FB8(m, 3, 2);
        }
        func_L01_00445758(&v->f254, 1.5707964f, &v->f250, 0.00043633234f, 0.00043633234f, 0.026179942f, 0);
        func_00389018(v->x2B0, 1, v->f254);
        break;
    case 2:
        if (func_L01_00452EF0(m) != 0) {
            h = v->w278;
            if (h != -1) {
                e = D_001A30B0 + (h << 7);
                if (*(void **)(e + 0xDC) == m && e[0xD0] != 0) {
                    func_0039FB08(h);
                }
            }
            v->w278 = -1;
        }
        {
            s32 h2 = v->w278;
            u8 *e2;
            if (h2 == -1 || (e2 = D_001A30B0 + (h2 << 7), *(void **)(e2 + 0xDC) != m) || e2[0xD0] == 0) {
                v->w278 = func_0039FE80(2, 4, m);
            }
        }
        if (v->w230 != 0) {
            u8 *p = func_0037E0B8(v->w230);
            if (p != 0) {
                p[0x31] = 0xFF;
            }
        }
        if (v->h234 == 0 || v->w27C == 0) {
            v->w27C = 600;
            func_L01_00441FB8(m, 4, 1);
        }
        break;
    case 3:
        break;
    }

    switch (m->b20) {
    case 1:
        func_L01_00452EC8(m);
        if (v->w244 >= 0) {
            func_L01_00441FB8(m, 2, -1);
        } else {
            func_L01_00457440(m, v->x290);
        }
        break;
    case 2: {
        P_003AAEA0 *path = D_L19_0021D500_003A92C8[v->w244];
        s32 dir = (v->w264 < v->w268) ? -1 : 1;
        s32 next = v->w268 + dir;
        f32 len;
        a = *(path->pt + next);
        vec_sub_ba(&b, &a, &m->pos);
        len = func_003887A0(&b);
        speed = 0.0f;
        func_003BEC60(&speed, len, &v->f26C, 0.0016666667f, 0.0016666667f, 0.050000004f);
        func_00388830(&b, &b, speed);
        func_L01_00457728(m, &b);
        func_L01_00458A08(m, func_00388A28(b.x, b.y));
        vec_sub_ba(&b, &m->pos, &a);
        if (len < speed || func_003887A0(&b) < v->fA4) {
            v->w268 = next;
            if ((dir > 0 && next >= path->n - 1) || (dir < 0 && next <= 0)) {
                speed = 0.0f;
                v->w264 = (dir > 0) ? 0 : path->n - 1;
            }
        }
        break;
    }
    case 3:
        if (func_L01_00452EC8(m) != 0) {
            v->w274 = 1;
            if (m->b43 != 1) {
                func_003BE4F0(m, 1, 0, 6);
            }
        } else if (m->b60 & 2) {
            v->w240 = 1;
            func_L01_00441FB8(m, 5, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(m) != 0) {
            v->w274 = 0;
            if (m->b43 != 5) {
                func_003BE4F0(m, 5, 0, 6);
            }
        } else if (m->b60 & 2) {
            v->w240 = 0;
            func_L01_00441FB8(m, 1, 1);
        }
        break;
    case 5:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b43 != 2) {
                func_003BE4F0(m, 2, 0, 6);
            }
            v->w270 = D_L19_001DE5A4;
        }
        if (func_00388800(&m->pos, &v->w230->pos) > 8.0f) {
            func_L01_00441FB8(m, 6, -1);
        }
        func_L01_00457590(m, &m->pos, func_00388A28(v->w230->pos.x - m->pos.x, v->w230->pos.y - m->pos.y));
        func_003BDA38(m, 0, &a);
        {
            f32 d = func_00388800(&a, &v->w230->pos);
            f32 ang = -func_00388A28(d, v->w230->pos.z - a.z);
            func_L01_00445758(&v->f254, ang, &v->f250, 0.00043633234f, 0.00043633234f, 0.026179942f, 0);
        }
        func_00389018(v->x2B0, 1, v->f254);
        if (func_00388398(&v->w270) != 0) {
            func_003BE4F0(m, 3, 0, 6);
            v->w24C = 1;
            v->w270 = D_L19_001DE5A4;
        }
        if (v->w24C != 0 && func_L01_00436500(m) > (f32)D_L19_001DE5A0) {
            s32 i;
            v->w24C = 0;
            for (i = 6; i < 8; i++) {
                s32 t;
                s32 k;
                func_003BD9A0(m, i, mtx);
                vec_sub_ba(&a, &v->w230->pos, &m->pos);
                func_003886E8(&a, &a, 1.1f);
                vec_add_ba(&b, &m->pos, &a);
                b.z += 0.3f;
                vec_sub_ab(&c, &b, &mtx[3]);
                func_00388830(&c, &c, D_L19_001DE598);
                t = v->w230->hAA;
                k = 0;
                if (t == 0x57) {
                    k = 1;
                }
                if (t == 0x1AA0) {
                    k = 2;
                }
                if (t == 0x1BD3) {
                    k = 2;
                }
                func_L19_003B65B0((s32)m, &mtx[3], &c, (s32)v->w230, 120, k);
            }
        }
        if (m->b42 == 3 && (m->b60 & 2) && m->b43 != 2) {
            func_003BE4F0(m, 2, 0, 6);
        }
        break;
    case 6:
        func_L01_00457440(m, &v->w230->pos);
        if (func_00388800(&m->pos, &v->w230->pos) < 8.0f) {
            func_L01_00441FB8(m, 5, -1);
        }
        break;
    case 7:
        break;
    }

    a = m->pos;
    func_003BEC60(&a.z, v->f288 + v->f258 + func_0037E250(-0.1f, 0.1f), &v->f248, 0.0011111111f, 0.0011111111f, 0.033333335f);
    vec_sub_ab(&b, &a, &m->pos);
    func_L01_00457728(m, &b);
    func_L01_00402498(func_L19_003AA000, m);
    func_L19_003A9F10(m);
}
/* localdecomp:end func_L19_003A92C8 */
