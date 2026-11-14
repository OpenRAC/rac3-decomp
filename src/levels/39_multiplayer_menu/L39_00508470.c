#include "common.h"

/* localdecomp:start func_L39_00508470 */
s32 func_L39_00508470(void *arg0, s32 (**arg1)(void *, s32), s32 arg2) {
    if (arg0 == 0) {
        return 0x212;
    }
    if (*(s32 *)((u8 *)arg0 + 0xC) != 0) {
        return 0x20E;
    }
    return (*arg1)(arg0, arg2);
}
/* localdecomp:end func_L39_00508470 */

/* localdecomp:start func_L39_005084A8 */
s32 func_L39_004F5F38(void);
s32 func_L39_004F5EA0(void *, void *, s32);

typedef struct {
    s32 unk0;
    s32 (*unk4)(void *, void *);
} S_005084A8;

s32 func_L39_005084A8(void *arg0, s32 *arg1, S_005084A8 *arg2) {
    s32 ret;

    if (arg0 == 0) {
        return 0x212;
    }
    if (*(s32 *)((u8 *)arg0 + 0xC) == 0) {
        return 0x211;
    }
    if (func_L39_004F5F38() == 0) {
        return 0;
    }
    ret = arg2->unk4(arg1, arg0);
    if (ret != 0) {
        return ret;
    }
    return func_L39_004F5EA0(arg0, arg2, *arg1);
}
/* localdecomp:end func_L39_005084A8 */

/* localdecomp:start func_L39_00508540 */
extern s32 func_L39_004F6060(void *, s32 **, s32);
extern u8 D_L39_0046E9C8[];

s32 func_L39_00508540(void *arg0, s32 arg1, s32 arg2)
{
    s32 *p;
    s32 r;

    r = func_L39_004F6060(arg0, &p, 8);
    if (r != 0) {
        return r;
    }
    p[0] = arg1;
    p[1] = arg2;
    return ((s32 (*)(void *, void *, s32 *))func_L39_004F5EA0)(arg0, D_L39_0046E9C8, p);
}
/* localdecomp:end func_L39_00508540 */

/* localdecomp:start func_L39_005085B0 */
void func_L39_005085B0(u8 *arg0) {
    u32 i;

    for (i = 0; i < 8; i++) {
        u8 *p = arg0 + i;
        u32 n = 0;
        u32 mask = 0x80;
        u8 b = *p;

        do {
            if (b & mask) {
                n++;
            }
            mask >>= 1;
        } while (mask >= 2);
        if (n & 1) {
            *p &= 0xFE;
        } else {
            *p |= 1;
        }
    }
}
/* localdecomp:end func_L39_005085B0 */

/* localdecomp:start func_L39_00508620 */
void func_L39_004F7510(void *, void *, s32);
s32 func_L39_004F7560(void *, void *, s32);
extern void func_L39_004F74E8(void *, s32, s32);

s32 func_L39_00508620(void *arg0) {
    u8 buf[8];
    s32 ret;

    func_L39_004F7510(buf, arg0, 8);
    func_L39_005085B0(buf);
    if (func_L39_004F7560(buf, arg0, 8) != 0) {
        ret = 0x21E;
    } else {
        ret = 0;
    }
    func_L39_004F74E8(buf, 0, 8);
    return ret;
}
/* localdecomp:end func_L39_00508620 */

INCLUDE_ASM("asm/levels", func_L39_00508688);

INCLUDE_ASM("asm/levels", func_L39_00508758);

/* localdecomp:start func_L39_005088D0 */
extern u8 D_L39_0046F010[];

s32 func_L39_005088D0(void ***list, void ***arr, void *key, s32 *out) {
    s32 i;
    s32 found;
    void *t;

    i = 0;
    found = 0;
    for (; *list != 0; list++, i++) {
        t = **list;
        if (t == key) {
            found++;
        }
        if (t == D_L39_0046F010) {
            break;
        }
    }
    if (found == 0) {
        return 0;
    }
    found += i + 2;
    i = 0;
    if (arr != 0) {
        for (; arr[i] != 0; i++) {
        }
        if (*arr[i - 1] == D_L39_0046F010) {
            return 0;
        }
    }
    *out = i;
    return found;
}
/* localdecomp:end func_L39_005088D0 */
