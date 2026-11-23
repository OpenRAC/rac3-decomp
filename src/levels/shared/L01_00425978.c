#include "common.h"

/* localdecomp:start func_L01_00425978 */
extern s32 D_L01_001FD180[];
extern s32 D_L01_001EA9B8[];
extern s32 D_001D4B60;
extern u8 *D_001A5E80[];
extern u8 D_00142660[];
extern void func_00398808(s32);
extern void func_00398A88(s32);
extern void func_00399A08(s32, s32);

void func_L01_00425978(s32 a0)
{
    u8 *p;
    u8 *q;
    s32 v;

    func_00398808(a0);
    func_00398A88(a0);
    func_00399A08(D_L01_001FD180[0], D_L01_001EA9B8[0]);
    D_001D4B60 = a0;
    p = D_001A5E80[0];
    if (p != 0) {
        q = D_00142660;
        v = p[126] & 0x8F;
        p[126] = v;
        if ((u32)(*(s32 *)(q + 120) - 1) < 3) {
            p[126] = v | ((*(s32 *)(q + 120) << 4) | 0x80);
        }
    }
}
/* localdecomp:end func_L01_00425978 */

/* localdecomp:start func_L01_00425A08 */
extern void func_00399A08(s32, s32);
extern s32 D_L01_001FD180[];
typedef int s128_422C60 __attribute__((mode(TI)));

extern u8 D_L01_001FFB0A[];
extern s32 D_L01_00200670[];
extern s128_422C60 D_L01_00200DF0[];
extern s32 D_L01_001EA9B8[];
extern void func_0038CB78(void *, s32, s32);

void func_L01_00425A08(s32 restore) {
    u8 idx;

    if (restore) {
        idx = D_L01_001FFB0A[0];
        *(s32 *)((u8 * *)&D_L01_001FD180)[0] = *(s32 *)((u8 * *)&D_L01_001FD180)[idx];
        ((u8 * *)&D_L01_001FD180)[0][4] = ((u8 * *)&D_L01_001FD180)[idx][4];
        ((u8 * *)&D_L01_001FD180)[0][5] = ((u8 * *)&D_L01_001FD180)[idx][5];
        ((u8 * *)&D_L01_001FD180)[0][6] = ((u8 * *)&D_L01_001FD180)[idx][6];
        ((u8 * *)&D_L01_001FD180)[0][7] = ((u8 * *)&D_L01_001FD180)[idx][7];
        *(s32 *)(((u8 * *)&D_L01_001FD180)[0] + 32) = *(s32 *)(((u8 * *)&D_L01_001FD180)[idx] + 32);
        D_L01_00200670[0] = D_L01_00200670[idx];
        D_L01_00200DF0[0] = D_L01_00200DF0[idx];
    } else {
        ((void (*)(u8 *, s32))func_00399A08)(((u8 * *)&D_L01_001FD180)[0], D_L01_001EA9B8[0]);
        D_L01_00200670[0] = 0xFFFC0000;
        func_0038CB78(D_L01_00200DF0, -1, 16);
    }
    ((u8 * *)&D_L01_001FD180)[0][9] = ((u8 * *)&D_L01_001FD180)[0][8];
}
/* localdecomp:end func_L01_00425A08 */

/* localdecomp:start func_L01_00425B18 */
#include "vu0.h"
typedef unsigned int U64_00425B18 __attribute__((mode(DI)));
typedef struct { s32 sector; s32 size; } WadPair_00425B18;
/* The WAD table (as func_L01_00425FE0 reads it): the base sector, then (sector, size) pairs */
typedef struct {
    u8 pad0[0x1EB4];
    s32 base;                      /* 0x1EB4: the WAD's first sector */
    u8 pad1EB8[0x1FB8 - 0x1EB8];
    WadPair_00425B18 armor[80];    /* 0x1FB8 */
} Wad_00425B18;
typedef struct { u8 pad0[0x60]; } __attribute__((aligned(16))) LoadImage_00425B18;
/* The wrench's texture state (16 bytes, the core's .extern size): a word, then the TEX0 it draws
   with. Small data: retail stores the TEX0 at symbol + 8 as one unsplit macro (Ps2EeAs lui $at),
   which reorg keeps out of the call's delay slot (docs/build/globals.md, "Small data at an offset
   stays out of delay slots"). An alias, since func_L01_00425CD0 below declares the two words apart. */
