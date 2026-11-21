/* functional: high. C++ constructor (operator new via func_003F2740) verified against PAL asm: the object's 16 pointer slots are zeroed, x40..x54 cleared, x58/x5C = 1.0f. The US draft's `malloc` alias is replaced by a plain extern declaration (bytes only). */
typedef struct { s32 *arr[16]; s32 x40, x44, x48, x4C, x50, x54; f32 x58, x5C; } O_003EE310;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_003EE310 *x2C; } T_003EE310;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_003EE310;
extern u8 D_001D9708[8];
extern s32 D_1DA938[];
extern void func_003EDD40();
extern s32 *func_003E6FC0();
extern void **func_003E7078(s32 *, s32);
extern void *func_003F2740(s32, s32);
extern void func_003EE518();
s32 func_003EE310(T_003EE310 *p) {
    s32 *q;
    void **t;
    O_003EE310 *o;
    s32 i;
    s32 **w;
    func_003EDD40(p);
    p->f8 = D_001D9708;
    if (D_1DA938[1] != 0) q = D_1DA938;
    else q = func_003E6FC0(D_1DA938);
    t = func_003E7078(q, 1);
    if (t != 0) {
        o = (O_003EE310 *)func_003F2740(0x60, ((VT_003EE310 *)*t)->f8(t, 0x60));
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
