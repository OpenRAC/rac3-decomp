/* functional: high. Same reads/writes/calls in same order as retail (verified against PAL asm: state offsets, constants, callee names); differs only in register allocation/scheduling. Snippet declares its own D_L20_001E2E80 and takes u8 *obj: the file context declares D_L20_001E2E80 as C_003EEB40[] and func_L20_003F0088(void), so reconcile when landing. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003F0088;
typedef struct { f32 inner, outer, brightness; u8 p0C[4]; s16 frame, duration, alpha, p16, ring, flash, p1C, beam; } State_003F0088;
typedef struct { V_003F0088 position; u8 p10[0x450]; } Player_003F0088;
extern s16 D_001CFEC0[];
extern s32 D_001D52F0;
extern Player_003F0088 D_L20_001E2E80[];
static __inline__ void sub_003F0088(V_003F0088 *d, V_003F0088 *a, V_003F0088 *b) {
    __asm__("lqc2 $vf2, %1\n lqc2 $vf1, %2\n vsub.xyz $vf2, $vf2, $vf1\n sqc2 $vf2, %0" : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_003F0088(V_003F0088 *d, V_003F0088 *a, V_003F0088 *b) {
    __asm__("lqc2 $vf2, %2\n lqc2 $vf1, %1\n vadd.xyz $vf1, $vf1, $vf2\n sqc2 $vf1, %0" : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
void func_L20_003F0088(u8 *obj) {
    extern void func_003A9440(s32, s32);
    extern void func_0038AF30(s32, s32, s32, s32, u32);
    extern void func_L20_003F0418(void *, s32, s32, f32, f32, f32, f32, f32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    u8 packet[0x90] __attribute__((aligned(16)));
    V_003F0088 camera, delta, rotated, center, side, up, temp;
    State_003F0088 *state = *(State_003F0088 **)(obj + 0x68);
    f32 scale;
    u32 color;
    if (state->flash != 0 && state->duration - state->frame < 2) {
        if (state->alpha != 0) {
            func_003A9440(0x42, 0x48);
            func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], 0x80808080);
        }
    }
    if (state->ring != 0) {
        s32 remaining = state->duration - state->frame;
        if (remaining < 10) {
            func_L20_003F0418(obj + 0x10, 0x3B, 0,
                state->inner + (state->outer - state->inner) * ((f32)remaining / 10.0f), 0.5f, 0.0f, 0.0f, 0.0f);
        } else if ((u16)(state->frame - 46) < 4) {
            func_L20_003F0418(obj + 0x10, 0x3B, 0,
                state->inner + (state->outer - state->inner) * ((f32)(state->frame - 45) / 10.0f), 0.5f, 0.0f, 0.0f, 0.0f);
        }
    }
    if (state->beam != 0 && state->alpha != 0) {
        func_003C5180(obj + 0x10, &camera, 1);
        scale = (f32)state->alpha * state->brightness;
        func_003D93B0(packet, 11, 4, 128);
        color = ((s32)(scale * 255.0f) << 24) | 0xFFFFFF;
        *(u32 *)(packet + 0x40) = color;
        *(u32 *)(packet + 0x4C) = color;
        *(u32 *)(packet + 0x48) = color;
        *(u32 *)(packet + 0x44) = color;
        *(f32 *)(packet + 0x50) = 0.0f;
        *(f32 *)(packet + 0x54) = 0.0f;
        *(f32 *)(packet + 0x58) = 0.0f;
        *(f32 *)(packet + 0x5C) = 1.0f;
        *(f32 *)(packet + 0x60) = 1.0f;
        *(f32 *)(packet + 0x64) = 0.0f;
        *(f32 *)(packet + 0x68) = 1.0f;
        *(f32 *)(packet + 0x6C) = 1.0f;
        sub_003F0088(&delta, (V_003F0088 *)(obj + 0x10), &D_L20_001E2E80[D_001D52F0].position);
        func_0038CF68(&rotated, &delta, 0.1f);
        add_003F0088(&center, &D_L20_001E2E80[D_001D52F0].position, &rotated);
        func_0038CE90(&side, &delta, &camera);
        func_0038CF68(&side, &side, 0.075f);
        func_0038CE90(&up, &side, &delta);
        func_0038CF68(&up, &up, 0.075f);
        add_003F0088(&temp, &center, &up);
        add_003F0088((V_003F0088 *)(packet + 0x00), &temp, &side);
        sub_003F0088((V_003F0088 *)(packet + 0x10), &temp, &side);
        sub_003F0088(&temp, &center, &up);
        add_003F0088((V_003F0088 *)(packet + 0x20), &temp, &side);
        sub_003F0088((V_003F0088 *)(packet + 0x30), &temp, &side);
        func_003D2DA0(packet, 0, 0);
    }
}
