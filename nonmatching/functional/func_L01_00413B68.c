/* functional: high. Follow-camera collision/distance solver; VU0 vec add/sub written as xyz float ops (w taken from the first operand, as vadd.xyz/vsub.xyz keep it); constants carried over from PAL asm (0.032, 0.064, 1.6000001, 0.008, 0.40000003, 0.51, 0.5); 312 byte-diff is codegen only. */
typedef struct {
    f32 x, y, z, w;
} V4_00413B68;

extern u8 D_L01_001EAA00[];
extern f32 D_001D6530;
extern f32 D_001D6534;

extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_L01_00446E38(void *, void *, s32, s32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);

void func_L01_00413B68(u8 *a0, V4_00413B68 *a, V4_00413B68 *b) {
    V4_00413B68 target, source, delta, original, offset, direction, hit;
    V4_00413B68 matrix[3];
    f32 dot, length, fraction;
    V4_00413B68 *eye = (V4_00413B68 *)(a0 + 0x30);
    u8 *forward = a0 + 0xC0;
    u8 *hitbase = D_L01_001EAA00;
    s32 owner;

    target = *a;
    original = *a;
    source = *b;
    delta.x = target.x - source.x;
    delta.y = target.y - source.y;
    delta.z = target.z - source.z;
    delta.w = target.w;
    dot = func_0038CE68(&delta, &delta);
    length = func_0038CEA8(forward);
    if (0.01f < (dot < 0.0f ? -dot : dot)) {
        fraction = func_L01_00446E38(&source, &target, 0x84, *(s32 *)(a0 + 0xBC), D_001D6530);
        if (fraction < 1.0f) {
            if (*(s32 *)(hitbase + 0x18) == 0 || 0.0f < fraction) {
                target = *(V4_00413B68 *)(hitbase + 0x30);
            }
        }
    }
    if (length == 0.0f) {
        *eye = target;
        return;
    }
    if (*(u16 *)(a0 + 0xE0) & 4) {
        *(u16 *)(a0 + 0xE0) &= 0xFFFB;
        func_003C41A0((f32 *)(a0 + 0x124), a0 + 0x128, 0.0f, 0.032f, 0.064f, 1.6000001f);
    } else {
        func_0038D000(&direction, forward, a0);
        func_0038CF68(&direction, &direction, length + 0.5f);
        direction.x = direction.x + original.x;
        direction.y = direction.y + original.y;
        direction.z = direction.z + original.z;
        if (func_003D3CB0(&target, &direction, 4, *(void **)(a0 + 0xBC), 0)) {
            hit = *(V4_00413B68 *)(hitbase + 0x20);
            if (*(u8 **)(hitbase + 0x18) != 0 && *(s16 *)(*(u8 **)(hitbase + 0x18) + 0xAA) != 0xD54
                && func_003D4D00(a0 + 0x30, 0, *(void **)(a0 + 0xBC), 0, 0.51f)) {
                length = func_0038CF00(&original, &hit) - 0.5f;
            } else {
                if (func_003D3CB0(&target, &direction, 2, *(void **)(a0 + 0xBC), 0)) {
                    length = func_0038CF00(&original, hitbase + 0x20) - 0.5f;
                }
            }
            if (length < 0.0f) {
                *eye = target;
                return;
            }
        }
        if (length < *(f32 *)(a0 + 0x124)) {
            *(f32 *)(a0 + 0x124) = length;
            *(f32 *)(a0 + 0x128) = 0.0f;
        } else if (*(f32 *)(a0 + 0x124) < length) {
            if (*(f32 *)(a0 + 0x128) < 0.0f) {
                *(f32 *)(a0 + 0x128) = 0.0f;
            }
            func_003C41A0((f32 *)(a0 + 0x124), a0 + 0x128, length, 0.008f, 0.008f, 0.40000003f);
        }
    }
    func_0038D000(eye, forward, a0);
    func_0038CF68(&offset, eye, *(f32 *)(a0 + 0x124) - 1.0f);
    func_0038CF68(eye, eye, *(f32 *)(a0 + 0x124));
    eye->x = eye->x + original.x;
    eye->y = eye->y + original.y;
    eye->z = eye->z + original.z;
    offset.x = offset.x + target.x;
    offset.y = offset.y + target.y;
    offset.z = offset.z + target.z;
    fraction = func_L01_00446E38(&offset, eye, 0x104, *(s32 *)(a0 + 0xBC), D_001D6534);
    if (fraction < 1.0f) {
        *eye = *(V4_00413B68 *)(hitbase + 0x30);
    }
    func_0038D308(matrix, a0 + 0xD0);
    func_0038D5F0(a0, a0, matrix);
}
