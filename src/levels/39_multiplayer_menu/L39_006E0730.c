#include "common.h"

/* declared by functions of L39_006DC228.c, which this file was cut from */
extern u8 D_001A5CD0[];
extern void *D_001E2050_sda;
extern s32 func_L39_006D6E50(s32, s32, s32, s32 *);
extern void func_L39_006D6E30(s32, s32, s32 *);
typedef struct {
    s32 ids[8];
    f32 a[8];
    f32 b[8];
    char pad[0x8C - 0x60];
    s32 count;
    char pad2[0xA4 - 0x90];
} S_006E0150_Ent;
typedef struct {
    char pad[0x100];
    s32 active[8];
    char pad2[0x2E8 - 0x120];
    S_006E0150_Ent ent[8];
} S_006E0150;
extern S_006E0150 D_001FD7E8;

/* localdecomp:start func_L39_006E0730 */
typedef struct { s16 v; s16 pad; } E_006E0730;
extern E_006E0730 D_001FD928[];

void func_L39_006E0730(s32 *min, s32 *max) {
    s32 i, j, sum;

    *max = 0;
    *min = 10000;
    for (i = 0; i < 8; i++) {
        if (D_001FD7E8.ent[i].count > 0) {
            sum = 0;
            for (j = 0; j < D_001FD7E8.ent[i].count; j++) {
                sum += (D_001FD928 + D_001FD7E8.ent[i].ids[j])->v;
            }
            if (sum < *min) {
                *min = sum;
            }
            if (sum > *max) {
                *max = sum;
            }
        }
    }
}
/* localdecomp:end func_L39_006E0730 */

/* localdecomp:start func_L39_006E07E8 */
void func_L39_006E07E8(s32 *min, s32 *max) {
    s32 i, j, v;

    *max = 0;
    *min = 10000;
    for (i = 0; i < 8; i++) {
        if (D_001FD7E8.ent[i].count > 0) {
            for (j = 0; j < D_001FD7E8.ent[i].count; j++) {
                v = (D_001FD928 + D_001FD7E8.ent[i].ids[j])->v;
                if (v < *min) {
                    *min = v;
                }
                if (v > *max) {
                    *max = v;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_006E07E8 */

INCLUDE_ASM("asm/levels", func_L39_006E08A0);

/* localdecomp:start func_L39_006E0B18 */
extern void func_L39_006E0298();
 
void func_L39_006E0B18(void) {
    func_L39_006E0298();
}
/* localdecomp:end func_L39_006E0B18 */

/* localdecomp:start func_L39_006E0B38 */
typedef struct {
    char _p0[0xC];
    s32 fC;
    char _p10[0x88 - 0x10];
    f32 f88[3];
    f32 f94;
    f32 f98[3];
    f32 fA4;
    char _pA8[0x170 - 0xA8];
    s32 f170;
} S_006E0B38;
typedef struct {
    char _p0[0x30];
    s32 *f30;
    char _p34[0x44 - 0x34];
    s32 f44;
} G_006E0B38;

s32 func_00197550(s32);
void func_00196700(f32 *, s32);
f32 func_L39_006E0FF8(s32, f32 *);
void func_L39_006DF760(s32 *, s32, f32);
void func_L39_006E1108(void);
void func_L39_006DEDF8(void);
extern s32 D_001FDFF4 __attribute__((section(".data")));
extern f32 D_001A6A58 __attribute__((section(".data")));
typedef void (*F_006E0B38)(f32 *, f32 *, s32, s32, s32, s32, s32);
extern F_006E0B38 D_001DE9C8_sda[2];

void func_L39_006E0B38(void) {
    s32 buf[100];
    s32 total;
    s32 num;
    s32 key;
    s32 out;
    f32 a;
    f32 b;
    S_006E0B38 *p;
    G_006E0B38 *g;
    s32 n;
    s32 idx;
    s32 e;

    p = (S_006E0B38 *)D_001A5CD0;
    n = p->fC;
    total = 0;
    num = 0;
    key = -1;
    out = -1;

    idx = func_00197550(D_001FDFF4);
    if (p->f170 != 0) {
        return;
    }
    func_L39_006E0150(&total, &num, &key, &out);
    if (func_L39_006E0220(total, num, n) == 0) {
        return;
    }
    g = D_001E2050_sda;
    e = g->f44;
    if (func_L39_006D6E50(e, *g->f30, 0, buf) == 0) {
        return;
    }
    func_L39_006DEDF8();
    D_001DE9C8_sda[idx](&a, &b, total, num, key, out, idx);
    p->f88[idx] = a;
    p->f98[idx] = b;
    p->f94 = func_L39_006E0FF8(3, p->f88);
    p->fA4 = func_L39_006E0FF8(3, p->f98);
    func_L39_006DF760(buf, key, a);
    func_00196700(p->f88, 1);
    ((s32 (*)(s32, s32, s32 *))func_L39_006D6E30)(e, 0, buf);
    if (D_001A6A58 > 0.0f) {
        func_L39_006E1108();
    }
}
/* localdecomp:end func_L39_006E0B38 */

INCLUDE_ASM("asm/levels", func_L39_006E0CC8);

/* localdecomp:start func_L39_006E0CF0 */
f32 func_L39_006E0CC8();

f32 func_L39_006E0CF0(void) {
    f32 temp_f0;

    temp_f0 = func_L39_006E0CC8();
    return temp_f0 * temp_f0;
}
/* localdecomp:end func_L39_006E0CF0 */
