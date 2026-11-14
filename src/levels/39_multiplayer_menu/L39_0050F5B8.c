#include "common.h"

/* localdecomp:start func_L39_0050F5B8 */
typedef struct {
    u8 *a;
    u32 b;
} P_0050F5B8;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    P_0050F5B8 pr;
    s32 f14;
    s32 f18;
    s32 f1C;
} A_0050F5B8;

typedef struct {
    s32 flags;
    s32 (*handler)(A_0050F5B8 *, void *);
    s32 f8;
    s32 tag;
    char *name;
} I_0050F5B8;

typedef struct O_0050F5B8 {
    s32 (**vt)(struct O_0050F5B8 *, s32 *, s32 *);
    u8 *f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} O_0050F5B8;

extern s32 func_L39_00510220(I_0050F5B8 *);
extern s32 func_L39_0050FDC8(s32 *, s32 *, s32 *, P_0050F5B8 *, s32, s32);
extern s32 func_L39_00510DB8(O_0050F5B8 *, s32 *, s32 *, s32);
extern s32 func_L39_0050D5B0(s32, I_0050F5B8 *, s32, s32, s32 *);
extern void func_L39_0050CE50(u32 *, I_0050F5B8 *);
extern s32 func_L39_0050D4C0(s32 *, s32, s32);
extern void func_L39_0050D780(s32 *);
extern s32 func_L39_00510008(s32 *, I_0050F5B8 *, void **, s32, s32, O_0050F5B8 *, s32, P_0050F5B8 *, s32 *);
extern s32 func_L39_004F7648(char *);
extern void *func_L39_004F7590(s32);
extern void func_L39_004F7660(void *, char *);
extern u8 D_L39_0046F400[];

