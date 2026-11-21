/* functional: high. Per-frame update of a velocity-driven effect object: sets the scale from a config ramp, damps the velocity, moves the position (following a target's matrix if it has one), and kills the object when its life ends or the target dies. */
typedef struct {
    s32 w0;
    s32 w4;
    s16 h8;
    s16 hA;
    s32 wC;
} Cfg_46E1B8;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 b20;
} Target_46E1B8;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    Target_46E1B8 *target;
    f32 vx;
    f32 vy;
    f32 vz;
    Cfg_46E1B8 *cfg;
} Sub_46E1B8;

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    vu0_v4 pos;
    Sub_46E1B8 sub;
} Obj_46E1B8;

extern s32 D_L01_001D6694;
extern void func_0038CE20(void *dst, void *src, f32 s);
extern void func_0038D000(void *a, void *b, void *m);
extern s32 func_L01_00447470(s32 a, s32 b, f32 t);

void func_L01_0046E1B8(Obj_46E1B8 *obj) {
    Sub_46E1B8 *sub = &obj->sub;
    Cfg_46E1B8 *cfg;
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    if (sub != 0) {
        cfg = sub->cfg;
        obj->fC = (f32)((cfg->h8 * (cfg->wC - obj->hA)) / cfg->wC + cfg->hA) * 1000.0f;
        v0.x = sub->f0;
        v0.y = sub->f4;
        v0.z = sub->f8;
        func_0038CE20(&v0, &v0, 0.976f);
        sub->f0 = v0.x;
        sub->f4 = v0.y;
        sub->f8 = v0.z;
        if (D_L01_001D6694 == 0 && sub->target != 0) {
            if (sub->target->b20 == 0xFE) {
                goto kill;
            }
            if (sub->target->b20 == 0xFD) {
kill:
                func_003CD250((Obj *)obj);
                return;
            }
            v10.x = sub->vx;
            v10.y = sub->vy;
            v10.z = sub->vz;
            vec_add_ba(&v10, &v10, &v0);
            sub->vx = v10.x;
            sub->vy = v10.y;
            sub->vz = v10.z;
            func_0038D000(&v20, &v10, (u8 *)sub->target + 0xC0);
            vec_add_ba(&obj->pos, &sub->target->pos, &v20);
        } else {
            vec_add_ab(&obj->pos, &obj->pos, &v0);
        }
        obj->b8++;
        obj->w4 = func_L01_00447470(cfg->w4, cfg->w0, (f32)obj->hA / (f32)cfg->wC);
        if (func_0038CB00(&obj->hA) != 0) {
            func_003CD250((Obj *)obj);
        }
    }
}
