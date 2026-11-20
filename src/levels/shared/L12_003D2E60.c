#include "common.h"

typedef struct {
    void (*f0)(u8 *);
    void (*f4)(u8 *);
} Vt003D1AA8;
typedef struct {
    s32 a;
    f32 b;
    s32 c;
    f32 d;
} Src_3D1EB8;

typedef struct {
    u8 pad0[0x19E0];
    u8 *f19E0;
    u8 pad19E4[0x25C0 - 0x19E4];
    s32 f25C0;
} G_003D1BE8;
typedef struct {
    u8 pad0[0x140];
    s32 f140;
    u8 pad144[0x160 - 0x144];
    u8 f160[0x1C8 - 0x160];
    f32 f1C8;
    u8 pad1CC[0x1E0 - 0x1CC];
    u8 f1E0[0x240 - 0x1E0];
    f32 f240;
    u8 pad244[0x274 - 0x244];
    f32 f274;
    f32 f278;
} P_003D1BE8;

/* localdecomp:start func_L12_003D2E60 */
typedef struct {
    u8 pad0[0x40];
    f32 f40;
    u8 pad44[0x130 - 0x44];
    u8 b130[0x10];
    s32 w140;
    u8 pad144[0x270 - 0x144];
    s32 w270;
    f32 f274;
    f32 f278;
    f32 f27C;
} P_003D2E60;

typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1C[4];
    u8 b20;
    u8 pad21[0x60 - 0x21];
    u8 b60;
    u8 pad61[0x68 - 0x61];
    P_003D2E60 *p68;
} O_003D2E60;

