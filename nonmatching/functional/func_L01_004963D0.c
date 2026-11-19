/* functional: high. Compiles at level_01 (73 diff: lui vs gp-relative load of D_001D545C, otherwise same). Called indirect methods are passed no a0, as retail leaves a0 unset. */
extern u8 D_L01_001D9190;
extern s32 D_L01_001D9198;
extern s32 D_L01_001DC1B0;

extern s32 D_001D545C;
extern u8 D_00160C40[];
extern s32 D_L01_001E15E0[];
extern void func_L01_00496B00(void);
extern void func_003A5348(s32, s32, s32);
extern s32 *func_L01_0043B548(s32, s32);
extern s32 func_003BB3A8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern s32 *func_003E6C08(void);
extern s32 func_003E6DE8(s32 *);
extern u8 *func_003E6378(s32, s32);

void func_L01_004963D0(void) {
    s32 *obj;
    s32 *inst;
    u8 *z;
    s32 mem;

    func_L01_00496B00();
    func_003A5348(0x12, 0, 0);
    if (D_001D545C == 3) {
        obj = func_L01_0043B548(0x1936, 0x10);
        if (obj != 0) {
            ((void (*)(s32))obj[2])(1);
        }
    } else if (D_001D545C == 7) {
        obj = func_L01_0043B548(0x1AD1, 0xC);
        if (obj != 0) {
            ((void (*)(s32))obj[0])(1);
        }
    }
    D_L01_001D9190 = 0;
    mem = func_003BB3A8(1);
    D_L01_001D9198 = (mem + 0xF) & ~0xF;
    func_003B4528((void *)func_003B42F8(0), D_L01_001D9198, 0, *(s32 *)(D_00160C40 + 0x4954), (s32)(D_00160C40 + 0x7260));
    inst = D_L01_001E15E0;
    if (D_L01_001E15E0[1] == 0) {
        inst = func_003E6C08();
    }
    z = func_003E6378(func_003E6DE8(inst), 0x47001C);
    if (z != 0) {
        s32 *vt = *(s32 **)(z + 8);
        s32 ok = ((s32 (*)(u8 *, s32))vt[4])(z, D_L01_001DC1B0);
        if (ok == 0) {
            z = 0;
        }
    }
    *(s32 *)(z + 0x50) = (s32)func_003B42F8(0);
}
