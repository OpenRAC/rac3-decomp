/* NTSC-U draft (Claude wave K): C of func_L39_005416E8, the NTSC-U twin of func_L39_00541F78, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 135 words differ on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L39_005416E8", whose code is not the PAL one).
 * Worker's note: 135 raw diff lines, 36 aligned insns differ of 220 (register-blind 32; yours 218 vs retail 220), draft near/func_L39_005416E8.medium.c. FLAGS: the entry's flags have @ps2as but lack -mvu0-use-vf0-vf2 (vec_add_ba, qzero from vu0.h), so the best status is ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_00541F78 (src/levels/shared/...) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_005416E8 */
#include "vu0.h"
typedef struct {
    u128_t x0;
    u8 *x10;
    f32 x14;
    u8 pad18[0xC];
    s32 x24;
    u8 pad28[4];
    s32 x2C;
    u32 x30;
    u8 pad34[4];
    f32 x38;
    f32 x3C;
} M_005416E8;
typedef struct {
    u8 pad0[0x10];
    u128_t x10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    M_005416E8 *x68;
    u8 pad6C[0xAA - 0x6C];
    u16 xAA;
    u8 padAC[0xC0 - 0xAC];
    f32 xC0[4];
    f32 xD0[4];
    f32 xE0[4];
} O_005416E8;
typedef struct {
    u128_t x0;
    void *x10;
    s32 x14;
    u8 x18;
    u8 x19;
    u16 x1A;
    f32 x1C;
    s32 x20;
    u8 pad24[4];
    s32 x28;
    u8 pad2C[4];
} S_005416E8;
typedef struct {
    u8 pad0[0x18];
    s32 x18;
    s32 x1C;
    u128_t x20;
} G_005416E8;
extern u8 *D_L39_0024CF1C;
__asm__(".extern D_L39_0024CF1C, 16");
extern G_005416E8 D_L39_0025F840;
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L39_005FD658(s32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_L39_005FD6D8(void);
extern void func_003886E8(void *, void *, f32);
extern void func_003CF790(void *, s32, void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L04_00353C08(void *, s32, s32, s32, s32, s32, f32);
extern void func_003BD360(void *);
extern void func_00389158(void *, void *, void *, f32);
extern void func_L01_004026A0(void *, void *);
extern void func_L39_00541D00(void);

void func_L39_005416E8(O_005416E8 *o) {
    M_005416E8 *m;
    u8 *tgt;
    vu0_v4 v0;
    S_005416E8 s;
    vu0_v4 v40;
    S_005416E8 s2;
    s32 hit;
    s32 a;
    u128_t *hp;

    m = o->x68;
    tgt = (u8 *)o;
    if (m->x30 != 0xFFFFFFFF) {
        tgt = m->x10;
    }
    m->x24 = m->x24 + 1;
    if (m->x24 >= 0x45) {
        func_003BD360(o);
        return;
    }
    switch (o->b20) {
    case 0:
        m->x38 = m->x38 + m->x3C;
        vec_add_ba(&v0, &o->x10, m);
        func_L01_00443628(&s, o, m->x2C, m, m->x14);
        s.x1A = o->xAA;
        s.x18 = 0;
        s.x28 = m->x30;
        s.x19 = 1;
        a = -1;
        if (D_L39_0024CF1C != 0) {
            a = *(s32 *)(D_L39_0024CF1C + 0x2548);
        }
        func_L39_005FD658(a);
        hit = func_003CE740(&o->x10, &v0, 0, tgt, &s);
        func_L39_005FD6D8();
        if (hit != 0) {
            if (D_L39_0025F840.x18 != 0) {
                if (D_L39_0025F840.x18 != (s32)m->x10) {
                    *(u128_t *)&v40 = m->x0;
                    func_003886E8(&v40, &v40, 2.0f);
                    hp = &D_L39_0025F840.x20;
                    v40.w = 5627.9248f;
                    func_L01_00443628(&s2, o, m->x2C, &v40, m->x14);
                    s2.x1A = o->xAA;
                    s2.x14 = 0x10001;
                    s2.x19 = 1;
                    s2.x18 = 0;
                    a = -1;
                    if (D_L39_0024CF1C != 0) {
                        a = *(s32 *)(D_L39_0024CF1C + 0x2548);
                    }
                    s2.x28 = m->x30;
                    func_L39_005FD658(a);
                    func_003CF790(hp, 0, o, &s2, 1.0f);
                    func_L39_005FD6D8();
                    func_L01_00441FB8(o, 1, -1);
                    return;
                }
            } else {
                *(u128_t *)&v40 = m->x0;
                func_003886E8(&v40, &v40, 3.0f);
                hp = &D_L39_0025F840.x20;
                v40.w = 5627.9248f;
                func_L01_00443628(&s2, o, m->x2C, &v40, m->x14);
                s2.x19 = 1;
                s2.x1A = o->xAA;
                s2.x18 = 0;
                a = -1;
                if (D_L39_0024CF1C != 0) {
                    a = *(s32 *)(D_L39_0024CF1C + 0x2548);
                }
                s2.x28 = m->x30;
                func_L39_005FD658(a);
                func_003CF790(hp, 0, tgt, &s2, 2.0f);
                func_L39_005FD6D8();
                func_L01_00441FB8(o, 1, -1);
                return;
            }
        }
        o->x10 = *(u128_t *)&v0;
        func_003886E8(&v40, m, -0.5f);
        qzero(&s2);
        break;
    case 1:
        func_L04_00353C08((u8 *)o + 0x10, 0x803B0612, 0x80DA5615, 0x64FFFFFF, 0x507030FF, 0x320000FF, 5.85f);
        func_003BD360(o);
        return;
    default:
        break;
    }
    func_00389158(o->xE0, o->xE0, o->xD0, 0.0f);
    func_00389158(o->xC0, o->xC0, o->xD0, 0.0f);
    func_L01_004026A0(func_L39_00541D00, o);
}
/* localdecomp:end func_L39_005416E8 */
