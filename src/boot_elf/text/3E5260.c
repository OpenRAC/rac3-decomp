#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003E5898(s32);
extern void func_003E5428(f32 *, f32);
extern s32 func_003E5448(s32);
extern s32 func_003E55B0(s32);
extern s32 func_003E5718(s32);
/* --- end of declarations from other files --- */

/* declarations of 3E50C8.c's earlier functions */
extern s32 D_001D9550;
extern s32 func_003E7BF0(s32, s32, s32);
typedef struct { s32 x0, x4, x8, xC; } S_3DF038;
extern u8 D_001D9554;
extern S_3DF038 D_001DA938[];
extern void func_003E41F8(void);
extern u8 D_001D9566;
extern s32 func_003E52E8(s32);
extern void func_003E5260();

/* localdecomp:start func_003E5260 */
extern s32 D_001D9550;
extern u8 D_001D9566;
extern void func_003E5128(s32);
extern void func_003E41F8(void);
extern void func_003E47F8(void);
extern void func_003E48C0(void);
extern s32 func_003E7BF0(s32, s32, s32);
void func_003E5260(void) {
    if (D_001D9550 != 0 && D_001D9566 == 0) {
        D_001D9550--;
        func_003E5128(0x90000);
        func_003E41F8();
        func_003E47F8();
        func_003E48C0();
    } else {
        func_003E7BF0(0x90000, 1, 0);
    }
}
/* localdecomp:end func_003E5260 */

/* localdecomp:start func_003E52C8 */
extern u8 D_001D9554;
extern s32 func_003E8960();
void func_003E52C8(void) {
    D_001D9554 = 0;
    func_003E8960(7);
}
/* localdecomp:end func_003E52C8 */

