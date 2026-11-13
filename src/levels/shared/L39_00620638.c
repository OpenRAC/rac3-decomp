#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00620638);

/* localdecomp:start func_L39_00620AF8 */
typedef struct { u8 pad0[0x1A14]; u8 f1A14; } O_00620AF8;
extern s32 func_L39_006626C8_00620AF8(void *, s32);
extern s32 func_L39_006625A8(void *, s32, s32, s32);
extern void func_L39_00662AA0(s32, void *, s32);

void func_L39_00620AF8(O_00620AF8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 buf;
    s32 h;
    if (arg0->f1A14 != 0) {
        if (arg2 != 0) {
            if (func_L39_006626C8_00620AF8(arg0, 8) == 0) {
                h = func_L39_006625A8(arg0, 8, 0, 0);
                buf = arg1;
                func_L39_00662AA0(h, &buf, 1);
                buf = arg3;
                func_L39_00662AA0(h, &buf, 1);
            }
        } else {
            if (func_L39_006626C8_00620AF8(arg0, 6) == 0) {
                h = func_L39_006625A8(arg0, 6, 0, 0);
                buf = arg1;
                func_L39_00662AA0(h, &buf, 1);
                buf = arg3;
                func_L39_00662AA0(h, &buf, 1);
            }
        }
    }
}
/* localdecomp:end func_L39_00620AF8 */

/* localdecomp:start func_L39_00620BE8 */
void func_L01_00443EA0(s32, s32);

void func_L39_00620BE8(void) {
    func_L01_00443EA0(0x18CB, 0x171C);
    func_L01_00443EA0(0x18CC, 0x171C);
    func_L01_00443EA0(0x18CF, 0x171C);
    func_L01_00443EA0(0x18CD, 0x171C);
    func_L01_00443EA0(0x1ADC, 0x171C);
    func_L01_00443EA0(0x16DB, 0x171C);
    func_L01_00443EA0(0x1CFC, 0x171C);
    func_L01_00443EA0(0x1E68, 0x171C);
    func_L01_00443EA0(0x1E07, 0x171C);
    func_L01_00443EA0(0x1CFB, 0x171C);
    func_L01_00443EA0(0x1E77, 0x171C);
    func_L01_00443EA0(0x1E78, 0x171C);
    func_L01_00443EA0(0x1CFD, 0x171C);
    func_L01_00443EA0(0x1CFE, 0x171C);
    func_L01_00443EA0(0x1E4C, 0x171C);
    func_L01_00443EA0(0x1E65, 0x171C);
    func_L01_00443EA0(0x1E4D, 0x171C);
    func_L01_00443EA0(0x1E69, 0x171C);
    func_L01_00443EA0(0x1E59, 0x171C);
    func_L01_00443EA0(0x1E7A, 0x171C);
    func_L01_00443EA0(0x1E83, 0x171C);
}
/* localdecomp:end func_L39_00620BE8 */

INCLUDE_ASM("asm/levels", func_L39_00620CF8);

INCLUDE_ASM("asm/levels", func_L39_00620E28);

/* localdecomp:start func_L39_006212E8 */
s32 func_L39_006212E8(void *arg0) {
    if ((*(s32 *)((u8 *)arg0 + 0x474)) == 2) {
        return (*(s32 *)((u8 *)arg0 + 0x478));
    }
    return -1;
}
/* localdecomp:end func_L39_006212E8 */

/* localdecomp:start func_L39_00621308 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0xA0];
    u128_t q0A0;
    u8 padB0[0x2348 - 0xB0];
    s32 head;
    s32 count;
} S_00621308;

void func_L39_00621308(S_00621308 *s) {
    *(u128_t *)((s->head << 4) + (s32)s + 0x1DC0) = s->q0A0;
    s->head = (s->head + 1) % 32;
    s->count++;
    if (s->count > 32) {
        s->count = 32;
    }
}
/* localdecomp:end func_L39_00621308 */

/* localdecomp:start func_L39_00621370 */
typedef int u128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0xA0];
    u128 xA0;
    u8 padB0[0x1DC0 - 0xB0];
    u128 x1DC0;
    u8 pad1DD0[0x2348 - 0x1DD0];
    s32 x2348;
    s32 x234C;
} func_0061EBD0_t;

void func_L39_00621370(func_0061EBD0_t *a) {
    a->x2348 = 1;
    a->x1DC0 = a->xA0;
    a->x234C = 1;
}
/* localdecomp:end func_L39_00621370 */
