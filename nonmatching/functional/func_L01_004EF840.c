/* functional: medium. written from the PAL asm, no draft; 663 diff words (frame/regalloc, hoisted base regs, shared func_0038CE20 call in retail vs two in mine); every callee, constant and field offset read against the asm; func_0012FE98 is the vector-normalize entry inside func_0012FE78 (+0x20); D_L01_001EAA00 is the hit record (object +0x18, count +0x1C, position +0x20, normal +0x40) and is declared u8[] here, reconcile with the later Hit_004F52E0 typedef */
#include "vu0.h"
extern u8 D_001A4BE0_004EF840[];
extern u8 D_L01_001EAA00[];
extern s32 D_001D545C;
extern s32 D_L01_001D673C;
void func_L01_004EF840(void) {
    extern s32 func_L01_004E9308(void);
    extern void func_L01_004EF6F0(void *, void *, s32, f32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern s32 func_L01_003FE908(void);
    extern s32 func_003D5630(void);
    extern f32 func_003C3EC8(void *, void *);
    extern s32 func_003C4B50(void *);
    extern u8 *func_00382348(void *);
    extern u8 *func_003C4D58(void *);
    extern f32 func_L01_00451580(void *);
    extern f32 func_0038CF00(void *, void *);
    extern void func_0012FE98(void *, void *);
    extern f32 func_L01_00511848(void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CE68(void *, void *);
    extern s32 func_L01_00500240(s32, s32);
    extern f32 func_003C4138(f32 *, f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_004F40A8(void *, void *);
    extern void func_L01_00511038(void *, s32, f32, f32, f32);
    vu0_v4 low, high, cvec, pa, pb, pc, pd;
    u8 *h = D_001A4BE0_004EF840;
    u8 *hit;
    u8 *obj;
    u8 *r;
    s32 mode, state, i, k;
    s32 old358;
    f32 range, f, g;

    qzero(h + 0x2F0);
    old358 = *(s32 *)(h + 0x358);
    *(u16 *)(h + 0x36E) = *(u16 *)(h + 0x36E) + 1;
    *(u16 *)(h + 0x36C) = *(u16 *)(h + 0x36C) + 1;
    *(f32 *)(h + 0x2C8) = 1.0f;
    *(f32 *)(h + 0x33C) = 32.0f;
    *(s32 *)(h + 0x2C0) = 0;
    *(s32 *)(h + 0x2C4) = 0;
    *(s32 *)(h + 0x340) = 0;
    *(s32 *)(h + 0x338) = 0;
    *(s16 *)(h + 0x36A) = 0;
    *(s32 *)(h + 0x35C) = 0;
    if (old358 != 0) *(s32 *)(h + 0x358) = old358 + 1;

    range = *(f32 *)(h + 0x284) * 2.2f;
    if (*(s32 *)(h + 0x25CC) == 2) range = *(f32 *)(h + 0x284) * 2.9f;
    if (func_L01_004E9308()) range = 0.0f;
    func_L01_004EF6F0(&high, &low, 1, range, -48.0f);
    if (!func_003D3CB0(&high, &low, 2, *(void **)(h + 0x25C0), 0)) goto tail;

    *(u8 *)(h + 0x147F) = func_L01_003FE908();
    hit = D_L01_001EAA00;
    obj = *(u8 **)(hit + 0x18);
    if (obj != 0) {
        *(u8 *)(h + 0x147F) = 0;
        mode = D_001D545C;
        if (mode == 2) {
            if (*(s16 *)(obj + 0xAA) == 0x18C6) *(u8 *)(h + 0x147F) = 2;
            obj = *(u8 **)(hit + 0x18);
            if (*(s16 *)(obj + 0xAA) == 0x18AF) *(u8 *)(h + 0x147F) = 2;
        }
        if (D_001D545C == 5) {
            if (*(s16 *)(*(u8 **)(hit + 0x18) + 0xAA) == 0x1607) *(u8 *)(h + 0x147F) = 2;
            if (*(s16 *)(*(u8 **)(hit + 0x18) + 0xAA) == 0x1681) *(u8 *)(h + 0x147F) = 2;
            if (*(s16 *)(*(u8 **)(hit + 0x18) + 0xAA) == 0x15F7) *(u8 *)(h + 0x147F) = 2;
            if (*(s16 *)(*(u8 **)(hit + 0x18) + 0xAA) == 0x16BB) *(u8 *)(h + 0x147F) = 3;
        }
        if (D_001D545C == 8) {
            if (*(s16 *)(*(u8 **)(hit + 0x18) + 0xAA) == 0x1A44) *(u8 *)(h + 0x147F) = 2;
        }
        if (D_001D545C == 0xA) {
            if (*(s16 *)(*(u8 **)(hit + 0x18) + 0xAA) == 0x1645) *(u8 *)(h + 0x147F) = 3;
            if (*(s16 *)(*(u8 **)(hit + 0x18) + 0xAA) == 0x162E) *(u8 *)(h + 0x147F) = 1;
        }
        if (D_001D545C == 0x15) {
            if (*(s16 *)(*(u8 **)(hit + 0x18) + 0xAA) == 0x1BA9) *(u8 *)(h + 0x147F) = 3;
        }
    }

    k = func_003D5630();
    *(s16 *)(h + 0x1470) = k;
    if ((s16)k == 0) {
        f = func_003C3EC8(hit + 0x20, h + 0x2D0);
        *(f32 *)(h + 0x350) = f;
        if (*(f32 *)(h + 0x88) < f) {
            if (*(s32 *)(h + 0x358) <= 0) *(s32 *)(h + 0x358) = 1;
        }
        if (!func_003D3CB0(&high, &low, 0x24, *(void **)(h + 0x25C0), 0)) goto tail;
        *(u8 *)(h + 0x147F) = func_L01_003FE908();
    }

    k = *(s16 *)(h + 0x1470);
    if (k == 0xD) {
        f = *(f32 *)(hit + 0x28);
        *(f32 *)(h + 0x350) = f;
        high.z = f - 0.01f;
        if (!func_003D3CB0(&high, &low, 4, *(void **)(h + 0x25C0), 0)) goto tail;
        k = *(s16 *)(h + 0x1470);
    }
    if (k == 3) {
        f = *(f32 *)(hit + 0x28);
        *(f32 *)(h + 0x354) = f;
        high.z = f - 0.01f;
        if (!func_003D3CB0(&high, &low, 4, *(void **)(h + 0x25C0), 0)) goto tail;
        k = *(s16 *)(h + 0x1470);
    }
    if (k == 0xB) {
        *(f32 *)(h + 0x354) = *(f32 *)(hit + 0x28);
        goto tail;
    }
    if (k == 1) {
        if ((u32)(*(s32 *)(h + 0x25C4) - 0x7E) < 2) goto tail;
    }

    obj = *(u8 **)(hit + 0x18);
    if (obj != 0) {
        if (func_003C4B50(obj)) *(s16 *)(h + 0x36A) = 1;
        r = func_00382348(*(u8 **)(hit + 0x18));
        if (r != 0) {
            if (*(u16 *)(r + 0x1E) & 8) *(s16 *)(h + 0x36A) = 1;
        }
        r = func_003C4D58(*(u8 **)(hit + 0x18));
        if (r != 0) {
            if (*(s32 *)(r + 0x3C) & 8) *(s16 *)(h + 0x36A) = 1;
        }
    }
    if (*(s32 *)(hit + 0x1C) > 0) {
        vec_copy(h + 0x2F0, hit + 0x20);
        *(f32 *)(h + 0x338) = *(f32 *)(hit + 0x28);
        if (D_L01_001D673C) func_L01_00451580(hit + 0x20);
        f = func_0038CF00(h + 0x80, h + 0x2F0);
        *(f32 *)(h + 0x33C) = f;
        *(s32 *)(h + 0x35C) = *(s32 *)(hit + 0x18);
        func_0012FE98(h + 0x2C0, hit + 0x40);
        f = func_L01_00511848(hit + 0x40);
        *(f32 *)(h + 0x340) = f;
        f = func_0038D160(*(f32 *)(hit + 0x40), *(f32 *)(hit + 0x44));
        *(f32 *)(h + 0x34C) = f;
        vec_sub_ab(&cvec, h + 0x2F0, h + 0x80);
        if (0.0f < func_0038CE68(&cvec, h + 0x2C0)) {
            *(f32 *)(h + 0x33C) = -*(f32 *)(h + 0x33C);
        }
        if (*(f32 *)(h + 0x33C) < 0.02f) {
            *(s16 *)(h + 0x36C) = 0;
            if (*(f32 *)(h + 0x340) <= 0.87266463f || *(u8 *)(h + 0x25F4) != 0) {
                *(s16 *)(h + 0x36E) = 0;
                *(s32 *)(h + 0xBF0) = *(s32 *)(hit + 0x18);
            }
        }
    }

tail:
    if (*(f32 *)(h + 0x350) < *(f32 *)(h + 0x88)) *(s32 *)(h + 0x358) = 0;
    if (*(s16 *)(h + 0x36E) != 0) {
        *(s32 *)(h + 0x360) = 0;
    } else {
        s32 n = *(s32 *)(h + 0x360);
        vec_copy(h + 0x300, h + 0x2F0);
        *(s32 *)(h + 0x360) = n + 1;
        if (func_L01_00500240(0x38, 0x64) == 0) *(s32 *)(h + 0x1B70) = 0;
    }

    qzero(h + 0x2E0);
    k = *(u8 *)(h + 0x25F4);
    if (k == 1) {
        if (*(f32 *)(h + 0x31C) == 0.0f) {
            vec_copy(h + 0x2E0, h + 0x2C0);
            func_0038CE20(h + 0x2E0, h + 0x2E0, -1.0f);
        } else {
            func_003C4138((f32 *)(h + 0x31C), 0.0f, 1.0f);
            vec_copy(h + 0x2E0, h + 0x310);
            func_0038CE20(h + 0x2C0, h + 0x2E0, -1.0f);
        }
    } else if (k == 0) {
        *(f32 *)(h + 0x2E8) = -1.0f;
    } else if (k == 2) {
        f = -1.0f;
        if (0.0f < *(f32 *)(h + 0xBC)) f = 1.0f;
        vec_sub_ab(h + 0x2E0, h + 0xB0, h + 0x80);
        func_0038CF68(h + 0x2E0, h + 0x2E0, f);
    }

    h = D_001A4BE0_004EF840;
    *(s32 *)(h + 0x344) = 0;
    *(s32 *)(h + 0x348) = 0;
    *(s32 *)(h + 0x330) = 0;
    *(s32 *)(h + 0x334) = 0;
    *(s32 *)(h + 0x328) = 0;
    *(s32 *)(h + 0x32C) = 0;
    *(s32 *)(h + 0x320) = 0;
    *(s32 *)(h + 0x324) = 0;
    if (!(*(f32 *)(h + 0x33C) < 0.25f)) return;

    state = *(s32 *)(h + 0x25CC);
    if (state == 0 || state == 0xC || state == 9 || state == 7 || state == 1 ||
        (state == 4 && *(u8 *)(h + 0x46C) != 0)) {
        func_L01_004F40A8(h + 0x2C0, &cvec);
        if (-0.78539816f < cvec.y) {
            if (cvec.y < 0.78539816f) *(f32 *)(h + 0x344) = cvec.y;
        }
        if (-0.78539816f < cvec.x) {
            if (cvec.x < 0.78539816f) *(f32 *)(h + 0x348) = cvec.x;
        }
        for (i = 0; i < 2; i++) {
            f = 1.5707964f;
            if (i == 1) f = -f;
            func_L01_00511038(&pa, 1, 0.2f, f, 0.45f);
            func_L01_00511038(&pb, 1, 0.2f, f, -0.45f);
            if (func_003D3CB0(&pa, &pb, 0x22, *(void **)(h + 0x25C0), 0)) {
                if (D_L01_001D673C) {
                    g = func_L01_00451580(hit + 0x20);
                    g -= func_L01_00451580(h + 0x2F0);
                    *(f32 *)(h + 0x320 + i * 4) = g;
                } else {
                    *(f32 *)(h + 0x320 + i * 4) = *(f32 *)(hit + 0x28) - *(f32 *)(h + 0x338);
                }
                {
                    f32 a = *(f32 *)(h + 0x320 + i * 4);
                    if (0.4f < fabs_asm(a)) *(s32 *)(h + 0x320 + i * 4) = 0;
                }
                func_0012FE98(&pc, hit + 0x40);
                func_L01_004F40A8(&pc, &pd);
                if (-0.78539816f < pd.y) {
                    if (pd.y < 0.78539816f) *(f32 *)(h + 0x328 + i * 4) = pd.y;
                }
                if (-0.78539816f < pd.x) {
                    if (pd.x < 0.78539816f) *(f32 *)(h + 0x330 + i * 4) = pd.x;
                }
            } else {
                *(s32 *)(h + 0x320 + i * 4) = 0;
                *(f32 *)(h + 0x328 + i * 4) = *(f32 *)(h + 0x344);
                *(f32 *)(h + 0x330 + i * 4) = *(f32 *)(h + 0x348);
            }
        }
    }
}
