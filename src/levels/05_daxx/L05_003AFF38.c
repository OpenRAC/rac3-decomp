#include "common.h"
#include "vu0.h"

/* declared by functions of L05_003AFC08.c, which this file was cut from */
extern void func_00382580(void *, f32, f32);

typedef struct { u8 pad[0x2A0]; s32 ids[3]; } V_3B00A8;

/* localdecomp:start func_L05_003AFF38 */
extern s32 func_0038DC20(void *, f32);
extern void func_L05_003AFC08(f32, u8 *, s32, u8 *, s32);
extern void func_00382580(void *, f32, f32);

void func_L05_003AFF38(u8 *obj, f32 x, f32 y, f32 z, f32 w, s32 arg, s32 color, s32 cnt) {
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    f32 r;
    s32 i;

    color = (color == 0x1FF) ? 0xFF : color;
    *(vu0_q *)&v0 = *(vu0_q *)(obj + 0x10);
    v0.w = w + w;
    r = 128.0f;
    if (color > 128) {
        r = color;
    }
    if (func_0038DC20(&v0, r) < 0) {
        return;
    }
    func_00382580(&v1, y * 0.8f, y * 1.2f);
    v1.z += x;
    vec_add_ba(&v1, &v1, obj + 0x10);
    for (i = 0; i < 2; i++) {
        func_00382580(&v2, z * 0.75f, z * 1.25f);
        vec_add_ab(&v2, &v1, &v2);
        func_L05_003AFC08(w * 0.75f, (u8 *)&v2, arg, (u8 *)color, cnt);
    }
}
/* localdecomp:end func_L05_003AFF38 */

/* localdecomp:start func_L05_003B00A8 */
#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(u8 **)((u8 *)(p) + (o)))

extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern s16 D_001CD018[];
extern u8 *D_L05_001DFB9C;
extern u8 *D_L05_001DFC80;
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
extern u8 D_00142660[];
extern s32 D_001A7430[];
extern s32 D_00142668[];
extern u8 D_L05_001D9AE0[8];
extern u8 D_L05_001DAF30;
extern u8 D_001D66B0;
extern u8 D_L05_001E2700[];
extern u8 *D_L05_002208AC[];
extern vu0_v4 D_L05_001DE7B0 __attribute__((section(".sdata")));
__asm__(".extern D_L05_001DE7B0, 4");

