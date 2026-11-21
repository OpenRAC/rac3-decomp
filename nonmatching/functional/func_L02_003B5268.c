/* functional: high. Written from PAL asm; callee names resolved through functions.tsv (places column, level 02). The check compiles at level 02 (282 diff: block order/regalloc). Float constants verified from hex. gp-relative D_001D545C ($gp-0x7454) and D_L02_001DE2DC ($gp+0x1A2C) used by name. Retail's state==1 re-test after the state-0 body is kept (state 0 falls into the state-1 update in the same call). */
extern s32 D_001D545C;
extern u8 D_00142790;
extern u8 D_001A4C60[];
extern u8 D_001A7E18[];
extern f32 D_L02_001E8060[];
extern f32 D_L02_001DDF10;
extern s32 D_L02_001DE6B8;
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_00382538(void);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L02_003B4D68(void *);
extern void func_L02_003B4A98(void *);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003A1798(void);
extern void func_L02_003B5060(void *);
extern s32 func_00382468(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L02_003B5710(void *, s32);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_0039EF28(void);
extern void func_0039EC28(s32, s32);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2880(void *);

void func_L02_003B5268(u8 *obj) {
    u8 *p;
    u8 *par;
    f32 a[4];
    f32 b[4];
    s32 i;

    p = *(u8 **)(obj + 0x68);
    if (p == 0) return;
    if (D_001D545C == 3) {
        if (obj[0x20] != 0) return;
        obj[0x20] = 1;
        if (D_00142790 == 0) {
            *(s32 *)(obj + 0x98) = 0;
            *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(obj, 1);
            return;
        }
        *(f32 *)(obj + 0xF4) = func_0038DAB8(*(f32 *)(obj + 0xF4), 1.5707963705062866f);
        *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + 0.3499999940395355f;
        par = *(u8 **)(obj + 0x24);
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) & 0xFFBE) | (*(u16 *)(par + 0x44) & 0x1000);
        *(s32 *)(obj + 0x98) = *(s32 *)(par + 0x10);
        return;
    }
    if (obj[0x20] == 0) {
        if (D_00142790 != 0) {
            func_003C2880(obj);
            return;
        }
        *(vu0_v4 *)(p + 0x20) = *(vu0_v4 *)(obj + 0x10);
        *(f32 *)(p + 0x2C) = *(f32 *)(obj + 0xF8);
        *(vu0_v4 *)&a[0] = *(vu0_v4 *)(obj + 0x10);
        *(vu0_v4 *)&b[0] = *(vu0_v4 *)(obj + 0x10);
        a[2] = a[2] + 1.0f;
        b[2] = b[2] - 1.0f;
        if (func_003D3CB0(a, b, 2, obj, 0) != 0) {
            *(f32 *)(obj + 0x18) = D_L02_001E8060[2] + 0.5f;
        }
        *(f32 *)(obj + 0xF0) = func_00382538();
        *(f32 *)(obj + 0xF4) = func_00382538();
        *(f32 *)(obj + 0xF8) = func_00382538();
        *(f32 *)(obj + 0xFC) = func_00382538();
        *(f32 *)(p + 8) = *(f32 *)(obj + 0x18);
        func_L01_004450F0(obj, 1, -1);
    } else if (obj[0x20] == 1) {
        if (func_0038CF00(D_001A4C60, obj + 0x10) <= D_L02_001DDF10) {
            func_L02_003B4D68(obj);
        }
    }
    if (obj[0x20] == 1) {
        *(f32 *)(obj + 0xF0) = func_0038DAB8(*(f32 *)(obj + 0xF0), 0.041887905448675156f);
        *(f32 *)(obj + 0xF4) = func_0038DAB8(*(f32 *)(obj + 0xF4), 0.013962634839117527f);
        *(f32 *)(obj + 0xF8) = func_0038DAB8(*(f32 *)(obj + 0xF8), 0.0069813174195587635f);
        *(f32 *)(obj + 0xFC) = func_0038DAB8(*(f32 *)(obj + 0xFC), 0.03141592815518379f);
        func_L02_003B4A98(obj);
        func_L01_0044EAE0(obj, p, p + 4, 0.25f, 0.027925269678235054f, *(f32 *)(p + 8));
        *(s16 *)(obj + 0x96) = 0;
        return;
    }
    if (obj[0x20] != 2) return;
    {
        extern G_003B4D68 D_001CCFD0;
        if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
            func_003A1798();
        }
    }
    D_L02_001DE6B8 = 1;
    *(s16 *)(D_001A4BE0 + 0x1DC) = 3;
    func_L02_003B5060(obj);
    *(vu0_v4 *)(obj + 0x10) = *(vu0_v4 *)(D_001A4BE0 + 0x80);
    *(vu0_v4 *)(obj + 0xF0) = *(vu0_v4 *)(D_001A4BE0 + 0x90);
    if (obj[0x42] == 1) {
        if (func_00382468(10) == 0) func_L02_003B4A98(obj);
        if (obj[0x60] & 2) {
            if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 0);
            *(u16 *)(obj + 0x34) |= 1;
            obj[0x31] = 0;
            for (i = 3; i >= 0; i--) func_L02_003B4A98(obj);
        }
    }
    if (*(s32 *)(D_001A4BE0 + 0xC08) & 2) func_L01_0050FB40(0, 0, 25.0f);
    if (obj[0x42] != 0) return;
    if (func_0038CAD0(p + 0x7C) == 0) return;
    D_L02_001DE2DC = 0;
    func_L01_004F50C8(D_001A4BE0 + 0x80, D_001A4BE0 + 0x90, 0, 0);
    func_L01_003EB5E0(0, 0);
    func_003A52A0(0, 0, obj);
    func_L02_003B5710(obj + 0x10, 10);
    func_L01_00451F60(0x12A7, 0x1A1, 0);
    D_00142790 = 1;
    func_0039EF28();
    func_0039EC28(0, -1);
    if (*(u16 *)(D_001A7E18 + 0x8000 + 0x4540) == 0) func_L01_0041A5B0(0x1070, 0xDF);
    *(s32 *)(obj + 0x98) = 0;
    *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(obj, 1);
    func_003C2880(obj);
}
