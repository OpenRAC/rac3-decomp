#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E1E50;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E23C0;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2118;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E21F8;
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E24B0;

/* localdecomp:start func_L01_00516438 */
extern f32 D_L01_001DC0E8;
extern f32 D_L01_001DC0EC;
extern void func_003E7268(void);
void func_L01_00516438(f32 a, f32 b) {
    D_L01_001DC0E8 = a;
    D_L01_001DC0EC = b;
    func_003E7268();
}
/* localdecomp:end func_L01_00516438 */

/* localdecomp:start func_L01_00516458 */
extern s32 D_L01_001DC108_00516458;

void func_L01_00516458(s32 a) {
    D_L01_001DC108_00516458 = a;
}
/* localdecomp:end func_L01_00516458 */

/* localdecomp:start func_L01_00516460 */
extern s32 D_L01_001DC108_00516460;
s32 func_L01_00516460(void) {
    return D_L01_001DC108_00516460;
}
/* localdecomp:end func_L01_00516460 */

/* localdecomp:start func_L01_00516468 */
void func_L01_00516468(void) {

}
/* localdecomp:end func_L01_00516468 */

/* localdecomp:start func_L01_00516470 */
extern s32 func_L01_00516470(s32, f32, f32);

extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_L01_00519600[];
extern s32 D_L01_001DC0B8;
extern S_003E1E50 D_L01_001E15E0;
extern u8 D_L01_0026DA08[];
s32 func_L01_00516470(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E1E50 *q;

    r = 0;
    q = &D_L01_001E15E0;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L01_001DC0B8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519600)(D_L01_0026DA08, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_L01_00516470 */

/* localdecomp:start func_L01_00516558 */
extern S_003E1E50 D_L01_001E15E0;
extern s32 func_L01_00516558(s32, s32, s32);
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L01_001DC0B8;

extern u8 func_L01_00519680[];
extern u8 D_L01_0026DA50[];
s32 func_L01_00516558(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E23C0 *q;

    r = 0;
    q = &(*(S_003E23C0 *)&D_L01_001E15E0);
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L01_001DC0B8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519680)(D_L01_0026DA50, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_L01_00516558 */

INCLUDE_ASM("asm/levels", func_L01_00516640);

/* localdecomp:start func_L01_00516728 */
extern s32 func_L01_00516728(s32, f32, f32);

extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_L01_00519600[];
extern s32 D_L01_001DC0B8;
extern S_003E1E50 D_L01_001E15E0;
extern u8 D_L01_0026DBB8[];
s32 func_L01_00516728(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E1E50 *q;

    r = 0;
    q = &D_L01_001E15E0;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L01_001DC0B8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519600)(D_L01_0026DBB8, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_L01_00516728 */

LINKER_REMNANT("asm/levels", func_L01_00516810);

/* localdecomp:start func_L01_00516818 */
extern S_003E1E50 D_L01_001E15E0;
extern s32 func_L01_00516818(s32, f32);
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L01_001DC0B8;

extern u8 D_L01_001E1610[];
s32 func_L01_00516818(s32 arg0, f32 fa)
{
  s32 *base;
  unsigned char new_var;
  s32 (*cb)(void *, f32);
  s32 r;
  s32 t;
  void *p;
  S_003E2118 *q;
  r = 0;
  q = &(*(S_003E2118 *)&D_L01_001E15E0);
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
  if (new_var || ((*((s32 (**)(void *, s32)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0x10)))(p, D_L01_001DC0B8) == 0))
  {
    p = 0;
  }
  if (p != 0)
  {
    t = (*((s32 (**)(void *)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0xC)))(p);
 do { } while (0);
    cb = (void *) func_L01_00519788(D_L01_001E1610, t);
    if (cb != 0)
    {
      r = cb(p, fa);
    }
  }
  return r;
}
/* localdecomp:end func_L01_00516818 */

/* localdecomp:start func_L01_005168F0 */
extern S_003E1E50 D_L01_001E15E0;
extern s32 func_L01_005168F0(s32, f32);
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L01_001DC0B8;

extern u8 func_L01_00519810[];
extern u8 D_L01_0026DFF0[];
s32 func_L01_005168F0(s32 arg0, f32 fa) {
    s32 *base;
    s32 (*cb)(void *, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E21F8 *q;

    r = 0;
    q = &(*(S_003E21F8 *)&D_L01_001E15E0);
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L01_001DC0B8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519810)(D_L01_0026DFF0, t);
        if (cb != 0) {
            r = cb(p, fa);
        }
    }
    return r;
}
/* localdecomp:end func_L01_005168F0 */

/* localdecomp:start func_L01_005169C8 */
extern S_003E1E50 D_L01_001E15E0;
extern s32 func_L01_005169C8(s32, f32);
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L01_001DC0B8;

extern u8 func_L01_00519810[];
extern u8 D_L01_0026DDF8[];
s32 func_L01_005169C8(s32 arg0, f32 fa) {
    s32 *base;
    s32 (*cb)(void *, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E21F8 *q;

    r = 0;
    q = &(*(S_003E21F8 *)&D_L01_001E15E0);
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L01_001DC0B8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519810)(D_L01_0026DDF8, t);
        if (cb != 0) {
            r = cb(p, fa);
        }
    }
    return r;
}
/* localdecomp:end func_L01_005169C8 */

/* localdecomp:start func_L01_00516AA0 */
extern S_003E1E50 D_L01_001E15E0;
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L01_001DC0B8;

extern u8 func_L01_00519890[];
extern u8 D_L01_0026DE40[];
s32 func_L01_00516AA0(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E23C0 *q;

    r = 0;
    q = &(*(S_003E23C0 *)&D_L01_001E15E0);
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L01_001DC0B8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519890)(D_L01_0026DE40, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_L01_00516AA0 */

LINKER_REMNANT("asm/levels", func_L01_00516B88);

/* localdecomp:start func_L01_00516B90 */
extern S_003E1E50 D_L01_001E15E0;
extern s32 func_L01_00516B90(s32, s32, s32);
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L01_001DC0B8;

extern u8 func_L01_00519890_00516B90[];
extern u8 D_L01_0026DED0[];
s32 func_L01_00516B90(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E23C0 *q;

    r = 0;
    q = &(*(S_003E23C0 *)&D_L01_001E15E0);
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L01_001DC0B8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519890_00516B90)(D_L01_0026DED0, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_L01_00516B90 */

/* localdecomp:start func_L01_00516C78 */
extern S_003E1E50 D_L01_001E15E0;
extern s32 func_L01_00516C78(s32, s32, s32);
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 D_L01_001DC0B8;

extern u8 func_L01_00519990_00516C78[];
extern u8 D_L01_0026DF18[];
s32 func_L01_00516C78(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E23C0 *q;

    r = 0;
    q = &(*(S_003E23C0 *)&D_L01_001E15E0);
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L01_001DC0B8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519990_00516C78)(D_L01_0026DF18, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_L01_00516C78 */

/* localdecomp:start func_L01_00516D60 */
extern S_003E1E50 D_L01_001E15E0;
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_L01_00516D60(s32 arg0, s32 arg1);
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();

extern s32 func_003E6DE8();
extern s32 D_L01_001DC120;
extern void func_003EDAD0(void *p, s32, s32);
s32 func_L01_00516D60(s32 arg0, s32 arg1) {
    S_003E24B0 *q;
    S_003E24B0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = ((S_003E24B0 *)&D_L01_001E15E0);
    if (p->x4) q = p;
    else q = func_003E6C08(p);
    t = (void *)func_003E6378(func_003E6DE8(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_L01_001DC120) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EDAD0(v, 1, arg1);
    }
    return r;
}
/* localdecomp:end func_L01_00516D60 */
