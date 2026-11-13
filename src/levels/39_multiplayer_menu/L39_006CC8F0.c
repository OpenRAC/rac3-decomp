#include "common.h"

/* localdecomp:start func_L39_006CC8F0 */
typedef struct { s8 a; s32 b; s32 c; } E_006CC8F0;
typedef struct { u8 pad[0x74]; E_006CC8F0 e[1]; } S_006CC8F0;
void func_L39_006CC8F0(S_006CC8F0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->e[arg1].a = 1;
    arg0->e[arg1].b = arg2;
    arg0->e[arg1].c = arg3;
}
/* localdecomp:end func_L39_006CC8F0 */

/* localdecomp:start func_L39_006CC918 */
void func_L39_006CC918(s32 arg0, s32 arg1) {
    *(s8 *)((u8 *)(((arg1 * 0xC) + arg0)) + 0x74) = 0;
}
/* localdecomp:end func_L39_006CC918 */

/* localdecomp:start func_L39_006CC930 */
typedef struct { s32 id; s32 b; s32 c; u8 flag; } E_006CC930;
typedef struct { u8 a; s32 b; s32 c; } F_006CC930;
typedef struct { u8 pad[0x74]; F_006CC930 e[1]; } S_006CC930;
extern E_006CC930 D_L39_0047F0C0[];
extern s32 func_L39_006D5460(s32, s32);
extern s32 func_L39_006D52D0(s32, s32, s32, s32);
extern void func_L39_006CC2A8(s32, s32, s32);
__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;

s32 func_L39_006CC930(void *arg) {
    S_006CC930 *arg0 = arg;
    s32 obj = *(s32 *)(D_L39_0024D760 + 0x70);
    s32 res = 1;
    s32 i;
    s32 tmp;

    for (i = 0; i < 29 && res; i++) {
        s32 id = D_L39_0047F0C0[i].id;
        if (D_L39_0047F0C0[i].flag && !arg0->e[id].a) {
            res = func_L39_006D5460(obj, D_L39_0047F0C0[id].b);
        }
    }
    {
        s32 j;
        for (j = 0; j < 29 && res; j++) {
            s32 k = D_L39_0047F0C0[j].id;
            if (D_L39_0047F0C0[j].flag && arg0->e[k].a) {
                tmp = 0;
                func_L39_006CC2A8(k, (s32)&tmp, arg0->e[k].c);
                res = func_L39_006D52D0(obj, D_L39_0047F0C0[j].b, arg0->e[k].b, tmp);
            }
        }
    }
    return res;
}
/* localdecomp:end func_L39_006CC930 */

INCLUDE_ASM("asm/levels", func_L39_006CCA88);

LINKER_REMNANT("asm/levels", func_L39_006CCC48);

/* localdecomp:start func_L39_006CCC58 */
void *func_L39_006CCC58(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    (*(s32 *)arg0) = -1;
    *(s8 *)((u8 *)arg0 + 0x2C) = 0;
    *(s8 *)((u8 *)arg0 + 0x2D) = 0;
    *(s8 *)((u8 *)arg0 + 0x2E) = 0;
    *(s8 *)((u8 *)arg0 + 0x2F) = 0;
    *(s8 *)((u8 *)arg0 + 0x30) = 0;
    *(s8 *)((u8 *)arg0 + 0x31) = 0;
    return arg0;
}
/* localdecomp:end func_L39_006CCC58 */

/* localdecomp:start func_L39_006CCC88 */
void func_0011D534(void *, s32, s32);

void func_L39_006CCC88(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    *(s8 *)((u8 *)arg0 + 0x2C) = 0;
    *(s8 *)((u8 *)arg0 + 0x2D) = 0;
    *(s8 *)((u8 *)arg0 + 0x2E) = 0;
    *(s8 *)((u8 *)arg0 + 0x2F) = 0;
    *(s8 *)((u8 *)arg0 + 0x30) = 0;
    *(s8 *)((u8 *)arg0 + 0x31) = 0;
    (*(s32 *)arg0) = -1;
    func_0011D534(arg0 + 0x34, 0, 0x20);
    func_0011D534(arg0 + 0x54, 0, 0xC4);
    func_0011D534(arg0 + 0x118, 0, 0x1C);
}
/* localdecomp:end func_L39_006CCC88 */
