/* functional: high. Draft had func_003C2C98(owner) with one arg; retail passes (owner, p), written via a cast because the file prototype has one arg. In the settled+active case retail passes the OLD p->owner (cur) in a0, kept. abs.s written as ternary. 160 diff words are scheduling/VU only */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0044E850;
typedef struct {
    u8 pad0[0x20];
    u8 state;
} Owner_0044E850;
typedef struct {
    u8 pad0;
    u8 active;
    u8 pad2[0xE];
    V_0044E850 transform;
    V_0044E850 scale;
    u8 pad30[0x10];
    V_0044E850 rotation;
    V_0044E850 speed;
    V_0044E850 target;
    f32 factor;
    u8 pad74[4];
    Owner_0044E850 *owner;
} State_0044E850;
extern void func_003C2C98();
extern void func_L01_00448728(f32 *, f32 *, f32, f32, f32, f32, s32);
extern void func_L01_0043A430(void *, void *, void *);
extern void func_003C3FC0(void *, void *);

void func_L01_0044E850(Owner_0044E850 *owner, State_0044E850 *p, void *arg, f32 a, f32 b) {
    Owner_0044E850 *cur = p->owner;
    /* func_003C2C98 takes (owner, p); the file's one-argument prototype omits p */
    if (cur != 0) {
        if (cur != owner) {
            if (p->active != 0 && cur->state < 127) {
                ((void (*)(Owner_0044E850 *, State_0044E850 *))func_003C2C98)(cur, p);
            }
            p->active = 0;
            p->owner = owner;
        }
    } else {
        p->owner = owner;
    }
    if (p->target.x == 0.0f && p->target.y == 0.0f &&
        p->target.z == 0.0f && p->factor == 1.0f &&
        (p->rotation.x < 0.0f ? -p->rotation.x : p->rotation.x) < 0.005f &&
        (p->rotation.y < 0.0f ? -p->rotation.y : p->rotation.y) < 0.005f &&
        (p->rotation.z < 0.0f ? -p->rotation.z : p->rotation.z) < 0.005f) {
        if (p->active != 0) {
            ((void (*)(Owner_0044E850 *, State_0044E850 *))func_003C2C98)(cur, p);
        }
    } else {
        func_L01_00448728(&p->rotation.x, &p->speed.x, p->target.x, a, b, 0.0f, 0);
        func_L01_00448728(&p->rotation.y, &p->speed.y, p->target.y, a, b, 0.0f, 0);
        func_L01_00448728(&p->rotation.z, &p->speed.z, p->target.z, a, b, 0.0f, 0);
        if (p->active == 0) func_L01_0043A430(owner, arg, p);
        func_003C3FC0(&p->transform, &p->rotation);
        p->scale.x = p->factor;
        p->scale.y = p->factor;
        p->scale.z = p->factor;
        p->target.x = 0.0f;
        p->target.y = 0.0f;
        p->target.z = 0.0f;
        p->target.w = 0.0f;
        p->factor = 1.0f;
    }
}
