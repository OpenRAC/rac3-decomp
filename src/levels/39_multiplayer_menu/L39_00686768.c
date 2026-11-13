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

/* localdecomp:start func_L39_00686810 */
typedef struct S_00686810 {
    u8 pad0[0x108];
    s32 f108;
    u8 pad10C[0x294 - 0x10C];
    s32 f294;
    s32 f298;
} S_00686810;

extern s32 func_L01_00521C90(s32, s32);
extern S_00686810 *func_L39_0068B4D0(s32);
extern S_00686810 *func_L39_0068CDA8(s32);
extern S_00686810 *func_L39_0068D808(s32);
extern S_00686810 *func_L39_0068E160(s32);
extern S_00686810 *func_L39_0068FFD8(s32);
extern S_00686810 *func_L39_00691E60(s32);
extern S_00686810 *func_L39_006932E8(s32);
extern S_00686810 *func_L39_00694E78(s32);
extern S_00686810 *func_L39_00695530(s32);
extern S_00686810 *func_L39_00696308(s32);
extern S_00686810 *func_L39_00698C28(s32);
extern S_00686810 *func_L39_00699838(s32);
extern S_00686810 *func_L39_0069C138(s32);
extern S_00686810 *func_L39_0069D2D8(s32);
extern S_00686810 *func_L39_0069E5C0(s32);
extern S_00686810 *func_L39_0069EB18(s32);
extern S_00686810 *func_L39_0069F650(s32);
extern S_00686810 *func_L39_006A05F8(s32);
extern S_00686810 *func_L39_006A0E80(s32);
extern S_00686810 *func_L39_006A2F50(s32);
extern S_00686810 *func_L39_006A57B0(s32);
extern S_00686810 *func_L39_006A69C0(s32);
extern S_00686810 *func_L39_006A9160(s32);
extern S_00686810 *func_L39_006ABC38(s32);
extern S_00686810 *func_L39_006ACEA8(s32);
extern S_00686810 *func_L39_006AF168(s32);
extern S_00686810 *func_L39_006AF810(s32);
extern S_00686810 *func_L39_006B0728(s32);
extern S_00686810 *func_L39_006B1080(s32);
extern S_00686810 *func_L39_006B2D50(s32);
extern S_00686810 *func_L39_006B3308(s32);
extern S_00686810 *func_L39_006B63B8(s32);
extern S_00686810 *func_L39_006B6CC8(s32);
extern S_00686810 *func_L39_006B9008(s32);
extern S_00686810 *func_L39_006BAB00(s32);
extern S_00686810 *func_L39_006BE7E0(s32);
extern S_00686810 *func_L39_006C4818(s32);
extern S_00686810 *func_L39_006C8050(s32);
extern S_00686810 *func_L39_006C8BE0(s32);
extern S_00686810 *func_L39_006CA2C0(s32);
extern S_00686810 *func_L39_006CAEC8(s32);
extern S_00686810 *func_L39_006CB4D8(s32);
__asm__(".extern D_001DC208_sda, 4");
extern s32 D_001DC208_sda;
__asm__(".extern D_001DC20C_sda, 4");
extern s32 D_001DC20C_sda;

