#include "common.h"

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0xB2 - 0x36];
    s16 fB2;
    u8 padB4[0x100 - 0xB4];
} Type_004A3A90;

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x4B90 - 0x4958];
    u8 f4B90[1];
    u8 pad2[0x6D28 - 0x4B91];
    u8 fX[1];
} S_func_0049A930;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 pad[3];
} Ent_0049AB20;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad[3];
} S_2EC7A8;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    s32 v[12][3];
} S_236B80;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_49E5B8;
typedef struct {
    s32 offset;
    s32 data;
    u16 size;
    s16 kind;
    s16 arg1;
    s16 arg0;
} Entry_4A0270;
typedef struct {
    s32 count;
    Entry_4A0270 entries[1];
} Table_4A0270;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 fC;
    u8 pad[11];
} S_2EC760_0049E648;

/* localdecomp:start func_L01_004A28C8 */
typedef struct {
    u8 pad0[0xE];
    s16 fE;
} Row_004A28C8;
extern s32 D_L01_001D96C0;
__asm__(".extern D_L01_001D96C0, 4");
extern s32 D_L01_001D96C4;
__asm__(".extern D_L01_001D96C4, 4");
extern s32 D_L01_001D96C8;
__asm__(".extern D_L01_001D96C8, 4");
extern char D_L01_001D96D8[4];
__asm__(".extern D_L01_001D96D8, 4");
extern char D_L01_001D9710[8];
__asm__(".extern D_L01_001D9710, 8");
extern s32 D_L01_001E0D28;
__asm__(".extern D_L01_001E0D28, 4");
extern f32 D_L01_001E0D24;
__asm__(".extern D_L01_001E0D24, 4");
extern f32 D_L01_001DC0E8;
extern u16 D_001A8EC8[];
extern Row_004A28C8 *const D_L01_001DFCC0;
extern void func_0038E150(s32);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern s32 func_00381F80(s32);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00516FD8(s32, s32);

void func_L01_004A28C8(void) {
    s32 t;
    s32 d0;
    s32 d1;
    s32 d2;

    func_0038E150(1);
    if (D_L01_001D96C0 != 0) {
        t = D_L01_001D96C0 - func_003B9C58(func_003B9BD0(0));
        D_L01_001D96C4 = t - 1;
        d0 = t % 10;
        d1 = t / 10 % 10;
        d2 = t / 100 % 10;
        if (d2 != 0) {
            D_L01_001D96D8[0] = d2 + '0';
            D_L01_001D96D8[1] = d1 + '0';
            D_L01_001D96D8[2] = d0 + '0';
            D_L01_001D96D8[3] = 0;
        } else if (d1 != 0) {
            D_L01_001D96D8[2] = 0;
            D_L01_001D96D8[0] = d1 + '0';
            D_L01_001D96D8[1] = d0 + '0';
        } else {
            D_L01_001D96D8[1] = 0;
            D_L01_001D96D8[0] = d0 + '0';
        }
        if (D_L01_001D96C4 >= 0) {
            if (D_L01_001D96C8 != D_L01_001D96C4) {
                if (D_L01_001E0D28 == 0) {
                    D_L01_001E0D28 = 1;
                    D_L01_001E0D24 = 65.0f / D_L01_001DC0E8;
                }
                if ((*(Row_004A28C8 **)&D_L01_001DFCC0)[func_00381F80(D_001A8EC8[D_L01_001D96C4])].fE == 0x1DC
                    || (*(Row_004A28C8 **)&D_L01_001DFCC0)[func_00381F80(D_001A8EC8[D_L01_001D96C4])].fE == 0xB0E
                    || (*(Row_004A28C8 **)&D_L01_001DFCC0)[func_00381F80(D_001A8EC8[D_L01_001D96C4])].fE == 0x150E
                    || (*(Row_004A28C8 **)&D_L01_001DFCC0)[func_00381F80(D_001A8EC8[D_L01_001D96C4])].fE == 0x166A
                    || (*(Row_004A28C8 **)&D_L01_001DFCC0)[func_00381F80(D_001A8EC8[D_L01_001D96C4])].fE == 0x1736) {
                    func_L01_00516470(0x580003, D_L01_001E0D24 * 0.5f + 0.500369f, 0.337772f);
                    func_L01_00517538(0x580003, 0.775758f - D_L01_001E0D24, 0.356964f);
                } else {
                    func_L01_00516470(0x580003, 0.500369f, 0.337772f);
                    func_L01_00517538(0x580003, 0.775758f, 0.356964f);
                }
                func_L01_00516FD8(0x580003, func_00381FF0(D_001A8EC8[D_L01_001D96C4]));
            }
            D_L01_001D96C8 = D_L01_001D96C4;
        }
    } else {
        D_L01_001D96D8[0] = 0;
        func_L01_00516FD8(0x580003, (s32)D_L01_001D9710);
    }
}
/* localdecomp:end func_L01_004A28C8 */

