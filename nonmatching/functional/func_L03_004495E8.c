/* functional: high. Rewritten from the asm. Parameters are ints to match the file's existing prototype (func_L03_004495E8(int, int)); a0 is the object, a1 the path (u32 count at +0, points as quads from +0x10). VU0 vsub/vadd.xyz are scalar here (no VU0 flag on the file). Not byte-matched. */
extern void *func_L01_0045B958(void *);
extern void func_L03_00449838(s32, s32, s16, s16);
extern void func_L01_0045A748(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
void func_L03_004495E8(int a0i, int a1i) {
    u8 *obj = (u8 *)a0i;
    u8 *path = (u8 *)a1i;
    f32 tgt[4] __attribute__((aligned(16)));
    f32 seg[4] __attribute__((aligned(16)));
    f32 rel[4] __attribute__((aligned(16)));
    u8 *st = func_L01_0045B958(obj);
    s32 idx, prev;
    f32 need;
    u8 *pc;
    u8 *pp;
    s32 t;
    if (st == 0) {
        return;
    }
    if (*(s32 *)(st + 0xC4) != a1i) {
        func_L03_00449838(a0i, a1i, 1, -1);
    }
    idx = *(s16 *)(st + 0xC8);
    pc = path + 0x10 + idx * 16;
    tgt[0] = *(f32 *)(pc + 0) - *(f32 *)(obj + 0x10);
    tgt[1] = *(f32 *)(pc + 4) - *(f32 *)(obj + 0x14);
    tgt[2] = *(f32 *)(pc + 8) - *(f32 *)(obj + 0x18);
    if ((*(s32 *)(st + 0x38) & 0x400) == 0) {
        tgt[2] = 0;
    }
    func_0038CF68(tgt, tgt, *(f32 *)(st + 0x34) * 10.0f + 1.0f);
    tgt[0] += *(f32 *)(obj + 0x10);
    tgt[1] += *(f32 *)(obj + 0x14);
    tgt[2] += *(f32 *)(obj + 0x18);
    func_L01_0045A748(obj, tgt);
    prev = (s16)(*(u16 *)(st + 0xC8) - *(u16 *)(st + 0xCA));
    if (prev < 0) {
        prev = (s16)(prev + *(u16 *)path);
    } else if (!(prev < *(s32 *)path)) {
        prev = (s16)(prev - *(u16 *)path);
    }
    idx = *(s16 *)(st + 0xC8);
    pc = path + 0x10 + idx * 16;
    pp = path + 0x10 + prev * 16;
    seg[0] = *(f32 *)(pc + 0) - *(f32 *)(pp + 0);
    seg[1] = *(f32 *)(pc + 4) - *(f32 *)(pp + 4);
    seg[2] = *(f32 *)(pc + 8) - *(f32 *)(pp + 8);
    if ((*(s32 *)(st + 0x38) & 0x400) == 0) {
        seg[2] = 0;
    }
    need = func_0038CEA8(seg) - *(f32 *)(st + 0x34);
    func_0038CF68(seg, seg, 1.0f);
    rel[0] = *(f32 *)(obj + 0x10) - *(f32 *)(pp + 0);
    rel[1] = *(f32 *)(obj + 0x14) - *(f32 *)(pp + 4);
    rel[2] = *(f32 *)(obj + 0x18) - *(f32 *)(pp + 8);
    if (need < func_0038CE68(rel, seg)) {
        t = *(u16 *)(st + 0xC8) + *(u16 *)(st + 0xCA);
        *(s16 *)(st + 0xC8) = t;
        if ((s16)t < 0) {
            *(s16 *)(st + 0xC8) = t + *(u16 *)path;
        } else if (!((s16)t < *(s32 *)path)) {
            *(s16 *)(st + 0xC8) = t - *(u16 *)path;
        }
    }
}
