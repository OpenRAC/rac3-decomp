#include "common.h"

/* localdecomp:start func_L39_0062B670 */
typedef struct { u8 pad[16]; u8 b16; } Info_00628E98;
typedef struct { u8 pad[72]; Info_00628E98 *info[1]; } Tbl_00628E98;
typedef struct { u8 pad0[36]; Tbl_00628E98 *tbl; u8 pad1[24]; u8 b64; u8 b65; u8 b66; u8 b67; s32 w68; } Sub_00628E98;
typedef struct { u8 pad[9508]; Sub_00628E98 *sub; } Obj_00628E98;
extern void func_003C29B0(Sub_00628E98 *);
void func_L39_0062B670(Obj_00628E98 *o, s32 a1, s32 a2) {
    Sub_00628E98 *s = o->sub;
    s32 n;
    s->b65 = a2 + 1;
    s->b64 = a2;
    n = s->tbl->info[a1]->b16 - 1;
    if (n < s->b65) s->b65 = n;
    s->b66 = a1;
    s->b67 = a1;
    s->w68 = 0;
    func_003C29B0(s);
}
/* localdecomp:end func_L39_0062B670 */

/* localdecomp:start func_L39_0062B6D8 */
typedef struct { u8 pad[16]; u8 b16; } Info_0062B6D8;
typedef struct { u8 pad[72]; Info_0062B6D8 *info[1]; } Tbl_0062B6D8;
typedef struct { u8 pad0[36]; Tbl_0062B6D8 *tbl; u8 pad1[27]; u8 b67; } Sub_0062B6D8;
typedef struct { u8 pad[0x630]; s32 w630; s32 w634; u8 pad2[0x2524-0x638]; Sub_0062B6D8 *sub; } Obj_0062B6D8;
void func_L39_0062B6D8(Obj_0062B6D8 *o, s32 a1, s32 a2) {
    if (a1 >= 0) {
        Sub_0062B6D8 *s = o->sub;
        if (a2 < s->tbl->info[s->b67]->b16) {
            o->w630 = a1;
            o->w634 = a2;
        }
    }
}
/* localdecomp:end func_L39_0062B6D8 */

/* localdecomp:start func_L39_0062B718 */
void func_L39_0062B718(u8 *a0) {
    *(s32 *)(a0 + 0x638) = 0;
    *(s32 *)(a0 + 0x630) = -1;
}
/* localdecomp:end func_L39_0062B718 */

/* localdecomp:start func_L39_0062B728 */
void func_L39_0062B728(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x638) = (s32) ((~arg1 != 0) ? arg1 : 4);
}
/* localdecomp:end func_L39_0062B728 */

INCLUDE_ASM("asm/levels", func_L39_0062B740);

INCLUDE_ASM("asm/levels", func_L39_0062B838);
