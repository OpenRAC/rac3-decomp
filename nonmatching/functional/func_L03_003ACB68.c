/* functional: medium. Player-input driven (stick/buttons) object update: steps v[1] angle index +-4/+-16 with wrap, requests/holds a handle (func_003A52A0 / func_003A4F28), writes t[0]=(v1-0x20)/4*45 degrees and t[2]=sel. goto-structured to mirror the asm; w/ gp floats D_001DE608/60C. Not byte-exact. */
extern u8 D_001A30B0[];
extern u8 *D_001D52FC;
extern f32 D_001DE608;
extern f32 D_001DE60C;
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern void func_L01_004606A8(void *);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern u8 *func_L03_003B8DF8(u8 *, s32, f32);
extern u8 *func_L03_003B9688(u8 *, s32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);

void func_L03_003ACB68(u8 *obj) {
    s32 *v = *(s32 **)(obj + 0x68);
    u8 *p;
    s32 *t;
    s32 h;
    s32 cur;
    s32 nv;
    s32 a;
    s32 sel;
    s32 m;
    f32 x;

    if (func_L01_004606E8(0x60, 0x3C, 0, 0) != 0) {
        func_L01_004AAC98(3, 0, (void *)v[0], 0x1AE0);
        func_L03_003B8DF8(obj, v[1], D_001DE608);
        func_L01_004606A8(D_001D52FC);
    } else if (func_L01_004606E8(0x80, 0x3C, 0, 0) != 0) {
        func_L01_004AAC98(5, 0, (void *)v[0], 0x1AE0);
        func_L03_003B9688(obj, v[1], D_001DE60C);
        func_L01_004606A8(D_001D52FC);
    }
    p = D_001D52FC;
    t = *(s32 **)((u8 *)v[0] + 0x68);
    x = *(f32 *)(p + 0x148);
    /* a: argument of the handle request, sel: value for t[2], dir: +1 up / -1 down, step */
    if (*(s32 *)(p + 0x1D8) != 0) {
        if (x < -0.7f) {
            a = 0; sel = 1; goto up4;
        } else if (0.7f < x) {
            a = 1; sel = 0; goto down4;
        }
        return;
    } else {
        s32 bits = *(s32 *)(p + 0x1A0);
        if (bits & 0x2000) {
            a = 1; sel = 0; goto down4;
        } else if (bits & 0x8000) {
            a = 0; sel = 1; goto up4;
        } else if (bits & 8) {
            a = 1; sel = 2;
            h = v[6];
            if (h == -1 || *(u8 **)(D_001A30B0 + (h << 7) + 0xDC) != obj || D_001A30B0[(h << 7) + 0xD0] == 0) {
                v[6] = func_003A52A0(a, 4, obj);
            }
            cur = v[1];
            nv = cur - 0x10;
            v[1] = nv;
            if (nv < 0x20) {
                v[1] = cur + 0x10;
            }
            goto finish;
        } else if (bits & 4) {
            a = 0; sel = 3;
            h = v[6];
            if (h == -1 || *(u8 **)(D_001A30B0 + (h << 7) + 0xDC) != obj || D_001A30B0[(h << 7) + 0xD0] == 0) {
                v[6] = func_003A52A0(a, 4, obj);
            }
            cur = v[1];
            nv = cur + 0x10;
            v[1] = nv;
            if (!(nv < 0x40)) {
                v[1] = cur - 0x10;
            }
            goto finish;
        } else {
            if (v[6] >= 0x34) {
                v[6] = -1;
            }
            h = v[6];
            if (h != -1 && *(u8 **)(D_001A30B0 + (h << 7) + 0xDC) == obj && D_001A30B0[(h << 7) + 0xD0] != 0) {
                func_003A4F28(h);
            }
            v[6] = -1;
            return;
        }
    }
up4:
    h = v[6];
    if (h == -1 || *(u8 **)(D_001A30B0 + (h << 7) + 0xDC) != obj || D_001A30B0[(h << 7) + 0xD0] == 0) {
        v[6] = func_003A52A0(a, 4, obj);
    }
    cur = v[1];
    nv = cur + 4;
    v[1] = nv;
    if (!(nv < 0x40)) {
        v[1] = cur - 0x1C;
    }
    goto finish;
down4:
    h = v[6];
    if (h == -1 || *(u8 **)(D_001A30B0 + (h << 7) + 0xDC) != obj || D_001A30B0[(h << 7) + 0xD0] == 0) {
        v[6] = func_003A52A0(a, 4, obj);
    }
    cur = v[1];
    nv = cur - 4;
    v[1] = nv;
    if (nv < 0x20) {
        v[1] = cur + 0x1C;
    }
finish:
    t[2] = sel;
    m = (v[1] - 0x20) / 4;
    ((f32 *)t)[0] = (f32)(m * 0x2D);
}
