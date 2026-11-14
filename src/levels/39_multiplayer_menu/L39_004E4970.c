#include "common.h"

/* declared by functions of L39_004DF158.c, which this file was cut from */
extern s32 func_L39_004E4970(s32, s32 *, s32);

/* localdecomp:start func_L39_004E4970 */
typedef struct V_004E4970 { s32 f0; s32 count; s32 cap; s32 *items; } V_004E4970;
extern s32 func_L39_004E4A50(s32, s32, s32, s32);
extern s32 func_L39_004E48E8(V_004E4970 *, s32);
extern s32 *func_L39_00505780(void);
extern s32 func_L39_005057D0(s32 *, s32 *, s32);

s32 func_L39_004E4970(s32 arg0, s32 *arg1, s32 arg2) {
    V_004E4970 *v = (V_004E4970 *)arg0;
    s32 *item;
    s32 r;
    if (arg2 & 0x10) {
        func_L39_004E4A50(arg0, arg1[0], arg1[1], 0);
    }
    if (v->cap <= v->count) {
        r = func_L39_004E48E8(v, v->count + 4);
        if (r != 0) {
            return r;
        }
    }
    if ((arg2 & 8) == 0) {
        item = func_L39_00505780();
        if (item == 0) {
            return 1;
        }
        r = func_L39_005057D0(item, arg1, arg2);
        if (r != 0) {
            return r;
        }
        arg1 = item;
    }
    v->items[v->count++] = (s32)arg1;
    return 0;
}
/* localdecomp:end func_L39_004E4970 */

/* localdecomp:start func_L39_004E4A50 */
typedef struct { s32 f0; s32 count; s32 cap; s32 *items; } S_004E4A50;
struct Record;
struct Container;
extern s32 func_L39_004E4AE8(struct Container *container, u32 category, u32 key,
                             s32 *cursor, struct Record **output, u32 flags);
extern void func_L39_004E4748(struct Record *);

s32 func_L39_004E4A50(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    S_004E4A50 *v = (S_004E4A50 *)arg0;
    s32 idx = 0;
    struct Record *item;
    s32 i;
    s32 n;

    i = func_L39_004E4AE8((struct Container *)arg0, arg1, arg2, &idx, &item, 0);
    if (i != 0) {
        return i;
    }
    func_L39_004E4748(item);
    n = v->count - 1;
    for (i = idx - 1; i < n; i++) {
        v->items[i] = v->items[i + 1];
    }
    v->count--;
    return 0;
}
/* localdecomp:end func_L39_004E4A50 */

/* localdecomp:start func_L39_004E4AE8 */
struct Record {
    s32 k0;
    s32 k1;
};
struct Container {
    u8 pad0[4];
    s32 count;
    u8 pad8[4];
    struct Record **items;
};

s32 func_L39_004E4AE8(struct Container *list, u32 k0, u32 k1, s32 *start, struct Record **out, u32 flags)
{
    s32 i;
    s32 end;
    s32 found0;
    s32 found1;
    struct Record *e;

    if (list == 0 || list->count == 0) {
        *out = 0;
        return 1;
    }
    end = 0;
    if (start != 0) {
        end = *start;
    }
    if (list->count < end) {
        end = list->count - 1;
    }
    found0 = k0 == 0;
    found1 = k1 == 0;
    i = end;
    while (!found0 && !found1) {
        if (i >= list->count) {
            if (!(flags & 4)) {
                break;
            }
            i = 0;
            flags = (s32)flags & ~4;
        }
        e = list->items[i];
        if (k0 == e->k0 && k1 == e->k1) {
            found1 = 1;
            found0 = 1;
            break;
        }
        i++;
        if (i == end) {
            break;
        }
    }
    if (found0 && found1) {
        *out = list->items[i];
        if (start != 0) {
            *start = i + 1;
        }
        return 0;
    }
    *out = 0;
    return 1;
}
/* localdecomp:end func_L39_004E4AE8 */

/* localdecomp:start func_L39_004E4BE0 */
/* Near miss, ported from rac4-decomp's func_L00_005209E0 (cross-game near pair). NEAR: 16-byte save slots (frame 0x60, s0-s3/ra at 0x10..0x50) vs our 0x30 packed frame; logic/regs otherwise same (s1=&record hoisted) */
typedef struct Record Record;
typedef struct Container Container;
extern s32 func_L39_004E4AE8(Container *container, u32 category, u32 key,
                             s32 *cursor, Record **output, u32 flags);

s32 func_L39_004E4BE0(Container *container, u32 category, const u32 *keys)
{
    s32 cursor = 0;
    Record *record;
    s32 status;
    while (*keys != 0) {
        status = func_L39_004E4AE8(container, category, *keys,
                                   &cursor, &record, 4);
        if (status != 0)
            return status;
        ++keys;
    }
    return 0;
}
/* localdecomp:end func_L39_004E4BE0 */

/* localdecomp:start func_L39_004E4C68 */
extern s32 (*D_L39_0046D32C)(void *) __attribute__((section(".data")));

s32 func_L39_004E4C68(void *arg0) {
    s32 ret;

    if (D_L39_0046D32C != 0) {
        ret = D_L39_0046D32C(arg0);
    } else {
        ret = 0;
    }
    return ret;
}
/* localdecomp:end func_L39_004E4C68 */

