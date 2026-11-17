/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_003B0780, the NTSC-U twin of func_L01_003B1F50, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_003B1F50.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 */
#include "common.h"

/* localdecomp:start func_L01_003B0780 */
typedef struct {
    u8 p0[0x1C];
    s32 (*f1C)(void);
    u8 p20[0xC];
    void (*f2C)(void *, f32);
    s32 (*f30)(s32);
    s32 (*f34)(void);
    s32 (*f38)(void);
    s32 (*f3C)(s32);
    s32 (*f40)(void);
} V_003B0780;

typedef struct {
    u8 p0[0x10];
    s32 w10;
    u8 p14[0x18];
    f32 f2C;
    s32 w30;
    s32 w34;
    u8 p38[4];
    s32 w3C;
    u8 p40[0x10];
    u8 b50;
    u8 p51[0x13];
    s32 w64;
} P_003B0780;

typedef struct {
    u8 p0[0x20];
    u8 state;
    u8 p21[0x13];
    u16 h34;
    u8 p36[0x32];
    P_003B0780 *p68;
} M_003B0780;

extern u8 *D_001E009C_sda;
__asm__(".extern D_001E009C_sda, 4");
extern f32 D_L01_001DF9D0;
__asm__(".extern D_L01_001DF9D0, 16");
extern u8 D_001A4BE0[];
static __inline__ u8 *hero_base(void) {
    return D_001A4BE0;
}

