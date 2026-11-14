/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_003C5E20, the NTSC-U twin of func_L01_003C76A0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L01_003C64E0.c's current line.
 * Worker's note: 61 diff; best log w52/func_L01_003C5E20.01.log; inline literal assembler mismatch: retail lui/ori/mtc1 1/60 versus compiler lit4 load; all other instructions align after 8-byte shift 61 diff; best log w60/func_L01_003C5E20-01.log; confirmed inline literal assembler mismatch: retail lui/ori/mtc1 1/60
 */
#include "common.h"
/* localdecomp:start func_L01_003C5E20 */
typedef struct { char p0[0xC8]; float timer; char p1[0x5F0]; int index; char p2[0x10]; int a[8]; int b[8]; int c[4]; int d[8]; } State;
extern void func_L01_003C5670(void *, State *);
extern int func_L01_003C4FE0(void *);
extern void func_L01_003C5F90(void *, State *, int, int, int);
extern void func_L01_00441FB8(void *, int, int);
extern void func_L01_003C3C68(void *, State *);
extern void func_L01_003C3F30(void *, State *, int);
extern void func_L01_003C55F8(void *, State *);
extern void func_L01_003C3A10(void *, State *);
extern float D_001DECC0_sda;
void func_L01_003C5E20(void *obj, State *s, int enabled) {
    func_L01_003C5670(obj,s);
    if (enabled && s->d[s->index] != -1 && !func_L01_003C4FE0(obj)) {
        func_L01_003C5F90(obj,s,s->d[s->index],s->a[s->index],1);
        s->timer = D_001DECC0_sda * (1.0f/60.0f);
        if (s->c[s->index] != -1) func_L01_00441FB8(obj,1,-1);
        else func_L01_00441FB8(obj,2,-1);
        func_L01_003C3C68(obj,s);
    } else {
        s->timer = 0;
        func_L01_003C3F30(obj,s,s->a[s->index]);
        if (s->b[s->index]) func_L01_00441FB8(obj,5,-1);
        else func_L01_00441FB8(obj,4,-1);
        func_L01_003C55F8(obj,s);
        func_L01_003C3A10(obj,s);
    }
}
/* localdecomp:end func_L01_003C5E20 */
