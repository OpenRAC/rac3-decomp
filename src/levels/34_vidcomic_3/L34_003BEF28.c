#include "common.h"

typedef struct {
    u8 pad0[0x80];
    s32 f80;
} Sub_003BEF28;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x47];
    Sub_003BEF28 *f68;
} Obj_003BEF28;
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x6C - 0x28];
    s32 f6C;
    u8 pad70[0x94 - 0x70];
    s32 f94;
} Glob_003BEF28;

/* localdecomp:start func_L34_003BEF28 */
extern Glob_003BEF28 D_001CCFD0[];
extern void func_L34_003BEFC0(Obj_003BEF28 *);
extern void func_L01_004450F0(Obj_003BEF28 *, s32, s32);
extern void func_L34_003BEFF8(Obj_003BEF28 *);
extern void func_L34_003BF080(Obj_003BEF28 *);

void func_L34_003BEF28(Obj_003BEF28 *p) {
    Sub_003BEF28 *q = p->f68;

    if (p->f20 == 0) {
        func_L34_003BEFC0(p);
        func_L01_004450F0(p, 1, -1);
    }
    if (D_001CCFD0[0].f6C == 0 && D_001CCFD0[0].f24 == -1 && D_001CCFD0[0].f94 == 0 && q->f80 == 0) {
        func_L34_003BF080(p);
    }
    func_L34_003BEFF8(p);
}
/* localdecomp:end func_L34_003BEF28 */

INCLUDE_ASM("asm/levels", func_L34_003BEFC0);

INCLUDE_ASM("asm/levels", func_L34_003BEFF8);

INCLUDE_ASM("asm/levels", func_L34_003BF080);
