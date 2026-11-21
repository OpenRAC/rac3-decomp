/* functional: high. Written from asm (no draft). gp offsets resolved with gp=0x1DC8B0 (D_001D9688/968C=1.0, 9690/9694=0, 9698=512.0, 96A0 set to 512 only for mode 0 or 1, 969C/96A4 = 416.0 (mode 0) or 448.0 (mode 1), unchanged for other modes), then func_003E7620 (computes the ratios), func_00391068(&x,&y,1) and the outputs D_001D96B0=x*14/13/ D_001D969C, D_001D96B4=(y+x/2)*14/13/D_001D969C (constant 0x3F89D89E). 38 words differ (branch layout, store order). */
extern f32 D_001D9688;
extern f32 D_001D968C;
extern s32 D_001D9690;
extern s32 D_001D9694;
extern f32 D_001D969C;
extern f32 D_001D9698;
extern f32 D_001D96A0;
extern f32 D_001D96A4;
extern f32 D_001D96B0;
extern f32 D_001D96B4;
extern void func_003E7620(void);
extern void func_00391068(f32 *, f32 *, s32);
void func_003E7670(s32 mode) {
    f32 v[2];
    f32 w;
    D_001D968C = 1.0f;
    D_001D9688 = 1.0f;
    D_001D9690 = 0;
    D_001D9694 = 0;
    D_001D9698 = 512.0f;
    if (mode == 0) {
        D_001D96A0 = 512.0f;
        w = 416.0f;
        D_001D96A4 = w;
        D_001D969C = w;
    } else if (mode == 1) {
        D_001D96A0 = 512.0f;
        w = 448.0f;
        D_001D96A4 = w;
        D_001D969C = w;
    }
    func_003E7620();
    v[0] = 0.0f;
    v[1] = 0.0f;
    func_00391068(&v[0], &v[1], 1);
    D_001D96B0 = (v[0] * 1.0769231f) / D_001D969C;
    D_001D96B4 = ((v[1] + v[0] * 0.5f) * 1.0769231f) / D_001D969C;
}
