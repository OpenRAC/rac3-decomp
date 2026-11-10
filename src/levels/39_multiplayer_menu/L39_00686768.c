#include "common.h"

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683550;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
} T_00683550;

typedef struct Vt_00685D48 {
    u8 pad_00[0x30];
    s32 (*f30)(void *, void *, void *);
    s32 (*f34)(void *, void *, void *);
} Vt_00685D48;

typedef void (*Fn_00686768)(void *);
typedef struct S_00686768 {
    u8 pad[0x110];
    u8 *arr[1];
} S_00686768;

/* declared by functions of L39_00681758.c, which this file was cut from */
s32 func_L39_00688340(s32, s32, s32);

/* localdecomp:start func_L39_00686768 */
void func_L39_00686768(void *arg0) {
    S_00686768 *s = arg0;
    u8 *self = arg0;
    s32 i;
    s32 n = *(s32 *)(self + 0x270);
    if (n >= 0) {
        u8 *o = s->arr[n];
        u8 *vt = *(u8 **)(o + 0x60);
        Fn_00686768 f = *(Fn_00686768 *)(vt + 0x18);
        f(o);
    }
    for (i = *(s32 *)(self + 0x270) + 1; i <= *(s32 *)(self + 0x274); i++) {
        u8 *o = ((u8 **)(self + 0x110))[i];
        u8 *vt = *(u8 **)(o + 0x60);
        Fn_00686768 f = *(Fn_00686768 *)(vt + 0x18);
        f(o);
    }
}
/* localdecomp:end func_L39_00686768 */

INCLUDE_ASM("asm/levels", func_L39_00686810);

/* localdecomp:start func_L39_00686E40 */
typedef struct Vt_00686E40 {
    u8 pad0[0xEC];
    void (*fEC)(void *);
    void (*fF0)(void *);
} Vt_00686E40;

typedef struct O_00686E40 {
    u8 pad0[0x60];
    Vt_00686E40 *vt;
    u8 pad64[0x29C - 0x64];
    u8 f29C;
} O_00686E40;

typedef struct S_00686E40 {
    u8 pad0[0x64];
    O_00686E40 *menus[(0x110 - 0x64) / 4];
    O_00686E40 *stack[(0x1C0 - 0x110) / 4];
    s32 ids[(0x270 - 0x1C0) / 4];
    s32 cur;
    s32 top;
    s32 f278;
    u8 pad27C[8];
    s32 a;
    s32 b;
    s32 c;
} S_00686E40;

extern s32 D_004AE240[];

void func_L39_00686E40(void *arg0) {
    S_00686E40 *s = arg0;
    s32 i;
    s32 n;

    if (s->a == 0x2C) {
        if (s->top > s->cur) {
            s->stack[s->top]->vt->fF0(s->stack[s->top]);
            s->stack[s->top] = 0;
            s->ids[s->top] = 0x2D;
            s->top--;
        } else if (s->cur >= 0) {
            n = D_004AE240[s->ids[s->cur]];
            s->stack[s->cur]->vt->fF0(s->stack[s->cur]);
            s->stack[s->cur] = 0;
            s->ids[s->cur] = 0x2D;
            if (n != 0x2C) {
                s->cur = 0;
                s->stack[0] = s->menus[n];
                s->ids[0] = n;
            } else {
                s->cur--;
            }
            if (s->cur >= 0) {
                s->stack[s->cur]->f29C = 0;
                s->stack[s->cur]->vt->fEC(s->stack[s->cur]);
            }
        }
        if (s->top <= s->cur) {
            s->top = -1;
        }
    } else if (s->a != 0x2D) {
        if (s->cur >= 0) {
            s->stack[s->cur]->vt->fF0(s->stack[s->cur]);
        }
        if (D_004AE240[s->a] != 0x2C) {
            s->cur = 0;
        } else {
            s->cur++;
            for (i = 0; i < s->cur - 1; i++) {
                if (s->ids[i] == s->a) {
                    s->cur = i;
                    break;
                }
            }
        }
        s->stack[s->cur] = s->menus[s->a];
        s->ids[s->cur] = s->a;
        s->stack[s->cur]->f29C = 0;
        s->stack[s->cur]->vt->fEC(s->stack[s->cur]);
    } else if (s->b != 0x2D) {
        if (s->cur >= 0) {
            s->stack[s->cur]->vt->fF0(s->stack[s->cur]);
        }
        if (D_004AE240[s->b] != 0x2C) {
            s->cur = 0;
        }
        s->stack[s->cur] = s->menus[s->b];
        s->ids[s->cur] = s->b;
        s->stack[s->cur]->f29C = 0;
        s->stack[s->cur]->vt->fEC(s->stack[s->cur]);
    } else if (s->c != 0x2D) {
        if (s->top < s->cur) {
            s->top = s->cur;
        }
        s->top++;
        s->stack[s->top] = s->menus[s->c];
        s->ids[s->top] = s->c;
        s->stack[s->top]->f29C = 1;
        s->stack[s->top]->vt->fEC(s->stack[s->top]);
    }
    if (s->a != 0x2D || s->b != s->a || s->c != s->b) {
        s->f278 = 0;
    }
    s->a = 0x2D;
    s->b = 0x2D;
    s->c = 0x2D;
}
/* localdecomp:end func_L39_00686E40 */

/* localdecomp:start func_L39_00687268 */
extern void func_L39_00686E40(void *);
extern s32 func_L39_00688340(s32, s32, s32);
extern void func_00195410(void);

void func_L39_00687268(void *arg0, s32 arg1) {
    s32 saved;

    *(s32 *)((u8 *)arg0 + 0x28C) = arg1;
    saved = *(s32 *)((u8 *)arg0 + 0x274);
    func_L39_00686E40(arg0);
    func_L39_00688340(0x15, 0, 0);
    do {
        func_00195410();
        (*(void (**)(void *))(*(u8 **)((u8 *)arg0 + 0x60) + 0xE8))(arg0);
        func_L39_00686E40(arg0);
    } while (*(s32 *)((u8 *)arg0 + 0x274) != saved);
    func_L39_00688340(0x14, 0, 0);
}
/* localdecomp:end func_L39_00687268 */

INCLUDE_ASM("asm/levels", func_L39_006872E8);
