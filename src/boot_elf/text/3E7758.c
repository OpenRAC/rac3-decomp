#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003E88E0(s32 arg0, s32 *arg1);
extern s32 func_003E8868(s32 a);
extern s32 func_003E87F8(s32 arg0);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003E86B0();
extern s32 func_003E8780();
extern s32 func_003E92A8(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E94F0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8EA0(s32, s32, s32, s32, s32, s32);
extern s32 func_003E9710(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E91F0(s32, s32, s32);
extern s32 func_003E8C50(s32, f32, f32);
extern s32 func_003E8D10(s32, s32);
extern s32 func_003E8DC0(s32, s32, s32);
extern s32 func_003E93A0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E89E8(s32, s32);
extern s32 func_003E8700(s32, s32);
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E8128(s32, s32);
extern s32 func_003E8960();
extern void func_003E7758(s32);
extern s32 func_003E7760();
extern s32 func_003E7CE0(s32, s32, s32);
extern s32 func_003E7DD0(s32, s32);
extern s32 func_003E8AC8(s32, s32);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E8B70(s32, s32, s32);
extern void func_003E9808();
extern s32 func_003E9110(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003E9628(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9470(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E7A38(s32, f32);
extern s32 func_003E7948(s32, f32, f32);
extern s32 func_003E7DD0(s32 arg0, s32 arg1);
extern s32 func_003E82D8(s32, s32);
extern s32 func_003E7E80(s32, s32);
extern s32 func_003E9020(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8E10(s32, s32, s32, s32, s32);
extern s32 func_003E8F50(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E7B18(s32, f32);
extern s32 func_003E8128();
extern s32 func_003E7BF0();
extern s32 func_003E8048();
extern s32 func_003E83B0(s32, s32, s32, s32, s32);
extern s32 func_003E84B8(s32, s32, s32);
extern s32 func_003E7760(void);
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
extern void func_003E7620();
extern void func_00391068(f32 *, f32 *, s32);
/* localdecomp:start func_003E7758 */
extern s32 D_001D96B8;
void func_003E7758(s32 a) {
    D_001D96B8 = a;
}
/* localdecomp:end func_003E7758 */

/* localdecomp:start func_003E7760 */
extern s32 D_001D96B8;
s32 func_003E7760(void) {
    return D_001D96B8;
}
/* localdecomp:end func_003E7760 */

/* localdecomp:start func_003E7768 */
s32 func_003E7768(void) {
}
/* localdecomp:end func_003E7768 */

/* localdecomp:start func_003E7770 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA0B0_003E7770[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E1E50;
extern S_003E1E50 D_001DA938;
extern u8 D_0031B7C8[];
s32 func_003E7770(s32 arg0, f32 fa, f32 fb) {
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
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA0B0_003E7770)(D_0031B7C8, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E7770 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7858);

extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA1B0_003E7860[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E1F40;
extern S_003E1F40 D_001DA938_003E7860;
extern s32 D_001DA9C8[2];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E7860);

/* localdecomp:start func_003E7948 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA0B0_003E7948[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2028;
extern S_003E2028 D_001DA938_003E7948;
extern u8 D_0031B978[];
s32 func_003E7948(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E2028 *q;

    r = 0;
    q = &D_001DA938_003E7948;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA0B0_003E7948)(D_0031B978, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E7948 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7A30);

/* localdecomp:start func_003E7A38 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2118;
extern S_003E2118 D_001DA938_003E7A38;
extern u8 D_001DA968[];
s32 func_003E7A38(s32 arg0, f32 fa)
{
  s32 *base;
  unsigned char new_var;
  s32 (*cb)(void *, f32);
  s32 r;
  s32 t;
  void *p;
  S_003E2118 *q;
  r = 0;
  q = &D_001DA938_003E7A38;
  if (q->f4 != 0)
  {
    base = (s32 *) q;
  }
  else
  {
    base = (s32 *) func_003E6FC0(q);
  }
  p = (void *) func_003E6730(func_003E71A0(base), arg0);
  new_var = p == 0;
  if (new_var || ((*((s32 (**)(void *, s32)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0x10)))(p, D_001D9668) == 0))
  {
    p = 0;
  }
  if (p != 0)
  {
    t = (*((s32 (**)(void *)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0xC)))(p);
 do { } while (0);
    cb = (void *) func_003EA238(D_001DA968, t);
    if (cb != 0)
    {
      r = cb(p, fa);
    }
  }
  return r;
}
/* localdecomp:end func_003E7A38 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7B10);

/* localdecomp:start func_003E7B18 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA2C0_003E7B18[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E21F8;
extern S_003E21F8 D_001DA938_003E7B18;
extern u8 D_0031BBB8[];
s32 func_003E7B18(s32 arg0, f32 fa) {
    s32 *base;
    s32 (*cb)(void *, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E21F8 *q;

    r = 0;
    q = &D_001DA938_003E7B18;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA2C0_003E7B18)(D_0031BBB8, t);
        if (cb != 0) {
            r = cb(p, fa);
        }
    }
    return r;
}
/* localdecomp:end func_003E7B18 */

/* localdecomp:start func_003E7BF0 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA340_003E7BF0[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E22D0;
extern S_003E22D0 D_001DA938_003E7BF0;
extern u8 D_0031BC00[];
s32 func_003E7BF0(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E22D0 *q;

    r = 0;
    q = &D_001DA938_003E7BF0;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA340_003E7BF0)(D_0031BC00, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_003E7BF0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7CD8);

/* localdecomp:start func_003E7CE0 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA340_003E7CE0[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E23C0;
extern S_003E23C0 D_001DA938_003E7CE0;
extern u8 D_0031BC90[];
s32 func_003E7CE0(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E23C0 *q;

    r = 0;
    q = &D_001DA938_003E7CE0;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA340_003E7CE0)(D_0031BC90, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_003E7CE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7DC8);

/* localdecomp:start func_003E7DD0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E24B0;
extern S_003E24B0 D_001DA938_003E7DD0[];
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E6730();
extern s32 D_001D96D0;
extern void func_003EDE88(void *p, s32, s32);
s32 func_003E7DD0(s32 arg0, s32 arg1) {
    S_003E24B0 *q;
    S_003E24B0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA938_003E7DD0;
    if (p->x4) q = p;
    else q = func_003E6FC0(p);
    t = (void *)func_003E6730(func_003E71A0(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D96D0) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EDE88(v, 1, arg1);
    }
    return r;
}
/* localdecomp:end func_003E7DD0 */

/* localdecomp:start func_003E7E80 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E2560;
extern S_003E2560 D_001DA938_003E7E80[];
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E6730();
extern s32 D_001D96D0;
extern void func_003EDE88(void *p, s32, s32);
s32 func_003E7E80(s32 arg0, s32 arg1) {
    S_003E2560 *q;
    S_003E2560 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA938_003E7E80;
    if (p->x4) q = p;
    else q = func_003E6FC0(p);
    t = (void *)func_003E6730(func_003E71A0(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D96D0) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EDE88(v, 0x40, arg1);
    }
    return r;
}
/* localdecomp:end func_003E7E80 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7F30);

/* localdecomp:start func_003E7F38 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA4C0_003E7F38[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2618;
extern S_003E2618 D_001DA938_003E7F38;
extern u8 D_0031BD20[];
s32 func_003E7F38(s32 arg0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 *base;
    s32 (*cb)(void *, s32, s32, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2618 *q;

    r = 0;
    q = &D_001DA938_003E7F38;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA4C0_003E7F38)(D_0031BD20, t);
        if (cb != 0) {
            r = cb(p, a1, a2, a3, a4);
        }
    }
    return r;
}
/* localdecomp:end func_003E7F38 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E8040);

/* localdecomp:start func_003E8048 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA540_003E8048[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_3E2728;
extern S_3E2728 D_001DA938_003E8048;
extern u8 D_0031B8A0[];
s32 func_003E8048(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_3E2728 *q;

    r = 0;
    q = &D_001DA938_003E8048;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA540_003E8048)(D_0031B8A0, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_003E8048 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E8120);

/* localdecomp:start func_003E8128 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA640_003E8128[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2808;
extern S_003E2808 D_001DA938_003E8128;
extern u8 D_0031B930[];
s32 func_003E8128(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2808 *q;

    r = 0;
    q = &D_001DA938_003E8128;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA640_003E8128)(D_0031B930, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_003E8128 */

/* localdecomp:start func_003E8200 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA640_003E8200[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E28E0;
extern S_003E28E0 D_001DA938_003E8200;
extern u8 D_0031BA50[];
s32 func_003E8200(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E28E0 *q;

    r = 0;
    q = &D_001DA938_003E8200;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA640_003E8200)(D_0031BA50, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_003E8200 */

/* localdecomp:start func_003E82D8 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern void *func_003EA6C0();
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E29B8;
extern S_003E29B8 D_001DA938_003E82D8;
extern u8 D_001DA9E8[];
s32 func_003E82D8(s32 arg0, s32 arg1)
{
  s32 *base;
  s32 (*cb)(void *, s32);
  s32 r;
  s32 t;
  void *p;
  S_003E29B8 *q;
  r = 0;
  q = &D_001DA938_003E82D8;
  if (q->f4 != 0)
  {
    base = (s32 *) q;
  }
  else
  {
    base = (s32 *) func_003E6FC0(q);
  }
  p = (void *) func_003E6730(func_003E71A0(base), arg0);
  if ((p == 0) || ((*((s32 (**)(void *, s32)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0x10)))(p, D_001D9668) == 0))
  {
    p = 0;
  }
  if (p != 0)
  {
 do { t = (*((s32 (**)(void *)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0xC)))(p); } while (0);
    cb = (void *) func_003EA6C0(D_001DA9E8, t);
    if (cb != 0)
    {
      r = cb(p, arg1);
    }
  }
  return r;
}
/* localdecomp:end func_003E82D8 */

/* localdecomp:start func_003E83B0 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA748_003E83B0[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2A90;
extern S_003E2A90 D_001DA938_003E83B0;
extern u8 D_0031BD68[];
s32 func_003E83B0(s32 arg0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 *base;
    s32 (*cb)(void *, s32, s32, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2A90 *q;

    r = 0;
    q = &D_001DA938_003E83B0;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA748_003E83B0)(D_0031BD68, t);
        if (cb != 0) {
            r = cb(p, a1, a2, a3, a4);
        }
    }
    return r;
}
/* localdecomp:end func_003E83B0 */

/* localdecomp:start func_003E84B8 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA7C8_003E84B8[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2B98;
extern S_003E2B98 D_001DA938_003E84B8;
extern u8 D_0031BB70[];
s32 func_003E84B8(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2B98 *q;

    r = 0;
    q = &D_001DA938_003E84B8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA7C8_003E84B8)(D_0031BB70, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_003E84B8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E85A0);

/* localdecomp:start func_003E85A8 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA0B0_003E85A8[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2C88;
extern S_003E2C88 D_001DA938_003E85A8;
extern u8 D_0031B858[];
s32 func_003E85A8(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E2C88 *q;

    r = 0;
    q = &D_001DA938_003E85A8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA0B0_003E85A8)(D_0031B858, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E85A8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E8690);

/* localdecomp:start func_003E86B0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2D90;
extern S_3E2D90 D_001DA938_003E86B0;
extern void *func_003E6FC0();
extern void func_003E71C8();
void func_003E86B0(s32 a) {
    S_3E2D90 *q;
    if (D_001DA938_003E86B0.x4) q = &D_001DA938_003E86B0;
    else q = func_003E6FC0(&D_001DA938_003E86B0);
    func_003E71C8(q, a);
}
/* localdecomp:end func_003E86B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E86F8);

/* localdecomp:start func_003E8700 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2DE0;
extern S_3E2DE0 D_001DA938_003E8700;
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E60A0(s32, s32, s32);
s32 func_003E8700(s32 a, s32 b) {
    S_3E2DE0 *q;
    s32 r = 0;
    s32 t;
    if (D_001DA938_003E8700.x4) q = &D_001DA938_003E8700;
    else q = func_003E6FC0(&D_001DA938_003E8700);
    t = func_003E71A0(q);
    if (t) r = func_003E60A0(t, a, b);
    return r;
}
/* localdecomp:end func_003E8700 */

/* localdecomp:start func_003E8780 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2E60;
extern S_3E2E60 D_001DA938_003E8780;
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E6680();
s32 func_003E8780(s32 a) {
    S_3E2E60 *q;
    s32 r = 0;
    s32 t;
    if (D_001DA938_003E8780.x4) q = &D_001DA938_003E8780;
    else q = func_003E6FC0(&D_001DA938_003E8780);
    t = func_003E71A0(q);
    if (t) r = func_003E6680(t, a);
    return r;
}
/* localdecomp:end func_003E8780 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E87F0);

/* localdecomp:start func_003E87F8 */
extern s32 func_003E65C8(s32, s32);
s32 *func_003E6FC0_003E87F8(s32 *);                  /* extern */
s32 func_003E71A0_003E87F8(s32 *);                       /* extern */
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E2ED8;
extern S_001DA9B8_003E2ED8 D_001DA938_003E87F8[];

s32 func_003E87F8(s32 arg0) {
    s32 *var_v0;
    s32 temp_v0;
    s32 var_s1;

    var_s1 = -1;
    if (D_001DA938_003E87F8->f4 != 0) {
        var_v0 = D_001DA938_003E87F8;
    } else {
        var_v0 = func_003E6FC0_003E87F8(D_001DA938_003E87F8);
    }
    temp_v0 = func_003E71A0_003E87F8(var_v0);
    if (temp_v0 != 0) {
        var_s1 = func_003E65C8(temp_v0, arg0);
    }
    return var_s1;
}
/* localdecomp:end func_003E87F8 */

/* localdecomp:start func_003E8868 */
typedef struct { s32 a; s32 b; } S_3E2F48;
extern S_3E2F48 D_001DA938_003E8868[];
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E6750(void *, s32);
static inline S_3E2F48 *get_3E2F48(void) {
    S_3E2F48 *p = D_001DA938_003E8868;
    if (p->b != 0) return p;
    return func_003E6FC0();
}
s32 func_003E8868(s32 a) {
    s32 r = 0;
    void *q = func_003E71A0(get_3E2F48());
    if (q != 0) r = func_003E6750(q, a);
    return r;
}
/* localdecomp:end func_003E8868 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E88D8);

/* localdecomp:start func_003E88E0 */
s32 func_003E6088(s32, s32);                        /* extern */
s32 *func_003E6FC0_003E88E0(s32 *);                  /* extern */
s32 func_003E71A0_003E88E0(s32 *);                       /* extern */
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E2FC0;
extern S_001DA9B8_003E2FC0 D_001DA938_003E88E0[];

s32 func_003E88E0(s32 arg0, s32 *arg1) {
    s32 *var_v0;
    s32 temp_v0;
    s32 var_s2;

    var_s2 = 0;
    if (D_001DA938_003E88E0->f4 != 0) {
        var_v0 = D_001DA938_003E88E0;
    } else {
        var_v0 = func_003E6FC0_003E88E0(D_001DA938_003E88E0);
    }
    temp_v0 = func_003E71A0_003E88E0(var_v0);
    if (temp_v0 != 0) {
        var_s2 = 1;
        *arg1 = func_003E6088(temp_v0, arg0);
    }
    return var_s2;
}
/* localdecomp:end func_003E88E0 */

/* localdecomp:start func_003E8960 */
typedef struct { s32 a; s32 b; } S_3E3040;
extern S_3E3040 D_001DA938_003E8960[];
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern void func_003E6178(void *, s32);
s32 func_003E8960(s32 a) {
    S_3E3040 *p = D_001DA938_003E8960;
    void *q;
    s32 r = 0;
    { S_3E3040 *t; if (p->b != 0) t = p; else t = func_003E6FC0(); q = func_003E71A0(t); }
    if (q) { func_003E6178(q, a); r = 1; }
    return r;
}
/* localdecomp:end func_003E8960 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E89D0);

/* localdecomp:start func_003E89E8 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern u8 func_003EA640_003E89E8[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E30C8;
extern S_003E30C8 D_001DA938_003E89E8;
extern u8 D_0031BA98[];
s32 func_003E89E8(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E30C8 *q;

    r = 0;
    q = &D_001DA938_003E89E8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA640_003E89E8)(D_0031BA98, t);
        if (cb != 0) {
            r = cb(p, arg1);
        } else {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_003E89E8 */

/* localdecomp:start func_003E8AC8 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern s32 D_001D9760;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E31A8;
extern S_003E31A8 D_001DA938_003E8AC8;
s32 func_003E8AC8(s32 arg0, s32 arg1) {
    s32 *base;
    s32 r;
    void *p;
    void *o;
    S_003E31A8 *q;

    r = 0;
    q = &D_001DA938_003E8AC8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    o = (p != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9760) != 0) ? p : 0;
    if (o != 0) {
        *(s32 *)((u8 *)o + 0x50) = arg1;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003E8AC8 */

/* localdecomp:start func_003E8B70 */
void *func_003E6730_003E8B70(s32, s32);                      /* extern */
s32 *func_003E6FC0_003E8B70(s32 *);                  /* extern */
s32 func_003E71A0_003E8B70(s32 *);                       /* extern */
s32 func_003E7BF0(s32, s32, s32);
void func_003F0250(void *, s32);
extern s32 D_001D9760;
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E3250;
extern S_001DA9B8_003E3250 D_001DA938_003E8B70[];

s32 func_003E8B70(s32 arg0, s32 arg1, s32 arg2) {
    s32 *var_v0;
    s32 var_s4;
    void *var_s0;

    var_s4 = 0;
    if (D_001DA938_003E8B70->f4 != 0) {
        var_v0 = D_001DA938_003E8B70;
    } else {
        var_v0 = func_003E6FC0_003E8B70(D_001DA938_003E8B70);
    }
    var_s0 = func_003E6730_003E8B70(func_003E71A0_003E8B70(var_v0), arg0);
    if ((var_s0 == 0) || ((*(s32 (**)(void *, s32))((u8 *)((*(void **)((u8 *)(var_s0) + 8))) + 0x10))(var_s0, D_001D9760) == 0)) {
        var_s0 = 0;
    }
    if (var_s0 != 0) {
        var_s4 = 1;
        func_003E7BF0(arg0, 0x8000, arg1);
        func_003F0250(var_s0, arg2);
    }
    return var_s4;
}
/* localdecomp:end func_003E8B70 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E8C40);

/* localdecomp:start func_003E8C50 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E3330;
extern S_003E3330 D_001DA938_003E8C50[];
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E6730();
extern s32 D_001D9790;
extern void func_003F03A0(void *p, f32, f32);
s32 func_003E8C50(s32 arg0, f32 fparg0, f32 fparg1) {
    S_003E3330 *q;
    S_003E3330 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA938_003E8C50;
    if (p->x4) q = p;
    else q = func_003E6FC0(p);
    t = (void *)func_003E6730(func_003E71A0(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9790) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003F03A0(v, fparg0, fparg1);
    }
    return r;
}
/* localdecomp:end func_003E8C50 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E8D08);

/* localdecomp:start func_003E8D10 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E33F0;
extern S_003E33F0 D_001DA938_003E8D10[];
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E6730();
extern s32 D_001D9790;
extern void func_003F0358(u8 *p, u8, s32);
s32 func_003E8D10(s32 arg0, s32 arg1) {
    S_003E33F0 *q;
    S_003E33F0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA938_003E8D10;
    if (p->x4) q = p;
    else q = func_003E6FC0(p);
    t = (void *)func_003E6730(func_003E71A0(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9790) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003F0358(v, 1, arg1);
    }
    return r;
}
/* localdecomp:end func_003E8D10 */

/* localdecomp:start func_003E8DC0 */
s32 func_003E89E8(s32, s32);
s32 func_003E8DC0(s32 a, s32 b, s32 c) {
    s32 x = func_003E89E8(a, b) != 0;
    s32 y = func_003E89E8(a, c) != 0;
    return x & y;
}
/* localdecomp:end func_003E8DC0 */

/* localdecomp:start func_003E8E10 */
extern s32 func_003E89E8();
s32 func_003E8E10(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 r;
    s32 t;
    r = func_003E89E8(a, b) != 0;
    t = func_003E89E8(a, c) != 0;
    r = r & t;
    t = func_003E89E8(a, d) != 0;
    r = r & t;
    t = func_003E89E8(a, e) != 0;
    return r & t;
}
/* localdecomp:end func_003E8E10 */

/* localdecomp:start func_003E8EA0 */
extern s32 func_003E89E8();
s32 func_003E8EA0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 r;
    s32 t;
    r = func_003E89E8(a, b) != 0;
    t = func_003E89E8(a, c) != 0;
    r = r & t;
    t = func_003E89E8(a, d) != 0;
    r = r & t;
    t = func_003E89E8(a, e) != 0;
    r = r & t;
    t = func_003E89E8(a, f) != 0;
    return r & t;
}
/* localdecomp:end func_003E8EA0 */

/* localdecomp:start func_003E8F50 */
extern s32 func_003E89E8();
s32 func_003E8F50(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    s32 r;
    s32 t;
    r = func_003E89E8(a, b) != 0;
    t = func_003E89E8(a, c) != 0;
    r = r & t;
    t = func_003E89E8(a, d) != 0;
    r = r & t;
    t = func_003E89E8(a, e) != 0;
    r = r & t;
    t = func_003E89E8(a, f) != 0;
    r = r & t;
    t = func_003E89E8(a, g) != 0;
    return r & t;
}
/* localdecomp:end func_003E8F50 */

/* localdecomp:start func_003E9020 */
extern s32 func_003E89E8(s32, s32);
s32 func_003E9020(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    s32 r;
    s32 t;
    r = func_003E89E8(a0, a1) != 0;
    t = func_003E89E8(a0, a2) != 0; r = r & t;
    t = func_003E89E8(a0, a3) != 0; r = r & t;
    t = func_003E89E8(a0, a4) != 0; r = r & t;
    t = func_003E89E8(a0, a5) != 0; r = r & t;
    t = func_003E89E8(a0, a6) != 0; r = r & t;
    t = func_003E89E8(a0, a7) != 0; r = r & t;
    return r;
}
/* localdecomp:end func_003E9020 */

/* localdecomp:start func_003E9110 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E37F0;
extern S_003E37F0 D_001DA938_003E9110[];
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E6730();
extern s32 D_001D9700;
extern void func_003EE518(void *p, s32, s32);
s32 func_003E9110(s32 arg0, s32 arg1, s32 arg2) {
    S_003E37F0 *q;
    S_003E37F0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA938_003E9110;
    if (p->x4) q = p;
    else q = func_003E6FC0(p);
    t = (void *)func_003E6730(func_003E71A0(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9700) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EE518(v, arg1, arg2);
    }
    return r;
}
/* localdecomp:end func_003E9110 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E91C8);

/* localdecomp:start func_003E91D0 */
extern s32 func_003E9110(s32 arg0, s32 arg1, s32 arg2);
 
void func_003E91D0(void *p, s32 arg1) {
    func_003E9110(p, 1, arg1);
}
/* localdecomp:end func_003E91D0 */

/* localdecomp:start func_003E91F0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E38D0;
extern S_003E38D0 D_001DA938_003E91F0[];
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E6730();
extern s32 D_001D97C0;
extern s32 func_003F0FA0(u8 *arg0, s32, s32);
s32 func_003E91F0(s32 arg0, s32 arg1, s32 arg2) {
    S_003E38D0 *q;
    S_003E38D0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA938_003E91F0;
    if (p->x4) q = p;
    else q = func_003E6FC0(p);
    t = (void *)func_003E6730(func_003E71A0(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D97C0) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003F0FA0(v, arg1, arg2);
    }
    return r;
}
/* localdecomp:end func_003E91F0 */

/* localdecomp:start func_003E92A8 */
extern s32 func_003E5448();
extern s32 func_00392DF8();
extern s32 func_003E84B8(s32, s32, s32);
extern s32 func_003E8128(s32, s32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E7B18(s32, f32);
s32 func_003E92A8(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w, f32 u) {
    s32 f = func_003E5448(a);
    s32 ok = func_003E84B8(a, func_00392DF8(), b) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E8128(a, c) != 0;
    ok = ok & t;
    t = func_003E85A8(a, z, w) != 0;
    ok = ok & t;
    t = func_003E7770(a, x, y) != 0;
    ok = ok & t;
    t = func_003E7B18(a, u) != 0;
    return ok & t;
}
/* localdecomp:end func_003E92A8 */

/* localdecomp:start func_003E93A0 */
extern s32 func_003E5718();
extern s32 func_003E8048(s32, s32);
extern s32 func_003E8128(s32, s32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E7770(s32, f32, f32);
s32 func_003E93A0(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w) {
    s32 f = func_003E5718(a);
    s32 ok = func_003E8048(a, b) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E8128(a, c) != 0;
    ok = ok & t;
    t = func_003E85A8(a, z, w) != 0;
    ok = ok & t;
    t = func_003E7770(a, x, y) != 0;
    return ok & t;
}
/* localdecomp:end func_003E93A0 */

/* localdecomp:start func_003E9470 */
extern s32 func_003E93A0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7948(s32, f32, f32);
s32 func_003E9470(s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i) {
    s32 r;
    s32 t;
    s32 u;
    u = func_003E93A0(a, b, c, d, e, f, g);
    r = func_003E7948(a, h, i) != 0;
    if (u == 0) r = 0;
    t = ((s32 (*)(s32, s32, s32))func_003E7BF0)(a, 0x40, 1) != 0;
    return r & t;
}
/* localdecomp:end func_003E9470 */

/* localdecomp:start func_003E94F0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E3BD0;
extern S_003E3BD0 D_001DA938_003E94F0[];
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E6730();
extern s32 func_003E55B0(s32);
extern s32 D_001D9760;
s32 func_003E94F0(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w) {
    S_003E3BD0 *p;
    S_003E3BD0 *q;
    void *t;
    void *v;
    s32 ok;
    s32 u;
    ok = func_003E55B0(a);
    u = func_003E7770(a, x, y) != 0;
    if (!ok) u = 0;
    ok = u;
    u = func_003E8128(a, b) != 0;
    ok = ok & u;
    u = func_003E85A8(a, z, w) != 0;
    ok = ok & u;
    u = func_003E8200(a, c) != 0;
    ok = ok & u;
    p = D_001DA938_003E94F0;
    if (p->x4) q = p;
    else q = func_003E6FC0(p);
    t = (void *)func_003E6730(func_003E71A0(q), a);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9760) != 0) ? t : 0;
    *(s16 *)((u8 *)v + 0x4A) = 0;
    return ok;
}
/* localdecomp:end func_003E94F0 */

/* localdecomp:start func_003E9628 */
extern s32 func_003EA9C8();
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E8128(s32, s32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E7860(s32, f32, f32);
s32 func_003E9628(s32 a, s32 b, f32 x, f32 y, f32 z, f32 w, f32 u, f32 v) {
    s32 f = func_003EA9C8(a);
    s32 ok = func_003E7770(a, x, y) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E8128(a, b) != 0;
    ok = ok & t;
    t = func_003E85A8(a, z, w) != 0;
    ok = ok & t;
    t = func_003E7860(a, u, v) != 0;
    return ok & t;
}
/* localdecomp:end func_003E9628 */

/* localdecomp:start func_003E9710 */
extern s32 func_003EAB30();
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E8128(s32, s32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E8048(s32, s32);
extern s32 func_003E7A38(s32, f32);
s32 func_003E9710(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w, f32 u) {
    s32 f = func_003EAB30(a);
    s32 ok = func_003E7770(a, x, y) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E8128(a, c) != 0;
    ok = ok & t;
    t = func_003E85A8(a, z, w) != 0;
    ok = ok & t;
    t = func_003E8048(a, b) != 0;
    ok = ok & t;
    t = func_003E7A38(a, u) != 0;
    return ok & t;
}
/* localdecomp:end func_003E9710 */

/* localdecomp:start func_003E9808 */
extern void func_003B5418();
 
void func_003E9808(void) {
    func_003B5418();
}
/* localdecomp:end func_003E9808 */

extern u8 D_001D96BC;
extern s32 D_001D9700;
extern s32 D_001D9730;
extern s32 D_001D9760;
extern s32 D_001D9790;
extern s32 D_001D97C0;
extern s32 D_001D97F0;
extern s32 D_001DA948[2];
extern s32 D_001DA968_003E9828[2];
extern s32 D_001DA988[2];
extern s32 D_001DA9A8[2];
extern s32 D_001DA9C8[2];
extern s32 D_001DA9E8_003E9828[2];
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
extern s32 func_003EAD00_003E9828(void *, s32, void *);
extern s32 func_003EAE38_003E9828(void *, s32, void *);
extern s32 func_003EAF58_003E9828(void *, s32, void *);
extern s32 func_003EB0E0_003E9828(void *, s32, void *);
extern s32 func_003EB218_003E9828(void *, s32, void *);
extern s32 func_003EB350_003E9828(void *, s32, void *);
extern s32 func_003EB4F0_003E9828(void *, s32, void *);
extern s32 func_003EB700_003E9828(void *, s32, void *);
extern s32 func_003EB820_003E9828(void *, s32, void *);
extern s32 func_003EBAB8_003E9828(void *, s32, void *);
extern s32 func_003EBFA0_003E9828(void *, s32, void *);
extern s32 func_003EC0D8(void *, s32, void *);
extern s32 func_003EC2D8_003E9828(void *, s32, void *);
extern s32 func_003EC9D0_003E9828(void *, s32, void *);
extern s32 func_003ECAF8_003E9828(void *, s32, void *);
extern s32 func_003ED280_003E9828(void *, s32, void *);
extern s32 func_003ED718_003E9828(void *, s32, void *);
extern s32 func_003ED890_003E9828(void *, s32, void *);
extern s32 func_003EAC98(u8 *p, f32 a, f32 b);
extern s32 func_003EADD0(u8 *p, s32 a, s32 b);
extern s32 func_003EAF08(u8 *p, s32 a);
extern s32 func_003EB028(u8 *p, f32 a, f32 b);
extern s32 func_003EB090(u8 *p, s32 a);
extern s32 func_003EB1B0(u8 *p, s32 a, s32 b);
extern s32 func_003EB2E8(u8 *p, s32 a, u8 *out);
extern s32 func_003EB420(u8 *p, s32 a, s32 b);
extern s32 func_003EB488(u8 *p, s32 a, s32 b);
extern s32 func_003EB5C0(u8 *p, f32 a, f32 b);
extern s32 func_003EB628(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EB7D0(u8 *p, s32 a);
extern s32 func_003EB8F8(u8 *p, f32 a, f32 b);
extern s32 func_003EB968(u8 *p, s32 a, s32 b);
extern s32 func_003EB9D0(u8 *p, s32 a);
extern s32 func_003EBA28(u8 *p, s32 a, s16 b, s16 c, s32 d);
extern s32 func_003EBB88(u8 *p, f32 a, f32 b);
extern s32 func_003EBBF8(u8 *p, s32 a);
extern s32 func_003EBC50(u8 *p, s32 a, s32 b);
extern s32 func_003EBCB8(u8 *p, s32 a, u8 *out);
extern s32 func_003EBD20(u8 *p, s32 a, s32 b);
extern s32 func_003EBD88(u8 *p, s32 a, s32 b);
extern s32 func_003EBDF0(u8 *p, f32 a, f32 b);
extern s32 func_003EBE58(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EBF30(u8 *p, f32 a, f32 b);
extern s32 func_003EC078(u8 *p, f32 a);
extern s32 func_003EC1B0(u8 *p, f32 a);
extern s32 func_003EC210(u8 *p, f32 a, f32 b);
extern s32 func_003EC280(u8 *p, s32 a);
extern s32 func_003EC3A8(u8 *p, s32 a, s32 b);
extern s32 func_003EC410(u8 *p, s32 a);
extern s32 func_003EC468(u8 *p, f32 a, f32 b);
extern s32 func_003EC4D0(u8 *p, s32 a, s32 b);
extern s32 func_003EC538(u8 *p, f32 a, f32 b);
extern s32 func_003EC5A0();
extern s32 func_003EC608();
extern s32 func_003EC668(u8 *p, s32 a, s32 b);
extern s32 func_003EC6D0(u8 *p, s32 a, u8 *out);
extern s32 func_003EC738(u8 *p, s32 a, s32 b);
extern s32 func_003EC7A0(u8 *p, s32 a, s32 b);
extern s32 func_003EC808(u8 *p, f32 a, f32 b);
extern s32 func_003EC870(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EC948(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_003ECAA0(u8 *p, f32 a);
extern s32 func_003ECBC8(u8 *p, f32 a, f32 b);
extern s32 func_003ECC30(u8 *p, s32 a, s32 b);
extern s32 func_003ECC98(u8 *p, f32 a, f32 b);
extern s32 func_003ECD00(u8 *p, s32 a);
extern s32 func_003ECD50(u8 *p, s32 a, s32 b);
extern s32 func_003ECDB8(u8 *p, s32 a, u8 *out);
extern s32 func_003ECE20(u8 *p, s32 a, s32 b);
extern s32 func_003ECE88(u8 *p, s32 a, s32 b);
extern s32 func_003ECEF0(u8 *p, f32 a, f32 b);
extern s32 func_003ECF58(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ED030(u8 *p, f32 a, f32 b);
extern s32 func_003ED098(u8 *p, f32 a, f32 b);
extern s32 func_003ED100(u8 *p, s32 a, s32 b);
extern s32 func_003ED168(u8 *p, f32 a, f32 b);
extern s32 func_003ED1D0(u8 *p, s32 a);
extern s32 func_003ED220();
extern s32 func_003ED350(u8 *p, s32 a, s32 b);
extern s32 func_003ED3B8(u8 *p, s32 a, u8 *out);
extern s32 func_003ED420(u8 *p, s32 a, s32 b);
extern s32 func_003ED488(u8 *p, s32 a, s32 b);
extern s32 func_003ED4F0(u8 *p, f32 a, f32 b);
extern s32 func_003ED558(u8 *p, f32 a);
extern s32 func_003ED5B0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ED688(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern s32 func_003ED7E8();
extern s32 func_003ED840();
extern s32 func_003ED960(u8 *p, s32 a, s32 b);
extern s32 func_003ED9C8(u8 *p, s32 a, u8 *out);
extern s32 func_003EDA30(u8 *p, s32 a, s32 b);
extern s32 func_003EDA98(u8 *p, s32 a, s32 b);
extern s32 func_003EDB00(u8 *p, f32 a, f32 b);
extern s32 func_003EDB68(u8 *p, f32 a, f32 b);
extern s32 func_003EDBD8(u8 *p, s32 a, s32 b);
extern s32 func_003EDC40(u8 *p, f32 a, f32 b);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E9828);

LINKER_REMNANT("asm/boot_elf/remnants", func_003EA0A8);

/* localdecomp:start func_003EA0B0 */
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
extern u8 D_001DAA09;
void *func_003EA0B0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA09) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA0B0 */

/* localdecomp:start func_003EA130 */
extern u8 D_001DAA0A;
void *func_003EA130(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA0A) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA130 */

/* localdecomp:start func_003EA1B0 */
typedef struct { u32 key; void *val; } HE_003E4890;
typedef struct { s32 f0; s32 n; HE_003E4890 e[3]; } HT_003E4890;
extern u8 D_001DAA0B;
void *func_003EA1B0(HT_003E4890 *t, u32 key) {
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
/* localdecomp:end func_003EA1B0 */

/* localdecomp:start func_003EA238 */
typedef struct { u32 key; void *val; } HE_003E4918;
typedef struct { s32 f0; s32 n; HE_003E4918 e[3]; } HT_003E4918;
extern u8 D_001DAA0C;
void *func_003EA238(HT_003E4918 *t, u32 key) {
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
/* localdecomp:end func_003EA238 */

/* localdecomp:start func_003EA2C0 */
extern u8 D_001DAA0D;
void *func_003EA2C0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA0D) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA2C0 */

/* localdecomp:start func_003EA340 */
extern u8 D_001DAA0E;
void *func_003EA340(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA0E) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA340 */

/* localdecomp:start func_003EA3C0 */
extern u8 D_001DAA0F;
void *func_003EA3C0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA0F) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA3C0 */

/* localdecomp:start func_003EA440 */
extern u8 D_001DAA10;
void *func_003EA440(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA10) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA440 */

/* localdecomp:start func_003EA4C0 */
extern u8 D_001DAA11;
void *func_003EA4C0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA11) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA4C0 */

/* localdecomp:start func_003EA540 */
extern u8 D_001DAA12;
void *func_003EA540(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA12) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA540 */

/* localdecomp:start func_003EA5C0 */
extern u8 D_001DAA13;
void *func_003EA5C0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA13) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA5C0 */

/* localdecomp:start func_003EA640 */
extern u8 D_001DAA14;
void *func_003EA640(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA14) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA640 */

/* localdecomp:start func_003EA6C0 */
typedef struct { u32 key; void *val; } HE_003E4DA0;
typedef struct { s32 f0; s32 n; HE_003E4DA0 e[3]; } HT_003E4DA0;
extern u8 D_001DAA15;
void *func_003EA6C0(HT_003E4DA0 *t, u32 key) {
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
/* localdecomp:end func_003EA6C0 */

/* localdecomp:start func_003EA748 */
extern u8 D_001DAA16;
void *func_003EA748(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA16) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA748 */

/* localdecomp:start func_003EA7C8 */
extern u8 D_001DAA17;
void *func_003EA7C8(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA17) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA7C8 */

/* localdecomp:start func_003EA848 */
extern u8 D_001DAA18;
void *func_003EA848(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA18) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA848 */

/* localdecomp:start func_003EA8C8 */
extern u8 D_001DAA19;
void *func_003EA8C8(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA19) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA8C8 */

/* localdecomp:start func_003EA948 */
extern u8 D_001DAA1A;
void *func_003EA948(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA1A) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA948 */

/* localdecomp:start func_003EA9C8 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E50A8;
extern S_003E50A8 D_001DA938_003EA9C8[];
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E7078();
extern s32 func_003E5CB0();
extern s32 func_003E6700();
extern void *func_003EEB18();
extern s32 func_003F2740();
extern void func_003E7758(s32);
extern s32 func_003E7760();
s32 func_003EA9C8(s32 a) {
    S_003E50A8 *p;
    S_003E50A8 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA938_003EA9C8;
    if (!q->x4) q = func_003E6FC0();
    obj = func_003E71A0(q);
    func_003E7758(0x3C);
    vv = func_003E7760();
    if (obj != 0) {
        if (func_003E5CB0(obj, a) == 0) {
            p = D_001DA938_003EA9C8;
            if (p->x4) q = p;
            else q = func_003E6FC0(p);
            t1 = func_003E7078(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003EEB18(func_003F2740(0x3C, e));
                r = func_003E6700(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA938_003EA9C8;
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
/* localdecomp:end func_003EA9C8 */

/* localdecomp:start func_003EAB30 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E5210;
extern S_003E5210 D_001DA938_003EAB30[];
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E7078();
extern s32 func_003E5CB0();
extern s32 func_003E6700();
extern void *func_003F0AC0();
extern s32 func_003F2740();
extern void func_003E7758(s32);
extern s32 func_003E7760();
s32 func_003EAB30(s32 a) {
    S_003E5210 *p;
    S_003E5210 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA938_003EAB30;
    if (!q->x4) q = func_003E6FC0();
    obj = func_003E71A0(q);
    func_003E7758(0x38);
    vv = func_003E7760();
    if (obj != 0) {
        if (func_003E5CB0(obj, a) == 0) {
            p = D_001DA938_003EAB30;
            if (p->x4) q = p;
            else q = func_003E6FC0(p);
            t1 = func_003E7078(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003F0AC0(func_003F2740(0x38, e));
                r = func_003E6700(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA938_003EAB30;
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
/* localdecomp:end func_003EAB30 */
