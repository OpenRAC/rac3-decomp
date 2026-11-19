#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0039A6E0(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0039AA38(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_0039A6E0 */
extern void func_0038CB78(void *, s32, s32);
extern u8 D_0016C690[];
void func_0039A6E0(void) {
    s32 *p;
    s32 i;
    func_0038CB78(D_0016C690, 0, 0x35840);
    *(s16 *)(D_0016C690 + 0x14) = -1;
    p = (s32 *)(D_0016C690 + 0x3C);
    for (i = 2; i >= 0; i--) {
        *p-- = -1;
    }
}
/* localdecomp:end func_0039A6E0 */

/* localdecomp:start func_0039A748 */
extern s32 D_001D600C;
typedef struct { u8 pad[0x34]; s32 arr[8]; } T_00395958;
extern T_00395958 D_0016C690_0039A748;
typedef struct { s32 f0; s32 f4; } S_00395958;

void func_0039A748(S_00395958 *arg0, s32 arg1) {
    if (arg1 != 0) {
        if (arg0->f4 >= 0) {
            D_0016C690_0039A748.arr[arg0->f4] = arg0->f0;
            if (arg0->f4 == D_001D600C) {
                D_001D600C = arg0->f4 ^ 1;
            }
        }
    }
    arg0->f0 = -1;
}
/* localdecomp:end func_0039A748 */

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_003959A8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_003959A8 el[0x30]; } S_003959A8;
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; } L_003959A8;
typedef struct { s32 f0; s32 f4; u8 *f8; } A_003959A8;
extern S_003959A8 D_160C40_0039A798;
extern void func_11F0A0();
extern s32 func_11F1E0();
extern s32 func_11F1C0();
extern s32 func_003A2630();
/* localdecomp:start func_0039A798 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4B38_0039A798;
__asm__(".extern D_001D4B38_0039A798, 16");
extern void func_0039A748();
void func_0039A798(A_003959A8 *a, s32 flag) {
    s32 t;
    s32 off;
    s32 base;
    s32 h;
    u8 *o;
    s32 *r;
    L_003959A8 l;
    if (flag == 0) {
        a->f0 = -1;
        return;
    }
    t = D_160C40_0039A798.el[a->f0].f10;
    if (t != 0) {
        off = a->f4 * 0xC800;
        o = a->f8;
        base = D_001D4B38_0039A798;
        base = base + off;
        l.w0 = (s32)o;
        l.w4 = base;
        l.w8 = t << 11;
        l.wC = 0;
        r = (s32 *)(o + 0x18);
        *(s32 *)(o + 0x14) = 0xC000;
        r[10] = 0xC000;
        r[11] = 0xC000;
        func_11F0A0(0);
        h = func_11F1E0(&l, 1);
        while (func_11F1C0(h) >= 0) {
        }
    }
    func_003A2630(a->f8, D_160C40_0039A798.el[a->f0].f4 + D_160C40_0039A798.g458C, D_160C40_0039A798.el[a->f0].f8, func_0039A748, a);
}
/* localdecomp:end func_0039A798 */

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_00395AC8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_00395AC8 el[0x30]; } S_00395AC8;
extern S_00395AC8 D_160C40_0039A8B8;
typedef struct { u8 pad[0x34]; s32 f34[3]; } T_00395AC8;
extern T_00395AC8 D_16C690_0039A8B8;
extern s32 D_001D6000_0039A8B8;
extern s32 D_001D6004_0039A8B8;
__asm__(".extern D_001D6004_0039A8B8, 16");
extern u8 D_001D6008_0039A8B8;
extern s32 func_003A2630();
extern void func_0039A798();
/* localdecomp:start func_0039A8B8 */
extern void func_0039A748();
s32 func_0039A8B8(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 t;
    if (D_160C40_0039A8B8.el[a0].f8 != 0) {
        t = D_001D6000_0039A8B8;
        if (t == -1) {
            D_001D6000_0039A8B8 = a0;
            D_001D6004_0039A8B8 = a1;
            (&D_001D6004_0039A8B8)[1] = a2;
            if (a1 >= 0) {
                D_16C690_0039A8B8.f34[a1] = t;
            }
            if (D_160C40_0039A8B8.el[a0].f10 != 0 && a3 == 0) {
                return func_003A2630(a2, D_160C40_0039A8B8.el[a0].fC + D_160C40_0039A8B8.g458C, D_160C40_0039A8B8.el[a0].f10, func_0039A798, &D_001D6000_0039A8B8);
            }
            return func_003A2630(a2, D_160C40_0039A8B8.el[a0].f4 + D_160C40_0039A8B8.g458C, D_160C40_0039A8B8.el[a0].f8, func_0039A748, &D_001D6000_0039A8B8);
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_0039A8B8 */

/* localdecomp:start func_0039A9B0 */
typedef struct { s32 k; u8 pad[0x10]; } E_395BC0;
typedef struct { u8 pad[0x4590]; E_395BC0 e[0x30]; } S_395BC0;
typedef struct { u8 d[0xC800]; } B_395BC0;
typedef struct { u8 pad[0x34]; s32 f34[3]; B_395BC0 blk[1]; } S_395BC0b;
extern S_395BC0 D_160C40_0039A9B0;
extern S_395BC0b D_16C690_0039A9B0;
void func_0039A9B0(s32 a, s32 b) {
    s32 i;
    for (i = 0; i < 0x30; i++) {
        if (D_160C40_0039A9B0.e[i].k == a) break;
    }
    if (i == 0x30) return;
    if (D_16C690_0039A9B0.f34[b] == i) return;
    func_0039A8B8(i, b, &D_16C690_0039A9B0.blk[b], 0);
}
/* localdecomp:end func_0039A9B0 */

/* localdecomp:start func_0039AA38 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4C40_0039AA38;
__asm__(".extern D_001D4C40_0039AA38, 16");
typedef struct { u8 pad[0x10]; s32 f10; u8 pad2[0xDC]; } E_395C48;
typedef struct { s32 id; s32 pad[4]; } F_395C48;
typedef struct { u8 pad[0x4590]; F_395C48 e[0x30]; } S_395C48;
typedef struct { u8 pad[0x34]; s32 v[3]; } T_395C48;
typedef struct { u8 pad[0x25F8]; s32 f25F8; u8 pad2[0x18]; s32 f2614; } A_395C48;
extern A_395C48 D_1A4BE0;
extern u8 D_001425C0[];
extern s32 D_00142674[];
extern s16 D_001CCFD4[];
extern E_395C48 D_001DAA40[];
extern S_395C48 D_160C40_0039AA38;
extern T_395C48 D_16C690_0039AA38;
extern s32 func_0039AC08(s32);
static __inline__ s32 get_395C48(s32 n) {
    E_395C48 *e = &D_001DAA40[D_001425C0[n]];
    return e->f10;
}
void func_0039AA38(s32 id) {
    s32 a, b, x, y, i, t, k;
    if (func_0039AC08(id) != 0) return;
    if (D_001CCFD4[0] != 0) return;
    i = 0;
    a = get_395C48(D_1A4BE0.f2614);
    b = get_395C48(D_001D4C40_0039AA38); /* through $gp (a plain sized extern) it schedules differently */
    if (b == a) {
        b = get_395C48(D_00142674[0]);
    }
    y = -1;
    if (a == id) a = -1;
    if (b == id) b = -1;
    x = -1;
    for (; i < 3; i++) {
        s32 e = D_160C40_0039AA38.e[D_16C690_0039AA38.v[i]].id;
        if (a == e) x = i;
        if (b == e) y = i;
    }
    for (i = 0; i == x || i == y; i++);
    t = D_1A4BE0.f25F8;
    if (t != 0) {
        k = D_16C690_0039AA38.v[i];
        if (k != -1) {
            if (get_395C48(t) == D_160C40_0039AA38.e[k].id) {
                D_1A4BE0.f25F8 = 0;
            }
        }
    }
    func_0039A9B0(id, i);
}
/* localdecomp:end func_0039AA38 */

LINKER_REMNANT("asm/remnants", func_0039AC00);

/* localdecomp:start func_0039AC08 */
typedef struct { s32 id; s32 pad[4]; } E_395E18;
typedef struct { u8 pad[0x4590]; E_395E18 e[0x30]; } S_395E18;
typedef struct { u8 pad[0x34]; s32 v[3]; } T_395E18;
extern S_395E18 D_160C40[];
extern T_395E18 D_16C690[];
s32 func_0039AC08(s32 id) {
    s32 i, j;
    for (i = 0; i < 0x30; i++) if (D_160C40[0].e[i].id == id) break;
    if (i == 0x30) return 1;
    for (j = 0; j < 3; j++) if (D_16C690[0].v[j] == i) break;
    return j != 3;
}
/* localdecomp:end func_0039AC08 */

LINKER_REMNANT("asm/remnants", func_0039AC98);