LINKER_REMNANT("asm/levels", func_L39_004E4CA0);

INCLUDE_ASM("asm/levels", func_L39_004E4CA8);

/* localdecomp:start func_L39_004E4CB8 */
typedef struct V_004E4CB8 {
    s32 hi;
    u32 lo;
    u32 ns;
} V_004E4CB8;

typedef struct T_004E4CB8 {
    s32 f0;
    s32 f4;
    V_004E4CB8 v;
} T_004E4CB8;

extern s32 func_L39_004F1608(T_004E4CB8 *);

V_004E4CB8 *func_L39_004E4CB8(V_004E4CB8 *out) {
    T_004E4CB8 t;

    if (out != 0) {
        if (func_L39_004F1608(&t) != 0) {
            return 0;
        }
        *out = t.v;
        return out;
    }
    return 0;
}
/* localdecomp:end func_L39_004E4CB8 */

LINKER_REMNANT("asm/levels", func_L39_004E4D10);

/* localdecomp:start func_L39_004E4D18 */
typedef struct V_004E4D18 {
    s32 hi;
    u32 lo;
    u32 ns;
} V_004E4D18;

typedef struct T_004E4D18 {
    s32 f0;
    s32 f4;
    V_004E4D18 v;
} T_004E4D18;

extern void func_0011D534(void *, s32, s32);
extern s32 func_L39_004F1358(T_004E4D18 *, T_004E4D18 *, s32, s32);

V_004E4D18 *func_L39_004E4D18(V_004E4D18 *out, V_004E4D18 *in, s32 arg2, s32 arg3) {
    T_004E4D18 t;

    func_0011D534(&t, 0, 0x14);
    if (out != 0) {
        if (in != 0) {
            t.v = *in;
        }
        if (func_L39_004F1358(&t, &t, arg3, arg2) != 0) {
            return 0;
        }
        *out = t.v;
        return out;
    }
    return 0;
}
/* localdecomp:end func_L39_004E4D18 */

/* localdecomp:start func_L39_004E4DC8 */
typedef struct V_004E4DC8 {
    s32 hi;
    u32 lo;
    u32 ns;
} V_004E4DC8;

typedef struct T_004E4DC8 {
    s32 f0;
    s32 f4;
    V_004E4DC8 v;
} T_004E4DC8;

extern void func_0011D534(void *, s32, s32);
extern s32 func_L39_004F01D8(T_004E4DC8 *, T_004E4DC8 *, s32 *);

s32 func_L39_004E4DC8(V_004E4DC8 *a, V_004E4DC8 *b) {
    T_004E4DC8 ta;
    T_004E4DC8 tb;
    s32 diff;

    func_0011D534(&ta, 0, 0x14);
    func_0011D534(&tb, 0, 0x14);
    if (a != 0) {
        ta.v = *a;
    }
    if (b != 0) {
        tb.v = *b;
    }
    func_L39_004F01D8(&ta, &tb, &diff);
    return diff;
}
/* localdecomp:end func_L39_004E4DC8 */

/* localdecomp:start func_L39_004E4E78 */
typedef struct V_004E4E78 {
    s32 hi;
    u32 lo;
    u32 ns;
} V_004E4E78;

typedef struct T_004E4E78 {
    s32 f0;
    s32 f4;
    V_004E4E78 v;
} T_004E4E78;

extern s32 func_L39_004F0A78(T_004E4E78 *out, s32 type, u8 *data, u32 len);

s32 func_L39_004E4E78(u8 *data, u32 len, s32 type, V_004E4E78 *out) {
    T_004E4E78 t;
    s32 ret;

    if (out == 0) {
        return 0x2721;
    }
    ret = func_L39_004F0A78(&t, type, data, len);
    *out = t.v;
    return ret;
}
/* localdecomp:end func_L39_004E4E78 */

/* localdecomp:start func_L39_004E4ED8 */
typedef struct V_004E4ED8 {
    s32 hi;
    u32 lo;
    u32 ns;
} V_004E4ED8;

typedef struct T_004E4ED8 {
    s32 f0;
    s32 f4;
    V_004E4ED8 v;
} T_004E4ED8;

extern s32 func_L39_004F02A0(T_004E4ED8 *out, s32 type, u8 *buf, s32 *plen, s32 buflen);

s32 func_L39_004E4ED8(V_004E4ED8 *v, s32 type, u8 *buf, s32 buflen) {
    T_004E4ED8 t;
    s32 len;

    if (v == 0) {
        return 0x2721;
    }
    t.v = *v;
    return func_L39_004F02A0(&t, type, buf, &len, buflen);
}
/* localdecomp:end func_L39_004E4ED8 */

/* localdecomp:start func_L39_004E4F28 */
typedef struct S_004E4F28 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} S_004E4F28;

extern S_004E4F28 *func_L39_004E5090(void);
extern void func_L39_004E5008(S_004E4F28 *);

s32 func_L39_004E4F28(S_004E4F28 *arg0) {
    S_004E4F28 *obj = func_L39_004E5090();

    func_L39_004E5008(obj);
    *obj = *arg0;
    return 0;
}
/* localdecomp:end func_L39_004E4F28 */
