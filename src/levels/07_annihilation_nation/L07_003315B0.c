#include "common.h"

typedef struct S_L07_00331EE8 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} S_L07_00331EE8;

/* localdecomp:start func_L07_003315B0 */
extern int *func_L07_00333918(void *);
extern void func_L01_004443E8(void *, int, int);
extern s32 func_L07_00333D40(void *, void *);
void func_L07_003315B0(void *a) {
    int *r = func_L07_00333918(a);
    func_L01_004443E8(a, 0, 3);
    func_L07_00333D40((void *)r[2], a);
}
/* localdecomp:end func_L07_003315B0 */

/* localdecomp:start func_L07_00331600 */
#include "vu0.h"
typedef struct { u8 pad[0x1C]; s32 groups[7]; s32 single[3]; } Vars_00331600;
extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458;
extern u8 *D_L07_001DF41C;
s32 func_L07_00331600(u8 *self) {
    extern void func_L07_003315B0(void *a);
    extern f32 func_L01_0040E570(void *, void *);
    Vars_00331600 *vars = *(Vars_00331600 **)(self + 0x68);
    s32 active = 0;
    s32 i;

    for (i = 0; i < 7;) {
        s32 next = i + 1;
        if ((u32)(i - 3) >= 2) {
            u16 *p = D_L07_0021C020[vars->groups[i]];
            while ((vars->groups[i] & 0xFF) != 0xFF && vars->groups[i] <= D_L07_001DF458 && p) {
                u8 *moby;
                if ((s16)p[-1] < 0 && p != D_L07_0021C020[vars->groups[i]]) break;
                moby = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
                if (moby == 0) break;
                if (moby[0x20] != 1) {
                    active = 1;
                    if (fabs_asm(*(f32 *)(self + 0x18) - *(f32 *)(moby + 0x18)) > 40.0f ||
                        func_L01_0040E570(self + 0x10, moby + 0x10) > 3192.25f) {
                        func_L07_003315B0(moby);
                    }
                }
                p++;
            }
        }
        i = next;
    }
    { s32 one = 1;
    s32 *single = vars->single;
    s32 count;
    count = 2;
    do {
        u8 *moby = D_L07_001DF41C + (*single << 8);
        if (moby[0x20] != one) {
            active = 1;
            if (fabs_asm(*(f32 *)(self + 0x18) - *(f32 *)(moby + 0x18)) > 40.0f ||
                func_L01_0040E570(self + 0x10, moby + 0x10) > 3192.25f) {
                func_L07_003315B0(moby);
            }
        }
        single++;
    } while (--count >= 0);
    }
    return active;
}
/* localdecomp:end func_L07_00331600 */

/* localdecomp:start func_L07_00331890 */
void func_L03_0032ED88(s32);
void func_L07_003318D8(s32);
void func_L07_00331908();
void func_L07_00331B10(s32);
void func_L07_00332298(s32);

void func_L07_00331890(s32 arg0) {
    func_L07_00331908();
    func_L07_00331B10(arg0);
    func_L03_0032ED88(arg0);
    func_L07_00332298(arg0);
    func_L07_003318D8(arg0);
}
/* localdecomp:end func_L07_00331890 */

/* localdecomp:start func_L07_003318D8 */
extern s32 D_L07_001DF600;

void func_L07_003318D8(s32 a) {
    u8 *q = *(u8 **)((u8 *)a + 0x68);
    s32 *p = &D_L07_001DF600;
    s32 i;

    for (i = 1; i >= 0; i--) {
        if (*p) {
            *p = 0;
        }
        p++;
    }
    q[0xA9] = 0;
}
/* localdecomp:end func_L07_003318D8 */

/* localdecomp:start func_L07_00331908 */
extern void func_L07_003319C8(void *, s32);
extern int *func_L07_00333918(void *);
extern s32 func_L07_00333D40(void *, void *);
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");