s32 func_L39_00686810(void *arg0, s32 arg1) {
    S_00686810 *r = 0;

    if (arg1 == 0) {
        r = func_L39_0068B4D0(func_L01_00521C90(0x33C, D_001DC208_sda));
    } else if (arg1 == 1) {
        r = func_L39_0068CDA8(func_L01_00521C90(0x2C4, D_001DC208_sda));
    } else if (arg1 == 2) {
        r = func_L39_0068D808(func_L01_00521C90(0x778, D_001DC208_sda));
    } else if (arg1 == 38) {
        r = func_L39_006CAEC8(func_L01_00521C90(0x2B8, D_001DC208_sda));
    } else if (arg1 == 3) {
        r = func_L39_0068E160(func_L01_00521C90(0x3BC, D_001DC208_sda));
    } else if (arg1 == 4) {
        r = func_L39_0068FFD8(func_L01_00521C90(0x27C8, D_001DC208_sda));
    } else if (arg1 == 5) {
        r = func_L39_00691E60(func_L01_00521C90(0x169C, D_001DC208_sda));
    } else if (arg1 == 6) {
        r = func_L39_006932E8(func_L01_00521C90(0x3D8, D_001DC208_sda));
    } else if (arg1 == 7) {
        r = func_L39_00694E78(func_L01_00521C90(0x2BC, D_001DC208_sda));
    } else if (arg1 == 8) {
        r = func_L39_00695530(func_L01_00521C90(0x408, D_001DC208_sda));
    } else if (arg1 == 9) {
        r = func_L39_00696308(func_L01_00521C90(0x4C4, D_001DC208_sda));
    } else if (arg1 == 10) {
        r = func_L39_006C8BE0(func_L01_00521C90(0x4C0, D_001DC208_sda));
    } else if (arg1 == 11) {
        r = func_L39_00698C28(func_L01_00521C90(0x2B8, D_001DC208_sda));
    } else if (arg1 == 12) {
        r = func_L39_00699838(func_L01_00521C90(0x62C, D_001DC208_sda));
    } else if (arg1 == 13) {
        r = func_L39_0069C138(func_L01_00521C90(0x2E0, D_001DC208_sda));
    } else if (arg1 == 42) {
        r = func_L39_0069D2D8(func_L01_00521C90(0x2CC, D_001DC208_sda));
    } else if (arg1 == 41) {
        r = func_L39_0069E5C0(func_L01_00521C90(0x2B0, D_001DC208_sda));
    } else if (arg1 == 14) {
        r = func_L39_006A05F8(func_L01_00521C90(0x2D0, D_001DC208_sda));
    } else if (arg1 == 15) {
        r = func_L39_006A0E80(func_L01_00521C90(0x1644, D_001DC208_sda));
    } else if (arg1 == 16) {
        r = func_L39_006A2F50(func_L01_00521C90(0x340, D_001DC208_sda));
    } else if (arg1 == 17) {
        r = func_L39_006A57B0(func_L01_00521C90(0x1728, D_001DC208_sda));
    } else if (arg1 == 18) {
        r = func_L39_006A69C0(func_L01_00521C90(0x494, D_001DC208_sda));
    } else if (arg1 == 19) {
        r = func_L39_006A9160(func_L01_00521C90(0x3C0, D_001DC208_sda));
    } else if (arg1 == 20) {
        r = func_L39_006AF168(func_L01_00521C90(0x2AC, D_001DC208_sda));
    } else if (arg1 == 21) {
        r = func_L39_006ABC38(func_L01_00521C90(0x2E8, D_001DC208_sda));
    } else if (arg1 == 23) {
        r = func_L39_006ACEA8(func_L01_00521C90(0x3C4, D_001DC208_sda));
    } else if (arg1 == 22) {
        r = func_L39_006AF810(func_L01_00521C90(0x2A8, D_001DC208_sda));
    } else if (arg1 == 24) {
        r = func_L39_006B0728(func_L01_00521C90(0x2B0, D_001DC208_sda));
    } else if (arg1 == 25) {
        r = func_L39_006B1080(func_L01_00521C90(0x2898, D_001DC208_sda));
    } else if (arg1 == 26) {
        r = func_L39_006B2D50(func_L01_00521C90(0x2B0, D_001DC208_sda));
    } else if (arg1 == 27) {
        r = func_L39_006B3308(func_L01_00521C90(0x2F4, D_001DC208_sda));
    } else if (arg1 == 28) {
        r = func_L39_006B63B8(func_L01_00521C90(0x320, D_001DC208_sda));
    } else if (arg1 == 29) {
        r = func_L39_006B6CC8(func_L01_00521C90(0x2C8, D_001DC208_sda));
    } else if (arg1 == 30) {
        r = func_L39_006B9008(func_L01_00521C90(0x2B4, D_001DC208_sda));
    } else if (arg1 == 31) {
        r = func_L39_006BAB00(func_L01_00521C90(0x8768, D_001DC208_sda));
    } else if (arg1 == 33) {
        r = func_L39_006BE7E0(func_L01_00521C90(0x304, D_001DC208_sda));
    } else if (arg1 == 34) {
        r = func_L39_006CB4D8(func_L01_00521C90(0x2C4, D_001DC208_sda));
    } else if (arg1 == 39) {
        r = func_L39_0069F650(func_L01_00521C90(0x2CC, D_001DC208_sda));
    } else if (arg1 == 35) {
        r = func_L39_006C4818(func_L01_00521C90(0xD54, D_001DC208_sda));
    } else if (arg1 == 36) {
        r = func_L39_006C8050(func_L01_00521C90(0x3AC, D_001DC208_sda));
    } else if (arg1 == 40) {
        r = func_L39_0069EB18(func_L01_00521C90(0x2B4, D_001DC208_sda));
    } else if (arg1 == 37) {
        r = func_L39_006CA2C0(func_L01_00521C90(0x6B8, D_001DC208_sda));
    }
    if (r != 0) {
        s32 size = r->f298;
        r->f108 = arg1;
        D_001DC208_sda = r->f294;
        D_001DC20C_sda -= size;
    }
    return (s32)r;
}
/* localdecomp:end func_L39_00686810 */

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

/* localdecomp:start func_L39_006872E8 */
extern u8 D_L39_002479A8[];
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_L39_00687268(void *, s32);
extern void func_L39_00699668(void *, u8 *);
extern void func_L39_00699690_006872E8(void *, s32, f32, s32);
extern s32 func_L39_00699828(void *);

s32 func_L39_006872E8(void *arg0, u8 *s1, u8 *s2, s32 arg3, f32 arg5, s32 arg4) {
    u8 buf[0xD0];
    void *w = *(void **)((u8 *)arg0 + 0x90);

    if (w != 0) {
        if (s1 != 0 && *s1 != 0) {
            if (s2 != 0 && *s2 != 0) {
                func_00120048(buf, D_L39_002479A8, s1, s2);
                func_L39_00699668(w, buf);
            } else {
                func_L39_00699668(w, s1);
            }
        } else if (s2 != 0 && *s2 != 0) {
            func_L39_00699668(w, s2);
        } else {
            return 0;
        }
        func_L39_00699690_006872E8(w, arg3, arg5, arg4);
        func_L39_00687268(arg0, 11);
        return func_L39_00699828(w);
    }
    return 0;
}
/* localdecomp:end func_L39_006872E8 */
