/* functional: high. From PAL near-miss draft; re-read all constants, loop count (2 iterations), movn 3/-3 choice and particle arg order against PAL asm. 21 diff = loop decrement placement. Uses vec_neg/vec_add_ab from vu0.h as the file does. D_L07_0021EC98 is declared elsewhere in the file as G_003B4DF8; the local Data_003B4978 struct only reads +0x16C, rename/merge when integrating. */
typedef struct { u8 pad[0x16C]; u8 *p; } Data_003B4978;
extern Data_003B4978 D_L07_0021EC98;
void func_L07_003B4978(void *obj, u8 side) {
    extern void func_003C2EC0(void *, s32, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C4C18(void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    struct { vu0_q matrix[4]; vu0_q position, direction, jitter, velocity; } v;
    s32 i;
    s32 next;
    s32 life;
    f32 a,b;
    u8 *p;
    func_003C2EC0(obj, side * 3 + 8, v.matrix);
    v.direction = v.matrix[0];
    if (side == 1) vec_neg(&v.direction, &v.direction);
    func_0038CE20(&v.position, &v.direction, 1.0f);
    vec_add_ab(&v.position, &v.matrix[3], &v.position);
    i=1;
    do {
        v.jitter = v.position;
        func_003C4C18(&v.jitter, 1.0f);
        func_0038CE20(&v.velocity, &v.direction, func_003824E0(0.10000001f, 0.50000006f));
        func_003C4C18(&v.velocity, 0.060000002f);
        life = func_00382498(20,30);
        a = func_003824E0(52500.0f,105000.0f);
        b = func_003824E0(315000.0f,525000.0f);
        p = func_L01_0046FB40(&v.position,&v.velocity,life,0x808080,func_00382468(2) ? 3 : -3,127,0,0,a,b,0.0f);
        next = i - 1;
        if (p) p[2] = *D_L07_0021EC98.p;
        i = next;
    } while (i >= 0);
}
