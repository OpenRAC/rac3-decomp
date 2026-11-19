/* functional: high. US C carried to PAL and checked against PAL's assembly: PAL calls func_003A8440 (US func_003A82F8), func_003E5A98 (US 003E5950), func_003A4688 (US 003A4548), passes func_003A7EF8 (US 003A7DB0) as the callback, and its frame threshold is 15 instead of US 18 (50 Hz). The VU0 add is plain float code keeping w from the first operand; the draft's volatile read (a matching device) is dropped. Note: the US draft with only these PAL renames, keeping its volatile read of f34 and the j-form VU0 asm, is byte-EXACT (check.py MATCH); the volatile is not honest (not hardware memory), so it is kept out; without it 89 words differ (f34 reload). */
extern void func_003A8440(void);
extern s32 func_003E5A98(void);
extern void func_003A7EF8();
extern void func_003A4688(void);
s32 func_003A6C90(void) {
    s32 r;
    s32 over;
    f32 f;
    if (D_00225700_003A6C90.f60 != 0) return 0;
    if (!(D_00225700_003A6C90.f34 + 1 < D_00225700_003A6C90.f40)) {
        D_001D5B90_003A6C90 = 0;
        D_00225700_003A6C90.f60 = 1;
        return 0;
    }
    func_003E58D8();
    func_003A8440();
    f = D_001D9BD0_003A6C90 - 0.34f;
    D_00225700_003A6C90.f38++;
    D_00225700_003A6C90.f34++;
    D_001D9BD0_003A6C90 = f;
    if (f < 0.0f) D_001D9BD0_003A6C90 = 0.0f;
    if (!(D_00225700_003A6C90.f34 < D_00225700_003A6C90.f48)) func_003A1B98();
    r = 0;
    over = !(D_00225700_003A6C90.f34 < D_00225700_003A6C90.f40);
    if (D_00225700_003A6C90.f34 >= 15 && D_001D9BD0_003A6C90 == 0.0f) {
        if (((D_00142690_003A6C90[0] & 0xFFFF0000) != 0 || D_001D4D40_003A6C90 != 0 || D_001D545C_003A6C90 <= 0)
            && (((s32 *)D_001D52FC_003A6C90)[0x1A4 / 4] & 0x800)) {
            r = 1;
        } else {
            r = 1;
            if ((D_001D52FC_003A6C90->f1A0 & 0x8000000000FUL) ^ 0x8000000000FUL) r = 0;
        }
    }
    if (r != 0 || over) {
        D_00225700_003A6C90.f60 = 1;
        D_001D5B90_003A6C90 = 0;
    } else {
        s32 i;
        s32 v;
        s32 lim = D_00143950_003A6C90[0] ? 0x50 : 0x60;
        if (D_00225700_003A6C90.f38 >= lim) {
            D_00225700_003A6C90.f3C++;
            if (D_001CCFD4_003A6C90[0] != 0) func_003A2B50(1);
            func_003A70C8();
            func_003A6C08(D_00225700_003A6C90.f3C + 1);
        }
        v = func_003E5A98();
        for (i = 0; i < D_00225700_003A6C90.f44; i++) {
            O_3A1438 *o = D_00225700_003A6C90.f1A0[i];
            s32 h = D_00225700_003A6C90.f38 >> 1;
            u8 *p;
            V4_3A1438 a, b;
            o->f41 = h + 1;
            o->f40 = h;
            func_003C2D68_003A6C90(o);
            o->f44 = (f32)(D_00225700_003A6C90.f38 & 1) * 0.5f;
            if (v != 0 && (D_00225700_003A6C90.f38 & 1)) o->f44 = 1.0f;
            p = o->f68;
            func_0038D200_003A6C90(&a, p + o->f40 * 16, 1.0f - o->f44);
            func_0038D200_003A6C90(&b, p + o->f41 * 16, o->f44);
            /* VU0 vadd.xyz: w comes from a */
            o->f10.x = a.x + b.x;
            o->f10.y = a.y + b.y;
            o->f10.z = a.z + b.z;
            o->f10.w = a.w;
            {
                s32 aa = o->fAA;
                if (aa == 0xD54) {
                    o->f63 = 8;
                    func_003A5CC0(o, 0);
                    if (D_001DA008 == 0 || D_001DA008->fAA == aa) func_0038A2F8_003A6C90(func_003A7EF8, o);
                }
            }
            o->f61 = 0xFF;
            func_003C7FF0_003A6C90(o);
            if (o->fAA == 0) {
                D_001A4BE0_003A6C90.f25C0 = o;
                func_00381C78(o, 1);
            }
            if (o->fAA == 10) func_00381BA0(o);
        }
        if (D_001D4B60_003A6C90 == 4 || func_00381BC0_003A6C90() > 0) {
            E_3A1438 *e;
            for (e = D_001DA49C_003A6C90; e < D_001DA4A4_003A6C90; e++) {
                if (e->f20 < 0xFE && e->fAA == 0x50A) e->f34 |= 1;
            }
        }
    }
    func_003A4688();
    func_003D0ED8();
    func_003E5970();
    return r;
}
