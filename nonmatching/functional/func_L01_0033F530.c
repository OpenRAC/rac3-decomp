/* functional: high. Not byte-exact (stack/regalloc); all gp slots, constants and PAL 5/6 frame scale read from PAL asm; VU0 vsub/vadd.xyz as scalar ops keeping w. */
typedef struct { vu0_v4 verts[4]; u32 colors[4]; f32 uv[8]; u64 zero, texture, alpha, prim; } Pkt_0033F530;
typedef struct { u8 pad0[8]; s16 age; } Obj_0033F530;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 state; u8 pad21[0x68 - 0x21]; Obj_0033F530 *p; } Mob_0033F530;
typedef struct { s16 a, b, age, c, active, pad; } Slot_0033F530;
extern s32 D_001DD040_sda;
extern s32 D_001DD098_sda;
extern s32 D_001DD09C_sda;
extern vu0_v4 D_001DD0A0_sda[];
extern f32 D_001DD0E0_sda;
extern f32 D_001DD0E4_sda;
extern f32 D_001DD0E8_sda;
extern s32 D_001DD0EC_sda;
extern s32 D_001DD0F0_sda;
extern f32 D_001DD0F4_sda;
__asm__(".extern D_001DD040_sda, 4");
__asm__(".extern D_001DD098_sda, 4");
__asm__(".extern D_001DD09C_sda, 4");
__asm__(".extern D_001DD0A0_sda, 64");
__asm__(".extern D_001DD0E0_sda, 4");
__asm__(".extern D_001DD0E4_sda, 4");
__asm__(".extern D_001DD0E8_sda, 4");
__asm__(".extern D_001DD0EC_sda, 4");
__asm__(".extern D_001DD0F0_sda, 4");
__asm__(".extern D_001DD0F4_sda, 4");
extern vu0_v4 D_L01_001E29C0[];
extern vu0_v4 D_001A4EC0[];
extern f32 D_L01_001E18CC[];
extern Slot_0033F530 D_L01_00278DA0[];
extern u64 func_00389598(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, f32, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_003405B8(void);

void func_L01_0033F530(Mob_0033F530 *m) {
    Pkt_0033F530 packet;
    vu0_v4 normal, tangent, bitangent, pos, tmp;
    s32 i, j;
    vu0_v4 *source, *dest;
    u32 color;
    f32 fade, ratio, size;
    Obj_0033F530 *p = m->p;

    if (m->state != 2) {
        if (p->age < ((D_001DD040_sda - 30) * 5 + 2) / 6) {
            fade = 1.0f;
        } else {
            fade = (f32)((D_001DD040_sda * 5 + 2) / 6 - p->age) / 25.0f;
        }
        packet.texture = func_00389598(8);
        normal = D_L01_001E29C0[0];
        normal.x -= m->pos.x; normal.y -= m->pos.y; normal.z -= m->pos.z; /* vsub.xyz: w kept */
        packet.prim = 0x8000000048UL;
        packet.alpha = 0xFF9000000260UL;
        packet.zero = 0;
        packet.uv[0] = 0; packet.uv[1] = 0; packet.uv[2] = 0; packet.uv[3] = 1.0f;
        packet.uv[4] = 1.0f; packet.uv[5] = 0; packet.uv[6] = 1.0f; packet.uv[7] = 1.0f;
        func_0038CF68(&normal, &normal, 1.0f);
        pos = m->pos;
        func_0038CE20(&bitangent, -1.0f, D_001A4EC0);
        func_0038CE90(&tangent, &normal, &bitangent);
        func_0038CF68(&tangent, &tangent, 1.0f);
        func_0038CE90(&bitangent, &tangent, &normal);
        for (i = 0; i < 10; i++) {
            if (D_L01_00278DA0[i].active != 0) {
                ratio = (f32)D_L01_00278DA0[i].age * D_L01_001E18CC[0];
                if (ratio > 1.0f) {
                    ratio = 1.0f;
                }
                color = (D_001DD09C_sda & 0xFFFFFF)
                      | ((s32)(fade * ((f32)D_001DD098_sda + (0.0f - (f32)D_001DD098_sda) * ratio)) << 24);
                size = D_001DD0E0_sda + (D_001DD0E4_sda - D_001DD0E0_sda) * ratio;
                packet.colors[0] = color; packet.colors[3] = color;
                packet.colors[2] = color; packet.colors[1] = color;
                source = D_001DD0A0_sda;
                dest = packet.verts;
                for (j = 3; j >= 0; j--) {
                    func_0038CE20(&tmp, size, source++);
                    func_0038D028(dest++, &tmp, &normal);
                }
                func_003D2DA0(&packet, 0, 0);
            }
        }
        packet.texture = func_00389598(11);
        color = (D_001DD0F0_sda & 0xFFFFFF) | D_001DD0EC_sda;
        packet.prim = 0x8000000044UL;
        packet.colors[0] = color; packet.colors[3] = color;
        packet.colors[2] = color; packet.colors[1] = color;
        func_0038CF68(&pos, &normal, D_001DD0F4_sda);
        pos.x += m->pos.x; pos.y += m->pos.y; pos.z += m->pos.z; /* vadd.xyz: w kept */
        size = D_001DD0E8_sda + func_L01_00443A18(0.0f, 0.1f);
        source = D_001DD0A0_sda;
        dest = packet.verts;
        for (j = 3; j >= 0; j--) {
            func_0038CE20(&tmp, size, source++);
            func_0038D028(dest++, &tmp, &normal);
        }
        func_003D2DA0(&packet, 0, 0);
        func_L01_0033F920(m, fade);
    }
    func_L01_003405B8();
}
