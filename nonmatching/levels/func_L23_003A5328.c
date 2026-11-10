/* func_L23_003A5328: near miss (w3 p2w3). From asm (twin func_L11_003F4F30 unrelated). Loop 1..2: matrix[64], u128_t v[2] (a=v[0], b=v[1]), gp floats D_L23_001DE064/28, &D_L23_001DE068.
   Remaining 2 rows: loop test slti uses $v0 vs retail $v1 (+ matching bnez). Tried for/do-while/<=2/post-inc.
    */
typedef int u128_t __attribute__((mode(TI)));
extern float D_L23_001DE064;
__asm__(".extern D_L23_001DE064, 4");
extern float D_L23_001DE028;
__asm__(".extern D_L23_001DE028, 4");
extern s32 D_L23_001DE068;
__asm__(".extern D_L23_001DE068, 4");
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, float);
extern void func_003A52A0(s32, s32, void *);
extern void func_L23_0032B060(void *, void *, void *, float);

void func_L23_003A5328(void *obj) {
    char matrix[64] __attribute__((aligned(16)));
    u128_t v[2];
    s32 i;

    for (i = 1; i < 3; i++) {
        func_003C2EC0(obj, i, matrix);
        v[0] = *(u128_t *)(matrix + 0x30);
        func_0038CF68(&v[1], matrix, D_L23_001DE064);
        func_003A52A0(2, 0, obj);
        func_L23_0032B060(&v[0], &v[1], &D_L23_001DE068, D_L23_001DE028);
    }
}
