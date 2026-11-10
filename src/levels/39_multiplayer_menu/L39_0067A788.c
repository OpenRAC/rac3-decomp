#include "common.h"

typedef struct { int a, b, c; } T;

/* localdecomp:start func_L39_0067A788 */
extern void func_L39_00595628(u8 *, u8 *);

void func_L39_0067A788(u8 *arg0) {
    u8 buf[0x200];
    u8 *d = buf;
    u8 *s = arg0;
    while (*s != 0) {
        *d++ = 0;
        *d++ = *s++;
    }
    *d++ = 0;
    *d++ = 0;
    func_L39_00595628(buf, arg0);
}
/* localdecomp:end func_L39_0067A788 */

/* localdecomp:start func_L39_0067A7E0 */
typedef struct S_0067A7E0 {
    u8 pad[0x10];
    s32 ***f10;
} S_0067A7E0;

extern u8 D_001A5E72[];
s32 func_L01_003EC898(s32);
S_0067A7E0 *func_L01_004127C0(u8 *);
s32 func_L01_00412810(s32);
void func_L01_004126A8(s32);
s32 func_001206F4(void *, s32);
void func_001260A0(void);

void func_L39_0067A7E0(void) {
    S_0067A7E0 *e;
    u8 *base;

    func_L01_003EC898(0);
    base = D_001A5E72;
    e = func_L01_004127C0(base);
    if (e != 0) {
        func_001206F4(base - 0x20, func_L01_00412810(**e->f10));
        func_001206F4(base + 0x100, (s32)(base - 0x20));
    }
    e = func_L01_004127C0(base + 0xC0);
    if (e != 0) {
        func_001206F4(base + 0xA0, func_L01_00412810(**e->f10));
    }
    func_L01_004126A8(0);
    func_001260A0();
}
/* localdecomp:end func_L39_0067A7E0 */

INCLUDE_ASM("asm/levels", func_L39_0067A888);

INCLUDE_ASM("asm/levels", func_L39_0067AB38);

INCLUDE_ASM("asm/levels", func_L39_0067ABC8);

INCLUDE_ASM("asm/levels", func_L39_0067BBE8);

/* localdecomp:start func_L39_0067BC58 */
typedef struct S_0067BC58 {
    s16 lo;
    s16 hi;
    u8 pad[12];
} S_0067BC58;

