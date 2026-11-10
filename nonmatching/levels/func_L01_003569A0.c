/* Level 01. 42 diff: retail zeroes a quadword twice with a bare "sq $zero" (sp+0 and 0xC0($s1)); plain C gives "por"+"sq", which shifts the rest. Same blocker as func_L01_00423E20 and func_L01_00356818. The C below is the structure from the agent report (the best compile had no third argument for func_0040E3C0 and needs @ps2as checked). */
#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) W4;
typedef struct { char p0[0x10]; W4 f10; char p1[0x14]; u32 pad24; f32 f2C; char p30[4]; u16 f34; } A_3569A0;
/* Offsets (a = arg0): f10 @0x10 (W4), f24 @0x24 (-> R with f10 @0x10, f24 @0x24, f44 @0x44 u16), f2C @0x2C, f34 @0x34,
   f68 @0x68 (-> B), f98 @0x98, fC0 @0xC0, fF0 @0xF0 (W4).  B: fC0 (W4), fF8, fFC, f100, f110, f118, f148 = -1, f354, f358.
   $gp slots (base 0x1DC8B0): D28 = D_001DD5D8_sda, D18 = D_001DD5C8_sda, D1C = D_001DD5CC_sda, D04 = D_001DD5B4_sda (f32), D00 = D_001DD5B0_sda (s32). */
/* body, in order: v = {0}; v.z = z; a->f10 = *p; a->fF0 = v; func_0040EB68(a+0xC0, &v);
   a->f34 = (a->f34 & 0xFFBE) | (a->f24->f44 & 0x1000); a->f98 = a->f24->f10; b = a->f68; b->f358 = D28;
   a->f2C = a->f24->f24 * D28; b->f354 = 0; func_0040E3C0(b+0x110, a+0xC0, D18); b->fC0 = zero quad; b->fF8 = b->fFC = b->f100 = 0;
   b->f148 = -1; b->f118 = D1C; func_L01_004450F0(a, 0x19, 4); func_00444CB8(a, D00, (s32)D04); */
