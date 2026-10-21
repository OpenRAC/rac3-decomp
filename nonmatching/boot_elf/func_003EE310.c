/* US draft of func_003EE310 (rac3-uya-decomp func_003EE1B0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003EE310 */
typedef struct { s32 *arr[16]; s32 x40, x44, x48, x4C, x50, x54; f32 x58, x5C; } O_3E89F0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E89F0 *x2C; } T_3E89F0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_3E89F0;
extern u8 D_001D9708[8];
void **func_003E7078(s32 *, s32);
s32 func_003EE310(T_3E89F0 *p) {
    /* func_003F2740 is operator new, which gcc treats as malloc: naming it
     * malloc lets the object's stores move past p->x2C, as in retail. */
    extern void *malloc(s32, s32) __asm__("func_003F2740");
    S_003E8838 *q;
    void **t;
    O_3E89F0 *o;
    s32 i;
    s32 **w;
    func_003EDD40((O_3E8420 *)p);
    p->f8 = &D_001D9708;
    if (D_001DA938_003EE158->x4 != 0) q = D_001DA938_003EE158;
    else q = (S_003E8838 *)func_003E6FC0(D_001DA938_003EE158);
    t = func_003E7078((s32 *)q, 1);
    if (t != 0) {
        o = (O_3E89F0 *)malloc(0x60, ((VT_3E89F0 *)*t)->f8(t, 0x60));
        w = o->arr;
        i = 15;
        do { *w++ = 0; } while (--i != -1);
        p->x2C = o;
        o->x40 = 0;
        o->x54 = 0;
        o->x5C = 1.0f;
        o->x50 = 0;
        o->x44 = 0;
        o->x58 = 1.0f;
        o->x48 = 0;
        func_003EE518(p, 1, 0);
    }
    return (s32)p;
}
/* localdecomp:end func_003EE310 */
