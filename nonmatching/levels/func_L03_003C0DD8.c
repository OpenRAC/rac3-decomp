/* NTSC-U draft (Claude wave K): C of func_L03_003BEFE8, the NTSC-U twin of func_L03_003C0DD8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 15 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L03_003BEFE8", whose code is not the PAL one).
 * Worker's note: near: 15 aligned diff units (ck4; 296 of 297 words, 9 hunks; was 29 at medium) with the PAL line + @ps2as (the PAL line alone cannot match: lui/ori/mtc1 float literals and the lui $at store macro), so it could only land as flags. Levers found: (1) compare the ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L03_003C0DD8 (src/levels/shared/L03_003C0DD8.c). NEAR (high): 15 words differ by the aligned score
   (ck4 TOTAL; 296 of 297 words) with the PAL flags + @ps2as (lui/ori/mtc1 literals, lui $at store macro). The state byte m[0x20] is
   compared RAW in every condition (no local) as retail does (lbu v0; andi a0,v0,0xFF; a1 copy). Open: retail's third compare keeps
   `andi v1,a1,0xFF` (combine merges it into the branch here) and its allocation is a0/a1 where ours is v1/a0; D_001A7E18 base/result swapped. */

/* localdecomp:start func_L03_003BEFE8 */
typedef struct { u8 pad[0x24]; s32 i24; u8 pad28[0x6C - 0x28]; s32 i6C; u8 pad70[6]; s16 h76; u8 pad78[0x94 - 0x78]; s32 i94; s16 h98; u8 pad9A[4]; s16 h9E; } G_003C08D8;
typedef struct { u8 p0[0x80]; vu0_q q80; vu0_q q90; u8 pA0[0x1DC - 0xA0]; s16 h1DC; u8 p1DE[0xC08 - 0x1DE]; u32 wC08; } H_3BEFE8;
extern H_3BEFE8 D_001A4BE0;
extern u8 D_001A4C60[];
extern u16 D_001A7E18[];
extern G_003C08D8 D_001CCFD0;
extern u8 D_00142791[];
extern s32 D_001D545C_sda;
extern f32 D_001DEC60_sda;
extern s32 D_001DF35C_sda;
extern s32 D_L03_001DF738;
__asm__(".extern D_L03_001DF738, 16");
extern f32 D_L03_001E92A8[];
__asm__(".extern D_001D545C_sda, 4");
__asm__(".extern D_001DEC60_sda, 4");
__asm__(".extern D_001DF35C_sda, 4");
extern void func_003BD360(void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_0037E2A8(void);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_003887C8(void *, void *);
extern void func_L03_003BEAE8(void *);
extern f32 func_00389380(f32, f32);
extern void func_L03_003BE830(void *);
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);
extern void func_0039C710(void);
extern void func_L03_003BEDE0(void *);
extern s32 func_0037E1D8(s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_0050BB98(s32, s32, f32);
extern s32 func_00388398(void *);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_003E9730(s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L03_003BF490(void *, s32);
extern void func_L01_0044ECE0(s32, s32, s32);
extern void func_00399F90(void);
extern void func_00399C90(s32, s32);
extern void func_L01_00417F60(s32, s32);
extern void func_L01_004A6DF8(void *, s32);

void func_L03_003BEFE8(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 vec0;
    vu0_v4 vec10;
    s32 i;

    if (v == 0) {
        return;
    }
    if (D_001D545C_sda != 3) {
        if (m[0x20] == 0) {
            if (D_00142791[0] != 0) {
                goto call_end;
            }
            *(vu0_q *)(v + 0x20) = *(vu0_q *)(m + 0x10);
            *(f32 *)(v + 0x2C) = *(f32 *)(m + 0xF8);
            vec10 = vec0 = *(vu0_v4 *)(m + 0x10);
            vec10.z += 1.0f;
            vec0.z -= 1.0f;
            if (func_003CE740(&vec10, &vec0, 2, m, 0) != 0) {
                *(f32 *)(m + 0x18) = D_L03_001E92A8[0] + 1.5f;
            }
            *(f32 *)(m + 0xF0) = func_0037E2A8();
            *(f32 *)(m + 0xF4) = func_0037E2A8();
            *(f32 *)(m + 0xF8) = func_0037E2A8();
            *(f32 *)(m + 0xFC) = func_0037E2A8();
            *(f32 *)(v + 8) = *(f32 *)(m + 0x18);
            func_L01_00441FB8(m, 1, -1);
        } else if (m[0x20] == 1) {
            if (func_003887C8(D_001A4C60, m + 0x10) <= D_001DEC60_sda) {
                func_L03_003BEAE8(m);
            }
        }
        if (m[0x20] == 1) {
            *(f32 *)(m + 0xF0) = func_00389380(*(f32 *)(m + 0xF0), 0.03490659f);
            *(f32 *)(m + 0xF4) = func_00389380(*(f32 *)(m + 0xF4), 0.011635529f);
            *(f32 *)(m + 0xF8) = func_00389380(*(f32 *)(m + 0xF8), 0.0058177644f);
            *(f32 *)(m + 0xFC) = func_00389380(*(f32 *)(m + 0xFC), 0.026179941f);
            func_L03_003BE830(m);
            func_L01_0044B860(m, v, v + 4, 0.25f, 0.023271058f, *(f32 *)(v + 8));
            *(s16 *)(m + 0x96) = 0;
            return;
        }
        if (m[0x20] == 2) {
            if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
                func_0039C710();
            }
            D_L03_001DF738 = 1;
            D_001A4BE0.h1DC = 3;
            func_L03_003BEDE0(m);
            *(vu0_q *)(m + 0x10) = D_001A4BE0.q80;
            *(vu0_q *)(m + 0xF0) = D_001A4BE0.q90;
            if (m[0x42] == 1) {
                if (func_0037E1D8(10) == 0) {
                    func_L03_003BE830(m);
                }
                if (m[0x60] & 2) {
                    if (m[0x43] != 0) {
                        func_003BE4F0(m, 0, 0, 0);
                    }
                    m[0x31] = 0;
                    *(u16 *)(m + 0x34) |= 1;
                    for (i = 3; i >= 0; i--) {
                        func_L03_003BE830(m);
                    }
                }
            }
            if (D_001A4BE0.wC08 & 2) {
                func_L01_0050BB98(0, 0, 30.0f);
            }
            if (m[0x42] != 0) {
                return;
            }
            if (func_00388398(v + 0x7C) == 0) {
                return;
            }
            D_001DF35C_sda = 0;
            func_L01_004F12C0(&D_001A4BE0.q80, &D_001A4BE0.q90, 0, 0);
            func_L01_003E9730(0, 0);
            func_0039FE80(0, 0, m);
            func_L03_003BF490(m + 0x10, 10);
            func_L01_0044ECE0(0x12A8, 0x1F4, 0);
            D_00142791[0] = 1;
            func_00399F90();
            func_00399C90(0, -1);
            if (D_001A7E18[0xC540 / 2] == 0) {
                func_L01_00417F60(0x1070, 0xDF);
            }
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(m, 1);
        call_end:
            func_003BD360(m);
        }
    } else {
        if (m[0x20] != 0) {
            return;
        }
        m[0x20] = 1;
        if (D_00142791[0] == 0) {
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(m, 1);
            return;
        }
        *(f32 *)(m + 0xF4) = func_00389380(*(f32 *)(m + 0xF4), 1.5707964f);
        *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) + 0.35f;
        *(u16 *)(m + 0x34) &= 0xFFBE;
        *(u16 *)(m + 0x34) |= *(u16 *)(*(u8 **)(m + 0x24) + 0x44) & 0x1000;
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        return;
    }
}
/* localdecomp:end func_L03_003BEFE8 */
