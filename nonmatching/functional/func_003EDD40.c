/* functional: high. Constructor of a render/object class: runs the base ctor func_003E74A0(p), sets vtable-like pointer p->f8 = D_001D96D8 and zeroes f10..f24, sets default flags 0x80808080 (before the first flag call, as retail's delay slot), applies nine func_003EDE88(p, bit, on) flag settings, func_003EDEC0(p,3,3), func_003EDF20(p,.5,.5), func_003EDF48(p,1,1), then f28 = 0x40000000 and f20 = f24 = 0.005f; returns p. Verified against PAL asm. */
typedef struct { u8 p0[8]; void *f8; u8 pC[4]; s32 f10, f14, f18, f1C; f32 f20, f24; s32 f28; } O_003EDD40;
extern u8 D_001D96D8[];
extern void **func_003E74A0();
extern void func_003EDE88(void *, s32, s32);
extern void func_003EDEC0(void *, s32, s32);
extern void func_003EDF20(void *, f32, f32);
extern void func_003EDF48(void *, f32, f32);

O_003EDD40 *func_003EDD40(O_003EDD40 *p)
{
    func_003E74A0(p);
    p->f8 = D_001D96D8;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1C = 0;
    p->f20 = 0;
    p->f24 = 0;
    p->f28 = 0x80808080;
    func_003EDE88(p, 1, 1);
    func_003EDE88(p, 2, 0);
    func_003EDE88(p, 4, 1);
    func_003EDE88(p, 8, 1);
    func_003EDE88(p, 0x20, 0);
    func_003EDE88(p, 0x10, 0);
    func_003EDE88(p, 0x40, 0);
    func_003EDE88(p, 0x80, 0);
    func_003EDE88(p, 0x100, 0);
    func_003EDEC0(p, 3, 3);
    func_003EDF20(p, 0.5f, 0.5f);
    func_003EDF48(p, 1.0f, 1.0f);
    p->f28 = 0x40000000;
    p->f20 = 0.005f;
    p->f24 = 0.005f;
    return p;
}
