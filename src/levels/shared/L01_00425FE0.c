#include "common.h"

/* localdecomp:start func_L01_00425FE0 */
#include "vu0.h"
typedef unsigned int U64_00425FE0 __attribute__((mode(DI)));
typedef struct { s32 sector; s32 size; } WadPair_00425FE0;
typedef struct {
    u8 pad0[0x1EB4];
    s32 base;                      /* 0x1EB4: the WAD's first sector */
    u8 pad1EB8[0x1FB8 - 0x1EB8];
    WadPair_00425FE0 armor[80];    /* 0x1FB8 */
    WadPair_00425FE0 clank[20];    /* 0x2238 */
} Wad_00425FE0;
typedef struct { u8 pad0[0x60]; } __attribute__((aligned(16))) LoadImage_00425FE0;
/* Clank's texture state (16 bytes, the core's .extern size): his texture number, then the TEX0 he
   draws with. Small data: retail stores the number through $gp in a delay slot and the TEX0 at
   symbol + 8 as one unsplit macro (Ps2EeAs lui $at) (docs/build/globals.md, "Small data at an
   offset stays out of delay slots"). */
typedef struct {
    s32 index;
    s32 pad4;
    U64_00425FE0 tex0;
} TexState_00425FE0;
extern TexState_00425FE0 D_001D4BA0 __attribute__((section(".sdata")));
extern u8 *D_L01_001E1060[];
extern s32 D_L01_001E1074;
extern Wad_00425FE0 D_00160C40;
extern s32 D_001A1ED0[];
extern void func_003A92F0(s32);
/* s32, as the core's: a call's result in $v0 keeps local-alloc's next quantity out of $v0 */
extern s32 func_003A2750(s32);
extern s32 func_003A26F0(void *, s32, s32);
extern s32 func_0012C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_0011F0A0(s32);
extern void func_0012CCC8(void *, void *);
extern s32 func_0012A9F0(s32, s32);

/* clank_texture_load: Clank's texture n (0 on a new game), from the pairs after the armor entries,
   to the GS: palette, then pixels, then the TEX0 Clank draws with. */
void func_L01_00425FE0(s32 n) {
    LoadImage_00425FE0 li;
    u8 *buf;
    u8 *pal;
    s32 *tex;
    s32 tbw;
    s32 lg;

    D_001D4BA0.index = n;
    func_003A92F0(1);
    buf = D_L01_001E1060[1 - D_L01_001E1074];
    func_003A2750(1);
    pal = buf + 0x20;
    func_003A26F0(buf, D_00160C40.clank[n].sector + D_00160C40.base, D_00160C40.clank[n].size);
    func_0012C9A0(&li, D_001A1ED0[7] >> 8, 1, 0, 0, 0, 16, 16);
    func_0011F0A0(0);
    func_0012CCC8(&li, pal);
    func_0012A9F0(0, 0);
    tex = (s32 *)buf;
    tbw = tex[2] >> 6;
    if (tbw <= 0) {
        tbw = 1;
    }
    lg = 30 - plzcw_asm(tex[2]);
    func_0012C9A0(&li, D_001A1ED0[12] >> 8, tbw, 0x1B, 0, 0, ((s16 *)tex)[4], ((s16 *)tex)[6]);
    func_0011F0A0(0);
    func_0012CCC8(&li, buf + 0x420);
    func_0012A9F0(0, 0);
    /* TEX0: TBP the pixels, TBW, PSM 0x1B (PSMT8H), TW = TH = log2(width), TCC 1, CBP the palette,
       CLD 4 */
    D_001D4BA0.tex0 = (U64_00425FE0)(D_001A1ED0[12] >> 8) | ((U64_00425FE0)tbw << 14) |
        ((U64_00425FE0)0x1B << 20) | ((U64_00425FE0)lg << 26) | ((U64_00425FE0)lg << 30) |
        ((U64_00425FE0)1 << 34) | ((U64_00425FE0)(D_001A1ED0[7] >> 8) << 37) | ((U64_00425FE0)4 << 61);
}
/* localdecomp:end func_L01_00425FE0 */
