/* functional: high. Same reads, writes, calls and order as retail; only the stack frame (16-byte saves) differs in bytes. Spawns effect object (type 0x7A) attached to an owner joint. */
typedef struct V_00473C80 { f32 x,y,z,w; } __attribute__((aligned(16))) V_00473C80;
typedef struct Payload_00473C80 {
    void *owner;
    f32 scale, length;
    s16 b, a;
    f32 offset;
    u8 joint, mode, pad16, axis;
} Payload_00473C80;
typedef struct Effect_00473C80 {
    u8 b0,b1,b2,b3;
    s32 arg;
    u8 b8,b9;
    s16 a;
    f32 scale;
    V_00473C80 pos;
    Payload_00473C80 data;
} Effect_00473C80;
extern u8 *D_L07_0021EC98[];
Effect_00473C80 *func_L07_00473C80(void *owner, u8 joint, s32 arg, u8 mode, s16 a, s16 b, u8 axis, s32 table, s32 index, f32 scale, f32 length, f32 offset) {
    Effect_00473C80 *func_L01_004618E0(s32);
    s32 func_00382468(s32);
    void func_003C2EC0(void *, long, V_00473C80 *);
    void func_0038CF68(V_00473C80 *, V_00473C80 *, f32);
    void func_003C2F58(void *, s32, V_00473C80 *);
    V_00473C80 matrix[4];
    V_00473C80 delta;
    Effect_00473C80 *p;
    Payload_00473C80 *d;
    if (!owner) return 0;
    p = func_L01_004618E0(0x7A);
    if (p) {
        d = &p->data;
        p->b1 = 0;
        p->b9 = 0x44;
        p->scale = scale;
        p->b3 = 0x48;
        p->b8 = func_00382468(0x100);
        p->b2 = D_L07_0021EC98[table][index];
        p->arg = arg;
        d->owner = owner;
        p->a = a;
        d->joint = joint;
        d->scale = scale;
        d->length = length;
        d->a = a;
        d->b = b;
        d->axis = axis;
        d->mode = mode;
        d->offset = offset;
        if (offset != 0.0f) {
            func_003C2EC0(d->owner, (u8)(s32)joint, matrix);
            func_0038CF68(&delta, &matrix[d->axis], d->offset);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(p->pos) : "m"(matrix[3]), "m"(delta) : "vf1", "vf2");
        } else {
            func_003C2F58(d->owner, d->joint, &p->pos);
        }
    }
    return p;
}
