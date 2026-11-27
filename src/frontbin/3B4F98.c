#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003B5060(s32);
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
