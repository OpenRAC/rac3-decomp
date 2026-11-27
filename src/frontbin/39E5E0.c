#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0039E5E0();
typedef struct {
    s32 port;  s32 slot;  s32 type;  s32 free;
    s32 f10;   s32 f14;   s16 f18;   s16 f1A;   s32 f1C;
    s32 f20;   s32 f24;   s32 f28;   s32 f2C;   s32 f30;
    u8 p34[0x18]; s32 f4C; u8 p50[0x18]; s32 f68; u8 p6C[0x18]; s32 f84; u8 p88[0x18];
} MC_397490;
typedef struct {
    MC_397490 c[2];
    s32 f140, f144, f148, f14C, f150, f154, f158, f15C, f160, f164, f168, f16C, f170, f174, f178, f17C, f180, f184, f188;
} S_397490;
extern S_397490 D_142430_0039C410;
extern s32 func_0039E788();
extern void func_0039E8E0();
extern s32 func_0039E998();
/* --- end of declarations from other files --- */

/* localdecomp:start func_0039E5E0 */
extern u8 D_00332388[];
extern u8 D_00332618[];
extern s32 func_0039E6A8();
extern s32 func_0039E7C8();
void func_0039E5E0(u8 *p) {
    s32 i;
    *(s32 *)p = func_0039E6A8(D_00332388);
    *(s32 *)(p + 4) = func_0039E6A8(D_00332618);
    p += 8;
    p += func_0039E7C8(p, 0, D_00332388);
    for (i = 0; i < 0x25; i++) {
        p += func_0039E7C8(p, i, D_00332618);
    }
}
/* localdecomp:end func_0039E5E0 */

/* localdecomp:start func_0039E688 */
extern void func_12DA60(void);
void func_0039E688(void) {
    func_12DA60();
}
/* localdecomp:end func_0039E688 */

/* localdecomp:start func_0039E6A8 */
s32 func_0039E6A8(s32 *p) {
    s32 n = 8;
    if (p[0] != 0) {
        do {
            n += 8;
            n += p[1];
            p += 4;
            n = (n + 3) & ~3;
        } while (p[0] != 0);
    }
    return n + 8;
}
/* localdecomp:end func_0039E6A8 */

/* localdecomp:start func_0039E6E0 */
extern u8 D_00332388[];
u16 func_0039E6E0(u8 *p, u32 n) {
    u8 *end;
    s32 r;
    s32 k;
    if ((u32)func_0039E6A8((s32 *)D_00332388) < n) return 0;
    end = p + n;
    r = 0xEDB88320;
    for (; p < end; p++) {
        r ^= *p << 8;
        for (k = 7; k >= 0; k--) {
            if (r & 0x8000) r = (r << 1) ^ 0x1F45;
            else r = r << 1;
        }
    }
    return r;
}
/* localdecomp:end func_0039E6E0 */

/* localdecomp:start func_0039E788 */
s32 func_0039E6E0_0039E788(void *, s32);

s32 func_0039E788(s32 *arg0) {
    s32 ret = 0;
    s32 v = arg0[1];
    s32 key = arg0[0];

    if (v != 0) {
        ret = func_0039E6E0_0039E788(arg0 + 2, key) == v;
    }
    return ret;
}
/* localdecomp:end func_0039E788 */

/* localdecomp:start func_0039E7C8 */
extern void func_0038CB78(void *, s32, s32);
extern void func_0038CC88();
extern u16 func_0039E6E0(u8 *p, u32 n);
s32 func_0039E7C8(u8 *dst, s32 n, s32 *e) {
    s32 off = 0;
    u8 *p = dst + 8;
    s32 *q;
    s32 t, u, w;
    if (e[0] != 0) {
        q = e;
        do {
            off += 8;
            w = n * q[1];
            u = q[0];
            t = u + w;
            *(s32 *)p = q[2];
            *(s32 *)(p + 4) = q[1];
            p += 8;
            if (q[2] == 0x1770) {
                func_0038CB78(p, 0, q[1]);
            } else {
                func_0038CC88(p, t, q[1]);
            }
            p += q[1];
            off += q[1];
            q += 4;
            p = (u8 *)((s32)p + 3 & ~3);
            off = (off + 3) & ~3;
        } while (q[0] != 0);
    }
    off += 8;
    *(s32 *)(p + 4) = 0;
    *(s32 *)p = -1;
    *(s32 *)(dst + 4) = func_0039E6E0(dst + 8, off);
    *(s32 *)dst = off;
    return off + 8;
}
/* localdecomp:end func_0039E7C8 */

