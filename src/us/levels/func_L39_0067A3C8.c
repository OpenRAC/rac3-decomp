#include "common.h"

/* NTSC-U counterpart of func_L39_0067CED8 (src/levels/39_multiplayer_menu/L39_0067CE08.c) */
/* localdecomp:start func_L39_0067A3C8 */
typedef struct S_0067CED8_Blk { char *a; char *b; char *c; } S_0067CED8_Blk;
typedef struct S_0067CED8_Src { s32 w; s16 h; } S_0067CED8_Src;
typedef struct S_0067CED8_Buf { s32 w; s16 h; u8 pad[26]; } S_0067CED8_Buf;
__asm__(".extern D_001E1970_sda, 4");
extern S_0067CED8_Blk D_001E1970_sda[] __attribute__((section(".sdata")));
extern s32 D_001E197C_sda;
extern char D_L39_002469F0[];
extern char D_L39_00246A08[];
extern S_0067CED8_Src D_L39_00246A10[];
extern char D_L39_00246A18[];
extern void func_00193128(char *);
extern void func_L39_0059C5E8(char *, s32, S_0067CED8_Blk *);

void func_L39_0067A3C8(void) {
    S_0067CED8_Buf buf;
    S_0067CED8_Blk blk;

    if (D_001E197C_sda == 0) {
        blk.a = D_L39_002469F0;
        blk.c = D_L39_00246A08;
        blk.b = (char *)&buf;
        D_001E197C_sda = 1;
        D_001E1970_sda[0] = blk;
    }
    buf.w = D_L39_00246A10[0].w;
    buf.h = D_L39_00246A10[0].h;
    func_00193128((char *)&buf + 5);
    func_L39_0059C5E8(D_L39_00246A18, 3, D_001E1970_sda);
}
/* localdecomp:end func_L39_0067A3C8 */
