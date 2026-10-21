/* Near miss of func_003F0708 with its file's own flags: tools/check.py reports 42 diff
   (the US draft it started from: 103).
   What differs: Two float arguments (0.03846f = 0x3D1D883C, 0.0005f = 0x3A03126F): retail
   builds them inline (lui $at,0x3d1d / ori $at,$at,0x883c / mtc1 $at,$f12), which is SN
   Ps2EeAs expanding gcc's `li.s` reference to a .lit4 pool entry; with the file's flags
   (default assembler ee-as) the same gcc output expands to a $gp-relative lwc1
   $f12,-0x4000($gp). gcc only builds a constant inline when its low 16 bits are zero
   (verified: 0.0625f -> lui $at,0x3d80 / mtc1 $at,$f12), so no C wording of these two values
   can produce retail's inline form with the default assembler (per docs/wiki/Matching-
   Patterns.md...
*/

/* US draft of func_003F0708 (rac3-uya-decomp func_003EB180, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003F0708 */
/* PAL names: func_003EB578/func_003EB588/func_003EB598 are func_003F0B00/func_003F0B20/func_003F0B48.
 * D_001D97C8 is reached by retail with lui/addiu, so it is used through the unsized alias
 * D_001D97C8_003F0708[] (a sized extern u8 is small data and gets a $gp-relative addiu);
 * that alias needs an entry in config/frontbin/symbol_addrs_resolved.txt for the full build. */
typedef struct {
    s32 f0, f4, f8, fC, f10, f14;
    s16 f18, f1A;
    s32 f1C;
    u8 f20;
    s16 f22;
    f32 f24, f28;
    s32 f2C, f30;
    u32 f34, f38;
    s32 f3C, f40, f44;
    u8 p48[2];
    u8 f4A;
    u8 p4B[0x56 - 0x4B];
    s16 f56;
    u8 p58;
    u8 f59, f5A;
} O_3EB180;
typedef struct { u8 p0[8]; void *f8; u8 pC[0x2C - 0xC]; O_3EB180 *f2C; u8 f30; s32 f34; } T_3EB180;
typedef struct { s32 f0; s32 f4; } S_3EB180;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_3EB180;
extern u8 D_001D97C8;
extern u8 D_001D97C8_003F0708[];
extern S_3EB180 D_001DA938_003F0708[];
extern s32 *func_003E6C08();
extern void *func_003ED988_003F0708();
extern void **func_003E6CC0();
extern void func_003F0980(void *, s32);
extern void func_003F0AC0(u8 *, s32, f32, f32);
extern s32 func_003F0BE8(u8 *arg0, s32, s32);
extern void func_003F0A70(void *, f32);
extern void func_003F0CD8(void *, s32);
extern void func_003F0B00(void *, f32);
extern void func_003F0B20(void *, s32);
extern void func_003F0B48(void *, s32);
extern void func_003F0B70(u8 *p, s32 m, s32 on);

void *func_003F0708(T_3EB180 *p) {
    /* func_003F2388 is operator new(size, heap). gcc assumes malloc's result
     * aliases nothing, so the new object's stores can move past p->f2C. */
    extern void *malloc(s32, s32) __asm__("func_003F2388");
    void **t;
    O_3EB180 *o;
    S_3EB180 *q;
    func_003ED988_003F0708(p);
    q = D_001DA938_003F0708;
    p->f2C = 0;
    p->f8 = D_001D97C8_003F0708;
    if (q->f4 == 0) q = (S_3EB180 *)func_003E6C08();
    t = func_003E6CC0(q, 1);
    p->f30 = 0;
    p->f34 = 0;
    if (t != 0) {
        o = (O_3EB180 *)malloc(0x5C, ((VT_3EB180 *)*t)->f8(t, 0x5C));
        o->f34 = 0x80808080;
        o->f0 = 0;
        o->f4 = 0;
        o->f3C = 0;
        o->f40 = 0;
        o->f44 = 0;
        p->f2C = o;
        o->f24 = 1.0f;
        o->fC = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f18 = 0;
        o->f1C = 0;
        o->f20 = 0;
        o->f22 = 0;
        o->f2C = 0;
        o->f30 = 0;
        o->f8 = 0;
        o->f38 = 0x80808080;
        o->f1A = -1;
        o->f4A = 0x10;
        o->f28 = 1.0f;
        func_003F0980(p, 0x80808080);
        func_003F0AC0((u8 *)p, 1, 0.0f, 0.0f);
        func_003F0BE8((u8 *)p, 0, 0);
        func_003F0A70(p, 0.03846f);
        func_003F0CD8(p, 2);
        func_003F0B00(p, 0.0005f);
        func_003F0B20(p, 0);
        func_003F0B48(p, 0);
        p->f2C->f56 = 0;
        p->f2C->f59 = 0;
        func_003F0B70((u8 *)p, 4, 0);
        func_003F0B70((u8 *)p, 8, 0);
        func_003F0B70((u8 *)p, 0x10, 0);
        func_003F0B70((u8 *)p, 0x40, 1);
        p->f2C->f5A = 0;
    }
    return p;
}
/* localdecomp:end func_003F0708 */
