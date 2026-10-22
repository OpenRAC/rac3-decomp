#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef int s128_3AC638 __attribute__((mode(TI)));
typedef struct { u8 pad[3184]; int a[4]; int b[4]; int c[4]; int d[4]; int e[4]; int f[4]; int g[4]; } S_3AC638;
typedef struct {
    int f0;
    f32 f4;
    f32 f8;
    int fC;
} V_3AD948;

INCLUDE_ASM("asm/levels", func_L01_003AC8C0);

INCLUDE_ASM("asm/levels", func_L01_003ACAD0);

INCLUDE_ASM("asm/levels", func_L01_003ACCD8);

INCLUDE_ASM("asm/levels", func_L01_003ACD38);

/* localdecomp:start func_L01_003ACFA8 */
void func_L01_003ACFA8(s32 arg0, s32 arg1, void *arg2, void *arg3) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;
    f32 var_f0_2;

    (*(s32 *)arg3) = 0;
    temp_f1 = *(f32 *)((u8 *)arg3 + 4);
    var_f0 = *(f32 *)((u8 *)arg2 + 0xC);
    if ((var_f0 < temp_f1) || (var_f0 = (*(f32 *)((u8 *)arg2 + 8)), (temp_f1 < var_f0))) {
        *(f32 *)((u8 *)arg3 + 4) = var_f0;
    }
    temp_f1_2 = *(f32 *)((u8 *)arg3 + 8);
    var_f0_2 = *(f32 *)((u8 *)arg2 + 0x14);
    if ((var_f0_2 < temp_f1_2) || (var_f0_2 = (*(f32 *)((u8 *)arg2 + 0x10)), (temp_f1_2 < var_f0_2))) {
        *(f32 *)((u8 *)arg3 + 8) = var_f0_2;
    }
}
/* localdecomp:end func_L01_003ACFA8 */

INCLUDE_ASM("asm/levels", func_L01_003AD010);

INCLUDE_ASM("asm/levels", func_L01_003AD418);

/* localdecomp:start func_L01_003AD800 */
extern void func_003A52A0(s32, s32, s32);

void func_L01_003AD800(s32 a0, u8 *s) {
    s32 st = *(s32 *)(s + 3136);
    s32 idx;
    if (st == 0 || st == 3) {
        *(s32 *)(s + 3136) = 1;
        idx = *(s32 *)(*(u8 **)(s + 104) + 68);
        if (idx >= 0) {
            func_003A52A0(idx, 0, *(s32 *)(s + 100));
        }
    }
}
/* localdecomp:end func_L01_003AD800 */

/* localdecomp:start func_L01_003AD850 */
extern void func_003A52A0(s32, s32, s32);
void func_L01_003AD850(s32 a0, u8 *a1) {
    s32 t;
    if ((u32)(*(s32 *)(a1 + 3136) - 1) < 2) {
        *(s32 *)(a1 + 3136) = 3;
        t = *(s32 *)(*(u8 **)(a1 + 104) + 68);
        if (t >= 0) {
            func_003A52A0(t, 0, *(s32 *)(a1 + 100));
        }
    }
}
/* localdecomp:end func_L01_003AD850 */

INCLUDE_ASM("asm/levels", func_L01_003AD898);

INCLUDE_ASM("asm/levels", func_L01_003ADA68);

INCLUDE_ASM("asm/levels", func_L01_003ADBE0);

/* localdecomp:start func_L01_003ADCE8 */
extern char *func_L01_0043B568(int, int, int);
void func_L01_003ADCE8(int a, int b, char *m)
{
    char *v = func_L01_0043B568(*(short *)(m + 170), 2, 12);
    (*(void (**)(char *))(v + 8))(m);
}
/* localdecomp:end func_L01_003ADCE8 */

/* localdecomp:start func_L01_003ADD28 */
extern u8 *func_L01_00449050(u8 *a0);
extern void func_0038D308(u8 *a0, u8 *a1);
void func_L01_003ADD28(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    u8 *v = func_L01_00449050(a0);
    s32 *src = (s32 *)(*(u8 **)(*(u8 **)(v + 8) + 104) + 160);
    s32 *dst = (s32 *)(s1 + 3216);
    s32 i;
    for (i = 0; i < 4; i++) {
        *dst++ = *src++;
    }
    *(u128_t *)(a0 + 16) = *(u128_t *)(s1 + 3376);
    *(u128_t *)(a0 + 240) = *(u128_t *)(s1 + 3392);
    func_0038D308(a0 + 192, a0 + 240);
}
/* localdecomp:end func_L01_003ADD28 */

/* localdecomp:start func_L01_003ADDA0 */
extern void func_L01_003ADDA0(void *p);
extern void func_L01_003ADDA0(void *);

extern void func_L01_003ACAD0_003ADDA0(void *, s32);
 
void func_L01_003ADDA0(void *p) {
    func_L01_003ACAD0_003ADDA0(p, 0);
}
/* localdecomp:end func_L01_003ADDA0 */

/* localdecomp:start func_L01_003ADDC0 */

#define W(p, o) (*(int *)((p) + (o)))
#define F(p, o) (*(f32 *)((p) + (o)))
#define Q(p, o) (*(s128_3AC638 *)((p) + (o)))


