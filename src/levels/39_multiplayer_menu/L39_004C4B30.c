#include "common.h"

/* localdecomp:start func_L39_004C4B30 */
typedef struct S_004C4B30 S_004C4B30;
typedef struct {
    char _p0[0x2C];
    s32 (*f2C)(S_004C4B30 *);
} V_004C4B30;
struct S_004C4B30 {
    char _p0[0x8];
    V_004C4B30 *f8;
    char _pC[0x20 - 0xC];
    s32 (*f20)(S_004C4B30 *);
};

extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004C4EE0(S_004C4B30 *);

s32 func_L39_004C4B30(S_004C4B30 *arg0) {
    s32 ret = 1;

    if (arg0->f20 == 0) {
        func_L39_004BC6C8(0x14, 0xB4, 0x90, 0, 0);
        return -1;
    }
    arg0->f8->f2C(arg0);
    if ((func_L39_004C4EE0(arg0) & 0x3000) || (func_L39_004C4EE0(arg0) & 0x4000)) {
        ret = arg0->f20(arg0);
    }
    return ret;
}
/* localdecomp:end func_L39_004C4B30 */

/* localdecomp:start func_L39_004C4BD0 */
typedef struct S_004C4BD0 {
    char _p0[0x20];
    void (*f20)(void);
    s32 f24;
    s32 _p28;
    s32 f2C;
    s32 f30;
} S_004C4BD0;

extern void func_L39_004C3CC0(void);
extern void func_L39_004C36A8(S_004C4BD0 *, s32);

void func_L39_004C4BD0(S_004C4BD0 *arg0) {
    arg0->f30 = 0x5000;
    arg0->f20 = func_L39_004C3CC0;
    arg0->f24 = 0;
    arg0->f2C = 0;
    func_L39_004C36A8(arg0, 0);
}
/* localdecomp:end func_L39_004C4BD0 */

/* localdecomp:start func_L39_004C4BF8 */
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004C4BF8() {
    func_L39_004BC6C8(0x14, 0xC6, 0x22, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004C4BF8 */

/* localdecomp:start func_L39_004C4C28 */
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004C4C28(void) {
    func_L39_004BC6C8(0x14, 0xA1, 0x22, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004C4C28 */

/* localdecomp:start func_L39_004C4C58 */
extern char D_L39_00475C20[];
extern char D_L39_00475C28[];
extern char D_L39_00475C30[];
extern char D_L39_00475C38[];

char *func_L39_004C4C58(s32 *arg0) {
    s32 v = *arg0;

    if (v == 0x301) {
        return D_L39_00475C20;
    }
    if (v == 0x300) {
        return D_L39_00475C28;
    }
    if (v == 2) {
        return D_L39_00475C30;
    }
    return D_L39_00475C38;
}
/* localdecomp:end func_L39_004C4C58 */

/* localdecomp:start func_L39_004C4CA8 */
typedef struct E_004C4CA8 E_004C4CA8;
struct E_004C4CA8 {
    E_004C4CA8 *f0;
    E_004C4CA8 *f4;
    E_004C4CA8 *f8;
};
typedef struct {
    char _p0[0x68];
    E_004C4CA8 f68;
    E_004C4CA8 f74;
    void (*f80)(void *);
} S_004C4CA8;

extern void func_L39_004DE828(void *);

void func_L39_004C4CA8(S_004C4CA8 *arg0) {
    E_004C4CA8 *list[2];
    s32 i;

    list[0] = &arg0->f68;
    list[1] = &arg0->f74;
    for (i = 0; i < 2; i++) {
        if (list[i]->f8 != 0) {
            func_L39_004DE828(list[i]->f8);
            list[i]->f8 = 0;
        }
        if (list[i]->f4 != 0) {
            arg0->f80(list[i]->f4);
            list[i]->f4 = 0;
            list[i]->f0 = 0;
        }
    }
}
/* localdecomp:end func_L39_004C4CA8 */

/* localdecomp:start func_L39_004C4D48 */
typedef struct {
    char _p0[0x10];
    void *f10;
    void *f14;
} S_004C4D48;

extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004D9ED8(void);
extern void *func_L39_004DA968(s32);
extern void *func_L39_004DAFC0(void *);
extern void *func_L39_004DAF40(void *, void *);
extern s32 func_L39_004DAE48(void *, s32, s32, s32);
extern s32 func_L39_004DAE28(void *, s32, s32, s32);

s32 func_L39_004C4D48(S_004C4D48 *s, s32 arg1) {
    void *h;

    if (s->f14 == 0) {
        h = func_L39_004DA968((s32)func_L39_004D9ED8());
        if (h == 0) {
            return 0;
        }
        s->f14 = h;
    } else {
        h = s->f14;
        if (h == s->f10) {
            s->f10 = func_L39_004DAFC0(h);
        }
    }
    func_L39_004DAE48(h, 1, 0, 0);
    if (func_L39_004DAE28(h, 0x75, 0x800, 1) == 0 && func_L39_004DAE28(h, 0x75, 1, 0) == 0) {
        func_L39_004BC6C8(0x14, 0xB8, 0x807, 0, 0);
        return 0;
    }
    if (arg1 != 0) {
        if (s->f10 != h) {
            s->f10 = func_L39_004DAF40(h, s->f10);
        }
    } else if (s->f10 == h) {
        s->f10 = func_L39_004DAFC0(h);
    }
    return 1;
}
/* localdecomp:end func_L39_004C4D48 */

/* localdecomp:start func_L39_004C4E68 */
typedef struct {
    char _p0[0x10];
    void *f10;
    void *f14;
} S_004C4E68;

extern void *func_L39_004DAFC0(void *);
extern void func_L39_004DAAB0(void *);

void func_L39_004C4E68(void *arg0) {
    S_004C4E68 *s = arg0;
    void *r;

    if (s->f14 != 0) {
        if (s->f14 == s->f10) {
            r = func_L39_004DAFC0(s->f14);
            if (r != 0) {
                s->f10 = r;
            }
        }
        func_L39_004DAAB0(s->f14);
        s->f14 = 0;
    }
}
/* localdecomp:end func_L39_004C4E68 */
