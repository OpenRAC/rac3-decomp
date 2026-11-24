/* PAL near miss (FAM-3, Promises, 2026-11-23, upstream bbf261a1): Flavius's PAL C (nonmatching/functional/func_L03_003C4A58.c) with func_0039EC28 declared s32, its real return type (src/frontbin/39EC28.c). Replaces the NTSC-U draft of func_L03_003C2C08 (Codex worker, 2026-11-14), which is in git at 115d087a. 208 differences (tools/check.py, level 03, the file's flags), 209 at level 22; 178 with @ps2as (--as ps2as), where 9 aligned rows are left (14 with the void declaration). Blocker: the family's missing join andi on o[0x20] (nonmatching/README.md). */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003C4A58 */
typedef struct { u8 pad[0x76]; s16 h76; u8 pad78[0x98 - 0x78]; s16 h98; u8 pad9A[4]; s16 h9E; } G_func_L03_003C4A58;
typedef struct { u8 p0[0x80]; vu0_q q80; vu0_q q90; u8 pA0[0x1DC - 0xA0]; s16 h1DC; u8 p1DE[0xC08 - 0x1DE]; u32 wC08; } H_func_L03_003C4A58;
extern H_func_L03_003C4A58 D_001A4BE0;
extern u8 D_001A4C60[];
extern u16 D_001A7E18[];
extern G_func_L03_003C4A58 D_001CCFD0;
extern u8 D_00142795[];
extern s32 D_001D545C_sda;
extern f32 D_001DED60_sda;
extern s32 D_001DF2DC_sda;
extern s32 D_L03_001DF6B8;
__asm__(".extern D_L03_001DF6B8, 16");
extern f32 D_L03_001E9220[];
__asm__(".extern D_001D545C_sda, 4");
__asm__(".extern D_001DED60_sda, 4");
__asm__(".extern D_001DF2DC_sda, 4");
extern void func_003C2880(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_00382538(void);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L03_003C4558(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_003C4288(void *);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern void func_003A1798(void);
extern void func_L03_003C4850(void *);
extern s32 func_00382468(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L03_003C4EE8(void *, s32);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_0039EF28(void);
extern s32 func_0039EC28(s32, s32);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_004AA7E8(void *, s32);

void func_L03_003C4A58(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 vec0;
    vu0_v4 vec10;
    s32 i;

    if (v == 0) {
        return;
    }
    if (D_001D545C_sda != 3) {
        if (m[0x20] == 0) {
            if (D_00142795[0] != 0) {
                goto call_end;
            }
            *(vu0_q *)(v + 0x20) = *(vu0_q *)(m + 0x10);
            *(f32 *)(v + 0x2C) = *(f32 *)(m + 0xF8);
            vec10 = vec0 = *(vu0_v4 *)(m + 0x10);
            vec10.z += 1.0f;
            vec0.z -= 1.0f;
            if (func_003D3CB0(&vec10, &vec0, 2, m, 0) != 0) {
                *(f32 *)(m + 0x18) = D_L03_001E9220[2] + 0.5f;
            }
            *(f32 *)(m + 0xF0) = func_00382538();
            *(f32 *)(m + 0xF4) = func_00382538();
            *(f32 *)(m + 0xF8) = func_00382538();
            *(f32 *)(m + 0xFC) = func_00382538();
            *(f32 *)(v + 8) = *(f32 *)(m + 0x18);
            func_L01_004450F0(m, 1, -1);
        } else if (m[0x20] == 1) {
            if (func_0038CF00(D_001A4C60, m + 0x10) <= D_001DED60_sda) {
                func_L03_003C4558(m);
            }
        }
        if (m[0x20] == 1) {
            *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(m + 0xF0), 0.0418879054f);
            *(f32 *)(m + 0xF4) = func_0038DAB8(*(f32 *)(m + 0xF4), 0.0139626348f);
            *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 0.00698131742f);
            *(f32 *)(m + 0xFC) = func_0038DAB8(*(f32 *)(m + 0xFC), 0.0314159282f);
            func_L03_003C4288(m);
            func_L01_0044EAE0(m, v, v + 4, 0.25f, 0.0279252697f, *(f32 *)(v + 8));
            *(s16 *)(m + 0x96) = 0;
            return;
        }
        if (m[0x20] == 2) {
            if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
                func_003A1798();
            }
            D_L03_001DF6B8 = 1;
            D_001A4BE0.h1DC = 3;
            func_L03_003C4850(m);
            *(vu0_q *)(m + 0x10) = D_001A4BE0.q80;
            *(vu0_q *)(m + 0xF0) = D_001A4BE0.q90;
            if (m[0x42] == 1) {
                if (m[0x60] & 2) {
                    if (m[0x43] != 0) {
                        func_003C3A10(m, 0, 0, 0);
                    }
                    m[0x31] = 0;
                    *(u16 *)(m + 0x34) |= 1;
                    for (i = 3; i >= 0; i--) {
                        func_L03_003C4288(m);
                    }
                }
            }
            if (D_001A4BE0.wC08 & 2) {
                func_L01_0050FB40(0, 0, 25.0f);
            }
            if (m[0x42] != 0) {
                return;
            }
            if (func_0038CAD0(v + 0x7C) == 0) {
                return;
            }
            D_001DF2DC_sda = 0;
            func_L01_004F50C8(&D_001A4BE0.q80, &D_001A4BE0.q90, 0, 0);
            func_L01_003EB5E0(0, 0);
            func_003A52A0(0, 0, m);
            func_L03_003C4EE8(m + 0x10, 10);
            func_L01_00451F60(0x12AC, 0x1A1, 0);
            D_00142795[0] = 1;
            func_0039EF28();
            func_0039EC28(0, -1);
            if (D_001A7E18[0xC540 / 2] == 0) {
                func_L01_0041A5B0(0x1070, 0xDF);
            }
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
        call_end:
            func_003C2880(m);
        }
    } else {
        if (m[0x20] != 0) {
            return;
        }
        m[0x20] = 1;
        if (D_00142795[0] == 0) {
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            return;
        }
        *(f32 *)(m + 0xF4) = func_0038DAB8(*(f32 *)(m + 0xF4), 1.57079637f);
        *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) + 0.349999994f;
        *(u16 *)(m + 0x34) &= 0xFFBE;
        *(u16 *)(m + 0x34) |= *(u16 *)(*(u8 **)(m + 0x24) + 0x44) & 0x1000;
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        return;
    }
}
/* localdecomp:end func_L03_003C4A58 */
