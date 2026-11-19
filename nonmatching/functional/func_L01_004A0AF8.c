/* functional: medium. 295 words differ at default flags (register/constant scheduling). Retail quirk reproduced: after the horizontal-align test fails for 1 and 2 it re-tests that value, not the vertical one, so vertical offset is skipped then. */
extern s32 D_L01_001D95F8[];
__asm__(".extern D_L01_001D95F8, 8");
extern s32 D_L01_002ED730[];
extern f32 D_L01_001DC0E8;
extern void func_L01_00516558(s32, void *, void *);
extern void func_L01_00516C78(s32, void *, void *);
extern void func_0038E150(s32);
extern s32 func_0038E548(char *, s32, f32);
extern s32 func_003E7AC8(s32, s32);
void func_L01_004A0AF8(s32 idx) {
    f32 rect[4];
    f32 pos[2];
    s32 align[2];
    f32 w, h, t, pad_w, pad_h, ph;
    s32 mode;
    s32 id;
    pos[0] = 0.0f;
    pos[1] = 0.0f;
    id = D_L01_001D95F8[idx];
    h = 0.0f;
    ph = 0.038463999f;
    if ((u32)(idx - 2) < 2) {
        rect[0] = rect[1] = rect[2] = rect[3] = 0.0f;
        func_L01_00516558(0x540012, &rect[0], &rect[1]);
        func_L01_00516558(0x540016, &rect[2], &rect[3]);
        align[0] = 3;
        align[1] = 3;
        func_0038E150(1);
        t = (f32)func_0038E548((char *)D_L01_00236B00.v[2][D_L01_002ED730[0]], -1, 1.0f) / D_L01_001DC0E8;
        w = (f32)func_0038E548((char *)D_L01_00236B00.v[3][D_L01_002ED730[0]], -1, 1.0f) / D_L01_001DC0E8;
        h = w;
        if (w < t) h = t;
        id = 0x540012;
        ph = 0.086543999f;
        pos[1] = (rect[1] + rect[3]) * 0.5f - 0.0024039999f;
        pos[0] = (rect[0] + rect[2]) * 0.5f;
        func_003E7AC8(0x540016, 0);
    } else {
        func_L01_00516558(id, &pos[0], &pos[1]);
        func_L01_00516C78(id, &align[0], &align[1]);
        func_0038E150(1);
        h = (f32)func_0038E548((char *)D_L01_00236B00.v[idx][D_L01_002ED730[0]], -1, 1.0f) / D_L01_001DC0E8;
    }
    {
        pad_w = 0.015623999f + 0.0080000004f + h;
        pad_h = ph + 0.01f;
        pos[1] -= 0.0024039999f;
        mode = align[0];
        if (mode == 1) {
            pos[0] += (pad_w - 0.0080000004f - 0.015623999f) * 0.5f;
            mode = align[1];
        } else if (mode == 2) {
            pos[0] -= (pad_w - 0.0080000004f - 0.015623999f) * 0.5f;
            mode = align[1];
        }
        if (mode == 1) {
            pos[1] += pad_h * 0.5f;
        } else if (mode == 2) {
            pos[1] -= pad_h * 0.5f;
        }
        func_003E7AC8(id, 0);
    }
    func_L01_00516470(id + 1, pos[0], pos[1]);
    func_L01_00517538(id + 1, pad_w, pad_h);
    func_L01_00516470(id + 2, pos[0], pos[1]);
    func_L01_00517538(id + 2, pad_w - 0.0080000004f, pad_h - 0.01f);
    func_L01_00516470(id + 3, pos[0] + 0.0019529999f * 4.0f, pos[1] + 0.0024039999f * 4.0f);
    func_L01_00517538(id + 3, pad_w, pad_h);
    func_L01_00516B90(id + 1, 3, 3);
    func_L01_00516B90(id + 2, 3, 3);
    func_L01_00516B90(id + 3, 3, 3);
}
