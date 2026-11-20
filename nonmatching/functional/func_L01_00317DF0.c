/* functional: high. Taken from the PAL near-miss draft (208 words differ: allocation and loop schedules) after checking every state, constant, offset and call against retail's assembly (jump table 0-4, 137-iteration random table fill, hit loop with mask 0x500000000000 and the four excluded class ids, particle follow, moby scale/rotation); VU0 add/sub helpers written as plain C; D_L01_001E29C0 declared as the file's other C does. */
typedef struct {
    vu0_q vector;
    u8 pad10[8];
    u8 type, mode;
    u16 class_id;
    s32 pad1C, flags;
    u8 pad24[12];
} Hit_00317DF0;
typedef struct { s32 f0, f4; f32 alpha; s32 fC; vu0_q pos; } Particle_00317DF0;
extern G_00318408 D_001A4BE0;
extern u8 D_001A4CC0[];
extern f32 D_L01_00274130[][2];
extern vu0_q D_L01_001EAA20[];
extern u8 *D_L01_001EEA80[];
extern s32 D_L01_001DC7DC;
extern u8 D_001A4EA0[];
extern Particle_00317DF0 D_L01_001F1B40[];
extern vu0_v4 D_L01_001E29C0;
static __inline__ void sub_317DF0(void *d, void *a, void *b) {
    f32 w = ((f32 *)a)[3];
    ((f32 *)d)[0] = ((f32 *)a)[0] - ((f32 *)b)[0];
    ((f32 *)d)[1] = ((f32 *)a)[1] - ((f32 *)b)[1];
    ((f32 *)d)[2] = ((f32 *)a)[2] - ((f32 *)b)[2];
    ((f32 *)d)[3] = w;
}
static __inline__ void add_317DF0(void *d, void *a, void *b) {
    f32 w = ((f32 *)a)[3];
    ((f32 *)d)[0] = ((f32 *)a)[0] + ((f32 *)b)[0];
    ((f32 *)d)[1] = ((f32 *)a)[1] + ((f32 *)b)[1];
    ((f32 *)d)[2] = ((f32 *)a)[2] + ((f32 *)b)[2];
    ((f32 *)d)[3] = w;
}
void func_L01_00317DF0(u8 *obj)
{
    extern f32 func_00382538(void);
    extern f32 func_L01_004451A0(f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern void func_L01_00319258(void *, void *, s32);
    extern void func_L01_00318878(void *);
    extern s32 func_0038CAD0(void *);
    extern s32 func_003D4D00(void *, s32, void *, s32, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_003185F0(void);
    extern void func_L01_003186A8(void *);
    extern void func_003C2880(u8 *);
    extern void func_L01_00424D88(s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern void func_0038D308(void *, void *);
    extern void func_L01_003189B0(void *);
    extern void func_L01_00318C30(void *);
    extern void func_L01_00319480(void *);
    extern void func_L01_00318E68(u8 *);
    extern void func_L01_00404A10(void (*)(u8 *), u8 *);
    vu0_v4 v;
    Hit_00317DF0 hit;
    u8 *hero = (u8 *)&D_001A4BE0;
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 t;
    s32 i, count;
    f32 (*randoms)[2];
    u8 **list;
    Particle_00317DF0 *particle;
    *(vu0_q *)(obj + 0x10) = *(vu0_q *)(*(u8 **)(hero + 0x25C0) + 0x10);
    /* The five labels are decoded in func_L01_00317DF0.switch.txt. */
    switch (obj[0x20]) {
    case 0:
        obj[0x20] = 1;
        *(s32 *)(vars + 4) = 50;
        *(s32 *)(vars + 20) = 0;
        randoms = D_L01_00274130;
        i = 136;
        do {
            --i;
            (*randoms)[0] = func_00382538();
            (*randoms)[1] = func_00382538();
            ++randoms;
        } while (i >= 0);
    case 1:
        obj[0x20] = 2;
    case 2:
        *(f32 *)(vars + 20) = func_L01_004451A0(1.0f - (f32)*(s32 *)(vars + 4) / 50.0f) * 15.0f;
        if (*(s32 *)(vars + 4) % 3 == 0 && *(s32 *)(vars + 24) == 0) {
            f32 a = func_00382538();
            f32 b = func_00382538();
            func_00382760(&v, *(f32 *)(vars + 20), a, b);
            add_317DF0(&v, &v, D_001A4CC0);
            if (func_003D3CB0(D_001A4CC0, &v, 0, *(s32 *)(D_001A4CC0 + 0x24E0), 0))
                *(vu0_q *)&v = D_L01_001EAA20[0];
            func_L01_00319258(obj, &v, 8);
        }
        if (*(s32 *)(vars + 4) < 8 && (*(s32 *)(vars + 4) & 7) == 0)
            func_L01_00318878(obj);
        if (func_0038CAD0(vars + 4)) {
            *(s32 *)(vars + 4) = 100;
            obj[0x20] = 3;
            if (*(s32 *)(vars + 24) == 0) {
                count = func_003D4D00(D_001A4CC0, 0, obj, 0, 10.0f);
                if (count > 0) {
                    list = D_L01_001EEA80;
                    do {
                        u8 *moby = *list;
                        if ((*(unsigned long *)(moby + 0x30) & 0x500000000000UL) &&
                            moby != *(u8 **)(hero + 0x25C0) &&
                            *(s16 *)(moby + 0xAA) != 0xCE7 &&
                            *(s16 *)(moby + 0xAA) != 0x107E &&
                            *(s16 *)(moby + 0xAA) != 0x1A17 &&
                            *(s16 *)(moby + 0xAA) != 0xBB8) {
                            sub_317DF0(&v, moby + 0x10, hero + 0xE0);
                            func_0038CF68((f32 *)&v, (f32 *)&v, 1.0f);
                            func_0038CF68((f32 *)&hit, (f32 *)&hit, 1.0f);
                            func_L01_00446760(&hit, obj, 0x1030000, &v, 30.0f);
                            hit.vector = *(vu0_q *)&v;
                            hit.flags = 1;
                            ((f32 *)&hit.vector)[3] = 5627.9248046875f;
                            hit.type = 5;
                            hit.mode = 3;
                            hit.class_id = *(u16 *)(*list + 0xAA);
                            func_L01_00446978(*list, &hit);
                        }
                        --count;
                        ++list;
                    } while (count);
                }
            }
            func_L01_003185F0();
        }
        break;
    case 3:
        if ((*(s32 *)(vars + 4) & 7) == 0) func_L01_00318878(obj);
        func_0038CAD0(vars + 4);
        func_L01_003186A8(obj);
        if (*(s32 *)(vars + 4) == 33) obj[0x20] = 4;
        break;
    case 4:
        if (func_0038CAD0(vars + 4) && *(s32 *)vars == 0) {
            if (*(u8 **)(vars + 8)) func_003C2880(*(u8 **)(vars + 8));
            if (*(u8 **)(vars + 12)) func_003C2880(*(u8 **)(vars + 12));
            if (*(s32 *)(vars + 16) != -1) func_L01_00424D88(*(s32 *)(vars + 16));
            D_L01_001DC7DC = 0;
            func_003C2880(obj);
            return;
        }
        break;
    }
    t = (func_0038D098((1.0f - (f32)*(s32 *)(vars + 4) / 100.0f) * 6.28318530718f - 3.14159265359f) + 1.0f) * 0.5f;
    if (*(u8 **)(vars + 8)) {
        u8 *moby = *(u8 **)(vars + 8);
        **(s32 **)(moby + 0x68) = (s32)(t * 32.0f);
        *(f32 *)(*(u8 **)(vars + 8) + 0xF8) = func_0038DAB8(*(f32 *)(*(u8 **)(vars + 8) + 0xF8), 0.062831856f);
        moby = *(u8 **)(vars + 8);
        func_0038D308(moby + 0xC0, moby + 0xF0);
        *(f32 *)(*(u8 **)(vars + 8) + 0xC0) *= 0.5f;
        *(f32 *)(*(u8 **)(vars + 8) + 0xD4) *= 0.5f;
        *(f32 *)(*(u8 **)(vars + 8) + 0xE8) = t * 1.5f;
        *(vu0_q *)(*(u8 **)(vars + 8) + 0x10) = *(vu0_q *)(*(u8 **)(hero + 0x25C0) + 0x10);
    }
    if (*(u8 **)(vars + 12)) {
        u8 *moby = *(u8 **)(vars + 12);
        **(s32 **)(moby + 0x68) = (s32)(t * 32.0f);
        *(f32 *)(*(u8 **)(vars + 12) + 0xF8) = func_0038DB00(*(f32 *)(*(u8 **)(vars + 12) + 0xF8), 0.062831856f);
        moby = *(u8 **)(vars + 12);
        func_0038D308(moby + 0xC0, moby + 0xF0);
        *(f32 *)(*(u8 **)(vars + 12) + 0xE8) = t;
        *(vu0_q *)(*(u8 **)(vars + 12) + 0x10) = *(vu0_q *)(*(u8 **)(hero + 0x25C0) + 0x10);
    }
    if (*(s32 *)(vars + 16) != -1) {
        u8 *axis = D_001A4EA0;
        particle = &D_L01_001F1B40[*(s32 *)(vars + 16)];
        func_0038CF68((f32 *)&v, (f32 *)axis, 0.5f);
        add_317DF0(&particle->pos, *(u8 **)(axis + 0x2300) + 0x10, &v);
        sub_317DF0(&v, &D_L01_001E29C0, &particle->pos);
        func_0038CF68((f32 *)&v, (f32 *)&v, 0.15f);
        add_317DF0(&particle->pos, &particle->pos, &v);
        ((f32 *)&particle->pos)[3] = 5.0f;
        particle->alpha = t;
        particle->fC = 0;
    }
    func_L01_003189B0(obj);
    func_L01_00318C30(obj);
    func_L01_00319480(obj);
    func_L01_00404A10(func_L01_00318E68, obj);
}
