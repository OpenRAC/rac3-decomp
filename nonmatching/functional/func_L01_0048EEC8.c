/* functional: high. Constants and arguments machine-read from the asm. */
extern s32 D_L01_001D8D08;
extern u8 D_00160C40[];
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_0047DE68(void);
extern s32 func_003BB3A8(s32);
extern void func_L01_00518D40(s32);
extern void func_003E8348(s32, s32);
extern void func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E7AC8(s32, s32);
extern void func_L01_00516B90(s32, s32, s32);
extern void func_003E7F20(s32, s32);
extern void func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_003B4528(s32, s32, s32, s32, s32);
extern void func_003E8710(s32, s32);
extern void func_L01_00518480(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L01_0048EEC8(void) {
    s32 t;
    s32 a;
    s32 b;

    t = (s32)func_00381FF0(0x116);
    func_003B9298(0x10, 0xd000b, 0xd0002, 0xd0003, 0xd0004, 0xd0000, 0xd0001, 0xd0005, 0xd0008, t, 0xd0006, 0x15c6, 0xd0007, 0x177, 7.5f);
    func_L01_0047DE68();
    t = func_003BB3A8(0);
    D_L01_001D8D08 = t;
    func_L01_00518D40(0x180001);
    func_003E8348(0x11, 0x180001);
    t = (s32)func_00381FF0(0x172);
    func_003E8FE8(0x180003, t, 0x8066ccff, 0.100000001f, 0.785000026f, 0.800000012f, 0.800000012f);
    func_003E7AC8(0x180003, 1);
    func_L01_00516B90(0x180003, 1, 3);
    t = (s32)func_00381FF0(0x171);
    func_003E8FE8(0x180002, t, 0x8066ccff, 0.899999976f, 0.785000026f, 0.800000012f, 0.800000012f);
    func_003E7AC8(0x180002, 1);
    func_L01_00516B90(0x180002, 2, 3);
    t = (s32)func_00381FF0(0x11a);
    func_003E8FE8(0x180008, t, 0x8066ccff, 0.100000001f, 0.824999988f, 0.800000012f, 0.800000012f);
    func_003E7AC8(0x180008, 1);
    func_L01_00516B90(0x180008, 1, 3);
    t = (s32)func_00381FF0(0x11b);
    func_003E8FE8(0x180009, t, 0x8066ccff, 0.899999976f, 0.824999988f, 0.800000012f, 0.800000012f);
    func_003E7AC8(0x180009, 1);
    func_L01_00516B90(0x180009, 2, 3);
    func_003E8FE8(0x180007, 0, 0x8066ccff, 0.889999986f, 0.319999993f, 1.25f, 1.25f);
    func_003E7AC8(0x180007, 1);
    func_L01_00516B90(0x180007, 2, 3);
    func_003E7F20(0x180007, 1);
    func_003E9270(0x180004, 0x332299de, 0.5f, 0.25f, 0.827000022f, 0.224999994f, 0.00350000011f, 0.00600000005f);
    func_003E9270(0x180005, 0x332299de, 0.5f, 0.61500001f, 0.827000022f, 0.493499994f, 0.00350000011f, 0.00600000005f);
    func_003E9138(0x180006, 0x80808080, 0, 0.502499998f, 0.250999987f, 0.818000019f, 0.212249994f);
    func_L01_00516AA0(0x180006, 0x8000, 1);
    a = (D_L01_001D8D08 + 15) & 0xfffffff0;
    b = (a + 0x800f) & 0xfffffff0;
    func_003B4528((s32)func_003B42F8(0), a, b, *(s32 *)(D_00160C40 + 0x4954), (s32)(D_00160C40 + 0x7080));
    func_003E8710(0x180006, (s32)func_003B42F8(0));
    func_L01_00518480(0x180001, 0x180002, 0x180003, 0x180008, 0x180009, 0x180006, 0x180007, 0x180004, 0x180005);


}
