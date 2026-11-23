#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { u8 pad0[0x44]; u16 x44; u8 pad46[2]; u8 *x48; u8 pad4C[8]; u8 *x54; u8 *x58; } Cls_3B57B8;
typedef struct { s32 count; u8 pad4[0xC]; V4 pts[1]; } Pts_3B57B8;
typedef struct {
    u8 pad0[0x30]; f32 x30; u8 pad34[0x160 - 0x34]; u8 a160[0xC0];
    V4 v220; s32 w230; s16 h234; u8 pad236[0x2C0 - 0x236];
    s32 x2C0; s32 x2C4; u8 pad2C8[4]; s32 x2CC; u8 pad2D0[0x2E0 - 0x2D0];
    s32 x2E0; s32 x2E4; s32 x2E8; f32 x2EC; u8 pad2F0[0x300 - 0x2F0];
    s32 x300; s32 x304; u8 pad308[0x320 - 0x308];
    V4 x320; V4 x330;
} Vars_3B57B8;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[3]; Cls_3B57B8 *cls; u8 pad28[0xC]; u16 flags;
    u8 pad36[0xC]; u8 b42; u8 b43; u8 pad44[4]; s32 x48; u8 pad4C[0x14]; u8 b60; u8 pad61[7];
    Vars_3B57B8 *vars; u8 pad6C[0x29]; u8 b95; u8 pad96[2]; s32 x98; u8 pad9C[0x20]; u8 bBC;
    u8 padBD[0x3B]; f32 fF8;
} Moby_3B57B8;

/* localdecomp:start func_L23_003B3EB0 */
#include "vu0.h"

