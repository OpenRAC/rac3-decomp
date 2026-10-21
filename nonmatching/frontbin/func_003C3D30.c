/* US draft of func_003C3D30 (rac3-uya-decomp func_003BE7F0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C3D30 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BE7F0;
extern V_3BE7F0 D_00227660;
s32 func_003D3CB0(V_3BE7F0 *, V_3BE7F0 *, s32, s32, s32);
f32 func_003C3D30(V_3BE7F0 *p, s32 flags, s32 c, f32 dz) {
    V_3BE7F0 a = *p;
    V_3BE7F0 b = *p;
    a.z = 0.01f;
    b.z += dz;
    if (func_003D3CB0(&b, &a, flags | 2, c, 0)) return D_00227660.z;
    return 0.0f;
}
/* localdecomp:end func_003C3D30 */
