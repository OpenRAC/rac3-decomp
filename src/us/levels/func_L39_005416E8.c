#include "common.h"
/* localdecomp:start func_L39_005416E8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00541F78;
typedef struct { u8 p0[0x14]; s32 x14; u8 x18; u8 x19; u16 x1A; u8 p1C[0xC]; s32 x28; u8 p2C[0x4]; } S_00541F78;
typedef struct { V_00541F78 v; s32 x10; f32 x14; u8 p18[0xC]; s32 x24; s32 x28; s32 x2C; s32 x30; u8 p34[4]; f32 x38; f32 x3C; } M_00541F78;
typedef struct { u8 p0[0x10]; V_00541F78 pos; u8 b20; u8 p21[0x89]; u16 xAA; u8 pAC[0x14]; u8 xC0[0x10]; u8 xD0[0x10]; u8 xE0[0x10]; } O_00541F78;
typedef struct { u8 p0[0x18]; s32 x18; u8 p1C[4]; u8 x20[0x10]; } G_00541F78;
extern u8 *D_L39_0024CF1C;
extern G_00541F78 D_L39_0025F840;
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L39_005FD658(s32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_L39_005FD6D8(void);
extern void func_003886E8(void *, void *, f32);
extern void func_003CF790(void *, s32, void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BD360(void *);
extern void func_00389158(void *, void *, void *, f32);
extern void func_L01_004026A0(void *, void *);
extern void func_L04_00353C08(f32, void *, u32, u32, u32, u32, u32);
extern void func_L04_00354758(void);

void func_L39_005416E8(O_00541F78 *o) {
    M_00541F78 *m = *(M_00541F78 **)((u8 *)o + 0x68);
    u8 *tgt = (u8 *)o;
    V_00541F78 v0; S_00541F78 s; V_00541F78 v40; S_00541F78 s2;
    s32 hit, a;
    void *p;

    if ((u32)m->x30 != 0xFFFFFFFF) {
        tgt = (u8 *)m->x10;
    }
    m->x24 = m->x24 + 1;
    if (m->x24 >= 0x45) {
        func_003BD360(o);
        return;
    }
    switch (o->b20) {
    case 0:
        m->x38 = m->x38 + m->x3C;
        vec_add_ba(&v0, &o->pos, m);
        func_L01_00443628(&s, o, m->x2C, m, m->x14);
        s.x1A = o->xAA;
        s.x28 = m->x30;
        s.x18 = 0;
        s.x19 = 1;
        a = -1; if (D_L39_0024CF1C != 0) { a = *(s32 *)(D_L39_0024CF1C + 0x2548); }
        func_L39_005FD658(a);
        hit = func_003CE740(&o->pos, &v0, 0, tgt, &s);
        func_L39_005FD6D8();
        if (hit != 0) {
            if (D_L39_0025F840.x18 != 0) {
                if (D_L39_0025F840.x18 != m->x10) {
                    v40 = m->v;
                    func_003886E8(&v40, &v40, 2.0f);
                    tgt = D_L39_0025F840.x20;
                    v40.w = 5627.9248f;
                    func_L01_00443628(&s2, o, m->x2C, &v40, m->x14);
                    s2.x19 = 1;
                    s2.x1A = o->xAA;
                    s2.x14 = 0x10001;
                    s2.x18 = 0;
                    s2.x28 = m->x30;
                    a = -1; if (D_L39_0024CF1C != 0) { a = *(s32 *)(D_L39_0024CF1C + 0x2548); }
                    func_L39_005FD658(a);
                    func_003CF790(tgt, 0, o, &s2, 1.0f);
                    func_L39_005FD6D8();
                    func_L01_00441FB8(o, 1, -1);
                    return;
                }
            } else {
                v40 = m->v;
                func_003886E8(&v40, &v40, 3.0f);
                p = D_L39_0025F840.x20;
                v40.w = 5627.9248f;
                func_L01_00443628(&s2, o, m->x2C, &v40, m->x14);
                s2.x19 = 1;
                s2.x1A = o->xAA;
                s2.x18 = 0;
                s2.x28 = m->x30;
                a = -1; if (D_L39_0024CF1C != 0) { a = *(s32 *)(D_L39_0024CF1C + 0x2548); }
                func_L39_005FD658(a);
                func_003CF790(p, 0, tgt, &s2, 2.0f);
                func_L39_005FD6D8();
                func_L01_00441FB8(o, 1, -1);
                return;
            }
        }
        o->pos = v0;
        func_003886E8(&v40, m, -0.5f);
        qzero(&s2);
        break;
    case 1:
        func_L04_00353C08(5.85f, (u8 *)o + 0x10, 0x803B0612, 0x80DA5615, 0x64FFFFFF, 0x507030FF, 0x320000FF);
        func_003BD360(o);
        return;
    default:
        break;
    }
    func_00389158(o->xE0, o->xE0, o->xD0, 0.0f);
    func_00389158(o->xC0, o->xC0, o->xD0, 0.0f);
    func_L01_004026A0(func_L04_00354758, o);
}
/* localdecomp:end func_L39_005416E8 */
