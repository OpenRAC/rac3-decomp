#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 116F80.c's earlier functions */
extern void func_0011B240(s32);
extern void func_0013AFE8(s32) __attribute__((noreturn));

typedef struct Reent_116F98 {
    u8 pad0[0xC];
    void *err;
} Reent_116F98;
extern void *D_0013D770[];
extern char D_00150080[];
extern s32 func_00118950(void *, char *, ...);
extern void func_00116F80(void);

/* localdecomp:start func_00116FD0 */
typedef struct At_116FD0 {
    struct At_116FD0 *next;
    s32 ind;
    void (*fns[32])(void);
} At_116FD0;
typedef struct {
    u8 pad148[0x148];
    At_116FD0 *atexit;
    At_116FD0 atexit0;
} Reent_116FD0;
extern void *D_0013D770[];
extern void *func_001194E8(u32);
s32 func_00116FD0(void (*fn)(void)) {
    At_116FD0 *p;
    if ((p = ((Reent_116FD0 *)D_0013D770[0])->atexit) == 0) {
        ((Reent_116FD0 *)D_0013D770[0])->atexit = p = &((Reent_116FD0 *)D_0013D770[0])->atexit0;
    }
    if (p->ind >= 0x20) {
        if ((p = (At_116FD0 *)func_001194E8(0x88)) == 0) {
            return -1;
        }
        p->ind = 0;
        p->next = ((Reent_116FD0 *)D_0013D770[0])->atexit;
        ((Reent_116FD0 *)D_0013D770[0])->atexit = p;
    }
    p->fns[p->ind++] = fn;
    return 0;
}
/* localdecomp:end func_00116FD0 */

/* localdecomp:start func_00117070 */
extern long func_0011BFD8(s32, s32, s32);
s32 func_00117070(s32 a) {
    return func_0011BFD8(a, 0, 10);
}
/* localdecomp:end func_00117070 */

/* localdecomp:start func_00117098 */
extern s32 func_0011A160();
s32 func_00117098(s32 a, s32 b) {
    return func_0011A160(b, a);
}
/* localdecomp:end func_00117098 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001170B8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011716C);

/* localdecomp:start func_001171C8 */
typedef struct Bigint_1171C8 {
    struct Bigint_1171C8 *next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint_1171C8;
extern s32 func_0011ABB8(Bigint_1171C8 *, Bigint_1171C8 *);

s32 func_001171C8(Bigint_1171C8 *b, Bigint_1171C8 *S)
{
    s32 n;
    s32 borrow, y;
    u32 carry, q, ys;
    u32 *bx, *bxe, *sx, *sxe;
    s32 z;
    u32 si, zs;

    n = S->wds;
    if (b->wds < n) {
        return 0;
    }
    sx = S->x;
    sxe = sx + --n;
    bx = b->x;
    bxe = bx + n;
    q = *bxe / (*sxe + 1);
    if (q) {
        borrow = 0;
        carry = 0;
        do {
            si = *sx++;
            ys = (si & 0xFFFF) * q + carry;
            zs = (si >> 16) * q + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xFFFF) - (ys & 0xFFFF) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xFFFF) + borrow;
            borrow = z >> 16;
            ((u16 *)bx)[1] = (u16)z;
            ((u16 *)bx)[0] = (u16)y;
            bx++;
        } while (sx <= sxe);
        if (!*bxe) {
            bx = b->x;
            while (--bxe > bx && !*bxe) {
                --n;
            }
            b->wds = n;
        }
    }
    if (func_0011ABB8(b, S) >= 0) {
        q++;
        borrow = 0;
        carry = 0;
        bx = b->x;
        sx = S->x;
        do {
            si = *sx++;
            ys = (si & 0xFFFF) + carry;
            zs = (si >> 16) + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xFFFF) - (ys & 0xFFFF) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xFFFF) + borrow;
            borrow = z >> 16;
            ((u16 *)bx)[1] = (u16)z;
            ((u16 *)bx)[0] = (u16)y;
            bx++;
        } while (sx <= sxe);
        bx = b->x;
        bxe = bx + n;
        if (!*bxe) {
            while (--bxe > bx && !*bxe) {
                --n;
            }
            b->wds = n;
        }
    }
    return q;
}
/* localdecomp:end func_001171C8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001173F8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011865C);
