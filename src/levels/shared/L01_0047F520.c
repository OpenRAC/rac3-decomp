#include "common.h"

/* declared by functions of L01_0047F220.c, which this file was cut from */
extern s32 func_00381FF0(s32);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);

/* localdecomp:start func_L01_0047F520 */
typedef struct {
    s32 text;
    s32 name;
    u8 enabled;
    u8 pad9[3];
    void (*cb)(void);
    u8 b10;
    u8 pad11[3];
} Entry_0047F520;

__asm__(".extern D_L01_001D82C8, 8");
__asm__(".extern D_L01_001D82D0, 8");
__asm__(".extern D_L01_001D82D8, 8");
__asm__(".extern D_L01_001D82E0, 4");
__asm__(".extern D_L01_001D82E4, 4");
__asm__(".extern D_L01_001D82E8, 4");
__asm__(".extern D_L01_001D82EC, 4");
__asm__(".extern D_L01_001D82F0, 4");
__asm__(".extern D_L01_001D82F4, 4");
__asm__(".extern D_L01_001D82F8, 4");
__asm__(".extern D_L01_001D82FC, 4");
extern s32 D_001D545C;
extern s32 D_L01_001D7BE0;
extern u8 D_00143950[];
extern Entry_0047F520 D_L01_002EA020[];
extern Entry_0047F520 D_L01_002EA0C0[];
extern Entry_0047F520 D_L01_002EA178[];
extern f32 D_L01_001D82C8[2];
extern f32 D_L01_001D82D0[2];
extern f32 D_L01_001D82D8[2];
extern Entry_0047F520 *D_L01_001D82E0;
extern f32 *D_L01_001D82E4;
extern s32 D_L01_001D82E8;
extern s32 D_L01_001D82EC;
extern s32 D_L01_001D82F0;
extern f32 D_L01_001D82F4;
extern f32 D_L01_001D82F8;
extern f32 D_L01_001D82FC;
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003B5060(s32);
extern s32 func_003E8AE8(s32, s32, s32, s32, s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);

void func_L01_0047F520(void) {
    s32 lvl;
    s32 m;
    s32 i;
    s32 j;
    s32 id;
    u8 setting;
    f32 scale;
    f32 y;

    lvl = D_001D545C;
    if ((lvl == 12 || lvl == 18 || lvl == 20 || lvl == 26 || lvl == 29 || lvl == 4) && D_L01_001D7BE0 != -1) {
        D_L01_001D82E0 = D_L01_002EA0C0;
        D_L01_001D82E4 = D_L01_001D82D0;
        D_L01_001D82EC = 9;
        m = 1;
    } else if ((lvl == 7 || lvl == 3) && D_L01_001D7BE0 != -1) {
        D_L01_001D82E0 = D_L01_002EA178;
        D_L01_001D82E4 = D_L01_001D82D8;
        D_L01_001D82EC = 9;
        m = 1;
    } else {
        D_L01_001D82E0 = D_L01_002EA020;
        D_L01_001D82E4 = D_L01_001D82C8;
        D_L01_001D82EC = 8;
        m = 0;
    }
    if (D_L01_001D82F0 != m) {
        D_L01_001D82E8 += m - D_L01_001D82F0;
        D_L01_001D82F0 = m;
    }
    if (D_L01_001D82E8 > D_L01_001D82EC) {
        D_L01_001D82E8 = D_L01_001D82EC;
    }
    if (D_L01_001D82E8 < 0) {
        D_L01_001D82E8 = 0;
    }
    scale = (f32)D_L01_001D82EC * 0.09f + -0.18f;
    if (scale < 0.0f) {
        scale = 0.0f;
    }
    scale += 1.0f;
    func_003E8EF0(0xD0000, 0x3D, 0x332299DE, 0.5f, 0.5f, 1.0f, 1.0f, scale);
    func_003E8EF0(0xD0001, 0x3E, 0x332299DE, 0.5f, 0.5f, 1.0f, 1.0f, scale);
    func_003E8EF0(0xD0002, 0x3F, 0x331465B7, 0.5f, 0.5f, 1.0f, 1.0f, scale);
    func_003E8EF0(0xD0003, 0x40, 0x802299DE, 0.5f, 0.5f, 1.0f, 1.0f, scale);
    func_003E9138(0xD0028, 0x402299DE, 0.5f, 0.5f, 0.333333f, 0.025f, 0);
    func_003B5060(0xD000B);
    func_003E8AE8(0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0028);
    func_003E8348(0x10, 0xD000B);
    func_003B5060(0xD0025);
    func_003B5060(0xD0026);
    for (i = 0; i < D_L01_001D82EC; i++) {
        func_003E8FE8(D_L01_001D82E0[i].text, func_00381FF0(D_L01_001D82E0[i].name), 0x8066CCFF, 0.0f, 0.0f, 1.0f, 1.0f);
        func_L01_00516AA0(D_L01_001D82E0[i].text, 0x40, 1);
        func_003E8630(0xD0025, D_L01_001D82E0[i].text);
        if (i < D_L01_001D82EC - 1) {
            id = i + 0xD0019;
            func_003E9138(id, 0x202299DE, 0.0f, 0.0f, 1.0f, 1.0f, 0);
            func_003E8630(0xD0026, id);
        }
        setting = D_00143950[0xB7];
        if (setting >= 2) {
            func_L01_00517538(D_L01_001D82E0[i].text, 0.7f, 0.8f);
        }
    }
    func_003E8630(0xD0025, 0xD0026);
    func_003E8348(0x11, 0xD0025);
    y = 0.5f - (f32)(D_L01_001D82EC - 1) * 0.03f;
    for (j = 0; j < D_L01_001D82EC; j++) {
        func_L01_00516470(D_L01_001D82E0[j].text, 0.5f, y);
        if (j < D_L01_001D82EC - 1) {
            id = j + 0xD0019;
            func_L01_00516470(id, 0.5f, y + D_L01_001D82F4 * 0.5f);
            func_L01_00517538(id, 0.43f, 0.0048f);
        }
        y += D_L01_001D82F4;
    }
    func_003E9138(0x5A0001, 0x332299DE, D_L01_001D82F8, D_L01_001D82E4[0], -0.07f, 0.08615385f, 0xED5A);
    func_003E9138(0x5A0002, 0x332299DE, D_L01_001D82FC, D_L01_001D82E4[1], 0.07f, -0.08615385f, 0xED5A);
    func_003E8A08(0xD000B, 0x5A0001, 0x5A0002);
}
/* localdecomp:end func_L01_0047F520 */

