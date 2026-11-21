/* functional: high. Draft verified against PAL assembly field by field (arc record layout 0xA0, wobble phases x100 while the timer runs, damage packet, end effect); 90 words differ in codegen only. */
typedef struct {
    vu0_v4 first, second, start, end;
    f32 phase[3], rate[3], scale[3];
    f32 phase2[3], rate2[3], scale2[3];
    s32 delay; u8 *owner, *target;
    s32 timer, duration, done;
} Arc_0030A670;
typedef struct { u8 pad[0x70]; f32 damage; u8 tail[0x7C]; } Weapon_0030A670;
typedef struct { u8 pad[0x10]; u8 weapon; } Selection_0030A670;
extern A00309EA0 D_L01_0026FD30[30];
extern Weapon_0030A670 D_L01_002C5600[];
extern Selection_0030A670 D_001425C0;
void func_L01_0030A670(u8 *object) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 *func_00382348(u8 *);
    extern void func_L01_00451290(u8 *, void *, s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern s32 func_0038CAD0(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00446760(void *, u8 *, s32, void *, f32);
    extern void func_L01_00446978(u8 *, void *);
    extern void func_L01_0031B090(u8 *, s32, s32);
    extern void func_003A52A0(s32, s32, u8 *);
    extern void func_L01_0030BF20(void *, void *, s32, s32);
    vu0_v4 delta;
    Query_003090E0 packet;
    u8 *state = *(u8 **)(object + 0x68);
    s32 i;
    Arc_0030A670 *e;
    f32 *info;
    for (i = 0; i < 30; i++) {
        e = (Arc_0030A670 *)(i * sizeof(Arc_0030A670) + (u32)D_L01_0026FD30);
        if (e->owner != object) continue;
        *(vu0_q *)&e->start = *(vu0_q *)(object + 0x10);
        if (e->timer) {
            e->phase[0] = func_0038DAB8(e->phase[0], e->rate[0] * 100.0f);
            e->phase[1] = func_0038DAB8(e->phase[1], e->rate[1] * 100.0f);
            e->phase[2] = func_0038DAB8(e->phase[2], e->rate[2] * 100.0f);
            e->phase2[0] = func_0038DAB8(e->phase2[0], e->rate2[0] * 100.0f);
            e->phase2[1] = func_0038DAB8(e->phase2[1], e->rate2[1] * 100.0f);
            e->phase2[2] = func_0038DAB8(e->phase2[2], e->rate2[2] * 100.0f);
        } else {
            e->phase[0] = func_0038DAB8(e->phase[0], e->rate[0]);
            e->phase[1] = func_0038DAB8(e->phase[1], e->rate[1]);
            e->phase[2] = func_0038DAB8(e->phase[2], e->rate[2]);
            e->phase2[0] = func_0038DAB8(e->phase2[0], e->rate2[0]);
            e->phase2[1] = func_0038DAB8(e->phase2[1], e->rate2[1]);
            e->phase2[2] = func_0038DAB8(e->phase2[2], e->rate2[2]);
        }
        e->first.x = func_0038D098(e->phase[0]) * e->scale[0];
        e->first.y = func_0038D0B0(e->phase[1]) * e->scale[1];
        e->first.z = -func_0038D0B0(e->phase[2]) * e->scale[2];
        e->second.x = func_0038D098(e->phase2[0]) * e->scale2[0];
        e->second.y = func_0038D0B0(e->phase2[1]) * e->scale2[1];
        e->second.z = -func_0038D0B0(e->phase2[2]) * e->scale2[2];
        if (e->target) {
            info = func_00382348(e->target);
            if (info != 0) {
                func_L01_00451290(e->target, &delta, 1);
                func_0038CE20((f32 *)&delta, (f32 *)&delta, info[4]);
                vec_add_ab(&e->end, &delta, e->target + 0x10);
            } else {
                *(vu0_q *)&e->end = *(vu0_q *)(e->target + 0x10);
            }
            func_0038CDF8(&e->end, &e->start, &e->end, 1.0f - (f32)e->timer / (f32)e->duration);
        }
        if (func_0038CAD0(&e->timer)) {
            if (*(s32 *)(e->target + 0x98) && !e->done) {
                vec_sub_ba(&delta, &e->end, &e->start);
                func_0038CF68(&delta, &delta, 0.040000002831220627f);
                func_L01_00446760(&packet, object, 0x410000, &delta, ((Weapon_0030A670 *)(D_001425C0.weapon * sizeof(Weapon_0030A670) + (u32)D_L01_002C5600))->damage);
                packet.b18 = 1;
                packet.b19 = 3;
                packet.h1A = *(u16 *)(object + 0xAA);
                func_L01_00446978(e->target, &packet);
                func_L01_0031B090(e->target, 160, *(s32 *)(object + 0xB8));
                func_003A52A0(1, 0, object);
                func_0038CF68(&delta, &delta, -1.0f);
                func_L01_0030BF20(&e->end, &delta, 9, 0xFF0000);
                e->done = 1;
            }
            if (func_0038CAD0(&e->delay)) {
                e->owner = 0;
                (*(s32 *)(state + 0x54))--;
            }
        }
    }
}
