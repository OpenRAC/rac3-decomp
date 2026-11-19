/* functional: high. repo near-miss draft (9 words off with @ps2as on this file, which it lacks, so 100 diff here from the data-address macros); all offsets/args re-read against PAL asm */
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
extern s32 D_001D4BA0;
extern U64_00425FE0 D_001D4BA8;
extern u8 *D_L01_001E1060[];
extern s32 D_L01_001E1074;
extern Wad_00425FE0 D_00160C40;
extern s32 D_001A1ED0[];
extern void func_003A92F0(s32);
extern void func_003A2750(s32);
extern void func_003A26F0(void *, s32, s32);
extern void func_0012C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_0011F0A0(s32);
extern void func_0012CCC8(void *, void *);
extern void func_0012A9F0(s32, s32);

/* clank_texture_load: Clank's texture n (0 on a new game), from the pairs after the armor entries,
   to the GS: palette, then pixels, then the TEX0 Clank draws with. */
void func_L01_00425FE0(s32 n) {
    LoadImage_00425FE0 li;
    u8 *buf;
    u8 *pal;
    s32 *tex;
    s32 tbw;
    s32 lg;
    U64_00425FE0 value, term, term2;

    D_001D4BA0 = n;
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
    value = (U64_00425FE0)(D_001A1ED0[7] >> 8) << 37;
    value |= 0x400000000ULL;
    term2 = (long)(D_001A1ED0[12] >> 8);
    term2 |= (U64_00425FE0)tbw << 14;
    term = (U64_00425FE0)lg << 26;
    term |= 0x1B00000;
    term2 |= term;
    term2 |= (U64_00425FE0)lg << 30;
    value = term2 | value;
    D_001D4BA8 = value | 0x8000000000000000ULL;
}