extern G_003D1BE8 D_001A4BE0_003D2E60;
extern s32 D_L12_001DEEE0;
extern s32 D_L12_001DEEE8;
extern s32 D_L12_001DEEEC;
extern f32 D_L12_001DEEF8;
extern f32 D_L12_001DEF04;
extern f32 D_L12_001DEF08;
extern f32 D_L12_001DEF10;
extern s32 D_L12_001DEF1C;
extern s32 D_L12_001DEF20;
extern s32 D_L12_001DEF24;
extern s32 D_L12_001DEF28;
__asm__(".extern D_L12_001DEEE0, 4");
__asm__(".extern D_L12_001DEEE8, 4");
__asm__(".extern D_L12_001DEEEC, 4");
__asm__(".extern D_L12_001DEEF8, 4");
__asm__(".extern D_L12_001DEF04, 4");
__asm__(".extern D_L12_001DEF08, 4");
__asm__(".extern D_L12_001DEF10, 4");
__asm__(".extern D_L12_001DEF1C, 4");
__asm__(".extern D_L12_001DEF20, 4");
__asm__(".extern D_L12_001DEF24, 4");
__asm__(".extern D_L12_001DEF28, 4");
extern s32 func_L12_003D3338(u8 *, u8 *);
extern s32 func_L12_003D3488(u8 *, u8 *);
extern void func_L12_003D36B0(u8 *, s32);
extern s32 func_L12_003D3748(s32, u8 *, s32);
extern void func_L12_003D37F0(u8 *, P_003D1BE8 *);
extern void func_L12_003D3978(u8 *, u8 *);
extern void func_L12_003D3A80(u8 *, u8 *);
extern s32 func_L01_004561B8(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_L01_00443A18(f32, f32);

void func_L12_003D2E60(O_003D2E60 *a) {
    P_003D2E60 *s;
    f32 v[4];

    s = a->p68;
    if (a->b20 == 0 && func_L12_003D3338((u8 *)a, (u8 *)s) == 0) {
        return;
    }
    if (func_L12_003D3488((u8 *)a, (u8 *)s) == 0) {
        func_L12_003D36B0((u8 *)a, 1);
        return;
    }
    switch (a->b20) {
    case 1:
        if (func_L01_004561B8(a) != 0) {
            func_003C2F58(a, 2, v);
            s->f40 = v[2] - a->f18;
            s->w270 = 0;
        }
        if (func_L12_003D3748((s32)a, (u8 *)s, 0) != 0) {
            if (s->w270 != 0) {
                if (func_0038CAD0(&s->w270) != 0) {
                    func_003C3A10(a, 1, 0, 8);
                    func_L01_004450F0(a, 2, -1);
                }
            } else {
                s->w270 = D_L12_001DEEE0;
            }
        }
        break;
    case 2:
        func_003C2F58(a, 2, v);
        s->f40 = v[2] - a->f18;
        if ((a->b60 & 2) != 0) {
            func_003C3A10(a, 2, 0, 8);
            if (func_L12_003D3748((s32)a, (u8 *)s, 1) != 0) {
                s->w270 = (s->w140 == D_001A4BE0_003D2E60.f25C0 && D_001A4BE0_003D2E60.f19E0 != 0 && *(s16 *)(D_001A4BE0_003D2E60.f19E0 + 0xAA) == 0x1A17)
                              ? D_L12_001DEF24
                              : D_L12_001DEF1C;
                func_L01_004450F0(a, 5, -1);
            } else {
                func_L01_004450F0(a, 4, -1);
            }
        }
        break;
    case 3:
        func_003C2F58(a, 2, v);
        s->f40 = v[2] - a->f18;
        if ((a->b60 & 2) != 0) {
            func_003C3A10(a, 0, 0, 8);
            func_L01_004450F0(a, 1, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(a) != 0) {
            s->f274 = func_00382538();
            s->f278 = func_003824E0(D_L12_001DEF04 * 0.017453292f, D_L12_001DEF08 * 0.017453292f);
            s->w270 = func_00382498(D_L12_001DEEE8, D_L12_001DEEEC);
        }
        if (func_0038CAD0(&s->w270) != 0) {
            if (func_L12_003D3748((s32)a, (u8 *)s, 1) != 0) {
                s->w270 = D_L12_001DEF1C;
                func_L01_004450F0(a, 5, -1);
            } else if (func_L12_003D3748((s32)a, (u8 *)s, 0) != 0) {
                s->f274 = func_00382538();
                s->f278 = func_003824E0(D_L12_001DEF04 * 0.017453292f, D_L12_001DEF08 * 0.017453292f);
                s->w270 = func_00382498(D_L12_001DEEE8, D_L12_001DEEEC);
            } else {
                func_003C3A10(a, 4, 0, 8);
                func_L01_004450F0(a, 3, -1);
            }
        } else if (D_001A4BE0_003D2E60.f19E0 != 0 && *(s16 *)(D_001A4BE0_003D2E60.f19E0 + 0xAA) == 0x1A17 && func_L12_003D3748((s32)a, (u8 *)s, 1) != 0) {
            s->w270 = (s->w140 == D_001A4BE0_003D2E60.f25C0) ? D_L12_001DEF24 : D_L12_001DEF1C;
            func_L01_004450F0(a, 5, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(a) != 0) {
            if (func_L01_0040E570((u8 *)a + 0x10, s->b130) < D_L12_001DEF10 * D_L12_001DEF10) {
                s->f27C = func_L01_00443A18(D_L12_001DEEF8 * 0.75f * 0.017453292f, D_L12_001DEEF8 * 0.017453292f);
            } else {
                s->f27C = 0.0f;
            }
        }
        if (func_0038CAD0(&s->w270) != 0) {
            if (func_L12_003D3748((s32)a, (u8 *)s, 1) != 0) {
                func_L01_004450F0(a, 6, -1);
            } else {
                func_L01_004450F0(a, 4, -1);
            }
        } else if (func_L12_003D3748((s32)a, (u8 *)s, 1) != 0) {
            func_L12_003D3978((u8 *)a, (u8 *)s);
        }
        break;
    case 6:
        if (func_L01_004561B8(a) != 0) {
            func_003C3A10(a, 3, 0, 1);
            func_L12_003D3A80((u8 *)a, (u8 *)s);
        }
        if ((a->b60 & 2) != 0) {
            if (s->w140 == D_001A4BE0_003D2E60.f25C0 && D_001A4BE0_003D2E60.f19E0 != 0 && *(s16 *)(D_001A4BE0_003D2E60.f19E0 + 0xAA) == 0x1A17) {
                s->w270 = D_L12_001DEF28;
            } else {
                s->w270 = D_L12_001DEF20;
            }
            func_003C3A10(a, 2, 0, 1);
            func_L01_004450F0(a, 5, -1);
        }
        break;
    }
    func_L12_003D37F0((u8 *)a, (P_003D1BE8 *)s);
}
/* localdecomp:end func_L12_003D2E60 */

/* localdecomp:start func_L12_003D3338 */
extern u8 D_L12_001DEF14;
__asm__(".extern D_L12_001DEF14, 4");
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern Vt003D1AA8 *func_L01_0043B548(s32 a0, s32 a1);
extern void func_003C3938(void *a0, s32 a1, s32 a2);

s32 func_L12_003D3338(u8 *a0, u8 *a1) {
    Vt003D1AA8 *vt;
    s16 h;
    u8 *p = *(u8 **)(a0 + 0x24);

    *(f32 *)(a0 + 0x2C) = *(f32 *)(p + 0x24) + *(f32 *)(p + 0x24);
    *(f32 *)(a1 + 0xC8) = 2.0f;
    a1[0xB8] = 0xFF;
    *(f32 *)(a1 + 0xCC) = 2.0f;
    a1[0x81] = 0xFF;
    h = *(s16 *)(a1 + 0x34);
    a1[0xE7] = 1;
    if (h == 0) {
        *(s16 *)(a1 + 0x34) = 30;
        *(f32 *)(a1 + 0x30) = 30.0f;
    }
    *(f32 *)(a1 + 0x40) = 0.6f;
    a1[0x38] = 2;
    a1[0x64] = 1;
    a1[0x3E] = 3;
    a1[0x39] = 0;
    a1[0x3F] = 0;
    if (a1[0x44] == 0) {
        a1[0x44] = D_L12_001DEF14;
    }
    *(f32 *)(a1 + 0x274) = *(f32 *)(a0 + 0xF8);
    *(s32 *)(a1 + 0x278) = 0;
    func_0038CB78(a1 + 0x160, 0, 0x80);
    func_0038CB78(a1 + 0x1E0, 0, 0x80);
    if (*(s32 *)(a1 + 0x150) > 0) {
        vt = func_L01_0043B548(6625, 108);
        *(s32 *)(a1 + 0x150) = -1;
        func_003C3938(a0, 0, 0);
        a1[0x15E] = 7;
        vt->f0(a0);
        return 0;
    }
    func_L01_004450F0(a0, 1, -1);
    return 1;
}
/* localdecomp:end func_L12_003D3338 */

/* localdecomp:start func_L12_003D3488 */
extern s32 func_L01_00452FB0(u8 *, u8 *, s32, s32, s32);
extern void func_L12_003D3538(u8 *, u8 *, s32);
extern void func_L01_00456BD0(u8 *, s32);

s32 func_L12_003D3488(u8 *self, u8 *target) {
    s32 r = func_L01_00452FB0(self, target + 112, 0, 0, 0);

    if (r != 0) {
        if ((u32)(r - 4) < 2) {
            func_L12_003D3538(self, target, 1);
            return 0;
        }
    }
    if (target[94] != 0) {
        func_L12_003D3538(self, target, 1);
        return 0;
    }
    if (target[62] == 2) {
        func_L12_003D3538(self, target, 0);
        return 0;
    }
    func_L01_00456BD0(self, 3);
    return 1;
}
/* localdecomp:end func_L12_003D3488 */
