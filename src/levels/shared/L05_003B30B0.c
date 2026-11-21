#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003B30B0 */
typedef struct P_003B30B0 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    vu0_q v10;
    s32 f20;
    s32 f24;
    s32 f28;
    f32 f2c;
} P_003B30B0;
typedef struct Q_003B30B0 {
    u8 pad0[0x24];
    f32 f24;
} Q_003B30B0;
typedef struct M_003B30B0 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 b20;
    u8 b21;
    u8 pad22[2];
    Q_003B30B0 *p24;
    u8 pad28[4];
    f32 f2c;
    u8 b30;
    u8 pad31[3];
    u16 flags;
    u8 pad36[0x32];
    P_003B30B0 *p68;
    u8 pad6C[0xC];
    s32 r78;
    u8 pad7C[0x1A];
    u16 h96;
    u8 pad98[0x12];
    s16 id;
    u8 padAC[0x10];
    u8 bBC;
} M_003B30B0;

extern s32 D_001D545C;
extern f32 D_L05_001EA6E8[];
extern M_003B30B0 *D_L05_001DFB9C;
extern s16 *D_L05_0021DAE0[];

extern s32 func_L01_0044C108(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L01_00456230(void *, s32);
extern void func_L01_00445BE0(s32, s32);
extern void func_L03_004330B8(s32, s32);
extern s32 func_L05_003B2EF0(void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_0040F598(s32, s32);

void func_L05_003B30B0(M_003B30B0 *m) {
    P_003B30B0 *p;
    vu0_v4 a;
    vu0_v4 b;
    f32 f20;
    s32 c;
    s16 *l;
    M_003B30B0 *o;
    s32 st;

    if (func_L01_0044C108(&m->pos) == 0) {
        return;
    }
    p = m->p68;
    switch (m->b20) {
    case 0:
        *(vu0_q *)&b = *(vu0_q *)&a = *(vu0_q *)&m->pos;
        a.z = a.z - 1.0f;
        b.z = b.z + 1.0f;
        if (func_003D3CB0(&b, &a, 2, m, 0) != 0) {
            m->pos.z = D_L05_001EA6E8[0];
        }
        if (p->f20 != 0) {
            m->b30 = 0xFF;
        }
        m->pos.z = m->pos.z + (m->f2c * -0.36f) / m->p24->f24;
        p->v10 = *(vu0_q *)&m->pos;
        m->flags |= 0x10;
        func_L01_004450F0(m, 4, -1);
        break;
    case 1:
        func_L01_00456230(m, 1);
        *(vu0_q *)&a = p->v10;
        a.z = a.z - (m->f2c * 0.04f) / m->p24->f24;
        if (1.0f < (f32)m->h96++ / 12.833333f) {
            f20 = 1.0f;
        } else {
            f20 = (f32)m->h96++ / 12.833333f;
        }
        vec_sub_ba(&b, &a, &p->v10);
        func_0038CE20(&b, &b, f20);
        vec_add_ab(&m->pos, &p->v10, &b);
        if (1.0f <= f20) {
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 3:
        *(vu0_q *)&a = p->v10;
        a.z = a.z - (m->f2c * 0.04f) / m->p24->f24;
        if (1.0f < (f32)m->h96++ / 12.833333f) {
            f20 = 0.0f;
        } else {
            f20 = 1.0f - (f32)m->h96++ / 12.833333f;
        }
        vec_sub_ba(&b, &a, &p->v10);
        func_0038CE20(&b, &b, f20);
        vec_add_ab(&m->pos, &p->v10, &b);
        if (f20 <= 0.0f) {
            func_L01_004450F0(m, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            p->f28 = p->f8;
            p->f0 = 0;
            *(vu0_q *)&m->pos = p->v10;
            func_L01_00456230(m, 0);
            if (m->b21 != 0xFF) {
                func_L01_00445BE0(m->b21, 0);
                func_L03_004330B8(m->b21, 0);
            }
        }
        if (func_L05_003B2EF0(m) != 0) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            *(vu0_q *)&m->pos = p->v10;
            m->pos.z = m->pos.z - (m->f2c * 0.04f) / m->p24->f24;
            p->f0 = 1;
            p->f28 = p->f4;
            func_003A52A0(0, 0, m);
            func_L01_00456230(m, 1);
            if (m->b21 != 0xFF) {
                if (m->bBC == 0) {
                    func_003A52A0(0, 0, m);
                }
                func_L01_00445BE0(m->b21, 1);
                func_L03_004330B8(m->b21, 1);
            }
        }
        if (p->fC == 0 && func_L05_003B2EF0(m) == 0) {
            func_L01_004450F0(m, 3, -1);
        }
        break;
    }
    if (D_001D545C == 5 && m->b21 != 0xFF) {
        l = D_L05_0021DAE0[m->b21];
        do {
            o = (M_003B30B0 *)((u8 *)D_L05_001DFB9C + ((*(u16 *)l & 0x7FFF) << 8));
            if (o->id == 0x1618) {
                st = m->b20;
                if (st < 4) {
                    if (st != 0) {
                        o->h96 = 0;
                    }
                }
                if (o->b20 >= 2) {
                    p->f28 = p->f4;
                } else {
                    p->f28 = p->f8;
                }
            }
        } while (*l++ >= 0);
    }
    if (p->f28 == p->f4) {
        p->f2c = p->f2c + 0.03f;
        if (1.0f < p->f2c) {
            p->f2c = 1.0f;
        }
    } else {
        p->f2c = p->f2c - 0.03f;
        if (p->f2c < 0.0f) {
            p->f2c = 0.0f;
        }
    }
    c = func_0038DBD8(p->f8, p->f4, p->f2c);
    if (func_0038CAD0(&p->f24) != 0) {
        p->f24 = 0x32;
    }
    f20 = func_0038D0B0((f32)p->f24 * 6.2831855f / 50.0f) * 0.5f;
    f20 = f20 + 0.5f;
    {
        s32 x = func_L01_0040F598(c, 0x80B0B0B0);
        m->r78 = func_0038DBD8(x, func_L01_0040F598(c, 0x80505050), f20);
    }
}
/* localdecomp:end func_L05_003B30B0 */
