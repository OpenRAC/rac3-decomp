#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003967C8);

INCLUDE_ASM("asm/levels", func_L03_00396860);

INCLUDE_ASM("asm/levels", func_L03_00396E00);

INCLUDE_ASM("asm/levels", func_L03_00396FF0);

/* localdecomp:start func_L03_00397138 */
typedef struct { u8 pad0[0x140]; s32 idx; } S_00397138;
typedef struct { u8 pad0[0x43]; u8 st; u8 pad1[0x24]; S_00397138 *p; } A_00397138;
extern u8 *D_L03_001DF99C;
extern void func_003C3A10(void *, s32, s32, s32);
void func_L03_00397138(void *a, s32 b, s32 c, s32 d) {
    A_00397138 *o = a;
    S_00397138 *s;
    if (o->st != b) {
        s = o->p;
        func_003C3A10(a, b, c, d);
        func_003C3A10(D_L03_001DF99C + (s->idx << 8), b, c, d);
    }
}
/* localdecomp:end func_L03_00397138 */

INCLUDE_ASM("asm/levels", func_L03_003971B0);

INCLUDE_ASM("asm/levels", func_L03_00397260);

INCLUDE_ASM("asm/levels", func_L03_00397390);

/* localdecomp:start func_L03_003975A8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    char pad0[0x120];
    u128_t v120;
    char pad130[0x1C];
    int i14C;
    char pad150[0xC];
    short s15C;
    short s15E;
} S_003975A8;
typedef struct {
    char pad0[0x68];
    S_003975A8 *p68;
    char pad6C[0x3E];
    short sAA;
} O_003975A8;
extern u128_t *D_L03_0021D8C0[];
__asm__(".extern D_L03_0021D8C0, 16");

void func_L03_003975A8(void *a, int b, int c) {
    O_003975A8 *o = a;
    S_003975A8 *s;
    if (o->sAA == 0x18DE) {
        s = o->p68;
        if (s->i14C != -1 && s->s15E != c) {
            u128_t *t = D_L03_0021D8C0[s->i14C];
            s->s15E = c;
            s->s15C = b;
            s->v120 = t[b + 1];
        }
    }
}
/* localdecomp:end func_L03_003975A8 */

/* localdecomp:start func_L03_00397608 */
extern u8 D_001DE308_sda[4];
__asm__(".extern D_001DE308_sda, 4");
extern void *D_001DE310_sda;
__asm__(".extern D_001DE310_sda, 8");
extern s32 D_00142C10[];
extern void func_L03_0034B348(s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_00397608(s32 idx) {
    if (D_00142C10[0] & 0x80000) {
        func_L03_0034B348(D_001DE308_sda[idx]);
        func_L01_004450F0(D_001DE310_sda, 3, 0);
    }
}
/* localdecomp:end func_L03_00397608 */

/* localdecomp:start func_L03_00397650 */
extern u8 D_001DE308_sda[4];
__asm__(".extern D_001DE308_sda, 4");
extern u8 D_001D5530[8];
s32 func_L03_00397650(s32 i) { return D_001D5530[D_001DE308_sda[i]] != 0; }
/* localdecomp:end func_L03_00397650 */
