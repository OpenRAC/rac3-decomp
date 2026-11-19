/* functional: high. 19 words differ, all in the prologue register assignment (which saved register holds the count/pos); body, calls and arguments equal retail. */
/* localdecomp:start func_L30_003B3BD0 */
__asm__(".extern D_L30_001DED0C, 4");
__asm__(".extern D_L30_001DED10, 4");
__asm__(".extern D_L30_001DED14, 4");
__asm__(".extern D_L30_001DED18, 4");
__asm__(".extern D_L30_001DED1C, 4");
__asm__(".extern D_L30_001DED20, 4");
__asm__(".extern D_L30_001DED24, 4");
__asm__(".extern D_L30_001DED28, 4");
__asm__(".extern D_L30_001DED2C, 4");
extern s32 D_L30_001DED0C;
extern s32 D_L30_001DED10;
extern s32 D_L30_001DED14;
extern s32 D_L30_001DED18;
extern f32 D_L30_001DED1C;
extern f32 D_L30_001DED20;
extern f32 D_L30_001DED24;
extern f32 D_L30_001DED28;
extern f32 D_L30_001DED2C;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003B3BD0;
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_00474078(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);
void func_L30_003B3BD0(u8 *pos, s32 count) {
    V_003B3BD0 a, b;
    s32 life1;
    u8 *p;

    if (count <= 0) {
        return;
    }
    do {
        func_00382580(&a, 0.1f, 1.5f);
        func_0038CF68(&b, &a, func_003824E0(D_L30_001DED1C * 0.7f, D_L30_001DED1C) * 0.02f);
        b.y = -fabs_asm(b.y);
        if (func_00382468(3) != 0) {
            b.z = fabs_asm(b.z);
        }
        func_00382580(&a, 0.1f, 1.5f);
        vec_add_ab(&a, &a, pos + 0x10);
        life1 = (func_00382498(D_L30_001DED14, D_L30_001DED18) * 5 + 2) / 6;
        p = func_L01_00474078(&a, &b, life1, D_L30_001DED20, D_L30_001DED24, D_L30_001DED28, D_L30_001DED2C, D_L30_001DED0C, D_L30_001DED10, (func_00382498(D_L30_001DED14 - 5, D_L30_001DED14) * 5 + 2) / 6, 0);
        if (p != 0) {
            p[2] = D_L30_0021F098[0x62][0];
        }
        count--;
    } while (count != 0);
}
/* localdecomp:end func_L30_003B3BD0 */
