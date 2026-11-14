#include "common.h"

/* NTSC-U counterpart of func_L39_005285A8 (src/levels/shared/L39_005285A8.c).
 * D_L39_00273710 is an unsized array read [0] (the scalar .extern 16 form coalesced the lui/lbu registers), and o[0x20] = 0
 * is ONE statement after the if/else, not repeated in both arms (cross-jump kept the sched block different). */
/* localdecomp:start func_L39_00528090 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad0[0x10]; s32 f10; } Q_00528090;
typedef struct {
    u8 pad0[0x70];
    s32 f70;
    s16 s74;
    s16 s76;
    u8 pad78[4];
    s32 f7C;
    s32 f80;
    u8 pad84[4];
    f32 f88;
    u8 pad8C[4];
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
} P_00528090;
typedef struct O_00528090 {
    u8 pad0[0x10];
    u128_t v10;
    u8 b20;
    u8 pad21;
    u8 b22;
    u8 pad23;
    Q_00528090 *p24;
    u8 pad28[8];
    u8 b30;
    u8 b31;
    s16 s32;
    u16 s34;
    u8 pad36[0x12];
    f32 f48;
    u8 pad4C[0x18];
    s32 f64;
    P_00528090 *p68;
    u8 pad6C[0x2C];
    s32 f98;
    u8 pad9C[0x54];
    u128_t vF0;
} O_00528090;
typedef struct { u8 pad0[0xE]; u8 b0E; u8 pad0F[8]; u8 b17; } R_00528090;
extern u8 D_L39_00273710[];
extern s32 D_L39_00271C40[];
extern s32 D_L39_00272000[];
extern s32 D_L39_00242B40;
extern s32 D_L39_00242B3C;
__asm__(".extern D_L39_00242B40, 16");
__asm__(".extern D_L39_00242B3C, 16");
extern O_00528090 *func_003BCFB0(s32, s32);
extern void func_003BD0D8(void *, s32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_00388E38(void *, void *);
extern void func_003BF360(void *, void *);
extern f32 func_L39_005B25C8_00528090(void);
extern s16 func_L39_005B24C8(s32, s32);
extern void func_L39_00528620(void *);
extern R_00528090 *func_0037E0B8(void *);
extern void func_L39_005B2A90(void *, s32, s32);
extern void func_003BD360(void *);
extern void func_003C26C8(void *);

u8 *func_L39_00528090(u8 *a0, s32 a1) {
    u8 *o = (u8 *)func_003BCFB0(0x10AA, 0xA0);
    P_00528090 *p;
    R_00528090 *r;
    s32 old;
    f32 m[16] __attribute__((aligned(16)));

    if (o != 0) {
        p = *(P_00528090 **)(o + 0x68);
        old = o[0x22];
        func_003BD0D8(o, 0x1080);
        o[0x22] = D_L39_00273710[0];
        *(Q_00528090 **)(o + 0x24) = (Q_00528090 *)D_L39_00271C40[o[0x22]];
        *(s32 *)(o + 0x64) = D_L39_00272000[old];
        *(P_00528090 **)(o + 0x68) = p;
        o[0x30] = 0x7F;
        *(s16 *)(o + 0x32) = 0x7F;
        o[0x31] = 1;
        *(f32 *)(o + 0x48) = func_L39_005B2510(0.85f, 1.15f);
        *(u128_t *)(o + 0x10) = *(u128_t *)(a0 + 0x10);
        if (D_L39_00242B40 != 0 || D_L39_00242B3C != 0) {
            func_00388E38(m, a0 + 0xC0);
            func_003BF360(m, o + 0xF0);
        } else {
            qzero(o + 0xF0);
            *(f32 *)(o + 0xF8) = func_L39_005B25C8_00528090();
        }
        o[0x20] = 0;
        p->s76 = 0;
        p->s74 = func_L39_005B24C8(0x78, 0x12C);
        p->f90 = 0x258;
        p->f94 = 0x1E;
        p->f9C = a1;
        p->f7C = 0;
        p->f98 = 0;
        o[0x20] = 4;
        func_L39_00528620(o);
        *(s32 *)(o + 0x98) = (*(Q_00528090 **)(o + 0x24))->f10;
        p->f88 = 1.0f;
        p->f80 = -1;
        r = func_0037E0B8(a0);
        r->b17 = 9;
        if (*(u16 *)(o + 0x34) & 0x1000) {
            func_L39_005B2A90(a0, 0, 3);
        }
        if (r != 0 && r->b0E == 1) {
            r->b0E = 2;
        } else {
            func_003BD360(a0);
        }
        p->f70 = (s32)a0;
        func_003C26C8(o);
    }
    return o;
}
/* localdecomp:end func_L39_00528090 */