/* localdecomp:start func_0039E8E0 */
typedef struct { u8 b[8]; } V8_399948;
typedef struct { s32 f0, f4, f8, fC; V8_399948 f10; s32 f18; } E_399948;
typedef struct { u8 p0[0x30]; E_399948 e[4]; } R_399948;
extern R_399948 D_00142430_0039E8E0[];
extern s32 func_0039E788();
void func_0039E8E0(u8 *a, s32 i, s32 j) {
    s32 r = func_0039E788(a) == 0;
    a += 0x10;
    D_00142430_0039E8E0[i].e[j].f18 = r;
    D_00142430_0039E8E0[i].e[j].f0 = *(s32 *)a;
    a += 0xC;
    D_00142430_0039E8E0[i].e[j].f4 = *(s32 *)a;
    D_00142430_0039E8E0[i].e[j].f8 = a[0x32];
    a += 0x88;
    D_00142430_0039E8E0[i].e[j].fC = *(s32 *)a;
    *(V8_399948 *)((u8 *)D_00142430_0039E8E0 + 0x40 + j * 0x1C + i * 0xA0) = *(V8_399948 *)(a + 0xC);
}
/* localdecomp:end func_0039E8E0 */

/* func_0039E998: from the US C of func_00399A00 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_0039E998 */
typedef struct { u8 *f0; s32 f4, f8, fC; } E_399A00;
extern s32 D_001D6310;
extern s32 func_0039E788();
extern s32 func_0039E6A8();
extern s32 func_0011A01C();
extern void func_0038CC88();
s32 func_0039E998(u8 *p, u8 *end, s32 idx, E_399A00 *tab) {
    s32 fail, total, i, n;
    u8 *dst, *data;
    s32 *slot;
    s32 val;

    if (func_0039E788(p) == 0) return 1;
    p += 8;
    fail = 0;
    total = 8;
    for (i = 0; tab[i].f0 != 0; i++) tab[i].fC = 0;
    while (p < end && *(s32 *)p != -1) {
        for (i = 0; tab[i].f0 != 0; i++) {
            if (tab[i].f8 == *(s32 *)p) break;
        }
        if (tab[i].f0 != 0) {
            dst = tab[i].f0 + idx * tab[i].f4;
            if (((s32 *)p)[1] == tab[i].f4) {
                tab[i].fC = 1;
                n = tab[i].f4;
            } else if (((s32 *)p)[1] < tab[i].f4) {
                n = ((s32 *)p)[1];
                tab[i].fC = -1;
            } else {
                tab[i].fC = -2;
                n = tab[i].f4;
            }
            data = p + 8;
            if (func_0011A01C(dst, data, n)) D_001D6310++;
            if (tab[i].f8 != 0x1770) {
                func_0038CC88(dst, data, n);
                total += 8 + ((n + 3) & ~3);
            } else {
                total += 8 + ((((s32 *)p)[1] + 3) & ~3);
            }
        } else {
            fail++;
        }
        p += 8 + ((((s32 *)p)[1] + 3) & ~3);
    }
    total += 8;
    if (total != func_0039E6A8(tab)) fail++;
    p += 8;
    for (i = 0; tab[i].f0 != 0 && tab[i].f8 != *(s32 *)p; i++) {
        if (tab[i].fC <= 0) fail++;
    }
    slot = &D_142430_0039C410.c[D_142430_0039C410.f14C].f24;
    val = *slot;
    val += fail;
    *slot = val;
    return fail;
}
/* localdecomp:end func_0039E998 */