extern s32 D_L23_001D6694;
extern f32 D_L23_001DE4B8;
__asm__(".extern D_L23_001DE4B8, 4");
extern f32 D_L23_001DE4F0;
__asm__(".extern D_L23_001DE4F0, 4");
extern s32 D_L23_001DE4E4;
__asm__(".extern D_L23_001DE4E4, 4");
extern f32 D_L23_001DE4E8;
__asm__(".extern D_L23_001DE4E8, 4");
extern Pts_3B57B8 *D_L23_0021D400[];
extern s32 func_L01_00448E90(void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_L23_003B4A40(void *);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00452EC8(void *);
extern f32 func_L01_00436500(void *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L23_003B3E58(unsigned char *);
extern void func_L23_003B3E80(char *, float);
extern void func_L23_003B5048(u8 *);
extern void func_L23_003B5138(void *);
extern void func_L23_003B5188(u8 *);
extern void func_L23_003B5348(u8 *);
extern s32 func_L01_00451078(void *, void *);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_L01_0044AF40(void *, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_L23_003B4E68(void *, void *, int, float, float);

void func_L23_003B3EB0(Moby_3B57B8 *m)
{
    Vars_3B57B8 *v;
    f32 a;
    f32 d;

    if (func_L01_00448E90(&m->pos) == 0)
        return;
    v = m->vars;
    if (D_L23_001D6694 == 2) {
        m->x98 = 0;
        m->flags = (m->flags | 0x41) & 0xEFFF;
        func_L01_004A6DF8(m, 1);
    } else {
        m->flags &= 0xFFBE;
        m->flags |= m->cls->x44 & 0x1000;
        m->x98 = *(s32 *)((u8 *)m->cls + 0x10);
    }
    func_L23_003B4A40(m);
    switch (m->b95) {
    case 2:
        if (v->h234 == 1) {
            func_L01_00441FB8(m, 7, 4);
            func_L23_003B5348(m);
        }
        break;
    case 3:
        if (func_L01_00452EF0(m) != 0)
            v->x2C4 = 600;
        if (v->h234 == 1) {
            func_L01_00441FB8(m, 7, 4);
            func_L23_003B5348(m);
        }
        if (v->x2C4 <= 0)
            func_L01_00441FB8(m, 4, 2);
        break;
    case 4:
        if (v->h234 == 0)
            func_L01_00441FB8(m, 6, 3);
        break;
    case 5:
        if (func_L01_00452EF0(m) != 0)
            func_L23_003B5348(m);
        break;
    }
    switch (m->b20) {
    case 1:
        if (func_L01_00452EC8(m) != 0) {
            m->x98 = 0;
            m->flags = (m->flags | 0x41) & 0xEFFF;
            func_L01_004A6DF8(m, 1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(m) != 0 || (m->b43 == 1 && (m->b60 & 2) && m->b42 == m->b43)) {
            if (m->b43 != 0)
                func_003BE4F0(m, 0, func_0037E1D8(m->cls->x48[0x10]), 10);
            v->x2C0 = func_0037E208(0xB4, 0x168);
        }
        if (v->x2C0 == 0) {
            v->x2C0 = -1;
            if (m->b43 != 1)
                func_003BE4F0(m, 1, 0, 10);
        }
        if (v->x2E4 != 0)
            func_L01_00441FB8(m, 5, 2);
        func_L23_003B3E58(m);
        break;
    case 5:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b43 != 3)
                func_003BE4F0(m, 3, func_0037E1D8(m->cls->x54[0x10]), 10);
            v->x2C0 = func_0037E208(0x168, 0x1E0);
            v->x320 = m->pos;
        }
        if (v->x2C0 == 0) {
            v->x2C0 = -1;
            if (m->b43 != 1)
                func_003BE4F0(m, 1, 0, 10);
        }
        if (m->b43 == 1) {
            if ((m->b60 & 2) && m->b42 == m->b43) {
                if (m->b42 != 3)
                    func_003BE4F0(m, 3, func_0037E1D8(m->cls->x54[0x10]), 10);
                v->x2C0 = func_0037E208(0x168, 0x1E0);
            }
            func_L23_003B3E58(m);
        } else {
            a = func_00388A28(v->x320.x - m->pos.x, v->x320.y - m->pos.y);
            func_L23_003B4E68(m, &v->x320, 1, a, 0.0f);
            d = func_L01_0040C040(&m->pos, &v->x320);
            if (d < D_L23_001DE4B8 * D_L23_001DE4B8) {
                if (v->x2E0 >= 0) {
                    Pts_3B57B8 *t = D_L23_0021D400[v->x2E0];
                    v->x320 = *(t->pts + v->x2E8);
                    v->x2E8++;
                    if (v->x2E8 >= t->count)
                        v->x2E8 = 0;
                } else {
                    a = func_0037E2A8();
                    v->x320.x = func_00388960(a) * v->x2EC;
                    v->x320.y = func_00388978(a) * v->x2EC;
                    v->x320.z = 0.0f;
                    vec_add_ab(&v->x320, &v->x320, &v->x330);
                }
            }
        }
        break;
    case 6:
        if (func_L01_00452EC8(m) != 0 || v->x2C0 <= 0) {
            if (m->b43 != 1)
                func_003BE4F0(m, 1, 0, 6);
        }
        if (m->b43 == 1) {
            if ((m->b60 & 2) && m->b42 == m->b43) {
                if (m->b42 != 0)
                    func_003BE4F0(m, 0, func_0037E1D8(m->cls->x48[0x10]), 6);
                v->x2C0 = func_0037E208(0x3C, 0xB4);
            }
        }
        func_L23_003B3E58(m);
        break;
    case 7:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b43 != 4)
                func_003BE4F0(m, 4, func_0037E1D8(m->cls->x58[0x10]), 6);
        }
        a = func_00388A28(m->pos.x - v->v220.x, m->pos.y - v->v220.y);
        v->x320.x = func_00388960(a) * D_L23_001DE4F0;
        v->x320.y = func_00388978(a) * D_L23_001DE4F0;
        v->x320.z = 0.0f;
        vec_add_ba(&v->x320, &v->x320, &v->v220);
        func_L23_003B4E68(m, &v->x320, 2, 0.0f, 0.0f);
        d = func_L01_0040C040(&m->pos, &v->x320);
        if (d < D_L23_001DE4B8 * D_L23_001DE4B8)
            func_L01_00441FB8(m, 8, -1);
        break;
    case 8:
        if (func_L01_00452EC8(m) != 0) {
            v->x2CC = 3;
            v->x300 = D_L23_001DE4E4;
            v->x304 = 0;
            if (m->b43 != 0)
                func_003BE4F0(m, 0, func_0037E1D8(m->cls->x48[0x10]), v->x300 >> 1);
        }
        if (v->x300 <= 0 && v->x2CC == 3) {
            v->x2CC = 1;
            if (m->b43 != 5)
                func_003BE4F0(m, 5, 0, 6);
        }
        if (m->b43 == 5 && m->b42 == m->b43) {
            f32 f = func_L01_00436500(m);
            if (func_L01_0044AF40(m, 2.0f) != 0) {
                a = func_00388A28(m->pos.x - v->v220.x, m->pos.y - v->v220.y);
                v->x320.x = func_00388960(a) * D_L23_001DE4E8;
                v->x320.y = func_00388978(a) * D_L23_001DE4E8;
                v->x320.z = 0.0f;
                vec_add_ab(&v->x320, &v->x320, &v->v220);
                v->x320.z = func_003BE7F0(&v->x320, 0, 0, 0.5f);
                if (fabs_asm(v->x320.z - m->pos.z) > 1.0f)
                    v->x320 = m->pos;
            }
            if (2.0f <= f && f <= 9.0f)
                func_L23_003B3E80(m, (f - 2.0f) / 7.0f);
            else
                func_L23_003B3E58(m);
        } else {
            func_L23_003B3E58(m);
        }
        if (m->b43 == 5 && func_L01_0044AF40(m, 28.0f) != 0)
            func_L01_00441FB8(m, 9, -1);
        func_L23_003B5048(m);
        break;
    case 9:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b43 != 6)
                func_003BE4F0(m, 6, 0, 6);
            v->x320 = m->pos;
            m->bBC = 0;
        }
        if (func_L01_0044AF40(m, 35.0f) != 0) {
            a = func_00389380(m->fF8, 3.1415927f);
            v->x320.x = func_00388960(a) * 2.0f;
            v->x320.y = func_00388978(a) * 2.0f;
            v->x320.z = 0.0f;
            vec_add_ab(&v->x320, &v->x320, &m->pos);
            v->x320.z = func_003BE7F0(&v->x320, 0, 0, 0.5f);
            if (fabs_asm(v->x320.z - m->pos.z) > 1.0f)
                v->x320 = m->pos;
        }
        d = func_L01_00436500(m);
        if (35.0f <= d && d <= 49.0f)
            func_L23_003B3E80(m, (d - 35.0f) / 14.0f);
        else
            func_L23_003B3E58(m);
        if (func_L01_0044AF40(m, 56.0f) != 0) {
            if (v->x304 != 0)
                func_L01_00441FB8(m, 10, -1);
            else
                func_L01_00441FB8(m, 7, -1);
        }
        break;
    case 10:
        if (func_L01_00452EC8(m) != 0 && m->b43 != 2)
            func_003BE4F0(m, 2, 0, 6);
        if (m->b42 == m->b43 && (m->b60 & 2))
            func_L01_00441FB8(m, 7, -1);
        func_L23_003B4E68(m, &m->pos, 0, func_00388A28(v->v220.x - m->pos.x, v->v220.y - m->pos.y), 0.0f);
        break;
    case 11: {
        s32 r = func_L01_00451078(m, v->a160);
        if (v->x30 <= 0.0f || (r & 1) != 0) {
            func_L01_00441FB8(m, 12, 5);
        } else if ((r & 2) != 0) {
            if (m->b95 == 4)
                func_L01_00441FB8(m, 8, -1);
            else
                func_L01_00441FB8(m, 6, 3);
        }
        break;
    }
    case 12:
        if (func_L01_00452EC8(m) != 0)
            func_L23_003B5188(m);
        break;
    }
    func_L23_003B5138(m);
}
/* localdecomp:end func_L23_003B3EB0 */