s32 func_L39_0050F5B8(I_0050F5B8 *p, s32 a1, s32 a2, s32 a3, O_0050F5B8 *obj, s32 *plen, void **table, s32 *err)
{
    s32 flags;
    s32 cnt;
    s32 rc;
    s32 l48, l4c, l50, l54, l6c, l70;
    u32 l58;
    P_0050F5B8 pr;
    s32 s12;
    s32 s19;
    u32 s23;
    s32 len;
    u32 i;
    s32 *ent;

    *err = 0;
    flags = p->flags & ~0x200;
    l50 = 0;
    cnt = func_L39_00510220(p);
    l6c = 0;
    l70 = -1;
    if (obj && (a2 == 0 || (p->flags & 0x8800))) {
        rc = (*obj->vt)(obj, &a2, &a3);
        if (rc != 0)
            return func_L39_0050D5B0(rc, p, l50, -1, err);
        if (func_L39_0050FDC8(plen, &l48, &l4c, &pr, a2, a3) && (p->flags & 0x8000)) {
            rc = func_L39_00510DB8(obj, &a2, &a3, *plen);
            if (rc != 0)
                return func_L39_0050D5B0(rc, p, l50, -1, err);
        }
    }
    if (table[p->tag] == D_L39_0046F400) {
        *plen = 0;
        return 0;
    }
    rc = func_L39_0050FDC8(plen, &l48, &l4c, &pr, a2, a3);
    if (rc != 0) {
        if (rc == 0x800 && (flags & 0x800))
            return func_L39_0050D5B0(func_L39_00510008(plen, p, table, a2, a3, obj, l48, &pr, &l50), p, l50, -1, err);
        if (cnt == 0)
            return func_L39_0050D5B0(rc, p, l50, -1, err);
    }
    if (*plen == 0)
        l6c = l4c + 4;
    cnt = (s32)pr.a - a2;
    if ((flags & 0x1FF) != 0x102) {
        if (l48 != (flags & 0xFF)) {
            if ((flags & 0x4420) == 0x4420 && !(p[1].flags & 0x20) && l48 == (flags & 0xDF)) {
                rc = func_L39_0050F5B8(&p[1], a1, a2, *plen, obj, &l54, table, &l50);
                if (rc != 0)
                    return func_L39_0050D5B0(rc, p, l50, -1, err);
            } else {
                if (p->flags & 0x200) {
                    *plen = 0;
                    return 0;
                }
                return func_L39_0050D5B0(0x807, p, l50, -1, err);
            }
        }
        if (l48 & 0x20) {
            func_L39_0050CE50(&l58, p);
            for (i = 1; i < l58; i++) {
                if (p[i].flags != 0x103 && table[p[i].tag] != 0)
                    break;
            }
            if (i >= l58) {
                if (*plen == 0) {
                    rc = func_L39_0050D4C0(plen, a2, a3);
                    if (rc != 0)
                        return func_L39_0050D5B0(rc, p, l50, -1, err);
                    pr.b = *plen - l6c;
                }
            } else {
                if (*plen == 0)
                    pr.b = a3 - l6c;
                s12 = (flags & 0xC0) && !(flags & 0x1000);
                if (obj) {
                    pr.a = obj->f4;
                    obj->f14 += cnt;
                    i = obj->f14;
                } else
                    i = 0;
                s23 = 0;
                s19 = 1;
                while (s12 || (((flags & 0x400) ? (l70++, 1) : p[s19].flags != 0x103) && (*plen == 0 ? (pr.a[i] != 0 || pr.a[i + 1] != 0) : s23 < pr.b))) {
                    s32 rem = obj ? obj->f10 - obj->f14 : pr.b - i;
                    rc = func_L39_0050F5B8(&p[s19], a1, (s32)pr.a + i, rem, obj, &l54, table, &l50);
                    if (rc != 0)
                        return func_L39_0050D5B0(rc, p, l50, l70, err);
                    len = l54;
                    if (obj) {
                        pr.a = obj->f4;
                        i = obj->f14;
                    } else
                        i += len;
                    s23 += len;
                    if (s12)
                        break;
                    if (!(flags & 0x400)) {
                        func_L39_0050CE50(&l58, &p[s19]);
                        s19 += l58;
                    }
                }
                if (*plen == 0) {
                    if (obj) {
                        l6c = 2;
                        obj->f14 += l6c;
                    }
                    pr.b = i;
                    *plen = i + l6c;
                } else if (s23 != pr.b)
                    return func_L39_0050D5B0(0x806, p, l50, l70, err);
                if (!s12 && !(flags & 0x400) && p[s19].flags != 0x103) {
                    while (p[s19].flags != 0x103) {
                        if (!(p[s19].flags & 0x200) && table[p[s19].tag] != D_L39_0046F400) {
                            if (p[s19].name != 0) {
                                l50 = (s32)func_L39_004F7590(func_L39_004F7648(p[s19].name) + 1);
                                if (l50 != 0)
                                    func_L39_004F7660((void *)l50, p[s19].name);
                            }
                            return func_L39_0050D5B0(0x805, p, l50, l70, err);
                        }
                        func_L39_0050CE50(&l58, &p[s19]);
                        s19 += l58;
                    }
                }
            }
        }
    } else {
        if (*plen == 0) {
            rc = func_L39_0050D4C0(plen, a2, a3);
            if (rc != 0)
                return func_L39_0050D5B0(rc, p, l50, -1, err);
            pr.b = *plen - l6c;
        }
    }
    ent = (s32 *)table[p->tag];
    if (ent != 0) {
        if (p->handler != 0) {
            A_0050F5B8 args;
            args.f0 = l48;
            args.f4 = a2 + 1;
            args.f8 = a1;
            args.f14 = a2;
            args.f18 = *plen;
            args.pr = pr;
            args.f1C = 0;
            rc = p->handler(&args, ent);
            l50 = args.f1C;
            func_L39_0050D780(&l50);
            if (rc != 0)
                return func_L39_0050D5B0(rc, p, l50, l70, err);
            if (obj && (!(p->flags & 0x20) || p[1].flags == 0x103))
                obj->f14 += *plen;
        } else {
            *ent = a2;
            ((s32 *)table[p->tag])[1] = *plen;
            if (obj)
                obj->f14 += *plen;
        }
    }
    if (p->flags & 0x8000) {
        a2 += *plen;
        rc = (*obj->vt)(obj, &a2, &a3);
        if (rc != 0)
            return rc;
    }
    return 0;
}
/* localdecomp:end func_L39_0050F5B8 */

INCLUDE_ASM("asm/levels", func_L39_0050FDC8);

INCLUDE_ASM("asm/levels", func_L39_00510008);

INCLUDE_ASM("asm/levels", func_L39_00510220);

/* localdecomp:start func_L39_00510298 */
extern void func_L39_004F74E8(void *, int, int);
extern int func_L39_00515BD8(void *);

void func_L39_00510298(char *a, int b)
{
    func_L39_004F74E8(a + 4, 0, 0x18);
    if (func_L39_00515BD8(a) == 0)
        *(int *)(a + 0x1C) = b;
}
/* localdecomp:end func_L39_00510298 */

/* localdecomp:start func_L39_005102E8 */
typedef struct {
    s32 f0;
    s32 f4;
    u32 count;
    void **items;
    s32 size;
    void *buf;
} S_005102E8;

extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_004F7620(void *);
extern void func_L39_00515C28(void *);

void func_L39_005102E8(S_005102E8 *a0) {
    u32 i;

    if (a0->buf != 0) {
        func_L39_004F74E8(a0->buf, 0, a0->size);
        func_L39_004F7620(a0->buf);
    }
    for (i = 0; i < a0->count; i++) {
        func_L39_004F7620(a0->items[i]);
    }
    func_L39_004F7620(a0->items);
    if (a0->f0 != 0) {
        func_L39_00515C28(a0);
    }
}
/* localdecomp:end func_L39_005102E8 */
