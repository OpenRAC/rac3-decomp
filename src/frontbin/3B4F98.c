#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3B3750.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_00381FF0();
extern void func_11B2E8();
extern void *func_003B4FD0();
extern s32 func_003B51C8(void);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E81F0(s32, f32, f32);
extern void *func_003B42F8(s32 arg0);

/* localdecomp:start func_003B4F98 */
extern s32 func_003E85A8();
 
void func_003B4F98(void) {
    func_003E85A8(0x10);
    func_003E85A8(0x11);
}
/* localdecomp:end func_003B4F98 */

/* localdecomp:start func_003B4FC0 */
s32 func_003B4FC0(void) {
}
/* localdecomp:end func_003B4FC0 */

/* localdecomp:start func_003B4FC8 */
s32 func_003B4FC8(void) {
}
/* localdecomp:end func_003B4FC8 */

/* localdecomp:start func_003B4FD0 */
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA160;
extern s32 D_001DA148[2];
extern void func_003B4878();
extern void func_003B4F98(void);
extern void func_003B4CD0();
extern s32 func_003B4FC0(void);
extern s32 func_003B4FC8(void);
void *func_003B4FD0() {
    if (D_001DA160 == 0) {
        func_003E6FA0(D_001DA148, (s32)func_003B4878, (s32)func_003B4F98, (s32)func_003B4CD0, (s32)func_003B4FC0, (s32)func_003B4FC8);
        D_001DA160 = 1;
    }
    return D_001DA148;
}
/* localdecomp:end func_003B4FD0 */

/* localdecomp:start func_003B5028 */
void func_003B5028(s32 arg0) {
    func_003B4FD0(arg0);
}
/* localdecomp:end func_003B5028 */

/* localdecomp:start func_003B5048 */
extern u8 D_00337690[];
 
void *func_003B5048(s32 i) {
    return D_00337690 + i * 0x9000;
}
/* localdecomp:end func_003B5048 */

