#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

INCLUDE_ASM("asm/levels", func_L01_0035BF48);

INCLUDE_ASM("asm/levels", func_L01_0035C098);

/* localdecomp:start func_L01_0035C6B0 */
extern void func_L01_004C8668(int);
extern void func_003C2880(void *);
void func_L01_0035C6B0(char *m)
{
    char *v = *(char **)(m + 104);
    if (v != 0) {
        func_L01_004C8668(*(int *)(v + 44));
    }
    func_003C2880(m);
}
/* localdecomp:end func_L01_0035C6B0 */

INCLUDE_ASM("asm/levels", func_L01_0035C6F0);

INCLUDE_ASM("asm/levels", func_L01_0035C8D0);

INCLUDE_ASM("asm/levels", func_L01_0035CAD0);

INCLUDE_ASM("asm/levels", func_L01_0035CFC8);

INCLUDE_ASM("asm/levels", func_L01_0035D358);

INCLUDE_ASM("asm/levels", func_L01_0035D738);

INCLUDE_ASM("asm/levels", func_L01_0035DAF0);

INCLUDE_ASM("asm/levels", func_L01_0035DC18);

INCLUDE_ASM("asm/levels", func_L01_0035DEC8);

INCLUDE_ASM("asm/levels", func_L01_0035E010);

INCLUDE_ASM("asm/levels", func_L01_0035E418);

INCLUDE_ASM("asm/levels", func_L01_0035E450);

/* localdecomp:start func_L01_0035E488 */
extern void func_003C2880(void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004C8668(s32);
extern void func_L01_0035E450(u8 *);

void func_L01_0035E488(u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);

    if (*(s32 *)(pv + 0x24) == 0) {
        func_L01_003303B8(m + 16, 0, 0, 0, 0, 30, 0, 0, 0.75f, 0.0f, 0.0f, 2.0f,
                      0, 0, 0, 0, 0, 0, 0x10000, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000, 0xFF8F00, 0xFF6430, 0x7FFFA060, 0x28FF0000, 0xFF6430, 0);
    }
    func_L01_004C8668(*(s32 *)(pv + 0x2C));
    func_L01_0035E450(m);
    ((void (*)(u8 *))func_003C2880)(m);
}
/* localdecomp:end func_L01_0035E488 */

INCLUDE_ASM("asm/levels", func_L01_0035E598);

LINKER_REMNANT("asm/levels", func_L01_0035E630);

INCLUDE_ASM("asm/levels", func_L01_0035E638);

INCLUDE_ASM("asm/levels", func_L01_0035E710);

LINKER_REMNANT("asm/levels", func_L01_0035EB18);

INCLUDE_ASM("asm/levels", func_L01_0035EB20);

INCLUDE_ASM("asm/levels", func_L01_0035ED40);

INCLUDE_ASM("asm/levels", func_L01_0035EF20);

INCLUDE_ASM("asm/levels", func_L01_0035F048);

INCLUDE_ASM("asm/levels", func_L01_0035F340);

INCLUDE_ASM("asm/levels", func_L01_0035F480);

/* localdecomp:start func_L01_0035FEB8 */
void func_L01_0035FEB8(u8 *a) {
    a[32] = 3;
}
/* localdecomp:end func_L01_0035FEB8 */

INCLUDE_ASM("asm/levels", func_L01_0035FEC8);

INCLUDE_ASM("asm/levels", func_L01_00360170);

INCLUDE_ASM("asm/levels", func_L01_00360398);

/* localdecomp:start func_L01_003609D0 */
extern void func_L01_00361D60_003609D0(void *);
extern void func_L01_003609D0(void *);

extern void func_L01_00361AC0_003609D0();
void func_L01_003609D0(void *p) {
    func_L01_00361AC0_003609D0(p);
    func_L01_00361D60_003609D0(p);
}
/* localdecomp:end func_L01_003609D0 */

/* localdecomp:start func_L01_00360A00 */
extern void func_003A9440(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s16 D_001CFEC0[];

void func_L01_00360A00(void) {
    func_003A9440(66, 72);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], (s32)0x80808080);
}
/* localdecomp:end func_L01_00360A00 */

INCLUDE_ASM("asm/levels", func_L01_00360A48);

INCLUDE_ASM("asm/levels", func_L01_003612E0);

/* localdecomp:start func_L01_00361568 */


extern void func_0038D328(s128 *, S_38C110v *);
extern void func_0038D640(s128 *, void *, s128 *);
extern void func_0038CE20(s128 *, s128 *, f32);
extern void func_L01_003612E0(s128 *, f32, f32, f32, s32, f32, s32, s32);

void func_L01_00361568(S_38C110v *a0, void *a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16, f32 f17) {
    S_38C110v v;
    s128 m1[4];
    s128 m2[4];

    v.x = 0.0f;
    v.y = 0.0f;
    v.z = f12;
    v.w = 1.0f;
    func_0038D328(m1, &v);
    func_0038D640(m2, a1, m1);
    func_0038CE20(&m2[0], &m2[0], f13);
    func_0038CE20(&m2[1], &m2[1], f13);
    func_0038CE20(&m2[2], &m2[2], f13);
    *(S_38C110v *)&m2[3] = *a0;
    func_L01_003612E0(m2, f17, f14, f15, a2, f16, a3, 1);
}
/* localdecomp:end func_L01_00361568 */

INCLUDE_ASM("asm/levels", func_L01_00361690);

INCLUDE_ASM("asm/levels", func_L01_00361AC0);

INCLUDE_ASM("asm/levels", func_L01_00361D60);

INCLUDE_ASM("asm/levels", func_L01_00361FA8);

/* localdecomp:start func_L01_00362600 */
void func_L01_00362600(u8 *a) {
    a[32] = 3;
}
/* localdecomp:end func_L01_00362600 */

INCLUDE_ASM("asm/levels", func_L01_00362610);

INCLUDE_ASM("asm/levels", func_L01_00362758);

/* localdecomp:start func_L01_00363138 */
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F160[];
s32 func_L01_00363138(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F160[i] != 0) n++;
    }
    return n;
}
/* localdecomp:end func_L01_00363138 */

/* localdecomp:start func_L01_00363170 */
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];
extern s32 D_L01_0028F160[];
s32 func_L01_00363170(s32 *out) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        s32 v = D_L01_0028F160[i];
        if (v != 0) {
            D_L01_0028F160[i] = 0;
            *out = D_L01_0028F0C0[i];
            D_L01_0028F0C0[i] = 0;
            return v;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_00363170 */

INCLUDE_ASM("asm/levels", func_L01_003631C8);

INCLUDE_ASM("asm/levels", func_L01_00363468);

INCLUDE_ASM("asm/levels", func_L01_00363690);

INCLUDE_ASM("asm/levels", func_L01_00363BF0);

/* localdecomp:start func_L01_00363D90 */
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F160[];

s32 func_L01_00363D90(void) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F160[i] != 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_00363D90 */

/* localdecomp:start func_L01_00363DD0 */
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];

s32 func_L01_00363DD0(void) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F0C0[i] != 0) return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00363DD0 */

/* localdecomp:start func_L01_00363E10 */
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];

s32 func_L01_00363E10(s32 value) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F0C0[i] == value) return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00363E10 */

LINKER_REMNANT("asm/levels", func_L01_00363E50);
