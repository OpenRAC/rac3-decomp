#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void *func_003B5388();
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003B5580(void);
extern s32 func_003B5418(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B5350 */
extern s32 func_003E8960();
 
void func_003B5350(void) {
    func_003E8960(0x10);
    func_003E8960(0x11);
}
/* localdecomp:end func_003B5350 */

/* localdecomp:start func_003B5378 */
s32 func_003B5378(void) {
}
/* localdecomp:end func_003B5378 */

/* localdecomp:start func_003B5380 */
s32 func_003B5380(void) {
}
/* localdecomp:end func_003B5380 */

/* localdecomp:start func_003B5388 */
extern s32 func_003E7358(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA160;
extern s32 D_001DA148[2];
extern void func_003B4C30();
extern void func_003B5350(void);
extern void func_003B5088();
extern s32 func_003B5378(void);
extern s32 func_003B5380(void);
void *func_003B5388() {
    if (D_001DA160 == 0) {
        func_003E7358(D_001DA148, (s32)func_003B4C30, (s32)func_003B5350, (s32)func_003B5088, (s32)func_003B5378, (s32)func_003B5380);
        D_001DA160 = 1;
    }
    return D_001DA148;
}
/* localdecomp:end func_003B5388 */

/* localdecomp:start func_003B53E0 */
void func_003B53E0(s32 arg0) {
    func_003B5388(arg0);
}
/* localdecomp:end func_003B53E0 */

/* localdecomp:start func_003B5400 */
extern u8 D_00337690[];
 
void *func_003B5400(s32 i) {
    return D_00337690 + i * 0x9000;
}
/* localdecomp:end func_003B5400 */

/* localdecomp:start func_003B5418 */
typedef struct { void *f0; void *f4; void *(*f8)(void *, void *); void (*fC)(void *, void *); } VT_3AFAA8;
typedef struct { VT_3AFAA8 *vt; } O_3AFAA8;
typedef struct { void *f0; void *f4; void (*f8)(void *, s32); } VT2_3AFAA8;
typedef struct { s32 f0; s32 f4; VT2_3AFAA8 *vt; } P_3AFAA8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_3AFAA8;
extern u8 D_001DA938[];
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern void func_003E7758(s32);
extern s32 func_003E7760();
extern s32 func_003E5CB0();
extern s32 func_003E7078();
extern s32 func_003F2740(s32, s32);
extern s32 func_003EE310();
extern void func_003E6700();
s32 func_003B5418(s32 a0) {
    S_3AFAA8 *q;
    void *x;
    void *s;
    void *w;
    void *e;
    P_3AFAA8 *p;
    O_3AFAA8 *o;
    s32 r = 0;
    x = D_001DA938;
    if (((S_3AFAA8 *)x)->f4 == 0) x = func_003E6FC0();
    s = (void *)func_003E71A0(x);
    func_003E7758(0x30);
    w = (void *)func_003E7760();
    if (s != 0) {
        if (func_003E5CB0(s, a0) == 0) {
            q = (S_3AFAA8 *)D_001DA938;
            if (q->f4 != 0) x = q; else x = func_003E6FC0(q);
            o = (O_3AFAA8 *)func_003E7078(x, 1);
            e = o->vt->f8(o, w);
            if (e != 0) {
                p = (P_3AFAA8 *)func_003EE310(func_003F2740(0x30, (s32)e));
                r = ((s32 (*)())func_003E6700)(s, p, a0) != 0;
                if (r == 0) {
                    p->vt->f8(p, 2);
                    q = (S_3AFAA8 *)D_001DA938;
                    if (q->f4 != 0) x = q; else x = func_003E6FC0(q);
                    o = (O_3AFAA8 *)func_003E7078(x, 1);
                    o->vt->fC(o, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003B5418 */

/* localdecomp:start func_003B5580 */
extern s32 func_003E7358(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA180;
extern s32 D_001DA168[2];
extern void func_003B55D8();
extern void func_003B5B80(void);
extern void func_003B5890();
extern void func_003B5BC8(void);
extern void func_003B5BE8(void);
s32 func_003B5580(void) {
    if (D_001DA180 == 0) {
        func_003E7358(D_001DA168, (s32)func_003B55D8, (s32)func_003B5B80, (s32)func_003B5890, (s32)func_003B5BC8, (s32)func_003B5BE8);
        D_001DA180 = 1;
    }
    return (s32)D_001DA168;
}
/* localdecomp:end func_003B5580 */
