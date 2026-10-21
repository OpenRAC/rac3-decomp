/* US draft of func_003EDD40 (rac3-uya-decomp func_003EDBE0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003EDD40 */
typedef struct { u8 p0[8]; void *f8; u8 pC[4]; s32 f10, f14, f18, f1C; f32 f20, f24; s32 f28; } O_3E8420;
extern u8 D_001D96D8[];
extern void **func_003E74A0();
extern void func_003EDE88(void *, s32, s32);
extern void func_003EDEC0(void *, s32, s32);
extern void func_003EDF20(void *, f32, f32);
extern void func_003EDF48(void *, f32, f32);
O_3E8420 *func_003EDD40(O_3E8420 *p) {
    func_003E74A0(p);
    p->f8 = D_001D96D8;
    p->f28 = 0x80808080;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1C = 0;
    p->f20 = 0;
    p->f24 = 0;
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
/* localdecomp:end func_003EDD40 */
