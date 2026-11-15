#include "common.h"

/* declared by functions of L39_005DED10.c, which this file was cut from */
extern void func_L01_00516AA0(int, int, int);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L39_005DEDD8(void);

/* localdecomp:start func_L39_005DF060 */
/* log: callee alias func_L01_004D2110_005DF060 (stub is another copy in levels 40+). */
/* log: id local = 10 diff (s0 for temp); inline i + 0x6xxxx at each use = MATCH with --as ps2as (float constants inline, file needs @ps2as) */
extern u8 D_001D821C_sda;
extern void func_L01_004D2110_005DF060(s32);
extern void func_L01_00484A80(s32);
extern s32 func_003B5060(s32);
extern s32 func_003E5360(s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern void func_003E6FF0(s32, s32);
extern void func_L39_005DEDD8(void);
void func_L39_005DF060(s32 a0) {
    s32 i;
    s32 id;
    D_001D821C_sda = 1;
    func_L01_004D2110_005DF060(1);
    func_L01_00484A80(0x60000);
    func_003B5060(0x60001);
    func_003B5060(0x60002);
    func_003B5060(0x60003);
    func_003B5060(0x60004);

    func_003E5360(0x60005);
    func_L01_00516AA0(0x60005, 1, 0);
    func_L01_00516AA0(0x60005, 0x40, 1);
    func_L01_00516AA0(0x60005, 0x2000, 1);
    func_L01_00516FD8(0x60005, func_00381FF0(0x1332));
    func_L01_005170B8(0x60005, 0x8066CCFF);
    func_L01_00516470(0x60005, 0.28f, 0.25f);
    func_003E8630(0x60001, 0x60005);

    func_003E5360(0x60006);
    func_L01_00516AA0(0x60006, 1, 0);
    func_L01_00516AA0(0x60006, 0x40, 1);
    func_L01_00516AA0(0x60006, 0x2000, 1);
    func_L01_00516FD8(0x60006, func_00381FF0(0x1336));
    func_L01_005170B8(0x60006, 0x8066CCFF);
    func_L01_00516470(0x60006, 0.62f, 0.25f);
    func_003E8630(0x60001, 0x60006);

    func_003E5360(0x60007);
    func_L01_00516AA0(0x60007, 1, 0);
    func_L01_00516AA0(0x60007, 0x40, 1);
    func_L01_00516AA0(0x60007, 0x2000, 1);
    func_L01_00516FD8(0x60007, func_00381FF0(0x1337));
    func_L01_005170B8(0x60007, 0x8066CCFF);
    func_L01_00516470(0x60007, 0.83f, 0.25f);
    func_003E8630(0x60001, 0x60007);

    for (i = 0; i < 16; i++) {
        func_003E5360(i + 0x60008);
        func_L01_00516AA0(i + 0x60008, 1, 0);
        func_L01_00516AA0(i + 0x60008, 0x40, 1);
        func_L01_00516AA0(i + 0x60008, 0x2000, 1);
        func_L01_005170B8(i + 0x60008, 0x8066CCFF);
        func_003E8630(0x60002, i + 0x60008);

        func_003E5360(i + 0x60018);
        func_L01_00516AA0(i + 0x60018, 1, 0);
        func_L01_00516AA0(i + 0x60018, 0x40, 1);
        func_L01_00516AA0(i + 0x60018, 0x2000, 1);
        func_L01_005170B8(i + 0x60018, 0x8066CCFF);
        func_003E8630(0x60003, i + 0x60018);

        func_003E5360(i + 0x60028);
        func_L01_00516AA0(i + 0x60028, 1, 0);
        func_L01_00516AA0(i + 0x60028, 0x40, 1);
        func_L01_00516AA0(i + 0x60028, 0x2000, 1);
        func_L01_005170B8(i + 0x60028, 0x8066CCFF);
        func_003E8630(0x60004, i + 0x60028);
    }

    func_003E5360(0x60038);
    func_L01_00516AA0(0x60038, 1, 0);
    func_L01_00516AA0(0x60038, 0x40, 1);
    func_L01_00516FD8(0x60038, func_00381FF0(0x12A5));
    func_L01_005170B8(0x60038, 0x8066CCFF);
    func_L01_00516470(0x60038, 0.5f, 0.8438f);
    func_003E8630(0x60001, 0x60038);

    func_003E8630(0x60000, 0x60001);
    func_003E8630(0x60000, 0x60002);
    func_003E8630(0x60000, 0x60003);
    func_003E8630(0x60000, 0x60004);
    func_003E8348(0x18, 0x60000);
    func_003E6FF0(a0, 1);
    func_L39_005DEDD8();
    func_L01_004D2110_005DF060(0);
}
/* localdecomp:end func_L39_005DF060 */

/* localdecomp:start func_L39_005DF510 */
typedef struct B_005DF510 B_005DF510;
typedef struct { void *f0; s32 f4, f8, fC, f10; B_005DF510 *f14; } A_005DF510;
struct B_005DF510 { void *f0; s32 f4, f8, fC, f10, f14; B_005DF510 *f18; };
typedef struct {
    u8 pad0[0x18];
    s16 a[8][2];
    u8 pad1[0x10];
    u8 b[8];
    u8 c[8];
    u8 pad2[0x198 - 0x58];
    s16 d[8];
} T_005DF510;
extern u8 *D_L39_00241640;
__asm__(".extern D_L39_00241640, 16");
extern u8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern T_005DF510 D_L39_00352940;
extern s32 func_L39_0066C7D8(s32);
s32 func_L39_005DF510(A_005DF510 *a, B_005DF510 *b) {
    u8 *p = D_L39_00241640;
    s32 flag = 0;
    s32 n = 0;
    s32 i, j, k, cnt;
    if (p != 0) {
        flag = *(s32 *)(p + 0x180) == 1;
    }
    for (i = 0; i < 8; i++) {
        if (D_L39_0024CE20[i] != 0) {
            b[n].f0 = p + i * 16;
            b[n].f18 = 0;
            if (flag) {
                b[n].f8 = D_L39_00352940.c[i];
                b[n].f4 = D_L39_00352940.b[i];
            } else {
                b[n].f8 = D_L39_00352940.a[i][1];
                b[n].f4 = D_L39_00352940.a[i][0] - D_L39_00352940.d[i];
            }
            b[n].f10 = i;
            b[n].f14 = *(s32 *)(D_L39_0024CE20[i] + 0x2548);
            b[n].fC = b[n].f4 - b[n].f8;
            n++;
        }
        a[i].f14 = 0;
        a[i].f10 = -1;
    }
    cnt = n;
    n = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < cnt; j++) {
            if (b[j].f14 == i) {
                B_005DF510 *q;
                if (a[n].f14 == 0) {
                    a[n].f0 = (void *)func_L39_0066C7D8(i);
                    a[n].f14 = &b[j];
                    a[n].f8 = b[j].f8;
                    a[n].f4 = b[j].f4;
                    a[n].fC = b[j].fC;
                    a[n].f10 = i;
                } else {
                    q = a[n].f14;
                    a[n].f8 += b[j].f8;
                    a[n].f4 += b[j].f4;
                    if (q->fC < b[j].fC) {
                        b[j].f18 = q;
                        a[n].f14 = &b[j];
                    } else {
                        for (; q->f18 != 0 && q->f18->fC >= b[j].fC; q = q->f18) ;
                        b[j].f18 = q->f18;
                        q->f18 = &b[j];
                    }
                }
            }
        }
        if (a[n].f14 != 0) {
            n++;
        }
    }
    for (i = 1; i < n; i++) {
        A_005DF510 t = a[i];
        k = i;
        while (k > 0 && (a[k - 1].f4 < t.f4 || (a[k - 1].f4 == t.f4 && t.f8 < a[k - 1].f8))) {
            a[k] = a[k - 1];
            k--;
        }
        if (k != i) {
            a[k] = t;
        }
    }
    return n;
}
/* localdecomp:end func_L39_005DF510 */

INCLUDE_ASM("asm/levels", func_L39_005DF8F8);