void func_L01_003ADDC0(u8 *a, u8 *b) {
    u8 *src = *(u8 **)(b + 0x68);
    u8 *dst = *(u8 **)(a + 0x68);
    int i;

    Q(dst, 3376) = Q(src, 3376);
    Q(dst, 3392) = Q(src, 3392);
    W(dst, 96) = W(src, 96);
    W(dst, 108) = W(src, 108);
    W(dst, 3104) = W(src, 3104);
    W(dst, 3108) = W(src, 3108);
    W(dst, 3112) = W(src, 3112);
    W(dst, 3116) = W(src, 3116);
    W(dst, 3120) = W(src, 3120);
    F(dst, 3124) = F(src, 3124);
    W(dst, 3152) = W(src, 3152);
    W(dst, 3156) = W(src, 3156);
    W(dst, 3160) = W(src, 3160);
    W(dst, 3164) = W(src, 3164);
    F(dst, 3172) = F(src, 3172);
    F(dst, 3176) = F(src, 3176);
    for (i = 0; i < 4; i++) {
        ((S_3AC638 *)dst)->a[i] = ((S_3AC638 *)src)->a[i];
        ((S_3AC638 *)dst)->b[i] = ((S_3AC638 *)src)->b[i];
        ((S_3AC638 *)dst)->c[i] = -1;
        ((S_3AC638 *)dst)->d[i] = ((S_3AC638 *)src)->d[i];
        ((S_3AC638 *)dst)->e[i] = ((S_3AC638 *)src)->e[i];
        ((S_3AC638 *)dst)->f[i] = ((S_3AC638 *)src)->f[i];
        ((S_3AC638 *)dst)->g[i] = ((S_3AC638 *)src)->g[i];
    }
    W(dst, 3296) = W(src, 3296);
    W(dst, 3300) = W(src, 3300);
    W(dst, 3304) = W(src, 3304);
    F(dst, 3312) = F(src, 3312);
    W(dst, 3148) = W(src, 3148);
}
/* localdecomp:end func_L01_003ADDC0 */

/* localdecomp:start func_L01_003ADEC8 */
extern void func_L01_003ADFC0(void);
extern void func_L01_003AE0E8(u8 *);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_004AAC98(s32, s32, u8 *, s32);
extern s32 func_L01_003AE5B8(u8 *);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C2880(u8 *);

void func_L01_003ADEC8(u8 *o) {
    u8 *s = *(u8 **)(o + 104);
    u8 *p;
    u8 *q;
    s32 st = o[32];

    if (st != 2) {
        if (st < 3) {
            if (st == 1) {
                func_L01_003ADFC0();
                func_L01_003AE0E8(o);
            }
        }
    } else {
        if (func_L01_004561B8(o) != 0) {
            func_L01_004AAC98(1, 0, o, 6496);
        }
        if (func_L01_003AE5B8(o) != 0) {
            p = *(u8 **)(o + 184);
            if (p != 0 && s[36] == 0) {
                p[188] = 1;
                s[36] = 1;
            }
        }
        if (func_0038CAD0(s + 20) != 0) {
            func_L01_004450F0(o, 3, -1);
            func_003C2880(o);
            q = *(u8 **)(o + 184);
            if (q != 0 && s[36] == 0) {
                q[188] = 2;
            }
        }
    }
}
/* localdecomp:end func_L01_003ADEC8 */

INCLUDE_ASM("asm/levels", func_L01_003ADFC0);

INCLUDE_ASM("asm/levels", func_L01_003AE0E8);

INCLUDE_ASM("asm/levels", func_L01_003AE1A0);

INCLUDE_ASM("asm/levels", func_L01_003AE5B8);

LINKER_REMNANT("asm/levels", func_L01_003AE6E0);

INCLUDE_ASM("asm/levels", func_L01_003AE6E8);

INCLUDE_ASM("asm/levels", func_L01_003AEA58);

INCLUDE_ASM("asm/levels", func_L01_003AEB68);

/* localdecomp:start func_L01_003AF118 */
extern void func_L01_004450F0(u8 *, s32, s32);

extern u8 D_001A4C60[];
extern void func_L01_003E8BD0(int, int, f32, f32);
extern void func_L01_003E8D48_003AF118(int, f32);
extern void func_L01_003E8F90(int, int);
extern int func_L01_00456500(void *, int);

void func_L01_003AF118(u8 *m) {
    u8 st = m[0x20];
    V_3AD948 *pv = *(V_3AD948 **)(m + 0x68);

    switch (st) {
    case 0:
        m[0x30] = 0xFF;
        ((void (*)(void *, int, int))func_L01_004450F0)(m, 1, -1);
    case 1:
        if (pv->f0 != -1 && func_L01_00456500(D_001A4C60, pv->f0) != 0) {
            ((void (*)(void *, int, int))func_L01_004450F0)(m, 2, -1);
        }
        break;
    case 2:
        func_L01_003E8BD0(0, 0, pv->f4, 0.003f);
        func_L01_003E8D48_003AF118(0, pv->f8 * 0.017453292f);
        if (pv->fC != -1) {
            if (pv->fC == 1) {
                func_L01_003E8F90(0, -1);
            } else if (pv->fC == 2) {
                func_L01_003E8F90(0, 1);
            } else if (pv->fC == 3) {
                func_L01_003E8F90(0, 2);
            }
        }
        if (func_L01_00456500(D_001A4C60, pv->f0) == 0) {
            ((void (*)(void *, int, int))func_L01_004450F0)(m, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L01_003AF118 */