S_0067BC58 *func_L39_0067BC58(s32 key, S_0067BC58 *tab, u32 n) {
    u32 i;
    S_0067BC58 *ret = 0;
    for (i = 0; i < n; i++, tab++) {
        if (tab->lo <= key && key <= tab->hi) {
            ret = tab;
            break;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_0067BC58 */

INCLUDE_ASM("asm/levels", func_L39_0067BCA8);

INCLUDE_ASM("asm/levels", func_L39_0067BE08);

INCLUDE_ASM("asm/levels", func_L39_0067C408);

/* localdecomp:start func_L39_0067C8E8 */
typedef struct { u8 pad[0x25C]; T t; } S_0067C8E8;
extern S_0067C8E8 D_L39_0025D6C0;
extern void func_L39_0067ED40(void);
extern void func_L39_00685FF0(void);
extern void func_L39_006D78F8(void);
extern void func_00392260(s32, s32, s32);

void func_L39_0067C8E8(void) {
    func_L39_0067ED40();
    func_00392260(D_L39_0025D6C0.t.a, D_L39_0025D6C0.t.b, D_L39_0025D6C0.t.c);
    func_L39_00681470();
    func_L39_00685FF0();
    func_L39_006D78F8();
    func_001953B8(0);
    func_001953D0(0);
}
/* localdecomp:end func_L39_0067C8E8 */

INCLUDE_ASM("asm/levels", func_L39_0067C948);

INCLUDE_ASM("asm/levels", func_L39_0067C9C0);

INCLUDE_ASM("asm/levels", func_L39_0067CA48);

INCLUDE_ASM("asm/levels", func_L39_0067CAC0);

INCLUDE_ASM("asm/levels", func_L39_0067CCB0);

/* localdecomp:start func_L39_0067CE08 */
void func_001953B8(void *);
void func_001953D0(void *);
extern u8 D_L39_0067CAC0[];

void func_L39_0067CE08(void) {
    func_001953B8(D_L39_0067CAC0);
    func_001953D0(D_L39_0067CAC0);
}
/* localdecomp:end func_L39_0067CE08 */

/* localdecomp:start func_L39_0067CE40 */
u8 func_L39_0067CE40(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x9D));
}
/* localdecomp:end func_L39_0067CE40 */

/* localdecomp:start func_L39_0067CE48 */
extern void func_L39_00595628(u8 *, u8 *);

void func_L39_0067CE48(u8 *arg0) {
    u8 buf[0x200];
    u8 *d = buf;
    u8 *s = arg0;
    while (*s != 0) {
        *d++ = 0;
        *d++ = *s++;
    }
    *d++ = 0;
    *d = 0;
    func_L39_00595628(buf, arg0);
}
/* localdecomp:end func_L39_0067CE48 */

/* localdecomp:start func_L39_0067CEA0 */
extern long func_0012DCB0(void);
extern long func_00130760(long arg0, long arg1);

/* from rac4-decomp's func_L00_0077E000 */
s32 func_L39_0067CEA0(void) {
    return func_00130760(func_0012DCB0(), 0x24000);
}
/* localdecomp:end func_L39_0067CEA0 */

/* localdecomp:start func_L39_0067CED8 */
typedef struct S_0067CED8_Blk { char *a; char *b; char *c; } S_0067CED8_Blk;
typedef struct S_0067CED8_Src { s32 w; s16 h; } S_0067CED8_Src;
typedef struct S_0067CED8_Buf { s32 w; s16 h; u8 pad[26]; } S_0067CED8_Buf;
__asm__(".extern D_001E19F0_sda, 4");
extern S_0067CED8_Blk D_001E19F0_sda[] __attribute__((section(".sdata")));
extern s32 D_001E19FC_sda;
extern char D_L39_00246890[];
extern char D_L39_002468A8[];
extern S_0067CED8_Src D_L39_002468B0[];
extern char D_L39_002468B8[];
extern void func_00193038(char *);
extern void func_L39_0059D978(char *, s32, S_0067CED8_Blk *);

void func_L39_0067CED8(void) {
    S_0067CED8_Buf buf;
    S_0067CED8_Blk blk;

    if (D_001E19FC_sda == 0) {
        blk.a = D_L39_00246890;
        blk.c = D_L39_002468A8;
        blk.b = (char *)&buf;
        D_001E19FC_sda = 1;
        D_001E19F0_sda[0] = blk;
    }
    buf.w = D_L39_002468B0[0].w;
    buf.h = D_L39_002468B0[0].h;
    func_00193038((char *)&buf + 5);
    func_L39_0059D978(D_L39_002468B8, 3, D_001E19F0_sda);
}
/* localdecomp:end func_L39_0067CED8 */

INCLUDE_ASM("asm/levels", func_L39_0067CF68);

INCLUDE_ASM("asm/levels", func_L39_0067D410);

/* localdecomp:start func_L39_0067D658 */
void func_L39_006121B0(s32);
void func_L39_00681470();

void func_L39_0067D658(void) {
    func_L39_006121B0(0);
    func_L39_006121B0(1);
    func_L39_00681470();
}
/* localdecomp:end func_L39_0067D658 */

INCLUDE_ASM("asm/levels", func_L39_0067D688);

INCLUDE_ASM("asm/levels", func_L39_0067D758);

/* localdecomp:start func_L39_0067EB98 */
void func_00137520();
s32 func_L39_0067CEA0();
extern s32 D_001A5DF0[];
extern s32 D_001DB168_sda;

s32 func_L39_0067EB98(void) {
    D_001DB168_sda = func_L39_0067CEA0();
    func_00137520();
    D_001A5DF0[0] = 2;
    return 0;
}
/* localdecomp:end func_L39_0067EB98 */

/* localdecomp:start func_L39_0067EBD0 */
int func_L39_0067EBD0(void) { int r = func_L39_0067CEA0(); int g = D_001DB168_sda; return g < 0 ? 3000 : r - g; }
/* localdecomp:end func_L39_0067EBD0 */

/* localdecomp:start func_L39_0067EC00 */
extern int func_00126150(void);
extern int func_001260F0(int arg0, int arg1);
extern void func_001915F0(void);
extern int D_001E1A60_sda;

/* from rac4-decomp's func_L00_00708228 */
void func_L39_0067EC00(void) {
    D_001E1A60_sda = func_001260F0(func_00126150(), 0x3C);
    func_001915F0();
}
/* localdecomp:end func_L39_0067EC00 */

INCLUDE_ASM("asm/levels", func_L39_0067EC30);

INCLUDE_ASM("asm/levels", func_L39_0067ED40);

/* localdecomp:start func_L39_0067ED90 */
extern T D_L39_004AE080[];
extern void func_001377D0(int, int, int);
void func_L39_0067ED90(unsigned int i) {
    if (i < 6) func_001377D0(D_L39_004AE080[i].a, D_L39_004AE080[i].b, D_L39_004AE080[i].c);
}
/* localdecomp:end func_L39_0067ED90 */

LINKER_REMNANT("asm/levels", func_L39_0067EDD8);
