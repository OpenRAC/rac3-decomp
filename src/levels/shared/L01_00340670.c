#include "common.h"

typedef int s128_00341C10 __attribute__((mode(TI)));
typedef union {
    s128_00341C10 q;
    f32 f[4];
} V_00341C10;
typedef struct {
    u8 a;
    u8 b;
    u8 pad[238];
} S_00341C10;
typedef struct {
    u8 pad0[16];
    u8 pos[20];
    s32 active;
    s32 visible;
    s32 target;
} Vars3462F0;
typedef struct {
    char pad0[0x20];
    unsigned char b32;
} Obj;
typedef struct { u8 pad[0x1A]; s16 x1A; } V_347888;
typedef struct { u8 pad[0x68]; V_347888 *x68; } O_347888;

INCLUDE_ASM("asm/levels", func_L01_00340670);

INCLUDE_ASM("asm/levels", func_L01_00340C48);

INCLUDE_ASM("asm/levels", func_L01_00340C68);

INCLUDE_ASM("asm/levels", func_L01_00340DC0);

INCLUDE_ASM("asm/levels", func_L01_00340FB0);

INCLUDE_ASM("asm/levels", func_L01_003411A8);

INCLUDE_ASM("asm/levels", func_L01_003413D0);

INCLUDE_ASM("asm/levels", func_L01_003415F8);

INCLUDE_ASM("asm/levels", func_L01_00341910);

/* localdecomp:start func_L01_003424B0 */



extern s32 D_L01_001D6694;
extern s32 D_L01_001DD25C;
extern u8 D_001A4BE0[];
extern u8 D_001425D6[];
extern S_00341C10 D_L01_002C5600[];
extern f32 func_L01_004C93D8_003424B0(void);
extern s32 func_L01_00343850(f32 t);
extern void func_003C2F58(s32 a, s32 b, void *c);
extern void func_L01_00342640(u8 *self);
extern void func_L01_00342938(u8 *self);
extern void func_L01_00342D18(u8 *self);
extern void func_0038CE20(void *out, void *in, f32 s);
extern void func_0038CE90(void *out, void *a, void *b);
extern void func_0038CF68(void *out, void *in, f32 s);
extern void func_003D9740(void *v, s32 a, s32 b, s32 c, s32 d, f32 e);

void func_L01_003424B0(u8 *self) {
    V_00341C10 arr[4];
    V_00341C10 tmp;
    u8 *v;
    u8 *base;
    f32 t;

    if (D_L01_001D6694 != 0) {
        return;
    }
    v = *(u8 **)(self + 104);
    if (func_L01_00343850(func_L01_004C93D8_003424B0()) == 0) {
        return;
    }
    if (D_L01_001DD25C == 40) {
        return;
    }
    base = D_001A4BE0;
    func_003C2F58(*(s32 *)(base + 9664), 10, v + 48);
    func_L01_00342640(self);
    func_L01_00342938(self);
    func_L01_00342D18(self);
    if ((D_001425D6[0] + D_L01_002C5600)->b < 2) {
        return;
    }
    t = *(f32 *)(v + 64) + 0.1f;
    *(f32 *)(v + 64) = t;
    if (7.0f <= t) {
        *(f32 *)(v + 64) = t - 7.0f;
    }
    arr[3].q = *(s128_00341C10 *)(v + 48);
    arr[3].f[3] = 1.0f;
    arr[0].q = *(s128_00341C10 *)(*(u8 **)(base + 9664) + 192);
    func_0038CE20(&tmp, base + 736, -1.0f);
    func_0038CE90(&arr[1], &arr[0], &tmp);
    func_0038CF68(&arr[1], &arr[1], 1.0f);
    func_0038CE90(&arr[2], &arr[1], &arr[0]);
    func_003D9740(arr, 23, *(s32 *)(v + 8) | 0x1F000000, 10, 1, *(f32 *)(v + 64));
}
/* localdecomp:end func_L01_003424B0 */

INCLUDE_ASM("asm/levels", func_L01_00342640);

INCLUDE_ASM("asm/levels", func_L01_00342938);

INCLUDE_ASM("asm/levels", func_L01_00342D18);

INCLUDE_ASM("asm/levels", func_L01_003430E8);

/* localdecomp:start func_L01_00343650 */
extern s32 D_L01_001DD298;

void func_L01_00343650(void) { D_L01_001DD298 = 0; }
/* localdecomp:end func_L01_00343650 */

INCLUDE_ASM("asm/levels", func_L01_00343658);

INCLUDE_ASM("asm/levels", func_L01_00343850);

/* localdecomp:start func_L01_003438C0 */
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
void func_L01_003438C0(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 104);
    s32 i = *(s32 *)(s0 + 12);
    if (i != -1) {
        u8 *e = D_001A30B0 + (i << 7);
        if (*(u8 **)(e + 220) == a0 && e[208] != 0) {
            func_003A4F28(i);
        }
    }
    *(s32 *)(s0 + 12) = -1;
}
/* localdecomp:end func_L01_003438C0 */

INCLUDE_ASM("asm/levels", func_L01_00343928);