/* localdecomp:start func_L01_004A2BE0 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_L01_004A2BE0;
extern s32 D_L01_001D96EC;
__asm__(".extern D_L01_001D96EC, 4");
extern f32 D_L01_001D9714;
__asm__(".extern D_L01_001D9714, 4");
extern f32 D_L01_001D9718;
__asm__(".extern D_L01_001D9718, 4");
extern char D_L01_001D9720[];
extern s32 D_001D55E8;
__asm__(".extern D_001D55E8, 16");
extern void *func_0011A264(void *, s32, s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 func_003B9C68();
extern void func_003BABB0(void *, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern void func_L01_00498F18(void *, s32, s32);
extern s32 func_003B9E30(void *, s32, s32);
extern void func_L01_004A32E0(s32, u8 *, f32, f32);

void func_L01_004A2BE0(void) {
    u8 buf[0x40];
    S_L01_004A2BE0 s;
    s32 i;
    s32 n;
    s32 saved;
    func_0011A264(buf, 0, 0x40);
    D_L01_001D96C0 = 0;
    for (i = 0; i < 0x190; i++) {
        if (D_001A8EC8[i] != 0) {
            D_L01_001D96C0++;
        }
    }
    n = D_L01_001D96C0;
    if (n == 0) {
        return;
    }
    s.f0 = 0x4F000;
    s.f4 = D_L01_001D96EC;
    s.f8 = 0x14;
    s.fC = n;
    s.f10 = n < 7 ? n : 6;
    s.f14 = 1;
    s.f18 = 1.0f;
    s.f1C = D_L01_001D9714;
    s.f20 = D_L01_001D9718;
    s.a24[0] = 0.5f;
    s.a24[1] = 1.0f;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = 0.79520601f;
    s.a34[1] = 0.0f;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_003B9C68(func_003B9BD0(0), &s);
    func_003BABB0(func_003B9BD0(0), 0.5f, 0.816536009f, 0.0450000018f, 0.0425000004f, 0.349999994f, 0);
    func_003BABD0(func_003B9BD0(0), 0.500369012f, 0.700703025f, 0.816536009f, 0.312705994f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.0264999997f, 0.00665999996f, 0.0299999993f);
    func_L01_00498F18(func_003B9BD0(0), 0, 1);
    saved = D_001D55E8;
    func_0038E150(1);
    for (i = 0; i < D_L01_001D96C0; i++) {
        func_L01_004A32E0(D_001A8EC8[i], buf, s.f18, s.a34[0] - 0.00999999978f);
        func_0011B2E8((char *)func_003B9E30(func_003B9BD0(0), 0, D_L01_001D96C0 - i - 1), D_L01_001D9720, (char *)buf);
    }
    func_0038E150(saved);
}
/* localdecomp:end func_L01_004A2BE0 */

/* localdecomp:start func_L01_004A2E88 */
typedef struct { s32 a, b; } Row2_004A2E88;
typedef struct { u8 p0[0x6188]; s32 a, b; } RowB_004A2E88;
typedef struct { u8 p0[0x4954]; s32 f4954; u8 p1[0x6188 - 0x4958]; Row2_004A2E88 f6188[1]; } Big_004A2E88;
typedef struct { u8 p0[0x2C]; s32 f2C; } Tab_004A2E88;
extern s32 D_L01_001D96F0;
__asm__(".extern D_L01_001D96F0, 4");
extern u32 *D_L01_001D96E8;
__asm__(".extern D_L01_001D96E8, 4");
extern Row_004A28C8 *D_L01_001D96CC;
__asm__(".extern D_L01_001D96CC, 4");
extern s32 D_L01_001D96D0;
__asm__(".extern D_L01_001D96D0, 4");
extern s16 D_001CCFD4[];
extern u8 D_00143A07[];
extern Big_004A2E88 D_00160C40;
extern Tab_004A2E88 D_L01_002E5F30;
extern s32 func_003A26F0(u32 *, s32, s32);
extern void func_L01_004A2FC0(void);


s32 func_L01_004A2E88(void) {
    u32 *a;
    u32 *p;
    s32 i;
    s32 n;
    s32 next;
    switch (D_L01_001D96F0) {
    case 0:
        if (D_001CCFD4[0] != 0) {
            return 1;
        }
        {
            next = func_003A26F0(D_L01_001D96E8, D_00160C40.f6188[D_00143A07[0]].a + D_00160C40.f4954, D_00160C40.f6188[D_00143A07[0]].b);
            if (next != 0) {
                next = 1;
            } else {
                next = 4;
            }
        }
        goto set;
    case 1:
        if (D_001CCFD4[0] != 0) {
            return 1;
        }
        a = D_L01_001D96E8;
        n = *a >> 4;
        D_L01_001D96CC = D_L01_001DFCC0;
        D_L01_001D96D0 = D_L01_002E5F30.f2C;
        *(Row_004A28C8 **)&D_L01_001DFCC0 = (Row_004A28C8 *)a;
        D_L01_002E5F30.f2C = n;
        p = a;
        for (i = 0; i < D_L01_002E5F30.f2C; i++) {
            p[i * 4] += (u32)D_L01_001DFCC0;
        }
        next = 2;
    set:
        D_L01_001D96F0 = next;
        return 1;
    case 2:
        func_L01_004A2FC0();
        D_L01_001D96F0 = 3;
        return 0;
    case 3:
    case 4:
        return 0;
    }
    return 0;
}
/* localdecomp:end func_L01_004A2E88 */

INCLUDE_ASM("asm/levels", func_L01_004A2FC0);
