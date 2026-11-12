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

typedef struct { u8 pad0[0x70]; s16 f70; u8 pad72[4]; s16 f76; u8 pad78[0x20]; s16 f98; u8 pad9A[4]; s16 f9E; } S_L34_003BEFF8_g;

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

/* localdecomp:start func_L34_003BEFC0 */
void func_L34_003BEFC0(Obj_003BEF28 *p) {
    u8 *q = (u8 *)p->f68;

    *(u8 *)((u8 *)p + 0x30) = 0xFF;
    *(s32 *)(q + 0x60) = 0;
    *(s32 *)(q + 0x64) = 0;
    *(s32 *)(q + 0x68) = 0;
    *(s32 *)(q + 0x6C) = 0;
    *(s32 *)(q + 0x70) = 0;
    *(s32 *)(q + 0x74) = 0;
    *(s32 *)(q + 0x78) = 0;
    *(s32 *)(q + 0x7C) = 0;
    *(s32 *)(q + 0x80) = 0;
}
/* localdecomp:end func_L34_003BEFC0 */

/* localdecomp:start func_L34_003BEFF8 */
extern void func_003A1798(void);
extern S_L34_003BEFF8_g D_001CCFD0_003BEFF8;

void func_L34_003BEFF8(Obj_003BEF28 *a) {
    Sub_003BEF28 *s = a->f68;

    if (D_001CCFD0_003BEFF8.f70 >= 7000) {
        if (s->f80 != 0) {
            s->f80 = 0;
        }
    }
    if (D_001CCFD0_003BEFF8.f76 == 0 && D_001CCFD0_003BEFF8.f9E == 3 && D_001CCFD0_003BEFF8.f98 < 7000) {
        func_003A1798();
        s->f80 = 0;
    }
}
/* localdecomp:end func_L34_003BEFF8 */

INCLUDE_ASM("asm/levels", func_L34_003BF080);
