/* functional: medium. Starship Phoenix light-beam/spotlight object update: state machine 1/2/3 (fade out, fade in + sparkle particles, held), proximity scale from distance+direction, rotates angle by 0.0523/frame. VU0 vsub done as plain float math; unrun blocks unverified (no gate yet). Not byte-exact. */
extern u8 *D_L03_001DFA80;
extern void func_L03_003A4FC8(void *);
extern void func_L03_003A51E0(vu0_v4 *, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 D_001A30B0[];
extern u8 D_L03_001E2440[];
extern u8 D_001A4C60[];
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00456250(void *);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern void func_L01_004048D0(void *, void *);
extern void func_L03_003A5388(void *);

void func_L03_003A4900(u8 *obj) {
    s32 *v = *(s32 **)(obj + 0x68);
    f32 scale;
    f32 d[4];
    f32 dist;
    f32 dot;
    f32 q[4];
    f32 w[4];
    s32 n;
    s32 h;
    s32 st;
    f32 r1;
    f32 r2;
    f32 ang;

    if (obj[0x20] == 0) {
        func_L03_003A4FC8(obj);
    }
    if (obj[0x95] == 0) {
        return;
    }
    scale = 0.0f;
    st = obj[0x20];
    if (st != 1) {
        f32 *o = (f32 *)(obj + 0x10);
        f32 *e = (f32 *)D_L03_001E2440;
        d[0] = o[0] - e[0];
        d[1] = o[1] - e[1];
        d[2] = o[2] - e[2];
        d[3] = o[3];
        dist = func_L01_0040E548(obj + 0x10, D_001A4C60);
        if (dist < 2304.0f) {
            dot = e[0x20 / 4] * d[0] + e[0x24 / 4] * d[1];
            if (0.0f < dot) {
                scale = 1.0f - (dist - 576.0f) / 1728.0f;
                if (1.0f < scale) {
                    scale = 1.0f;
                } else if (scale < 0.0f) {
                    scale = 0.0f;
                }
            }
        }
        st = obj[0x20];
    }
    if (st == 2) {
        if (func_L01_004561B8(obj) != 0) {
            func_L01_00456230(obj, 0);
        }
        if (((u8 *)v)[0x1F] == 0) {
            h = v[5];
            if (h == -1 || *(u8 **)(D_001A30B0 + (h << 7) + 0xDC) != obj) {
                v[5] = func_003A52A0(1, 4, obj);
            }
        }
        ((f32 *)v)[1] = ((f32 *)v)[1] + 0.05f;
        if (1.0f < ((f32 *)v)[1]) {
            ((f32 *)v)[1] = 1.0f;
        }
        v[2] = v[6];
        if (func_L01_00456250(obj) != 0) {
            v[3] = 1;
        }
        if (v[3] > 0) {
            func_L01_004450F0(obj, 1, -1);
        }
        if (((u8 *)v)[0x1F] == 0) {
            n = (s32)(scale * 10.0f);
            while (n > 0) {
                n--;
                func_L03_003A51E0((vu0_v4 *)q, v[0]);
                *(vu0_q *)w = *(vu0_q *)(D_L03_001DFA80 + (v[0] << 7) + 0x30);
                w[0] -= q[0];
                w[1] -= q[1];
                w[2] -= q[2];
                r1 = func_003824E0(0.0f, 0.2f);
                r2 = func_003824E0(0.0f, 0.1f);
                func_0038CE20(w, w, r1 * r2);
                r1 = func_003824E0(0.5f, 1.0f);
                func_L01_0046B458(q, 0x28, 0.1f, r1, 0x80802020, 0, func_00382498(-10, 10), w, 0.0f, 0);
            }
        }
    } else if (st < 3) {
        if (st == 1) {
            if (func_L01_004561B8(obj) != 0) {
                h = v[5];
                if (h >= 0 && *(u8 **)(D_001A30B0 + (h << 7) + 0xDC) == obj) {
                    func_003A4F28(h);
                }
                v[5] = -1;
                func_L01_00456230(obj, 1);
            }
            ((f32 *)v)[1] = ((f32 *)v)[1] - 0.1f;
            if (((f32 *)v)[1] < 0.0f) {
                ((f32 *)v)[1] = 0.0f;
            }
            v[2] = 0;
            if (func_L01_00456250(obj) == 0) {
                v[3] = 0;
            }
            if (v[3] == 0) {
                func_L01_004450F0(obj, 3, -1);
            }
        }
    } else if (st == 3) {
        if (func_L01_004561B8(obj) != 0) {
            h = v[5];
            if (h >= 0) {
                if (*(u8 **)(D_001A30B0 + (h << 7) + 0xDC) == obj && D_001A30B0[(h << 7) + 0xD0] != 0) {
                    func_003A4F28(h);
                }
                v[5] = -1;
            }
            if (((u8 *)v)[0x1F] == 0) {
                v[5] = func_003A52A0(0, 0, obj);
            }
        }
        v[2] = v[2] + 1;
        ((f32 *)v)[1] = 0.0f;
        if (!(v[2] < v[6])) {
            v[5] = -1;
            func_L01_004450F0(obj, 2, -1);
        }
        if (v[3] > 0) {
            h = v[5];
            if (h >= 0) {
                if (*(u8 **)(D_001A30B0 + (h << 7) + 0xDC) == obj && D_001A30B0[(h << 7) + 0xD0] != 0) {
                    func_003A4F28(h);
                }
                v[5] = -1;
            }
            func_L01_004450F0(obj, 1, -1);
        }
        if (((u8 *)v)[0x1F] == 0) {
            dot = (f32)(v[2] * 10) * 0.5f;
            r1 = 3.0f;
            if (v[6] != 0) {
                r1 = (f32)v[6];
            }
            n = (s32)(scale * (dot / r1));
            while (n > 0) {
                n--;
                func_L03_003A51E0((vu0_v4 *)q, v[0]);
                w[0] = 0.0f;
                w[1] = 0.0f;
                w[2] = 0.0f;
                w[3] = 0.0f;
                h = func_00382498(20, 30);
                r1 = func_003824E0(0.3f, 0.8f);
                func_L01_0046B458(q, h, 0.08f, r1, 0x60804040, 0, func_00382498(-6, 6), w, 0.0f, 0);
            }
        }
    }
    ang = ((f32 *)v)[4] + 0.05235988f;
    ((f32 *)v)[4] = ang;
    if (3.1415927f <= ang) {
        ((f32 *)v)[4] = ang - 6.2831855f;
    }
    if (0.0f < ((f32 *)v)[1]) {
        if (((u8 *)v)[0x1F] == 0) {
            func_L01_004048D0(func_L03_003A5388, obj);
        }
        *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
    } else {
        *(s32 *)(obj + 0x98) = 0;
    }
}
