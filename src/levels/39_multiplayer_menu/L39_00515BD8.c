#include "common.h"

/* localdecomp:start func_L39_00515BD8 */
extern void *func_L39_004F7590(s32);
extern void func_L39_004F74E8(void *, s32, s32);

s32 func_L39_00515BD8(void **arg0) {
    void *p;

    p = func_L39_004F7590(12);
    *arg0 = p;
    if (p == 0) {
        return 0x258;
    }
    func_L39_004F74E8(p, 0, 12);
    return 0;
}
/* localdecomp:end func_L39_00515BD8 */

/* localdecomp:start func_L39_00515C28 */
extern void func_L39_00515C70(void *, s32);
extern void func_L39_004F7620(void *);

typedef struct {
    s32 unk0;
    s32 unk4;
    void *unk8;
} S_00515C28;

typedef struct {
    S_00515C28 *p;
} H_00515C28;

s32 func_L39_00515C28(H_00515C28 *arg0) {
    func_L39_00515C70(arg0->p, 0);
    func_L39_004F7620(arg0->p->unk8);
    func_L39_004F7620(arg0->p);
    arg0->p = 0;
    return 0;
}
/* localdecomp:end func_L39_00515C28 */

INCLUDE_ASM("asm/levels", func_L39_00515C70);

/* localdecomp:start func_L39_00515D28 */
extern void *func_L39_004F7590(s32);
extern s32 func_L39_00515E00(s32, s32, void *);
extern void func_L39_004F7620(void *);
s32 func_L39_00515D28(s32 a, s32 b, void **c) {
    void *v;
    s32 r;

    v = func_L39_004F7590(b);
    *c = v;
    if (v == 0) {
        return 0x258;
    }
    r = func_L39_00515E00(a, b, v);
    if (r != 0) {
        func_L39_004F7620(*c);
    }
    return r;
}
/* localdecomp:end func_L39_00515D28 */

INCLUDE_ASM("asm/levels", func_L39_00515DA8);

INCLUDE_ASM("asm/levels", func_L39_00515E00);

INCLUDE_ASM("asm/levels", func_L39_00515E18);

LINKER_REMNANT("asm/levels", func_L39_00515F30);

/* localdecomp:start func_L39_00515F38 */
typedef struct {
    s32 key;
    s32 unk4;
    s32 unk8;
} E_00515F38;

typedef struct {
    u32 count;
    s32 unk4;
    E_00515F38 *items;
} S_00515F38;

E_00515F38 *func_L39_00515F38(S_00515F38 *arg0, s32 arg1) {
    u32 n;
    E_00515F38 *p;
    if (arg1 == 0) return 0;
    n = arg0->count;
    p = arg0->items;
    while (n-- > 0) {
        if (p->key == arg1) return p;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L39_00515F38 */
