/* functional: medium. Same reads, writes, calls and order as retail (switch on obj state 0/1/2/6, other states only run the tail); vsub.xyz/vadd.xyz and lq/sq copies are plain C; vars+0x74 saved pointer is just &vars->w14. */
typedef int s128_311430 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_311430;
typedef struct {
    s32 w0, w4, w8, wC;
    f32 f10;
    s32 w14;
    f32 f18;
    s32 w1C;
    s32 w20;
    s32 w24;
    s32 w28;
} Vars_311430;
typedef struct {
    u8 pad0[0x20];
    f32 f20;
    s32 pad24;
    s32 w28;
    s32 w2C;
} G_2A40_311430;
typedef struct {
    u8 pad0[0x38];
    s32 w38;
} G_1730_311430;
typedef struct {
    u8 pad0[0x10];
    V_311430 pos;
    u8 state;
    u8 pad21[0x68 - 0x21];
    Vars_311430 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} Obj_311430;
typedef struct {
    V_311430 vec;
    u8 pad10[8];
    u8 type, mode;
    u16 class_id;
    s32 pad1C, flags;
} Hit_311430;
extern s32 func_L01_00457458(s32 a0, s32 a1);
extern void func_L01_004CAB30(V_311430 *, V_311430 *);
extern s32 func_L01_004572B0(void *, s32, void *);
extern s32 func_L01_00457480(s32, s32);
extern s32 func_L01_003113E8(s32);
extern void func_003C5180(V_311430 *, V_311430 *, s32);
extern void func_L01_0044BB30(void *, void *, s32, f32, f32);
extern void func_L01_00312B60(f32, void *, s32, void *, void *);
extern void func_L01_003119F0(void *, void *);
extern s32 func_0038DC20(s128_311430 *a0, f32 f12);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern s32 func_00382348(void *);
extern void func_0038CF68(float *off, char *src, float scale);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_003119E0();
extern void func_003C2880(void *);
extern void func_L01_00312C88(void *);
extern void func_L01_00404A10(void (*)(void *), void *);
extern void func_L01_00311D08(void *);
extern s32 D_L01_001E1730[];
extern u8 *D_L01_001E1734;
extern s32 *D_L01_001E1738;
extern G_2A40_311430 D_L01_001E2A40;
extern u8 D_001A4BE0[];
extern u8 *D_L01_001EEA80[];
extern f32 D_L01_001DC6A4;
extern f32 D_L01_001DC6A0;

