#include "common.h"

/* localdecomp:start func_L03_0032DB58 */
typedef struct S_0032DB58 {
    char pad0[0x1A];
    short h;
    unsigned char b1C;
    unsigned char b1D;
} S_0032DB58;
void *func_L03_0032F6A8();
extern int D_001DCF28_sda[2];
__asm__(".extern D_001DCF28_sda, 8");

int func_L03_0032DB58(void) {
    S_0032DB58 *s = func_L03_0032F6A8();
    int v = D_001DCF28_sda[s->b1D];
    if (v == -1) return 1;
    if ((unsigned)(s->b1C - 2) < 2) return 1;
    if (s->h != -1) return s->h < v;
    return 0;
}
/* localdecomp:end func_L03_0032DB58 */

/* localdecomp:start func_L03_0032DBC0 */
s32 func_L03_0032DBC0(void) {
    return 0x10001;
}
/* localdecomp:end func_L03_0032DBC0 */

/* localdecomp:start func_L03_0032DBD0 */
void *func_L03_0032F6A8();

s32 func_L03_0032DBD0(s32 arg0, s32 arg1) {
    return (((*(u8 *)((u8 *)(func_L03_0032F6A8()) + 0x1C)) ^ 3) == 0) ? arg1 : 0xA;
}
/* localdecomp:end func_L03_0032DBD0 */

INCLUDE_ASM("asm/levels", func_L03_0032DC08);

INCLUDE_ASM("asm/levels", func_L03_0032DDC8);

/* localdecomp:start func_L03_0032DF10 */
void *func_L03_0032F6A8();
void func_L01_004443E8(void *, s32, s32);
void func_L03_0032F6F8(s32, void *);

void func_L03_0032DF10(void *arg0) {
    void *p;

    p = func_L03_0032F6A8(arg0);
    if (p != 0) {
        func_L01_004443E8(arg0, 0, 3);
        func_L03_0032F6F8(*(s32 *)((u8 *)p + 0x8), arg0);
    }
}
/* localdecomp:end func_L03_0032DF10 */

INCLUDE_ASM("asm/levels", func_L03_0032DF60);

INCLUDE_ASM("asm/levels", func_L03_0032E0D8);

INCLUDE_ASM("asm/levels", func_L03_0032E640);

/* localdecomp:start func_L03_0032E6F0 */
extern u8 D_L03_002AE4D0[];
extern s32 D_00142660[];
extern s32 func_L03_0032E7A0(void *a0, s32 a1);
extern s32 func_L03_0032F948(s32 a0);
extern void func_L03_0032FA18(s32 a0);
extern void func_0039EC28(s32 a0, s32 a1);

s32 func_L03_0032E6F0(void *arg0, s32 arg1) {
    s32 r;
    s32 r2;
    u8 *p;

    p = *(u8 **)((u8 *)arg0 + 0x68);
    r = func_L03_0032E7A0(arg0, D_L03_002AE4D0[arg1 * 0x28 + 0x10]);
    if (r != 0) {
        *(s32 *)(p + 0x108) = -1;
    } else {
        r2 = func_L03_0032F948(arg1);
        if (r2 != 0) {
            *(s32 *)(p + 0x108) = r2;
        } else {
            *(s32 *)(p + 0x108) = -2;
        }
        D_00142660[0] += r2;
    }
    func_L03_0032FA18(arg1);
    func_0039EC28(1, -1);
    return r;
}
/* localdecomp:end func_L03_0032E6F0 */

INCLUDE_ASM("asm/levels", func_L03_0032E7A0);

/* localdecomp:start func_L03_0032E7E8 */
extern int func_0011A264(void *, int, int);
extern int func_00382498(int, int);
extern int func_L03_0032F790(void *, int, int);
extern void func_L03_00399C68(void *, int, int, int);
void func_L03_0032E7E8(void *a, int n, int *p19, int *p17, unsigned char *p18) {
    int c[3];
    int i;
    func_0011A264(c, 0, 12);
    if (*p19 > 0) {
        n++;
        *p19 = *p19 - 1;
    }
    if (n > 0) {
        do {
            if (*p17 > 0) {
                i = func_L03_0032F790(p18, func_00382498(0, *p17 - 1), 3);
                p18[i]--;
                c[i]++;
                *p17 = *p17 - 1;
            }
        } while (--n != 0);
    }
    func_L03_00399C68(a, c[0], c[1], c[2]);
}
/* localdecomp:end func_L03_0032E7E8 */

/* localdecomp:start func_L03_0032E8D8 */
void func_L03_0032E8D8(void *arg0, s32 arg1) {
    u8 temp_a1;
    u8 temp_v0;
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    temp_a1 = arg1 & 0xFF;
    temp_v0 = *(u8 *)((u8 *)temp_v1 + 0xF6);
    *(u8 *)((u8 *)temp_v1 + 0xF6) = temp_a1;
    *(s8 *)((u8 *)temp_v1 + 0xF7) = (s8) (temp_a1 & ~temp_v0 & 0x1F);
}
/* localdecomp:end func_L03_0032E8D8 */

INCLUDE_ASM("asm/levels", func_L03_0032E900);

/* localdecomp:start func_L03_0032EB30 */
typedef struct S_0032EB30 {
    char pad0[0xC0];
    int idx;
} S_0032EB30;
extern int D_L03_0021C620[];
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern int D_001DF9D8_sda;
__asm__(".extern D_001DF9D8_sda, 4");
void func_L02_003A02D8(void *a, int b);

void func_L03_0032EB30(void *a) {
    S_0032EB30 *p = *(S_0032EB30 **)((char *)a + 0x68);
    short *cur = (short *)D_L03_0021C620[p->idx];
    while ((p->idx & 0xFF) != 0xFF && D_001DF9D8_sda >= p->idx && cur != 0 &&
           (cur[-1] >= 0 || cur == (short *)D_L03_0021C620[p->idx])) {
        char *buf = D_L03_001DF99C + ((*(unsigned short *)cur & 0x7FFF) << 8);
        if (buf == 0) return;
        func_L02_003A02D8(buf, 0);
        cur += 1;
    }
}
/* localdecomp:end func_L03_0032EB30 */

INCLUDE_ASM("asm/levels", func_L03_0032EBF0);

INCLUDE_ASM("asm/levels", func_L03_0032EC38);