void func_L07_00331908(u8 *self) {
    s32 i;
    s32 k;
    s32 *p;
    u8 *o;
    u8 *s;

    s = *(u8 **)(self + 0x68);
    for (i = 0; i < 7; i++) {
        if ((u32)(i - 3) >= 2) {
            func_L07_003319C8(self, i);
        }
    }
    p = (s32 *)(s + 0x38);
    for (k = 2; k >= 0; k--) {
        o = D_L07_001DF41C + (*p++ << 8);
        if (o[0x20] >= 2) {
            func_L07_00333D40((void *)func_L07_00333918(o)[2], o);
        }
    }
}
/* localdecomp:end func_L07_00331908 */

/* localdecomp:start func_L07_003319C8 */
typedef struct {
    u8 pad0[0x1C];
    s32 ids[7];
} Grp_003319C8;

/* localdecomp:start func_L07_003319C8 */
extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458;
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern int *func_L07_00333918(void *);
extern s32 func_L07_00333D40(void *, void *);

void func_L07_003319C8(void *self, s32 i) {
    Grp_003319C8 *o = *(Grp_003319C8 **)((u8 *)self + 0x68);
    u16 *p;
    u8 *e;

    p = D_L07_0021C020[o->ids[i]];
    while ((o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L07_001DF458 && p != 0) {
        if ((s16)p[-1] < 0 && p != D_L07_0021C020[o->ids[i]]) {
            break;
        }
        e = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            break;
        }
        if (e[0x20] >= 2) {
            func_L07_00333D40((void *)func_L07_00333918(e)[2], e);
        }
        p++;
    }
}
/* localdecomp:end func_L07_003319C8 */
/* localdecomp:end func_L07_003319C8 */

/* localdecomp:start func_L07_00331B10 */
extern s32 func_L07_00333B68(void *);
extern s32 func_L07_00333D40(void *, void *);
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");

void func_L07_00331B10(s32 arg0) {
    s32 *s = *(s32 **)(arg0 + 0x68);
    s32 *p = s;
    u8 *o;
    s32 k;

    for (k = 5; k >= 0; k--) {
        o = D_L07_001DF41C;
        o += *p++ << 8;
        func_L07_00333D40(*(void **)(func_L07_00333B68(o) + 4), o);
    }
    o = D_L07_001DF41C;
    o += s[6] << 8;
    func_L07_00333D40(*(void **)(func_L07_00333B68(o) + 4), o);
}
/* localdecomp:end func_L07_00331B10 */

/* localdecomp:start func_L07_00331BB0 */
extern S_L07_00331EE8 D_L07_002B0D40[];
extern u8 *D_L07_001DF41C;
extern void *func_0011A264(void *, s32, s32);
extern s32 func_L07_003343E8(s32);
extern void func_L07_00334318(void *, s32 *, s32 *);
extern s32 func_L07_00333B68(void *);
extern s32 func_00382468(s32);
extern s32 func_L07_00333D70(u8 *, s32, s32, s32);
extern s32 func_L07_00333D40(void *, void *);

typedef struct { s32 f0; s32 f4; void *f8; u8 got[7]; } V_00331BB0;

