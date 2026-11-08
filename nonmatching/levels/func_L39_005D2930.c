/* func_L39_005D2930: near miss (w3 p2w3). Port of rac2 func_L00_0033FFB8 (particle spawner), needs --as ps2as. All values/constants right (0.00040000002f).
   Remaining 7 rows: lui for D_L39_002969A4 is scheduled after the mtc1 instead of before addiu s1 (reg $v1 vs $a0).
    */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L39_002969A4;
__asm__(".extern D_L39_002969A4, 16");
extern u8 *func_003CD108(s32);
extern float func_L39_005B4410(float, float);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern float func_L39_005B44C8(void);

u8 *func_L39_005D2930(u128_t *position, u128_t *velocity, s32 lifetime) {
    u8 *particle = func_003CD108(0x63);
    u8 *motion;
    if (particle) {
        motion = particle + 0x20;
        particle[9] = 0x42;
        particle[3] = 0x44;
        particle[1] = 0;
        particle[2] = *D_L39_002969A4;
        *(float *)(particle + 0xC) = func_L39_005B4410(0.05f, 0.2f) * 210000.0f;
        particle[8] = func_L39_005B4398(255);
        *(s16 *)(particle + 0xA) = (lifetime * 5 + 2) / 6;
        *(u128_t *)(particle + 0x10) = *position;
        *(u128_t *)motion = *velocity;
        *(float *)(motion + 0xC) = func_L39_005B4410(0.6f, 2.6f) * 0.00040000002f;
        *(float *)(motion + 0x18) = *(float *)(particle + 0xC) * 2.0f;
        *(s16 *)(motion + 0x16) = func_L39_005B43C8(0, 3);
        *(s16 *)(motion + 0x14) = ((lifetime / 2) * 5 + 2) / 6;
        *(float *)(motion + 0x1C) = func_L39_005B44C8();
    }
    return particle;
}
