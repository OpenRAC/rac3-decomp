/* functional: high. plain C for the 3 VU0 vector ops (file lacks -mvu0-use-vf0-vf2 so vu0.h helpers do not compile); vadd.xyz keeps w so only xyz added; not byte-exact */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00423C48;
extern u8 D_L01_001E29E0[];
extern void func_0038D000(void *, void *, void *);
extern void func_003C4C18(f32 *, f32);
extern f32 func_003824E0(f32, f32);
extern void *func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);

/* spawn a burst effect at *a0 (rotated by the matrix), jittered by a random vector of size a1 */
void func_L01_00423C48(V4_00423C48 *a0, f32 a1, f32 a2, f32 a3) {
    V4_00423C48 v;
    V4_00423C48 z;
    V4_00423C48 w;
    void *r;

    v = *a0;
    z.x = 0.0f; z.y = 0.0f; z.z = 0.0f; z.w = 0.0f;
    func_0038D000(&v, &v, D_L01_001E29E0);
    func_003C4C18(&z.x, a1);
    w = *(V4_00423C48 *)(D_L01_001E29E0 - 0x20);
    z.z = a2 * z.z;
    z.x += v.x; z.y += v.y; z.z += v.z;
    z.x = w.x + z.x; z.y = w.y + z.y; z.z = w.z + z.z;
    r = func_L01_003303B8(&z, 0, 25, 20, 20, 20, 45, 2, a3 * func_003824E0(0.2f, 0.4f), 0.0f, 0.0f, 2.0f,
                          1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    if (r != 0) {
        func_L01_004AAC98(0, 0, r, 0x1F7B);
    }
}
