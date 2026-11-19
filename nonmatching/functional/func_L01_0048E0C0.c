/* functional: high. 76 calls with identical targets/order as retail; check.py 544 diff lines are scheduling/regalloc. The NTSC-U draft's constants differ from PAL, all constants here were read from the PAL asm. */
extern s32 D_L01_001D8C80;
extern f32 D_L01_001D8CA8;
extern f32 D_L01_001D8CA4;
extern f32 D_L01_001D8CF0;
extern f32 D_L01_001D8CF4[];
extern f32 D_L01_001D8CF8;
extern f32 D_L01_001D8CFC[];
extern f32 D_L01_001D8CE4;
extern f32 D_L01_001D8CE8;
extern f32 D_L01_001D8CC0;
extern f32 D_L01_001D8CC4;
extern f32 D_L01_001D8CC8;
extern s32 D_L01_001D8C88;
extern s32 D_L01_001D8C8C;
extern s32 D_L01_001D8C90;
extern s32 D_L01_001D8C94;
extern u8 D_L01_002BCB00[];
extern u8 D_L01_001D8D00[];
extern u8 D_00160C40[];
extern void func_0039EF28(void);
extern void func_L01_0048D940(void);
extern s32 func_L01_00437540(void);
extern void func_L01_0048D970(void);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_L01_0047DB60(void);
extern void func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E7F20(s32, s32);
extern void func_003E8630(s32, s32);
extern void func_L01_00518D40(s32);
extern void func_L01_00518590(s32, s32, s32);
extern void func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E8898(s32, f32, f32);
extern void func_L01_00518010(s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00517BF8(s32, s32, s32, s32, s32, s32);
extern void func_L01_00517DB8(s32, s32, s32, f32);
extern void func_L01_00518670(s32, s32, s32);
extern void func_003E8A08(s32, s32, s32);
extern void func_L01_00516D60(s32, s32);
extern void func_L01_005168F0(s32, f32);
extern s32 func_003BB3A8(s32);
extern void func_003B4528(s32, s32, s32, s32, s32);
extern void func_003E8710(s32, s32);
extern void func_003E7AC8(s32, s32);
extern void func_L01_00516B90(s32, s32, s32);
extern void func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E8A58(s32, s32, s32, s32, s32);
extern void func_003E8348(s32, s32);
extern void func_003E87B8(s32, s32, s32);

void func_L01_0048E0C0(void) {
    s32 i;
    s32 t;
    s32 a;
    s32 b;

    func_L01_00437548();
    func_0039EF28();
    D_L01_001D8C80 = 0;
    func_L01_0048D940();
    if (func_L01_00437540() != 0) {
        func_L01_0048D970();
        func_L01_00437548();
    }
    func_003B9298(0x10, 0xd000b, 0xd0002, 0xd0003, 0xd0004, 0xd0000, 0xd0001, 0xd0005, 0xd0008, (s32)func_00381FF0(0x174), 0xd0006, 0, 0xd0007, 0xcd5, 8.5f);
    if (D_L01_001D8C80 == 0) {
        if (func_L01_0047DB60() != 2) {
            func_003E8FE8(0xd000a, (s32)func_00381FF0(0x1b81), 0x8066ccff, 0.970000029f, 0.5f, 1.0f, 1.0f);
            func_003E7F20(0xd000a, 1);
            func_003E8630(0xd000b, 0xd000a);
        }
    }
    func_L01_00518D40(0x160000);
    func_L01_00518D40(0x160002);
    func_L01_00518590(0x160000, 1, 1);
    func_003E9138(0x160008, 0x332299de, 0, 0.5f, 0.5f, 0.800000012f, 0.0500000007f);
    func_003E8630(0x160000, 0x160008);
    for (i = 0; i < 4; i++) {
        func_003E8FE8(0x160011 + i, (s32)func_00381FF0(*(s32 *)(D_L01_001D8C84 + i * 0x14)), 0x8066ccff, D_L01_001D8CA8, D_L01_001D8CA4, 1.0f, 1.0f);
        func_003E8898(0x160011 + i, 0.800000012f, 0.800000012f);
        func_L01_00518010(0x160011 + i, 1);
        func_003E8630(0x160000, 0x160011 + i);
        func_L01_00516AA0(0x160011 + i, 0x40, 1);
        func_003E9138(0x160016 + i, 0x332299de, 0, D_L01_001D8CA8, D_L01_001D8CA4, 0.775000036f, 0.00666699978f);
        func_003E8630(0x160000, 0x160016 + i);
    }
    func_003E9358(0x160003, (s32)D_L01_002BCB00, 0x8066ccff, D_L01_001D8CF0, D_L01_001D8CF4[0], D_L01_001D8CF8, D_L01_001D8CFC[0], 1.0f);
    func_L01_00516AA0(0x160003, 0x40, 1);
    func_L01_00517BF8(0x160003, 1, 1, 1, 0, 0);
    func_L01_00517DB8(0x160003, 0x64, 0, 0.000500000024f);
    func_003E7F20(0x160003, 1);
    func_003E9358(0x160006, (s32)D_L01_001D8D00, 0x8066ccff, D_L01_001D8CE4, D_L01_001D8CE8, D_L01_001D8CF8, 0.0613319986f, 0.899999976f);
    func_L01_00516AA0(0x160006, 0x40, 1);
    func_L01_00518670(0x160006, 1, 1);
    func_003E8A08(0x160002, 0x160003, 0x160006);
    func_003E9138(0x16000f, 0x332299de, 0, 0.322916001f, 0.35916701f, 0.432999015f, 0.00666699978f);
    func_003E8630(0x160002, 0x16000f);
    func_003E9138(0x160009, 0x706ec8ff, 0x7569, D_L01_001D8CC0, D_L01_001D8CC4, 0.0350000001f, 0.043076925f);
    func_L01_00516D60(0x160009, 0);
    func_L01_005168F0(0x160009, 4.71238899f);
    func_L01_00516AA0(0x160009, 0x40, 1);
    func_003E9138(0x16000a, 0x706ec8ff, 0x7569, D_L01_001D8CC0, D_L01_001D8CC8, 0.0350000001f, 0.043076925f);
    func_L01_005168F0(0x16000a, 1.57079637f);
    func_L01_00516AA0(0x16000a, 0x40, 1);
    func_L01_00516D60(0x16000a, 0);
    func_003E8A08(0x160000, 0x160009, 0x16000a);
    a = func_003BB3A8(0);
    b = func_003BB3A8(0);
    D_L01_001D8C88 = b;
    D_L01_001D8C8C = (a + 15) & 0xfffffff0;
    func_003B4528((s32)func_003B42F8(0), D_L01_001D8C8C, D_L01_001D8C88, *(s32 *)(D_00160C40 + 0x4954), (s32)(D_00160C40 + 0x5950));
    t = func_003BB3A8(0);
    D_L01_001D8C90 = t;
    D_L01_001D8C94 = (t + 0x8c0f) & 0xfffffff0;
    func_003B4528((s32)func_003B42F8(1), D_L01_001D8C90, D_L01_001D8C94, *(s32 *)(D_00160C40 + 0x4954), (s32)(D_00160C40 + 0x7080));
    func_003E9138(0x160004, 0x80808080, 0, 0.741999984f, 0.437000006f, 0.339899987f, 0.341500014f);
    func_003E8710(0x160004, (s32)func_003B42F8(0));
    func_003E8630(0x160002, 0x160004);
    func_003E9138(0x160010, 0x80808080, 0, 0.502499998f, 0.194999993f, 0.817499995f, 0.105760001f);
    func_003E8710(0x160010, (s32)func_003B42F8(1));
    func_L01_00516AA0(0x160010, 0x8000, 1);
    func_003E8630(0x160002, 0x160010);
    func_003E8FE8(0x160007, 0, 0xc066ccff, 0.889999986f, 0.219999999f, 1.0f, 1.0f);
    func_003E7F20(0x160007, 1);
    func_003E7AC8(0x160007, 1);
    func_L01_00516B90(0x160007, 2, 3);
    func_003E8630(0x160002, 0x160007);
    func_003E9270(0x16000d, 0x332299de, 0.5f, 0.194999993f, 0.824999988f, 0.114500001f, 0.00350000011f, 0.00600000005f);
    func_003E9270(0x16000b, 0x332299de, 0.324499995f, 0.434329987f, 0.474999994f, 0.351999998f, 0.00350000011f, 0.00600000005f);
    func_003E9270(0x16000c, 0x332299de, 0.74000001f, 0.434329987f, 0.344249994f, 0.351999998f, 0.00350000011f, 0.00600000005f);
    func_003E9270(0x16000e, 0x332299de, 0.5f, 0.739000022f, 0.824999988f, 0.246000007f, 0.00350000011f, 0.00600000005f);
    func_003E8A58(0x160002, 0x16000b, 0x16000c, 0x16000e, 0x16000d);
    func_003E8348(0x11, 0x160000);
    func_003E8348(0x12, 0x160002);
    func_L01_00516D60(0x160004, 0);
    func_003E87B8(0x160004, 1, 8);
}

