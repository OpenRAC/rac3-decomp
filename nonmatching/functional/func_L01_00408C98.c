/* functional: high. PAL near miss (219 words differ: frame size 0x12f0 vs 0x1340 from sq/sd spill slots, allocation); packet layout, GS tags, loops, slot rotation and every call read against the asm. */
/* localdecomp:start func_L01_00408C98 */
typedef int Q_00408C98 __attribute__((mode(TI)));
typedef struct {
    Q_00408C98 vertex[4];
    s32 color[4];
    f32 uv[4][2];
    unsigned long tag, texture, mode, clamp;
} Packet_00408C98;
extern s32 D_L01_001D63D4;
extern s32 D_L01_001D63D8;
extern f32 D_L01_001D63E0;
extern f32 D_L01_001D63E4[] __attribute__((section(".sdata")));
void func_L01_00408C98(Q_00408C98 *vertices, s32 count, Q_00408C98 *positions,
    Q_00408C98 *rotations, s32 index, s32 steps, s32 color0, s32 color1, s32 tex, f32 start)
{
    extern s32 func_0038DBD8(s32, s32, f32);
    extern unsigned long func_00389598(s32);
    extern void func_0038D830(void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    Packet_00408C98 packets[32];
    Q_00408C98 matrix[4];
    s32 slot;
    s32 i, j, k;
    s32 idx;
    s32 next;
    s32 color;
    s32 initial_color;
    f32 delta, t;
    if (steps < 2) return;
    delta = 1.0f / (steps - 1);
    t = delta * start;
    slot = 2;
    initial_color = func_0038DBD8(color0, color1, delta);
    for (i = 0; i < (count >> 1); i = next) {
        next = i + 1;
        packets[i].texture = func_00389598(tex);
        packets[i].color[1] = initial_color;
        packets[i].mode = 0xFF9000000260;
        packets[i].tag = 5;
        packets[i].clamp = ((unsigned long)D_L01_001D63D4 << 2) |
            ((unsigned long)D_L01_001D63D8 << 6) | 0x8000000000;
        packets[i].color[0] = initial_color;
        for (j = 0; j < 4; j++) {
            packets[i].uv[j][0] = (&D_L01_001D63E0)[j * 2];
            packets[i].uv[j][1] = D_L01_001D63E4[j * 2];
        }
    }
    idx = index;
    func_0038D830(&rotations[idx], matrix);
    matrix[3] = positions[idx];
    ((f32 *)&matrix[3])[3] = 1.0f;
    for (i = 0; i < count; i++)
        func_0038D028(&packets[i >> 1].vertex[i & 1], &vertices[i], matrix);
    for (i = 1; i < steps; i++) {
        idx = (idx + steps - 1) % steps;
        func_0038D830(&rotations[idx], matrix);
        matrix[3] = positions[idx];
        ((f32 *)&matrix[3])[3] = 1.0f;
        color = func_0038DBD8(color0, color1, t);
        t += delta;
        if (t > 1.0f) t = 1.0f;
        for (j = 0; j < count; j++) {
            s32 n = slot + (j & 1);
            func_0038D028(&packets[j >> 1].vertex[n], &vertices[j], matrix);
            packets[j >> 1].color[n] = color;
        }
        slot = (slot + 2) % 4;
        for (j = 0; j < (count >> 1); j++)
            func_003D2DA0(&packets[j], 0, 1);
    }
}
/* localdecomp:end func_L01_00408C98 */
