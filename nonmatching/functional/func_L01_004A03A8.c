/* functional: high. Retail differs only in branch layout (9 words). Reads of D_L01_001E0CD0 as s32; D_001439F4 unsized as retail uses lui. */
extern s32 D_L01_001E0CD0[];
extern s32 D_L01_001E0CC0[];
extern u8 D_001439F4[];
extern s32 D_L01_001D9590;
extern void func_L01_00514508(s32);
extern void func_003BB468(s32);
void func_L01_004A03A8(void) {
    O_49A988 *o;
    s32 v;
    if (D_L01_001E0CD0[0] != D_L01_001E0CC0[0]) {
        s32 t = D_L01_001E0CD0[0];
        v = 0;
        if (t == 1) {
            v = 1;
        } else if (t >= 2) {
            if (t == 2) v = 2;
        }
        D_001439F4[0] = v;
        func_L01_00514508(v);
    }
    o = func_003B42F8(0);
    o->vt->fn(o);
    func_003BB468(D_L01_001D9590);
}
