#include "common.h"

/* localdecomp:start func_L39_0061D0B8 */
typedef struct {
    u8 pad0[0x24C9];
    u8 idx;
    u8 pad24CA[0x4E];
    u8 on;
} S_61A940;

extern s32 D_L39_00241118[];
extern u8 D_L39_001DA778[8];
extern S_61A940 *func_L39_0061BF38(s32);
extern void func_L39_0058B1B8(s32, s32, s32, s32);

void func_L39_0061D0B8(void) {
    S_61A940 *p = func_L39_0061BF38(D_L39_00241118[0]);
    if (p->on) {
        if (D_L39_001DA778[p->idx] < 96) {
            D_L39_001DA778[p->idx] += 2;
        }
    } else {
        if (D_L39_001DA778[p->idx] == 0) {
            return;
        }
        D_L39_001DA778[p->idx] -= 2;
    }
    if (D_L39_001DA778[p->idx]) {
        func_L39_0058B1B8(0, 0, 0, D_L39_001DA778[p->idx]);
    }
}
/* localdecomp:end func_L39_0061D0B8 */

/* localdecomp:start func_L39_0061D150 */
extern s32 D_L39_0024D758[];
extern s32 D_L39_001E204C;
extern void func_L39_0061E0C0(void);
extern void func_L39_0061D8C0(s32 a0);
extern void func_L39_0061D9D8(s32 a0);
extern void func_L39_0061DAF0(s32 a0);
extern void func_L39_0061DC08(s32 a0);
extern void func_L39_0061DD20(s32 a0);
extern void func_L39_0061DE38(s32 a0);
extern void func_L39_0061DF50(s32 a0);

void func_L39_0061D150(void) {
    D_L39_001E204C = -1;
    D_L39_0024D758[0] = -1;
    func_L39_0061E0C0();
    func_L39_0061D8C0(1);
    func_L39_0061D9D8(2);
    func_L39_0061DAF0(3);
    func_L39_0061DC08(4);
    func_L39_0061DD20(5);
    func_L39_0061DE38(6);
    func_L39_0061DF50(7);
}
/* localdecomp:end func_L39_0061D150 */

/* localdecomp:start func_L39_0061D1B0 */
extern s32 D_L39_0024D75C[];
extern s32 D_L39_001E2048;
extern void func_L39_0061D6A8(void);
void func_L39_0061D1B0(s32 a0, s32 a1) {
    D_L39_0024D75C[0] = a0;
    D_L39_001E2048 = a1;
    func_L39_0061D6A8();
}
/* localdecomp:end func_L39_0061D1B0 */

INCLUDE_ASM("asm/levels", func_L39_0061D1D8);

INCLUDE_ASM("asm/levels", func_L39_0061D2D8);

INCLUDE_ASM("asm/levels", func_L39_0061D3F0);

INCLUDE_ASM("asm/levels", func_L39_0061D470);

INCLUDE_ASM("asm/levels", func_L39_0061D540);

/* localdecomp:start func_L39_0061D628 */
typedef struct S_61AEB0 S_61AEB0;

typedef struct {
    u8 pad[12];
    void (*fn)(S_61AEB0 *);
} V_61AEB0;

struct S_61AEB0 {
    u8 pad[12];
    S_61AEB0 *next;
    u8 pad2[4];
    V_61AEB0 *vt;
};

extern S_61AEB0 *D_L39_0024CE40[];

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
