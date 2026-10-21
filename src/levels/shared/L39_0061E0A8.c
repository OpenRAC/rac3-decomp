#include "common.h"

/* localdecomp:start func_L39_0061E0A8 */
s32 func_L39_0061E0A8(void) {
    return 0;
}
/* localdecomp:end func_L39_0061E0A8 */

/* localdecomp:start func_L39_0061E0B0 */
s32 func_L39_0061E0B0(u8 *a0, s32 a1) {
    return *(s32 *)(a0 + 0x18) == a1;
}
/* localdecomp:end func_L39_0061E0B0 */

/* localdecomp:start func_L39_0061E0C0 */
extern void func_L39_0061E3B8(s32);
extern void func_L39_0061E4D0(s32);
extern void func_L39_0061E5E8(s32);
extern void func_L39_0061E700(s32);
extern void func_L39_0061E818(s32);
extern void func_L39_0061E930(s32);
extern void func_L39_0061EA48(s32);
extern void func_L39_0061EB60(s32);

void func_L39_0061E0C0(void) {
    func_L39_0061E3B8(0);
    func_L39_0061E4D0(1);
    func_L39_0061E5E8(2);
    func_L39_0061E700(3);
    func_L39_0061E818(4);
    func_L39_0061E930(5);
    func_L39_0061EA48(6);
    func_L39_0061EB60(7);
}
/* localdecomp:end func_L39_0061E0C0 */

INCLUDE_ASM("asm/levels", func_L39_0061E118);

LINKER_REMNANT("asm/levels", func_L39_0061E1A0);

INCLUDE_ASM("asm/levels", func_L39_0061E1B8);

INCLUDE_ASM("asm/levels", func_L39_0061E278);

/* localdecomp:start func_L39_0061E330 */
typedef struct S_61BBB8 S_61BBB8;

typedef struct {
    u8 pad[16];
    void (*fn)(S_61BBB8 *);
} V_61BBB8;

struct S_61BBB8 {
    u8 pad[4];
    S_61BBB8 *next;
    u8 pad2[4];
    V_61BBB8 *vt;
};

extern S_61BBB8 *D_L39_0024CEA0[];

void func_L39_0061E330(void) {
    s32 i;
    S_61BBB8 *p;
    S_61BBB8 *q;

    for (i = 0; i < 8; i++) {
        p = D_L39_0024CEA0[i];
        while (p != 0) {
            q = p;
            p = p->next;
            q->vt->fn(q);
        }
    }
}
/* localdecomp:end func_L39_0061E330 */
