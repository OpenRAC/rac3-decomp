/* functional: high. PAL draft re-verified against the asm (arg registers, 16.0 phase split, end-peak divisor, delay-slot z store before call); VU0 vadd/vsub.xyz written as plain xyz float ops (w from position as retail). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00353178;
typedef int Q_00353178 __attribute__((mode(TI)));
void func_L07_00353178(u8 *self, s32 sequence, s32 joint, s32 amount,
                       f32 time, f32 speed, f32 height, f32 start, f32 end, f32 peak) {
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_003C3D30(void *, s32, s32, f32);
    extern f32 func_003C3BE8(f32, f32, f32);
    extern void func_L01_0045AA30(void *, void *);
    V_00353178 position, scaled, delta;
    V_00353178 *pos0 = (V_00353178 *)(self + 0x10);
    f32 factor;
    f32 angle;
    if (self[0x42] != sequence) return;
    if (!(start <= time && time < end)) return;
    *(Q_00353178 *)&position = *(Q_00353178 *)(self + 0x10);
    func_0038CF68(&scaled, self + 0xC0 + joint * 16, ((f32)amount * speed) / (end - start));
    position.x += scaled.x;
    position.y += scaled.y;
    position.z += scaled.z;
    if (time < 16.0f) factor = (time - start) / (peak - start);
    else factor = 1.0f - (time - peak) / (end - peak);
    angle = func_003C3D30(&position, 0, 0, 0.5f);
    position.z = func_003C3BE8(angle, angle + height, factor);
    delta.x = position.x - pos0->x;
    delta.y = position.y - pos0->y;
    delta.z = position.z - pos0->z;
    delta.w = position.w;
    func_L01_0045AA30(self, &delta);
}
