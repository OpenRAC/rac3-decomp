/* exact: high. check.py MATCH at level 01. */
/* PAL near miss (Codex wave 8): near miss: 0 words differ with the file's flags.
 * Worker's note: Canonical MATCH; final.log checks 18 PAL places: 6 MATCH, 12 one-word JAL mismatch at +0x1B8. callee-evidence.txt proves helper catalogue uses multiple copies (00447470, 00451FB8, 0047C4F8, 0047C518, 00447450); requires catalogue call-resolution correction ...
 */
#include "common.h"
/* localdecomp:start func_L01_0031A560 */
#include "vu0.h"
extern s16 **D_L01_001D6764;
extern u8 *D_L01_001E0EDC;
typedef struct { u128_t sphere; u128_t other; } Bound_0031A560;
extern Bound_0031A560 *D_L01_001E0ED4;
extern vu0_v4 D_L01_001E29C0;
__asm__(".extern D_L01_001D6764, 16");
__asm__(".extern D_L01_001E0EDC, 16");
__asm__(".extern D_L01_001E0ED4, 4");
void func_L01_0031A560(u8 *self) {
    extern void func_L01_0031A518(u128_t *, s32 *, u128_t *, s32 *, s32 *);
    extern s32 func_0038DC20(void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern s32 func_L01_00447470(s32, s32, f32);
    extern void func_L01_00451A68(s32, void *, void *, f32, f32);
    u128_t positions[70];
    s32 colors[70];
    vu0_v4 sphere, position, offset, temp, direction, temp2;
    s32 count;
    s32 color;
    u8 *p = *(u8 **)(self + 0x68);
    s16 *it;
    u8 *matrix;
    s32 index;
    s32 first;
    f32 dot;
    first = *(s32 *)p;
    count = 0;
    it = D_L01_001D6764[first];
    while (it && (it[-1] >= 0 || it == D_L01_001D6764[*(s32 *)p])) {
        index = *(u16 *)it & 0x7FFF;
        matrix = D_L01_001E0EDC + index * 64;
        if (!matrix) break;
        *(u128_t *)&sphere = *(u128_t *)((s32)D_L01_001E0ED4 + (index << 5));
        sphere.w += *(f32 *)(p + 0x4C);
        if (func_0038DC20(&sphere, *(f32 *)(p + 0x60)) >= 0) {
            *(u128_t *)&position = *(u128_t *)(matrix + 0x30);
            *(u128_t *)&temp = 0;
            temp.x = *(f32 *)(p + 0x50);
            temp.y = *(f32 *)(p + 0x54);
            temp.z = *(f32 *)(p + 0x58);
            *(u128_t *)&offset = *(u128_t *)&temp;
            func_0038D000(&offset, &offset, matrix);
            vec_add_ab(&position, &position, &offset);
            if (*(s32 *)(p + 0x6C)) {
                func_L01_0031A518((u128_t *)&position, (s32 *)(p + 0x30), positions, colors, &count);
            } else {
                vec_sub_ba(&temp, &D_L01_001E29C0, &position);
                func_0038CF68((f32 *)&temp, (f32 *)&temp, 1.0f);
                *(u128_t *)&temp2 = 0;
                temp2.x = *(f32 *)(p + 0x40);
                temp2.y = *(f32 *)(p + 0x44);
                temp2.z = *(f32 *)(p + 0x48);
                *(u128_t *)&direction = *(u128_t *)&temp2;
                func_0038D000(&direction, &direction, matrix);
                func_0038CF68((f32 *)&direction, (f32 *)&direction, 1.0f);
                dot = func_0038CE68(&temp, &direction);
                if (*(f32 *)(p + 0x3C) < dot) {
                    dot = dot * 0.5f + 0.5f;
                    if (*(s32 *)(p + 0x38)) dot *= dot;
                    color = func_L01_00447470(*(s32 *)(p + 0x34), *(s32 *)(p + 0x30), dot);
                    func_L01_0031A518((u128_t *)&position, &color, positions, colors, &count);
                }
            }
        }
        it++;
    }
    func_L01_00451A68(count, positions, colors, *(f32 *)(p + 0x4C), *(f32 *)(p + 0x5C));
}
/* localdecomp:end func_L01_0031A560 */
