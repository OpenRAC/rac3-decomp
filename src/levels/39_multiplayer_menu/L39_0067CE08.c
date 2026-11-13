#include "common.h"

typedef struct { int a, b, c; } T;

/* declared by functions of L39_0067A788.c, which this file was cut from */
extern void func_L39_00595628(u8 *, u8 *);

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
