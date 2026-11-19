/* functional: high. Float expressions and operand order machine-read from the asm. */
extern s32 D_L01_001D8D68;
extern u8 D_L01_002EB098[];
extern f32 D_L01_001D8D88;
extern f32 D_L01_001D8D90;
extern f32 D_L01_001D8D7C;
extern f32 D_L01_001D8D84;
extern f32 D_L01_001D8D8C;
extern f32 D_L01_001D8D94;
extern void func_L01_004908D8(void);
extern void func_L01_004903F0(s32);
extern void func_L01_00499B20(s32, s32, s32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_003E8348(s32, s32);
extern void func_L01_004906D0(void);
extern void func_L01_00518D40(s32);
extern void func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00516B90(s32, s32, s32);
extern void func_L01_005170B8(s32, s32);
extern void func_003E8B98(s32, s32, s32, s32, s32, s32, s32);
extern void func_003E8A08(s32, s32, s32);
extern void func_L01_00490FC8(void);
extern void func_003E8710(s32, s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516D60(s32, s32);
extern void func_003E87B8(s32, s32, s32);

void func_L01_0048FBF0(void) {
    f32 fa = 1.0f;
    f32 fb = 0.0f;
    s32 t;

    D_L01_001D8D68 = -1;
    func_L01_004908D8();
    func_L01_004903F0((s32)D_L01_002EB098);
    func_L01_00499B20(0xcbd, (s32)&fa, (s32)&fb);
    t = (s32)func_00381FF0(0xcbd);
    func_003B9298(0x10, 0xd000b, 0xd0000, 0xd0001, 0xd0002, 0xd0003, 0xd0004, 0xd0005, 0xd0008, t, 0xd0006, 0xff, 0xd0007, 0xcd5, fb);
    func_L01_00517538(0xd0005, fa, fa);
    func_003E8348(0x11, 0x1e0000);
    func_L01_004906D0();
    func_L01_00518D40(0x1e0006);
    func_003E9270(0x1e0009, 0x706ec8ff, (D_L01_001D8D88 + D_L01_001D8D90), (D_L01_001D8D7C + (D_L01_001D8D84 + D_L01_001D8D84)), 0.0195300002f, 0.0408679992f, 0.00400000019f, 0.00499999989f);
    func_003E9270(0x1e0008, 0x332299de, (((D_L01_001D8D88 + D_L01_001D8D90) + D_L01_001D8D8C) * 0.5f), (D_L01_001D8D7C + (D_L01_001D8D84 + D_L01_001D8D84)), (D_L01_001D8D8C - (D_L01_001D8D88 + D_L01_001D8D90)), D_L01_001D8D94, 0.00400000019f, 0.00499999989f);
    func_003E9138(0x1e0007, 0x332299de, 0, ((D_L01_001D8D88 + D_L01_001D8D90) + 0.00400000019f), (D_L01_001D8D7C + (D_L01_001D8D84 + D_L01_001D8D84)), ((D_L01_001D8D8C - (D_L01_001D8D88 + D_L01_001D8D90)) - 0.00800000038f), (D_L01_001D8D94 - 0.00999999978f));
    func_L01_00516B90(0x1e0007, 1, 3);
    func_003E9270(0x1e000c, 0x706ec8ff, (D_L01_001D8D88 + D_L01_001D8D90), (D_L01_001D8D7C + (D_L01_001D8D84 * 3.0f)), 0.0195300002f, 0.0408679992f, 0.00400000019f, 0.00499999989f);
    func_003E9270(0x1e000b, 0x332299de, (((D_L01_001D8D88 + D_L01_001D8D90) + D_L01_001D8D8C) * 0.5f), (D_L01_001D8D7C + (D_L01_001D8D84 * 3.0f)), (D_L01_001D8D8C - (D_L01_001D8D88 + D_L01_001D8D90)), D_L01_001D8D94, 0.00400000019f, 0.00499999989f);
    func_003E9138(0x1e000a, 0x332299de, 0, ((D_L01_001D8D88 + D_L01_001D8D90) + 0.00400000019f), (D_L01_001D8D7C + (D_L01_001D8D84 * 3.0f)), ((D_L01_001D8D8C - (D_L01_001D8D88 + D_L01_001D8D90)) - 0.00800000038f), (D_L01_001D8D94 - 0.00999999978f));
    func_L01_005170B8(0x1e0008, 0x331465b7);
    func_L01_005170B8(0x1e0007, 0x60000000);
    func_L01_005170B8(0x1e000b, 0x331465b7);
    func_L01_005170B8(0x1e000a, 0x60000000);
    func_L01_00516B90(0x1e000a, 1, 3);
    func_003E8B98(0x1e0006, 0x1e0007, 0x1e0008, 0x1e000a, 0x1e0009, 0x1e000b, 0x1e000c);
    func_003E8A08(0x1e0000, 0x1e0006, 0x1e000d);
    func_L01_00490FC8();
    func_003E8710(0x1e0003, (s32)func_003B42F8(1));
    func_L01_00517190(0x1e0003, 0);
    func_L01_00516D60(0x1e0003, 0);
    func_003E87B8(0x1e0003, 1, 8);


}
