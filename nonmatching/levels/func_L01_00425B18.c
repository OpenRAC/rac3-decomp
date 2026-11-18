/* Near miss (22 words of 110, 2026-11-18; open-rac-engine: wrench_load). Uses plzcw_asm() from
 * include/vu0.h for the size's log2. Everything else matches except: the TEX0 build's two chains get
 * $v0/$v1 the other way round (local-alloc priority; tried the stepwise and one-expression forms, an
 * inline builder like func_L01_0042D9C0, 60 OR-tree shapes and statement orders on the twin
 * clank_texture_load); and the store to D_001D4B98, which gcc sees as small data (one insn), lands in
 * the last call's delay slot, where Ps2EeAs must use $gp; retail has it before the argument addu that
 * fills the slot, so Ps2EeAs expands it with $at. Declared as an array it is split by gcc instead
 * (lui $v0 + sd in the slot).
 */
#include "common.h"
/* localdecomp:start func_L01_00425B18 */
#include "vu0.h"
typedef unsigned int U64_00425B18 __attribute__((mode(DI)));
typedef struct { s32 w[0x2100 / 4]; } Wad_00425B18;
typedef struct { u8 pad0[0x60]; } __attribute__((aligned(16))) LoadImage_00425B18;
extern U64_00425B18 D_001D4B98;
extern void *D_L01_001EA9B4[];
extern Wad_00425B18 D_00160C40;
extern s32 D_001A1ED0[];
extern void func_003A92F0(s32);
extern void func_003A2750(s32);
extern void func_003A26F0(void *, s32, s32);
extern void func_0012C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_0011F0A0(s32);
extern void func_0012CCC8(void *, void *);
extern void func_0012A9F0(s32, s32);

/* wrench_load: armor-WAD entry 31's texture to the GS (palette, then pixels) and its mesh into the
   wrench's buffer, then the TEX0 the wrench draws with. */
void func_L01_00425B18(void) {
    LoadImage_00425B18 li;
    u8 *buf;
    u8 *pal;
    s32 *tex;
    s32 tbw;
    s32 lg;
    U64_00425B18 value, term, term2;

    func_003A92F0(1);
    buf = D_L01_001EA9B4[0];
    func_003A2750(1);
    pal = buf + 0x30;
    tex = (s32 *)(buf + 0x10);
    func_003A26F0(buf, D_00160C40.w[0x20B0 / 4] + D_00160C40.w[0x1EB4 / 4], D_00160C40.w[0x20B4 / 4]);
    func_0012C9A0(&li, D_001A1ED0[5] >> 8, 1, 0, 0, 0, 16, 16);
    func_0011F0A0(0);
    func_0012CCC8(&li, pal);
    func_0012A9F0(0, 0);
    tbw = tex[2] >> 6;
    if (tbw <= 0) {
        tbw = 1;
    }
    lg = 30 - plzcw_asm(tex[2]);
    func_0012C9A0(&li, D_001A1ED0[10] >> 8, tbw, 0x1B, 0, 0, ((s16 *)tex)[4], ((s16 *)tex)[6]);
    func_0011F0A0(0);
    func_0012CCC8(&li, buf + 0x430);
    func_0012A9F0(0, 0);
    value = (U64_00425B18)(D_001A1ED0[5] >> 8) << 37;
    value |= 0x400000000ULL;
    term2 = (long)(D_001A1ED0[10] >> 8);
    term2 |= (U64_00425B18)tbw << 14;
    term = (U64_00425B18)lg << 26;
    term |= 0x1B00000;
    term2 |= term;
    term2 |= (U64_00425B18)lg << 30;
    value = term2 | value;
    D_001D4B98 = value | 0x8000000000000000ULL;
    func_003A26F0(buf, D_00160C40.w[0x20A8 / 4] + D_00160C40.w[0x1EB4 / 4], D_00160C40.w[0x20AC / 4]);
}
/* localdecomp:end func_L01_00425B18 */
