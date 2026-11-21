/* functional: medium. Near-miss draft (compiles under file flags); 246 diff words; stack 0xa0; description inferred from draft and callee inventory, not every branch re-read */
/* localdecomp:start func_L01_0034EAA0 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_0034EAA0;
typedef struct {
    Vec_0034EAA0 direction;
    u8 *source;
    u32 flags;
    u8 kind, subtype;
    u16 class_id;
    f32 damage;
    s32 enabled;
} Hit_0034EAA0;
typedef struct { u8 pad[0x6C]; f32 damage; u8 tail[0x80]; } Row_0034EAA0;
extern Row_0034EAA0 D_L01_002C5600[];
static __inline__ Row_0034EAA0 *row_0034EAA0(u32 base, s32 index) {
    return (Row_0034EAA0 *)(base + index * sizeof(Row_0034EAA0));
}
extern u8 D_001425C0[];
extern u8 D_L01_001D66B0[];
extern f32 D_L01_001DD410;
__asm__(".extern D_L01_001DD410, 4");
extern f32 D_L01_001DD414;
__asm__(".extern D_L01_001DD414, 4");
extern f32 D_L01_001DD418;
__asm__(".extern D_L01_001DD418, 4");
extern f32 D_L01_001DD41C;
__asm__(".extern D_L01_001DD41C, 4");
extern f32 D_L01_001DD420;
__asm__(".extern D_L01_001DD420, 4");
extern f32 D_L01_001DD424;
__asm__(".extern D_L01_001DD424, 4");
extern f32 D_L01_001DD428;
__asm__(".extern D_L01_001DD428, 4");
extern f32 D_L01_001DD42C;
__asm__(".extern D_L01_001DD42C, 4");
extern f32 D_L01_001DD430;
__asm__(".extern D_L01_001DD430, 4");
extern f32 D_L01_001DD434;
__asm__(".extern D_L01_001DD434, 4");
void func_L01_0034EAA0(u8 *obj) {
    extern f32 func_0038CF00(void *, void *);
    extern s32 func_0038CB00(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00446978(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_L01_0044AE78(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_L01_00404A10(void (*)(u8 *), u8 *);
    extern void func_L01_0034F0B0(u8 *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_L01_0046B458(void *, s32, u32, s32, s32, void *, s32, f32, f32, f32);
    Hit_0034EAA0 hit;
    u8 *state = *(u8 **)(obj + 0x68);
    f32 distance = func_0038CF00(obj + 0x10, state + 0x30);
    f32 step, z, phase, phase2, height, wave, noise;
    f32 speed, yaw, pitch, size;
    s32 i, spin;
    if (*(s16 *)(state + 0x1C) && func_0038CB00(state + 0x1C)) {
        if (*(void **)(state + 0x20)) {
            hit.flags = 0x01010000;
            hit.enabled = 1;
            hit.source = obj;
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(hit.direction)
                : "m"(*(Vec_0034EAA0 *)(state + 0x30)), "m"(*(Vec_0034EAA0 *)(obj + 0x10))
                : "vf1", "vf2");
            func_0038CF68(&hit.direction, &hit.direction, 1.0f);
            hit.direction.w = 5627.9248046875f;
            hit.kind = 3;
            hit.subtype = 2;
            hit.class_id = *(u16 *)(obj + 0xAA);
            hit.damage = row_0034EAA0((u32)D_L01_002C5600, D_001425C0[0x16])->damage;
            if (*(u8 **)(state + 0x40)) {
                s32 kind = *(s16 *)(*(u8 **)(state + 0x40) + 0xAA);
                if (kind == 0x184E) {
                    hit.damage = row_0034EAA0((u32)D_L01_002C5600, D_001425C0[0x47])->damage * 0.5f;
                    hit.class_id = *(u16 *)(*(u8 **)(state + 0x40) + 0xAA);
                    hit.flags = 0x00410000;
                    hit.source = *(u8 **)(state + 0x40);
                    func_0038CF68(&hit.direction, &hit.direction, 0.5f);
                } else if (kind == 0x186D) {
                    hit.damage = row_0034EAA0((u32)D_L01_002C5600, D_001425C0[0x67])->damage;
                    hit.class_id = *(u16 *)(*(u8 **)(state + 0x40) + 0xAA);
                    hit.flags = 0x00410000;
                    hit.source = *(u8 **)(state + 0x40);
                    func_0038CF68(&hit.direction, &hit.direction, 0.5f);
                } else if (kind == 0x186B) {
                    hit.damage = row_0034EAA0((u32)D_L01_002C5600, D_001425C0[0x5F])->damage * 0.1f;
                    hit.class_id = *(u16 *)(*(u8 **)(state + 0x40) + 0xAA);
                    hit.flags = 0x00410000;
                    hit.source = *(u8 **)(state + 0x40);
                    func_0038CF68(&hit.direction, &hit.direction, 0.5f);
                }
            }
            func_L01_00446978(*(void **)(state + 0x20), &hit);
        }
    }
    step = (distance + (0.01f - distance) * ((f32)*(s16 *)(state + 0x1C) / 5.0f)) / 10.0f;
    *(f32 *)(state + 8) = func_0038DAB8(*(f32 *)(state + 8), D_L01_001DD41C * 0.01745329238474369f);
    *(f32 *)(state + 0xC) = func_0038DB00(*(f32 *)(state + 0xC), D_L01_001DD420);
    *(f32 *)(state + 0x10) = func_0038DAB8(*(f32 *)(state + 0x10), D_L01_001DD428);
    {
    s32 j;
    for (j = 0; j < 10; j++) {
        f32 index = (f32)j;
        z = D_L01_001DD418;
        if (j == 0 || j == 9) z = 0.0f;
        else {
            z *= func_0038D0B0(func_L01_0044AE78(*(f32 *)(state + 8) + index * 0.6283185482025146f));
            z += func_L01_00443A18(0.0f, D_L01_001DD414);
        }
        *(f32 *)(*(u8 **)state + j * 16 + 8) = z;
        *(s32 *)(*(u8 **)state + j * 16 + 4) = 0;
        *(f32 *)(*(u8 **)state + j * 16) = step * index;
        *(f32 *)(*(u8 **)state + j * 16 + 12) = 1.0f;
    }
    }
    for (i = 0; i < 19; i++) {
        f32 index = (f32)i;
        {
            f32 offset = index * D_L01_001DD424;
            *(s32 *)(*(u8 **)(state + 4) + i * 16 + 8) = 0;
            phase = func_L01_0044AE78(*(f32 *)(state + 0xC) + offset);
        }
        phase2 = func_L01_0044AE78(*(f32 *)(state + 0x10) + index * D_L01_001DD42C);
        height = D_L01_001DD430 * func_0038D0B0(phase2);
        wave = func_0038D0B0(phase);
        noise = func_L01_00443A18(D_L01_001DD410, D_L01_001DD414);
        z = height * wave + noise;
        *(f32 *)(*(u8 **)(state + 4) + i * 16 + 8) += z;
        *(f32 *)(*(u8 **)(state + 4) + i * 16 + 4) = D_L01_001DD434 * func_0038D098(phase);
        *(f32 *)(*(u8 **)(state + 4) + i * 16) = step * index;
        *(f32 *)(*(u8 **)(state + 4) + i * 16 + 12) = 1.0f;
    }
    func_L01_00404A10(func_L01_0034F0B0, obj);
    if (*(s16 *)(state + 0x1C) <= 0) {
        f32 speed_scale = 0.020000001415610313f;
        f32 particle_scale = 0.3f;
        {
        s32 j;
        for (j = 4; j >= 0; j--) {
            speed = func_003824E0(1.0f, 6.0f) * speed_scale;
            yaw = func_00382538();
            pitch = func_00382538();
            func_00382760(&hit.direction, speed, yaw, pitch);
            spin = func_00382498(1, 4);
            if (func_00382468(2)) spin = -spin;
            size = func_003824E0(0.4f, 0.8f);
            func_L01_0046B458(state + 0x30, 12, *(u32 *)(state + 0x24) | 0x7F000000, 0, spin,
                             &hit.direction, 0, size * particle_scale, size, 0.0f);
            func_L01_0046B458(state + 0x30, 12, 0x307F7F7F, 0, -spin,
                             &hit.direction, 0, size * 0.15f, size * 0.5f, 0.0f);
        }
        }
        spin = func_00382498(1, 8);
        if (func_00382468(2)) spin = -spin;
        {
        f32 final_size = func_003824E0(0.15f, 3.0f);
        func_L01_0046B458(state + 0x30, 10, *(u32 *)(state + 0x24) | 0x7F000000, 0, spin,
                         D_L01_001D66B0, 0, final_size * 0.1f, final_size, 0.0f);
        }
    }
}
/* localdecomp:end func_L01_0034EAA0 */
