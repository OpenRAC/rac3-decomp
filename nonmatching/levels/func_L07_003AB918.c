/* PAL near miss (Codex wave 6): near miss: 242 words differ with the file's flags.
 * Worker's note: Best 239 diff (w316/func_L07_003AB918-best.log): full decoded VU0/quad/sprite draft; extra saved register and 0x150 versus 0x140 frame, float allocation, block scheduling; fixed default assembler emits lit4 loads for 0.4/0.35/0.9 instead of inline constants.
 */
#include "common.h"
/* localdecomp:start func_L07_003AB918 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003AB918;
typedef struct {
    V_003AB918 vertex[4];
    s32 color[4];
    f32 uv[8];
    u8 rest[0x20];
} Quad_003AB918;
extern V_003AB918 D_L07_001E1EC0;
static __inline__ void sub_003AB918(V_003AB918 *d, V_003AB918 *a, V_003AB918 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_003AB918(V_003AB918 *d, V_003AB918 *a, V_003AB918 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void sub2_003AB918(V_003AB918 *d, V_003AB918 *a, V_003AB918 *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_ba_003AB918(V_003AB918 *d, V_003AB918 *a, V_003AB918 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void sub_ba_003AB918(V_003AB918 *d, V_003AB918 *a, V_003AB918 *b) {
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
void func_L07_003AB918(u8 *obj) {
    extern void func_003C2F58(u8 *, s32, f32 *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003D2DA0(void *, s32, s32);
    extern f32 func_00382538(void);
    extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
    V_003AB918 start;
    V_003AB918 direction;
    V_003AB918 end;
    V_003AB918 side0;
    V_003AB918 side1;
    Quad_003AB918 quad;
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 fraction = (f32)*(s16 *)(vars + 0x530) / 10.0f;
    f32 width;
    f32 length;
    f32 random;
    if (fraction > 1.0f) fraction = 1.0f;
    func_003C2F58(obj, vars[0x533], (f32 *)&start);
    sub_003AB918(&direction, (V_003AB918 *)(vars + 0x520), &start);
    if (*(f32 *)(vars + 0x538) == 1.0f) {
        end = *(V_003AB918 *)(vars + 0x520);
    } else {
        func_0038CE20(&end, &direction, *(f32 *)(vars + 0x538));
        add_003AB918(&end, &start, &end);
    }
    sub2_003AB918(&side0, &start, &D_L07_001E1EC0);
    width = fraction * 0.25f;
    func_0038CE90(&side0, &side0, &direction);
    func_0038CF68(&side0, &side0, width);
    sub_003AB918(&side1, &end, &D_L07_001E1EC0);
    func_0038CE90(&side1, &side1, &direction);
    func_0038CF68(&side1, &side1, width);
    func_003D93B0(&quad, 0x2B, 1, 0x80);
    quad.color[0] = 0x40802020;
    quad.color[3] = 0x40802020;
    quad.color[2] = 0x40802020;
    quad.color[1] = 0x40802020;
    add_ba_003AB918(&quad.vertex[0], &start, &side0);
    sub_ba_003AB918(&quad.vertex[1], &start, &side0);
    add_ba_003AB918(&quad.vertex[2], &end, &side1);
    sub_ba_003AB918(&quad.vertex[3], &end, &side1);
    quad.uv[0] = 0.0f;
    quad.uv[1] = 0.0f;
    quad.uv[2] = 0.0f;
    quad.uv[3] = 1.0f;
    quad.uv[4] = 1.0f;
    quad.uv[5] = 0.0f;
    quad.uv[6] = 1.0f;
    quad.uv[7] = 1.0f;
    func_003D2DA0(&quad, 0, 0);
    func_003D93B0(&quad, 0x27, 1, 0x80);
    width = fraction * 0.35f;
    quad.color[0] = -256;
    quad.color[2] = 0x80FF0000;
    quad.color[1] = -256;
    quad.color[3] = 0x80FF0000;
    func_0038CF68(&side0, &side0, width);
    func_0038CF68(&side1, &side1, width);
    add_ba_003AB918(&quad.vertex[0], &start, &side0);
    sub_003AB918(&quad.vertex[1], &start, &side0);
    add_ba_003AB918(&quad.vertex[2], &end, &side1);
    sub2_003AB918(&quad.vertex[3], &end, &side1);
    length = *(f32 *)(vars + 0x538) * 4.0f;
    quad.uv[0] = 0.0f - *(f32 *)(vars + 0x534);
    quad.uv[1] = 0.0f;
    quad.uv[2] = 0.0f - *(f32 *)(vars + 0x534);
    quad.uv[3] = 1.0f;
    quad.uv[4] = length - *(f32 *)(vars + 0x534);
    quad.uv[5] = 0.0f;
    quad.uv[6] = length - *(f32 *)(vars + 0x534);
    quad.uv[7] = 1.0f;
    func_003D2DA0(&quad, 0, 0);
    random = func_00382538();
    func_003D9508(&start, 0x47, 0x60606020, 1, 0.9f, 0.4f, random);
    random = func_00382538();
    func_003D9508(&start, 0x47, 0x80FFFFFF, 1, 0.25f, 0.4f, random);
    random = func_00382538();
    func_003D9508(&end, 0x47, 0x60604020, 0, 0.75f, 0.0f, random);
    random = func_00382538();
    func_003D9508(&end, 0x47, 0x80FFFFFF, 0, 0.5f, 0.0f, random);
}
/* localdecomp:end func_L07_003AB918 */
