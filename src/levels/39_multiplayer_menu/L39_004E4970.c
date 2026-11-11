#include "common.h"

/* declared by functions of L39_004DF158.c, which this file was cut from */
extern s32 func_L39_004E4970(s32, s32 *, s32);

/* localdecomp:start func_L39_004E4970 */
typedef struct V_004E4970 { s32 f0; s32 count; s32 cap; s32 *items; } V_004E4970;
extern s32 func_L39_004E4A50(s32, s32, s32, s32);
extern s32 func_L39_004E48E8(V_004E4970 *, s32);
extern s32 *func_L39_00505780(void);
extern s32 func_L39_005057D0(s32 *, s32 *, s32);

s32 func_L39_004E4970(s32 arg0, s32 *arg1, s32 arg2) {
    V_004E4970 *v = (V_004E4970 *)arg0;
    s32 *item;
    s32 r;
    if (arg2 & 0x10) {
        func_L39_004E4A50(arg0, arg1[0], arg1[1], 0);
    }
    if (v->cap <= v->count) {
        r = func_L39_004E48E8(v, v->count + 4);
        if (r != 0) {
            return r;
        }
    }
    if ((arg2 & 8) == 0) {
        item = func_L39_00505780();
        if (item == 0) {
            return 1;
        }
        r = func_L39_005057D0(item, arg1, arg2);
        if (r != 0) {
            return r;
        }
        arg1 = item;
    }
    v->items[v->count++] = (s32)arg1;
    return 0;
}
/* localdecomp:end func_L39_004E4970 */

INCLUDE_ASM("asm/levels", func_L39_004E4A50);

INCLUDE_ASM("asm/levels", func_L39_004E4AE8);

INCLUDE_ASM("asm/levels", func_L39_004E4BE0);

INCLUDE_ASM("asm/levels", func_L39_004E4C68);

INCLUDE_ASM("asm/levels", func_L39_004E4CA8);

/* localdecomp:start func_L39_004E4F28 */
typedef struct S_004E4F28 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} S_004E4F28;

extern S_004E4F28 *func_L39_004E5090(void);
extern void func_L39_004E5008(S_004E4F28 *);

s32 func_L39_004E4F28(S_004E4F28 *arg0) {
    S_004E4F28 *obj = func_L39_004E5090();

    func_L39_004E5008(obj);
    *obj = *arg0;
    return 0;
}
/* localdecomp:end func_L39_004E4F28 */
