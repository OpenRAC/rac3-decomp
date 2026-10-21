/* US draft of func_003F0AC0 (rac3-uya-decomp func_003F0940, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003F0AC0 */
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
extern S_3EB180 D_001DA938_003F0AC0[];
extern s32 *func_003E6FC0();
extern void *func_003EDD40_003F0AC0();
extern void **func_003E7078();
extern void func_003F0D38(void *, s32);
extern void func_003F0E78(u8 *, s32, f32, f32);
extern s32 func_003F0FA0(u8 *arg0, s32, s32);
extern void func_003F0E28(void *, f32);
extern void func_003F1090(void *, s32);
extern void func_003F0D38(void *p, f32 value);
extern void func_003F0D48(void *p, s16 value);
extern void func_003F0D58(void *p, s16 value);
extern void func_003F0F28(u8 *p, s32 m, s32 on);

void *func_003F0AC0(T_3EB180 *p) {
    /* func_003F2740 is operator new(size, heap). gcc assumes malloc's result
     * aliases nothing, so the new object's stores can move past p->f2C. */
    extern void *malloc(s32, s32) __asm__("func_003F2740");
    S_3EB180 *q;
    void **t;
    O_3EB180 *o;
    func_003EDD40_003F0AC0(p);
    p->f2C = 0;
    p->f8 = &D_001D97C8;
    q = D_001DA938_003F0AC0;
    if (q->f4 == 0) q = (S_3EB180 *)func_003E6FC0();
    t = func_003E7078(q, 1);
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
        func_003F0D38(p, 0x80808080);
        func_003F0E78((u8 *)p, 1, 0.0f, 0.0f);
        func_003F0FA0((u8 *)p, 0, 0);
        func_003F0E28(p, 0.03846f);
        func_003F1090(p, 2);
        func_003F0D38(p, 0.0005f);
        func_003F0D48(p, 0);
        func_003F0D58(p, 0);
        p->f2C->f56 = 0;
        p->f2C->f59 = 0;
        func_003F0F28((u8 *)p, 4, 0);
        func_003F0F28((u8 *)p, 8, 0);
        func_003F0F28((u8 *)p, 0x10, 0);
        func_003F0F28((u8 *)p, 0x40, 1);
        p->f2C->f5A = 0;
    }
    return p;
}
/* localdecomp:end func_003F0AC0 */
