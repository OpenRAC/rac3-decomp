/* functional: high. 125 diff at default flags, mostly register scheduling; the early part (frame, loop) is identical. Layout struct passed to func_003B9C68 is the same 0x54-byte config as in func_L01_004A1F78. */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 a24[4];
    f32 a34[4];
    f32 a44[4];
} S_L01_004A2BE0;
extern s32 D_L01_001D96C0;
extern s32 D_L01_001D96EC;
extern f32 D_L01_001D9714;
extern f32 D_L01_001D9718;
extern char D_L01_001D9720[];
extern u16 D_001A8EC8[];
extern s32 D_001D55E8;
__asm__(".extern D_L01_001D96C0, 4");
__asm__(".extern D_L01_001D96EC, 4");
__asm__(".extern D_L01_001D9714, 4");
__asm__(".extern D_L01_001D9718, 4");
extern void func_11A264(void *, s32, s32);
extern void func_11B2E8();
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C68();
extern void func_003BABB0(void *, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern void func_L01_00498F18(void *, s32, s32);
extern void func_0038E150(s32);
extern s32 func_003B9E30(void *, s32, s32);
extern void func_L01_004A32E0(s32, void *, f32, f32);
void func_L01_004A2BE0(void) {
    u8 buf[0x40];
    S_L01_004A2BE0 s;
    s32 i;
    s32 saved;
    func_11A264(buf, 0, 0x40);
    D_L01_001D96C0 = 0;
    for (i = 0; i < 0x190; i++) {
        if (D_001A8EC8[i] != 0) {
            D_L01_001D96C0++;
        }
    }
    if (D_L01_001D96C0 == 0) {
        return;
    }
    s.f0 = 0x4F000;
    s.f4 = D_L01_001D96EC;
    s.f8 = 0x14;
    s.fC = D_L01_001D96C0;
    s.f10 = (D_L01_001D96C0 < 7) ? D_L01_001D96C0 : 6;
    s.f14 = 1;
    s.f18 = 1.0f;
    s.f1C = D_L01_001D9714;
    s.f20 = D_L01_001D9718;
    s.a24[0] = 0.5f;
    s.a24[1] = 1.0f;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = 0.79520601f;
    s.a34[1] = 0.0f;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_003B9C68(func_003B9BD0(0), &s);
    func_003BABB0(func_003B9BD0(0), 0.5f, 0.816536009f, 0.0450000018f, 0.0425000004f, 0.349999994f, 0);
    func_003BABD0(func_003B9BD0(0), 0.500369012f, 0.700703025f, 0.816536009f, 0.312705994f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.0264999997f, 0.00665999996f, 0.0299999993f);
    func_L01_00498F18(func_003B9BD0(0), 0, 1);
    saved = D_001D55E8;
    func_0038E150(1);
    for (i = 0; i < D_L01_001D96C0; i++) {
        func_L01_004A32E0(D_001A8EC8[i], buf, s.f18, s.a34[0] - 0.00999999978f);
        func_11B2E8(func_003B9E30(func_003B9BD0(0), 0, D_L01_001D96C0 - i - 1), D_L01_001D9720, buf);
    }
    func_0038E150(saved);
}
