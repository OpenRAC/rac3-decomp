/* functional: medium. 568 diff but same length (578 vs 577 insns), 0x70 vs 0x60 frame; every constant, loop bound and clamp direction read against asm; no gate coverage; callee meanings inferred */
typedef struct { u8 pad[0xB0]; f32 fieldOfView; } Screen_00421A30;
extern s32 D_L01_002E5F30[];
extern u8 *D_L01_001D67C8;
extern Screen_00421A30 D_L01_001E7580;
extern f32 D_L01_001E11A4;
extern s32 D_L01_001D6A08;
extern s32 D_L01_001D6A0C;
extern f32 D_L01_001D6A10;
extern s32 D_L01_001D6A14;
extern s32 D_L01_001D6A18;
__asm__(".extern D_L01_001D67C8, 4");
__asm__(".extern D_L01_001D6A08, 4");
__asm__(".extern D_L01_001D6A0C, 4");
__asm__(".extern D_L01_001D6A10, 4");
__asm__(".extern D_L01_001D6A14, 4");
__asm__(".extern D_L01_001D6A18, 4");
extern void func_003873C0(void);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_003ABDD8(u8 *, s32);
extern void func_003AA320(s32, s32, f32, f32, f32, f32, f32);
extern void func_0038AF30(s32, s32, s32, s32, s32);

/* screen-transition wipe (nested bands / bars drawn with func_0038AF30 and the two HUD sprites
   func_003AA320); style D_L01_001D6A0C, progress D_L01_001D6A10, colours D_L01_001D6A14/18 */
void func_L01_00421A30(void) {
    f32 prev;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 t;
    f32 fa;
    f32 fb;
    s32 col0;
    s32 col1;
    s32 ia;
    s32 i;
    s32 h;

    if (D_L01_001D67C8 == 0) {
        return;
    }
    if (D_L01_002E5F30[0] != 0) {
        return;
    }
    if (D_L01_002E5F30[9] != -1) {
        return;
    }
    prev = D_L01_001E7580.fieldOfView;
    D_L01_001E7580.fieldOfView = 0.62f;
    func_003873C0();
    t = (f32)D_L01_001D6A08 * 0.1f;
    col0 = func_0038DBD8(0x1465B7, 0x331465B7, t);
    col1 = func_0038DBD8(0x2299DE, 0x332299DE, t);
    if (D_L01_001D6A0C == 3) {
        h = func_003ABDD8(D_L01_001D67C8 + 0x7090, 0x10);
        func_003AA320(h, col0, 484.0f, (f32)(s32)(D_L01_001E11A4 * 174.0f + 0.5f + 0.0f), 1.0f, 1.0f, 0.0f);
        h = func_003ABDD8(D_L01_001D67C8 + 0x7090, 0x11);
        func_003AA320(h, col1, 484.0f, (f32)(s32)(D_L01_001E11A4 * 174.0f + 0.5f + 0.0f), 1.0f, 1.0f, 0.0f);
    } else {
        h = func_003ABDD8(D_L01_001D67C8 + 0x7090, 0x10);
        func_003AA320(h, col0, 484.0f, (f32)(s32)(D_L01_001E11A4 * 206.0f + 0.5f + 0.0f), 1.0f, 1.0f, 0.0f);
        h = func_003ABDD8(D_L01_001D67C8 + 0x7090, 0x11);
        func_003AA320(h, col1, 484.0f, (f32)(s32)(D_L01_001E11A4 * 206.0f + 0.5f + 0.0f), 1.0f, 1.0f, 0.0f);
    }
    if (D_L01_001D6A0C < 3) {
        if (D_L01_001D6A0C > 0) {
            /* styles 1 and 2 */
            col0 = func_0038DBD8(D_L01_001D6A14 & 0xFFFFFF, D_L01_001D6A14, t);
            ia = (s32)(((f32)(0x11D - (s32)((1.0f - D_L01_001D6A10) * 157.0f)) * D_L01_001E11A4) + 0.5f + 0.0f);
            d = (f32)(s32)(D_L01_001E11A4 * 128.0f + 0.5f + 0.0f) * 0.25f;
            b = (f32)(s32)(D_L01_001E11A4 * 285.0f + 0.5f + 0.0f);
            a = b - d + 1.0f;
            for (i = 0; i < 5; ) {
                c = (f32)ia;
                if (a <= c) {
                    a = c;
                }
                func_0038AF30((s32)a, (s32)b, 0x1DC, 0x1E8, col0);
                b -= d;
                a -= d;
                i++;
                if (!(b > c)) {
                    break;
                }
            }
        } else if (D_L01_001D6A0C == 0) {
            if (0.0f <= D_L01_001D6A10) {
                if (D_L01_001D6A10 <= 1.0f) {
                    col0 = func_0038DBD8(D_L01_001D6A14 & 0xFFFFFF, D_L01_001D6A14, t);
                    col1 = func_0038DBD8(D_L01_001D6A18 & 0xFFFFFF, D_L01_001D6A18, t);
                    ia = (s32)(((f32)(0x11D - (s32)((1.0f - D_L01_001D6A10) * 157.0f)) * D_L01_001E11A4) + 0.5f + 0.0f);
                    d = (f32)(s32)(D_L01_001E11A4 * 128.0f + 0.5f + 0.0f) * 0.25f;
                    b = (f32)(s32)(D_L01_001E11A4 * 285.0f + 0.5f + 0.0f);
                    a = b - d + 1.0f;
                    for (i = 0; i < 5; ) {
                        c = (f32)ia;
                        if (a <= c) {
                            a = c;
                        }
                        func_0038AF30((s32)a, (s32)b, 0x1DD, 0x1E9, col0);
                        b -= d;
                        a -= d;
                        i++;
                        if (!(b > c)) {
                            break;
                        }
                    }
                    a = (f32)(s32)(D_L01_001E11A4 * 128.0f + 0.5f + 0.0f);
                    b = a + d - 1.0f;
                    for (i = 0; i < 5; i++) {
                        c = (f32)ia;
                        if (c <= b) {
                            b = c;
                        }
                        func_0038AF30((s32)a, (s32)b, 0x1DC, 0x1E8, col1);
                        a += d;
                        b += d;
                        if (c <= a) {
                            break;
                        }
                    }
                }
            }
        }
    } else if (D_L01_001D6A0C == 3) {
        col0 = func_0038DBD8(D_L01_001D6A14 & 0xFFFFFF, D_L01_001D6A14, t);
        fa = (f32)(s32)(D_L01_001E11A4 * 255.0f + 0.5f + 0.0f);
        fb = (f32)(s32)((255.0f - (1.0f - D_L01_001D6A10) * 157.0f) * D_L01_001E11A4 + 0.5f + 0.0f);
        d = (f32)(s32)(D_L01_001E11A4 * 96.0f + 0.5f + 0.0f) * 0.2f;
        a = fa - d + 1.0f;
        for (i = 0; i < 10; i++) {
            if (a <= fb) {
                a = fb;
            }
            func_0038AF30((s32)a, (s32)fa, 0x1DD, 0x1E9, col0);
            a -= d;
            fa -= d;
            if (fa <= fb) {
                break;
            }
        }
    }
    D_L01_001E7580.fieldOfView = prev;
    func_003873C0();
}