extern void func_L05_003B12E8(u8 *);
extern void func_L05_003B1100(u8 *);
extern void func_L05_003B1778(u8 *);
extern void func_L05_003B19E8(u8 *);
extern void func_L05_003B1A40(u8 *);
extern u8 *func_L05_003B1BD0(u8 *, void *);
extern void func_L05_003B1CF8(u8 *);
extern s32 func_L05_003B1E80(s32, s32);
extern void func_L05_003B2E40(u8 *);
extern u8 *func_L05_00362148(u8 *, vu0_v4 *, vu0_v4 *, s32, s32, u8, f32);
extern void func_L05_003AFF38(u8 *, f32, f32, f32, f32, s32, s32, s32);
extern void func_L05_003B1E90(u8 *);
extern void func_L05_003B21A8(u8 *);
extern void func_L05_003B2668(u8 *);
extern void func_L05_003B29D0(u8 *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00404A10(void *, void *);
extern s32 func_0038CB00(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_003C2880(void *);
extern void func_L01_0043B510(s32);
extern void func_003CA4A0();
extern s32 func_00382380(void *, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044AF78(void *, void *, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C4C18(void *, f32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_003A1930(s32, s32, s32);
extern void func_L01_0045F1E8(s32, s32);
extern void func_003A1C28(void);
extern u8 *func_L01_00470150(void *, void *, s32, s32, s32, s32, f32, f32, s32, s32, f32, s32, s32);
extern void func_L01_004A3610(u8 *, u8 *);
extern void func_L01_004AA760(s32, void *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);


void func_L05_003B00A8(u8 *m)
{
    vu0_v4 v90;
    vu0_v4 mtx[4];
    vu0_v4 vE0;
    vu0_v4 vF0;
    s32 t;
    u8 *v;
    u8 *o;
    s32 *p;
    s32 *q0;
    s32 *ids;
    s32 i;
    s32 j;
    f32 f;

    v = PTR(m, 0x68);
    func_L05_003B12E8(m);
    func_L05_003B1100(m);
    if (D_001BBC40[U8(m, 0xB0) + (D_001D545C << 4)] & 0x80) {
        s32 *pp = (s32 *)(v + 0x2A0);
        u8 *o2;
        if (D_001CD018[0] == S32(v, 0x2C8)) {
            func_003A1C28();
            func_003A1930(0, 1, 0x400);
        }
        for (i = 0; i < 2; i++) {
            u8 *q = D_L05_001DFB9C + (*pp++ << 8);
            S32(q, 0x98) = 0;
            U16(q, 0x34) = (U16(q, 0x34) | 0x41) & ~0x1000;
            func_L01_004AA7E8(q, 1);
        }
        o2 = D_L05_001DFB9C + (S32(v, 0x2A8) << 8);
        U16(o2, 0x34) &= ~0x41;
        U16(o2, 0x34) |= U16(PTR(o2, 0x24), 0x44) & 0x1000;
        S32(o2, 0x98) = S32(PTR(o2, 0x24), 0x10);
        func_003C2880(m);
        return;
    }
    switch (U8(m, 0x20)) {
    case 1:
        func_L01_004450F0(m, 2, -1);
        break;
    case 2:
        ids = ((V_3B00A8 *)v)->ids;
        p = ids;
        ids += U8(v, 0x2C0);
        o = D_L05_001DFB9C + (*ids << 8);
        if (func_00382380(D_001A4BE0 + 0x80, S32(v, 0x2C4), 0) == 0) {
            break;
        }
        {
            u8 *g1 = D_001A4BE0;
            if (S32(g1, 0x25CC) == 0xE && o == PTR(g1, 0xA54)) {
                return;
            }
        }
        F32(m, 0xF8) = func_0038D160(F32(v, 0x260) - F32(m, 0x10), F32(v, 0x264) - F32(m, 0x14));
        D_L05_001DAF30 = 1;
        func_L05_003B1A40(m);
        func_L05_003B19E8(m);
        func_L05_003B1778(m);
        U8(v, 0x2B9) = 2;
        q0 = p;
        for (j = 0; j < 2; j++) {
            o = D_L05_001DFB9C;
            o += *q0++ << 8;
            func_L01_0044AF78(o, D_L05_001D9AE0, 0, 0.5f, 1.0f, 5.0f, 2.5f, 9.0f, 1.5f, 15.0f, 10, 3, 16, -1, 1, 1, -1, 0, 0x1010001);
            S32(o, 0x98) = 0;
            U16(o, 0x34) = (U16(o, 0x34) | 0x41) & ~0x1000;
            func_L01_004AA7E8(o, 1);
        }
        func_003A1C28();
        func_003A1930(S32(v, 0x2C8), 1, 0x400);
        {
            u8 *h = D_00142660;
            u8 *g2 = D_001A4BE0;
            S32(g2, 0x2850) = S32(h, 8);
        }
        func_L01_004450F0(m, 3, -1);
        break;
    case 3:
        if (func_L01_004561B8(m)) {
            func_L01_004AAC98(3, 4, m, 0x1A13);
            S16(v, 0x2B4) = 100;
        }
        if (func_0038CB00(v + 0x2B4)) {
            D_001A7430[0] = D_00142668[0];
            func_L01_004450F0(m, 6, -1);
            U16(m, 0x34) |= 0x4000;
            break;
        }
        func_L01_00404A10(func_L05_003B1E90, m);
        break;
    case 6:
        if (func_L01_004561B8(m)) {
            if (U8(v, 0x2B8) >= 2) {
                func_L01_004AAC98(3, 0, m, 0x1A13);
            }
            U8(v, 0x2B9) = 1;
            S16(v, 0x2B4) = 100;
        }
        func_L05_003B1778(m);
        if (U8(v, 0x2B8) < 2) {
            func_L05_003B2E40(m);
            break;
        }
        if (func_0038CB00(v + 0x2B4)) {
            func_L01_004450F0(m, 7, -1);
            break;
        }
        func_L01_00404A10(func_L05_003B1E90, m);
        break;
    case 7:
        if (func_L01_004561B8(m)) {
            S16(v, 0x2B4) = 0x11;
        }
        if (func_0038CB00(v + 0x2B4)) {
            func_L05_003B1A40(m);
            func_L05_003B19E8(m);
            func_L05_003B1778(m);
            U8(v, 0x2B9) = 2;
            func_L01_004450F0(m, 8, -1);
        }
        break;
    case 8:
        if (func_L01_004561B8(m)) {
            func_L01_004AAC98(3, 0, m, 0x1A13);
            S16(v, 0x2B4) = 100;
        }
        func_L05_003B1778(m);
        if (func_0038CB00(v + 0x2B4)) {
            func_L05_003B2E40(m);
            break;
        }
        func_L01_00404A10(func_L05_003B1E90, m);
        break;
    case 9:
        if (func_L01_004561B8(m)) {
            F32(v, 0x284) = 4.6f;
            F32(v, 0x290) = 22.0f;
            U8(v, 0x2BB) = 3;
            U8(v, 0x2BE) = 1;
            S16(v, 0x2B4) = 0x7D;
            S32(v, 0x270) = 0;
        }
        func_L05_003B1778(m);
        F32(v, 0x248) = -0.17453292f;
        F32(v, 0x1C8) = 0.17453292f;
        if (func_0038CB00(v + 0x2B4)) {
            func_L01_004450F0(m, 10, -1);
        }
        break;
    case 10:
        if (func_L01_004561B8(m)) {
            S16(v, 0x2B4) = 0x75;
            func_L01_004AAC98(2, 4, m, 0x1A13);
        }
        func_L05_003B1778(m);
        F32(v, 0x248) = 0.69813168f;
        F32(v, 0x1C8) = -0.69813168f;
        func_L05_003B1CF8(m);
        func_L01_00404808(func_L05_003B21A8, m);
        if (func_0038CB00(v + 0x2B4)) {
            if (U8(v, 0x2B8) >= 4) {
                func_L01_004450F0(m, 11, -1);
            } else {
                U8(v, 0x2BE) = 0;
                func_L05_003B1A40(m);
                func_L01_004AA760(2, m);
                func_L01_004450F0(m, 6, -1);
            }
        }
        break;
    case 11:
        if (func_L01_004561B8(m)) {
            S16(v, 0x2B4) = 0x75;
        }
        func_L05_003B1778(m);
        F32(v, 0x248) = -0.17453292f;
        F32(v, 0x1C8) = 0.17453292f;
        func_L05_003B1CF8(m);
        func_L01_00404808(func_L05_003B21A8, m);
        if (func_0038CB00(v + 0x2B4)) {
            U8(v, 0x2BE) = 0;
            func_L05_003B1A40(m);
            func_L01_004AA760(2, m);
            func_L01_004450F0(m, 6, -1);
        }
        break;
    case 12:
        if (func_L01_004561B8(m)) {
            U8(v, 0x2BA) = func_00382498(0, 1);
            switch (U8(v, 0x2BA)) {
            case 0:
                F32(v, 0x27C) = func_0038DB00(F32(v, 0x278), 0.87266463f);
                U8(v, 0x2BB) = 2;
                break;
            case 1:
                F32(v, 0x27C) = func_0038DAB8(F32(v, 0x278), 0.87266463f);
                U8(v, 0x2BB) = 1;
                break;
            }
            F32(v, 0x284) = 4.6f;
            F32(v, 0x290) = 22.0f;
            U8(v, 0x2BE) = 1;
            U8(v, 0x2BF) = 1;
            S16(v, 0x2B4) = 0x96;
        }
        func_L05_003B1778(m);
        if (func_0038CB00(v + 0x2B4)) {
            switch (U8(v, 0x2BA)) {
            case 0:
                F32(v, 0x27C) = func_0038DAB8(F32(v, 0x278), 1.0821041f);
                break;
            case 1:
                F32(v, 0x27C) = func_0038DB00(F32(v, 0x278), 1.0821041f);
                break;
            }
            func_L01_004450F0(m, 0xD, -1);
        }
        break;
    case 13:
        if (func_L01_004561B8(m)) {
            S16(v, 0x2B4) = 200;
            func_L01_004AAC98(2, 4, m, 0x1A13);
        }
        func_L05_003B1778(m);
        func_L05_003B1CF8(m);
        func_L01_00404808(func_L05_003B21A8, m);
        if (func_0038CB00(v + 0x2B4)) {
            U8(v, 0x2BE) = 0;
            U8(v, 0x2BF) = 0;
            func_L05_003B1A40(m);
            func_L01_004AA760(2, m);
            func_L01_004450F0(m, 0xE, -1);
        }
        break;
    case 14:
        if (func_L01_004561B8(m)) {
            S16(v, 0x2B4) = 0x3E;
        }
        func_L05_003B1778(m);
        if (func_0038CB00(v + 0x2B4)) {
            func_L01_004450F0(m, 6, -1);
        }
        break;
    case 15:
        if (func_L01_004561B8(m)) {
            U8(v, 0x2BD) = func_00382498(4, 6);
            S16(v, 0x2B4) = 100;
            U8(v, 0x2BC) = 0;
        }
        t = func_L05_003B1E80(U8(v, 0x2BA), 0);
        f = F32(m, 0x2C);
        f = f * 0.0009765625f;
        func_003CA4A0(m, 1, &t, mtx);
        func_0038CE20(&v90, &mtx[3], f);
        if (S16(v, 0x2B4) < 6) {
            u8 *r;
            *(vu0_q *)&vE0 = *(vu0_q *)&v90;
            f = 3 - S16(v, 0x2B4) / 2;
            f = f * 0.8f;
            f = f + 1.5f;
            f *= func_003824E0(0.9f, 1.1f);
            func_003C4C18(&vE0, 0.3f);
            r = func_L01_00470150(&vE0, m, 0x30204080, -1, 0, 10, f * 210000.0f, 0.0f, 0, -1, 0.92f, func_00382468(2) ? 0xD0 : 0x30, 0);
            if (r != 0) {
                r[2] = *D_L05_002208AC[0];
            }
        }
        func_L05_003B1778(m);
        if (func_0038CB00(v + 0x2B4)) {
            u8 *r;
            func_0038D000(&v90, &v90, m + 0xC0);
            vec_add_ab(&v90, &v90, m + 0x10);
            *(vu0_q *)&vE0 = *(vu0_q *)(v + 0x140);
            if (func_L01_0040E570(&vE0, &D_L05_001DE7B0) > 118.80999f) {
                vec_sub_ab(&vF0, &vE0, &D_L05_001DE7B0);
                vF0.z = 0.0f;
                func_0038CF68(&vF0, &vF0, 10.9f);
                vec_add_ab(&vE0, &D_L05_001DE7B0, &vF0);
            }
            r = func_L05_003B1BD0(m, &vE0);
            if (r != 0) {
                vE0.z = F32(r, 0x18) + 0.2f;
            } else {
                vE0.z = 32.35f;
            }
            func_L05_00362148(m, &v90, &vE0, (s32)r, 0x3C, 1, U8(v, 0x44));
            func_L01_004AAC98(1, 0, m, 0x1A13);
            if (U8(v, 0x2BC) >= U8(v, 0x2BD)) {
                func_L01_004450F0(m, 0x10, -1);
            } else {
                U8(v, 0x2BC)++;
                S16(v, 0x2B4) = 0x19;
                U8(v, 0x2BA) ^= 1;
            }
        }
        break;
    case 16:
        if (func_L01_004561B8(m)) {
            S16(v, 0x2B4) = 0x32;
        }
        func_L05_003B1778(m);
        if (func_0038CB00(v + 0x2B4)) {
            func_L01_004450F0(m, 6, -1);
        }
        break;
    case 17:
        if (func_L01_004561B8(m)) {
            F32(v, 0x27C) = 0.0f;
            S16(v, 0x2B4) = 0x70;
            func_L01_004AAC98(5, 0, m, 0x1A13);
        }
        if (S16(v, 0x2B4) % 6 == 0) {
            func_L05_003AFF38(m, 2.0f, 3.0f, 1.5f, F32(m, 0x2C) / F32(PTR(m, 0x24), 0x24), 5, 0xFF, 2);
            if (S16(v, 0x2B4) % 42 == 0) {
                u8 *e = D_L05_001E2700;
                F32(e, 0x11A0) = 1.0f;
                S32(e, 0x11A8) = 0x19;
                S32(e, 0x11AC) = 0;
                func_L01_004AAC98(5, 0, m, 0x1A13);
            }
        }
        func_L05_003B1778(m);
        F32(m, 0x18) -= 0.6f;
        if (func_0038CB00(v + 0x2B4)) {
            func_L01_004450F0(m, 0x12, -1);
        }
        break;
    case 18:
        if (func_L01_004561B8(m)) {
            S32(v, 0x29C) = 0;
            S16(v, 0x2B4) = 0x19;
            func_L01_004AAC98(5, 0, m, 0x1A13);
        }
        if (S16(v, 0x2B4) % 6 == 0) {
            func_L05_003AFF38(m, 0.0f, 3.0f, 1.7f, F32(m, 0x2C) / F32(PTR(m, 0x24), 0x24), 5, 0xFF, 2);
        }
        func_L05_003B1778(m);
        F32(m, 0x18) -= 0.3f;
        if (func_0038CB00(v + 0x2B4)) {
            func_L01_004450F0(m, 0x13, -1);
            break;
        }
        func_L01_00404808(func_L05_003B2668, m);
        break;
    case 19:
        if (func_L01_004561B8(m)) {
            S32(v, 0x29C) = 0;
            S16(v, 0x2B4) = 0x43;
            F32(v, 0x298) = func_00382538();
            U8(v, 0x2C1) = 1;
            func_L01_004AAC98(5, 0, m, 0x1A13);
        }
        if (S16(v, 0x2B4) % 6 == 0) {
            func_L05_003AFF38(m, 0.0f, 5.0f, 2.0f, F32(m, 0x2C) / F32(PTR(m, 0x24), 0x24), 5, 0xFF, 2);
        }
        if (func_0038CB00(v + 0x2B4)) {
            func_L01_004450F0(m, 0x15, -1);
            break;
        }
        S32(m, 0x98) = 0;
        U16(m, 0x34) = (U16(m, 0x34) | 0x41) & ~0x1000;
        func_L01_004AA7E8(m, 1);
        func_L01_00404808(func_L05_003B29D0, m);
        if (U8(v, 0x2C1) != 0) {
            func_L01_00451FE0(m, 0x3FFF, &D_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            {
                u8 *e = D_L05_001E2700;
                F32(e, 0x40) = 0.15f;
                S32(e, 0x48) = 0x19;
                S32(e, 0x2C) = 0;
            }
            func_0038CF68(&mtx[0], m + 0xE0, 1.0f);
            vec_add_ab(&v90, m + 0x10, &mtx[0]);
            func_L01_003303B8(&v90, 0, 0x19, 0, 0x28, 0x19, 0x23, 1, 1.5f, 0.0f, 0.0f, 2.0f,
                              0, 1, 1, 1, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            U8(v, 0x2C1) = 0;
        }
        break;
    case 21:
        func_L01_0045F1E8(0, S32(v, 0x2CC));
        func_L01_004443E8(m, 0, 3);
        func_L01_0043B510(U8(m, 0xB0));
        {
            u8 *a = D_L05_001DFC80 + (S32(v, 0x2C4) << 7);
            func_L01_004A3610(a + 0x30, a + 0x70);
        }
        D_L05_001DAF30 = 0;
        {
            u8 *b;
            ids = ((V_3B00A8 *)v)->ids;
            b = D_L05_001DFB9C + (ids[2] << 8);
            U16(b, 0x34) &= ~0x41;
            U16(b, 0x34) |= U16(PTR(b, 0x24), 0x44) & 0x1000;
            S32(b, 0x98) = S32(PTR(b, 0x24), 0x10);
        }
        func_L01_004AAC98(5, 0, m, 0x1A13);
        func_003C2880(m);
        break;
    }
}
/* localdecomp:end func_L05_003B00A8 */
