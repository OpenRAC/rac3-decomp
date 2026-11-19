/* functional: medium. Hand-decoded from the retail asm; the moby fix-up loop is the same routine as the matched sibling func_L18_00436E90 (checked line by line against it); the four state arms (f30 = 0..3) were traced instruction by instruction, incl. the 30-arg func_L01_003303B8 stack layout and the 100-iteration spark loop (x = 3 sin r2 cos r1, y = 3 sin r2 sin r1, z = 3 cos r2). vadd.xyz is written as plain float adds (w copied as retail). Differences from retail: none intended; m == 0 is dereferenced exactly as retail does (it reads 0xAA(0) there; never null in practice). Needs the file flags for bytes only. */
#include "common.h"
#include "vu0.h"

/* Kerwan level script (per-frame): fixes up mobys by type, then runs the intro/boss cutscene
   states keyed on D_L16_001E6EC0.f30 (mode) and f34 (frame counter). */
typedef struct { u8 p0[0x34]; u16 h34; u8 p36[0x2D]; u8 b63; u8 p64[4]; u8 *p68; u8 p6C[0x3E]; s16 hAA; } M_434C98;
typedef struct {
    u8 p0[0x30];
    s32 f30;
    s32 f34;
    u8 p38[0xC];
    s16 count;
    u8 p46[0x15A];
    M_434C98 *list[8];  /* 0x1A0..0x1BC: mobys; list[2]=0x1A8, [4]=0x1B0, [5]=0x1B4, [6]=0x1B8, [7]=0x1BC */
} S_434C98;

extern S_434C98 D_L16_001E6EC0;
extern M_434C98 *D_0023A2B0[];
extern u32 D_001D545C_00434C98;
__asm__(".extern D_001D545C_00434C98, 16");
extern u8 D_L16_001D6AE0[4];
__asm__(".extern D_L16_001D6AE0, 4");
extern u8 D_L16_001D6AE4[4];
extern u8 D_L16_001D6AE8[4];
extern u8 D_L16_001D6AEC[4];
extern s32 D_L16_001D6C88;
__asm__(".extern D_L16_001D6C88, 4");
extern s32 D_L16_001D6C48;
__asm__(".extern D_L16_001D6C48, 4");
extern vu0_v4 D_L16_001E2B20[];
extern u8 D_L16_001EF3D0[];
extern vu0_v4 D_L16_001EFAB0[];

