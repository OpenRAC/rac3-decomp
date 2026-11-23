#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003D3520 */
typedef void (*Fn_L04_003D3520)(u8 *);

extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
extern Fn_L04_003D3520 *func_L01_0043B548(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L04_003D3520(u8 *m, u8 *v) {
    vu0_v4 pos;
    s32 idx;
    u8 *e;

    idx = *(s32 *)(v + 0xBC);
    if (idx != -1) {
        e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
            func_003A4F28(idx);
        }
    }
    *(s32 *)(v + 0xBC) = -1;
    if (m[0x20] == 2) {
        *(s32 *)(v + 0x90) = 1;
        if (*(s32 *)(v + 0x70) != 0 && ((s32 (*)(u8 *))func_L01_0043B548(0x19E1, 0x6C)[18])(m) != 0) {
            *(s32 *)(v + 0x98) = 0;
        } else {
            *(s32 *)(v + 0x98) = 0xB4;
        }
        func_0038CE20(&pos, m + 0xC0, 5.0f);
        vec_add_ab(&pos, &pos, m + 0x10);
        func_L01_003303B8(&pos, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                          1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003C3A10(m, 3, 0, 1);
        func_L01_004450F0(m, 5, -1);
    } else {
        *(s32 *)(v + 0x98) = 0;
        func_L01_003303B8(m + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                          1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003C3A10(m, 0, 0, 1);
        func_L01_004450F0(m, 5, -1);
    }
    if (*(s32 *)(v + 0x70) != 0) {
        func_L01_0043B548(0x19E1, 0x6C)[1](m);
    }
}
/* localdecomp:end func_L04_003D3520 */

/* localdecomp:start func_L04_003D37F8 */
typedef int Q_003D37F8 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003D37F8;
extern s32 D_L04_001DF940;
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004668A0(void *, void *, s32, s32, s32, f32);

void func_L04_003D37F8(u8 *self, u8 *p) {
    V_003D37F8 pos, vel, tmp;
    s32 c, color;
    f32 size;
    V_003D37F8 *vp;
    if (!(D_L04_001DF940 & 1)) {
        *(f32 *)(p + 0x9C) = func_0038DAB8(*(f32 *)(p + 0x9C), func_L01_00443A18(0.052359879f, 0.104719758f));
        *(Q_003D37F8 *)&pos = *(Q_003D37F8 *)(self + 0x10);
        pos.z += 1.0f;
        pos.x += func_0038D098(*(f32 *)(p + 0x9C)) * func_L01_00443A18(0.5f, 1.0f);
        pos.y += func_0038D0B0(*(f32 *)(p + 0x9C)) * func_L01_00443A18(0.5f, 1.0f);
        if (*(s32 *)(p + 0x90)) {
            func_0038CE20(&tmp, self + 0xC0, 3.0f);
            vec_add_ab(&pos, &tmp, &pos);
        }
        vel.x = func_0038D098(*(f32 *)(p + 0x9C)) * (func_003824E0(0.5f, 2.0f) * 0.020000001f);
        vel.y = func_0038D0B0(*(f32 *)(p + 0x9C)) * (func_003824E0(0.5f, 2.0f) * 0.020000001f);
        vel.z = 0.0f;
        vel.z = func_003824E0(0.040000003f, 0.100000009f);
        c = func_00382498(0x10, 0x20);
        color = (c << 16) | 0x80000000 | (c << 8) | c;
        vp = &vel;
        size = func_003824E0(3.0f, 5.0f) * 210000.0f;
        func_L01_004668A0(&pos, vp, color, 0x101010, (func_00382498(0x50, 0x78) * 5 + 2) / 6, size);
    }
}
/* localdecomp:end func_L04_003D37F8 */

/* localdecomp:start func_L04_003D3A30 */
typedef struct {
    u8 pad0[0x1C];
    s32 w1C;
    u8 pad20[0x54 - 0x20];
    u8 b54;
    u8 pad55[0x70 - 0x55];
    s32 w70;
} S_003D3A30;
typedef struct {
    u8 pad0[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 pad83[0xD0 - 0x83];
    s32 wD0;
    s32 wD4;
} D_003D3A30;
typedef struct {
    u8 pad0[0x43];
    u8 b43;
    u8 pad44[0x68 - 0x44];
    void *w68;
} M_003D3A30;

void func_L04_003D3A30(M_003D3A30 *a0, M_003D3A30 *a1) {
    S_003D3A30 *s = a1->w68;
    D_003D3A30 *d = a0->w68;
    s32 t;
    d->b80 = s->b54;
    t = s->w1C;
    if (t == 2) {
        d->b81 = 1;
        d->b82 = 1;
        d->wD0 = -1;
        d->wD4 = 0;
    } else if (t == 3) {
        d->b82 = 2;
        d->wD0 = s->w70;
        d->wD4 = 0;
    } else {
        d->b81 = *(u8 *)&s->w1C;
        d->wD0 = -1;
        d->b82 = 0;
        d->wD4 = 0;
    }
    if (a0->b43) {
        func_003C3A10(a0, 0, 0, 0);
    }
}
/* localdecomp:end func_L04_003D3A30 */

/* localdecomp:start func_L04_003D3AC8 */
typedef void (*Fn_003CF2A0)(u8 *);
extern Fn_003CF2A0 *func_L01_0043B548(s32, s32);
typedef struct { u8 pad0[0x10]; s32 w10; } Q_3D3AC8;
typedef struct { u8 pad0[0x24]; Q_3D3AC8 *w24; u8 pad28[0x98 - 0x28]; s32 w98; } R_3D3AC8;
typedef struct {
    u8 pad0[0x19E0];
    s32 w19E0;
    u8 pad19E4[0x25C0 - 0x19E4];
    R_3D3AC8 *w25C0;
    u8 pad25C4[0x25E5 - 0x25C4];
    u8 b25E5;
} G_3D3AC8;
typedef struct { u8 pad0[0x20]; u8 b20; u8 padBC[0xBC - 0x21]; u8 bBC; } M_3D3AC8;
extern G_3D3AC8 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern void func_L01_003EB5E0(s32, s32);
extern void func_L04_003D3EE0(void);
extern void func_L04_0050CB28(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
void func_L04_003D3AC8(M_3D3AC8 *m) {
    u8 t = m->b20;
    if (t == 2) {
        func_L01_003EB5E0(0, 0);
        func_L04_003D3EE0();
        D_001A4BE0.w25C0->w98 = D_001A4BE0.w25C0->w24->w10;
        D_001A4BE0.b25E5 = 0;
        func_L04_0050CB28(0, 1);
        D_001A4BE0.w19E0 = 0;
        m->bBC = t;
        func_L01_004450F0(m, 1, -1);
        func_L01_00456230(m, 0);
        func_003C3A10(m, 0, 0, 1);
    }
    (*func_L01_0043B548(0x19E1, 0x6C))((u8 *)m);
}
/* localdecomp:end func_L04_003D3AC8 */

/* localdecomp:start func_L04_003D3B90 */
extern f32 D_L04_001DEBDC_003D3B90;
extern f32 D_L04_001DEBE0_003D3B90;
extern f32 D_L04_001DEBE4_003D3B90;
extern f32 D_L04_001DEBE8_003D3B90;
extern f32 D_L04_001DEBEC_003D3B90;
extern f32 D_L04_001DEBF0_003D3B90;
extern f32 D_L04_001DEBF4_003D3B90;
extern f32 D_L04_001DEBF8_003D3B90;
extern f32 D_L04_001DEBFC_003D3B90;
extern f32 D_L04_001DEC00_003D3B90;
extern f32 D_L04_001DEC08_003D3B90;
extern s32 D_L04_001DEC0C_003D3B90;
extern s32 D_L04_001DEC10_003D3B90;
__asm__(".extern D_L04_001DEBDC_003D3B90, 4");
__asm__(".extern D_L04_001DEBE0_003D3B90, 4");
__asm__(".extern D_L04_001DEBE4_003D3B90, 4");
__asm__(".extern D_L04_001DEBE8_003D3B90, 4");
__asm__(".extern D_L04_001DEBEC_003D3B90, 4");
__asm__(".extern D_L04_001DEBF0_003D3B90, 4");
__asm__(".extern D_L04_001DEBF4_003D3B90, 4");
__asm__(".extern D_L04_001DEBF8_003D3B90, 4");
__asm__(".extern D_L04_001DEBFC_003D3B90, 4");
__asm__(".extern D_L04_001DEC00_003D3B90, 4");
__asm__(".extern D_L04_001DEC08_003D3B90, 4");
__asm__(".extern D_L04_001DEC0C_003D3B90, 4");
__asm__(".extern D_L04_001DEC10_003D3B90, 4");
extern void func_L01_00521C88_003D3B90(s32);
extern s32 func_003B5060(s32);
extern s32 func_003E51F8(s32);
extern s32 func_L01_00516470_003D3B90(s32, f32, f32);
extern void func_L01_00517538_003D3B90(s32 a0, f32 a1, f32 a2);
extern s32 func_L01_005170B8_003D3B90(s32, s32);
extern void func_L01_00516B90_003D3B90(s32, s32, s32);
extern void func_003EA610(s32);
extern void func_L01_00516640_003D3B90(s32, f32, f32);
extern void func_L01_00517340_003D3B90(s32, s32, s32, s32, s32);
extern s32 func_L01_00517190_003D3B90(s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);

void func_L04_003D3B90(void)
{
    func_L01_00521C88_003D3B90(1);
    func_003B5060(0x490000);

    func_003E51F8(0x490001);
    func_L01_00516470_003D3B90(0x490001, D_L04_001DEBDC_003D3B90, D_L04_001DEBF4_003D3B90);
    func_L01_00517538_003D3B90(0x490001, D_L04_001DEBE0_003D3B90, D_L04_001DEBE4_003D3B90);
    func_L01_005170B8_003D3B90(0x490001, 0x331465B7);
    func_L01_00516B90_003D3B90(0x490001, 3, 3);

    func_003EA610(0x490002);
    func_L01_00516470_003D3B90(0x490002, D_L04_001DEBDC_003D3B90, D_L04_001DEBF4_003D3B90);
    func_L01_00517538_003D3B90(0x490002, D_L04_001DEBE0_003D3B90, D_L04_001DEBE4_003D3B90);
    func_L01_00516640_003D3B90(0x490002, D_L04_001DEBE8_003D3B90, D_L04_001DEBEC_003D3B90);
    func_L01_005170B8_003D3B90(0x490002, 0x332299DE);
    func_L01_00516B90_003D3B90(0x490002, 3, 3);

    func_003EA610(0x490003);
    func_L01_00516470_003D3B90(0x490003, D_L04_001DEBF0_003D3B90, D_L04_001DEBF4_003D3B90);
    func_L01_00517538_003D3B90(0x490003, D_L04_001DEBFC_003D3B90, D_L04_001DEBF8_003D3B90);
    func_L01_00516640_003D3B90(0x490003, D_L04_001DEBE8_003D3B90, D_L04_001DEBEC_003D3B90);
    func_L01_005170B8_003D3B90(0x490003, 0x332299DE);
    func_L01_00516B90_003D3B90(0x490003, 1, 3);

    func_003E51F8(0x490004);
    func_L01_00516470_003D3B90(0x490004, D_L04_001DEBDC_003D3B90 - D_L04_001DEC00_003D3B90, D_L04_001DEBF4_003D3B90);
    func_L01_00517538_003D3B90(0x490004, 0.0f, D_L04_001DEBF8_003D3B90);
    func_L01_005170B8_003D3B90(0x490004, 0x706EC8FF);
    func_L01_00516B90_003D3B90(0x490004, 2, 3);
    func_L01_00517340_003D3B90(0x490004, D_L04_001DEC10_003D3B90, D_L04_001DEC0C_003D3B90, D_L04_001DEC10_003D3B90, D_L04_001DEC0C_003D3B90);

    func_003E51F8(0x490005);
    func_L01_00516470_003D3B90(0x490005, D_L04_001DEBDC_003D3B90 + D_L04_001DEC00_003D3B90, D_L04_001DEBF4_003D3B90);
    func_L01_00517538_003D3B90(0x490005, 0.0f, D_L04_001DEBF8_003D3B90);
    func_L01_005170B8_003D3B90(0x490005, 0x706EC8FF);
    func_L01_00516B90_003D3B90(0x490005, 1, 3);
    func_L01_00517340_003D3B90(0x490005, D_L04_001DEC0C_003D3B90, D_L04_001DEC10_003D3B90, D_L04_001DEC0C_003D3B90, D_L04_001DEC10_003D3B90);

    func_003E51F8(0x490006);
    func_L01_00516470_003D3B90(0x490006, D_L04_001DEBDC_003D3B90, D_L04_001DEBF4_003D3B90);
    func_L01_00517538_003D3B90(0x490006, D_L04_001DEC08_003D3B90, D_L04_001DEBF8_003D3B90);
    func_L01_005170B8_003D3B90(0x490006, 0x706EC8FF);
    func_L01_00516B90_003D3B90(0x490006, 3, 3);
    func_L01_00517190_003D3B90(0x490006, 0xED42);

    func_003E8630(0x490000, 0x490001);
    func_003E8630(0x490000, 0x490002);
    func_003E8630(0x490000, 0x490003);
    func_003E8630(0x490000, 0x490004);
    func_003E8630(0x490000, 0x490005);
    func_003E8630(0x490000, 0x490006);
    func_003E8348(13, 0x490000);
    func_L01_00521C88_003D3B90(0);
}
/* localdecomp:end func_L04_003D3B90 */

/* localdecomp:start func_L04_003D3EE0 */
extern void func_L01_00517918(s32);
void func_L04_003D3EE0(void) {
    func_L01_00517918(13);
}
/* localdecomp:end func_L04_003D3EE0 */

/* localdecomp:start func_L04_003D3F00 */
__asm__(".extern D_L04_001DEC04, 4");
extern f32 D_L04_001DEC04;
__asm__(".extern D_L04_001DEBF8, 4");
extern f32 D_L04_001DEBF8;
extern void func_L01_00517538(s32 a0, f32 a1, f32 a2);

void func_L04_003D3F00(void *a0, u8 *a1)
{
    f32 t = *(f32 *)(a1 + 48) / (f32)*(s16 *)(a1 + 52);

    func_L01_00517538(0x490004, D_L04_001DEC04 * t, D_L04_001DEBF8);
    func_L01_00517538(0x490005, D_L04_001DEC04 * t, D_L04_001DEBF8);
}
/* localdecomp:end func_L04_003D3F00 */

/* localdecomp:start func_L04_003D3F68 */
__asm__(".extern D_L04_001DEBA4, 4");
extern f32 D_L04_001DEBA4;
__asm__(".extern D_L04_001DEBA8, 4");
extern f32 D_L04_001DEBA8;

void func_L04_003D3F68(u8 *a0, u8 *a1, void *a2) {
    vu0_v4 v;
    v.x = func_0038D098(*(f32 *)(a0 + 0xF8)) * D_L04_001DEBA4;
    v.y = func_0038D0B0(*(f32 *)(a0 + 0xF8)) * D_L04_001DEBA4;
    v.z = 0.0f;
    v.z += D_L04_001DEBA8;
    vec_add_ab(*(u8 **)(a1 + 0xD4) + 0x10, a2, &v);
    *(f32 *)(*(u8 **)(a1 + 0xD4) + 0xF8) = *(f32 *)(a0 + 0xF8);
}
/* localdecomp:end func_L04_003D3F68 */
