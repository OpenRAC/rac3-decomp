#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L04_003E20D0 */
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CAD0(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L04_003E2550(s32, u8 *, s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L04_003E26C8(void *, u8 *);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L04_003E2818(void *, u8 *);
extern void func_L04_003E25F8(void *, u8 *);
extern void func_L01_004450F0(void *, s32, s32);
__asm__(".extern D_L04_001DF030, 4");
__asm__(".extern D_L04_001DF034, 4");
__asm__(".extern D_L04_001DF038, 4");
__asm__(".extern D_L04_001DF03C, 4");
__asm__(".extern D_L04_001DF044, 4");
__asm__(".extern D_L04_001DF048, 4");
__asm__(".extern D_L04_001DF05C, 4");
__asm__(".extern D_L04_001DF060, 4");
extern s32 D_L04_001DF030;
extern s32 D_L04_001DF034;
extern s32 D_L04_001DF038;
extern s32 D_L04_001DF03C;
extern s32 D_L04_001DF044;
extern s32 D_L04_001DF048;
extern f32 D_L04_001DF05C;
extern f32 D_L04_001DF060;

typedef struct {
    u8 pad_0[0x60];
    s32 timer;              /* 0x60 */
    f32 unk_64;                /* 0x64 */
    f32 unk_68;              /* 0x68 */
} V_003E20D0;

typedef struct {
    u8 pad_0[0x20];
    u8 state;               /* 0x20 */
    u8 pad_21[0x43 - 0x21];
    u8 cur_seq;             /* 0x43 */
    u8 pad_44[0x48 - 0x44];
    f32 anim_speed;         /* 0x48 */
    u8 pad_4C[0x60 - 0x4C];
    u8 anim_flags;          /* 0x60 */
    u8 pad_61[0x68 - 0x61];
    V_003E20D0 *pvar;       /* 0x68 */
    u8 pad_6C[0x78 - 0x6C];
    s32 unk_78;              /* 0x78 */
} M_003E20D0;

void func_L04_003E20D0(M_003E20D0 *a0) {
    V_003E20D0 *p = a0->pvar;
    f32 t;

    switch (a0->state) {
    case 1:
        break;
    case 2:
        if (func_L01_004561B8(a0))
            p->timer = D_L04_001DF038;
        if (func_0038CAD0(&p->timer)) {
            func_L01_004450F0(a0, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(a0)) {
            p->timer = D_L04_001DF03C;
            func_003C3A10(a0, 1, 0, 0);
            a0->anim_speed = 0.25f;
        }
        if (a0->cur_seq == 1 && (a0->anim_flags & 2))
            func_003C3A10(a0, 2, 0, 0);
        if (func_0038CAD0(&p->timer) && a0->cur_seq != 1) {
            a0->unk_78 = D_L04_001DF034;
            p->unk_68 = D_L04_001DF060 * 0.017453292f;
            func_L01_004450F0(a0, 4, -1);
        } else {
            t = 1.0f - (f32)p->timer / (f32)D_L04_001DF03C;
            a0->unk_78 = func_0038DBD8(D_L04_001DF030, D_L04_001DF034, t);
            p->unk_68 = t * (D_L04_001DF060 * 0.017453292f);
        }
        break;
    case 4:
        if (func_L01_004561B8(a0)) {
            func_003C3A10(a0, 2, 0, 5);
            p->timer = D_L04_001DF044;
        }
        if (func_L04_003E2550((s32)a0, (u8 *)p, 0)) {
            func_L01_004450F0(a0, 6, -1);
        } else if (func_0038CAD0(&p->timer)) {
            p->unk_64 = func_00382538();
            p->unk_68 = func_003824E0(D_L04_001DF05C * 0.017453292f, D_L04_001DF060 * 0.017453292f);
            p->timer = func_00382498(D_L04_001DF044, D_L04_001DF048);
        }
        break;
    case 5:
        break;
    case 6:
        if (func_L01_004561B8(a0))
            func_003C3A10(a0, 3, 5, 5);
        if (!func_L04_003E2550((s32)a0, (u8 *)p, 1)) {
            func_L01_004450F0(a0, 4, -1);
        } else {
            func_L04_003E26C8(a0, (u8 *)p);
            if (func_L01_0044E1B8(a0, 0.5f))
                func_L04_003E2818(a0, (u8 *)p);
        }
        break;
    }
    func_L04_003E25F8(a0, (u8 *)p);
}
/* localdecomp:end func_L04_003E20D0 */

/* localdecomp:start func_L04_003E2390 */
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CB78(void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
__asm__(".extern D_L04_001DF040, 4");
__asm__(".extern D_L04_001DF030, 4");
__asm__(".extern D_L04_001DF064, 4");
extern f32 D_L04_001DF040;
extern s32 D_L04_001DF030;
extern f32 D_L04_001DF064;
u8 *func_L04_003E2390(s32 a0, u128_t *pos, u128_t *rot, s32 a3, s32 t0, f32 f12, f32 f13, f32 f14) {
    u8 *m;
    u8 *p;
    u8 *q;
    m = func_003C24B0(0x1B29, 0x200);
    if (m != 0) {
        *(s32 *)(m + 0xB8) = a0;
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 2.0f;
        *(u16 *)(m + 0x34) |= 0x20;
        p = *(u8 **)(m + 0x68);
        *(u8 **)(p + 0xC) = p + 0x30;
        func_0038CB78(p + 0x30, 0, 0x20);
        *(u128_t *)(m + 0x10) = *pos;
        q = m + 0xF0;
        *(u128_t *)q = *rot;
        *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), D_L04_001DF040 * 0.017453292f);
        func_0038D308(m + 0xC0, q);
        *(s32 *)(m + 0x78) = D_L04_001DF030;
        *(s32 *)(p + 0x50) = a3;
        *(f32 *)(p + 0x54) = f12;
        *(s32 *)(p + 0x58) = t0;
        *(f32 *)(p + 0x5C) = f13;
        *(f32 *)(p + 0x64) = *(f32 *)(m + 0xF8);
        *(s32 *)(p + 0x68) = 0;
        if (f14 != *(f32 *)(p + 0x68))
            *(f32 *)(p + 0x6C) = f14;
        else
            *(f32 *)(p + 0x6C) = D_L04_001DF064;
        func_0038CB78(p + 0x70, 0, 0x80);
        func_0038CB78(p + 0xF0, 0, 0x80);
        func_0038CB78(p + 0x170, 0, 0x80);
        func_L01_004450F0(m, 1, -1);
    }
    return m;
}
/* localdecomp:end func_L04_003E2390 */
