#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003A5348(s32, s32, s32);
/* --- end of declarations from other files --- */

/* declarations of 39DB38.c's earlier functions (tools/port_from_us.py) */
typedef struct {
    u8 pad0[0x100];
    f32 cur[16];
    f32 prev[16];
    u8 pad180[0xE];
    s16 head;
    s32 cnt;
    u8 pad194[0xC];
    s32 x1A0;
    s32 x1A4;
    s32 x1A8;
    s32 x1AC;
    s32 x1B0;
    s32 x1B4;
    s32 x1B8;
    s32 x1BC;
    s32 x1C0;
    s32 x1C4;
    s32 x1C8;
    s32 x1CC;
    s32 x1D0;
    s32 x1D4;
    s32 x1D8;
    u8 pad1DC[4];
    s32 hist[30];
    f32 ang[30];
    f32 mag[30];
    s32 x348;
    s32 idx;
    s32 count;
    s32 btn[7];
    s32 btn2[7];
    f32 an[7][16];
    u8 pad54C;
    u8 x54D;
    u8 x54E;
    u8 x54F;
    u8 pad550[0x18];
    s32 delay;
} Pad_39DB38;
extern s32 D_001D5B94;
extern u8 D_001D5477[];
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
#define SWAP_LR(x) \
    if ((x) & 0x8000) { (x) = ((x) & ~0x8000) | 0x2000; } \
    else if ((x) & 0x2000) { (x) = ((x) & ~0x2000) | 0x8000; }
typedef struct P_39E4B0 {
    u8 pad[0x188]; u8 f188; u8 f189; u8 pad18A[0x198 - 0x18A];
    s32 f198; s32 f19C; s32 f1A0; u8 pad1A4[8]; s32 f1AC; s32 f1B0; u8 pad1B4[8]; s32 f1BC;
    u8 pad1C0[0x1DC - 0x1C0]; s32 f1DC; u8 pad1E0[0x348 - 0x1E0]; s32 f348;
    u8 pad34C[0x54C - 0x34C]; u8 f54C; u8 pad54D[3]; u8 f550; u8 f551[6]; u8 f557; u8 f558; u8 pad559[3];
    s32 f55C; s32 f560; s32 f564; u8 pad568[4];
    void (*f56C)(struct P_39E4B0 *, u8 *, s32, s32); s32 f570; u8 f574; u8 f575;
} P_39E4B0;
extern P_39E4B0 *D_001D52FC_003A3740;
extern u8 D_001D4CF4;
extern u8 D_001D6DF0[8];
extern void func_003A2DC8(Pad_39DB38 *, u8 *, s32);
extern s32 func_12F470(s32, s32);
extern s32 func_12F728(s32, s32, s32, s32);
extern s32 func_12F860(s32, s32, s32, s32);
extern s32 func_12F5A8(s32, s32);
extern s32 func_12F608(s32, s32, s32, s32);
extern s32 func_12F9E0(s32, s32, u8 *);
extern s32 func_12FC18(s32, s32);
extern s32 func_12FC78(s32, s32);
extern s32 func_12EBB8(s32);
extern s32 func_12F3F8(s32, s32, u8 *);
extern s32 func_12F918(s32, s32, u8 *);
typedef struct { u8 pad[0x5C0]; } S_39E8E0;
extern S_39E8E0 D_001CD0C0[];
void func_003A3740(S_39E8E0 *);
typedef struct { u8 pad[0xA4]; u8 arr[1]; } S_143950;
extern S_143950 D_143950;
extern u8 D_001A71C4[];
typedef struct { u8 pad[8]; s32 f8; s32 fC; u8 pad2[9]; u8 f19; } S_39EA60;
extern s32 D_00222400[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_003A3CF0(f32 *, void *, f32, f32, f32);
typedef struct { s32 pad; f32 *q; } S_39EB38;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39EB98;
typedef struct { u8 pad[0x50]; f32 f50; } O_39EB98;
extern u8 D_00222800[];
extern void func_0038D5B0(void *, void *);
extern void func_0038D028_003A3E28(V4_39EB98 *, V4_39EB98 *, V4_39EB98 *);
extern f32 func_0038DAB8_003A3E28(f32, f32);
extern f32 func_0038DB00(f32, f32);
typedef struct { u8 p[0xC]; s32 fC; s32 f10; } T;
extern T D_00143950_b;
extern s32 D_1A30D0[];
extern void func_0038CD28(void *, void *, s32);
extern s32 D_001685EC[];
extern void func_0013CFC0(s32, s32);
extern u8 D_1A30B0[];
typedef struct { u8 pad[0x1200]; s32 x1200; u8 pad2[0x25C0 - 0x1204]; s32 x25C0; } S_39FB60;
typedef struct { u8 pad[0x50]; u8 b50; u8 pad2[0x2F]; } S2_39FB60;
extern S_39FB60 D_001A4BE0[];
extern S2_39FB60 D_001A30B0[];
typedef int u128_39FBD8 __attribute__((mode(TI)));
extern void func_003A3DC8(void *, void *, void *, void *);
typedef struct 
{
  u8 p0[0xC4];
  u8 *c4;
  u8 pC8[0x18];
  u128_39FBD8 qE0;
  u128_39FBD8 qF0;
} E_39FBD8;
typedef struct { u8 b[0x80]; } R_39FBD8;
extern s32 D_001D5B98_003A4FF8;
extern u8 D_001D6E14;
extern u8 D_00222480[];
extern s32 func_00382468(s32);
typedef struct { u8 pad[0xD]; u8 bD; u8 pad2[0x1A]; s32 f28; } O_39FE80;
typedef struct { u8 pad[0x24]; O_39FE80 *o; } P_39FE80;
extern u8 D_1A30B0[];
extern s32 func_003A4FF8();

/* localdecomp:start func_003A5348 */
extern s32 D_001D9D2C;
extern s32 D_001D5B9C;
extern u8 D_1A30B0[];
extern s32 func_003A4FF8();
s32 func_003A5348(s32 a, s32 b, s32 c) {
    s32 r;
    u8 *e;
    if (D_001D9D2C == 0) return -1;
    if (a >= D_001D5B9C) return -1;
    r = func_003A4FF8(D_001D9D2C + a * 32, b, c, 0, 0x400);
    if (r >= 0) {
        e = D_1A30B0 + r * 128;
        *(s32 *)(e + 0xDC) = c;
        *(s16 *)(e + 0xCA) = a;
    }
    return r;
}
/* localdecomp:end func_003A5348 */

LINKER_REMNANT("asm/remnants", func_003A53D8);
