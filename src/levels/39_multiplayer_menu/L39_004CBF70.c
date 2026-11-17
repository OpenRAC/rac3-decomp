#include "common.h"

/* localdecomp:start func_L39_004CBF70 */
extern s32 func_L39_004E0ED0(s32 *);

s32 func_L39_004CBF70(s32 *arg0) {
    if (arg0 != 0) {
        if ((*arg0 != 0x74) || (func_L39_004C4F30(2) != 0)) {
            return func_L39_004E0ED0(arg0);
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_L39_004CBF70 */

/* localdecomp:start func_L39_004CBFC8 */
extern s32 func_L39_004E0F28(s32, s32);

s32 func_L39_004CBFC8(s32 arg0, s32 arg1) {
    if (func_L39_004C4F30(2) != 0) {
        return func_L39_004E0F28(arg0, arg1);
    }
    return 0;
}
/* localdecomp:end func_L39_004CBFC8 */

/* localdecomp:start func_L39_004CC018 */
extern s32 func_L39_004E1060(void *);

s32 func_L39_004CC018(void *arg0) {
    if (func_L39_004C4F30(2) != 0) {
        return func_L39_004E1060(arg0);
    }
    return 0;
}
/* localdecomp:end func_L39_004CC018 */

/* localdecomp:start func_L39_004CC058 */
extern s32 func_L39_004E10B0(void *);

s32 func_L39_004CC058(void *arg0) {
    return func_L39_004E10B0(arg0);
}
/* localdecomp:end func_L39_004CC058 */

INCLUDE_ASM("asm/levels", func_L39_004CC078);

/* localdecomp:start func_L39_004CC088 */
extern s32 func_L39_004E1138(void *);

s32 func_L39_004CC088(void *arg0) {
    return func_L39_004E1138(arg0);
}
/* localdecomp:end func_L39_004CC088 */

INCLUDE_ASM("asm/levels", func_L39_004CC0A8);

/* localdecomp:start func_L39_004CC0B0 */
extern s32 func_L39_004CC088(void *);

s32 func_L39_004CC0B0(void *arg0, void *arg1) {
    s32 ret = 0;
    if (arg1 == 0) {
        return 0;
    }
    switch (func_L39_004CC088(arg1)) {
    case 6: ret = 0x31; break;
    case 0x74: ret = 0x12; break;
    case 0x1C: ret = 0x44; break;
    }
    switch ((s32)arg0) {
    case 6: ret |= 0x100; break;
    case 0x200: ret |= 0x200; break;
    }
    if (func_L39_004CBF70(arg1) <= 0x200) {
        ret |= 0x1000;
    }
    return ret;
}
/* localdecomp:end func_L39_004CC0B0 */

/* localdecomp:start func_L39_004CC178 */
typedef struct S_004CC178 {
    s32 count;
    s32 *items;
    s32 sorted;
    s32 capacity;
    s32 cmp;
} S_004CC178;

void func_L39_004CC178(S_004CC178 *t, s32 cmp) {
    if (t->cmp != cmp) {
        t->sorted = 0;
    }
    t->cmp = cmp;
}
/* localdecomp:end func_L39_004CC178 */

/* localdecomp:start func_L39_004CC190 */
typedef struct S_004CC190 {
    s32 count;
    s32 *items;
    s32 sorted;
    s32 capacity;
    s32 cmp;
} S_004CC190;

extern S_004CC190 *func_L39_004CC228(s32);
extern void *func_L39_004BEF00(void *, s32, s32);
extern void *func_0011D380(void *, void *, s32);

S_004CC190 *func_L39_004CC190(S_004CC190 *src) {
    S_004CC190 *t;
    s32 *p;

    t = func_L39_004CC228(src->cmp);
    if (t != 0) {
        p = func_L39_004BEF00(t->items, src->capacity * 4, 0);
        if (p != 0) {
            t->items = p;
            t->count = src->count;
            func_0011D380(p, src->items, src->count * 4);
            t->sorted = src->sorted;
            t->capacity = src->capacity;
            t->cmp = src->cmp;
            return t;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004CC190 */

/* localdecomp:start func_L39_004CC228 */
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);

S_004CC190 *func_L39_004CC228(s32 cmp) {
    S_004CC190 *t;
    s32 i;

    t = func_L39_004BEED8(sizeof(S_004CC190));
    if (t == 0) {
        return 0;
    }
    t->items = func_L39_004BEED8(0x28 * 4);
    if (t->items != 0) {
        for (i = 0; i < 0x28; i++) {
            t->items[i] = 0;
        }
        t->cmp = cmp;
        t->capacity = 0x28;
        t->count = 0;
        t->sorted = 0;
        return t;
    }
    func_L39_004BEF28(t);
    return 0;
}
/* localdecomp:end func_L39_004CC228 */

/* localdecomp:start func_L39_004CC2C8 */
typedef s32 (*Cmp_004CC2C8)(const void *, const void *);

typedef struct S_004CC2C8 {
    s32 count;
    s32 *items;
    s32 sorted;
    u8 padC[4];
    Cmp_004CC2C8 cmp;
} S_004CC2C8;

extern void func_0011E788(void *, s32, s32, Cmp_004CC2C8);
extern void *func_00118FF0(const void *, const void *, s32, s32, Cmp_004CC2C8);

s32 func_L39_004CC2C8(S_004CC2C8 *t, s32 key) {
    s32 i;
    s32 *r;
    Cmp_004CC2C8 c = t->cmp;

    if (c == 0) {
        for (i = 0; i < t->count; i++) {
            if (t->items[i] == key) {
                return i;
            }
        }
        return -1;
    }
    if (t->sorted == 0) {
        func_0011E788(t->items, t->count, 4, c);
        t->sorted = 1;
    }
    if (key == 0) {
        return -1;
    }
    r = func_00118FF0(&key, t->items, t->count, 4, c);
    if (r == 0) {
        return -1;
    }
    for (i = r - t->items; i > 0; i--) {
        if (t->cmp(&t->items[i - 1], &key) < 0) {
            break;
        }
    }
    return i;
}
/* localdecomp:end func_L39_004CC2C8 */

/* localdecomp:start func_L39_004CC3E0 */
extern s32 func_L39_004EEEF0(void *, void *, s32);

s32 func_L39_004CC3E0(s32 *arg0, void *arg1) {
    return func_L39_004EEEF0(arg0, arg1, *arg0);
}
/* localdecomp:end func_L39_004CC3E0 */

LINKER_REMNANT("asm/levels", func_L39_004CC400);
