/* PAL near miss (Codex wave 10): near miss: 37 words differ with the file's flags.
 * Worker's note: 37 word diffs: build/codex/w537/func_L01_0037CEC8.try3.log; two-loop behavior reconstructed; global base/address hoisting, cap load and second-loop register allocation differ; no metadata
 */
#include "common.h"
/* localdecomp:start func_L01_0037CEC8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x80]; vu0_v4 position; u8 pad90[0x50]; vu0_v4 origin;
    u8 padF0[0x25C0-0xF0]; u8 *hero;
    u8 pad25C4[0x2850-0x25C4]; s32 health;
} Game_0037CEC8;
extern Game_0037CEC8 D_001A4BE0;
typedef struct { u8 pad[8]; s32 cap; } Limit_0037CEC8;
extern Limit_0037CEC8 D_00142660;
extern s32 D_001D6694_sda;
extern s32 D_L01_001D6694 __attribute__((section(".data")));
void func_L01_0037CEC8(u8 *object) {
    extern f32 *func_00382348(u8 *);
    extern s32 func_0038CAD0(s32 *);
    extern void func_L01_00446748(void *, u8 *, s32, f32);
    extern void func_L01_00446978(u8 *, void *);
    extern void func_L01_0037D210(u8 *, void *);
    extern f32 func_L01_0040E548(void *, void *);
    extern s32 func_00382468(s32);
    extern void func_00382580(void *, f32, f32);
    extern void func_L01_0046C470(void *, void *, u32, s32, s32, s32, s32, s32, f32);
    extern void func_003E4D10(s32);
    u8 packet[0x30] __attribute__((aligned(16)));
    u8 *state = *(u8 **)(object + 0x68);
    u8 *p, *q, *target, *r;
    u8 **slot;
    f32 *health;
    s32 found = 0;
    s32 i;
    q = state + 0x90;
    p = state;
    do {
        target = *(u8 **)(p + 0x134);
        if (*(u8 **)(p + 0x130) != object || target == 0) goto next_target;
        health = func_00382348(target);
        if (health == 0 || target == *(u8 **)((u32)&D_001A4BE0 + 0x25C0) ||
            target == 0 || *(u8 **)(target + 0x24) == 0 ||
            (*(u8 **)(target + 0x24))[0x46] != 5 ||
            target[0x20] == 0xFE || target[0x20] == 0xFD || !(*health > 0.0f) ||
            (*(u16 *)(target + 0x34) & 2) ||
            *(s16 *)(target + 0xAA) == 0x1AE6 || *(s16 *)(target + 0xAA) == 0x1A17 ||
            *(s16 *)(target + 0xAA) == 0x1B27) goto next_target;
        found = 1;
        if (D_001D6694_sda == 0 && func_0038CAD0((s32 *)(state + 0x64))) {
            func_L01_00446748(packet, object, 0x10000, 1.0f);
            packet[0x18] = 0;
            *(u16 *)(packet + 0x1A) = *(u16 *)(object + 0xAA);
            packet[0x19] = found;
            func_L01_00446978(target, packet);
            *(s32 *)(state + 0x64) = 150;
        }
        func_L01_0037D210(object, q);
next_target:
        p += 0xB0;
        q += 0xB0;
    } while ((s32)p < (s32)(state + 0x840));
    r = state + 0x90;
    p = state + 0xB0;
    slot = (u8 **)(state + 0x134);
    for (i = 0; i < 12; i++, r += 0xB0, p += 0xB0, slot = (u8 **)((u8 *)slot + 0xB0)) {
        s32 old, cap, value;
        if (*slot != *(u8 **)((u32)&D_001A4BE0 + 0x25C0)) continue;
        if (!found) continue;
        if (!(func_L01_0040E548((void *)((u32)&D_001A4BE0 + 0x80), p) < 25.0f)) continue;
        if (func_00382468(2) == 0) {
            func_00382580(packet, 0.020000001415610313f, 0.040000002831220627f);
            func_L01_0046C470((void *)((u32)&D_001A4BE0 + 0xE0), packet, 0x50804040, 60,
                func_00382468(255) & 255, 1, 64, 0, 0.4f);
            func_L01_0046C470((void *)((u32)&D_001A4BE0 + 0xE0), packet, 0x407F7F7F, 60,
                func_00382468(255) & 255, 1, 64, 0, 0.2f);
        }
        cap = *(s32 *)((u32)&D_00142660 + 8);
        if (!D_L01_001D6694 && func_0038CAD0((s32 *)(state + 0x20))) {
            old = *(s32 *)((u32)&D_001A4BE0 + 0x2850);
            if (old != 0) {
                value = old + *(s32 *)(state + 0x54);
                if (value > cap) value = cap;
                *(s32 *)((u32)&D_001A4BE0 + 0x2850) = value;
                if (old != value) {
                    *(s32 *)(state + 0x20) = 37;
                    *(s16 *)(state + 0x26) -= *(u16 *)(state + 0x54);
                    if (*(s16 *)(state + 0x26) < 0) *(s16 *)(state + 0x26) = 0;
                    func_003E4D10(300);
                }
            }
        }
        func_L01_0037D210(object, r);
        break;
    }
}
/* localdecomp:end func_L01_0037CEC8 */