/* localdecomp:start func_L01_0047FAC8 */
typedef struct { u8 pad0[0x1C4]; s32 w1C4; } S_0047FAC8;
typedef struct {
    s32 w0;
    s32 w4;
    u8 b8;
    u8 pad9[3];
    void (*fnC)(void);
    u8 b10;
    u8 pad11[3];
} E_0047FAC8;
extern S_0047FAC8 *D_001D52FC;
extern u8 D_L01_001D672C[] __attribute__((section(".sdata")));
extern E_0047FAC8 *D_L01_001D82E0_0047FAC8;
extern s32 D_L01_001D82E8;
extern s32 D_L01_001D82EC;
extern f32 D_L01_001D8300;
extern f32 D_L01_001D8304;
extern f32 D_L01_001D8308;
extern f32 D_L01_001D830C;
__asm__(".extern D_L01_001D82E0_0047FAC8, 4");
__asm__(".extern D_L01_001D82E8, 4");
__asm__(".extern D_L01_001D82EC, 4");
__asm__(".extern D_L01_001D8300, 4");
__asm__(".extern D_L01_001D8304, 4");
__asm__(".extern D_L01_001D8308, 4");
__asm__(".extern D_L01_001D830C, 4");
extern void func_L01_0047EC88(void);
extern void func_L01_0047ECC0(void);
extern s32 func_L01_0047F220(void);
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090_0047FAC8(s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_005170B8(s32, u32);
extern void func_003BB5D0(void);
extern void func_003BB590(s32);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);

void func_L01_0047FAC8(s32 a0) {
    s32 found;
    s32 i;
    s32 off;
    s32 flags;
    f32 f;

    func_L01_0047EC88();
    func_L01_0047ECC0();
    if (func_L01_0047F220() != 0) {
        return;
    }
    flags = D_001D52FC->w1C4;
    if (flags & 0x4000) {
        found = 0;
        do {
            D_L01_001D82E8++;
            if (D_L01_001D82E8 >= D_L01_001D82EC) {
                D_L01_001D82E8 = 0;
            }
            if (D_L01_001D82E0_0047FAC8[D_L01_001D82E8].b8 != 0) {
                found = 1;
            }
        } while (found == 0);
        func_003A5348(3, 0, 0);
    } else if (flags & 0x1000) {
        found = 0;
        do {
            D_L01_001D82E8--;
            if (D_L01_001D82E8 < 0) {
                D_L01_001D82E8 = D_L01_001D82EC - 1;
            }
            if (D_L01_001D82E0_0047FAC8[D_L01_001D82E8].b8 != 0) {
                found = 1;
            }
        } while (found == 0);
        func_003A5348(3, 0, 0);
    } else if (flags & 0x40) {
        if (D_L01_001D82E0_0047FAC8[D_L01_001D82E8].b8 != 0 && D_L01_001D82E0_0047FAC8[D_L01_001D82E8].fnC != 0) {
            D_L01_001D82E0_0047FAC8[D_L01_001D82E8].fnC();
            if (D_L01_001D82E0_0047FAC8[D_L01_001D82E8].b10 != 0) {
                func_L01_00516090_0047FAC8(a0);
            }
            func_003A5348(4, 0, 0);
        }
    } else if (flags & 0x910) {
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090_0047FAC8(a0);
    }
    f = 0.5f - (f32)(D_L01_001D82EC - 1) * 0.03f;
    func_L01_00517538(0xD0028, D_L01_001D8304, D_L01_001D8300);
    func_L01_00516470(0xD0028, D_L01_001D830C, f + (f32)D_L01_001D82E8 * D_L01_001D8308);
    for (i = 0; i < D_L01_001D82EC; i++) {
        if (D_L01_001D82E0_0047FAC8[i].b8 != 0) {
            func_L01_005170B8(D_L01_001D82E0_0047FAC8[i].w0, 0x8066CCFF);
            if (i == D_L01_001D82E8) {
                func_L01_005170B8(D_L01_001D82E0_0047FAC8[i].w0, 0x66D6EEFA);
            }
        } else {
            func_L01_005170B8(D_L01_001D82E0_0047FAC8[i].w0, 0x80808080);
        }
    }
    func_003BB5D0();
    func_003BB590(0xD0028);
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090_0047FAC8(a0);
        if (D_L01_001D672C[0] == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
/* localdecomp:end func_L01_0047FAC8 */
