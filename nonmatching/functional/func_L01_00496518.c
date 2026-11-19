/* functional: high. Compiles at level_01 (121 diff, structure matched by reading). Indirect object methods called with no a0, as retail. */
extern u8 D_L01_001D9190;
extern f32 D_L01_001D9194;
extern s16 D_L01_001D9192;

extern s32 D_001D52FC;
extern s32 D_001D545C;
extern f32 D_L01_001DF950;
extern void func_L01_00497BE0(void);
extern void func_L01_0047DAD0(s32);
extern s32 *func_L01_0043B548(s32, s32);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090(s32);

void func_L01_00496518(s32 a0) {
    s32 *obj;
    s32 r;
    s32 cnt;
    s32 mode = D_001D545C;
    u8 st = D_L01_001D9190;

    if (st == 1) {
        if (*(s32 *)(D_001D52FC + 0x1C4) & 0x10) {
            D_L01_001D9190 = 0;
        }
        return;
    }
    if (st == 2) {
        f32 limit = (D_L01_001D9194 * 5.0f + 2.0f) / 6.0f;
        cnt = (u16)(D_L01_001D9192 + 1);
        D_L01_001D9192 = cnt;
        if (limit <= (f32)(s16)cnt) {
            func_L01_00497BE0();
            goto done;
        }
        return;
    }
    if (mode == 3) {
        obj = func_L01_0043B548(0x1936, 0x10);
        if (obj == 0) {
            return;
        }
        if (((s32 (*)(void))obj[1])() != 0 || (*(s32 *)(D_001D52FC + 0x1C4) & 0x80)) {
            func_L01_0047DAD0(4);
            goto done;
        }
        if (((s32 (*)(void))obj[3])() != 0) {
            goto done;
        }
        return;
    }
    if (mode != 7) {
        return;
    }
    obj = func_L01_0043B548(0x1AD1, 0xC);
    if (*(s32 *)(D_001D52FC + 0x1C4) & 0x80) {
        func_L01_0047DAD0(4);
        goto done;
    }
    if (obj == 0) {
        return;
    }
    r = ((s32 (*)(void))obj[1])();
    if (r == 1) {
        goto done;
    }
    if (r == 3) {
        func_L01_0047DAD0(0xA);
        D_L01_001D9190 = 2;
        D_L01_001DF950 = 1.0f;
        D_L01_001D9192 = 0;
    } else if (r == 2) {
        D_L01_001D9190 = 1;
    }
    return;
done:
    func_L01_00517748(func_L01_0047EBE0());
    func_L01_00516090(a0);
}
