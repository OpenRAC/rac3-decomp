/* functional: high. Near miss (8 diff lines: branch/load scheduling of the ground-height select only). Sibling of func_L01_0039D938 with state offsets +0x10 (0x70/0x50/0x78); every offset and constant re-read against retail. */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec4_003018B8;
typedef struct {
    u8 pad0[0x18];
    u8 *object;
    u8 pad1c[0xc];
    f32 height;
} Collision_003018B8;
extern Collision_003018B8 D_L01_001EAA00_003018B8 __asm__("D_L01_001EAA00");
extern f32 D_L01_001EAA28_003018B8[] __asm__("D_L01_001EAA28");
void func_L01_003018B8(u8 *object) {
    extern s32 func_L01_0044C108(void *);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L01_0044C998(void *, void *, void *, void *, void *, void *);
    extern void func_003C5278(Vec4_003018B8 *, Vec4_003018B8 *, Vec4_003018B8 *, f32);
    extern s32 func_003D3CB0(Vec4_003018B8 *, s32 *, s32, s32, s32);
    extern s32 func_003C4B50(void *);
    extern s32 func_003C4D58(void *);
    extern void func_L01_0044CB18(void *, void *, void *, void *, void *, void *);
    Vec4_003018B8 bottom, top, zero;
    u8 *state = *(u8 **)(object + 0x68);
    Vec4_003018B8 *position = (Vec4_003018B8 *)(object + 0x10);
    s32 collided = 0;
    f32 ground;
    if (!func_L01_0044C108(position)) {
        func_L01_004450F0(object, 5, -1);
        return;
    }
    if (*(void **)(state + 0xc)) {
        qzero(&zero);
        func_L01_0044C998(object, *(void **)(state + 0xc), state + 0x70, &zero, position, &zero);
    }
    bottom = *position;
    func_003C5278(position, &bottom, &bottom, -0.5f);
    top = bottom;
    func_003C5278(position, &top, &top, 1.5f);
    if (func_003D3CB0(&bottom, (s32 *)&top, 2, (s32)object, 0)) {
        collided = 1;
        ground = D_L01_001EAA28_003018B8[0];
    } else {
        ground = top.v[2];
    }
    if (collided) {
        Collision_003018B8 *c = &D_L01_001EAA00_003018B8;
        if (c->object) {
        if (func_003C4B50(c->object)) {
            *(f32 *)(state + 0x10) = *(f32 *)(c->object + 0x10);
            *(f32 *)(object + 0x10) = *(f32 *)(state + 0x10);
            *(f32 *)(state + 0x14) = *(f32 *)(c->object + 0x14);
            *(f32 *)(object + 0x14) = *(f32 *)(state + 0x14);
            *(f32 *)(object + 0x18) = c->height;
            *(Vec4_003018B8 *)(state + 0x10) = *(Vec4_003018B8 *)(object + 0x10);
            func_003C5278((Vec4_003018B8 *)(object + 0x10), (Vec4_003018B8 *)(state + 0x10), (Vec4_003018B8 *)(state + 0x10), -0.5f);
        } else if (!*(void **)(state + 0xc) && func_003C4D58(c->object)) {
            void *hit = c->object;
            *(void **)(state + 0xc) = hit;
            func_L01_0044CB18(object, hit, object + 0x10, object + 0xf0, state + 0x70, &zero);
        }
    }
    }
    if (*(f32 *)(object + 0x18) <= ground) {
        *(f32 *)(object + 0x18) = ground;
        object[0xbc] = 0;
        *(s32 *)(state + 0x50) = 0;
    } else {
        object[0xbc] = 1;
        if (*(void **)(state + 0xc)) *(f32 *)(state + 0x78) -= *(f32 *)(state + 0x50);
        else *(f32 *)(object + 0x18) -= *(f32 *)(state + 0x50);
        *(f32 *)(state + 0x50) += 0.00392f;
        *(f32 *)(state + 0x50) = *(f32 *)(state + 0x50) > 0.3f ? 0.3f : *(f32 *)(state + 0x50);
    }
}
