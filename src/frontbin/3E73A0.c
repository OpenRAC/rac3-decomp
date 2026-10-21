#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003E8528(s32 arg0, s32 *arg1);
extern s32 func_003E84B0(s32 a);
extern s32 func_003E8440(s32 arg0);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003E82F8();
extern s32 func_003E83C8();
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8AE8(s32, s32, s32, s32, s32, s32);
extern s32 func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E8E38(s32, s32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_003E8958(s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E7D70(s32, s32);
extern s32 func_003E85A8();
extern void func_003E73A0(s32);
extern s32 func_003E73A8();
extern s32 func_003E7928(s32, s32, s32);
extern s32 func_003E7A18(s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);
extern void func_003E9450();
extern s32 func_003E8D58(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E90B8(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E7680(s32, f32);
extern s32 func_003E7590(s32, f32, f32);
extern s32 func_003E7A18(s32 arg0, s32 arg1);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E7AC8(s32, s32);
extern s32 func_003E8C68(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8A58(s32, s32, s32, s32, s32);
extern s32 func_003E8B98(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E7760(s32, f32);
extern s32 func_003E7D70();
extern s32 func_003E7838();
extern s32 func_003E7C90();
extern s32 func_003E7FF8(s32, s32, s32, s32, s32);
extern s32 func_003E8100(s32, s32, s32);
extern s32 func_003E73A8(void);
/* --- end of declarations from other files --- */

extern f32 D_001D9688;
extern f32 D_001D968C;
extern s32 D_001D9690;
extern s32 D_001D9694;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern f32 D_001D96A0;
extern f32 D_001D96A4;
extern f32 D_001D96B0;
extern f32 D_001D96B4;
extern void func_003E7268();
extern void func_00390C88(f32 *, f32 *, s32);
/* localdecomp:start func_003E73A0 */
extern s32 D_001D96B8;
void func_003E73A0(s32 a) {
    D_001D96B8 = a;
}
/* localdecomp:end func_003E73A0 */

/* localdecomp:start func_003E73A8 */
extern s32 D_001D96B8;
s32 func_003E73A8(void) {
    return D_001D96B8;
}
/* localdecomp:end func_003E73A8 */

/* localdecomp:start func_003E73B0 */
s32 func_003E73B0(void) {
}
/* localdecomp:end func_003E73B0 */

/* localdecomp:start func_003E73B8 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003E9CF8_003E73B8[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E1E50;
extern S_003E1E50 D_001DA938;
extern u8 D_0031B7C8[];
s32 func_003E73B8(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E1E50 *q;

    r = 0;
    q = &D_001DA938;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E9CF8_003E73B8)(D_0031B7C8, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E73B8 */

LINKER_REMNANT("asm/remnants", func_003E74A0);

extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003E9DF8_003E74A8[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E1F40;
extern S_003E1F40 D_001DA938_003E74A8;
extern s32 D_001DA9C8[2];
INCLUDE_ASM("asm/nonmatchings/text", func_003E74A8);

/* localdecomp:start func_003E7590 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003E9CF8_003E7590[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2028;
extern S_003E2028 D_001DA938_003E7590;
extern u8 D_0031B978[];
s32 func_003E7590(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E2028 *q;

    r = 0;
    q = &D_001DA938_003E7590;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E9CF8_003E7590)(D_0031B978, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E7590 */

LINKER_REMNANT("asm/remnants", func_003E7678);

/* localdecomp:start func_003E7680 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2118;
extern S_003E2118 D_001DA938_003E7680;
extern u8 D_001DA968[];
s32 func_003E7680(s32 arg0, f32 fa)
{
  s32 *base;
  unsigned char new_var;
  s32 (*cb)(void *, f32);
  s32 r;
  s32 t;
  void *p;
  S_003E2118 *q;
  r = 0;
  q = &D_001DA938_003E7680;
  if (q->f4 != 0)
  {
    base = (s32 *) q;
  }
  else
  {
    base = (s32 *) func_003E6C08(q);
  }
  p = (void *) func_003E6378(func_003E6DE8(base), arg0);
  new_var = p == 0;
  if (new_var || ((*((s32 (**)(void *, s32)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0x10)))(p, D_001D9668) == 0))
  {
    p = 0;
  }
  if (p != 0)
  {
    t = (*((s32 (**)(void *)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0xC)))(p);
 do { } while (0);
    cb = (void *) func_003E9E80(D_001DA968, t);
    if (cb != 0)
    {
      r = cb(p, fa);
    }
  }
  return r;
}
/* localdecomp:end func_003E7680 */

LINKER_REMNANT("asm/remnants", func_003E7758);

/* localdecomp:start func_003E7760 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003E9F08_003E7760[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E21F8;
extern S_003E21F8 D_001DA938_003E7760;
extern u8 D_0031BBB8[];
s32 func_003E7760(s32 arg0, f32 fa) {
    s32 *base;
    s32 (*cb)(void *, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E21F8 *q;

    r = 0;
    q = &D_001DA938_003E7760;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E9F08_003E7760)(D_0031BBB8, t);
        if (cb != 0) {
            r = cb(p, fa);
        }
    }
    return r;
}
/* localdecomp:end func_003E7760 */

/* localdecomp:start func_003E7838 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003E9F88_003E7838[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E22D0;
extern S_003E22D0 D_001DA938_003E7838;
extern u8 D_0031BC00[];
s32 func_003E7838(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E22D0 *q;

    r = 0;
    q = &D_001DA938_003E7838;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E9F88_003E7838)(D_0031BC00, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_003E7838 */

LINKER_REMNANT("asm/remnants", func_003E7920);

/* localdecomp:start func_003E7928 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003E9F88_003E7928[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E23C0;
extern S_003E23C0 D_001DA938_003E7928;
extern u8 D_0031BC90[];
s32 func_003E7928(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E23C0 *q;

    r = 0;
    q = &D_001DA938_003E7928;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E9F88_003E7928)(D_0031BC90, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_003E7928 */

LINKER_REMNANT("asm/remnants", func_003E7A10);

/* localdecomp:start func_003E7A18 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E24B0;
extern S_003E24B0 D_001DA938_003E7A18[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6378();
extern s32 D_001D96D0;
extern void func_003EDAD0(void *p, s32, s32);
s32 func_003E7A18(s32 arg0, s32 arg1) {
    S_003E24B0 *q;
    S_003E24B0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA938_003E7A18;
    if (p->x4) q = p;
    else q = func_003E6C08(p);
    t = (void *)func_003E6378(func_003E6DE8(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D96D0) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EDAD0(v, 1, arg1);
    }
    return r;
}
/* localdecomp:end func_003E7A18 */

/* localdecomp:start func_003E7AC8 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E2560;
extern S_003E2560 D_001DA938_003E7AC8[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6378();
extern s32 D_001D96D0;
extern void func_003EDAD0(void *p, s32, s32);
s32 func_003E7AC8(s32 arg0, s32 arg1) {
    S_003E2560 *q;
    S_003E2560 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA938_003E7AC8;
    if (p->x4) q = p;
    else q = func_003E6C08(p);
    t = (void *)func_003E6378(func_003E6DE8(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D96D0) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EDAD0(v, 0x40, arg1);
    }
    return r;
}
/* localdecomp:end func_003E7AC8 */

LINKER_REMNANT("asm/remnants", func_003E7B78);

/* localdecomp:start func_003E7B80 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003EA108_003E7B80[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2618;
extern S_003E2618 D_001DA938_003E7B80;
extern u8 D_0031BD20[];
s32 func_003E7B80(s32 arg0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 *base;
    s32 (*cb)(void *, s32, s32, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2618 *q;

    r = 0;
    q = &D_001DA938_003E7B80;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA108_003E7B80)(D_0031BD20, t);
        if (cb != 0) {
            r = cb(p, a1, a2, a3, a4);
        }
    }
    return r;
}
/* localdecomp:end func_003E7B80 */

LINKER_REMNANT("asm/remnants", func_003E7C88);

/* localdecomp:start func_003E7C90 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003EA188_003E7C90[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_3E2728;
extern S_3E2728 D_001DA938_003E7C90;
extern u8 D_0031B8A0[];
s32 func_003E7C90(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_3E2728 *q;

    r = 0;
    q = &D_001DA938_003E7C90;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA188_003E7C90)(D_0031B8A0, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_003E7C90 */

LINKER_REMNANT("asm/remnants", func_003E7D68);

/* localdecomp:start func_003E7D70 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003EA288_003E7D70[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2808;
extern S_003E2808 D_001DA938_003E7D70;
extern u8 D_0031B930[];
s32 func_003E7D70(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2808 *q;

    r = 0;
    q = &D_001DA938_003E7D70;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA288_003E7D70)(D_0031B930, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_003E7D70 */

/* localdecomp:start func_003E7E48 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003EA288_003E7E48[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E28E0;
extern S_003E28E0 D_001DA938_003E7E48;
extern u8 D_0031BA50[];
s32 func_003E7E48(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E28E0 *q;

    r = 0;
    q = &D_001DA938_003E7E48;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA288_003E7E48)(D_0031BA50, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_003E7E48 */

/* localdecomp:start func_003E7F20 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern void *func_003EA308();
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E29B8;
extern S_003E29B8 D_001DA938_003E7F20;
extern u8 D_001DA9E8[];
s32 func_003E7F20(s32 arg0, s32 arg1)
{
  s32 *base;
  s32 (*cb)(void *, s32);
  s32 r;
  s32 t;
  void *p;
  S_003E29B8 *q;
  r = 0;
  q = &D_001DA938_003E7F20;
  if (q->f4 != 0)
  {
    base = (s32 *) q;
  }
  else
  {
    base = (s32 *) func_003E6C08(q);
  }
  p = (void *) func_003E6378(func_003E6DE8(base), arg0);
  if ((p == 0) || ((*((s32 (**)(void *, s32)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0x10)))(p, D_001D9668) == 0))
  {
    p = 0;
  }
  if (p != 0)
  {
 do { t = (*((s32 (**)(void *)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0xC)))(p); } while (0);
    cb = (void *) func_003EA308(D_001DA9E8, t);
    if (cb != 0)
    {
      r = cb(p, arg1);
    }
  }
  return r;
}
/* localdecomp:end func_003E7F20 */

/* localdecomp:start func_003E7FF8 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003EA390_003E7FF8[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2A90;
extern S_003E2A90 D_001DA938_003E7FF8;
extern u8 D_0031BD68[];
s32 func_003E7FF8(s32 arg0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 *base;
    s32 (*cb)(void *, s32, s32, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2A90 *q;

    r = 0;
    q = &D_001DA938_003E7FF8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA390_003E7FF8)(D_0031BD68, t);
        if (cb != 0) {
            r = cb(p, a1, a2, a3, a4);
        }
    }
    return r;
}
/* localdecomp:end func_003E7FF8 */

/* localdecomp:start func_003E8100 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003EA410_003E8100[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2B98;
extern S_003E2B98 D_001DA938_003E8100;
extern u8 D_0031BB70[];
s32 func_003E8100(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2B98 *q;

    r = 0;
    q = &D_001DA938_003E8100;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA410_003E8100)(D_0031BB70, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_003E8100 */

LINKER_REMNANT("asm/remnants", func_003E81E8);

/* localdecomp:start func_003E81F0 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003E9CF8_003E81F0[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2C88;
extern S_003E2C88 D_001DA938_003E81F0;
extern u8 D_0031B858[];
s32 func_003E81F0(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E2C88 *q;

    r = 0;
    q = &D_001DA938_003E81F0;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E9CF8_003E81F0)(D_0031B858, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E81F0 */

LINKER_REMNANT("asm/remnants", func_003E82D8);

/* localdecomp:start func_003E82F8 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2D90;
extern S_3E2D90 D_001DA938_003E82F8;
extern void *func_003E6C08();
extern void func_003E6E10();
void func_003E82F8(s32 a) {
    S_3E2D90 *q;
    if (D_001DA938_003E82F8.x4) q = &D_001DA938_003E82F8;
    else q = func_003E6C08(&D_001DA938_003E82F8);
    func_003E6E10(q, a);
}
/* localdecomp:end func_003E82F8 */

LINKER_REMNANT("asm/remnants", func_003E8340);

/* localdecomp:start func_003E8348 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2DE0;
extern S_3E2DE0 D_001DA938_003E8348;
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E5CE8(s32, s32, s32);
s32 func_003E8348(s32 a, s32 b) {
    S_3E2DE0 *q;
    s32 r = 0;
    s32 t;
    if (D_001DA938_003E8348.x4) q = &D_001DA938_003E8348;
    else q = func_003E6C08(&D_001DA938_003E8348);
    t = func_003E6DE8(q);
    if (t) r = func_003E5CE8(t, a, b);
    return r;
}
/* localdecomp:end func_003E8348 */

/* localdecomp:start func_003E83C8 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2E60;
extern S_3E2E60 D_001DA938_003E83C8;
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E62C8();
s32 func_003E83C8(s32 a) {
    S_3E2E60 *q;
    s32 r = 0;
    s32 t;
    if (D_001DA938_003E83C8.x4) q = &D_001DA938_003E83C8;
    else q = func_003E6C08(&D_001DA938_003E83C8);
    t = func_003E6DE8(q);
    if (t) r = func_003E62C8(t, a);
    return r;
}
/* localdecomp:end func_003E83C8 */

LINKER_REMNANT("asm/remnants", func_003E8438);

/* localdecomp:start func_003E8440 */
extern s32 func_003E6210(s32, s32);
s32 *func_003E6C08_003E8440(s32 *);                  /* extern */
s32 func_003E6DE8_003E8440(s32 *);                       /* extern */
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E2ED8;
extern S_001DA9B8_003E2ED8 D_001DA938_003E8440[];

s32 func_003E8440(s32 arg0) {
    s32 *var_v0;
    s32 temp_v0;
    s32 var_s1;

    var_s1 = -1;
    if (D_001DA938_003E8440->f4 != 0) {
        var_v0 = D_001DA938_003E8440;
    } else {
        var_v0 = func_003E6C08_003E8440(D_001DA938_003E8440);
    }
    temp_v0 = func_003E6DE8_003E8440(var_v0);
    if (temp_v0 != 0) {
        var_s1 = func_003E6210(temp_v0, arg0);
    }
    return var_s1;
}
/* localdecomp:end func_003E8440 */

/* localdecomp:start func_003E84B0 */
typedef struct { s32 a; s32 b; } S_3E2F48;
extern S_3E2F48 D_001DA938_003E84B0[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6398(void *, s32);
static inline S_3E2F48 *get_3E2F48(void) {
    S_3E2F48 *p = D_001DA938_003E84B0;
    if (p->b != 0) return p;
    return func_003E6C08();
}
s32 func_003E84B0(s32 a) {
    s32 r = 0;
    void *q = func_003E6DE8(get_3E2F48());
    if (q != 0) r = func_003E6398(q, a);
    return r;
}
/* localdecomp:end func_003E84B0 */

LINKER_REMNANT("asm/remnants", func_003E8520);

/* localdecomp:start func_003E8528 */
s32 func_003E5CD0(s32, s32);                        /* extern */
s32 *func_003E6C08_003E8528(s32 *);                  /* extern */
s32 func_003E6DE8_003E8528(s32 *);                       /* extern */
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E2FC0;
extern S_001DA9B8_003E2FC0 D_001DA938_003E8528[];

s32 func_003E8528(s32 arg0, s32 *arg1) {
    s32 *var_v0;
    s32 temp_v0;
    s32 var_s2;

    var_s2 = 0;
    if (D_001DA938_003E8528->f4 != 0) {
        var_v0 = D_001DA938_003E8528;
    } else {
        var_v0 = func_003E6C08_003E8528(D_001DA938_003E8528);
    }
    temp_v0 = func_003E6DE8_003E8528(var_v0);
    if (temp_v0 != 0) {
        var_s2 = 1;
        *arg1 = func_003E5CD0(temp_v0, arg0);
    }
    return var_s2;
}
/* localdecomp:end func_003E8528 */

/* localdecomp:start func_003E85A8 */
typedef struct { s32 a; s32 b; } S_3E3040;
extern S_3E3040 D_001DA938_003E85A8[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern void func_003E5DC0(void *, s32);
s32 func_003E85A8(s32 a) {
    S_3E3040 *p = D_001DA938_003E85A8;
    void *q;
    s32 r = 0;
    { S_3E3040 *t; if (p->b != 0) t = p; else t = func_003E6C08(); q = func_003E6DE8(t); }
    if (q) { func_003E5DC0(q, a); r = 1; }
    return r;
}
/* localdecomp:end func_003E85A8 */

LINKER_REMNANT("asm/remnants", func_003E8618);

/* localdecomp:start func_003E8630 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003EA288_003E8630[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E30C8;
extern S_003E30C8 D_001DA938_003E8630;
extern u8 D_0031BA98[];
s32 func_003E8630(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E30C8 *q;

    r = 0;
    q = &D_001DA938_003E8630;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA288_003E8630)(D_0031BA98, t);
        if (cb != 0) {
            r = cb(p, arg1);
        } else {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_003E8630 */

/* localdecomp:start func_003E8710 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_001D9760;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E31A8;
extern S_003E31A8 D_001DA938_003E8710;
s32 func_003E8710(s32 arg0, s32 arg1) {
    s32 *base;
    s32 r;
    void *p;
    void *o;
    S_003E31A8 *q;

    r = 0;
    q = &D_001DA938_003E8710;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    o = (p != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9760) != 0) ? p : 0;
    if (o != 0) {
        *(s32 *)((u8 *)o + 0x50) = arg1;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003E8710 */

/* localdecomp:start func_003E87B8 */
void *func_003E6378_003E87B8(s32, s32);                      /* extern */
s32 *func_003E6C08_003E87B8(s32 *);                  /* extern */
s32 func_003E6DE8_003E87B8(s32 *);                       /* extern */
s32 func_003E7838(s32, s32, s32);
void func_003EFE98(void *, s32);
extern s32 D_001D9760;
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E3250;
extern S_001DA9B8_003E3250 D_001DA938_003E87B8[];

s32 func_003E87B8(s32 arg0, s32 arg1, s32 arg2) {
    s32 *var_v0;
    s32 var_s4;
    void *var_s0;

    var_s4 = 0;
    if (D_001DA938_003E87B8->f4 != 0) {
        var_v0 = D_001DA938_003E87B8;
    } else {
        var_v0 = func_003E6C08_003E87B8(D_001DA938_003E87B8);
    }
    var_s0 = func_003E6378_003E87B8(func_003E6DE8_003E87B8(var_v0), arg0);
    if ((var_s0 == 0) || ((*(s32 (**)(void *, s32))((u8 *)((*(void **)((u8 *)(var_s0) + 8))) + 0x10))(var_s0, D_001D9760) == 0)) {
        var_s0 = 0;
    }
    if (var_s0 != 0) {
        var_s4 = 1;
        func_003E7838(arg0, 0x8000, arg1);
        func_003EFE98(var_s0, arg2);
    }
    return var_s4;
}
/* localdecomp:end func_003E87B8 */

LINKER_REMNANT("asm/remnants", func_003E8888);

/* localdecomp:start func_003E8898 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E3330;
extern S_003E3330 D_001DA938_003E8898[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6378();
extern s32 D_001D9790;
extern void func_003EFFE8(void *p, f32, f32);
s32 func_003E8898(s32 arg0, f32 fparg0, f32 fparg1) {
    S_003E3330 *q;
    S_003E3330 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA938_003E8898;
    if (p->x4) q = p;
    else q = func_003E6C08(p);
    t = (void *)func_003E6378(func_003E6DE8(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9790) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EFFE8(v, fparg0, fparg1);
    }
    return r;
}
/* localdecomp:end func_003E8898 */

LINKER_REMNANT("asm/remnants", func_003E8950);

/* localdecomp:start func_003E8958 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E33F0;
extern S_003E33F0 D_001DA938_003E8958[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6378();
extern s32 D_001D9790;
extern void func_003EFFA0(u8 *p, u8, s32);
s32 func_003E8958(s32 arg0, s32 arg1) {
    S_003E33F0 *q;
    S_003E33F0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA938_003E8958;
    if (p->x4) q = p;
    else q = func_003E6C08(p);
    t = (void *)func_003E6378(func_003E6DE8(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9790) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EFFA0(v, 1, arg1);
    }
    return r;
}
/* localdecomp:end func_003E8958 */

/* localdecomp:start func_003E8A08 */
s32 func_003E8630(s32, s32);
s32 func_003E8A08(s32 a, s32 b, s32 c) {
    s32 x = func_003E8630(a, b) != 0;
    s32 y = func_003E8630(a, c) != 0;
    return x & y;
}
/* localdecomp:end func_003E8A08 */

/* localdecomp:start func_003E8A58 */
extern s32 func_003E8630();
s32 func_003E8A58(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 r;
    s32 t;
    r = func_003E8630(a, b) != 0;
    t = func_003E8630(a, c) != 0;
    r = r & t;
    t = func_003E8630(a, d) != 0;
    r = r & t;
    t = func_003E8630(a, e) != 0;
    return r & t;
}
/* localdecomp:end func_003E8A58 */

/* localdecomp:start func_003E8AE8 */
extern s32 func_003E8630();
s32 func_003E8AE8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 r;
    s32 t;
    r = func_003E8630(a, b) != 0;
    t = func_003E8630(a, c) != 0;
    r = r & t;
    t = func_003E8630(a, d) != 0;
    r = r & t;
    t = func_003E8630(a, e) != 0;
    r = r & t;
    t = func_003E8630(a, f) != 0;
    return r & t;
}
/* localdecomp:end func_003E8AE8 */

/* localdecomp:start func_003E8B98 */
extern s32 func_003E8630();
s32 func_003E8B98(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    s32 r;
    s32 t;
    r = func_003E8630(a, b) != 0;
    t = func_003E8630(a, c) != 0;
    r = r & t;
    t = func_003E8630(a, d) != 0;
    r = r & t;
    t = func_003E8630(a, e) != 0;
    r = r & t;
    t = func_003E8630(a, f) != 0;
    r = r & t;
    t = func_003E8630(a, g) != 0;
    return r & t;
}
/* localdecomp:end func_003E8B98 */

/* localdecomp:start func_003E8C68 */
extern s32 func_003E8630(s32, s32);
s32 func_003E8C68(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    s32 r;
    s32 t;
    r = func_003E8630(a0, a1) != 0;
    t = func_003E8630(a0, a2) != 0; r = r & t;
    t = func_003E8630(a0, a3) != 0; r = r & t;
    t = func_003E8630(a0, a4) != 0; r = r & t;
    t = func_003E8630(a0, a5) != 0; r = r & t;
    t = func_003E8630(a0, a6) != 0; r = r & t;
    t = func_003E8630(a0, a7) != 0; r = r & t;
    return r;
}
/* localdecomp:end func_003E8C68 */

/* localdecomp:start func_003E8D58 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E37F0;
extern S_003E37F0 D_001DA938_003E8D58[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6378();
extern s32 D_001D9700;
extern void func_003EE160(void *p, s32, s32);
s32 func_003E8D58(s32 arg0, s32 arg1, s32 arg2) {
    S_003E37F0 *q;
    S_003E37F0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA938_003E8D58;
    if (p->x4) q = p;
    else q = func_003E6C08(p);
    t = (void *)func_003E6378(func_003E6DE8(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9700) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EE160(v, arg1, arg2);
    }
    return r;
}
/* localdecomp:end func_003E8D58 */

LINKER_REMNANT("asm/remnants", func_003E8E10);

/* localdecomp:start func_003E8E18 */
extern s32 func_003E8D58(s32 arg0, s32 arg1, s32 arg2);
 
void func_003E8E18(void *p, s32 arg1) {
    func_003E8D58(p, 1, arg1);
}
/* localdecomp:end func_003E8E18 */

/* localdecomp:start func_003E8E38 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E38D0;
extern S_003E38D0 D_001DA938_003E8E38[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6378();
extern s32 D_001D97C0;
extern s32 func_003F0BE8(u8 *arg0, s32, s32);
s32 func_003E8E38(s32 arg0, s32 arg1, s32 arg2) {
    S_003E38D0 *q;
    S_003E38D0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA938_003E8E38;
    if (p->x4) q = p;
    else q = func_003E6C08(p);
    t = (void *)func_003E6378(func_003E6DE8(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D97C0) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003F0BE8(v, arg1, arg2);
    }
    return r;
}
/* localdecomp:end func_003E8E38 */

/* localdecomp:start func_003E8EF0 */
extern s32 func_003E5090();
extern s32 func_00392A18();
extern s32 func_003E8100(s32, s32, s32);
extern s32 func_003E7D70(s32, s32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E7760(s32, f32);
s32 func_003E8EF0(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w, f32 u) {
    s32 f = func_003E5090(a);
    s32 ok = func_003E8100(a, func_00392A18(), b) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E7D70(a, c) != 0;
    ok = ok & t;
    t = func_003E81F0(a, z, w) != 0;
    ok = ok & t;
    t = func_003E73B8(a, x, y) != 0;
    ok = ok & t;
    t = func_003E7760(a, u) != 0;
    return ok & t;
}
/* localdecomp:end func_003E8EF0 */

/* localdecomp:start func_003E8FE8 */
extern s32 func_003E5360();
extern s32 func_003E7C90(s32, s32);
extern s32 func_003E7D70(s32, s32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E73B8(s32, f32, f32);
s32 func_003E8FE8(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w) {
    s32 f = func_003E5360(a);
    s32 ok = func_003E7C90(a, b) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E7D70(a, c) != 0;
    ok = ok & t;
    t = func_003E81F0(a, z, w) != 0;
    ok = ok & t;
    t = func_003E73B8(a, x, y) != 0;
    return ok & t;
}
/* localdecomp:end func_003E8FE8 */

/* localdecomp:start func_003E90B8 */
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7590(s32, f32, f32);
s32 func_003E90B8(s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i) {
    s32 r;
    s32 t;
    s32 u;
    u = func_003E8FE8(a, b, c, d, e, f, g);
    r = func_003E7590(a, h, i) != 0;
    if (u == 0) r = 0;
    t = ((s32 (*)(s32, s32, s32))func_003E7838)(a, 0x40, 1) != 0;
    return r & t;
}
/* localdecomp:end func_003E90B8 */

/* localdecomp:start func_003E9138 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E3BD0;
extern S_003E3BD0 D_001DA938_003E9138[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6378();
extern s32 func_003E51F8(s32);
extern s32 D_001D9760;
s32 func_003E9138(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w) {
    S_003E3BD0 *p;
    S_003E3BD0 *q;
    void *t;
    void *v;
    s32 ok;
    s32 u;
    ok = func_003E51F8(a);
    u = func_003E73B8(a, x, y) != 0;
    if (!ok) u = 0;
    ok = u;
    u = func_003E7D70(a, b) != 0;
    ok = ok & u;
    u = func_003E81F0(a, z, w) != 0;
    ok = ok & u;
    u = func_003E7E48(a, c) != 0;
    ok = ok & u;
    p = D_001DA938_003E9138;
    if (p->x4) q = p;
    else q = func_003E6C08(p);
    t = (void *)func_003E6378(func_003E6DE8(q), a);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9760) != 0) ? t : 0;
    *(s16 *)((u8 *)v + 0x4A) = 0;
    return ok;
}
/* localdecomp:end func_003E9138 */

/* localdecomp:start func_003E9270 */
extern s32 func_003EA610();
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E7D70(s32, s32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E74A8(s32, f32, f32);
s32 func_003E9270(s32 a, s32 b, f32 x, f32 y, f32 z, f32 w, f32 u, f32 v) {
    s32 f = func_003EA610(a);
    s32 ok = func_003E73B8(a, x, y) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E7D70(a, b) != 0;
    ok = ok & t;
    t = func_003E81F0(a, z, w) != 0;
    ok = ok & t;
    t = func_003E74A8(a, u, v) != 0;
    return ok & t;
}
/* localdecomp:end func_003E9270 */

/* localdecomp:start func_003E9358 */
extern s32 func_003EA778();
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E7D70(s32, s32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E7C90(s32, s32);
extern s32 func_003E7680(s32, f32);
s32 func_003E9358(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w, f32 u) {
    s32 f = func_003EA778(a);
    s32 ok = func_003E73B8(a, x, y) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E7D70(a, c) != 0;
    ok = ok & t;
    t = func_003E81F0(a, z, w) != 0;
    ok = ok & t;
    t = func_003E7C90(a, b) != 0;
    ok = ok & t;
    t = func_003E7680(a, u) != 0;
    return ok & t;
}
/* localdecomp:end func_003E9358 */

/* localdecomp:start func_003E9450 */
extern void func_003B5060();
 
void func_003E9450(void) {
    func_003B5060();
}
/* localdecomp:end func_003E9450 */

extern u8 D_001D96BC;
extern s32 D_001D9700;
extern s32 D_001D9730;
extern s32 D_001D9760;
extern s32 D_001D9790;
extern s32 D_001D97C0;
extern s32 D_001D97F0;
extern s32 D_001DA948[2];
extern s32 D_001DA968_003E9470[2];
extern s32 D_001DA988[2];
extern s32 D_001DA9A8[2];
extern s32 D_001DA9C8[2];
extern s32 D_001DA9E8_003E9470[2];
extern u8 D_0031B7C8[];
extern u8 D_0031B810[];
extern u8 D_0031B858[];
extern u8 D_0031B8A0[];
extern u8 D_0031B8E8[];
extern u8 D_0031B930[];
extern u8 D_0031B978[];
extern u8 D_0031B9C0[];
extern u8 D_0031BA08[];
extern u8 D_0031BA50[];
extern u8 D_0031BA98[];
extern u8 D_0031BAE0[];
extern u8 D_0031BB28[];
extern u8 D_0031BB70[];
extern u8 D_0031BBB8[];
extern u8 D_0031BC00[];
extern u8 D_0031BC48[];
extern u8 D_0031BC90[];
extern u8 D_0031BCD8[];
extern u8 D_0031BD20[];
extern u8 D_0031BD68[];
extern u8 D_0031BDB0[];
extern s32 func_003EA948_003E9470(void *, s32, void *);
extern s32 func_003EAA80_003E9470(void *, s32, void *);
extern s32 func_003EABA0_003E9470(void *, s32, void *);
extern s32 func_003EAD28_003E9470(void *, s32, void *);
extern s32 func_003EAE60_003E9470(void *, s32, void *);
extern s32 func_003EAF98_003E9470(void *, s32, void *);
extern s32 func_003EB138_003E9470(void *, s32, void *);
extern s32 func_003EB348_003E9470(void *, s32, void *);
extern s32 func_003EB468_003E9470(void *, s32, void *);
extern s32 func_003EB700_003E9470(void *, s32, void *);
extern s32 func_003EBBE8_003E9470(void *, s32, void *);
extern s32 func_003EBD20(void *, s32, void *);
extern s32 func_003EBF20_003E9470(void *, s32, void *);
extern s32 func_003EC618_003E9470(void *, s32, void *);
extern s32 func_003EC740_003E9470(void *, s32, void *);
extern s32 func_003ECEC8_003E9470(void *, s32, void *);
extern s32 func_003ED360_003E9470(void *, s32, void *);
extern s32 func_003ED4D8_003E9470(void *, s32, void *);
extern s32 func_003EA8E0(u8 *p, f32 a, f32 b);
extern s32 func_003EAA18(u8 *p, s32 a, s32 b);
extern s32 func_003EAB50(u8 *p, s32 a);
extern s32 func_003EAC70(u8 *p, f32 a, f32 b);
extern s32 func_003EACD8(u8 *p, s32 a);
extern s32 func_003EADF8(u8 *p, s32 a, s32 b);
extern s32 func_003EAF30(u8 *p, s32 a, u8 *out);
extern s32 func_003EB068(u8 *p, s32 a, s32 b);
extern s32 func_003EB0D0(u8 *p, s32 a, s32 b);
extern s32 func_003EB208(u8 *p, f32 a, f32 b);
extern s32 func_003EB270(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EB418(u8 *p, s32 a);
extern s32 func_003EB540(u8 *p, f32 a, f32 b);
extern s32 func_003EB5B0(u8 *p, s32 a, s32 b);
extern s32 func_003EB618(u8 *p, s32 a);
extern s32 func_003EB670(u8 *p, s32 a, s16 b, s16 c, s32 d);
extern s32 func_003EB7D0(u8 *p, f32 a, f32 b);
extern s32 func_003EB840(u8 *p, s32 a);
extern s32 func_003EB898(u8 *p, s32 a, s32 b);
extern s32 func_003EB900(u8 *p, s32 a, u8 *out);
extern s32 func_003EB968(u8 *p, s32 a, s32 b);
extern s32 func_003EB9D0(u8 *p, s32 a, s32 b);
extern s32 func_003EBA38(u8 *p, f32 a, f32 b);
extern s32 func_003EBAA0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EBB78(u8 *p, f32 a, f32 b);
extern s32 func_003EBCC0(u8 *p, f32 a);
extern s32 func_003EBDF8(u8 *p, f32 a);
extern s32 func_003EBE58(u8 *p, f32 a, f32 b);
extern s32 func_003EBEC8(u8 *p, s32 a);
extern s32 func_003EBFF0(u8 *p, s32 a, s32 b);
extern s32 func_003EC058(u8 *p, s32 a);
extern s32 func_003EC0B0(u8 *p, f32 a, f32 b);
extern s32 func_003EC118(u8 *p, s32 a, s32 b);
extern s32 func_003EC180(u8 *p, f32 a, f32 b);
extern s32 func_003EC1E8();
extern s32 func_003EC250();
extern s32 func_003EC2B0(u8 *p, s32 a, s32 b);
extern s32 func_003EC318(u8 *p, s32 a, u8 *out);
extern s32 func_003EC380(u8 *p, s32 a, s32 b);
extern s32 func_003EC3E8(u8 *p, s32 a, s32 b);
extern s32 func_003EC450(u8 *p, f32 a, f32 b);
extern s32 func_003EC4B8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EC590(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_003EC6E8(u8 *p, f32 a);
extern s32 func_003EC810(u8 *p, f32 a, f32 b);
extern s32 func_003EC878(u8 *p, s32 a, s32 b);
extern s32 func_003EC8E0(u8 *p, f32 a, f32 b);
extern s32 func_003EC948(u8 *p, s32 a);
extern s32 func_003EC998(u8 *p, s32 a, s32 b);
extern s32 func_003ECA00(u8 *p, s32 a, u8 *out);
extern s32 func_003ECA68(u8 *p, s32 a, s32 b);
extern s32 func_003ECAD0(u8 *p, s32 a, s32 b);
extern s32 func_003ECB38(u8 *p, f32 a, f32 b);
extern s32 func_003ECBA0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ECC78(u8 *p, f32 a, f32 b);
extern s32 func_003ECCE0(u8 *p, f32 a, f32 b);
extern s32 func_003ECD48(u8 *p, s32 a, s32 b);
extern s32 func_003ECDB0(u8 *p, f32 a, f32 b);
extern s32 func_003ECE18(u8 *p, s32 a);
extern s32 func_003ECE68();
extern s32 func_003ECF98(u8 *p, s32 a, s32 b);
extern s32 func_003ED000(u8 *p, s32 a, u8 *out);
extern s32 func_003ED068(u8 *p, s32 a, s32 b);
extern s32 func_003ED0D0(u8 *p, s32 a, s32 b);
extern s32 func_003ED138(u8 *p, f32 a, f32 b);
extern s32 func_003ED1A0(u8 *p, f32 a);
extern s32 func_003ED1F8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ED2D0(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern s32 func_003ED430();
extern s32 func_003ED488();
extern s32 func_003ED5A8(u8 *p, s32 a, s32 b);
extern s32 func_003ED610(u8 *p, s32 a, u8 *out);
extern s32 func_003ED678(u8 *p, s32 a, s32 b);
extern s32 func_003ED6E0(u8 *p, s32 a, s32 b);
extern s32 func_003ED748(u8 *p, f32 a, f32 b);
extern s32 func_003ED7B0(u8 *p, f32 a, f32 b);
extern s32 func_003ED820(u8 *p, s32 a, s32 b);
extern s32 func_003ED888(u8 *p, f32 a, f32 b);
INCLUDE_ASM("asm/nonmatchings/text", func_003E9470);

LINKER_REMNANT("asm/remnants", func_003E9CF0);

/* localdecomp:start func_003E9CF8 */
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
extern u8 D_001DAA09;
void *func_003E9CF8(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA09) return v;
    }
    return 0;
}
/* localdecomp:end func_003E9CF8 */

/* localdecomp:start func_003E9D78 */
extern u8 D_001DAA0A;
void *func_003E9D78(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA0A) return v;
    }
    return 0;
}
/* localdecomp:end func_003E9D78 */

/* localdecomp:start func_003E9DF8 */
typedef struct { u32 key; void *val; } HE_003E4890;
typedef struct { s32 f0; s32 n; HE_003E4890 e[3]; } HT_003E4890;
extern u8 D_001DAA0B;
void *func_003E9DF8(HT_003E4890 *t, u32 key) {
    s32 off;
    s32 three;
    void *sent;
    s32 i;
    s32 h;
    void * v;
    s32 u;
    i = 0;
    three = 3;
    sent = &D_001DAA0B;
    off = 0;
    for (; i < 3; i++) {
        h = ((key % three) + off) % three;
        v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != sent) return v;
        u = off + 1;
        off = (key & 1) + u;
    }
    return 0;
}
/* localdecomp:end func_003E9DF8 */

/* localdecomp:start func_003E9E80 */
typedef struct { u32 key; void *val; } HE_003E4918;
typedef struct { s32 f0; s32 n; HE_003E4918 e[3]; } HT_003E4918;
extern u8 D_001DAA0C;
void *func_003E9E80(HT_003E4918 *t, u32 key) {
    s32 off;
    s32 three;
    void *sent;
    s32 i;
    s32 h;
    void * v;
    s32 u;
    i = 0;
    three = 3;
    sent = &D_001DAA0C;
    off = 0;
    for (; i < 3; i++) {
        h = ((key % three) + off) % three;
        v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != sent) return v;
        u = off + 1;
        off = (key & 1) + u;
    }
    return 0;
}
/* localdecomp:end func_003E9E80 */

/* localdecomp:start func_003E9F08 */
extern u8 D_001DAA0D;
void *func_003E9F08(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA0D) return v;
    }
    return 0;
}
/* localdecomp:end func_003E9F08 */

/* localdecomp:start func_003E9F88 */
extern u8 D_001DAA0E;
void *func_003E9F88(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA0E) return v;
    }
    return 0;
}
/* localdecomp:end func_003E9F88 */

/* localdecomp:start func_003EA008 */
extern u8 D_001DAA0F;
void *func_003EA008(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA0F) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA008 */

/* localdecomp:start func_003EA088 */
extern u8 D_001DAA10;
void *func_003EA088(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA10) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA088 */

/* localdecomp:start func_003EA108 */
extern u8 D_001DAA11;
void *func_003EA108(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA11) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA108 */

/* localdecomp:start func_003EA188 */
extern u8 D_001DAA12;
void *func_003EA188(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA12) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA188 */

/* localdecomp:start func_003EA208 */
extern u8 D_001DAA13;
void *func_003EA208(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA13) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA208 */

/* localdecomp:start func_003EA288 */
extern u8 D_001DAA14;
void *func_003EA288(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA14) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA288 */

/* localdecomp:start func_003EA308 */
typedef struct { u32 key; void *val; } HE_003E4DA0;
typedef struct { s32 f0; s32 n; HE_003E4DA0 e[3]; } HT_003E4DA0;
extern u8 D_001DAA15;
void *func_003EA308(HT_003E4DA0 *t, u32 key) {
    s32 off;
    s32 three;
    void *sent;
    s32 i;
    s32 h;
    void * v;
    s32 u;
    i = 0;
    three = 3;
    sent = &D_001DAA15;
    off = 0;
    for (; i < 3; i++) {
        h = ((key % three) + off) % three;
        v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != sent) return v;
        u = off + 1;
        off = (key & 1) + u;
    }
    return 0;
}
/* localdecomp:end func_003EA308 */

/* localdecomp:start func_003EA390 */
extern u8 D_001DAA16;
void *func_003EA390(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA16) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA390 */

/* localdecomp:start func_003EA410 */
extern u8 D_001DAA17;
void *func_003EA410(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA17) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA410 */

/* localdecomp:start func_003EA490 */
extern u8 D_001DAA18;
void *func_003EA490(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA18) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA490 */

/* localdecomp:start func_003EA510 */
extern u8 D_001DAA19;
void *func_003EA510(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA19) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA510 */

/* localdecomp:start func_003EA590 */
extern u8 D_001DAA1A;
void *func_003EA590(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA1A) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA590 */

/* localdecomp:start func_003EA610 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E50A8;
extern S_003E50A8 D_001DA938_003EA610[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6CC0();
extern s32 func_003E58F8();
extern s32 func_003E6348();
extern void *func_003EE760();
extern s32 func_003F2388();
extern void func_003E73A0(s32);
extern s32 func_003E73A8();
s32 func_003EA610(s32 a) {
    S_003E50A8 *p;
    S_003E50A8 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA938_003EA610;
    if (!q->x4) q = func_003E6C08();
    obj = func_003E6DE8(q);
    func_003E73A0(0x3C);
    vv = func_003E73A8();
    if (obj != 0) {
        if (func_003E58F8(obj, a) == 0) {
            p = D_001DA938_003EA610;
            if (p->x4) q = p;
            else q = func_003E6C08(p);
            t1 = func_003E6CC0(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003EE760(func_003F2388(0x3C, e));
                r = func_003E6348(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA938_003EA610;
                    if (p->x4) q = p;
                    else q = func_003E6C08(p);
                    w = func_003E6CC0(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003EA610 */

/* localdecomp:start func_003EA778 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E5210;
extern S_003E5210 D_001DA938_003EA778[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6CC0();
extern s32 func_003E58F8();
extern s32 func_003E6348();
extern void *func_003F0708();
extern s32 func_003F2388();
extern void func_003E73A0(s32);
extern s32 func_003E73A8();
s32 func_003EA778(s32 a) {
    S_003E5210 *p;
    S_003E5210 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA938_003EA778;
    if (!q->x4) q = func_003E6C08();
    obj = func_003E6DE8(q);
    func_003E73A0(0x38);
    vv = func_003E73A8();
    if (obj != 0) {
        if (func_003E58F8(obj, a) == 0) {
            p = D_001DA938_003EA778;
            if (p->x4) q = p;
            else q = func_003E6C08(p);
            t1 = func_003E6CC0(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003F0708(func_003F2388(0x38, e));
                r = func_003E6348(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA938_003EA778;
                    if (p->x4) q = p;
                    else q = func_003E6C08(p);
                    w = func_003E6CC0(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003EA778 */
