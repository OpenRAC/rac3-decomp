#include "common.h"

/* localdecomp:start func_L31_0034D088 */
#include "vu0.h"

typedef struct {
    u8 pad0[0xD0];
    s32 iD0;
    s32 iD4;
    u8 padD8[0xF4 - 0xD8];
    s32 iF4;
    s32 iF8;
    s32 iFC;
} S_0034D088a;

typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1C[0x68 - 0x1C];
    S_0034D088a *p68;
} S_0034D088o;

typedef struct {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    void *pDC;
} S_0034D088h;

typedef struct {
    u8 pad0[0x84];
    f32 f84;
    f32 f88;
} S_0034D088k;

typedef struct {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[4];
    s32 i28;
    s32 i2C;
} S_0034D088g;

extern s32 func_L01_004561B8(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_L03_0034B148(s32, s32, f32);
extern void func_L30_0034CCD0(void *, f32 *, f32 *, f32 *, f32 *);
extern s32 func_00382498(s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void *func_L31_003AC0B0(f32 *, f32 *, s32, f32, s32, f32, f32, f32, s32, void *);
extern void func_L31_003AC210(void *, s32, f32, s32, s32, s32, f32, f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_003A4F28(s32);
extern void func_L31_0034B580(void *);

extern s32 D_L31_001DD244;
extern f32 D_L31_001DD1C8;
extern f32 D_L31_001DD1C4;
extern f32 D_L31_001DD1C0;
extern f32 D_L31_001DD318;
extern f32 D_L31_001DD1F4;
extern s32 D_L31_001DD1CC;
extern s32 D_L31_001DD1B4;
extern f32 D_L31_001DD1BC;
extern f32 D_L31_001DD1B8;
extern f32 D_L31_001DD1D0;
extern f32 D_L31_001DD1D4;
extern s32 D_L31_001DD1DC;
extern s32 D_L31_001DD1E0;
extern s32 D_L31_001DD1E4;
extern f32 D_L31_001DD1E8;
extern f32 D_L31_001DD1EC;
extern f32 D_L31_001DD1F0;
__asm__(".extern D_L31_001DD244, 4");
__asm__(".extern D_L31_001DD1C8, 4");
__asm__(".extern D_L31_001DD1C4, 4");
__asm__(".extern D_L31_001DD1C0, 4");
__asm__(".extern D_L31_001DD318, 4");
__asm__(".extern D_L31_001DD1F4, 4");
__asm__(".extern D_L31_001DD1CC, 4");
__asm__(".extern D_L31_001DD1B4, 4");
__asm__(".extern D_L31_001DD1BC, 4");
__asm__(".extern D_L31_001DD1B8, 4");
__asm__(".extern D_L31_001DD1D0, 4");
__asm__(".extern D_L31_001DD1D4, 4");
__asm__(".extern D_L31_001DD1DC, 4");
__asm__(".extern D_L31_001DD1E0, 4");
__asm__(".extern D_L31_001DD1E4, 4");
__asm__(".extern D_L31_001DD1E8, 4");
__asm__(".extern D_L31_001DD1EC, 4");
__asm__(".extern D_L31_001DD1F0, 4");
extern S_0034D088g D_L31_001E2440;
extern u8 D_001A30B0[];
extern S_0034D088k D_001A4BE0;
typedef struct {
    u8 pad0[0x80];
} S_0034D088c;

extern S_0034D088c *D_L31_001DF880;

void func_L31_0034D088(S_0034D088o *a0) {
    S_0034D088a *s = a0->p68;
    f32 r;
    f32 t;
    f32 x;
    f32 a, b, c, d;
    f32 pos[4] __attribute__((aligned(16)));
    f32 vec[4] __attribute__((aligned(16)));
    s32 n;
    s32 i;
    void *e;
    S_0034D088h *p;

    if (func_L01_004561B8(a0)) {
        s->iD0 = 0;
        s->iD4 = D_L31_001DD244;
        s->iF4 = 0;
        D_L31_001E2440.f20 = 0.5f;
        D_L31_001E2440.i28 = s->iD4;
        D_L31_001E2440.i2C = 0;
        a0->f18 = D_001A4BE0.f88 + D_L31_001DD1C8;
        if (s->iFC == -1 || (p = (S_0034D088h *)&D_001A30B0[s->iFC * 0x80])->pDC != a0 || !p->bD0) {
            s->iFC = func_003A52A0(4, 4, a0);
        }
    }
    r = func_L03_0034B148(s->iD4, D_L31_001DD244, 0.0f);
    func_L30_0034CCD0(&D_L31_001DF880[s->iF8], &a, &b, &c, &d);
    t = (a + b) * 0.5f;
    if (s->iD0 < (s32)(r * 8.0f)) {
        n = func_00382498(0, 7 - s->iD0);
        i = 0;
        s->iD0++;
        while (((s->iF4 >> i) & 1) || n != 0) {
            n -= !((s->iF4 >> i) & 1);
            i++;
        }
        x = func_003C4088(-D_L31_001DD1C4, D_L31_001DD1C4, (i + 0.5f) * 0.125f);
        qzero(vec);
        pos[1] = D_001A4BE0.f84;
        pos[2] = d + D_L31_001DD1C0;
        pos[0] = t + D_L31_001DD318 + x;
        s->iF4 |= 1 << i;
        e = func_L31_003AC0B0(pos, vec, D_L31_001DD1CC, D_L31_001DD1BC, D_L31_001DD1B4, D_L31_001DD1B8, D_L31_001DD1D0,
                              func_003824E0(-D_L31_001DD1F4, D_L31_001DD1F4), 0, a0);
        if (e) {
            func_L31_003AC210(e, 0, D_L31_001DD1D4, D_L31_001DD1DC, D_L31_001DD1E0, D_L31_001DD1E4, D_L31_001DD1E8,
                              D_L31_001DD1EC, D_L31_001DD1F0);
        }
    }
    if (func_0038CAD0(&s->iD4)) {
        s->iD0 = 0;
        if (s->iFC != -1 && (p = (S_0034D088h *)&D_001A30B0[s->iFC * 0x80])->pDC == a0 && p->bD0) {
            func_003A4F28(s->iFC);
        }
        s->iFC = -1;
        func_L31_0034B580(a0);
    }
}
/* localdecomp:end func_L31_0034D088 */