typedef struct {
    u32 value;
    u32 pad4;
    U64_00425B18 tex0;
} TexState_00425B18;
extern TexState_00425B18 D_001D4B90_00425B18 __attribute__((section(".sdata")));
extern void *D_L01_001EA9B4[];
extern Wad_00425B18 D_00160C40;
extern s32 D_001A1ED0[];
extern void func_003A92F0(s32);
extern s32 func_003A2750(s32);
extern s32 func_003A26F0(void *, s32, s32);
extern s32 func_0012C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_0011F0A0(s32);
extern void func_0012CCC8(void *, void *);
/* s32, as the core's: the result in $v0 keeps local-alloc's next quantity out of $v0 */
extern s32 func_0012A9F0(s32, s32);

/* wrench_load: armor-WAD entry 31's texture to the GS (palette, then pixels) and its mesh into the
   wrench's buffer, then the TEX0 the wrench draws with. */
void func_L01_00425B18(void) {
    LoadImage_00425B18 li;
    u8 *buf;
    u8 *pal;
    s32 *tex;
    s32 tbw;
    s32 lg;

    func_003A92F0(1);
    buf = D_L01_001EA9B4[0];
    func_003A2750(1);
    pal = buf + 0x30;
    tex = (s32 *)(buf + 0x10);
    func_003A26F0(buf, D_00160C40.armor[31].sector + D_00160C40.base, D_00160C40.armor[31].size);
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
    /* TEX0: TBP the pixels, TBW, PSM 0x1B (PSMT8H), TW = TH = log2(width), TCC 1, CBP the palette,
       CLD 4 */
    D_001D4B90_00425B18.tex0 = (U64_00425B18)(D_001A1ED0[10] >> 8) | ((U64_00425B18)tbw << 14) |
        ((U64_00425B18)0x1B << 20) | ((U64_00425B18)lg << 26) | ((U64_00425B18)lg << 30) |
        ((U64_00425B18)1 << 34) | ((U64_00425B18)(D_001A1ED0[5] >> 8) << 37) | ((U64_00425B18)4 << 61);
    func_003A26F0(buf, D_00160C40.armor[30].sector + D_00160C40.base, D_00160C40.armor[30].size);
}
/* localdecomp:end func_L01_00425B18 */

/* localdecomp:start func_L01_00425CD0 */
typedef unsigned int U64_00425CD0 __attribute__((mode(DI)));
typedef struct {
    U64_00425CD0 data;
    U64_00425CD0 tag1;
    U64_00425CD0 tag2;
} Packet_00425CD0;
extern U64_00425CD0 D_001D4B98;
extern u32 D_001D4B90;
extern void *D_L01_001EA9B4[];
extern Packet_00425CD0 D_L01_001F3DC0[];
extern U64_00425CD0 D_L01_001D6D20 __attribute__((sda));
__asm__(".extern D_L01_001D6D20, 8");

void func_L01_00425CD0(unsigned int value)
{
    extern void func_00399928(void *, int, void *);
    D_001D4B90 = value;
    D_L01_001F3DC0[0].data = D_001D4B98;
    D_L01_001F3DC0[0].tag1 = 0x0000FFA0000000E0ULL;
    D_L01_001F3DC0[0].tag2 = 0x0040000400004000ULL;
    func_00399928(D_L01_001EA9B4[0], 0, &D_L01_001D6D20);
}
/* localdecomp:end func_L01_00425CD0 */

LINKER_REMNANT("asm/levels", func_L01_00425D40);
