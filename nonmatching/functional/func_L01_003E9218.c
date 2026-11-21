/* functional: high. Camera helper: builds the vector from the follow block's look point (obj+0x70, +0x60) to *position (VU0 vsub.xyz, kept as COP2 asm) and forwards it to func_003E8FE8 together with the float argument that arrives in f12 (retail never touches f12, so it is passed through explicitly). The existing callers' (u8 *, f32) declaration omits the position argument */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_003E9218;
void func_L01_003E9218(u8 *camera, Vec_003E9218 *position, f32 limit) {
    extern f32 func_L01_003E8FE8(u8 *, Vec_003E9218 *, f32);
    Vec_003E9218 delta;
    u8 *follow = *(u8 **)(camera + 0x70);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta) : "m"(*position), "m"(*(Vec_003E9218 *)(follow + 0x60)) : "vf1", "vf2");
    func_L01_003E8FE8(camera, &delta, limit);
}
