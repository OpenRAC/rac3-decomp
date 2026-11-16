/* NTSC-U draft (Claude wave C2): C of func_L07_003DB958, the NTSC-U twin of func_L07_003DD5D8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 0 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L07_003DB958", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (0 diff) only with @ps2as (inline lui/ori/mtc1 for 1.1f and -0.122173056f); the PAL file's flags have none. Spawn of class 0x1D2D copying obj's 0x30/0x32/0x38(ld)/0x10/0xF0 (quads) and scaling class f24 by 1.1f, then p->f60 = o, ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L07_003DD5D8 (src/levels/07_annihilation_nation/L07_003DCB60.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef int s64_003DB958 __attribute__((mode(DI)));

/* localdecomp:start func_L07_003DB958 */
extern u8 *func_003BCFB0(s32, s32);
extern void func_003C26C8(void *);
extern void func_00389018(void *, s32, f32);
extern void func_00388440(void *, s32, s32);
extern void func_L01_00437350(void *, s32, void *);
extern void func_L07_003DBA58(void *);

void func_L07_003DB958(u8 *obj)
{
    u8 *p;
    u8 *o;
    u8 *v;

    if (obj[0x20] == 0) {
        p = *(u8 **)(obj + 0x68);
        o = func_003BCFB0(0x1D2D, 0x80);
        if (o != 0) {
            o[0x31] = 1;
            *(u16 *)(o + 0x32) = *(u16 *)(obj + 0x32);
            o[0x30] = obj[0x30];
            *(s64_003DB958 *)(o + 0x38) = *(s64_003DB958 *)(obj + 0x38);
            *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * 1.1f;
            *(u128_t *)(o + 0x10) = *(u128_t *)(obj + 0x10);
            *(u128_t *)(o + 0xF0) = *(u128_t *)(obj + 0xF0);
            func_003C26C8(o);
        }
        *(u8 **)(p + 0x60) = o;
        func_00389018(p + 0x50, 2, -0.122173056f);
        v = p + 0x10;
        func_00388440(v, 0, 0x40);
        func_L01_00437350(obj, 0, v);
        *(void **)(p + 4) = (void *)func_L07_003DBA58;
        func_L07_003DBA58(obj);
    }
}
/* localdecomp:end func_L07_003DB958 */
