/* functional: high. PAL near-miss draft (98 diff words) with its inline-asm vsub.xyz replaced by plain float code; control flow, constants (2.8797932, 0.5/1.0 overrides) and callees verified against the asm. 145 diff words are scheduling/VU only */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_44C3C0;
extern f32 func_00382C58(void *, f32, f32, f32, f32, f32);

void func_L01_0044C3C0(V4_44C3C0 *from, V4_44C3C0 *dir, V4_44C3C0 *to, void *state, V4_44C3C0 *axis, V4_44C3C0 *out, f32 low, f32 high, f32 rate, f32 distance)
{
    V4_44C3C0 delta, cross, rotation;
    f32 length, dot, lengths, angle, half;
    V4_44C3C0 *result = &rotation;
    delta.x = to->x - from->x;
    delta.y = to->y - from->y;
    delta.z = to->z - from->z;
    delta.w = to->w;
    length = func_0038CEA8(&delta.x);
    if (length == 0.0f) return;
    func_0038CE90(&cross.x, &delta.x, &dir->x);
    dot = func_0038CE68(&dir->x, &delta.x);
    lengths = func_0038CEA8(&dir->x) * func_0038CEA8(&delta.x);
    if (lengths == 0.0f) return;
    angle = 1.5707964f - func_0038D0C8(dot / lengths);
    if (angle > 2.8797932f) {
        func_0038CE90(&result->x, &dir->x, &axis->x);
        axis = result;
        func_0038CE90(&cross.x, &result->x, &dir->x);
    } else {
        axis = result;
        if (length < distance && angle < 1.5707964f) {
            high = 1.0f;
            low = 0.5f;
        }
    }
    half = func_00382C58(state, 0.0f, angle, low, high, rate) * 0.5f;
    func_0038CF68(&axis->x, &cross.x, func_0038D0B0(half));
    rotation.w = func_0038D098(half);
    func_0038D850(&dir->x, &dir->x, &axis->x);
    if (out) *out = rotation;
}
