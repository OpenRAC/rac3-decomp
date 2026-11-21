/* functional: high. Compiles; the retail unit evidently uses -fopt-stack (sd saves, 0x160 frame) while the file entry lacks it, so the diff is register/frame only; logic read block by block against the asm. */
/* localdecomp:start func_L39_006025F0 */
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern s32 D_L39_00241470;
extern f32 D_L39_00241150[] __attribute__((section(".sdata")));
extern void func_0011D534(void *, s32, s32);
extern void func_0038E150(s32);
extern s32 func_L01_00412750(u8 *, s32);
extern s32 func_L01_00412708(u8 *, s32);
extern s32 func_L01_00447470(u8 *, s32, f32);

void func_L39_006025F0(u8 *self, s32 mode, f32 x, f32 y, s32 a4) {
    u8 buf[256];
    s32 saved;
    s32 w = 1;
    s32 idx = 0;
    s32 cnt = 0;
    s32 nobreak = 1;
    s32 n;
    s32 k;
    u8 *p;
    u8 *q;

    (*(f32 **)self)[0] = x;
    (*(f32 **)self)[1] = y;
    *(s32 *)(self + 0x198) = a4;
    *(s32 *)(self + 0x1A4) = mode;
    self[0x187] = 0;
    *(s32 *)(self + 0x190) = 1;
    *(s32 *)(self + 0x1B4) = 0;
    func_0011D534(buf, 0, 0x100);
    func_0011D534(self + 0x1B8, 0, 0x78);
    saved = D_L39_00241470;
    *(u8 **)(self + 0x1B8 + (*(s32 *)(self + 0x190) - 1) * 4) = self + 0x88;
    func_0038E150(1);
    p = self + 0x88;
    if (*p != 0) {
        q = self + 0x89;
        do {
            u8 c = *p;
            if (c == 1) {
                *p = 0;
                buf[idx] = 0;
                nobreak = 0;
                n = *(s32 *)(self + 0x190);
                *(u8 **)(self + 0x1B8 + n * 4) = q;
                *(s32 *)(self + 0x190) = n + 1;
                if (mode == 1) {
                    k = *D_L39_00241120;
                    if (k >= 2) {
                        w = func_L01_00447470(buf, -1, D_L39_00241150[k - 1] / D_L39_00241150[0]);
                    } else {
                        w = func_L01_00412708(buf, -1);
                    }
                } else if (mode == 0) {
                    w = func_L01_00412750(buf, -1);
                }
                idx = 0;
                if (*(s32 *)(self + 0x1B4) < w) {
                    *(s32 *)(self + 0x1B4) = w;
                }
            } else {
                buf[idx] = c;
                idx++;
            }
            cnt++;
            q++;
            if (cnt >= 0xFF) {
                break;
            }
            p++;
        } while (*p != 0);
    }
    if (nobreak != 0) {
        if (mode == 1) {
            k = *D_L39_00241120;
            if (k >= 2) {
                *(s32 *)(self + 0x1B4) = func_L01_00447470(buf, -1, D_L39_00241150[k - 1] / D_L39_00241150[0]);
            } else {
                *(s32 *)(self + 0x1B4) = func_L01_00412708(buf, -1);
            }
        } else if (mode == 0) {
            *(s32 *)(self + 0x1B4) = func_L01_00412750(buf, -1);
        }
    } else {
        if (mode == 1) {
            k = *D_L39_00241120;
            if (k >= 2) {
                w = func_L01_00447470(buf, -1, D_L39_00241150[k - 1] / D_L39_00241150[0]);
            } else {
                w = func_L01_00412708(buf, -1);
            }
        } else if (mode == 0) {
            w = func_L01_00412750(buf, -1);
        }
        if (*(s32 *)(self + 0x1B4) < w) {
            *(s32 *)(self + 0x1B4) = w;
        }
    }
    func_0038E150(saved);
    (*(f32 **)(self + 4))[0] = 1.0f;
}
/* localdecomp:end func_L39_006025F0 */
