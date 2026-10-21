/* US draft of func_003ED988 (rac3-uya-decomp func_003E8420, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003ED988 */
typedef struct { u8 p0[8]; void *f8; u8 pC[4]; s32 f10, f14, f18, f1C; f32 f20, f24; s32 f28; } O_3E8420;
extern u8 D_001D96D8[];
extern void **func_003E70E8();
extern void func_003EDAD0(void *, s32, s32);
extern void func_003EDB08(void *, s32, s32);
extern void func_003EDB68(void *, f32, f32);
extern void func_003EDB90(void *, f32, f32);
O_3E8420 *func_003ED988(O_3E8420 *p) {
    func_003E70E8(p);
    p->f8 = D_001D96D8;
    p->f28 = 0x80808080;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1C = 0;
    p->f20 = 0;
    p->f24 = 0;
    func_003EDAD0(p, 1, 1);
    func_003EDAD0(p, 2, 0);
    func_003EDAD0(p, 4, 1);
    func_003EDAD0(p, 8, 1);
    func_003EDAD0(p, 0x20, 0);
    func_003EDAD0(p, 0x10, 0);
    func_003EDAD0(p, 0x40, 0);
    func_003EDAD0(p, 0x80, 0);
    func_003EDAD0(p, 0x100, 0);
    func_003EDB08(p, 3, 3);
    func_003EDB68(p, 0.5f, 0.5f);
    func_003EDB90(p, 1.0f, 1.0f);
    p->f28 = 0x40000000;
    p->f20 = 0.005f;
    p->f24 = 0.005f;
    return p;
}
/* localdecomp:end func_003ED988 */
