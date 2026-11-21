#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C25D8();
typedef struct { u8 pad[6]; u8 f6; u8 pad7[5]; u8 fC; u8 padD[0x48 - 0xD]; void *f48[1]; } T_3A1870;
typedef struct {
    u8 pad[0x24]; T_3A1870 *f24; u8 pad28[0x32 - 0x28]; s16 f32; u16 f34; u8 pad36[2];
    long f38; u8 pad40[2]; u8 f42; u8 f43; u8 pad44[0x62 - 0x44]; u8 f62; u8 f63; u8 pad64[4];
    u8 *f68; u8 pad6C[0x98 - 0x6C]; s32 f98; u8 pad9C[0xAA - 0x9C]; s16 fAA;
} O_3A1870;
extern void func_003C25D8(O_3A1870 *, s32);
/* --- end of declarations from other files --- */

/* declarations of 3C0CA0.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern u32 D_001DA4A0;

typedef struct {
    char n0[0x10];
    char n1[0x10];
    char n2[0x10];
    f32 f30;
    s32 f34, f38, f3C, f40, f44, f48, f4C;
    f32 f50;
} S_3BC568;
extern S_3BC568 D_002D2060_003BC568;
extern f32 D_001D9048, D_001D904C, D_001D9050, D_001D9054, D_001D9058, D_001D905C;
extern f32 D_001D9060, D_001D9064, D_001D9068, D_001D906C, D_001D9070, D_001D9074;
extern s32 D_001D9078;
extern f32 D_001D907C, D_001D9080;
extern s32 D_001D4BC4;
extern char D_001D9098[], D_001D90A0[], D_001D90A8[];
extern long func_00389598(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_0038B120(s32, s32, s32, s32, s32, s32, s32, s32, f32, long, long);
extern void func_0038AF30(s32, s32, s32, s32, long);
extern void func_11B2E8();
extern s32 func_11B868(char *);
extern s32 func_00390D48(char *, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
typedef struct { u8 p0[0x20]; u8 f20; u8 p21[0x47]; s32 f68; u8 p6c[0x34]; u32 fA0; u8 pa4[0x5C]; } O_3BCFB0;
extern u32 D_001DA4A0;
extern u32 D_001DA4A4;
extern s32 D_001D9D00;
extern s32 D_001DA3C0;
extern volatile u8 D_001D90C8;
extern s32 func_003C7310();
extern void func_0038CB78();
extern int func_003C38E0();
/* localdecomp:start func_003C24B0 */
__asm__(".extern D_001DA4A0, 16");
__asm__(".extern D_001DA4A4, 16");
__asm__(".extern D_001D9D00, 16");
__asm__(".extern D_001DA3C0, 16");
O_3BCFB0 *func_003C24B0(s32 a, s32 b) {
    O_3BCFB0 *p;
    s32 r;
    p = (O_3BCFB0 *)D_001DA4A0;
    if (p < (O_3BCFB0 *)D_001DA4A4) do {
        if (p->f20 < 0xFE) continue;
        if ((u32)D_001D9D00 < p->fA0) continue;
        r = 0;
        if (b) r = func_003C7310(b);
        if (r == 0 && b) break;
        if (p->f20 == 0xFF) *((u8 *)p + 0x120) = p->f20;
        func_003C25D8((O_3A1870 *)p, a);
        p->f68 = r;
        if (b) func_0038CB78(r, 0, b);
        if (D_001DA3C0) D_001DA3C0 = D_001DA3C0 - 1;
        return p;
    } while (++p < (O_3BCFB0 *)D_001DA4A4);
    if (D_001D90C8) func_003C38E0();
    return 0;
}
/* localdecomp:end func_003C24B0 */
