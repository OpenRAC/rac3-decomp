/* functional: medium. Rewritten from PAL asm; NTSC draft used only as a structural hint. */
/* localdecomp:start func_L01_004C1838 */
extern S_00244740 D_L01_002446C0[];
extern s32 D_L01_001E0F60[];
extern s32 D_L01_001E0F50[];
extern f32 D_L01_001E0F54[];
extern f32 D_L01_001E0F5C[];
extern f32 D_L01_001E0F68[];
extern f32 D_L01_001E0F6C[];
extern s32 D_L01_001E0F38[];
extern s32 D_L01_001E0F3C[];
extern s32 D_L01_001E0F40[];
extern s32 D_L01_001E0F44[];
extern s32 D_L01_001E0F48[];
extern s32 D_L01_001E0F4C[];
extern s32 D_L01_001E0F58[];
extern s32 D_L01_001E0F70[];
extern s32 D_L01_001E0F74[];
extern u8 *D_001D52FC_sda;
__asm__(".extern D_L01_001E0F60, 16");
__asm__(".extern D_L01_001E0F50, 16");
__asm__(".extern D_L01_001E0F54, 16");
__asm__(".extern D_L01_001E0F5C, 16");
__asm__(".extern D_L01_001E0F68, 16");
__asm__(".extern D_L01_001E0F6C, 16");
__asm__(".extern D_L01_001E0F38, 16");
__asm__(".extern D_L01_001E0F3C, 16");
__asm__(".extern D_L01_001E0F40, 16");
__asm__(".extern D_L01_001E0F44, 16");
__asm__(".extern D_L01_001E0F48, 16");
__asm__(".extern D_L01_001E0F4C, 16");
__asm__(".extern D_L01_001E0F58, 16");
__asm__(".extern D_L01_001E0F70, 16");
__asm__(".extern D_L01_001E0F74, 16");
extern s32 *func_003B9BD0(s32);
extern void func_L01_004991B8(s32 *, s32);
extern void func_L01_00516D60(s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern char *func_00381FF0(s32);
extern void func_L01_00516FD8(s32, char *);

s32 func_L01_004C1838(void) {
    u8 *u = (u8 *)D_L01_002446C0;
    s32 result = 0;
    s32 full, visible;
    f32 w, h, a, pad;

    switch (D_L01_001E0F60[0]) {
    case 1:
        func_L01_004991B8(func_003B9BD0(0), 0);
        break;
    case 2:
        *(s32 *)(u + 0x90) = 0;
        func_L01_004991B8(func_003B9BD0(0), 1);
        D_L01_001E0F54[0] = D_L01_001E0F54[0] + 0.14000002f;
        D_L01_001E0F50[0] = 1;
        if (1.0f < D_L01_001E0F54[0]) D_L01_001E0F54[0] = 1.0f;
        else if (D_L01_001E0F54[0] < 0.0f) D_L01_001E0F54[0] = 0.0f;
        if (D_L01_001E0F54[0] == 1.0f) D_L01_001E0F60[0] = 3;
        break;
    case 3:
        *(s32 *)(u + 0x90) = 0;
        func_L01_004991B8(func_003B9BD0(0), 1);
        result = *(s32 *)(D_001D52FC_sda + 0x1A4) & D_L01_001E0F70[0];
        if (result != 0) D_L01_001E0F60[0] = 4;
        break;
    case 4:
        *(s32 *)(u + 0x90) = 0;
        func_L01_004991B8(func_003B9BD0(0), 1);
        D_L01_001E0F54[0] = D_L01_001E0F54[0] - 0.14000002f;
        D_L01_001E0F50[0] = -1;
        if (1.0f < D_L01_001E0F54[0]) D_L01_001E0F54[0] = 1.0f;
        else if (D_L01_001E0F54[0] < 0.0f) D_L01_001E0F54[0] = 0.0f;
        if (D_L01_001E0F54[0] == 0.0f) {
            D_L01_001E0F60[0] = 1;
            *(s32 *)(u + 0x90) = 0x80;
        }
        break;
    default:
        break;
    }
    full = (1.0f <= D_L01_001E0F54[0]);
    visible = (0.0f < D_L01_001E0F54[0]);
    func_L01_00516D60(D_L01_001E0F38[0], full);
    func_L01_00516D60(D_L01_001E0F3C[0], full & D_L01_001E0F74[0]);
    func_L01_00516D60(D_L01_001E0F40[0], visible);
    func_L01_00516D60(D_L01_001E0F44[0], visible);
    func_L01_00516D60(D_L01_001E0F48[0], visible);
    func_L01_00516D60(D_L01_001E0F4C[0], visible);
    w = D_L01_001E0F68[0];
    h = D_L01_001E0F6C[0];
    a = D_L01_001E0F54[0];
    pad = D_L01_001E0F5C[0];
    if (full) {
        func_L01_00516470(D_L01_001E0F38[0], 0.5f, 0.29000002f - (f32)D_L01_001E0F74[0] * 0.03f);
        func_L01_00517538(D_L01_001E0F38[0], w, h);
        func_L01_00516FD8(D_L01_001E0F38[0], func_00381FF0(D_L01_001E0F58[0]));
        func_L01_00516470(D_L01_001E0F3C[0], 0.5f, h * 0.5f + 0.3f - 0.02f);
    }
    if (visible) {
        func_L01_00516470(D_L01_001E0F40[0], 0.5f, 0.3f);
        h = (h + pad) * a;
        w = (w + pad) * a;
        func_L01_00517538(D_L01_001E0F40[0], w, h);
        func_L01_00516470(D_L01_001E0F44[0], 0.5f, 0.3f);
        func_L01_00517538(D_L01_001E0F44[0], w, h);
        func_L01_00516470(D_L01_001E0F48[0], 0.5f, 0.3f);
        func_L01_00517538(D_L01_001E0F48[0], w + 0.015f, h + 0.015f);
    }
    return result;
}
/* localdecomp:end func_L01_004C1838 */
