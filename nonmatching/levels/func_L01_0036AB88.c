/* PAL near miss (Codex wave 10): near miss: 237 words differ with the file's flags.
 * Worker's note: ab88-05.log: 102 diff / 315 words with --divs 2 (not MATCH, no certified NEEDS); VU/pointer interleaving and FP scheduling; 3 final wordings same bytes; ab88-notes.txt
 */
#include "common.h"
/* localdecomp:start func_L01_0036AB88 */
#include "vu0.h"
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern u8 *D_L01_0022116C[];
extern u8 *D_L01_00221098[];
void func_L01_0036AB88(u8 *obj) {
    extern void func_003C5180(void *, void *, s32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_0038CAD0(void *);
    extern void func_003C2880(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    extern void func_L01_0036B078(u8 *);
    extern void func_L01_00404A10(void (*)(u8 *), u8 *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    vu0_v4 samples[3];
    vu0_v4 head, point;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *particle;
    s32 rotation, count, i;
    u8 *velocity;
    f32 t, angle, size;
    samples[0] = *(vu0_v4 *)(obj + 0x10);
    func_003C5180(obj + 0x10, &samples[1], 1);
    samples[2] = *(vu0_v4 *)(obj + 0x10);
    if (func_L01_004CB2D8()) {
        func_L01_004CAB30(obj + 0x10, obj + 0x10);
        func_L01_004CAB30(state + 0x50, state + 0x50);
        func_L01_004CAB30(state, state);
    }
    if (obj[0x20] == 0) {
        velocity = state + 0x20;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)(state + 0x50))
            : "m"(*(vu0_v4 *)(state + 0x50)), "m"(*(vu0_v4 *)velocity) : "vf1", "vf2");
        if (func_0038CAD0(state + 0x38)) {
            func_003C2880(obj);
            return;
        }
        func_0038CF68(&head, velocity, -0.5f);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(head) : "m"(head), "m"(*(vu0_v4 *)(obj + 0x10)) : "vf1", "vf2");
        rotation = func_00382468(255);
        particle = func_L01_0046FB40(&head, D_L01_001D66B0, 2, 0x202080, rotation, 32, 16, 420000.0f, 420000.0f, 0.0f, 2);
        if (particle) particle[2] = *D_L01_0022116C[0];
        rotation = (rotation + 128) % 255;
        particle = func_L01_0046FB40(&head, D_L01_001D66B0, 2, 0x204080, rotation, 32, 16, 420000.0f, 420000.0f, 0.0f, 2);
        if (particle) particle[2] = *D_L01_0022116C[0];
        func_L01_00404A10(func_L01_0036B078, obj);
        for (i = 1; i >= 0; i--) {
            t = func_003824E0(0.0f, 1.0f);
            func_0038CDF8(&point, state, &head, t);
            rotation = func_00382468(255);
            { f32 degrees = *(f32 *)(state + 0x60) * 180.0f;
            angle = -(degrees / 3.1415927410125732f); }
            size = 1.8f - angle * 0.01f * 5.0f;
            count = (s32)(t * 20.0f - angle);
            if (count >= 10) count = 9;
            else if (count <= 1) count = 2;
            point.x += func_L01_00443A18(0.0f, 0.04f);
            point.y += func_L01_00443A18(0.0f, 0.04f);
            point.z += func_L01_00443A18(0.0f, 0.04f);
            count = (count * 5 + 2) / 6;
            angle = angle * 5.0f * 0.0004000000189989805f;
            { u8 *spark = func_L01_0046FB40(&point, velocity, count, 0xFF1010, rotation, 48, 0, size * 210000.0f, size * 0.2f * 210000.0f, angle, 2);
            if (spark) spark[2] = *D_L01_00221098[91]; }
            size *= 0.5f;
            { u8 *spark = func_L01_0046FB40(&point, velocity, count, 0x808080, rotation, 48, 0, size * 210000.0f, size * 0.2f * 210000.0f, angle, 2);
            if (spark) spark[2] = *D_L01_00221098[91]; }
        }
    }
    if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f ||
        *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f ||
        *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) func_003C2880(obj);
}
/* localdecomp:end func_L01_0036AB88 */
