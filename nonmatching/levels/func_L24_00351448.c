/* func_L24_00351448: near miss (w3 p2w3). From asm (family of func_L30_0034C300); needs --as ps2as (0.00040000002f). Store order searched by hill-climb.
   Remaining 4 rows: sw 0x10 / swc1 0x20 order and swc1 0x14 relative to the jal.
    */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern float func_0038D160(float, float);
extern float func_0038CED8(void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_003C7C38(void *);

u8 *func_L24_00351448(u8 *pos, s32 a1, u8 *dir, s32 a3, s32 a4, float f12, float f13, float f14, float f15) {
    u8 *object = func_003C24B0(0x15E2, 0x80);
    u8 *state;
    float d;

    if (object != 0) {
        object[0x30] = 0xFF;
        *(u16 *)(object + 0x32) = 0xFF;
        object[0x31] = 1;
        object[0x20] = 0;
        state = *(u8 **)(object + 0x68);
        *(u128_t *)state = *(u128_t *)dir;
        *(u128_t *)(object + 0x10) = *(u128_t *)pos;
        *(float *)(object + 0xF8) = func_0038D160(*(float *)dir, *(float *)(dir + 4));
        d = func_0038CED8(dir);
        *(float *)(object + 0xF4) = -func_0038D160(d, *(float *)(dir + 8));
        *(s32 *)(object + 0xF0) = 0;
        *(float *)(state + 0x20) = f13;
        *(s32 *)(state + 0x10) = a1;
        *(s32 *)(state + 0x28) = a3;
        *(s32 *)(state + 0x2C) = a4;
        *(float *)(state + 0x24) = f14;
        *(float *)(state + 0x18) = f12 * 0.00040000002f;
        *(float *)(object + 0x2C) = *(float *)(*(u8 **)(object + 0x24) + 0x24) * f15;
        *(float *)(state + 0x14) = f15;
        func_003A52A0(0, 0, object);
        object[0x20] = 0;
        func_003C7C38(object);
    }
    return object;
}
