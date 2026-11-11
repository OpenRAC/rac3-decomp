#include "common.h"

/* The guber pools (multiplayer network objects). Each of the 8 types has its used and free lists,
   its pool's base, entry count and entry size; the tables are small data in the multiplayer
   levels (inside their $gp window), which this file's code reaches with lui/addiu. */
struct S_61AEB0;

typedef struct {
    u8 pad[8];
    void (*init)(struct S_61AEB0 *);
    void (*fn)(struct S_61AEB0 *);
} V_61AEB0;

typedef struct S_61AEB0 {
    u32 uid;
    s32 owner;
    s32 state;
    struct S_61AEB0 *next;
    struct S_61AEB0 *prev;
    V_61AEB0 *vt;
} S_61AEB0;

extern S_61AEB0 *D_L39_0024CE40[8] __attribute__((section(".sdata")));
extern S_61AEB0 *D_L39_0024CE60[8] __attribute__((section(".sdata")));
extern u8 *D_L39_0024CE80[8] __attribute__((section(".sdata")));
extern s32 D_L39_00245EE0[8] __attribute__((section(".sdata")));
extern s32 D_L39_00245F00[8] __attribute__((section(".sdata")));
extern s32 D_L39_0024D758[] __attribute__((section(".sdata")));
extern s32 D_L39_0024D75C[] __attribute__((section(".sdata")));

INCLUDE_ASM("asm/levels", func_L39_0061D1D8);

INCLUDE_ASM("asm/levels", func_L39_0061D2D8);

INCLUDE_ASM("asm/levels", func_L39_0061D3F0);

INCLUDE_ASM("asm/levels", func_L39_0061D470);

INCLUDE_ASM("asm/levels", func_L39_0061D540);

/* localdecomp:start func_L39_0061D628 */
void func_L39_0061D628(void) {
    s32 i;
    S_61AEB0 *p;
    S_61AEB0 *q;

    for (i = 0; i < 8; i++) {
        p = D_L39_0024CE40[i];
        while (p != 0) {
            q = p;
            p = p->next;
            q->vt->fn(q);
        }
    }
}
/* localdecomp:end func_L39_0061D628 */

INCLUDE_ASM("asm/levels", func_L39_0061D6A8);

/* localdecomp:start func_L39_0061D780 */
extern s32 func_L39_0061D7B0(void *a0);
u32 func_L39_0061D780(void) {
    s32 *p = ((s32 * (*)(void))func_L39_0061D7B0)();
    if (p) return *p;
    return 0xFFFFFFFF;
}
/* localdecomp:end func_L39_0061D780 */

/* localdecomp:start func_L39_0061D7B0 */
typedef s32 (*Fn_0061B038)(void *);
extern Fn_0061B038 *func_L39_005C1018(void);
s32 func_L39_0061D7B0(void *a0) {
    s32 r;
    if (a0) {
        r = func_L39_005C1018()[1](a0);
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_0061D7B0 */

/* localdecomp:start func_L39_0061D7F8 */
void func_L39_0061D7F8(s32 arg0, void *arg1) {
    *(s32 *)((u8 *)arg1 + 0x90) = arg0;
}
/* localdecomp:end func_L39_0061D7F8 */

INCLUDE_ASM("asm/levels", func_L39_0061D800);

/* localdecomp:start func_L39_0061D8B8 */
s32 func_L39_0061D8B8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x90));
}
/* localdecomp:end func_L39_0061D8B8 */

INCLUDE_ASM("asm/levels", func_L39_0061D8C0);

INCLUDE_ASM("asm/levels", func_L39_0061D9D8);

INCLUDE_ASM("asm/levels", func_L39_0061DAF0);

INCLUDE_ASM("asm/levels", func_L39_0061DC08);

INCLUDE_ASM("asm/levels", func_L39_0061DD20);

INCLUDE_ASM("asm/levels", func_L39_0061DE38);

INCLUDE_ASM("asm/levels", func_L39_0061DF50);