/* localdecomp:start func_L01_00343BA0 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);
void func_L01_00343BA0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_00343BA0 */

INCLUDE_ASM("asm/levels", func_L01_00343BD8);

/* localdecomp:start func_L01_00344A40 */
void func_L01_00344A40(u8 *a) {
    a[32] = 2;
}
/* localdecomp:end func_L01_00344A40 */

LINKER_REMNANT("asm/levels", func_L01_00344A50);

INCLUDE_ASM("asm/levels", func_L01_00344A58);

INCLUDE_ASM("asm/levels", func_L01_00344A88);

LINKER_REMNANT("asm/levels", func_L01_00344C70);

INCLUDE_ASM("asm/levels", func_L01_00344C78);

INCLUDE_ASM("asm/levels", func_L01_00344CA8);

INCLUDE_ASM("asm/levels", func_L01_00344D68);

INCLUDE_ASM("asm/levels", func_L01_00345C08);

/* localdecomp:start func_L01_00346620 */
extern void func_003C2F58(s32 a, s32 b, void *c);
extern void func_L01_00346668(f32 *, f32, f32, f32, f32);

void func_L01_00346620(s32 a) {
    f32 v[4];
    ((void (*)(s32, s32, f32 *))func_003C2F58)(a, 1, v);
    func_L01_00346668(v, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_00346620 */

INCLUDE_ASM("asm/levels", func_L01_00346668);

INCLUDE_ASM("asm/levels", func_L01_00346998);

/* localdecomp:start func_L01_00346C18 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);

extern s32 func_L01_004CB018(s32);
extern s32 func_L01_004CB2D8(void);
extern s32 D_L01_00277080[];

void func_L01_00346C18(u8 *self) {
    Vars3462F0 *v = *(Vars3462F0 **)(self + 104);

    if (v->target != 0) {
        if ((u32)(func_L01_004CB018(v->target) - 1) < 2) {
            v->visible = 0;
        } else if (v->active == 0 || (D_L01_00277080[0] >= 9 && func_L01_004CB2D8() == 0)) {
            v->visible = 0;
        } else {
            v->visible = 1;
        }
    }
    if (v->active != 0 && v->visible != 0) {
        ((void (*)(void *, void *, s32, s32, f32))func_L01_004C70A8)(v, v->pos, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_00346C18 */

INCLUDE_ASM("asm/levels", func_L01_00346CC8);

INCLUDE_ASM("asm/levels", func_L01_00347348);

/* localdecomp:start func_L01_00347640 */
extern void func_0038CF68(void *out, void *in, f32 s);
extern void func_0038CE90(void *dst, void *a, void *b);
void func_L01_00347640(u8 *a0, void *a1) {
    f32 one = 1.0f;
    ((void (*)(f32 s, void *dst, void *src))func_0038CF68)(one, a0 + 192, *(void **)(a0 + 104));
    func_0038CE90(a0 + 208, a0 + 192, a1);
    ((void (*)(f32 s, void *dst, void *src))func_0038CF68)(one, a0 + 208, a0 + 208);
    func_0038CE90(a0 + 224, a0 + 208, a0 + 192);
}
/* localdecomp:end func_L01_00347640 */

INCLUDE_ASM("asm/levels", func_L01_003476D8);

INCLUDE_ASM("asm/levels", func_L01_00347838);

/* localdecomp:start func_L01_00348160 */
void func_L01_00348160(void) {

}
/* localdecomp:end func_L01_00348160 */

/* localdecomp:start func_L01_00348168 */
extern void func_L01_003481F8(O_347888 *o);

extern int func_L01_00348500(Obj *);
extern int func_L01_00348C88(Obj *);
extern int func_L01_00349538(Obj *);
extern void func_L01_00404A10_00348168(void (*)(void), Obj *);
extern void func_003C2880(Obj *);

void func_L01_00348168(Obj *obj) {
    int a = func_L01_00348500(obj);
    int b = func_L01_00348C88(obj);
    int c = func_L01_00349538(obj);

    if (a == 0 && b == 0 && c == 0) {
        if (obj->b32 == 2) {
            func_003C2880(obj);
        }
    } else {
        func_L01_00404A10_00348168(((void (*)(void))func_L01_003481F8), obj);
    }
}
/* localdecomp:end func_L01_00348168 */

/* localdecomp:start func_L01_003481F8 */
extern void func_003C2880(Obj *);
extern s32 func_L01_00457458(s32, s32);
extern void func_L01_00348620(O_347888 *);
extern void func_L01_00348E30(O_347888 *);
extern void func_L01_003495F0(O_347888 *);
void func_L01_003481F8(O_347888 *o) {
    if (func_L01_00457458(3076, o->x68->x1A) == 0) {
        ((void (*)(O_347888 *))func_003C2880)(o);
    } else {
        func_L01_00348620(o);
        func_L01_00348E30(o);
        func_L01_003495F0(o);
    }
}
/* localdecomp:end func_L01_003481F8 */

INCLUDE_ASM("asm/levels", func_L01_00348258);

INCLUDE_ASM("asm/levels", func_L01_00348380);

INCLUDE_ASM("asm/levels", func_L01_00348500);
