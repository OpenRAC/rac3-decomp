/* NTSC-U draft (2026-11-14, Claude worker): C of func_L03_003CE9F8, the NTSC-U twin of func_L03_003D0A28, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 0 words differ with its file's flags.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003CE9F8 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct V_003CE9F8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003CE9F8;

extern f32 D_L03_001DF000;
extern f32 D_L03_001DF010;
__asm__(".extern D_L03_001DF000, 4");
__asm__(".extern D_L03_001DF010, 4");
extern s32 D_L03_001D6694;
extern s32 D_001A71A4[];
extern u8 D_00142CBE[];
extern s32 D_00142C10[];
extern u8 D_001D5471;

extern void func_003BD360(void *);
extern s32 func_L01_004B6C68(void);
extern void func_L03_003CEE58(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_003886C0(void *, void *, void *, f32);
extern s32 func_L02_003E4788(f32, void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_L01_00457708(void *, f32);
extern s32 func_L02_0042DDE0(f32, void *, void *, s32, f32, f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_004576E8(void *);
extern s32 func_00388398(void *);
extern s32 func_L03_00446540(void *, s32, s32, s32);
extern s32 func_L01_00458AE0(void *, s32);
extern void func_L01_00458A08(void *, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L03_003CE9F8(u8 *o) {
    u8 *p;
    u8 *s2;
    u8 *s3;
    V_003CE9F8 t;
    f32 f;
    s32 r;

    p = *(u8 **)(o + 0x68);
    if (D_00142CBE[0] != 0) {
        func_003BD360(o);
        return;
    }
    if (func_L01_004B6C68() != 0 || D_001A71A4[0] == 0x65) {
        if (D_L03_001D6694 == 2) {
            o[0x31] = 0;
            *(u16 *)(o + 0x34) |= 1;
        }
        return;
    }
    o[0x31] = 1;
    *(u16 *)(o + 0x34) &= 0xFFFE;
    switch (o[0x20]) {
    case 0:
        func_L03_003CEE58(o);
        if (o[0x43] != 2) {
            func_003BE4F0(o, 2, 0, 1);
        }
        func_L01_00441FB8(o, 4, -1);
        break;
    case 1:
        if (func_L01_00452EC8(o) != 0) {
            if (o[0x43] != 0) {
                func_003BE4F0(o, 0, 0, 1);
            }
        }
        if ((D_00142C10[0] & 0x10000) != 0) {
            *(u128_t *)(o + 0x10) = *(u128_t *)&D_L03_001DF000;
            *(f32 *)(o + 0xF8) = 1.5707964f;
            *(s32 *)(p + 0x68) &= ~0x10;
            func_L01_00441FB8(o, 3, -1);
        }
        break;
    case 2:
        r = func_L01_00452EC8(o);
        s2 = p + 0x120;
        s3 = o + 0x10;
        if (r != 0) {
            f = func_0037E250(0.0f, 1.0f);
            func_003886C0(s2, &D_L03_001DF000, &D_L03_001DF010, f);
            if (func_L02_003E4788(0.5f, s2, s3) != 0) {
                func_L01_00441FB8(o, 3, -1);
                break;
            }
            if (o[0x43] != 1) {
                func_003BE4F0(o, 1, 0, 15);
            }
            vec_sub_ab(&t, p + 0x120, o + 0x10);
            *(f32 *)(p + 0x138) = func_00388A28(t.x, t.y);
        }
        if (func_00389468(*(f32 *)(o + 0xF8), *(f32 *)(p + 0x138)) > 0.017453292f) {
            func_L01_00457708(o, *(f32 *)(p + 0x138));
        } else {
            func_L02_0042DDE0(*(f32 *)(p + 0x138), o, s2, *(s32 *)(p + 0x68), 0.033333335f, 0.0011111111f, 0.0022222223f);
        }
        if (func_L02_003E4788(0.2f, s3, s2) != 0) {
            func_L01_00441FB8(o, 3, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(o) != 0) {
            *(s32 *)(p + 0x134) = func_0037E208(40, 120);
        }
        if (func_00389468(*(f32 *)(o + 0xF8), 1.5707964f) > 0.08726646f) {
            if (o[0x43] != 1) {
                func_003BE4F0(o, 1, 0, 15);
            }
            func_L01_00457708(o, 1.5707964f);
        } else {
            if (o[0x43] != 0) {
                func_003BE4F0(o, 0, 0, 15);
            }
            func_L01_004576E8(o);
        }
        if (func_00388398(p + 0x134) != 0) {
            func_L01_00441FB8(o, 2, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(o) != 0) {
            func_L03_00446540(o, *(s32 *)(p + 0x130), -1, 0);
        }
        if (func_L01_00458AE0(o, *(s32 *)(p + 0x130)) == 0 && (D_00142C10[0] & 0x10000) == 0) {
            func_L01_00458A08(o, func_00388A28(*(f32 *)(p + 0xD0), *(f32 *)(p + 0xD4)));
        } else {
            func_L01_00441FB8(o, 1, -1);
        }
        break;
    }
    if (D_001D5471 != 0) {
        *(f32 *)(p + 0x1E0) = 2.75f;
    }
    func_L01_0044B5C8(o, p + 0x170, 6, 0.03f, 0.3f);
}
/* localdecomp:end func_L03_003CE9F8 */
