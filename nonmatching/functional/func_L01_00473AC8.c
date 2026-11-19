/* functional: high. Replaced qzero by plain sq $0 asm and vu0 asm names with $vf; file context lacks vu0.h. */
/* localdecomp:start func_L01_00473AC8 */
typedef int Q_00473AC8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00473AC8;
extern u8 *D_001A71A0[];
extern Q_00473AC8 D_L01_001EAA20[];
extern s32 D_L01_001D673C;
extern V_00473AC8 D_001A4EC0[];
void func_L01_00473AC8(Part_00470258 *particle) {
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_0046A938(void *, s32, u32, f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern u8 *func_L01_004669B0(f32, f32, f32, f32, void *, s32, void *, u32, s32);
    extern void func_003C5180(void *, void *, s32);
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    V_00473AC8 next, at, velocity;
    Sub_00470258 *s;
    u8 *p = (u8 *)particle;
    s32 hit;
    if (particle == 0) return;
    s = &particle->sub;
    func_L01_004CAB30(&particle->f10, &particle->f10);
    particle->fC += -120.00000762939453f;
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m" (next) : "m" (particle->f10), "m" (s->v) : "vf1", "vf2");
    hit = func_003D3CB0(&particle->f10, &next, 2, D_001A71A0[0], 0) != 0;
    particle->f4 = func_0038DBD8(s->f10, s->f14, 1.0f - (f32)particle->fA / (f32)s->f18);
    if (((f32 *)&s->v)[0] != 0.0f || ((f32 *)&s->v)[1] != 0.0f || ((f32 *)&s->v)[2] != 0.0f) {
        if (hit) {
            u32 r, g, b;
            u8 max;
            u32 alpha;
            f32 scale;
            s32 color;
            particle->f10 = D_L01_001EAA20[0];
            __asm__("sq $0, %0" : "=m"(s->v));
            particle->fC += particle->fC;
            color = particle->f4;
            g = (color >> 8) & 255;
            b = (color >> 16) & 255;
            alpha = (u32)color >> 24;
            r = p[4];
            if (g < r) {
                max = b < r ? r : b;
            } else {
                max = b < g ? g : b;
            }
            scale = 255.0f / (f32)max;
            s->f10 = (alpha << 24) | ((s32)((f32)(s32)b * scale) << 16) | ((s32)((f32)(s32)g * scale) << 8) | (s32)((f32)(s32)r * scale);
            s->f18 = particle->fA;
            switch (s->f1A) {
            case 0: break;
            case 1: {
                V_00473AC8 *pos = &at;
                f32 size;
                at.x = ((f32 *)&particle->f10)[0];
                at.y = ((f32 *)&particle->f10)[1];
                at.z = ((f32 *)&particle->f10)[2] + 0.01f;
                size = func_003824E0(0.01f, 0.15f);
                func_L01_0046A938(pos, 0, ((func_00382468(6) + 20) << 24) | 0xFF8040, size, 5250.0f);
                break;
            }
            case 2: {
                V_00473AC8 *pos = &at;
                V_00473AC8 *vel = &velocity;
                s32 i, spin;
                u8 *created;
                f32 speed, size;
                at.x = ((f32 *)&particle->f10)[0];
                at.y = ((f32 *)&particle->f10)[1];
                at.z = ((f32 *)&particle->f10)[2] + 0.02f;
                for (i = 4; i >= 0; i--) {
                    speed = func_003824E0(0.1f, 0.2f) * 0.020000001f;
                    func_0038CE20(vel, D_001A4EC0, -speed);
                    spin = (s32)func_L01_00443A18(1.0f, 2.0f);
                    size = func_003824E0(0.15f, 0.25f) * 210000.0f;
                    created = func_L01_004669B0(0.0f, 1.0f, 1.01f, size, pos, spin, vel, 0x7F202020, 0);
                    if (created) {
                        u8 *extra = created + 0x20;
                        created[3] = 0x44;
                        *(s16 *)(created + 10) = 75;
                        created[9] = 0x44;
                        *(f32 *)(extra + 0x1C) = 4.0f;
                        *(s32 *)(extra + 4) = 3;
                        extra[10] = 48;
                        extra[11] = created[10];
                    }
                }
                break;
            }
            }
        } else {
            particle->f10 = *(Q_00473AC8 *)&next;
            if (D_L01_001D673C) {
                func_003C5180(&particle->f10, &at, 0);
                {
                    f32 accel = ((f32 *)&s->v)[3];
                    if (accel != 0.0f) accel = -accel;
                    else accel = 0.009072f;
                    func_0038CE20(&at, &at, accel);
                }
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m" (s->v) : "m" (s->v), "m" (at) : "vf1", "vf2");
            } else {
                f32 accel = ((f32 *)&s->v)[3];
                if (accel != 0.0f) { } else accel = -0.009072f;
                ((f32 *)&s->v)[2] += accel;
            }
        }
    }
    if (func_0038CB00(&particle->fA) || particle->fC < 0.0f || next.x < 0.01f || next.y < 0.01f || next.z < 0.01f) {
        func_003CD250(p);
    } else particle->f8--;
}
/* localdecomp:end func_L01_00473AC8 */
