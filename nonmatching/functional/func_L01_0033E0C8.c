/* functional: medium. 142 diff words at the file's flags (frame 0x220 vs 0x230 and scheduling); structure, vector math (vadd.xyz with w from the first operand), call order and the rand(0x40,0x80)/rand(0,0x40) split on q+0x88 >= 6 checked against retail. */
typedef struct { f32 x, y, z, w; } V4;
extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0033E2D0(void *, s32, void *, s32);

void func_L01_0033E0C8(void *a0, u8 *q) {
    V4 pts[25];
    V4 t190;
    V4 t1A0;
    V4 t1B0;
    V4 t1C0;
    V4 *cur;
    s32 i;
    s32 r;

    cur = pts;
    i = 0;
    do {
        t190 = *(V4 *)q;
        t1C0 = *(V4 *)(q + 0x30);
        t1A0 = *(V4 *)(q + 0x10);
        t190.x = t190.x + ((V4 *)(q + 0x20))->x;
        t190.y = t190.y + ((V4 *)(q + 0x20))->y;
        t190.z = t190.z + ((V4 *)(q + 0x20))->z;
        t1A0.x = t1A0.x + t1C0.x;
        t1A0.y = t1A0.y + t1C0.y;
        t1A0.z = t1A0.z + t1C0.z;
        func_L01_00445208(cur, q + 0x20, q + 0x30, &t190, &t1A0, (f32)i / 23.0f);
        i++;
        t1B0.w = 0;
        t1B0.x = func_003824E0(-1.0f, 1.0f);
        t1B0.y = func_003824E0(-1.0f, 1.0f);
        t1B0.z = func_003824E0(-1.0f, 1.0f);
        func_0038CF68(&t1B0, &t1B0, 0.075f);
        cur->x = cur->x + t1B0.x;
        cur->y = cur->y + t1B0.y;
        cur->z = cur->z + t1B0.z;
        cur++;
    } while (i < 24);
    if (*(s32 *)(q + 0x88) >= 6) {
        r = func_00382498(0x40, 0x80);
    } else {
        r = func_00382498(0, 0x40);
    }
    func_L01_0033E2D0(a0, r, pts, 0x19);
}
