/* func_L01_0051E728 (byte twins: func_L01_0051F4B8, func_L01_005212A0, same fingerprint): ~123 diff,
   checked with check.py --as ps2as after adding divs_nops rows "2 2 0 0" for all three (the files have no
   C; they would get @ps2as for the inline float constants). The tail (func_003EDAF8 branch, memset, the
   min/max of the padded rect) and the position maths match. Left: retail keeps the redundant
   `hd = 2.0f` of the h != 1 path (mov.s $f23, $f22) and gives vd $f22 / hd $f23; gcc drops the copy and
   swaps the two registers, which shifts everything after it. Init order, chained inits, switch and
   copy-direction forms do not change it; px/py load order also differs (retail 0x24 first). */
typedef struct {
    f32 v[4];
} R_0051E728;
typedef struct {
    u8 pad0[0x10];
    f32 ax;
    f32 ay;
    f32 w;
    f32 h;
    f32 px;
    f32 py;
} W_0051E728;
extern void func_003EDB40(W_0051E728 *, s32 *, s32 *);
extern s32 func_003EDAF8(W_0051E728 *, s32);
extern void func_0011A264(void *buf, s32 c, s32 n);

void func_L01_0051E728(W_0051E728 *w, f32 *area, f32 *out, s32 align) {
    f32 hx;
    f32 hd;
    f32 vy;
    f32 vd;
    f32 x;
    f32 y;
    s32 h;
    s32 v;
    R_0051E728 r;

    hd = vd = 2.0f;
    hx = vy = 0.0f;
    if (align) {
        h = 0;
        v = 0;
        func_003EDB40(w, &h, &v);
        if (h != 3) {
            hx = 1.0f;
            if (h != 1) {
                hx = -1.0f;
                hd = 2.0f;
            }
        }
        if (v != 3) {
            if (v == 2) {
                vd = 2.0f;
                vy = -1.0f;
            } else {
                vd = 2.0f;
                vy = 1.0f;
            }
        }
    }
    x = (area[2] - area[0]) * w->ax + area[0];
    y = (area[3] - area[1]) * w->ay + area[1];
    out[0] = x - w->w / hd + hx * w->w / hd;
    out[1] = y - w->h / vd + vy * w->h / vd;
    out[2] = out[0] + w->w;
    out[3] = out[1] + w->h;
    if (func_003EDAF8(w, 0x40)) {
        f32 py = w->py;
        f32 px = w->px;

        func_0011A264(&r, 0, 0x10);
        r = *(R_0051E728 *)out;
        r.v[0] += px;
        r.v[2] += px;
        r.v[1] += py;
        r.v[3] += py;
        out[0] = r.v[0] < out[0] ? r.v[0] : out[0];
        out[2] = out[2] < r.v[2] ? r.v[2] : out[2];
        out[3] = out[3] < r.v[3] ? r.v[3] : out[3];
        out[1] = r.v[1] < out[1] ? r.v[1] : out[1];
    }
}
