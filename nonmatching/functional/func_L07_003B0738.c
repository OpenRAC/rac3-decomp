/* functional: high. Written from PAL asm using the NTSC draft only as a shape guide; PAL differs: divisor 50.0 (not 60), lifetime is (rand(20,40)*5+2)/6 and the draft's raw rand was wrong. VU0 vadd.xyz as plain float adds. 62 diff = scheduling. */
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_00382498(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00474078(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);

void func_L07_003B0738(u8 *obj) {
    f32 w[4];
    f32 q[4];
    u8 *vars;
    f32 t, scale, ang;
    s32 n, s;

    vars = *(u8 **)(obj + 0x68);
    t = 1.0f - (f32) * (s32 *)(vars + 0xA0) / 50.0f;
    n = (s32)(t * 4.0f + 2.0f);
    scale = (t * 0.8f + 0.2f) * 12.0f;
    while (n > 0) {
        ang = func_0038DAB8(*(f32 *)(obj + 0xF8), func_003824E0(-0.7853982f, 0.7853982f));
        func_00382760(w, scale, ang, func_003824E0(-0.7853982f, 0.7853982f));
        func_003C2F58(obj, 1, q);
        if (*(s32 *)(vars + 0xA0) < (func_00382498(20, 40) * 5 + 2) / 6) {
            s = *(s32 *)(vars + 0xA0);
        } else {
            s = (func_00382498(20, 40) * 5 + 2) / 6;
        }
        q[0] = q[0] + w[0];
        q[1] = q[1] + w[1];
        q[2] = q[2] + w[2];
        n--;
        func_0038CE20(w, w, -1.0f / (f32)s);
        func_L01_00474078(q, w, s, 0.15f, 0.75f, 1.2f, 1.0f, 0x8020FF40, 0x40A0FFA0, 0, 0);
    }
}
