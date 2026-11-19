/* functional: high. Checked every compare (a5,a6,a1,flags,a2,a3,a4 against fields 0x2C,0x28,0x20,0x24,0x30,0x34,0x38), the D_001D5B94==5 early-out (index 0 and 2 excepted), the serial counter D_001D9E88 (gp-0x2A28 == D_001D9E88, same variable) and stores to 0x64,0x68,0x7C,0x70; index*0x90 struct stride. 46 words differ (scheduling of the lw in compare delay slots). */
typedef struct { s32 f0; s32 f4; u8 p8[0x18]; s32 f20; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; u8 p3C[0x28]; s32 f64; s32 f68; u8 p6C[4]; s32 f70; u8 p74[8]; s32 f7C; u8 p80[0x10]; } S_EB;
extern S_EB D_00331AE0_00393728[];
extern s32 D_001D5B94_00393728;
extern s32 D_001D9E88_00393728;
extern s32 D_001D9E88;
extern void func_00393830(S_EB *);
s32 func_00393728(s32 arg0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    S_EB *p;
    s32 index = arg0 & 15;
    s32 flags;
    p = &D_00331AE0_00393728[index];
    flags = arg0 & 0xFFF0;
    if (D_001D5B94_00393728 == 5 && index != 2 && index != 0) return 0;
    if (p->f2C != a5 || p->f28 != a6 || p->f20 != a1 ||
        p->f24 != flags || p->f30 != a2 || p->f34 != a3 || p->f38 != a4) {
        s32 serial = D_001D9E88_00393728;
        p->f64 = serial;
        p->f2C = a5;
        p->f28 = a6;
        p->f20 = a1;
        p->f30 = a2;
        p->f34 = a3;
        p->f38 = a4;
        D_001D9E88 = serial + 1;
        p->f68 = 1;
        p->f24 = flags;
        p->f7C = 0;
        p->f70 = 0;
        if (flags & p->f4 & 0x20) func_00393830(p);
    }
    return p->f64;
}