extern void func_L01_003B0EB8(void *, void *);
extern void func_L01_003B12D0(void *, void *);
extern void func_L01_003B1618(void *, void *);
extern s32 func_00388398(void *);
extern V_003B0780 *func_L01_00438468(s32, s32);
extern s32 func_L01_00326F08(void);
extern void func_L01_00452F40(void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_004B6C68(void);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_0050DAC0(void);

void func_L01_003B0780(M_003B0780 *m) {
    P_003B0780 *p;
    V_003B0780 *v;
    s32 id;
    u8 *ent;

    p = m->p68;
    if (m->state == 0) {
        func_L01_003B0EB8(m, p);
    }
    switch (m->state) {
    case 1:
        m->h34 |= 2;
        break;
    case 2:
        if (p->w64 != 0) {
            if (func_00388398(&p->w64)) {
                D_L01_001DF9D0 = 0.0f;
            } else {
                D_L01_001DF9D0 = (f32)p->w64 / 20.0f * 1.1f;
            }
        }
        v = func_L01_00438468(0x19E1, 0x6C);
        if (!v->f38()) {
            return;
        }
        if (!func_L01_00326F08() && p->w3C != -1) {
            ent = D_001E009C_sda + (p->w3C << 8);
            ent[0x30] = 0xFF;
            *(u16 *)(ent + 0x34) &= 0xFFFD;
            func_L01_00452F40(ent, 1);
            func_L01_00441FB8(m, 4, -1);
            D_L01_001DF9D0 = 2.0f;
            break;
        }
        id = -2;
        if (p->w30 != 0) {
            id = -3;
            if (p->b50 == 0) {
                id = p->w34;
            }
        }
        if (id == -3 || v->f30(id)) {
            func_L01_003B12D0(m, p);
            return;
        }
        if (v->f3C(id)) {
            D_L01_001DF9D0 = 2.0f;
            p->w64 = 0x14;
            func_L01_00441FB8(m, 3, -1);
            return;
        }
        func_L01_003B12D0(m, p);
        return;
    case 3:
        if (p->w64 != 0) {
            if (func_00388398(&p->w64)) {
                D_L01_001DF9D0 = 0.0f;
            } else {
                D_L01_001DF9D0 = (f32)p->w64 / 20.0f * 1.1f;
            }
        }
        if (func_L01_00438468(0x19E1, 0x6C)->f40()) {
            D_L01_001DF9D0 = 2.0f;
            func_L01_003B12D0(m, p);
            return;
        }
        break;
    case 4:
        if (func_L01_004B6C68()) {
            return;
        }
        D_L01_001DF9D0 = 2.0f;
        if (func_L01_00326F08()) {
            id = -2;
            if (p->w30 != 0) {
                id = -3;
                if (p->b50 == 0) {
                    id = p->w34;
                }
            }
            v = func_L01_00438468(0x19E1, 0x6C);
            if (!v->f30(id)) {
                if (v->f34()) {
                    p->w64 = 0x14;
                    func_L01_00441FB8(m, 2, -1);
                    return;
                }
            }
        }
        func_L01_003B12D0(m, p);
        return;
    case 5:
        if (func_L01_00452EC8(m)) {
            p->w64 = 0x14;
        }
        v = func_L01_00438468(0x19E1, 0x6C);
        if (*(s32 *)(hero_base() + 0x25C4) != 0xB0 && v->f1C() && !func_L01_0050DAC0()) {
            v->f2C(0, -100.0f);
        }
        if (func_00388398(&p->w64)) {
            D_L01_001DF9D0 = 0.0f;
            if (*(s32 *)(hero_base() + 0x25C4) != 0xB0 && v->f1C()) {
                func_L01_00441FB8(m, 6, -1);
            } else {
                func_L01_00441FB8(m, 9, -1);
            }
            return;
        }
        D_L01_001DF9D0 = (f32)p->w64 / 20.0f * 1.1f;
        break;
    case 6:
        if (func_L01_00452EC8(m)) {
            p->w64 = 0x3C;
        }
        if (!func_L01_0050DAC0()) {
            func_L01_00438468(0x19E1, 0x6C)->f2C(0, -100.0f);
        }
        if (func_00388398(&p->w64)) {
            func_L01_00438468(0x19E1, 0x6C)->f2C(0, p->f2C);
            func_L01_00441FB8(m, 9, -1);
            return;
        }
        break;
    case 7:
        if (func_L01_00452EC8(m)) {
            p->w64 = 0x14;
        }
        if (p->w10 == -1) {
            v = func_L01_00438468(0x19E1, 0x6C);
            if (v->f1C() && !func_L01_0050DAC0()) {
                v->f2C(0, -100.0f);
            }
        }
        if (func_00388398(&p->w64)) {
            D_L01_001DF9D0 = 0.0f;
            v = func_L01_00438468(0x19E1, 0x6C);
            if (p->w10 == -1 && v->f1C()) {
                func_L01_00441FB8(m, 8, -1);
            } else {
                func_L01_00441FB8(m, 9, -1);
            }
            func_L01_003B1618(m, p);
            return;
        }
        D_L01_001DF9D0 = (f32)p->w64 / 20.0f * 1.1f;
        break;
    case 8:
        if (func_L01_00452EC8(m)) {
            p->w64 = 0x3C;
        }
        if (!func_L01_0050DAC0()) {
            func_L01_00438468(0x19E1, 0x6C)->f2C(0, -100.0f);
        }
        if (!func_00388398(&p->w64)) {
            return;
        }
        if (p->w30 == 0 || p->f2C != 0.0f) {
            func_L01_00438468(0x19E1, 0x6C)->f2C(0, p->f2C);
        }
        func_L01_00441FB8(m, 9, -1);
        return;
    case 11:
        if (func_L01_00452EC8(m)) {
            p->w64 = 0x14;
        }
        v = func_L01_00438468(0x19E1, 0x6C);
        if (*(s32 *)(hero_base() + 0x25C4) != 0xB0 && v->f1C() && !func_L01_0050DAC0()) {
            v->f2C(0, -100.0f);
        }
        if (func_00388398(&p->w64)) {
            D_L01_001DF9D0 = 0.0f;
            if (*(s32 *)(hero_base() + 0x25C4) != 0xB0 && v->f1C()) {
                func_L01_00441FB8(m, 0xC, -1);
            } else {
                func_L01_00441FB8(m, 0xA, -1);
            }
            return;
        }
        D_L01_001DF9D0 = (f32)p->w64 / 20.0f * 1.1f;
        break;
    case 12:
        if (func_L01_00452EC8(m)) {
            p->w64 = 0x3C;
        }
        if (!func_L01_0050DAC0()) {
            func_L01_00438468(0x19E1, 0x6C)->f2C(0, -100.0f);
        }
        if (func_00388398(&p->w64)) {
            func_L01_00438468(0x19E1, 0x6C)->f2C(D_001A4BE0, p->f2C);
            func_L01_00441FB8(m, 0xA, -1);
            return;
        }
        break;
    }
}
/* localdecomp:end func_L01_003B0780 */
