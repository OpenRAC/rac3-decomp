#include "common.h"

typedef struct { f32 f0; s16 h4; } P_003BB1F0;

typedef struct S_003BB7A8 {
    u8 pad[0xA4];
    u16 flags;
} S_003BB7A8;

/* declared by functions of L07_003BB360.c, which this file was cut from */
extern s32 func_L07_003A2380_003BB840(s32, s32, s32, s32) __asm__("func_L07_003A2380");

/* localdecomp:start func_L07_003BBBA8 */
#include "vu0.h"

typedef int u128_t_003BBBA8 __attribute__((mode(TI)));

extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern u8 *D_L07_001ECC80[];
extern u8 *D_L07_0021D2C0[];
extern u8 D_L07_001D66B0[8];

extern void func_L07_003BC4D8(void *);
extern void func_L07_003BC6C0(void *);
extern s32 func_L07_003BD078(void *);
extern void func_L07_003BCBE8(void *);
extern void func_L07_003BCDD0(void *);
extern void func_L07_003BCE50(void *);
extern void func_L07_003BCE68(void *);
extern void func_L07_003BCC88(void *);
extern void func_L07_003BCB10(void *, s32);
extern void func_L07_003BD118(void *);
extern void func_L07_003BCC30(void *);
extern void func_L07_003BCD80(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00409598(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L03_004497E8(void *, s32, s32, s32);
extern void func_L03_004495A8(void *, s32);
extern s32 func_L06_004591F8(void *, void *, u8);
extern s32 func_L01_0045BDE8(void *, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_0045A748(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_004443E8(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);

void func_L07_003BBBA8(u8 *m) {
    u8 *v;
    vu0_v4 tmp;
    vu0_v4 b;

    if (m[0x20] == 0) {
        func_L07_003BC4D8(m);
    }
    func_L07_003BC6C0(m);
    v = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 1:
        break;
    case 2:
        if (func_L01_004561B8(m)) {
            *(s16 *)(v + 0x29E) = (*(s16 *)(v + 0x29C) * 5 + 2) / 6;
        }
        if (func_L07_003BD078(m)) {
            if (func_0038CB00(v + 0x29E)) {
                func_L01_004450F0(m, 3, -1);
            }
        }
        break;
    case 3: {
        u8 *e;
        s32 n;
        s32 i;
        s32 ok;
        e = D_L07_001DF41C + (*(s32 *)(v + 0x298) << 8);
        func_0038CF68(&tmp, e + 0xE0, 0.8f);
        vec_add_ab(&tmp, e + 0x10, &tmp);
        n = func_003D4D00(&tmp, 1, 0.8f, m, 0);
        ok = 1;
        for (i = 0; i < n; i++) {
            s16 c = *(s16 *)(D_L07_001ECC80[i] + 0xAA);
            if (c == 0x1A85 || c == 0x19D2 || c == 0x1D88) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            qzero(&b);
            b.z = func_0038D160(*(f32 *)(v + 0x220) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x224) - *(f32 *)(m + 0x14));
            func_L01_00409598(m, &tmp, &b, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
            func_L07_003BCBE8(m);
        }
        break;
    }
    case 4:
        func_L07_003BCDD0(m);
        if (func_L07_003BD078(m)) {
            func_L07_003BCC88(m);
        }
        break;
    case 5:
        if (func_L01_004561B8(m)) {
            u8 *q = v + 0x30;
            *(f32 *)(q + 0x20) = *(f32 *)(v + 0x2A0) * 0.00040000002f;
            *(f32 *)(q + 0x24) = *(f32 *)(v + 0x2A0) * 0.00040000002f;
            *(f32 *)(q + 0x28) = *(f32 *)(v + 0x2A0) * 0.020000001f;
            func_L03_004497E8(m, *(s32 *)(v + 0x290), 1, -1);
        }
        func_L07_003BCE50(m);
        func_L03_004495A8(m, *(s32 *)(v + 0x290));
        func_L07_003BCE68(m);
        if (func_L07_003BD078(m)) {
            func_L07_003BCC88(m);
        }
        break;
    case 6:
        if (func_L01_004561B8(m)) {
            u8 *q = v + 0x30;
            u8 *t;
            *(f32 *)(q + 0x20) = *(f32 *)(v + 0x2A4) * 0.00040000002f;
            *(f32 *)(q + 0x24) = *(f32 *)(v + 0x2A4) * 0.00040000002f;
            *(f32 *)(q + 0x28) = *(f32 *)(v + 0x2A4) * 0.020000001f;
            t = D_L07_0021D2C0[*(s32 *)(v + 0x294)];
            *(u8 **)(q + 0xC4) = t;
            *(u128_t_003BBBA8 *)&tmp = *(u128_t_003BBBA8 *)(m + 0x10);
            *(s16 *)(q + 0xC8) = func_L06_004591F8(&tmp, t, 1);
            *(s16 *)(q + 0xCA) = 0;
        }
        if (func_L07_003BD078(m)) {
            func_L07_003BCC88(m);
            break;
        }
        func_L07_003BCE50(m);
        {
        s32 r = (u8)func_L01_0045BDE8(m, *(s32 *)(v + 0x294));
        func_L07_003BCE68(m);
        if (r) {
            func_L07_003BCBE8(m);
        }
        }
        break;
    case 8:
        if (func_L01_004561B8(m)) {
            *(s16 *)(v + 0x29E) = (func_003824E0(0.0f, 0.5f) + 1.0f) * 100.0f;
        }
        func_L07_003BCDD0(m);
        if (func_L07_003BD078(m)) {
            func_L07_003BCB10(m, 8);
        } else if (func_0038CB00(v + 0x29E)) {
            func_L07_003BCC30(m);
        }
        break;
    case 9:
        if (func_L01_004561B8(m)) {
            u8 *q = v + 0x30;
            u8 *t;
            *(f32 *)(q + 0x20) = *(f32 *)(v + 0x2A4) * 0.00040000002f;
            *(f32 *)(q + 0x24) = *(f32 *)(v + 0x2A4) * 0.00040000002f;
            *(f32 *)(q + 0x28) = *(f32 *)(v + 0x2A4) * 0.020000001f;
            t = D_L07_0021D2C0[*(s32 *)(v + 0x294)];
            *(u8 **)(q + 0xC4) = t;
            *(u128_t_003BBBA8 *)&tmp = *(u128_t_003BBBA8 *)(m + 0x10);
            *(s16 *)(q + 0xC8) = func_L06_004591F8(&tmp, t, 1);
            *(s16 *)(q + 0xCA) = *(u16 *)t - 1;
        }
        if (!func_L07_003BD078(m)) {
            func_L07_003BCB10(m, 8);
            break;
        }
        func_L07_003BCE50(m);
        {
        s32 r = (u8)func_L01_0045BDE8(m, *(s32 *)(v + 0x294));
        func_L07_003BCE68(m);
        if (r) {
            func_L07_003BCB10(m, 0xA);
        }
        }
        break;
    case 10:
        if (func_L01_004561B8(m)) {
            u8 *q = v + 0x30;
            *(f32 *)(q + 0x20) = 0.024f;
            *(f32 *)(q + 0x28) = 0.6f;
            *(f32 *)(q + 0x24) = 0.024f;
        }
        vec_sub_ba(&tmp, m + 0x10, v + 0x220);
        tmp.z = 0.0f;
        func_0038CF68(&tmp, &tmp, 3.0f);
        vec_add_ba(&tmp, v + 0x220, &tmp);
        func_L07_003BCE50(m);
        {
        s32 r = func_L01_0045A748(m, &tmp);
        func_L07_003BCE68(m);
        if (r & 0x80) {
            func_L07_003BCB10(m, 0xB);
        }
        }
        break;
    case 11:
        *(f32 *)(m + 0xF0) *= 0.97f;
        *(f32 *)(m + 0xF4) *= 0.97f;
        if (m[0x60] & 2) {
            func_L07_003BCB10(m, 0xC);
        }
        break;
    case 12:
        if (func_L01_004561B8(m)) {
            *(f32 *)(m + 0x48) = 0.0f;
        }
        *(f32 *)(m + 0x48) += 0.024f;
        *(f32 *)(m + 0xF0) *= 0.97f;
        *(f32 *)(m + 0xF4) *= 0.97f;
        if (*(f32 *)(m + 0x48) >= 1.0f) {
            *(f32 *)(m + 0x48) = 1.0f;
            func_L07_003BCB10(m, 0xD);
        }
        break;
    case 13:
        if (func_L01_004561B8(m)) {
            u8 *q = v + 0x30;
            *(f32 *)(q + 0x20) = 0.0016000001f;
            *(f32 *)(q + 0x28) = 0.060000002f;
            *(f32 *)(q + 0x24) = 0.0016000001f;
        }
        *(f32 *)(m + 0xF0) *= 0.97f;
        *(f32 *)(m + 0xF4) *= 0.97f;
        func_L01_0045A748(m, v + 0x220);
        func_L07_003BD118(m);
        if (!func_L07_003BD078(m)) {
            func_L07_003BCC30(m);
        } else if (func_L01_0040E570(m + 0x10, v + 0x220) > 144.0f) {
            func_L07_003BCB10(m, 0xA);
        }
        break;
    case 14: {
        u8 *pos;
        vu0_v4 *p;
        if (func_L01_004561B8(m)) {
            *(s16 *)(v + 0x29E) = 0x19;
        }
        pos = m + 0x10;
        *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 0.50265485f);
        p = &tmp;
        vec_add_ba(m + 0x10, m + 0x10, v + 0xD0);
        *(u128_t_003BBBA8 *)p = *(u128_t_003BBBA8 *)(m + 0x10);
        tmp.z += 0.8f;
        if (func_0038CB00(v + 0x29E) || func_L01_003FB640(p, 0, m, 0.9f)) {
            func_L01_003303B8(pos, 0, 5, 10, 10, 3, 0x14, 0, 0.3f, 0.0f, v[0x135], 1.0f,
                              0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                              0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_00451FE0(m, 0x1F, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                              -1.0f, -1.0f, 1.0f, 1.0f);
            func_L01_004443E8(m, 0, 3);
            func_L07_003BCD80(m);
            func_003A52A0(2, 0, m);
        }
        break;
    }
    }
}
/* localdecomp:end func_L07_003BBBA8 */
