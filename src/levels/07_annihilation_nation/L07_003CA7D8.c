#include "common.h"

/* localdecomp:start func_L07_003CA7D8 */
void func_L01_004450F0(void *, s32, s32);
s32 func_L01_004561B8(void *);
s32 func_L07_003CA8A0(void *);
void func_L07_003CA918(void *);
void func_L07_003CAA48(void *);

void func_L07_003CA7D8(void *arg0) {
    u8 temp_v1;

    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    switch (temp_v1) {                              /* irregular */
    case 1:
        if (func_L01_004561B8(arg0) != 0) {
            func_L07_003CAA48(arg0);
        }
        if (func_L07_003CA8A0(arg0) != 0) {
            func_L01_004450F0(arg0, 2, -1);
            return;
        }
        return;
    case 2:
        if (func_L01_004561B8(arg0) != 0) {
            func_L07_003CA918(arg0);
        }
        if (func_L07_003CA8A0(arg0) == 0) {
            func_L01_004450F0(arg0, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L07_003CA7D8 */

/* localdecomp:start func_L07_003CA8A0 */
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
s32 func_L07_003B28B8(void *);

s32 func_L07_003CA8A0(void *arg0) {
    s32 i;
    s32 *p = *(s32 **)((char *)arg0 + 0x68);
    for (i = 0; i < 2; i++, p++) {
        if (*p == -1) {
            return 0;
        }
        if (func_L07_003B28B8(D_L07_001DF41C + (*p << 8)) == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L07_003CA8A0 */

/* localdecomp:start func_L07_003CA918 */
extern u16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern u8 *D_001DF41C;
extern s32 D_L07_001DF458;
extern s32 func_L07_003BAC58(u8 *);

void func_L07_003CA918(void *arg0) {
    u8 *a0 = arg0;
    u8 *s = *(u8 **)(a0 + 0x68);
    u16 *p;
    u8 *e;

    if (*(s32 *)(s + 8) != -1) {
        e = D_001DF41C + (*(s32 *)(s + 8) << 8);
        if (func_L07_003BAC58(e) == 0) {
            *(s32 *)(e + 0x98) = 0;
            e[0x31] = 0;
            *(u16 *)(e + 0x34) |= 3;
        }
    }
    if (*(s32 *)(s + 0xC) == -1) return;
    p = D_L07_0021C020[*(s32 *)(s + 0xC)];
    while ((*(s32 *)(s + 0xC) & 0xFF) != 0xFF && *(s32 *)(s + 0xC) <= D_L07_001DF458 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L07_0021C020[*(s32 *)(s + 0xC)])) {
        e = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (func_L07_003BAC58(e) == 0) {
            *(s32 *)(e + 0x98) = 0;
            e[0x31] = 0;
            *(u16 *)(e + 0x34) |= 3;
        }
        p++;
    }
}
/* localdecomp:end func_L07_003CA918 */

INCLUDE_ASM("asm/levels", func_L07_003CAA48);