void func_L07_00331BB0(void *self) {
    s32 totals[2];
    u8 counts[7];
    s32 quotient[2];
    s32 remainder[2];
    s32 index, direction;
    u8 *state = *(u8 **)((u8 *)self + 0x68);
    s32 pass;
    u8 *row;
    s32 empty = 1;
    s32 i, j, k, n, choice, amount;
    u8 *m;
    V_00331BB0 *vars;
    row = (u8 *)D_L07_002B0D40[state[0x9E]].f4 + state[0x9F] * 12;
    func_0011A264(totals, 0, 8);
    row += 2;
    for (i = 0; i < 7; i++) {
        counts[i] = row[i];
        totals[func_L07_003343E8(i)] += row[i];
        if (counts[i]) empty = 0;
    }
    if (empty) return;
    amount = ((totals[0] > totals[1] ? totals[0] : totals[1]) + 3) / 4;
    if (amount <= 0) return;
    for (k = 0; k < 2; k++) {
        quotient[k] = totals[k] / amount;
        remainder[k] = totals[k] % amount;
    }
    func_L07_00334318(self, &index, &direction);
    for (pass = 1; (totals[0] > 0 || totals[1] > 0) && pass < 6; pass++) {
        m = D_L07_001DF41C + (*(s32 *)(state + (index << 2)) << 8);
        if (m[0x20] == 1) {
            vars = (V_00331BB0 *)func_L07_00333B68(m);
            for (i = 0; i < 2; i++) {
                n = quotient[i];
                if (remainder[i] > 0) { n++; remainder[i]--; }
                for (j = 0; j < n; j++) {
                    s32 r = func_00382468(totals[i]);
                    if (i == 1) {
                        choice = func_L07_00333D70(counts, r, 1, 6);
                    } else {
                        choice = func_L07_00333D70(counts, r, 6, 0);
                    }
                    if (choice != -1) {
                        vars->got[choice]++;
                        counts[choice]--;
                        totals[i]--;
                    }
                }
            }
            func_L07_00333D40(vars->f8, m);
        }
        index += pass * direction;
        if (index < 0) index += 6;
        if (index >= 6) index -= 6;
        direction = -direction;
    }
}
/* localdecomp:end func_L07_00331BB0 */

/* localdecomp:start func_L07_00331EE8 */
extern S_L07_00331EE8 D_L07_002B0D40[];
extern s32 D_001DF41C;
extern s32 func_L07_00333B68(void *);
extern s32 func_L07_00333D40(void *, void *);

s32 func_L07_00331EE8(void *arg0) {
    s32 i;
    u8 *q;
    s32 idx;
    void *obj;
    void *s;
    s32 r;

    obj = *(void **)((u8 *)arg0 + 0x68);
    idx = *(u8 *)((u8 *)obj + 0x9E);
    q = (u8 *)(D_L07_002B0D40[idx].f4) + (*(u8 *)((u8 *)obj + 0x9F) * 12) + 9;
    for (i = 0; i < 3; i++) {
        if (q[i] != 0) {
            s = (u8 *)D_001DF41C + (*(s32 *)((u8 *)obj + 0x18) << 8);
            r = func_L07_00333B68(s);
            *((u8 *)r + i + 0x13) = 1;
            return func_L07_00333D40((void *)*(s32 *)((u8 *)r + 8), s);
        }
    }
    return (s32)(q + i);
}
/* localdecomp:end func_L07_00331EE8 */

/* localdecomp:start func_L07_00331FA0 */
extern s32 D_L07_001DF41C_00331FA0;
__asm__(".extern D_L07_001DF41C_00331FA0, 16");
extern s32 func_L07_00331FF0(u8 *);

s32 func_L07_00331FA0(void *arg0) {
    u8 *q = *(u8 **)((u8 *)arg0 + 0x68);

    if (func_L07_00331FF0(arg0) != 0) {
        return 1;
    }
    return *(u8 *)((u8 *)D_L07_001DF41C_00331FA0 + (*(s32 *)(q + 0x18) << 8) + 0x20) != 1;
}
/* localdecomp:end func_L07_00331FA0 */

/* localdecomp:start func_L07_00331FF0 */
extern u8 *D_L07_001DF41C_00331FF0;
__asm__(".extern D_L07_001DF41C_00331FF0, 16");
s32 func_L07_00331FF0(u8 *arg0) {
    s32 *q = *(s32 **)(arg0 + 0x68);
    s32 i;
    for (i = 0; i < 6; i++) {
        if ((D_L07_001DF41C_00331FF0 + (q[i] << 8))[0x20] != 1) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L07_00331FF0 */
