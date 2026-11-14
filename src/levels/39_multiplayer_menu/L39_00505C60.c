#include "common.h"

/* localdecomp:start func_L39_00505C60 */
typedef struct {
    s32 f0;
    s32 *f4;
} S_00505C60;

s32 func_L39_004EEFF0(s32, s32);

s32 func_L39_00505C60(S_00505C60 *arg0, s32 arg1) {
    s32 n = arg0->f0;
    s32 i;

    for (i = 0; i < n; i++) {
        if (arg0->f4[i] == arg1) {
            return func_L39_004EEFF0((s32)arg0, i);
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00505C60 */

/* localdecomp:start func_L39_00505CC0 */
typedef struct {
    s32 count;
    void **items;
} S_00505CC0;

extern void *func_L39_004CC800(void *);
extern s32 func_L39_004F16C0(void *, void *);

void *func_L39_00505CC0(S_00505CC0 *list, void *key) {
    s32 i;
    void *e;

    for (i = 0; i < list->count; i++) {
        e = list->items[i];
        if (func_L39_004F16C0(func_L39_004CC800(e), key) == 0) {
            return e;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00505CC0 */

/* localdecomp:start func_L39_00505D50 */
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);

typedef struct S_00505D50 S_00505D50;
typedef struct {
    s32 f0;
    s32 (*init)(S_00505D50 *);
} T_00505D50;
struct S_00505D50 {
    s32 f0;
    s32 f4;
    T_00505D50 *type;
    s32 fC;
    s32 f10;
};

S_00505D50 *func_L39_00505D50(T_00505D50 *type) {
    S_00505D50 *o = func_L39_004BEED8(sizeof(S_00505D50));

    if (o == 0) {
        return 0;
    }
    o->f0 = 0;
    o->f4 = 0;
    o->type = type;
    o->fC = 0;
    o->f10 = 0;
    if (type->init != 0 && type->init(o) == 0) {
        func_L39_004BEF28(o);
        return 0;
    }
    return o;
}
/* localdecomp:end func_L39_00505D50 */

/* localdecomp:start func_L39_00505DD0 */
/* the free of func_L39_00505D50's object: the type's free hook (+8), then the memory */
typedef struct S_00505DD0 S_00505DD0;
typedef struct {
    s32 f0;
    s32 (*init)(S_00505DD0 *);
    void (*free)(S_00505DD0 *);
} T_00505DD0;
struct S_00505DD0 {
    s32 f0;
    s32 f4;
    T_00505DD0 *type;
};

void func_L39_00505DD0(S_00505DD0 *o) {
    if (o == 0) {
        return;
    }
    if (o->type != 0 && o->type->free != 0) {
        o->type->free(o);
    }
    func_L39_004BEF28(o);
}
/* localdecomp:end func_L39_00505DD0 */

INCLUDE_ASM("asm/levels", func_L39_00505E28);

INCLUDE_ASM("asm/levels", func_L39_00505E68);

/* localdecomp:start func_L39_00505EA8 */
typedef s32 (*Fn_00505EA8)(void *, s32, void *, void *);

s32 func_L39_00505EA8(void *arg0, s32 arg1, void *arg2, void *arg3) {
    void *p = *(void **)((u8 *)arg0 + 8);
    Fn_00505EA8 fn;

    if (p == 0 || (fn = *(Fn_00505EA8 *)((u8 *)p + 0x18)) == 0 || *(s32 *)((u8 *)arg0 + 4) != 0) {
        return 0;
    }
    return fn(arg0, arg1, arg2, arg3);
}
/* localdecomp:end func_L39_00505EA8 */

INCLUDE_ASM("asm/levels", func_L39_00505EE8);

INCLUDE_ASM("asm/levels", func_L39_00505F88);

INCLUDE_ASM("asm/levels", func_L39_00505FA8);

/* localdecomp:start func_L39_00505FC8 */
/* OpenSSL's X509_STORE_add_cert (lhash version): lh_insert, lh_delete, X509err, CRYPTO_w_lock */
typedef struct {
    s32 type;
    void *data;
} S_00505FC8;
extern u8 D_L39_00479638[];
void *func_L39_004BEED8(s32);
void func_L39_004BEF28(void *);
void func_L39_004BC6C8(s32, s32, s32, s32, s32);
void func_L39_004BECC0(s32, s32, void *, s32);
void func_L39_00505F88(S_00505FC8 *);
void func_L39_00505FA8(S_00505FC8 *);
void *func_L39_004BCC38(void *, void *);
void *func_L39_004BCD28(void *, void *);
s32 func_L39_00505FC8(u8 *ctx, void *x) {
    S_00505FC8 *obj;
    S_00505FC8 *r;
    s32 ret = 1;

    if (x == 0) {
        return 0;
    }
    obj = func_L39_004BEED8(sizeof(S_00505FC8));
    if (obj == 0) {
        func_L39_004BC6C8(0xB, 0xE8, 0x21, 0, 0);
        return 0;
    }
    obj->type = 1;
    obj->data = x;
    func_L39_004BECC0(9, 0xB, D_L39_00479638, 0x48);
    func_L39_00505F88(obj);
    r = func_L39_004BCC38(*(void **)(ctx + 4), obj);
    if (r != 0) {
        func_L39_004BCD28(*(void **)(ctx + 4), obj);
        func_L39_00505FA8(obj);
        func_L39_004BEF28(obj);
        func_L39_004BCC38(*(void **)(ctx + 4), r);
        func_L39_004BC6C8(0xB, 0xE8, 0x9B, 0, 0);
        ret = 0;
    }
    func_L39_004BECC0(10, 0xB, D_L39_00479638, 0x57);
    return ret;
}
/* localdecomp:end func_L39_00505FC8 */

LINKER_REMNANT("asm/levels", func_L39_005060E8);

/* localdecomp:start func_L39_005060F8 */
extern s32 func_L39_004E5108(void);
extern s32 func_L39_004E4C68(s32);
extern void func_L39_004E5210(s32, s32, s32, s32);
extern s32 func_L39_004E51C0(s32, s32);
extern void func_L39_004E5168(s32);

s32 func_L39_005060F8(s32 *arg0) {
    s32 a = func_L39_004E5108();
    s32 b = func_L39_004E5108();
    s32 r;

    func_L39_004E4C68(a);
    if (arg0[1] == 0x17) {
        func_L39_004E5210(arg0[2], arg0[0], 1, b);
    }
    r = func_L39_004E51C0(b, a);
    func_L39_004E5168(b);
    func_L39_004E5168(a);
    return r;
}
/* localdecomp:end func_L39_005060F8 */

LINKER_REMNANT("asm/levels", func_L39_00506188);