void func_L01_00311430(Obj_311430 *obj) {
    Vars_311430 *vars;
    V_311430 *pos;
    V_311430 tmp, out, tmp2, buf70;
    Hit_311430 hit;
    V_311430 dir;
    f32 f, f20;
    s32 i, count;
    u8 **list;

    vars = obj->vars;
    if (obj->state != 0) {
        if (func_L01_00457458(obj->hAA, vars->w28) == 0) {
            goto cleanup;
        }
    }
    pos = &obj->pos;
    func_L01_004CAB30(pos, pos);
    switch (obj->state) {
    case 0:
        obj->state = 1;
        vars->f10 = 0;
        vars->f18 = 0.8f;
        vars->w1C = 0x7F;
        vars->w24 = 0x6F;
        vars->w14 = 0x11;
        vars->w28 = func_L01_004572B0(obj, 0, &buf70);
        D_L01_001E1730[0] = func_L01_00457480(obj->hAA, vars->w28);
        D_L01_001E1734 = (u8 *)func_L01_003113E8(D_L01_001E1730[0] + 0x50);
        D_L01_001E1738 = (s32 *)func_L01_003113E8((s32)D_L01_001E1734 + 0xA000);
        for (i = 0; i < 0x90; i++) {
            D_L01_001E1738[i] = 0;
        }
        for (i = 0x13F; i >= 0; i--) {
            *(s32 *)(D_L01_001E1734 + i * 0x80 + 0x7C) = 0;
        }
        ((G_1730_311430 *)D_L01_001E1730[0])->pad0[0x30] = 0;
        *(s128_311430 *)&tmp = *(s128_311430 *)pos;
        func_003C5180(pos, &out, 1);
        tmp.x = pos->x + out.x;
        tmp.y = pos->y + out.y;
        tmp.z = pos->z + out.z;
        tmp.w = pos->w;
        func_L01_0044BB30(obj, &tmp, -1, 2.0f, 20.0f);
        func_L01_00312B60(0.2f, obj, 0x11, pos, vars);
        func_L01_003119F0(obj, pos);
        tmp2 = tmp;
        tmp2.w = 2.0f;
        if (func_0038DC20((s128_311430 *)&tmp2, 100.0f) != -1) {
            D_L01_001E2A40.f20 = 0.45f;
            D_L01_001E2A40.w28 = 0x21;
            D_L01_001E2A40.w2C = 0;
        }
        /* fall through */
    case 1:
        vars->w24 = vars->w24 - 5;
        if (vars->w24 < 0) {
            vars->w24 = 0;
        }
        f = ((f32)vars->w14 / 17.0f);
        f20 = 1.0f;
        vars->f10 = vars->f10 + vars->f18;
        count = func_003D4D00(pos, 0, obj, 0, (f20 - f) * 8.0f + 0.001f);
        if (count > 0) {
            list = D_L01_001EEA80;
            do {
                if (func_00382348(*list) != 0 || (*(u16 *)(*list + 0x34) & 0x4000) != 0) {
                    if (*list != *(u8 **)(D_001A4BE0 + 0x25C0) && *(s16 *)(*list + 0xAA) != 0xA5A) {
                        V_311430 *m = (V_311430 *)(*list + 0x10);
                        dir.x = m->x - pos->x;
                        dir.y = m->y - pos->y;
                        dir.z = m->z - pos->z;
                        dir.w = m->w;
                        func_0038CF68(&dir.x, (char *)&dir, 1.0f);
                        func_0038CF68(&hit.vec.x, (char *)&hit, 1.0f);
                        func_L01_00446760(&hit, obj, 0x1030000, &dir, 1.0f);
                        hit.vec = dir;
                        hit.mode = 3;
                        hit.flags = 1;
                        hit.vec.w = 5627.9248046875f;
                        hit.type = 5;
                        hit.class_id = *(u16 *)(*list + 0xAA);
                        func_L01_00446978(*list, &hit);
                    }
                }
                count--;
                list++;
            } while (count != 0);
        }
        if (func_0038CAD0(&vars->w14) != 0) {
            obj->state = 2;
            vars->w14 = 0x21;
        }
        break;
    case 2:
        f20 = (f32)vars->w14 / 40.0f;
        vars->f10 = vars->f10 + vars->f18;
        if (vars->w14 == 20) {
            func_L01_003119F0(obj, pos);
        }
        if (func_0038CAD0(&vars->w14) != 0) {
            if (vars->w1C != 0) {
                vars->w1C = vars->w1C - 1;
            } else {
                vars->w1C = 0;
                obj->state = 6;
            }
        } else {
            vars->w1C = (s32)(f20 * 127.0f);
        }
        break;
    case 6:
        vars->f18 = vars->f18 - 0.02f;
        if (vars->f18 < 0.1f) {
            vars->f18 = 0.1f;
        }
        vars->f10 = vars->f10 + vars->f18;
        if (((G_1730_311430 *)D_L01_001E1730[0])->w38 == 0) {
            goto cleanup;
        }
        break;
    default:
        break;
    }
    f = D_L01_001DC6A4 - 0.04f;
    D_L01_001DC6A4 = f;
    if (D_L01_001DC6A0 < -8.0f) {
        D_L01_001DC6A0 = D_L01_001DC6A0 + 8.0f;
    }
    if (f < -8.0f) {
        D_L01_001DC6A4 = f + 8.0f;
    }
    func_L01_00312C88(obj);
    func_L01_00404A10(func_L01_00311D08, obj);
    return;
cleanup:
    func_L01_003119E0();
    func_003C2880(obj);
}
