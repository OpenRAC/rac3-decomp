/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_003EE200, the NTSC-U twin of func_L01_003F0140, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_003EB9C8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_003F0140 (PAL twin) (src/levels/shared/L01_003EF380.c) */
/* localdecomp:start func_L01_003EE200 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x18];
    u8 f18;
    u8 pad19[7];
} Ent_003EE200;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003EE200;
extern u8 D_L01_001E2A40[];
extern Ent_003EE200 *D_L01_001DFBEC;
extern u8 D_001A30B0[];
extern void func_003888C8(void *, void *, void *);
extern s32 func_00388398(void *);
extern s32 func_L01_004A74A0(s32, s32, void *, s32);
extern s32 func_0037E1D8(s32);
extern void func_0039FB08(s32);

void func_L01_003EE200(u8 *self) {
    s32 *sub = *(s32 **)(self + 8);
    V4_003EE200 d;
    V4_003EE200 l;
    s32 flags = 0x19;
    u8 *slot;

    vec_sub_ab(&d, D_L01_001E2A40, self + 0x40);
    d.w = 0.0f;
    func_003888C8(&l, &d, self + 0x50);
    if (fabs_asm(l.x) <= 1.0f && fabs_asm(l.y) <= 1.0f && fabs_asm(l.z) <= 1.0f) {
        if (D_L01_001DFBEC[sub[0]].f18) flags |= 4;
        slot = D_001A30B0 + (sub[4] << 7);
        if (*(u8 **)(slot + 0x100) != self || !slot[0xD0]) {
            if (func_00388398(sub + 3)) {
                sub[4] = func_L01_004A74A0(sub[0], flags, self, 0x400);
                if (sub[2] > 0) {
                    sub[3] = (s32)((sub[1] + func_0037E1D8(sub[2] - sub[1])) * 60.0f);
                }
            } else {
                sub[4] = -1;
            }
        } else {
            *(s32 *)(slot + 0x118) = flags;
        }
    } else {
        s32 index = sub[4];
        if (index != -1) {
            u8 *slot2 = D_001A30B0 + (index << 7);
            if (*(u8 **)(slot2 + 0x100) == self && slot2[0xD0]) func_0039FB08(index);
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L01_003EE200 */