/* localdecomp:start func_003E52E8 */
typedef struct { u8 b[16]; } V16_3DF9E0;
extern void func_003E4940(s32);
extern void func_003E52C8(void);
extern void func_003E5260(void);
extern s32 func_003E7358(s32 *, s32, s32, s32, s32, s32);
extern s32 D_001DA780;
extern s32 D_001DA7A0;
extern s32 D_001DA7C0;
extern s32 D_001DA7E0;
extern s32 D_001DA768[2];
extern s32 D_001DA788[2];
extern s32 D_001DA7A8[2];
extern s32 D_001DA7C8[2];
extern V16_3DF9E0 D_001D9568[];
s32 func_003E52E8(s32 idx) {
    V16_3DF9E0 v;
    if (D_001DA780 == 0) {
        func_003E7358(D_001DA768, (s32)func_003E4940, (s32)func_003E52C8, (s32)func_003E5260, 0, 0);
        D_001DA780 = 1;
    }
    if (D_001DA7A0 == 0) {
        func_003E7358(D_001DA788, (s32)func_003E4940, (s32)func_003E52C8, (s32)func_003E5260, 0, 0);
        D_001DA7A0 = 1;
    }
    if (D_001DA7C0 == 0) {
        func_003E7358(D_001DA7A8, (s32)func_003E4940, (s32)func_003E52C8, (s32)func_003E5260, 0, 0);
        D_001DA7C0 = 1;
    }
    if (D_001DA7E0 == 0) {
        func_003E7358(D_001DA7C8, (s32)func_003E4940, (s32)func_003E52C8, (s32)func_003E5260, 0, 0);
        D_001DA7E0 = 1;
    }
    v = D_001D9568[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_003E52E8 */

/* localdecomp:start func_003E5428 */
void func_003E5428(f32 *p, f32 a) {
    *p = (a < *p) ? a : *p;
}
/* localdecomp:end func_003E5428 */

/* localdecomp:start func_003E5448 */
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E7078();
extern s32 func_003E5CB0();
extern void func_003E6700(void **, s32, s32);
extern void *func_003F2060();
extern s32 func_003F2740();
extern void func_003E7758(s32);
extern s32 func_003E7760();
s32 func_003E5448(s32 a) {
    S_3DF038 *p;
    S_3DF038 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA938;
    if (!q->x4) q = func_003E6FC0();
    obj = func_003E71A0(q);
    func_003E7758(0x48);
    vv = func_003E7760();
    if (obj != 0) {
        if (func_003E5CB0(obj, a) == 0) {
            p = D_001DA938;
            if (p->x4) q = p;
            else q = func_003E6FC0(p);
            t1 = func_003E7078(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003F2060(func_003F2740(0x48, e));
                r = ((s32 (*)())func_003E6700)(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA938;
                    if (p->x4) q = p;
                    else q = func_003E6FC0(p);
                    w = func_003E7078(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E5448 */

/* localdecomp:start func_003E55B0 */
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E7078();
extern s32 func_003E5CB0();
extern void func_003E6700(void **, s32, s32);
extern void *func_003EF4C8();
extern s32 func_003F2740();
extern void func_003E7758(s32);
extern s32 func_003E7760();
s32 func_003E55B0(s32 a) {
    S_3DF038 *p;
    S_3DF038 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA938;
    if (!q->x4) q = func_003E6FC0();
    obj = func_003E71A0(q);
    func_003E7758(0x54);
    vv = func_003E7760();
    if (obj != 0) {
        if (func_003E5CB0(obj, a) == 0) {
            p = D_001DA938;
            if (p->x4) q = p;
            else q = func_003E6FC0(p);
            t1 = func_003E7078(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003EF4C8(func_003F2740(0x54, e));
                r = ((s32 (*)())func_003E6700)(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA938;
                    if (p->x4) q = p;
                    else q = func_003E6FC0(p);
                    w = func_003E7078(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E55B0 */

/* localdecomp:start func_003E5718 */
typedef struct { u8 pad[8]; s32 (*f8)(); s32 (*fC)(); } VT_3DFE10;
typedef struct { VT_3DFE10 *vt; } O_3DFE10;
typedef struct { u8 pad[8]; VT_3DFE10 *vt; } D_3E5718;
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern void func_003E7758(s32);
extern s32 func_003E7760(void);
extern s32 func_003E5CB0();
extern s32 func_003E7078();
extern s32 func_003F2740(s32, s32);
extern void *func_003F02D0();
extern void func_003E6700(void **, s32, s32);
s32 func_003E5718(s32 arg0) {
    S_3DF038 *p;
    S_3DF038 *q;
    s32 a, b, c, r;
    D_3E5718 *d;
    O_3DFE10 *o;
    r = 0;
    q = D_001DA938;
    if (!q->x4) q = func_003E6FC0();
    a = func_003E71A0(q);
    func_003E7758(0x64);
    b = func_003E7760();
    if (a != 0) {
        if (func_003E5CB0(a, arg0) == 0) {
            p = D_001DA938;
            if (p->x4) q = p; else q = func_003E6FC0(p);
            o = (O_3DFE10 *)func_003E7078(q, 1);
            c = o->vt->f8(o, b);
            if (c != 0) {
                d = func_003F02D0(func_003F2740(0x64, c));
                r = ((s32 (*)())func_003E6700)(a, d, arg0) != 0;
                if (r == 0) {
                    ((void (*)())d->vt->f8)(d, 2);
                    p = D_001DA938;
                    if (p->x4) q = p; else q = func_003E6FC0(p);
                    o = (O_3DFE10 *)func_003E7078(q, 1);
                    o->vt->fC(o, c);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E5718 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E5880);

/* localdecomp:start func_003E5898 */
extern u8 D_001D9580;
extern s32 D_001D9578;
extern s32 func_003E7BF0(s32, s32, s32);
void func_003E5898(s32 a) {
    if (D_001D9580 != 0) {
        D_001D9578 = a;
        func_003E7BF0(0x10000, 1, a != 0);
    }
}
/* localdecomp:end func_003E5898 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E58C8);
