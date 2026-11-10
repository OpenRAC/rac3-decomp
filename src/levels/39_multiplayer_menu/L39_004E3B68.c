#include "common.h"

/* declared by functions of L39_004DF158.c, which this file was cut from */
extern void *func_L39_004BEED8(s32);

/* localdecomp:start func_L39_004E3B68 */
typedef struct N_004E3B68 {
    s32 f[8];
} N_004E3B68;

typedef struct V_004E3B68 {
    s32 _p0[3];
    s32 (*fC)(s32, s32 *, s32, s32, s32, s32);
} V_004E3B68;

typedef struct K_004E3B68 {
    s32 f0;
    s32 f4[21];
    V_004E3B68 *f58;
} K_004E3B68;

typedef struct S_004E3B68 {
    s32 _p0[2];
    K_004E3B68 *f8;
} S_004E3B68;

extern void func_L39_004FC370(N_004E3B68 *);
extern void func_L39_004FC228(N_004E3B68 *);
extern s32 func_L39_004FC158(s32 *);
extern void func_L39_004FC780(s32, u32, N_004E3B68 *);
extern s32 func_L39_004E38F0(N_004E3B68 *, N_004E3B68 *, K_004E3B68 *);
extern s32 func_L39_004FC8C0(N_004E3B68 *, s32);

s32 func_L39_004E3B68(S_004E3B68 *arg0, s32 arg1, s32 arg2, u32 *arg3, u32 arg4, s32 arg5, u32 arg6, s32 arg7) {
    N_004E3B68 a;
    N_004E3B68 b;
    u32 len;
    K_004E3B68 *key;
    s32 ret;
    s32 r;

    ret = 1;
    if (arg1 != 2) {
        return 2;
    }
    func_L39_004FC370(&a);
    func_L39_004FC370(&b);
    key = arg0->f8;
    len = (func_L39_004FC158(key->f4) + 7) / 8;
    if (arg4 >= len) {
        if (len < arg6) {
            ret = 3;
        } else {
            func_L39_004FC780(arg5, arg6, &a);
            if (func_L39_004E38F0(&b, &a, key) == 0) {
                r = func_L39_004FC8C0(&b, arg2);
                if (key->f58->fC(arg2, (s32 *)&len, arg2, r, len, arg7) == 0) {
                    ret = 0;
                    *arg3 = len;
                }
            }
        }
    }
    func_L39_004FC228(&b);
    func_L39_004FC228(&a);
    return ret;
}
/* localdecomp:end func_L39_004E3B68 */

INCLUDE_ASM("asm/levels", func_L39_004E3CB8);

INCLUDE_ASM("asm/levels", func_L39_004E3EB8);

INCLUDE_ASM("asm/levels", func_L39_004E3FC0);

INCLUDE_ASM("asm/levels", func_L39_004E42D8);

INCLUDE_ASM("asm/levels", func_L39_004E43F0);

INCLUDE_ASM("asm/levels", func_L39_004E4568);

/* localdecomp:start func_L39_004E4578 */
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern void func_11D380(void *, void *, s32);

typedef struct S_004E4578 {
    s32 f0;
    s32 f4;
    s32 f8;
    void *fC;
    s32 f10;
    s32 f14;
} S_004E4578;

s32 func_L39_004E4578(S_004E4578 *arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4, s32 arg5) {
    void *p;

    if ((arg5 & 2) && arg3 != 0 && arg4 != 0) {
        p = func_L39_004BEED8(arg4);
        if (p == 0) {
            return 1;
        }
        func_11D380(p, arg3, arg4);
        if (arg0->fC != 0 && (arg0->f14 & 2)) {
            func_L39_004BEF28(arg0->fC);
        }
        arg0->fC = p;
        arg0->f14 |= 2;
    } else {
        if (arg0->fC != 0 && (arg0->f14 & 2)) {
            func_L39_004BEF28(arg0->fC);
        }
        arg0->fC = arg3;
        arg0->f14 &= ~2;
    }
    arg0->f0 = arg1;
    arg0->f4 = arg2;
    arg0->f10 = arg4;
    arg0->f8 = 0;
    return 0;
}
/* localdecomp:end func_L39_004E4578 */

/* localdecomp:start func_L39_004E4688 */
typedef struct S_004E4688 {
    u8 f0[4];
    int f4;
    u8 f8[4];
    void **fC;
} S_004E4688;
extern void *func_L39_004E47A8(void);
extern void func_L39_004E47F8(void *);
extern int func_L39_004E4970(void *, void *, int);

void *func_L39_004E4688(void *a1, S_004E4688 *a2, int a3)
{
    void *v5;
    int v6;
    int v8;
    void *v10;
    if (!a1) {
        v5 = func_L39_004E47A8();
        if (!v5)
            return 0;
    } else {
        v5 = a1;
    }
    v8 = 0;
    v6 = a2->f4;
    if (v6 > 0) {
        do {
            v10 = a2->fC[v8];
            if (v10) {
                if (func_L39_004E4970(v5, v10, a3))
                    goto fail;
                v6 = a2->f4;
            }
            v8++;
        } while (v8 < v6);
    }
    return v5;
fail:
    func_L39_004E47F8(v5);
    return 0;
}
/* localdecomp:end func_L39_004E4688 */

INCLUDE_ASM("asm/levels", func_L39_004E4748);

/* localdecomp:start func_L39_004E47A8 */
extern void *func_L39_004BEED8(s32);
extern void func_0011D534(void *, s32, s32);

/* from rac4-decomp's func_L00_005205A8 (by way of the nonmatching/levels draft) */
void *func_L39_004E47A8(void) {
    void *obj = func_L39_004BEED8(0x18);
    if (obj == 0) {
        return 0;
    }
    func_0011D534(obj, 0, 0x18);
    *(s32 *)((u8 *)obj + 0x14) = 1;
    return obj;
}
/* localdecomp:end func_L39_004E47A8 */

INCLUDE_ASM("asm/levels", func_L39_004E47F8);
