#include "common.h"
#include "vu0.h"
#include "structs/hero.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct {
    V4 a;
    V4 b;
    V4 c;
    V4 pos;
} Fx_3A5890;
typedef struct {
    u8 pad0[0xC];
    f32 xC;
    u8 pad10[6];
    u8 x16;
    u8 pad17[3];
    u8 x1A;
} Ent_3A5890;

/* localdecomp:start func_L23_003A5890 */
extern u16 **D_L23_001D676C;
__asm__(".extern D_L23_001D676C, 16");
extern u8 *D_L23_001DFF88;
__asm__(".extern D_L23_001DFF88, 16");
extern u8 *D_L23_001DFF90;
__asm__(".extern D_L23_001DFF90, 16");
extern u8 *D_L23_001DE310;
extern s32 D_L23_001DECC0;
extern struct Hero D_001A4BE0;
extern void func_L23_003A62D8(u8 *);
extern f32 func_L01_0040C040(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00389380(f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_L01_004A73F8(s32, s32, void *, s32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_00402498(void (*)(u8 *), u8 *);
extern void func_L23_003A53E0(u8 *, f32);
extern void func_L23_003A6038(u8 *);
extern u8 *func_L23_003A6150(u8 *, u8 *, vu0_q *);

void func_L23_003A5890(u8 *self)
{
    s32 *v = *(s32 **)(self + 0x68);
    Ent_3A5890 *e;
    Fx_3A5890 *m;
    f32 scale;
    s32 i;

    if (self[0x20] == 0) {
        func_L23_003A6038(self);
    } else if (self[0x20] == 2) {
        return;
    }
    if (v[0] >= 0 && D_L23_001DECC0 % 3 == 1) {
        u16 *p =  D_L23_001D676C[v[0]];
        while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D676C[v[0]])) {
            e = (Ent_3A5890 *)(D_L23_001DFF88 + ((*p & 0x7FFF) << 5));
            if (e == 0)
                break;
            if (!(e->x16 & 1)) {
                m = (Fx_3A5890 *)(D_L23_001DFF90 + ((*p & 0x7FFF) << 6));
                if ((fabs_asm(m->pos.z - D_001A4BE0.pos.z) < 0.5f &&
                     func_L01_0040C040(&m->pos, &D_001A4BE0.pos) < 4.0f) ||
                    (fabs_asm(m->pos.z - *(f32 *)(D_L23_001DE310 + 0x18)) < 0.5f &&
                     func_L01_0040C040(&m->pos, D_L23_001DE310 + 0x10) < 4.0f)) {
                    f32 ang;

                    func_L23_003A53E0((u8 *)&m->pos, e->xC * 0.75f);
                    scale = e->xC * 2.0f * func_0037E250(0.9f, 1.1f);
                    ang = func_0037E250(-3.1415927f, 3.1415927f);
                    m->a.x = func_00388960(ang) * scale;
                    m->a.y = func_00388978(ang) * scale;
                    m->a.z = 0.0f;
                    m->b.x = func_00388960(func_00389380(ang, 1.5707964f)) * scale;
                    m->b.y = func_00388978(func_00389380(ang, 1.5707964f)) * scale;
                    qzero(&m->c);
                    m->b.z = 0.0f;
                    m->c.z = scale;
                    m->pos.z += 0.2f / scale;
                    m->pos.w = 1.0f;
                    e->x16 |= 1;
                }
            }
            p++;
        }
    }
    if (v[1] >= 0 && D_L23_001DECC0 % 3 == 2) {
        u16 *p;
        s32 id;
        p =  D_L23_001D676C[v[1]];
        while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D676C[v[1]])) {
            id = *p & 0x7FFF;
            e = (Ent_3A5890 *)(D_L23_001DFF88 + (id << 5));
            if (e == 0)
                break;
            if (!(e->x16 & 1)) {
                V4 vel;
                V4 c1;
                V4 c2;
                s32 hit = 0;

                m = (Fx_3A5890 *)(D_L23_001DFF90 + (id << 6));
                if (fabs_asm(m->pos.z - D_001A4BE0.pos.z) < 0.5f &&
                    func_L01_0040C040(&m->pos, &D_001A4BE0.pos) < 4.0f) {
                    f32 ang;

                    hit = 1;
                    ang = func_00388A28(m->pos.x - D_001A4BE0.pos.x, m->pos.y - D_001A4BE0.pos.y);
                    func_00389380(ang, func_0037E250(-0.5235988f, 0.5235988f));
                    vel.x = func_00388960(ang) * func_0037E250(0.06666667f, 0.13333334f);
                    vel.y = func_00388978(ang) * func_0037E250(0.06666667f, 0.13333334f);
                    vel.z = 0.0f;
                    vec_add_ba(&vel, &vel, &D_001A4BE0.vel);
                    vel.z = 0.06666667f;
                } else if (fabs_asm(m->pos.z - *(f32 *)(D_L23_001DE310 + 0x18)) < 0.5f &&
                           func_L01_0040C040(&m->pos, D_L23_001DE310 + 0x10) < 4.0f) {
                    f32 ang;

                    hit = 1;
                    ang = func_00388A28(m->pos.x - *(f32 *)(D_L23_001DE310 + 0x10),
                                        m->pos.y - *(f32 *)(D_L23_001DE310 + 0x14));
                    func_00389380(ang, func_0037E250(-0.5235988f, 0.5235988f));
                    vel.x = func_00388960(ang) * func_0037E250(0.06666667f, 0.13333334f);
                    vel.y = func_00388978(ang) * func_0037E250(0.06666667f, 0.13333334f);
                    vel.z = 0.0f;
                    vec_add_ab(&vel, &vel, *(u8 **)(D_L23_001DE310 + 0x68) + 0x110);
                    vel.z = 0.06666667f;
                }
                if (hit) {
                    e->x16 |= 1;
                    func_L23_003A6150((u8 *)e, (u8 *)m, (vu0_q *)&vel);
                    func_L01_004A73F8(0x10, 0, 0, 0);
                    qzero(&c1);
                    qzero(&c2);
                    for (i = 0; i < 12; i++) {
                        c1.x = func_0037E250(-0.083333336f, 0.16666667f);
                        c1.y = func_0037E250(-0.083333336f, 0.16666667f);
                        c1.z = func_0037E250(0.083333336f, 0.16666667f);
                        c2.w = c1.w = func_0037E250(0.1f, 0.4f);
                        c2.z = 0.0f;
                        func_L01_0045FEC8(&m->pos, &c1, &c2,
                                          func_003894A0(0x80004080, 0x80408080, func_0037E250(0.0f, 1.0f)),
                                          func_003894A0(0x4080, 0x408080, func_0037E250(0.0f, 1.0f)),
                                          func_0037E208(1, 10), func_0037E208(10, 20),
                                          func_0037E208(15, 30), 0x1003C);
                    }
                }
            }
            p++;
        }
    }
    func_L01_00402498(func_L23_003A62D8, self);
}
/* localdecomp:end func_L23_003A5890 */
