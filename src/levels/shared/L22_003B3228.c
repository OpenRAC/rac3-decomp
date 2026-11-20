#include "common.h"

INCLUDE_ASM("asm/levels", func_L22_003B3228);

/* localdecomp:start func_L22_003B5EF8 */
#include "vu0.h"

typedef int Q_003B5EF8 __attribute__((mode(TI)));
typedef union {
    Q_003B5EF8 q;
    f32 f[4];
} V_003B5EF8;
typedef struct { u8 pad[0x464]; u8 spent[1]; } S_003B5EF8;
typedef struct { V_003B5EF8 r[4]; } M_003B5EF8;
typedef struct { u8 pad[0x4A0]; s32 n4A0; } P_003B5EF8;

extern s32 func_L22_003B6698(u8 *);
extern void func_L03_0043BE98(void *, void *, s32, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L22_003B72F0(u8 *, V_003B5EF8 *, s32, f32);
extern void func_L01_0044FD88(void *, void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D570(void *, void *);
extern void func_0038D328(void *, void *);
extern void func_0038D640(void *, void *, void *);
extern void func_0038D590(void *, void *);
extern s32 func_L01_00452F78(void *, s32, s32, s32);
extern void func_L22_003B6C58_003B5EF8(u8 *);
extern void func_L02_003A5010(s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

extern S_003B5EF8 D_L22_00236640_003B5EF8;
extern u8 D_001BBE90[];
typedef struct { u8 pad[0x80]; f32 x; f32 y; } H_003B5EF8;
extern H_003B5EF8 D_001A4BE0;
extern s32 D_001D545C;
extern s32 D_L22_001DF8C0;
extern u8 *D_L22_001DFD9C;
extern s32 D_L22_001E9858[];
extern V_003B5EF8 D_L22_001DE460 __attribute__((section(".sdata")));
__asm__(".extern D_L22_001DE460, 4");
extern V_003B5EF8 D_L22_001DE470 __attribute__((section(".sdata")));
__asm__(".extern D_L22_001DE470, 4");

s32 func_L22_003B5EF8(u8 *m) {
    u8 *p;
    u8 *q;
    u16 id;
    u16 id3;
    u16 id4;
    s32 b;
    s32 was;

    p = *(u8 **)(m + 0x68);
    if (m[0x20] == 0 && func_L22_003B6698(m)) {
        return 1;
    }
    func_L03_0043BE98(m, p + 0x240, 0, 4, m[0x20] != 6);
    id = *(u16 *)(m + 0xB2);
    if (!D_L22_00236640_003B5EF8.spent[(s16)id]) {
        b = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
        if (!(((id & 1) ? b >> 4 : b) & 7) && D_001D545C != 22) {
            func_L01_00452860(m, p + 0x30, 0);
        }
    }
    if (((P_003B5EF8 *)p)->n4A0 > 0 && *(s32 *)(p + 0x464) != -1 && m[0x95] == 1
        && (D_L22_001DF8C0 & 0x1F) == (((s32)m >> 8) & 0x1F)) {
        q = D_L22_001DFD9C + (*(s32 *)(p + 0x464) << 8);
        if (func_L01_0040E570(m + 0x10, q + 0x10) > 0.1f) {
            V_003B5EF8 v;
            v = *(V_003B5EF8 *)(q + 0x10);
            func_L22_003B72F0(m, &v, 1, func_0038D160(D_001A4BE0.x - *(f32 *)(q + 0x10),
                                                      D_001A4BE0.y - *(f32 *)(q + 0x14)));
        }
        if (*(s32 *)(p + 0x530)) {
            u16 k = *(u16 *)(m + 0xB2);
            if (k & 1) {
                u8 *c = &D_001BBE90[((s16)k >> 1) + (D_001D545C << 10)];
                if (((*c >> 4) & 7) != 7) {
                    *c += 0x10;
                }
            } else {
                u8 *c = &D_001BBE90[((s16)k >> 1) + (D_001D545C << 10)];
                if ((*c & 7) != 7) {
                    *c += 1;
                }
            }
        }
    }
    if (*(s32 *)(p + 0x530)) {
        id = *(u16 *)(m + 0xB2);
        if (D_L22_00236640_003B5EF8.spent[(s16)id]
            || (b = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)], ((id & 1) ? b >> 4 : b) & 7)) {
            if (m[0x95] == 1) {
                ((P_003B5EF8 *)p)->n4A0++;
                q = D_L22_001DFD9C + (*(s32 *)(p + 0x464) << 8);
                if (func_L01_0040E570(m + 0x10, q + 0x10) > 0.1f) {
                    V_003B5EF8 v;
                    v = *(V_003B5EF8 *)(q + 0x10);
                    func_L22_003B72F0(m, &v, 1, func_0038D160(D_001A4BE0.x - *(f32 *)(q + 0x10),
                                                              D_001A4BE0.y - *(f32 *)(q + 0x14)));
                }
            }
        }
    }
    if (*(u8 **)(p + 0x48C)) {
        func_L01_0044FD88(m, *(u8 **)(p + 0x48C), 3, 0);
        {
            V_003B5EF8 v;
            M_003B5EF8 m2;
            M_003B5EF8 m3;

            func_0038CE20(&v, *(u8 **)(p + 0x48C) + 0xC0, D_L22_001DE460.f[0]);
            vec_add_ba(*(u8 **)(p + 0x48C) + 0x10, *(u8 **)(p + 0x48C) + 0x10, &v);
            func_0038CE20(&v, *(u8 **)(p + 0x48C) + 0xD0, D_L22_001DE460.f[1]);
            vec_add_ba(*(u8 **)(p + 0x48C) + 0x10, *(u8 **)(p + 0x48C) + 0x10, &v);
            func_0038CE20(&v, *(u8 **)(p + 0x48C) + 0xE0, D_L22_001DE460.f[2]);
            vec_add_ba(*(u8 **)(p + 0x48C) + 0x10, *(u8 **)(p + 0x48C) + 0x10, &v);
            func_0038D570(&m2, *(u8 **)(p + 0x48C) + 0xC0);
            func_0038D328(&m3, &D_L22_001DE470);
            func_0038D640(&m2, &m2, &m3);
            func_0038D590(*(u8 **)(p + 0x48C) + 0xC0, &m2);
        }
    }
    if (D_001D545C != 22 || (*(s32 *)(p + 0x53C)
        && (D_L22_00236640_003B5EF8.spent[(s16)(id3 = *(u16 *)(m + 0xB2))]
            || (b = D_001BBE90[((s16)id3 >> 1) + (D_001D545C << 10)], ((id3 & 1) ? b >> 4 : b) & 7)))) {
        if (func_L01_00452F78(m, 0, 0, 0)) {
            func_L22_003B6C58_003B5EF8(m);
        }
    }
    if (D_001D545C == 22) {
        id4 = *(u16 *)(m + 0xB2);
        if (!D_L22_00236640_003B5EF8.spent[(s16)id4]) {
            b = D_001BBE90[((s16)id4 >> 1) + (D_001D545C << 10)];
            if (!(((id4 & 1) ? b >> 4 : b) & 7)) {
                m[0xA8] = 0xFF;
            }
        }
    }
    if (p[0x3E] == 2 || p[0x5E] || p[0x60]) {
        func_L02_003A5010((s32)m);
        return 1;
    }
    if (p[0x5F]) {
        func_L01_00456BD0(m, 5);
    } else if (*(f32 *)(p + 0x30) > 0.0f) {
        func_L01_00456BD0(m, 3);
    }
    if ((*(s16 *)(m + 0xB2) + 8) % 8 != D_L22_001DF8C0 % 8) {
        return 0;
    }
    was = *(s16 *)(p + 0x234) == 1;
    if (p[0x5F]) {
        if (m[0x95] == 1) {
            func_L01_00456C98(m, *(s32 *)(p + 0x430), (s32)(p + 0x4F0), 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x434), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(m, *(s32 *)(p + 0x438), (s32)(p + 0x4F0), 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x43C), 10.0f, 1.0f);
        }
    } else {
        if (m[0x95] == 1) {
            func_L01_00456C98(m, *(s32 *)(p + 0x430), (s32)(p + 0x4F0), 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x434), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(m, *(s32 *)(p + 0x438), (s32)(p + 0x4F0), 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x43C), 10.0f, 1.0f);
        }
    }
    if (*(s16 *)(p + 0x234) == 1 && !was) {
        V_003B5EF8 a;
        V_003B5EF8 to;

        a = *(V_003B5EF8 *)(m + 0x10);
        a.f[2] += 1.0f;
        to = *(V_003B5EF8 *)(p + 0x220);
        to.f[2] += 1.0f;
        if (func_003D3CB0(&a, &to, 0, m, 0) && D_L22_001E9858[0] != *(s32 *)(p + 0x230)) {
            *(s16 *)(p + 0x234) = 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L22_003B5EF8 */
