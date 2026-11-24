#include "common.h"
#include "vu0.h"

typedef void (*fn_3A2780)(u8 *);

INCLUDE_ASM("asm/levels", func_L01_0039E1B0);

LINKER_REMNANT("asm/levels", func_L01_0039F0F0);

/* localdecomp:start func_L01_0039F0F8 */
extern s32 D_L01_001DAFEC_0039F0F8;
extern u8 D_001A4BE0[];
extern u8 D_L01_001EAA00_0039F0F8[];
extern s32 D_L01_001D673C_0039F0F8_b;
extern s32 D_L01_001D6740_0039F0F8_b;
extern s32 D_L01_001D673C_0039F0F8;
extern s32 D_L01_001D6740_0039F0F8;
__asm__(".extern D_L01_001D673C_0039F0F8, 4");
__asm__(".extern D_L01_001DAFEC_0039F0F8, 16");
__asm__(".extern D_L01_001D673C_0039F0F8_b, 16");
__asm__(".extern D_L01_001D6740_0039F0F8_b, 16");
__asm__(".extern D_L01_001D6740_0039F0F8, 4");

extern void func_0038D570(void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_L01_0044C638(u8 *, s32, void *, void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void *func_L01_00447490(u8 *, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_0039FEB0(u8 *);
extern void func_L01_004471A8(u8 *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004455E8(u8 *, f32, f32, void *, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L01_003A0528(u8 *);
extern s32 func_L01_00445728(u8 *, void *, void *, f32, f32, f32, f32, s32);
extern u8 *func_L01_00450010(void *, s32, f32, f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C3DA0(void *, void *, f32, s32, s32);
extern s32 func_003D5630(void);
extern void func_L01_003D42D0(u8 *);
extern void func_L01_00451290(u8 *, void *, s32);
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);

void func_L01_0039F0F8(u8 *self) {
    struct { vu0_v4 a, b, c, d, e, g; } L;
    u8 *h;
    u8 *t;
    f32 d;
    u8 *rec = *(u8 **)(self + 0x68);
    f32 ang;
    f32 f;
    s32 r;
    void *p;

    if (self[0x20] != 0 && D_L01_001DAFEC_0039F0F8 != 0) {
        func_0038D570(&L.c, self + 0xC0);
        func_003C48A8(&L.c, &L.a);
        func_L01_0044C638(self, D_L01_001DAFEC_0039F0F8, self + 0x10, &L.a, self + 0x10, &L.b);
        func_0038D308(self + 0xC0, &L.b);
        *(vu0_q *)(self + 0xF0) = *(vu0_q *)&L.b;
    }
    p = func_L01_00447490(self, 0x8010000, 0);
    if ((func_0038CAD0(rec + 0xA8) && D_L01_001D673C_0039F0F8) || p != 0) {
        func_L01_0039FEB0(self);
    }
    func_L01_004471A8(self, 0.400000006f);
    h = D_001A4BE0;
    *(s32 *)(rec + 0x98) += 1;
    ang = func_0038D160(*(f32 *)(self + 0x10) - *(f32 *)(h + 0x80),
                        *(f32 *)(self + 0x14) - *(f32 *)(h + 0x84));
    switch (self[0x20]) {
    case 1:
        if (self[0x60] & 2) {
            ang = func_003824E0(0.0f, 100.0f);
            if (0.0f <= ang && ang < 10.0f) func_003C3A10(self, 0, 0, 8);
            if (10.0f <= ang && ang < 20.0f) func_003C3A10(self, 1, 0, 8);
            if (20.0f <= ang && ang < 40.0f) func_003C3A10(self, 2, 0, 8);
            if (40.0f <= ang && ang < 100.0f && D_L01_001D6740_0039F0F8 == 0 && D_L01_001D673C_0039F0F8_b == 0) {
                *(vu0_q *)&L.c = *(vu0_q *)(self + 0x10);
                t = func_L01_00450010(&L.c, 0, 1.57079637f, 999.0f, -1.0f, -1.0f);
                *(u8 **)(rec + 0x9C) = t;
                if (t != 0) {
                    func_L01_004450F0(self, 8, -1);
                    func_003C3A10(self, 4, 0, 1);
                    *(f32 *)(self + 0x48) = 1.0f;
                }
            }
        }
        if (func_0038CF38(self + 0x10, D_001A4BE0 + 0x80) < 2.0f && D_L01_001D6740_0039F0F8 == 0 && D_L01_001D673C_0039F0F8 == 0) {
            func_L01_004450F0(self, 2, -1);
            func_003C3A10(self, 4, 0, 1);
            *(f32 *)(self + 0x48) = 1.0f;
        }
        if (func_0038CAD0(rec + 0x90)) {
            if (D_L01_001D6740_0039F0F8 != 0) return;
            if (D_L01_001D673C_0039F0F8_b == 0) {
                if (func_00382468(2)) {
                    func_L01_004450F0(self, 5, -1);
                    *(s32 *)(rec + 0x90) = (func_00382498(400, 600) * 5 + 2) / 6;
                    func_003C3A10(self, 3, 0, 8);
                } else {
                    func_L01_004450F0(self, 6, -1);
                    *(s32 *)(rec + 0x90) = (func_00382498(180, 360) * 5 + 2) / 6;
                    func_003C3A10(self, 4, 0, 8);
                }
            }
        }
        break;
    case 8:
        t = *(u8 **)(rec + 0x9C);
        d = func_0038D160(*(f32 *)(t + 0x10) - *(f32 *)(self + 0x10), *(f32 *)(t + 0x14) - *(f32 *)(self + 0x14));
        func_L01_004455E8(self, d, 0.00031415929f, rec + 0x78, 0.000628318579f, 0.0209439527f);
        func_0038CF68(&L.b, self + 0xC0, 0.0500000045f);
        vec_add_ba(&L.a, self + 0x10, &L.b);
        if (func_0038CAD0(rec + 0xA0)) {
            func_003A52A0(0, 0, self);
            func_L01_003A0528(self);
        }
        if (!func_L01_00445728(self, self + 0x10, &L.a, 0.5f, 0.6f, 0.25f, 0.52359879f, 0))
            func_L01_0039FEB0(self);
        break;
    case 6:
        if (self[0x60] & 2) func_003C3A10(self, 4, 0, 8);
        if (func_0038CAD0(rec + 0x90)) {
            func_L01_004450F0(self, 1, -1);
            *(s32 *)(rec + 0x90) = (func_00382498(120, 600) * 5 + 2) / 6;
            func_003C3A10(self, func_00382468(2), 0, 8);
        }
        break;
    case 5:
        if (self[0x60] & 2) func_003C3A10(self, 3, 0, 2);
        if (func_0038CF38(self + 0x10, D_001A4BE0 + 0x80) < 2.0f) {
            func_L01_004450F0(self, 2, -1);
            func_003C3A10(self, 4, 0, 1);
        }
        if (func_0038CAD0(rec + 0x90)) {
            func_L01_004450F0(self, 1, -1);
            *(s32 *)(rec + 0x90) = (func_00382498(400, 600) * 5 + 2) / 6;
        }
        f = func_003824E0(-30.0f, 30.0f);
        func_L01_004455E8(self, func_0038DAB8(*(f32 *)(self + 0xF8), f * 0.0174532924f), 0.000209439531f, rec + 0x78, 0.000628318579f, 0.0157079641f);
        func_0038CF68(&L.b, self + 0xC0, 0.00500000035f);
        vec_add_ba(&L.a, self + 0x10, &L.b);
        if (!func_L01_00445728(self, self + 0x10, &L.a, 0.1f, 0.5f, 0.25f, 0.52359879f, 0)) {
            f = func_003824E0(20.0f, 135.0f);
            func_L01_004455E8(self, func_0038DAB8(*(f32 *)(self + 0xF8), f * 0.0174532924f), 6.98131698e-05f, rec + 0x78, 0.000628318579f, 0.0157079641f);
        }
        break;
    case 2:
        *(vu0_q *)&L.c = *(vu0_q *)(self + 0x10);
        t = func_L01_00450010(&L.c, 0, 1.57079637f, 999.0f, -1.0f, -1.0f);
        *(u8 **)(rec + 0x9C) = t;
        if (t != 0) {
            d = func_0038D160(*(f32 *)(t + 0x10) - *(f32 *)(self + 0x10), *(f32 *)(t + 0x14) - *(f32 *)(self + 0x14));
            func_L01_004455E8(self, d, 0.00031415929f, rec + 0x78, 0.000628318579f, 0.0209439527f);
            func_0038CF68(&L.b, self + 0xC0, 0.0500000045f);
            vec_add_ba(&L.a, self + 0x10, &L.b);
        }
        if (!func_L01_00445728(self, self + 0x10, &L.a, 0.5f, 0.6f, 0.25f, 0.52359879f, 0)) {
            func_L01_0039FEB0(self);
        } else if (func_0038DBA0(ang, *(f32 *)(self + 0xF8)) > 0.52359879f) {
            func_L01_004455E8(self, ang, 0.000558505359f, rec + 0x78, 0.000628318579f, 0.0157079641f);
        }
        break;
    case 10:
        func_003C3DA0(self + 0x10, self + 0x10, 0.5f, 0, 0);
        r = func_003D5630();
        if (r > 0 && r != 10 && r != 7 && D_L01_001D6740_0039F0F8 == 0) {
            func_L01_003D42D0(self);
            return;
        }
    case 0:
        func_L01_004450F0(self, 1, -1);
        break;
    case 4:
        func_L01_00451290(self, &L.c, 0);
        func_0038CF68(&L.c, &L.c, 4.0f);
        vec_add_ba(&L.d, self + 0x10, &L.c);
        func_0038CF68(&L.c, &L.c, -1.0f);
        vec_add_ba(&L.e, self + 0x10, &L.c);
        if (func_003D3CB0(&L.e, &L.d, 0, self, 0)) {
            u8 *h2 = D_001A4BE0;
            u8 *q = D_L01_001EAA00_0039F0F8;
            if (*(s32 *)(q + 0x18) != *(s32 *)(h2 + 0x25C0)) {
                *(vu0_q *)(self + 0x10) = *(vu0_q *)(q + 0x20);
            }
        }
        r = func_003D5630();
        if (r > 0 && r != 10 && r != 7 && D_L01_001D6740_0039F0F8 == 0) {
            func_L01_0039FEB0(self);
            return;
        }
        func_L01_004450F0(self, 1, -1);
        break;
    }
    if (D_L01_001D6740_0039F0F8_b == 0 && D_L01_001D673C_0039F0F8_b == 0) {
        *(vu0_q *)&L.c = *(vu0_q *)(self + 0x10);
        *(f32 *)((u8 *)&L.c + 8) += 0.5f;
        *(f32 *)(self + 0x18) = func_003C3D30(&L.c, 0, 0, 0.5f);
        r = func_003D5630();
        if (r > 0 && r != 10 && r != 7 && D_L01_001D6740_0039F0F8 == 0) func_L01_0039FEB0(self);
    }
}
/* localdecomp:end func_L01_0039F0F8 */

/* localdecomp:start func_L01_0039FBD0 */
typedef int u128_t_0039FBD0 __attribute__((mode(TI)));

typedef struct E_0039FBD0 {
    u8 b0;
    u8 b1;
    u8 pad2[0xEE];
} E_0039FBD0;

extern s32 D_L01_001D6740_0039FBD0;
__asm__(".extern D_L01_001D6740_0039FBD0, 16");
extern s32 D_L01_001D673C_0039FBD0;
__asm__(".extern D_L01_001D673C_0039FBD0, 16");
extern s32 D_L01_001D67B0_0039FBD0;
__asm__(".extern D_L01_001D67B0_0039FBD0, 16");
extern s32 D_L01_001D67B0_sda_0039FBD0 __attribute__((section(".sdata")));
extern u8 D_001425C0_0039FBD0[];
extern E_0039FBD0 D_L01_002C5600_0039FBD0[];
extern f32 D_001A4BE0_0039FBD0[];
extern s32 D_001D545C_0039FBD0;
__asm__(".extern D_001D545C_0039FBD0, 16");

extern u8 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_0038D570(void *, void *);
extern void func_003C48A8(void *, void *);
extern f32 func_0038D160(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_003D4788(void *);
extern u8 *func_00382348(void *);
extern void func_L01_00459C50(s32);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_003C2880(void *);
extern void func_003C7C38(void *);

u8 *func_L01_0039FBD0(u8 *o) {
    u8 *obj;
    u8 *p;
    u8 *t;
    f32 tmp[16] __attribute__((aligned(16)));
    f32 f;

    obj = func_003C24B0(0x189B, 0xC0);
    if (obj != 0) {
        obj[0x30] = 0x7F;
        *(s16 *)(obj + 0x32) = 0x7F;
        obj[0x31] = 1;
        p = *(u8 **)(obj + 0x68);
        *(f32 *)(obj + 0x48) = func_003824E0(0.85f, 1.15f);
        *(u16 *)(obj + 0x34) |= 0x20;
        func_L01_0043B9E8(obj, 0x40, 0x10, 0x10);
        *(u128_t_0039FBD0 *)(obj + 0x10) = *(u128_t_0039FBD0 *)(o + 0x10);
        if (D_L01_001D6740_0039FBD0 != 0 || D_L01_001D673C_0039FBD0 != 0) {
            func_0038D570(&tmp, o + 0xC0);
            func_003C48A8(&tmp, obj + 0xF0);
        } else {
            qzero(obj + 0xF0);
            *(f32 *)(obj + 0xF8) = func_0038D160(*(f32 *)(obj + 0x10) - D_001A4BE0_0039FBD0[0x80 / 4], *(f32 *)(obj + 0x14) - D_001A4BE0_0039FBD0[0x84 / 4]);
        }
        obj[0x20] = 1;
        *(s16 *)(p + 0x76) = 0;
        *(s16 *)(p + 0x74) = func_00382498(100, 250);
        *(s32 *)(p + 0x90) = 0x1F4;
        *(s32 *)(p + 0x94) = 12;
        *(s32 *)(p + 0x7C) = 0;
        *(s32 *)(p + 0x98) = 0;
        if (((E_0039FBD0 *)(D_001425C0_0039FBD0[0x8F] * 0xF0 + (u32)D_L01_002C5600_0039FBD0))->b1 >= 4) {
            *(s32 *)(p + 0xA4) = 1;
        } else {
            *(s32 *)(p + 0xA4) = 0;
        }
        if (D_L01_001D673C_0039FBD0 != 0) {
            obj[0x20] = 0xA;
        } else {
            obj[0x20] = 4;
        }
        *(u8 **)p = p + 0x30;
        p[0x39] = 1;
        *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
        func_L01_003D4788(obj);
        *(s32 *)(p + 0xA8) = (func_00382498(100, 350) * 5 + 2) / 6;
        f = 1.0f;
        if (((E_0039FBD0 *)(D_001425C0_0039FBD0[0x8F] * 0xF0 + (u32)D_L01_002C5600_0039FBD0))->b1 != 0) {
            f = 4.0f;
        }
        *(f32 *)(p + 0x88) = f;
        *(s32 *)(p + 0x80) = -1;
        t = func_00382348(o);
        if (t != 0) {
            t[0x17] = 0x8F;
        }
        if (D_001D545C_0039FBD0 == 5 && *(s16 *)(o + 0xAA) == 0x19DB) {
            D_L01_001D67B0_sda_0039FBD0 = D_L01_001D67B0_0039FBD0 + 1;
            if (D_L01_001D67B0_sda_0039FBD0 >= 0xF) {
                func_L01_00459C50(7);
            }
        }
        if ((*(u16 *)(obj + 0x34) & 0x1000) != 0) {
            func_L01_004443E8(o, 0, 3);
        }
        if (t != 0 && t[0xE] == 1) {
            t[0xE] = 2;
        } else {
            func_003C2880(o);
        }
        func_003C7C38(obj);
    }
    return obj;
}
/* localdecomp:end func_L01_0039FBD0 */

INCLUDE_ASM("asm/levels", func_L01_0039FEB0);
