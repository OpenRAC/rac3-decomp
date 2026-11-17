/* NTSC-U draft (2026-11-14, Codex worker): C of func_L09_003BDB60, the NTSC-U twin of func_L09_003BF3E0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/09_tyhrranosis/L09_003B8580.c's current line.
 * Worker's note: 120 diff; inline-literal assembler mismatch: permitted GNU flags emit lit4 loads for angle constants versus retail lui/ori/mtc1; plus initial load scheduling; no flags_alt; forbidden flags not tried; best log func_L09_003BDB60.check02.log
 */
#include "common.h"

/* localdecomp:start func_L09_003BDB60 */
typedef int Q_003BDB60 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003BDB60;
extern V_003BDB60 D_L09_001D66B0;
extern u8 *D_L09_001E011C[];
extern f32 D_001A4BE0[];
extern f32 func_003893C8(f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_L01_00445758(f32 *, f32 *, s32, f32, f32, f32, f32);
extern void func_003BEA80(void *, void *);

void func_L09_003BDB60(u8 *o)
{
    V_003BDB60 rot;
    u8 *v, *target;
    f32 a;
    v = *(u8 **)(o + 0x68);
    rot = D_L09_001D66B0;
    rot.y = -0.01745329238474369f;
    target = D_L09_001E011C[0] + (*(s32 *)(v + 0xCD0) << 8);
    rot.x = *(f32 *)(v + 0xCDC);
    a = func_003893C8(*(f32 *)(o + 0xF8), 1.5707963705062866f);
    if (*(s8 *)(v + 0xD2F) == -1) {
        a = func_003893C8(func_00389380(func_00388A28(
            D_001A4BE0[0x80/4] - *(f32 *)(target + 0x10),
            D_001A4BE0[0x84/4] - *(f32 *)(target + 0x14)), 3.1415927410125732f), a);
        func_L01_00445758(&rot.x, (f32 *)(v + 0xCD8), *(s8 *)(v + 0xD2F), a, 0.0034906587097793818f, 0.0034906587097793818f, 0.024725498631596565f);
        if (func_00389468(rot.x, a) < 0.01745329238474369f) {
            s32 old = *(s8 *)(v + 0xD2F);
            *(s8 *)(v + 0xD2F) = 1;
            if (old != 1)
                v[0xD2E]++;
        }
    } else {
        a = func_003893C8(func_00388A28(
            D_001A4BE0[0x80/4] - *(f32 *)(target + 0x10),
            D_001A4BE0[0x84/4] - *(f32 *)(target + 0x14)), a);
        func_L01_00445758(&rot.x, (f32 *)(v + 0xCD8), *(s8 *)(v + 0xD2F), a, 0.0034906587097793818f, 0.0034906587097793818f, 0.024725498631596565f);
        if (func_00389468(rot.x, a) < 0.01745329238474369f) {
            s32 old = *(s8 *)(v + 0xD2F);
            *(s8 *)(v + 0xD2F) = -1;
            if (old != -1)
                v[0xD2E]++;
        }
    }
    *(f32 *)(v + 0xCDC) = rot.x;
    func_003BEA80(v + 0xC50, &rot);
}
/* localdecomp:end func_L09_003BDB60 */