/* localdecomp:start func_003B5060 */
typedef struct { void *f0; void *f4; void *(*f8)(void *, void *); void (*fC)(void *, void *); } VT_3AFAA8;
typedef struct { VT_3AFAA8 *vt; } O_3AFAA8;
typedef struct { void *f0; void *f4; void (*f8)(void *, s32); } VT2_3AFAA8;
typedef struct { s32 f0; s32 f4; VT2_3AFAA8 *vt; } P_3AFAA8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_3AFAA8;
extern u8 D_001DA938[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern void func_003E73A0(s32);
extern s32 func_003E73A8();
extern s32 func_003E58F8();
extern s32 func_003E6CC0();
extern s32 func_003F2388(s32, s32);
extern s32 func_003EDF58();
extern void func_003E6348();
s32 func_003B5060(s32 a0) {
    S_3AFAA8 *q;
    void *x;
    void *s;
    void *w;
    void *e;
    P_3AFAA8 *p;
    O_3AFAA8 *o;
    s32 r = 0;
    x = D_001DA938;
    if (((S_3AFAA8 *)x)->f4 == 0) x = func_003E6C08();
    s = (void *)func_003E6DE8(x);
    func_003E73A0(0x30);
    w = (void *)func_003E73A8();
    if (s != 0) {
        if (func_003E58F8(s, a0) == 0) {
            q = (S_3AFAA8 *)D_001DA938;
            if (q->f4 != 0) x = q; else x = func_003E6C08(q);
            o = (O_3AFAA8 *)func_003E6CC0(x, 1);
            e = o->vt->f8(o, w);
            if (e != 0) {
                p = (P_3AFAA8 *)func_003EDF58(func_003F2388(0x30, (s32)e));
                r = ((s32 (*)())func_003E6348)(s, p, a0) != 0;
                if (r == 0) {
                    p->vt->f8(p, 2);
                    q = (S_3AFAA8 *)D_001DA938;
                    if (q->f4 != 0) x = q; else x = func_003E6C08(q);
                    o = (O_3AFAA8 *)func_003E6CC0(x, 1);
                    o->vt->fC(o, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003B5060 */

/* localdecomp:start func_003B51C8 */
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA180;
extern s32 D_001DA168[2];
extern void func_003B5220();
extern void func_003B57C8(void);
extern void func_003B54D8();
extern void func_003B5810(void);
extern void func_003B5830(void);
s32 func_003B51C8(void) {
    if (D_001DA180 == 0) {
        func_003E6FA0(D_001DA168, (s32)func_003B5220, (s32)func_003B57C8, (s32)func_003B54D8, (s32)func_003B5810, (s32)func_003B5830);
        D_001DA180 = 1;
    }
    return (s32)D_001DA168;
}
/* localdecomp:end func_003B51C8 */

extern s32 D_001D89BC;
extern s32 D_001D89E4;
extern u8 D_0037F880[];
extern f32 D_001D9698_003B5220;
extern void func_003B5B38();
extern void func_0038E150(s32);
extern s32 func_00381FF0();
extern s32 func_0038E548(f32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E81F0(s32, f32, f32);
extern void func_003B5858();
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7928(s32, s32, s32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E7A18(s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);
extern void func_003B5D70();
INCLUDE_ASM("asm/nonmatchings/text", func_003B5220);

typedef struct { u8 p[0x1C0]; u32 f1C0; u32 f1C4; } P_3AFF20;
extern s32 D_001D89E4;
extern s32 D_001D89E8;
extern s32 D_001D89EC;
extern s32 D_001D89B0;
extern s32 D_001D89B4;
extern s32 D_001D89FC;
extern s32 D_001D5520_003B54D8;
extern s32 D_001D5520_g_003B54D8;
extern P_3AFF20 *D_001D52FC_003B54D8;
extern P_3AFF20 *D_001D52FC_g_003B54D8;
extern u8 D_0037F690[];
extern char D_001D89F0[];
extern s32 func_003B97B0(void);
extern s32 func_003B96D0(void);
extern s32 func_003B9700();
extern void func_003B96D8();
extern void func_003B6438(void);
extern void func_003B9890(void);
extern void func_00391408(s32, s32, s32);
extern void func_003BA4F8(void *, s32);
extern void func_11B2E8();
/* localdecomp:start func_003B54D8 */
extern s32 D_001D89E4;
extern s32 D_001D89E8;
extern s32 D_001D89EC;
extern s32 D_001D89B0;
extern s32 D_001D89B4;
extern s32 D_001D89FC;
extern s32 D_001D5520_003B54D8 __attribute__((section(".data")));
extern s32 D_001D5520_g_003B54D8;
extern P_3AFF20 *D_001D52FC_003B54D8 __attribute__((section(".data")));
extern P_3AFF20 *D_001D52FC_g_003B54D8;
extern u8 D_0037F690[];
extern char D_001D89F0[];
extern s32 func_003B97B0(void);
extern s32 func_003B96D0(void);
extern s32 func_003B9700();
extern void func_003B96D8();
extern void func_003B6438(void);
extern void func_003B9890(void);
extern void func_00391408(s32, s32, s32);
extern void func_003BA4F8(void *, s32);
extern void func_003B5CD8(void);
extern void func_003B5BC0(s32, s32);
extern void func_11B2E8();
extern s32 *func_003B9BD0(s32);
extern void func_003B6018(void);
void func_003B54D8(s32 a0) {
    switch (D_001D89E4) {
    case 1:
        if (func_003B97B0() != 0) break;
        switch (func_003B96D0()) {
        case 1: {
            u8 *buf; char *fmt;
            s32 x, y, z;
            D_001D89EC = D_001D89B0;
            D_001D89E8 = D_001D89B4;
            buf = D_0037F690;
            fmt = D_001D89F0;
            x = func_00381FF0(0x511);
            y = func_00381FF0(0x512);
            z = func_00381FF0(0x513);
            func_11B2E8(buf, fmt, x, y, D_001D89EC, z);
            {
                s32 w = func_00381FF0(0x8E3);
                func_003B9700(0, w, func_00381FF0(0x8DF), buf, 0);
            }
            func_003B96D8(0x20, 0x10);
            D_001D89E4 = 2;
            break;
        }
        case 2:
            D_001D89E4 = 0;
            break;
        }
        break;
    case 2:
        D_001D5520_g_003B54D8 = D_001D5520_003B54D8 == 0;
        func_003B6438();
        D_001D89E4 = 3;
        break;
    case 3: {
        u8 *buf; char *fmt;
        s32 x, y, z;
        buf = D_0037F690;
        fmt = D_001D89F0;
        x = func_00381FF0(0x511);
        y = func_00381FF0(0x512);
        z = func_00381FF0(0x513);
        func_11B2E8(buf, fmt, x, y, D_001D89EC, z);
        if (func_003B97B0() == 0) {
            switch (func_003B96D0()) {
            case 1:
                D_001D89E4 = 0;
                break;
            case 2:
                D_001D89E4 = 4;
                break;
            }
        } else {
            if (--D_001D89E8 > 0) break;
            if (--D_001D89EC <= 0) {
                ((s32 (*)(void))func_003B9890)();
                D_001D89E4 = 4;
            }
            D_001D89E8 = D_001D89B4;
        }
        break;
    }
    case 4:
        D_001D5520_g_003B54D8 = D_001D5520_003B54D8 == 0;
        func_003B6438();
        D_001D89E4 = 0;
        break;
    case 5: {
        u32 bits;
        if (func_003B97B0() == 0) {
            D_001D89E4 = 0;
            break;
        }
        bits = D_001D52FC_g_003B54D8->f1C0;
        if (bits & 0xF000) {
            s32 dx, dy;
            u32 q;
            if (++D_001D89FC < 3) break;
            D_001D89FC = 0;
            if (bits & 0x8000) dx = -2;
            else dx = (bits & 0x2000) ? 2 : 0;
            q = D_001D52FC_003B54D8->f1C0;
            if (q & 0x1000) dy = -1;
            else if (q & 0x4000) dy = 1;
            else dy = 0;
            func_00391408(dx, dy, 1);
        }
        break;
    }
    case 0: {
        s32 b = D_001D52FC_003B54D8->f1C4;
        func_003BA4F8(func_003B9BD0(0), b);
        func_003B5CD8();
        func_003B5BC0(a0, b);
        func_003B6018();
        break;
    }
    }
}
/* localdecomp:end func_003B54D8 */

/* localdecomp:start func_003B57C8 */
extern s32 func_003E85A8();
extern void func_003B5B90(void);
extern s32 func_003A2750(s32);
extern void func_003B9890(void);
void func_003B57C8(void) {
    func_003E85A8(0x10);
    func_003E85A8(0x11);
    func_003E85A8(0x14);
    func_003B5B90();
    func_003A2750(1);
    func_003B9890();
}
/* localdecomp:end func_003B57C8 */

/* localdecomp:start func_003B5810 */
void func_003B5810(void) {
    func_00381D38();
}
/* localdecomp:end func_003B5810 */

/* localdecomp:start func_003B5830 */
extern s32 func_00381D40(void);
extern void func_003B98A0();
 
void func_003B5830(void) {
    func_00381D40();
    func_003B98A0();
}
/* localdecomp:end func_003B5830 */
