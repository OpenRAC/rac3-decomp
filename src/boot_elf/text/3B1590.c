#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003B29D8(void *);
extern s32 func_003B16E0(u8 *, void **);
extern s32 func_003B17F8();
extern void func_003B1710(u8 *, s32);
extern s32 func_003B1750(u8 *, u8 **);
extern s32 func_003B1790();
extern s32 func_003B29E8(void *);
extern s32 func_003B2A68();
extern s32 func_003B2B38(void *);
extern void func_003B16C0();
extern s32 func_003B2830(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003B2B80();
extern s32 func_003B16D8();
extern s32 func_003B29A0();
extern s32 func_003B17D0();
extern s32 func_003B1590();
/* --- end of declarations from other files --- */

/* declarations of 3B1208.c's earlier functions (tools/port_from_us.py) */
typedef struct { u8 p0[8]; s32 f8; s32 fC; unsigned long f10; unsigned long f18; } O_ABA48;
extern s32 D_001DA0B4_003B13A8;
extern u8 D_001D87C8[];
extern s32 func_003B2958_003B13A8();
extern s32 func_003B2A00_003B13A8();
extern s32 func_003B03F8();
extern s32 func_003B2978_003B13A8();
typedef struct { u8 p0[8]; u32 f8; s32 fC; } O_ABB60;
extern s32 D_001DA0B8;

/* localdecomp:start func_003B1590 */
extern void func_11A0B0();
s32 func_003B1590(u8 *a, s32 sz, u8 *b, s32 off, u8 *src1, s32 len1, u8 *src2, s32 len2) {
    s32 d;
    if (sz + off < len1 + len2) return 0;
    if (len1 >= sz) {
        d = sz - len1;
        func_11A0B0(a, src1, sz);
        func_11A0B0(b, src1 + sz, len1 - sz);
        func_11A0B0(b + len1 - sz, src2, len2);
    } else {
        d = sz - len1;
        if (len2 >= d) {
            func_11A0B0(a, src1, len1);
            func_11A0B0(a + len1, src2, d);
            func_11A0B0(b, src2 + sz - len1, len2 - d);
        } else {
            func_11A0B0(a, src1, len1);
            func_11A0B0(a + len1, src2, len2);
        }
    }
    return len1 + len2;
}
/* localdecomp:end func_003B1590 */

/* localdecomp:start func_003B16C0 */
void func_003B16C0(void *a0) {
    u8 *p = (u8 *)a0 + 0x50000;
    *(s32 *)(p + 8) = 0x50000;
    *(s32 *)(p + 0) = 0;
    *(s32 *)(p + 4) = 0;
}
/* localdecomp:end func_003B16C0 */

/* localdecomp:start func_003B16D8 */
s32 func_003B16D8(void) {
}
/* localdecomp:end func_003B16D8 */

/* localdecomp:start func_003B16E0 */
s32 func_003B16E0(u8 *p, void **out) {
    u8 *q = p + 0x50000;
    s32 n = *(s32 *)(q + 8) - *(s32 *)(q + 4);
    if (n != 0) {
        *out = p + *(s32 *)q;
    }
    return n;
}
/* localdecomp:end func_003B16E0 */

/* localdecomp:start func_003B1710 */
typedef struct { s32 a, b, c; } R_3ABDB0;
void func_003B1710(u8 *p, s32 n) {
    R_3ABDB0 *r = (R_3ABDB0 *)(p + 0x50000);
    s32 m = r->c - r->b;
    if (n < m) m = n;
    r->b += m;
    r->a = (r->a + m) % r->c;
}
/* localdecomp:end func_003B1710 */

/* localdecomp:start func_003B1750 */
typedef struct { s32 a, b, c; } R_3ABDF0;
s32 func_003B1750(u8 *p, u8 **out) {
    R_3ABDF0 *r = (R_3ABDF0 *)(p + 0x50000);
    if (r->b != 0) *out = p + (r->a - r->b + r->c) % r->c;
    return r->b;
}
/* localdecomp:end func_003B1750 */

/* localdecomp:start func_003B1790 */
typedef struct { u8 pad[0x50004]; s32 x; } S_3ABE30;
s32 func_003B1790(S_3ABE30 *a, s32 n) {
    s32 m = a->x;
    if (n < m) m = n;
    a->x -= m;
    return m;
}
/* localdecomp:end func_003B1790 */

/* localdecomp:start func_003B17B8 */
extern s32 D_001D87E0;
s32 func_003B17B8(s32 *p, s32 b, s32 c) { D_001D87E0 = 0; p[2] = b; p[0] = c; return 1; }
/* localdecomp:end func_003B17B8 */

/* localdecomp:start func_003B17D0 */
extern s32 func_13CEB0();
extern void func_13CDF0(s32);
 
s32 func_003B17D0(void) {
    func_13CEB0();
    func_13CDF0(0);
    return 1;
}
/* localdecomp:end func_003B17D0 */

/* localdecomp:start func_003B17F8 */
__asm__(".extern D_001D87E0, 4");
extern s32 D_001D87E0;
typedef struct { u8 p0[8]; s32 f8; } P_3ABE98;
extern char D_001D87E8[];
extern char D_001D8800[];
extern void func_11F0A0();
extern s32 func_12BC00();
extern void func_11AF48();
extern s32 func_13CD28();
s32 func_003B17F8(P_3ABE98 *p, s32 b, s32 c) {
    s32 r;
    u8 buf[3];
    r = 0;
    if (D_001D87E0 != 0) {
        func_11F0A0(2);
        if (((s32 (*)(s32))func_13CDF0)(1) == 0) {
            D_001D87E0 = 0;
            if (func_12BC00() == 0) {
                r = (c >> 11) << 11;
                p->f8 = p->f8 + (c >> 11);
            } else {
                func_11AF48(D_001D87E8);
            }
        }
    } else {
        buf[0] = 100;
        buf[1] = 0;
        buf[2] = 0;
        func_13CDF0(0);
        if (func_13CD28(p->f8, c >> 11, b, buf) != 0) {
            D_001D87E0 = 1;
        } else {
            func_11AF48(D_001D8800);
        }
        r = 0;
    }
    return r;
}
/* localdecomp:end func_003B17F8 */

/* localdecomp:start func_003B18E8 */
typedef struct { s32 f0; s32 f4; s32 f8; } S_ABF88;
s32 func_003B18E8(S_ABF88 *p, s32 a1) {
    s32 t = p->f8 * 0x10 + 0x10;
    s32 addr = (p->f4 + t) & 0xFFFFFFF;
    if (a1 == addr) {
        return 0;
    }
    return (u32)(a1 - p->f0) >> 11;
}
/* localdecomp:end func_003B18E8 */

/* localdecomp:start func_003B1930 */
extern void func_124920(void);
extern void func_124970(void);
void func_003B1930(s32 a) {
    func_124920();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = a;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    func_124970();
}
/* localdecomp:end func_003B1930 */

/* localdecomp:start func_003B19A0 */
extern void func_124920(void);
extern void func_124970(void);
void func_003B19A0(s32 a) {
    func_124920();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B400 = a;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    func_124970();
}
/* localdecomp:end func_003B19A0 */

/* localdecomp:start func_003B1A10 */
void func_003B1A10(unsigned long *p, unsigned long a, unsigned long b, unsigned long c) {
    *p = (a << 32) | ((b << 32) >> 4) | ((c << 32) >> 32);
}
/* localdecomp:end func_003B1A10 */

/* localdecomp:start func_003B1A38 */
typedef struct { s32 f0; s32 f4; s32 f8; u8 pC[0xC]; s32 f18; u8 p1C[0x24]; s32 f40; u8 p44[4]; long f48; s32 f50; s32 f54; } O_3AC0D8;
typedef struct { s32 w0; s32 w4; s32 w8; s32 pad[5]; } St_3AC0D8;
extern s32 func_11EE20();
extern s32 func_003B1AB0();
s32 func_003B1A38(O_3AC0D8 *o, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{  St_3AC0D8 *new_var;
  St_3AC0D8 st;
  o->f0 = a1;
  o->f8 = a3;
  o->f50 = a4;
  o->f54 = a5;
  st.w8 = 1;
  o->f4 = (a2 & 0xFFFFFFF) | 0x20000000;
  st.w4 = 1;
  new_var = &st;
  o->f18 = a3 << 11;
  o->f40 = func_11EE20(new_var);
  ((s32 (*)(void *))func_003B1AB0)(o);
  o->f48 = 0;
  return 1;
}
/* localdecomp:end func_003B1A38 */

/* localdecomp:start func_003B1AB0 */
extern void func_003B1A10_003B1AB0();
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; u8 p18[0x2C]; s32 f44; u8 p48[8]; s32 f50; s32 f54; s32 f58; s32 f5C; } O_3AC150;
s32 func_003B1AB0(O_3AC150 *o) {
    s32 i = 0;
    o->f44 = 1;
    o->fC = 0;
    o->f10 = 0;
    o->f14 = 0;
    o->f58 = 0;
    o->f5C = 0;
    if (o->f54 > 0) {
        long m = -1;
        s32 off = 0;
        do {
            i++;
            *(long *)(off + o->f50) = m;
            *(long *)(off + o->f50 + 8) = m;
            *(s32 *)(off + o->f50 + 0x10) = 0;
            *(s32 *)(off + o->f50 + 0x14) = 0;
            off += 0x18;
        } while (i < o->f54);
    }
    i = 0;
    while (i < o->f8) {
        func_003B1A10_003B1AB0((unsigned long *)(o->f4 + i * 16), (o->f0 + i * 0x800) & 0xFFFFFFF, 3, 0x80);
        i++;
    }
    func_003B1A10_003B1AB0((unsigned long *)(o->f4 + i * 16), o->f4 & 0xFFFFFFF, 2, 0);
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000B410 = o->f0 & 0xFFFFFFF;
    *(volatile u32 *)0x1000B430 = o->f4 & 0xFFFFFFF;
    func_003B19A0(5);
    return 1;
}
/* localdecomp:end func_003B1AB0 */

/* localdecomp:start func_003B1C10 */
extern void func_0011EE40(s32);
extern void func_0011EE60(s32);
void func_003B1C10(arg0, arg1, arg2, arg3, arg4)
    void *arg0;
    s32 *arg1;
    s32 *arg2;
    s32 *arg3;
    s32 *arg4;
{
  s32 temp_2;
  s32 temp_3;
  s32 temp_4;
  s32 temp_5;
  s32 temp_5_2;
  s32 temp_6;
  s32 temp_hi;
  func_0011EE60(*((s32 *) (((u8 *) arg0) + 0x40)));
  temp_4 = *((s32 *) (((u8 *) arg0) + 0x10));
  temp_5 = *((s32 *) (((u8 *) arg0) + 0x14));
  temp_6 = temp_4 + 2;
  temp_3 = *((s32 *) (((u8 *) arg0) + 0x18));
  temp_hi = ((s32) ((((*((s32 *) (((u8 *) arg0) + 0xC))) + temp_4) << 0xB) + temp_5)) % temp_3;
  temp_5_2 = (((*((s32 *) (((u8 *) arg0) + 8))) - temp_6) << 0xB) - temp_5;
  ;
  if ((temp_3 - temp_hi) >= temp_5_2)
  {
    *arg1 = (*((s32 *) (((u8 *) arg0) + 0))) + temp_hi;
    *arg2 = temp_5_2;
    *arg3 = 0;
    *arg4 = 0;
  }
  else
  {
    *arg1 = (*((s32 *) (((u8 *) arg0) + 0))) + temp_hi;
    *arg2 = (*((s32 *) (((u8 *) arg0) + 0x18))) - temp_hi;
    *arg3 = *((s32 *) (arg0 + 0));
    *arg4 = temp_5_2 - ((*((s32 *) (((u8 *) arg0) + 0x18))) - temp_hi);
  }
  temp_4 = temp_6;
  ((void (*)(s32, s32, s32, s32)) func_0011EE40)(*((s32 *) (((u8 *) arg0) + 0x40)), temp_5_2, temp_4, temp_hi);
}
/* localdecomp:end func_003B1C10 */

/* localdecomp:start func_003B1D00 */
typedef struct { u8 pad[0x14]; s32 w14; u8 pad2[0x28]; s32 w40; u8 pad3[4]; unsigned long d48; } S_AC3A0;
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
void func_003B1D00(p, n) S_AC3A0 *p; s32 n; {  /* K&R: older callers use unprototyped calls */
    func_11EE60(p->w40);
    p->w14 += n;
    p->d48 = n + p->d48;
    func_11EE40(p->w40);
}
/* localdecomp:end func_003B1D00 */

/* localdecomp:start func_003B1D58 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; u8 p18[0x28]; s32 f40; s32 f44; } O_3AC3F8;
extern void func_003B1A10_003B1D58();
extern s32 func_003B03F8();
extern u8 D_001D8818[];
s32 func_003B1D58(O_3AC3F8 *o) {
    s32 flag = 0;
    u32 reg;
    s32 pos;
    s32 t;
    s32 n;
    s32 cur;
    s32 idx;
    s32 i;
    func_11EE60(o->f40);
    if (o->f44 == 0) {
        func_003B03F8(D_001D8818);
        return 0;
    }
    func_003B19A0(5);
    reg = *(volatile u32 *)0x1000B400;
    pos = func_003B18E8(o, *(volatile u32 *)0x1000B410);
    t = (pos + o->f8 - o->fC) % o->f8;
    n = o->f14 / 0x800;
    o->f14 = o->f14 - n * 0x800;
    o->fC = (o->fC + t) % o->f8;
    o->f10 = o->f10 - t;
    idx = (o->fC + o->f10) % o->f8;
    if (n > 0) {
        s32 m1 = o->f8 - 1;
        s32 k = (o->fC + o->f10 + m1) % o->f8;
        func_003B1A10_003B1D58(o->f4 + k * 16, o->f0 + k * 0x800, 3, 0x80);
        flag = 1;
    }
    {
        s32 c2 = idx;
        for (i = 0; i < n; i++) {
            s32 m = i != n - 1 ? 3 : 0;
        func_003B1A10_003B1D58(o->f4 + c2 * 16, o->f0 + c2 * 0x800, m, 0x80);
            c2 = (c2 + 1) % o->f8;
        }
    }
    o->f10 = o->f10 + n;
    if (o->f10 != 0) {
        if (flag) {
            reg = (reg & 0xFFFFFFF) | 0x30000000;
        }
        func_003B19A0(reg | 0x100);
    }
    func_11EE40(o->f40);
    return 1;
}
/* localdecomp:end func_003B1D58 */

/* localdecomp:start func_003B1F40 */
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
extern void func_003B19A0(s32);
extern void func_003B1930(s32);
s32 func_003B1F40(s32 *p) {
    func_11EE60(p[0x10]);
    p[0x11] = 0;
    func_003B19A0(5);
    p[7] = *(volatile s32 *)0x1000B410;
    p[8] = *(volatile s32 *)0x1000B430;
    p[9] = *(volatile s32 *)0x1000B420;
    p[10] = *(volatile s32 *)0x1000B400;
    if (*(volatile s32 *)0x10002010 & 0xF0) { do {} while (*(volatile s32 *)0x10002010 & 0xF0); }
    func_003B1930(0);
    p[11] = *(volatile s32 *)0x1000B010;
    p[12] = *(volatile s32 *)0x1000B020;
    p[13] = *(volatile s32 *)0x1000B000;
    p[14] = *(volatile s32 *)0x10002020;
    p[15] = *(volatile s32 *)0x10002010;
    func_11EE40(p[0x10]);
    return 1;
}
/* localdecomp:end func_003B1F40 */

/* localdecomp:start func_003B2050 */
typedef struct { u32 f0; u32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; u32 f1C; u32 f20; u32 f24; u32 f28; u32 f2C; u32 f30; u32 f34; u32 f38; u32 f3C; s32 f40; s32 f44; } O_3AC6F0;
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
extern void func_003B19A0(s32);
extern void func_003B1930(s32);
extern s32 func_003B18E8();
s32 func_003B2050(O_3AC6F0 *p) {
    u32 v = p->f38;
    u32 bits = v & 0x7F;
    u32 t = ((v >> 16) & 3) + ((v >> 8) & 0xF);
    u32 madr = p->f1C - t * 16;
    u32 qwc = p->f24 + t;
    u32 chcr = p->f28 | 0x100;
    u32 tadr = p->f20;
    func_11EE60(p->f40);
    if (madr < p->f0) {
        s32 tag;
        s32 m;
        qwc = (p->f0 - madr) >> 4;
        tadr = p->f4 & 0xFFFFFFF;
        madr += p->f8 << 11;
        tag = 0;
        if (p->f1C != p->f0) {
            tag = p->f1C == p->f0 + (p->f8 << 11) ? 0 : 3;
        }
        chcr = (p->f28 & 0xFFFFFFF) | (tag << 28) | 0x100;
        m = (p->f8 - p->fC) % p->f8;
        if (m < 0 || m >= p->f10) {
            p->fC = p->f8 - 1;
            p->f10 = p->f10 + 1;
        }
    } else {
        s32 a = func_003B18E8(p, p->f1C);
        s32 b = func_003B18E8(p, madr);
        if (a != b) {
            s32 tag;
            s32 m;
            tadr = (p->f4 + a * 16) & 0xFFFFFFF;
            qwc = (p->f0 + (a << 11) - madr) >> 4;
            tag = p->f0 + (p->f1C - p->f0) % (u32)(p->f8 << 11) == p->f0 + (((p->fC + p->f10) % p->f8) << 11) ? 0 : 3;
            chcr = (p->f28 & 0xFFFFFFF) | (tag << 28) | 0x100;
            m = (b + p->f8 - p->fC) % p->f8;
            if (m < 0 || m >= p->f10) {
                p->fC = b;
                p->f10 = p->f10 + 1;
            }
        }
    }
    if (p->f2C != 0 && p->f30 != 0) {
        *(volatile u32 *)0x1000B010 = p->f2C;
        *(volatile u32 *)0x1000B020 = p->f30;
        func_003B1930(p->f34 | 0x100);
    }
    if (p->f10 != 0) {
        if (*(volatile s32 *)0x10002010 < 0) { do {} while (*(volatile s32 *)0x10002010 < 0); }
        *(volatile u32 *)0x10002000 = bits;
        if (*(volatile s32 *)0x10002010 < 0) { do {} while (*(volatile s32 *)0x10002010 < 0); }
    }
    *(volatile u32 *)0x1000B410 = madr;
    *(volatile u32 *)0x1000B430 = tadr;
    *(volatile u32 *)0x1000B420 = qwc;
    if (p->f10 != 0) {
        func_003B19A0(chcr);
    }
    *(volatile u32 *)0x10002010 = p->f3C;
    p->f44 = 1;
    func_11EE40(p->f40);
    return 1;
}
/* localdecomp:end func_003B2050 */

/* localdecomp:start func_003B2360 */
extern void func_003B19A0(s32);
extern void func_11EE30(s32);
s32 func_003B2360(u8 *p) {
    func_003B19A0(5);
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000B410 = 0;
    *(volatile u32 *)0x1000B430 = 0;
    func_11EE30(*(s32 *)(p + 0x40));
    return 1;
}
/* localdecomp:end func_003B2360 */

/* localdecomp:start func_003B23B8 */
extern void func_0011EE60(s32);
extern void func_0011EE40(s32);
s32 func_003B23B8(u8 *p) {
    s32 r;
    func_0011EE60(*(s32 *)(p + 0x40));
    r = (*(s32 *)(p + 0x10) << 11) + *(s32 *)(p + 0x14);
    func_0011EE40(*(s32 *)(p + 0x40));
    return r;
}
/* localdecomp:end func_003B23B8 */

/* localdecomp:start func_003B2408 */
typedef struct { u8 pad[0x14]; s32 w14; u8 pad2[0x28]; s32 w40; } S_ACAA8;
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
void func_003B2408(S_ACAA8 *p) {
    func_11EE60(p->w40);
    p->w14 = (p->w14 + 0x7FF) / 0x800 * 0x800;
    func_11EE40(p->w40);
}
/* localdecomp:end func_003B2408 */

/* localdecomp:start func_003B2460 */
typedef struct { long f0; long f8; s32 f10; s32 f14; } S_ACB00b;
typedef struct { u8 p0[0x8]; s32 f8; u8 pC[0x44]; S_ACB00b *f50; s32 f54; s32 f58; s32 f5C; } S_ACB00a;
s32 func_003B2460(S_ACB00a *a, S_ACB00b *b) {
    s32 size;
    s32 idx;
    s32 ok;
    S_ACB00b *e;
    s32 t;
    s32 pos;
    s32 rem;
    s32 c;
    long lim;

    ok = 1;
    idx = (a->f5C - a->f58 + a->f54) % a->f54;
    size = a->f8 << 11;
    if (a->f58 > 0) {
        e = &a->f50[idx];
        if (e->f14 != 0 && b->f14 != 0) {
            lim = -1;
            do {
                pos = e->f10;
                if ((pos + size - b->f10) % size < b->f14) {
                    t = b->f10 + b->f14 - pos;
                    if (e->f14 < t) t = e->f14;
                    rem = e->f14 - t;
                    e->f14 = rem;
                    e->f10 = (pos + t) % size;
                    if (rem == 0) {
                        if (e->f0 >= 0) {
                            e->f0 = lim;
                            e->f8 = lim;
                            e->f10 = 0;
                            e->f14 = 0;
                        }
                        c = a->f58 - 1;
                        if (c < 0) c = 0;
                        a->f58 = c;
                    }
                } else {
                    ok = 0;
                }
                idx = (idx + 1) % a->f54;
                if (!ok) break;
                {
                    s32 off = idx * sizeof(S_ACB00b);
                    /* fence: keeps retail's $v0/$v1 for the offset and the f50 load */
                    __asm__("" : "+r"(off));
                    e = (S_ACB00b *)((u8 *)a->f50 + off);
                }
                pos = e->f14;
                if (pos == 0) break;
            } while (b->f14 != 0);
        }
    }
    return 0;
}
/* localdecomp:end func_003B2460 */

/* localdecomp:start func_003B2590 */
typedef struct { long f0; long f8; s32 f10; s32 f14; } S_CCb;
typedef struct { u8 p0[0x40]; s32 f40; u8 p44[0xC]; S_CCb *f50; s32 f54; s32 f58; s32 f5C; } S_CCa;
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
extern s32 func_003B2460();
s32 func_003B2590(S_CCa *a, S_CCb *b) {
    s32 r = 0;
    func_11EE60(a->f40);
    if (a->f58 < a->f54) {
        func_003B2460(a, b);
        if (b->f0 >= 0 || b->f8 >= 0) {
        a->f50[a->f5C].f0 = b->f0;
        a->f50[a->f5C].f8 = b->f8;
        a->f50[a->f5C].f10 = b->f10;
        a->f50[a->f5C].f14 = b->f14;
        a->f58 = a->f58 + 1;
        a->f5C = (a->f5C + 1) % a->f54;
        }
        r = 1;
    }
    func_11EE40(a->f40);
    return r;
}
/* localdecomp:end func_003B2590 */

/* localdecomp:start func_003B2698 */
typedef struct { long f0; long f8; s32 f10; s32 f14; } E_3ACD38;
typedef struct { u8 *f0; u8 p4[4]; s32 f8; u8 pC[0x2C]; s32 f38; u8 p3C[4]; s32 f40; u8 p44[0xC]; E_3ACD38 *f50; s32 f54; s32 f58; s32 f5C; } S_3ACD38;
typedef struct { long a, b; } R_3ACD38;
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
s32 func_003B2698(S_3ACD38 *p, R_3ACD38 *out) {
    s32 found = 0;
    u32 pos;
    s32 size;
    s32 n, i, idx;
    u32 st;
    s32 off;
    s32 rem, head;
    pos = *(volatile u32 *)0x1000B410;
    st = *(volatile u32 *)0x10002020;
    off = p->f38 & 0x7F;
    size = p->f8 << 11;
    pos -= (((st >> 16) & 3) + ((st >> 8) & 0xF)) << 4;
    func_11EE60(p->f40);
    out->a = -1;
    out->b = -1;
    rem = (pos + (off >> 3) + size - (u32)p->f0) % size;
    n = p->f58;
    head = p->f5C;
    for (i = 0; i < n && !found; i++) {
        idx = (head - n + p->f54 + i) % p->f54;
        if ((rem + size - p->f50[idx].f10) % size < p->f50[idx].f14) {
            found = 1;
            out->a = p->f50[idx].f0;
            out->b = p->f50[idx].f8;
            p->f50[idx].f0 = -1;
            p->f50[idx].f8 = -1;
            p->f58 -= p->f58 < 2 ? p->f58 : 1;
        }
    }
    func_11EE40(p->f40);
    return 1;
}
/* localdecomp:end func_003B2698 */

/* localdecomp:start func_003B2830 */
extern void func_003B2998(void *);
extern s32 func_003B2D90();
extern s32 func_003B2DB8();
extern s32 func_003B2DE8();
extern s32 func_003B2E10();
extern s32 func_003B2E38();
extern void func_003B1A38_003B2830(s32, s32, s32, s32, s32, s32);
extern void func_001350A8(void);
extern void func_00135D08(s32, s32, void *, s32);
s32 func_003B2830(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    func_001350A8();
    func_00135D08(arg0, 0, &func_003B2D90, 0);
    func_00135D08(arg0, 1, &func_003B2DB8, 0);
    func_00135D08(arg0, 2, &func_003B2DE8, 0);
    func_00135D08(arg0, 3, &func_003B2E10, 0);
    func_00135D08(arg0, 5, &func_003B2E38, 0);
    func_003B2998((void *)arg0);
    func_003B1A38_003B2830(arg0 + 0x48, arg3, arg4, arg5, arg6, arg7);
    return 1;
}
/* localdecomp:end func_003B2830 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003B2930);

/* localdecomp:start func_003B2938 */
extern void func_139E50();
 
s32 func_003B2938(void) {
    func_139E50();
    return 1;
}
/* localdecomp:end func_003B2938 */

/* localdecomp:start func_003B2958 */
s32 func_003B2958(s32 arg0) {
    func_003B1C10(arg0 + 0x48);
}
/* localdecomp:end func_003B2958 */

/* localdecomp:start func_003B2978 */
s32 func_003B2978(s32 arg0) {
    func_003B1D00(arg0 + 0x48);
}
/* localdecomp:end func_003B2978 */

/* localdecomp:start func_003B2998 */
void func_003B2998(void *p) {
    *(s32 *)((u8 *)p + 0xA8) = 0;
}
/* localdecomp:end func_003B2998 */

/* localdecomp:start func_003B29A0 */
extern void func_00135C00(u8 *);
s32 func_003B29A0(u8 *p) {
    func_003B2360(p + 0x48);
    func_00135C00(p);
    return 1;
}
/* localdecomp:end func_003B29A0 */

/* localdecomp:start func_003B29D8 */
void func_003B29D8(void *a0) {
    *(s32 *)((u8 *)a0 + 168) = 1;
}
/* localdecomp:end func_003B29D8 */

/* localdecomp:start func_003B29E8 */
s32 func_003B29E8(void *p) {
    return *(s32 *)((u8 *)p + 0xA8);
}
/* localdecomp:end func_003B29E8 */

/* localdecomp:start func_003B29F0 */
s32 func_003B29F0(void *a0, s32 a1) {
    s32 old = *(s32 *)((u8 *)a0 + 168);
    *(s32 *)((u8 *)a0 + 168) = a1;
    return old;
}
/* localdecomp:end func_003B29F0 */

typedef struct { unsigned long a, b; s32 c, d; } S_3AD0A0;
extern u8 *D_001DA0B4[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B2A00);

/* localdecomp:start func_003B2A40 */
s32 func_003B2A40(s32 arg0) {
    func_003B23B8(arg0 + 0x48);
}
/* localdecomp:end func_003B2A40 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003B2A60);

typedef struct { char c[4]; } S4_3AD108;
typedef struct { u8 p0[0x48]; u8 p48[0x60]; s32 fA8; } S_3AD108;
extern S4_3AD108 D_001D8830[];
extern s32 D_001DA0B4_003B2A68;
extern s32 func_003B2E80();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B2A68);

/* localdecomp:start func_003B2B38 */
extern s32 func_00135CF0(void *);
s32 func_003B2B38(void *p) {
    s32 r = 0;
    if (func_003B2A40(p) == 0) r = func_00135CF0(p) != 0;
    return r;
}
/* localdecomp:end func_003B2B38 */

extern void func_003B3010();
extern s32 D_001DA088;
extern s32 *D_001DA088_003B2B80[];
/* localdecomp:start func_003B2B80 */
extern s32 func_003B29F0();
extern s32 func_003B2BE8();
void func_003B2B80(s32 arg0) {
    volatile s32 *p;
    s32 x;
    func_003B1AB0(arg0 + 0x48);
    func_003B3010(D_001DA088);
    func_003B2BE8(arg0);
    p = (volatile s32 *)D_001DA088_003B2B80[0];
    do { x = p[3]; __asm__ volatile("nop
	nop
	nop
	nop"); } while (x != 0);
    func_003B29F0(arg0, 3);
}
/* localdecomp:end func_003B2B80 */

/* localdecomp:start func_003B2BE8 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; } S_3AD288;
__asm__(".extern D_001DA088_003B2BE8, 16");
extern S_3AD288 *D_001DA088_003B2BE8;
extern u8 D_001D8850[];
extern u8 D_001D8838[];
extern s32 func_003B30A8();
extern void func_003B0140();
extern s32 func_135C10();
extern s32 func_135CE0();
extern void func_135C60();
extern void func_003B3038();
extern void func_003B0F70();
extern s32 func_003B29E8();
extern void func_11AF48();
extern s32 func_003B03F8();
s32 func_003B2BE8(s32 *a) {
    s32 ret = 1;
    s32 v, h, w, hh;
    while (func_135CE0(a) == 0) {
        if (func_003B29E8(a) == 1) {
            ret = -1;
            func_11AF48(D_001D8838);
            break;
        }
        while ((v = func_003B30A8(D_001DA088)) == 0) {
            func_003B0140();
        }
        if (func_135C10(a, v, 0x340) < 0) {
            func_003B03F8(D_001D8850);
        }
        if (a[2] == 0) {
            S_3AD288 *p;
            hh = a[0];
            w = a[1];
            h = 0;
            p = (S_3AD288 *)D_001DA088;
            if (h < p->x10) {
                do {
                    func_003B0F70(p->x4 + h * 0x27E40 + 0x40, p->x0 + h * 0xD0000, 0, hh, w);
                    func_003B0F70(D_001DA088_003B2BE8->x4 + h * 0x27E40 + 0x13F40, D_001DA088_003B2BE8->x0 + h * 0xD0000, 1, hh, w);
                    h++;
                    p = D_001DA088_003B2BE8;
                } while (h < p->x10);
            }
        }
        func_003B3038(D_001DA088);
        func_003B0140();
    }
    func_135C60(a);
    return ret;
}
/* localdecomp:end func_003B2BE8 */
