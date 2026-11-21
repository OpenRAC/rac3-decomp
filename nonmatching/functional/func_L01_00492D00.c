/* functional: high. Byte-identical assembly twin of func_L01_004903F0 (diffed with addresses normalised, jump table 002BA7D0): same C, renamed */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    s32 w20;
    s32 w24;
    f32 f28;
    u32 w2C;
} S_00492D00;

extern s32 func_00381FF0(s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E90B8(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00518D40_00492D00(s32);
extern void func_L01_00518590(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00516818(s32, f32);
extern void func_L01_00516728(s32, f32, f32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00518670(s32, s32, s32);
extern void func_L01_00516B90(s32, s32, s32);

void func_L01_00492D00(S_00492D00 *e) {
    s32 i = 0;
    s32 mx = 3;
    s32 my = 3;
    S_00492D00 *q;
    s32 r, v;
    f32 t;

    if (e->w0 == 0) return;
    do {
        q = &e[i];
        switch (q->w8) {
        case 0:
            func_L01_00518D40_00492D00(q->w0);
            if (q->w2C & 1) {
                func_L01_00518590(q->w0, 1, 1);
                func_L01_00516470(q->w0, q->f10, q->f14);
                func_L01_00517538(q->w0, q->f18, q->f1C);
            }
            break;
        case 1:
            func_003E8EF0(q->w0, q->w24, q->wC, q->f10, q->f14, q->f18, q->f1C, 0.0f);
            break;
        case 2:
            func_003E9138(q->w0, q->wC, q->f10, q->f14, q->f18, q->f1C, q->w24);
            break;
        case 3:
            func_003E9270(q->w0, q->wC, q->f10, q->f14, q->f18, q->f1C, q->f28, q->f28);
            break;
        case 4:
            r = q->w24;
            if (q->w2C & 4) r = func_00381FF0(q->w24);
            func_003E90B8(q->w0, r, q->wC, q->f10, q->f14, q->f18, q->f1C, 0.005f, 0.005f);
            break;
        case 5:
            r = q->w24;
            if (q->w2C & 4) r = func_00381FF0(q->w24);
            func_003E9358(q->w0, r, q->wC, q->f10, q->f14, q->f18, q->f1C, 1.0f);
            func_L01_00516818(q->w0, q->f28);
            t = q->f28 * 0.005f;
            func_L01_00516728(q->w0, t, t);
            func_L01_00516AA0(q->w0, 0x40, 1);
            if (q->w2C & 8) func_L01_00518670(q->w0, 1, 1);
            break;
        }
        v = q->w20;
        if (v != 0) {
            if (v & 1) mx = 1;
            else if (v & 2) mx = 2;
            if (v & 8) my = 1;
            else if (v & 0x10) my = 2;
            func_L01_00516B90(q->w0, mx, my);
        }
        if (q->w2C & 2) func_L01_00516AA0(q->w0, 1, 0);
        if (q->w4 != 0) func_003E8630(q->w4, q->w0);
        i++;
    } while (e[i].w0 != 0);
}