extern void func_L01_00423AB8(void);
extern void func_L01_00423DF0(void);
extern void func_003A58C0(void *, s32);
extern void func_L01_004048D0(void *, void *);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00424168(void *);
extern void func_003A7AF8(void *);
extern void *func_L08_00406A30(s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L16_004345B8(void *, vu0_v4, vu0_v4, vu0_v4, s32);
extern void func_L01_00423C48(void *, f32, f32, f32);
extern void func_L03_00411778(s32, s32);
extern void func_L16_00434290(void);
extern void func_L16_00434938(void *);
extern void func_L03_00411C40(void *, s32, s32, s32);
extern void func_L16_00434A50(void *, void *);
extern void func_L16_00434A78(void *, void *, void *, void *, void *);
extern void func_L16_00434A00(void);
extern void func_L16_00434B70(void *);
extern void func_L16_00434AE8(void);
extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L08_00406AB0(void *, s32, s32, s32, f32, f32, f32);
extern void func_L08_004070C0(s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void *func_L10_00406780(s32);
extern void func_L01_004D7DC8(u8 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L16_00434C98(void) {
    S_434C98 *S = &D_L16_001E6EC0;
    M_434C98 *m;
    M_434C98 **p;
    vu0_v4 v90, vA0, vB0, vC0, vD0, vE0;
    vu0_v4 *a, *b;
    void *obj;
    f32 r1, r2, s, k;
    s32 i, kk, t, h, id;

    func_L01_00423AB8();
    for (i = 0; i < S->count; ) {
        id = 0xD54;
        m = S->list[i];
        if (m != 0 && m->hAA == 0xE29) m->h34 |= 0x800;
        i++;
        if (m->hAA == id) {
            m->b63 = 0;
            for (p = D_0023A2B0; *p != 0; p++) {
                if ((*p)->b63 != 0) (*p)->b63 = 1;
            }
            func_003A58C0(m, 0);
            func_L01_004048D0(func_003A7AF8, m);
        }
        if (m != 0) {
            h = m->hAA;
            if (h == 0xFA0) {
                if (m->p68 != 0) func_L01_00451DB8(m, m->p68 + 0xC, 0x80AAAAD2, 0x80396464, 0.07330383f);
            } else if (h == 0x1DEE || h == 0x19BC) {
                func_L01_00451DB8(m, D_L16_001D6AE0, 0x80505080, 0x80404038, 0.038397245f);
            } else if (h == 0x1977) {
                func_L01_00451DB8(m, D_L16_001D6AE4, 0x8080AAAA, 0x80464646, 0.045378566f);
            } else if (h == 0x1766) {
                func_L01_00451DB8(m, D_L16_001D6AE8, 0x80AAAAFF, 0x80646496, 0.13264504f);
            } else if (h == 0x195B || h == 0x1B58 || h == 0x195C || h == 0x175A) {
                func_L01_00404808(func_L01_00424168, m);
            }
        }
    }
    obj = func_L08_00406A30(0x1EFD);
    if (obj != 0) func_L01_00451DB8(obj, D_L16_001D6AEC, -0x191A, -0x7374, 0.040142577f);

    if (D_001D545C_00434C98 != 0x10) return;

    if (S->f30 == 0) {
        func_L01_00423DF0();
        if (S->f30 == 0 && S->f34 < 0x1A2) {
            func_0038CF68(&v90, &D_L16_001E2B20[0], 5.0f);
            v90.z += 5.0f;
            if (func_00382468(2) != 0) {
                func_0038CF68(&vA0, &D_L16_001E2B20[1], 15.0f);
                func_0038CF68(&vB0, &D_L16_001E2B20[1], 25.0f);
            } else {
                func_0038CF68(&vA0, &D_L16_001E2B20[1], -15.0f);
                func_0038CF68(&vB0, &D_L16_001E2B20[1], -25.0f);
            }
            a = &vA0;
            b = &vB0;
            if (func_00382468(5) == 0) {
                func_L16_004345B8(S->list[0], v90, *a, *b, func_00382468(2) + 2);
            }
            if (S->f34 % 0x14 == 0 && func_00382468(4) == 0) {
                qzero(&vC0);
                vC0.x = 18.0f;
                vC0.z = -2.0f;
                func_L01_00423C48(&vC0, 8.0f, 0.5f, 2.0f);
            }
        }
        func_L03_00411778(0x66, 0x190);
        func_L16_00434290();
        return;
    }

    if (S->f30 == 1) {
        qzero(&v90);
        qzero(&vA0);
        v90.z = 15.0f;
        vA0.z = 2.0f;
        func_L16_00434290();
        t = S->f34;
        if (t == 1) D_L16_001D6C88 = 0x5FD;
        if (t == 0xCF9) func_L16_00434938(S->list[6]);
        func_L03_00411C40(S->list[4], 0xC8, 0x40400000, 0x40404040);
        t = S->f34;
        if (t == 0xD09 || t == 0xD16) {
            qzero(&vD0);
            vD0.z += 1.0f;
            {
                vu0_v4 *pp = (vu0_v4 *)((u8 *)S->list[7] + 0x10);
                vD0.x = pp->x + vD0.x;
                vD0.y = pp->y + vD0.y;
                vD0.z = pp->z + vD0.z;
                vD0.w = pp->w;
            }
        }
        t = S->f34;
        if ((u32)(t - 0xCF9) < 0x1E) {
            func_L16_00434A50(S->list[7], &vA0);
            for (kk = 0; kk < 10; kk++) {
                vE0 = D_L16_001EFAB0[kk];
                func_L16_00434A78(S->list[6], &v90, &vE0, D_L16_001EF3D0 + kk * 0xB0, &D_L16_001D6C48);
                func_L01_00404808(func_L16_00434A00, 0);
            }
        }
        t = S->f34;
        if ((u32)(t - 0x5FD) < 0xE || (u32)(t - 0xBB8) < 0xD) {
            if (t == 0xBB8) D_L16_001D6C88 = t;
            func_L16_00434B70(S->list[5]);
            func_L01_00404808(func_L16_00434AE8, 0);
        }
        t = S->f34;
        if (t == 0xD09) {
            for (kk = 99; kk >= 0; kk--) {
                vB0 = vD0;
                r1 = (f32)func_00382468(0x168) * 0.017453292f;
                r2 = (f32)func_00382468(0x168) * 0.017453292f;
                s = func_0038D0B0(r2) * 3.0f;
                vE0.x = s * func_0038D098(r1);
                vE0.y = s * func_0038D0B0(r1);
                vE0.z = func_0038D098(r2) * 3.0f;
                func_0038CF68(&vC0, &vE0, -0.1f);
                vB0.x = vE0.x + vB0.x;
                vB0.y = vE0.y + vB0.y;
                vB0.z = vE0.z + vB0.z;
                vB0.w = vE0.w;
                k = func_003824E0(0.5f, 0.7f);
                func_L01_0046C470(&vB0, &vC0, 0x80802010, k, 0x1E, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
            }
        } else if (t == 0xD16) {
            vD0.x = vD0.x + 0.0f;
            vD0.y = vD0.y + -2.0f;
            func_L08_00406AB0(S->list[7], 0x80802010, 0x80802010, 10, 4.0f, 8.0f, 3.0f);
        }
        return;
    }

    if (S->f30 == 2) {
        if (S->f34 == 0xC77) {
            qzero(&v90);
            v90.z += 2.0f;
            func_L08_004070C0(3, &v90, 0x14, 2, 0x64, 0x32, 0x60204080, 0x80204080, 0x80204080, 1.0f, 1.0f);
            qzero(&v90);
            v90.z += 1.0f;
            func_L08_004070C0(4, &v90, 0x14, 2, 0x64, 0x32, 0x60204080, 0x80204080, 0x80204080, 1.0f, 1.0f);
        }
        func_L03_00411778(0x4A6, 0xF36);
        obj = func_L10_00406780(0x1F85);
        if (obj != 0) func_L01_004D7DC8(obj, 0x38, 0x88, 0x40, 0x80, 0x18, 0x40, 0x18, 0x64);
        return;
    }

    if (S->f30 == 3) {
        if (S->f34 == 0x34) {
            M_434C98 *src = S->list[2];
            if (src != 0) {
                v90 = *(vu0_v4 *)((u8 *)src + 0x10);
                func_L01_003303B8(&v90, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.5f, 0.0f, 0.0f, 2.0f,
                    1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                    0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            }
        }
    }
}
