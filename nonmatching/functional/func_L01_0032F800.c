/* functional: high. Same calls/args in the same order as retail; trailing xyz add into a stack local is dead in retail (kept, never read); only scheduling differs. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_32F800;
extern u8 *func_L01_004C80D0(u32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C47E8(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038D000(void *, void *, void *);

void func_L01_0032F800(u8 *moby, V4_32F800 *dir) {
    V4_32F800 a;
    V4_32F800 b;
    V4_32F800 c;
    V4_32F800 d;
    V4_32F800 up;
    V4_32F800 pos;
    V4_32F800 sum;
    u8 *e;

    e = func_L01_004C80D0(*(u32 *)(*(u8 **)(moby + 0x68) + 0x48));
    up.x = 0.0f;
    up.y = 0.0f;
    up.z = 1.0f;
    up.w = 0.0f;
    a = *dir;
    d = *dir;
    func_0038CE90(&b, &a, &up);
    func_0038CF68(&b, &b, 1.0f);
    func_0038CE90(&c, &b, &a);
    func_003C47E8(e + 0x10, &a);
    func_003C2F58(moby, 0, &pos);
    func_0038D000(&d, dir, moby + 0xC0);
    sum = d;
    sum.x = d.x + pos.x;
    sum.y = d.y + pos.y;
    sum.z = d.z + pos.z;
}
