#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { char p[0x444]; int f444; char q[0x470-0x448]; u128_t v; } B;
typedef struct { char p[0x10]; u128_t v; char q[0x68-0x20]; B *b; } A;

/* localdecomp:start func_L19_003C0910 */
extern void func_L19_003C2628(char *, float, char *, int);

void func_L19_003C0910(char *arg0)
{
    func_L19_003C2628(arg0, *(float *)(arg0 + 0xF8), arg0 + 0x10, 0);
}
/* localdecomp:end func_L19_003C0910 */

INCLUDE_ASM("asm/levels", func_L19_003C0938);

INCLUDE_ASM("asm/levels", func_L19_003C0960);

INCLUDE_ASM("asm/levels", func_L19_003C1F18);

INCLUDE_ASM("asm/levels", func_L19_003C2388);

INCLUDE_ASM("asm/levels", func_L19_003C2628);

INCLUDE_ASM("asm/levels", func_L19_003C27A8);

/* localdecomp:start func_L19_003C2930 */
void func_0038CAD0(s32);
void func_0038CB00(s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L19_001E2100[];

void func_L19_003C2930(void *arg0) {
    s32 temp_s1;
    u16 temp_v1;

    temp_s1 = *(s32 *)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L19_001E2100, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
    func_0038CB00(temp_s1 + 0x414);
    func_0038CB00(temp_s1 + 0x416);
    func_0038CAD0(temp_s1 + 0x458);
}
/* localdecomp:end func_L19_003C2930 */

/* localdecomp:start func_L19_003C29D0 */
extern void func_L01_004450F0(A *, int, int);
extern void func_003C2880(A *);
void func_L19_003C29D0(A *a) {
    B *b = a->b;
    if (b->f444 != 0) {
        a->v = b->v;
        func_L01_004450F0(a, 1, 1);
    } else {
        func_003C2880(a);
    }
}
/* localdecomp:end func_L19_003C29D0 */

/* localdecomp:start func_L19_003C2A20 */
void func_L01_004443E8(s32, s32, s32);
void func_L01_00315900(void *, s32, void *);
extern u8 D_L19_003C29D0[];

void func_L19_003C2A20(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    func_L01_004443E8((s32) arg0, 0, 3);
    if ((*(s32 *)((u8 *)temp_s0 + 0x444)) != 0) {
        *(s8 *)((u8 *)arg0 + 0x7F) = 0;
        *(u16 *)((u8 *)arg0 + 0xB6) = (u16) ((u16) (*(u16 *)((u8 *)arg0 + 0xB6)) >> 1);
        *(u16 *)((u8 *)arg0 + 0xB4) = (u16) ((s32) ((*(u16 *)((u8 *)arg0 + 0xB4)) << 0x10) >> 0x11);
    }
    func_L01_00315900(arg0, 0, D_L19_003C29D0);
}
/* localdecomp:end func_L19_003C2A20 */

INCLUDE_ASM("asm/levels", func_L19_003C2A98);

/* localdecomp:start func_L19_003C2BC0 */
s32 func_L19_003C2BC0(void *arg0) {
    s32 var_a1;

    var_a1 = 0;
    if ((arg0 != 0) && ((*(s16 *)((u8 *)arg0 + 0xAA)) == 0x1C13)) {
        var_a1 = (*(u8 *)((u8 *)arg0 + 0x95)) == 1;
    }
    return var_a1;
}
/* localdecomp:end func_L19_003C2BC0 */

INCLUDE_ASM("asm/levels", func_L19_003C2BF0);

INCLUDE_ASM("asm/levels", func_L19_003C2CC8);

INCLUDE_ASM("asm/levels", func_L19_003C3788);

INCLUDE_ASM("asm/levels", func_L19_003C3898);

/* localdecomp:start func_L19_003C3998 */
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
__asm__(".extern D_L19_001DF71C, 16");
extern s32 D_L19_001DF758;
extern s32 func_L19_003C2BC0(void *a);

s32 func_L19_003C3998(u8 *object) {
    u8 *o = *(u8 **)(object + 0x68);
    s32 count;
    u16 *p;
    u8 *e;
    if (*(s32 *)(o + 0x80) < 0)
        return 0;
    count = 0;
    p = D_L19_0021C260[*(s32 *)(o + 0x80)];
    while ((*(s32 *)(o + 0x80) & 0xFF) != 0xFF && D_L19_001DF758 >= *(s32 *)(o + 0x80) && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L19_0021C260[*(s32 *)(o + 0x80)])) {
        e = D_L19_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        p++;
        if (func_L19_003C2BC0(e))
            count++;
    }
    return count;
}
/* localdecomp:end func_L19_003C3998 */

INCLUDE_ASM("asm/levels", func_L19_003C3A78);

INCLUDE_ASM("asm/levels", func_L19_003C3B60);
